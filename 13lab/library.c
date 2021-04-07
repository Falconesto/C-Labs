//
// Created by Александр on 06.12.2019.
//

#include "library.h"
#include <strings.h>

struct Config* parse_args(int argc, char **argv) {
    struct Config *config = malloc(sizeof(struct Config));
    bzero(config, sizeof(struct Config));
    config->type = NOTHING;
    for(int i = 1; i < argc; i++) {
        if(strstr(argv[i], "--filepath") != NULL) {
            config->file_name = strpbrk(argv[i], "=") + 1;
        } else if(strstr(argv[i], "--set") != NULL) {
            config->prop_name = strpbrk(argv[i], "=") + 1;
            config->type = SET;
        } else if(strstr(argv[i], "--value") != NULL) {
            config->prop_value = strpbrk(argv[i], "=") + 1;
            config->type = SET;
        } else if(strstr(argv[i], "--get") != NULL) {
            config->prop_name = strpbrk(argv[i], "=") + 1;
            config->type = GET;
        } else if(strstr(argv[i], "--show") != NULL) {
            config->type = SHOW;
        }
    }
    if(config->type == NOTHING) {
        printf("Specify type\n");
        exit(EXIT_FAILURE);
    }
    if(config->type == GET && config->prop_name == NULL) {
        printf("Enter property\n");
        exit(EXIT_FAILURE);
    }
    if(config->type == SET && (config->prop_name == NULL || config->prop_value == NULL)) {
        printf("Enter property and value\n");
        exit(EXIT_FAILURE);
    }
    return config;
}

u_int32_t parse_size(const char* bytes, char max_bit) {
    u_int32_t res = 0;
    u_int32_t shift = 0;
    for(char i = 0; i < 4; i++) {\
        u_int32_t byte = bytes[3 - i];
        for(char j = 0; j < max_bit; j++) {
            res += (byte & 1u) * (1u << shift);
            shift++;
            byte >>= 1u;
        }
    }
    return res;
}

struct FileHeader* read_file_header(FILE *file) {
    struct FileHeader *header = malloc(sizeof(struct FileHeader));
    if(
            fread(header->identifier, sizeof(char), 3, file) < 0 ||
            fread(header->version, sizeof(char), 2, file) < 0 ||
            fread(&header->flags, sizeof(char), 1, file) < 0 ||
            fread(&header->size, sizeof(char), 4, file) < 0
            ) {
        printf("can't read file!\n");
        exit(EXIT_FAILURE);
    }
    header->size = parse_size((char *)&header->size, 7);
    return header;
}

struct FrameHeader* read_frame_header(FILE *file) {
    struct FrameHeader *header = malloc(sizeof(struct FrameHeader));
    header->name[4] = 0;
    header->useless = 0;
    if(
            fread(header->name, sizeof(char), 4, file) < 0 ||
            fread(&header->size, sizeof(char), 4, file) < 0 ||
            fread(&header->flags, sizeof(char), 2, file) < 0
            ) {
        printf("can't read tag in!\n");
        exit(EXIT_FAILURE);
    }
    header->size = parse_size((char*)&header->size, 8);
    if((header->name[0] == 'T') && (header->name[1] != 'X')) {
        read_text_frame(header, file);
    } else if((header->name[0] == 'W') && (header->name[1] != 'X')) {
        read_url_frame(header, file);
    } else if (strcmp(header->name, "COMM") == 0) {
        read_comment_frame(header, file);
    } else {
        header->useless = 1;
        // skip frame
        fseek(file, header->size, SEEK_CUR);
    }
    return header;
}


void read_text_frame(struct FrameHeader *frame, FILE *file) {
    frame->size--;
    //skip encoding
    fseek(file, 1, SEEK_CUR);
    frame->content = malloc(frame->size);
    frame->position = ftell(file);
    fread(frame->content, sizeof(char), frame->size, file);
}

void read_url_frame(struct FrameHeader *frame, FILE *file) {
    frame->content = malloc(frame->size);
    frame->position = ftell(file);
    fread(frame->content, sizeof(char), frame->size, file);
}

void read_comment_frame(struct FrameHeader *frame, FILE *file) {
    frame->size -= 4;
    //skip encoding and language
    fseek(file, 4, SEEK_CUR);
    frame->content = malloc(frame->size);
    frame->position = ftell(file);
    fread(frame->content, sizeof(char), frame->size, file);
}

void show_all(struct FrameHeader** frames, u_int32_t size) {
    printf("[Get all]\n");
    for(int i = 0; i < size; i++) {
        if(!frames[i]->useless) {
            printf("%s: ", frames[i]->name);
            for(int j = 0; j < frames[i]->size; j++) {
                putchar(frames[i]->content[j]);
            }
            printf("\n");
        }
    }
}

void show(struct FrameHeader** frames, u_int32_t size, struct Config *config) {
    for(int i = 0; i < size; i++) {
        if(!frames[i]->useless && strcmp(frames[i]->name, config->prop_name) == 0) {
            printf("[Get]\n%s: ", frames[i]->name);
            for(int j = 0; j < frames[i]->size; j++) {
                putchar(frames[i]->content[j]);
            }
            printf("\n");
            return;
        }
    }
    printf("No such frame\n");
}

void set(struct FrameHeader** frames, u_int32_t size, struct Config *config) {
    for(int i = 0; i < size; i++) {
        if(!frames[i]->useless && strcmp(frames[i]->name, config->prop_name) == 0) {
            if(strlen(config->prop_value) > frames[i]->size) {
                printf("Prop value too big\n");
                exit(EXIT_FAILURE);
            }

            FILE *file = fopen(config->file_name, "r+");

            printf("[Set] %s: ", frames[i]->name);
            bzero(frames[i]->content, frames[i]->size);
            for(int j = 0; j < strlen(config->prop_value); j++) {
                frames[i]->content[j] = config->prop_value[j];
                putchar(frames[i]->content[j]);
            }
            printf("\n");

            fseek(file, frames[i]->position, SEEK_SET);
            fwrite(frames[i]->content, sizeof(char), frames[i]->size, file);
            fclose(file);
            return;
        }
    }
    printf("No such frame: %s\n", config->prop_name);
}
