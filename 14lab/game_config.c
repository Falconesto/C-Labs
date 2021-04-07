//
// Created by Александр on 06.12.2019.
//
#include <stdlib.h>
#include <unistd.h>
#include "game_config.h"

struct game_status *init_game_status() {
    struct game_status *state = malloc(sizeof(struct game_status));

    // fill the universe with zeroes
    for (int y = 0; y < GAME_HEIGHT; y++) {
        for (int x = 0; x < GAME_WIDTH; x++) {
            state->universe[y][x] = 1;
            state->next_generation[y][x] = 1;
        }
    }
    return state;
}

int get_neighbours_count(struct game_status *status, int x, int y) {
    int ans = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            int x1 = x + i;
            int y1 = y + j;
            if (x1 == 1 && y1 == 1) continue;
            if (x1 < 0 || x1 >= GAME_WIDTH) continue;
            if (y1 < 0 || y1 >= GAME_HEIGHT) continue;
            if (status->universe[y1][x1] == 0) ans++;
        }
    }
    return ans;
}

void merge_next_generation(struct game_status *status) {
    for (int y = 0; y < GAME_HEIGHT; y++) {
        for (int x = 0; x < GAME_WIDTH; x++) {
            status->universe[y][x] = status->next_generation[y][x];
            status->next_generation[y][x] = 1;
        }
    }
}

void live_generation(struct game_status *status) {
    for (int y = 0; y < GAME_HEIGHT; y++) {
        for (int x = 0; x < GAME_WIDTH; x++) {
            int n = get_neighbours_count(status, x, y);
            if (n == 3 && status->universe[y][x] == 1) {
                status->next_generation[y][x] = 0;
            } else if ((n == 2 || n == 3) && status->universe[y][x] == 0) {
                status->next_generation[y][x] = 0;
            } else {
                status->next_generation[y][x] = 1;
            }
        }
    }
}

int check_change(struct game_status *status) {
    for (int y = 0; y < GAME_HEIGHT; y++) {
        for (int x = 0; x < GAME_WIDTH; x++) {
            if (status->universe[y][x] != status->next_generation[y][x]) {
                return 1;
            }
        }
    }
    return 0;
}

void run(struct game_config *conf) {
    struct game_status *status= init_game_status();
    read_image(conf->input_file, status);
    create_image(0, status, conf);
    for (int steps = 0; steps != conf->max_steps; steps++) {
        live_generation(status);

        if (check_change(status) == 0) {
            break;
        }

        merge_next_generation(status);
        if (steps % conf->dump_frequency == 0) {
            create_image(steps + 1, status, conf);
        }
    }
    printf("THE END\n");
}