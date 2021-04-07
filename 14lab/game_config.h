//
// Created by Александр on 06.12.2019.
//

#ifndef C_GAME_H
#define C_GAME_H
#include "structs.h"
#include "bmp.h"

struct game_status *init_game_status();

int check_change(struct game_status *status);

int get_neighbours_count(struct game_status *status, int x, int y);

void merge_next_generation(struct game_status *status);

void live_generation(struct game_status *status);

void run(struct game_config *conf);

#endif //C_GAME_H
