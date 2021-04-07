//
// Created by Александр on 06.12.2019.
//

#include <io.h>
#include "bmp.h"


struct game_config *parse_args(int args, char **argv) {
    struct game_config *conf = malloc(sizeof(struct game_config));

    conf->max_steps = 20;
    conf->dump_frequency = 1;

    //set up game_config
    for(int i = 1; i < args; i++) {
        if(strcmp(argv[i], "--input") == 0) {
            conf->input_file = argv[i + 1];
            i += 1;
        } else if( strcmp(argv[i], "--output") == 0) {
            conf->output_directory = argv[i + 1];
            i += 1;
        } else if( strcmp(argv[i], "--max_iter") == 0) {
            conf->max_steps = (int)strtol(argv[i + 1], NULL, 10);
            if(conf->max_steps == 0) {
                fprintf(stderr, "Please write correct integer after --max_iter\n");
                exit(1);
            }
            i += 1;
        } else if( strcmp(argv[i], "--dump_freq") == 0) {
            conf->dump_frequency = (int) strtol(argv[i + 1], NULL, 10);
            if(conf->dump_frequency == 0) {
                fprintf(stderr, "Please write correct integer after --dump_freq\n");
                exit(1);
            }
            i += 1;
        } else {
            fprintf(stderr, "Unknown argument \"%s\"\n", argv[i]);
            exit(1);
        }
    }
    if(conf->input_file == NULL || conf->output_directory == NULL) {
        fprintf(stderr, "Please specify input and output file\n");
        exit(1);
    }
    return conf;
}


int is_white(gdImagePtr image, int x, int y) {
    // check that pixel is white
    int c = gdImageGetPixel(image, x, y);
    return image->red[c] == 255 && image->green[c] == 255 && image->blue[c] == 255;
}


void read_image(char *input_file, struct game_status *state) {
    // Read image
    FILE* image_file = fopen(input_file, "rb");
    if(image_file == NULL) {
        perror("Error while opening input image file:\n");
        exit(1);
    }
    gdImagePtr image = gdImageCreateFromWBMP(image_file);
    fclose(image_file);

    // check that image is valid
    if(gdImageSX(image) < GAME_WIDTH) {
        fprintf(stderr, "Image width is too low, please make it bigger!\n");
        exit(1);
    }
    if(gdImageSY(image) < GAME_HEIGHT) {
        fprintf(stderr, "Image height is too low, please make it bigger!\n");
        exit(1);
    }

    // fill state
    for(int y = 0; y < GAME_HEIGHT; y++) {
        for(int x = 0; x < GAME_WIDTH; x++) {
            if(is_white(image, x, y)) {
                state->universe[y][x] = 1;
            }
        }
    }
}

void create_image(int step, struct game_status *state, struct game_config *config) {
    char *file_name = malloc(sizeof(char) * 100);
    memset(config, 100, sizeof(char) * 100);
    sprintf(file_name, "%s/%d.bmp", config->output_directory, step);

    FILE *image_file = fopen(file_name, "wb");
    if(image_file == NULL) {
        perror("Error while opening output image file:\n");
        exit(1);
    }

    gdImagePtr image = gdImageCreate(GAME_WIDTH, GAME_HEIGHT);
    int white = gdImageColorAllocate(image, 255, 255, 255);
    int black = gdImageColorAllocate(image, 0, 0, 0);
    for(int y = 0; y < GAME_HEIGHT; y++) {
        for(int x = 0; x < GAME_WIDTH; x++) {
            // cell here
            if(state->universe[y][x]) {
                gdImageSetPixel(image, x, y, black);
            } else {
                gdImageSetPixel(image, x, y, white);
            }
        }
    }
    gdImageWBMP(image, black, image_file);
    fclose(image_file);
    gdImageDestroy(image);
}

void create_directory(char *directory_name) {
    if(CreateDirectory(directory_name, 0) < 0) {
        perror("Error while creating directory:\n");
        exit(EXIT_FAILURE);
    }
}
