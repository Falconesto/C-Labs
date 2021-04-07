#include <srv.h>
#include "library.h"


#define MAX_FRAMES 100


int main(int argc, char **argv) {
    struct FrameHeader* frames[MAX_FRAMES];
    srv_bzero(frames, sizeof(struct FrameHeader*) * MAX_FRAMES);

    struct Config *config = parse_args(argc, argv);

    FILE *file = fopen(config->file_name, "r");
    if(file == NULL) {
        printf("can't open %s\n", config->file_name);
        exit(EXIT_FAILURE);
    }

    struct FileHeader* file_header = read_file_header(file);
    u_int32_t size = 10;
    u_int32_t frames_count = 0;

    while(size < file_header->size) {
        struct FrameHeader  *frame_header = read_frame_header(file);
        size += frame_header->size + 10;
        frames[frames_count++] = frame_header;
    }

    fclose(file);

    if(config->type == SHOW) {
        show_all(frames, frames_count);
    } else if(config->type == GET) {
        show(frames, frames_count, config);
    } else {
        set(frames, frames_count, config);
    }
    return 0;
}