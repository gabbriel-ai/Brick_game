#ifndef BACKEND_H
#define BACKEND_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>

#include "defines.h"
#include "fsm.h"
#include "gameinfo.h"
#include "objects.h"
#include "tetramino.h"

void update_info(GameInfoExtended_t *game_info_ext);
bool is_line_full(int **game_field, int y);
void clear_line(int **game_field, int y);
void shift_down(int **game_field, int y);
void update_score(GameInfoExtended_t *game_info_ext, int lines);
void update_speed(GameInfoExtended_t *game_info_ext);

bool is_collide(int **game_field, Tetramino_t *tetramino);

bool is_collide_walls(Tetramino_t *tetramino);
bool is_collide_field(int **game_field, Tetramino_t *tetramino);
bool is_valid_pos(Tetramino_t *tetramino, int pos_x, int pos_y);

void reset_game_info_ext(GameInfoExtended_t *game_info_ext);
void reset_game_info(GameInfo_t *game_info);
void reset_field(int **game_field);

int get_high_score();
void write_high_score(game_params *prms);
void update_time(game_params *prms);
long int current_mils();

#endif
