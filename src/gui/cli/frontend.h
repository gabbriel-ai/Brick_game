#ifndef FRONTEND_H
#define FRONTEND_H

#include "../../brick_game/tetris/headers/backend.h"
#include "ncurses.h"

#define OFFSET 1
#define INDENT 2

#define STANDART_H 20
#define STANDART_W 10

#define GAMEBOARD_H (20 + OFFSET)
#define GAMEBOARD_W (20 + OFFSET)

#define STATSBOARD_H GAMEBOARD_H
#define STATSBORAD_W (16 + OFFSET)

#define STATSBOARD_LX (GAMEBOARD_W + INDENT)
#define STATSBOARD_RX (GAMEBOARD_W + STATSBORAD_W)

#define SCORE "SCORE"
#define HIGHSCORE "HIGHSCORE"
#define LEVEL "LEVEL:"
#define SPEED "SPEED:"
#define NEXTFIGURE "NEXT FIGURE"
#define CONTROLS "CONTROLS:"

void enable_curses();
void disable_curses();

void print_overlay(void);
void print_rectangle(int top_y, int bottom_y, int left_x, int right_x);
void print_horizontal(int left_x, int right_x, int y);
void print_vertical(int top_y, int bottom_y, int x);
void print_stats(GameInfo_t *game_info);
void print_board(GameInfo_t *game_info);
void print_gameover();
void clear_board();
void clear_next_board();
void clear_pause();
void print_next(GameInfo_t *game_info);
void print_start();
void render(GameInfo_t game_info);
void print_controls();
#endif