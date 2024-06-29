#include <ncurses.h>
#include <time.h>

#include "brick_game/tetris/headers/backend.h"
#include "gui/cli/frontend.h"

#define ENTER 10

int get_user_action() {
  int input_key = getch();
  switch (input_key) {
    case ENTER:
      return Start;
      break;
    case 'p':
      return Pause;
      break;
    case 'q':
      return Terminate;
      break;
    case 'r':
      return Action;
      break;
    case KEY_LEFT:
      return Left;
      break;
    case KEY_RIGHT:
      return Right;
      break;
    case KEY_UP:
      return Up;
      break;
    case KEY_DOWN:
      return Down;
      break;
    default:
      return -1;
      break;
  }
}

void game_loop() {
  print_start();
  game_params* prms = get_current_game_prms();
  game_params_init(prms);
  while (prms->break_flag) {
    if (prms->state != START && prms->state != GAME_OVER) {
      render(updateCurrentState());
    }

    if (prms->state == START) {
      print_start();
    }
    if (prms->state == GAME_OVER) {
      print_gameover();
    }
    userInput(get_user_action(), 0);
  }
  game_params_deinit(prms);
}

int main() {
  srand(time(NULL));
  enable_curses();
  game_loop();
  disable_curses();
  return 0;
}