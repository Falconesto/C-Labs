#include "library.h"



int main(int argc, char **argv) {
    struct FrameHeader* frames[MAX_FRAME_NUMBER];
    memset(frames, 0, sizeof(struct FrameHeader*) * MAX_FRAME_NUMBER);
    struct Configuration *config = build_args(argc, argv);

    FILE *file = fopen(config->file_name, "r+");
    if(file == NULL) {
        printf("can't open %s\n", config->file_name);
        exit(EXIT_FAILURE);
    }

    struct FileHeader* file_header = read_file_header(file);
    size_t size = 10;
    size_t frames_count = 0;

    while(size < file_header->size) {
        struct FrameHeader  *frame_header = read_frame_header(file);
        size += frame_header->size + 10;
        frames[frames_count++] = frame_header;
    }

    if(config->type == SHOW) {
        show(frames, frames_count);
    } else if(config->type == GET) {
        get_particular(frames, frames_count, config);
    } else {
        set(frames, frames_count, config, file);
    }
    fclose(file);

    return 0;
}