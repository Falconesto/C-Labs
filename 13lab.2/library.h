//
// Created by Александр on 06.12.2019.
//


#ifndef C_LIBRARY_H
#define C_LIBRARY_H

#include <stdint.h>
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define MAX_FRAME_NUMBER 100


enum Action {
    GET,
    SET,
    SHOW,
    NOTHING,
};


struct Configuration {
    char *file_name;
    char *prop_name;
    char *prop_value;
    enum Action type;
};

struct FileHeader {
    char identifier[3];
    char version[2];
    char flags;
    size_t size;
};

struct FrameHeader {
    char name[5];
    size_t size;
    size_t position;
    char flags[2];
    char *content;
    char nenuzhno;
};


struct Configuration* build_args(int argc, char **argv);

size_t build_size(const char* bytes, char max_bit);

struct FileHeader* read_file_header(FILE *file);

struct FrameHeader* read_frame_header(FILE *file);

void read_text_frame(struct FrameHeader *frame, FILE *file);

void read_url_frame(struct FrameHeader *frame, FILE *file);

void show(struct FrameHeader** frames, size_t size);

void get_particular(struct FrameHeader** frames, size_t size, struct Configuration *config);

void set(struct FrameHeader* frames[], size_t size, struct Configuration *config, FILE *file);


#endif //C_LIBRARY_H
