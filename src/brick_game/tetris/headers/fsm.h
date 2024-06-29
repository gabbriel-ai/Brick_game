#ifndef FSM_H
#define FSM_H

#include "objects.h"

typedef enum {
  START = 0,
  SPAWN,
  MOVING,
  PAUSED,
  SHIFTING,
  ATTACHING,
  EXIT_STATE,
  GAME_OVER
} player_state;

typedef enum {
  MOVE_LEFT = 0,
  MOVE_RIGHT,
  MOVE_DOWN,
  ROTATE_BTN,
  DROP_BTN,
  ESCAPE_BTN,
  ENTER_BTN,
  PAUSE_BTN,
  NOSIG
} signals;

typedef struct {
  GameInfoExtended_t game_info_ext;
  player_state state;
  bool break_flag;
  double time;
  double last_time;
} game_params;

game_params *get_current_game_prms();

void game_params_init(game_params *prms);
void game_params_deinit(game_params *prms);

signals get_signal(UserAction_t user_input);
void sigact(signals sig, game_params *params);

void userInput(UserAction_t action, bool hold);
GameInfo_t updateCurrentState();

typedef void (*action)(game_params *prms);

void spawn(game_params *prms);
void move_left(game_params *prms);
void move_right(game_params *prms);
void move_down(game_params *prmst);
void rotate(game_params *prms);
void shifting(game_params *prms);
void pause(game_params *prms);
void drop(game_params *prms);
void attaching(game_params *prms);
void exitstate(game_params *prms);

#endif