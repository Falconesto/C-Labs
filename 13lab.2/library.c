//
// Created by Александр on 06.12.2019.
//

#include "library.h"

struct Configuration *build_args(int argc, char **argv) {
    struct Configuration *config = malloc(sizeof(struct Configuration));
    memset(config, 0, sizeof(struct Configuration));
    config->type = NOTHING;
    for (int i = 1; i < argc; i++) {
        if (strstr(argv[i], "--filepath") != NULL) {
            config->file_name = strstr(argv[i], "=") + 1;
        } else if (strstr(argv[i], "--set") != NULL) {
            config->prop_name = strstr(argv[i], "=") + 1;
            config->type = SET;
        } else if (strstr(argv[i], "--value") != NULL) {
            config->prop_value = strstr(argv[i], "=") + 1;
            config->type = SET;
        } else if (strstr(argv[i], "--get") != NULL) {
            config->prop_name = strstr(argv[i], "=") + 1;
            config->type = GET;
        } else if (strstr(argv[i], "--show") != NULL) {
            config->type = SHOW;
        }
    }
    if (config->type == NOTHING) {
        printf("Utochnite\n");
        exit(EXIT_FAILURE);
    }
    return config;
}

size_t build_size(const char *bytes, char max_bit) {
    size_t res = 0;
    size_t shift = 0;
    for (char i = 0; i < 4; i++) {

        size_t byte = bytes[3 - i];
        for (char j = 0; j < max_bit; j++) {
            res += (byte & 1u) * (1u << shift);
            shift++;
            byte >>= 1u;
        }
    }
    return res;
}

struct FileHeader *read_file_header(FILE *file) {
    struct FileHeader *header = malloc(sizeof(struct FileHeader));
    if (
            fread(header->identifier, sizeof(char), 3, file) < 0 ||
            fread(header->version, sizeof(char), 2, file) < 0 ||
            fread(&header->flags, sizeof(char), 1, file) < 0 ||
            fread(&header->size, sizeof(char), 4, file) < 0
            ) {
        printf("can't read file!\n");
        exit(EXIT_FAILURE);
    }
    header->size = build_size((char *) &header->size, 7);
    return header;
}

struct FrameHeader *read_frame_header(FILE *file) {
    struct FrameHeader *header = malloc(sizeof(struct FrameHeader));
    header->name[4] = 0;
    header->nenuzhno = 0;
    if ((fread(&header->name, sizeof(char), 4, file) < 0) || (fread(&header->size, sizeof(char), 4, file) < 0) || (fread(&header->flags, sizeof(char), 2, file) < 0)) {
        printf("can't read tag in!\n");
        exit(EXIT_FAILURE);
    }
    header->size = build_size((char *) &header->size, 8);
    if ((header->name[0] == 'T') && (header->name[1] != 'X')) {
        read_text_frame(header, file);
    } else if ((header->name[0] == 'W') && (header->name[1] != 'X')) {
        read_url_frame(header, file);
    } else {
        header->nenuzhno = 1;
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

void get_particular(struct FrameHeader **frames, size_t size, struct Configuration *config) {
    for (int i = 0; i < size; i++) {
        if (!frames[i]->nenuzhno && strcmp(frames[i]->name, config->prop_name) == 0) {
            for (int j = 0; j < frames[i]->size; j++) {
                putchar(frames[i]->content[j]);
            }
            printf("\n");
            return;
        }
    }
    printf("Nema freyma\n");
}

void show(struct FrameHeader **frames, size_t size) {
    for (int i = 0; i < size; i++) {
        if (!frames[i]->nenuzhno) {
            printf("%s: ", frames[i]->name);
            for (int j = 0; j < frames[i]->size; j++) {
                putchar(frames[i]->content[j]);
            }
            printf("\n");
        }
    }
}

void set(struct FrameHeader **frames, size_t size, struct Configuration *config, FILE *file) { //fail peredat
    for (int i = 0; i < size; i++) {
        if (!frames[i]->nenuzhno && strcmp(frames[i]->name, config->prop_name) == 0) {
            if (strlen(config->prop_value) > frames[i]->size) {
                printf("oy mnoga strashno virubay\n");
                exit(EXIT_FAILURE);
            }
            memset(frames[i]->content, 0, frames[i]->size);
            for (int j = 0; j < strlen(config->prop_value); j++) {
                frames[i]->content[j] = config->prop_value[j];
                putchar(frames[i]->content[j]);
            }
            printf("\n");

            fseek(file, frames[i]->position, SEEK_SET);
            fwrite(frames[i]->content, sizeof(char), frames[i]->size, file);
            return;
        }
    }
    printf("Nema freyma: %s\n", config->prop_name);
}
