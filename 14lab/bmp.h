//
// Created by Александр on 06.12.2019.
//

#ifndef C_LIB_H
#define C_LIB_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structs.h"
#include <windows.h>
#include "lib/gd-2.0.33-1-bin/include/gd.h"

struct game_config* parse_args(int args, char **argv);

int is_white(gdImagePtr image, int x, int y);

void read_image(char *input_file, struct game_status *state);

void create_image(int step, struct game_status *state, struct game_config *config);

void create_directory(char *directory_name);

#endif //C_LIB_H
