#include "frontend.h"

void print_overlay(void) {
  print_rectangle(0, GAMEBOARD_H, 0, GAMEBOARD_W);
  print_rectangle(0, STATSBOARD_H, STATSBOARD_LX, STATSBOARD_RX);
  print_rectangle(2, 7, STATSBOARD_LX + 2, STATSBOARD_RX - 2);

  mvprintw(1, 26, "%s", NEXTFIGURE);
  print_horizontal(STATSBOARD_LX, STATSBOARD_RX, 8);
  mvprintw(9, 27, "%s", HIGHSCORE);
  print_horizontal(STATSBOARD_LX, STATSBOARD_RX, 11);
  mvprintw(12, 29, "%s", SCORE);
  print_horizontal(STATSBOARD_LX, STATSBOARD_RX, 14);
  mvprintw(15, 26, "%s", LEVEL);
  print_horizontal(STATSBOARD_LX, STATSBOARD_RX, 16);
  mvprintw(17, 26, "%s", SPEED);
  print_horizontal(STATSBOARD_LX, STATSBOARD_RX, 18);

  print_controls();
}

void print_rectangle(int top_y, int bottom_y, int left_x, int right_x) {
  mvaddch(top_y, left_x, ACS_ULCORNER);
  mvaddch(top_y, right_x, ACS_URCORNER);
  mvaddch(bottom_y, left_x, ACS_LLCORNER);
  mvaddch(bottom_y, right_x, ACS_LRCORNER);

  print_horizontal(left_x, right_x, bottom_y);
  print_horizontal(left_x, right_x, top_y);
  print_vertical(top_y, bottom_y, left_x);
  print_vertical(top_y, bottom_y, right_x);
}

void print_horizontal(int left_x, int right_x, int y) {
  for (int i = left_x + 1; i < right_x; i++) {
    mvaddch(y, i, ACS_HLINE);
  }
}
void print_vertical(int top_y, int bottom_y, int x) {
  for (int i = top_y + 1; i < bottom_y; i++) {
    mvaddch(i, x, ACS_VLINE);
  }
}

void print_stats(GameInfo_t *game_info) {
  mvprintw(10, 31, "%d", game_info->high_score);
  mvprintw(13, 31, "%d", game_info->score);
  mvprintw(15, 33, "%d", game_info->level);
  mvprintw(17, 33, "%d", game_info->speed);
  if (game_info->pause == 1) {
    mvprintw(19, 28, "%s", "PAUSED");
  } else {
    clear_pause();
  }
}

void clear_pause() {
  for (int i = 0; i < 6; i++) {
    mvprintw(19, 28 + i, "%c", ' ');
  }
}

void print_board(GameInfo_t *game_info) {
  clear_board();
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      if (game_info->field[i][j] == 1) {
        mvaddch(1 + i, 1 + j * 2, '[');
        mvaddch(1 + i, 1 + j * 2 + 1, ']');
      }
    }
  }
}

void print_start() {
  mvprintw(9, 8, "%s", "TETRIS");
  mvprintw(11, 1, "%s", "PRESS ENTER TO START");
}

void print_controls() {
  print_rectangle(0, 9, 40, 60);
  mvprintw(1, 46, "%s", "CONTROLS");
  print_horizontal(40, 60, 2);
  mvprintw(3, 41, "%s", "PAUSE - \"P\"");
  mvprintw(4, 41, "%s", "EXIT GAME - \"Q\"");
  mvprintw(5, 41, "%s", "MOVE LEFT - \"<-\"");
  mvprintw(6, 41, "%s", "MOVE RIGHT - \"->\"");
  mvprintw(7, 41, "%s", "MOVE DOWN - \"down\"");
  mvprintw(8, 41, "%s", "ROTETE - \"R\"");
}

void clear_board() {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      mvaddch(1 + i, j + 1, ' ');
    }
  }
}

void print_next(GameInfo_t *game_info) {
  clear_next_board();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (game_info->next[i][j] == 1) {
        mvaddch(2 + i + 1, STATSBOARD_LX + 3 + j * 2, '[');
        mvaddch(2 + i + 1, STATSBOARD_LX + 3 + j * 2 + 1, ']');
      }
    }
  }
}

void clear_next_board() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 8; j++) {
      mvaddch(2 + i + 1, STATSBOARD_LX + 3 + j, ' ');
    }
  }
}

void render(GameInfo_t game_info) {
  print_board(&game_info);
  print_next(&game_info);
  print_stats(&game_info);
  refresh();
}

void print_gameover() {
  mvprintw(10, 7, "%s", "GAME OVER");
  mvprintw(11, 1, "%s", "PRESS enter TO START");
  mvprintw(12, 1, "%s", "PRESS q TO EXIT");
}

void enable_curses() {
  initscr();
  curs_set(0);
  cbreak();
  halfdelay(1);
  keypad(stdscr, TRUE);
  noecho();
  print_overlay();
}

void disable_curses() { endwin(); }