//
// Created by Александр on 06.12.2019.
//

#ifndef C_LIBRARY_H
#define C_LIBRARY_H

#include "stdlib.h"
#include "stdio.h"
#include "string.h"


enum INPUT_TYPE {
    GET,
    SET,
    SHOW,
    NOTHING,
};


struct Config {
    char *file_name;
    char *prop_name;
    char *prop_value;
    enum INPUT_TYPE type;
};

struct FileHeader {
    char identifier[3];
    char version[2];
    char flags;
    u_int32_t size;
};

struct FrameHeader {
    char name[5];
    u_int32_t size;
    u_int32_t position;
    char flags[2];
    char *content;
    char useless;
};


struct Config* parse_args(int argc, char **argv);

u_int32_t parse_size(const char* bytes, char max_bit);

struct FileHeader* read_file_header(FILE *file);

struct FrameHeader* read_frame_header(FILE *file);

void read_text_frame(struct FrameHeader *frame, FILE *file);

void read_url_frame(struct FrameHeader *frame, FILE *file);

void read_comment_frame(struct FrameHeader *frame, FILE *file);

void show_all(struct FrameHeader** frames, u_int32_t size);

void show(struct FrameHeader** frames, u_int32_t size, struct Config *config);

void set(struct FrameHeader** frames, u_int32_t size, struct Config *config);


#endif //C_LIBRARY_H
