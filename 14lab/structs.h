//
// Created by Александр on 06.12.2019.
//

#ifndef C_STRUCTS_H
#define C_STRUCTS_H

#define GAME_HEIGHT 10
#define GAME_WIDTH 10


struct game_config {
    int max_steps;
    int dump_frequency;
    char* input_file;
    char* output_directory;
};


struct game_status {
    char universe[GAME_HEIGHT][GAME_WIDTH];
    char next_generation[GAME_HEIGHT][GAME_WIDTH];
};

#endif //C_STRUCTS_H
