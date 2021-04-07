
#include "bmp.h"
#include "game_config.h"

int main(int argc, char **argv) {
    struct game_config *conf = parse_args(argc, argv);
    create_directory(conf->output_directory);
    run(conf);
    return 0;
}

