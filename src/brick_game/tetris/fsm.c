#include "headers/backend.h"

action fsm_table[8][9] = {
    {NULL, NULL, NULL, NULL, NULL, exitstate, spawn, NULL, NULL},
    {spawn, spawn, spawn, spawn, spawn, spawn, spawn, spawn, spawn},
    {move_left, move_right, drop, rotate, NULL, exitstate, NULL, pause,
     shifting},
    {NULL, NULL, NULL, NULL, NULL, exitstate, NULL, pause, NULL},
    {shifting, shifting, shifting, shifting, shifting, shifting, shifting,
     shifting},
    {attaching, attaching, attaching, attaching, attaching, attaching,
     attaching, attaching, attaching},
    {exitstate, exitstate, exitstate, exitstate, exitstate, exitstate,
     exitstate, exitstate, exitstate},
    {NULL, NULL, NULL, NULL, NULL, exitstate, spawn, NULL, NULL}};

/**
 * @brief Singleton to game params
 *
 * Singleton to game params
 *
 * @param argc 0
 * @return pointer to game params
 */
game_params *get_current_game_prms() {
  static game_params prms = {0};
  return &prms;
}

/**
 * @brief Init game params
 *
 * Set game params to start value
 *
 * @param argc 1
 * @param argv game_params*
 */
void game_params_init(game_params *prms) {
  game_info_ext_init(&prms->game_info_ext);
  prms->break_flag = 1;
  prms->state = START;
  prms->game_info_ext.game_info.high_score = get_high_score();
}

/**
 * @brief Deinit game params
 *
 * deinit game params
 *
 * @param argc 1
 * @param argv game_params
 */
void game_params_deinit(game_params *prms) {
  game_info_ext_deinit(&prms->game_info_ext);
  prms->break_flag = 0;
  prms->state = 0;
  write_high_score(prms);
  prms->game_info_ext.game_info.high_score = 0;
}

/**
 * @brief get current game info
 *
 * save HighScore to file
 *
 * @param argc 0
 * @return Game_info
 */
GameInfo_t updateCurrentState() {
  return get_current_game_prms()->game_info_ext.game_info;
}

/**
 * @brief get user input
 *
 * get user input and send signal
 *
 * @param argc 2
 * @param argv game_params, hold
 */
void userInput(UserAction_t action, bool hold) {
  (void)hold;

  game_params *prms = get_current_game_prms();

  sigact(get_signal(action), prms);
}

/**
 * @brief get signal
 *
 * get signal and act state
 *
 * @param argc 2
 * @param argv sig, game_params
 */
void sigact(signals sig, game_params *prms) {
  update_time(prms);
  action act = NULL;
  act = fsm_table[prms->state][sig];

  field_clear(prms->game_info_ext.game_info.field,
              &prms->game_info_ext.current_tetramino);

  if (act) {
    act(prms);
  }
  field_update(prms->game_info_ext.game_info.field,
               &prms->game_info_ext.current_tetramino);
}

/**
 * @brief get signal
 *
 * get signal by user input
 *
 * @param argc 1
 * @param argv user_input
 * @return signal
 */
signals get_signal(UserAction_t user_input) {
  signals rc = NOSIG;
  if (user_input == Left)
    rc = MOVE_LEFT;
  else if (user_input == Right)
    rc = MOVE_RIGHT;
  else if (user_input == Down)
    rc = MOVE_DOWN;
  else if (user_input == Action)
    rc = ROTATE_BTN;
  else if (user_input == Pause)
    rc = PAUSE_BTN;
  else if (user_input == Start)
    rc = ENTER_BTN;
  else if (user_input == Terminate) {
    rc = ESCAPE_BTN;
  }
  return rc;
}

/**
 * @brief spawn
 *
 * spawn tetramino and get next
 *
 * @param argc 1
 * @param argv prms
 */
void spawn(game_params *prms) {
  GameInfoExtended_t *game_info_ext = &prms->game_info_ext;
  game_info_ext->current_tetramino = game_info_ext->next_tetramino;
  game_info_ext->next_tetramino =
      get_rand_tetramino(&game_info_ext->default_tetronimus);
  game_info_ext->current_tetramino.pos.x = 5;
  game_info_ext->current_tetramino.pos.y = 0;
  tetramino_next_copy(
      game_info_ext->next_tetramino.states[game_info_ext->next_tetramino.state],
      game_info_ext->game_info.next);
  prms->state = MOVING;
}

/**
 * @brief move left
 *
 * move left tetramino
 *
 * @param argc 1
 * @param argv prms
 */
void move_left(game_params *prms) {
  GameInfoExtended_t *game_info_ext = &prms->game_info_ext;

  game_info_ext->current_tetramino.pos.x--;
  if (is_collide(game_info_ext->game_info.field,
                 &game_info_ext->current_tetramino)) {
    game_info_ext->current_tetramino.pos.x++;
  }

  shifting(prms);
  prms->state = MOVING;
}

/**
 * @brief move right
 *
 * move right tetramino
 *
 * @param argc 1
 * @param argv prms
 */
void move_right(game_params *prms) {
  GameInfoExtended_t *game_info_ext = &prms->game_info_ext;

  game_info_ext->current_tetramino.pos.x++;
  if (is_collide(game_info_ext->game_info.field,
                 &game_info_ext->current_tetramino)) {
    game_info_ext->current_tetramino.pos.x--;
  }

  shifting(prms);
  prms->state = MOVING;
}

/**
 * @brief move down
 *
 * move down tetramino
 *
 * @param argc 1
 * @param argv prms
 */
void move_down(game_params *prms) {
  GameInfoExtended_t *game_info_ext = &prms->game_info_ext;

  game_info_ext->current_tetramino.pos.y++;
  if (is_collide(game_info_ext->game_info.field,
                 &game_info_ext->current_tetramino)) {
    game_info_ext->current_tetramino.pos.y--;
    prms->state = ATTACHING;
  }
  if (prms->state != ATTACHING) {
    prms->state = MOVING;
  }
}

/**
 * @brief rotate
 *
 * rotate left tetramino
 *
 * @param argc 1
 * @param argv prms
 */
void rotate(game_params *prms) {
  GameInfoExtended_t *game_info_ext = &prms->game_info_ext;

  int old_state = game_info_ext->current_tetramino.state;
  game_info_ext->current_tetramino.state =
      (game_info_ext->current_tetramino.state + 1) %
      game_info_ext->current_tetramino.total_state;
  if (is_collide(game_info_ext->game_info.field,
                 &game_info_ext->current_tetramino)) {
    game_info_ext->current_tetramino.state = old_state;
  }
  shifting(prms);
  prms->state = MOVING;
}

/**
 * @brief shifting
 *
 * move down if time delta between presses >= 1.1
 *
 * @param argc 1
 * @param argv prms
 */
void shifting(game_params *prms) {
  if (prms->time >= 1.1 - prms->game_info_ext.game_info.speed / 10.0) {
    prms->time = 0;
    move_down(prms);
  } else {
    prms->state = MOVING;
  }
}

/**
 * @brief drop
 *
 * momenut drop figure to down
 *
 * @param argc 1
 * @param argv prms
 */
void drop(game_params *prms) {
  while (prms->state != ATTACHING) {
    move_down(prms);
  }
}

/**
 * @brief pause
 *
 * pause game
 *
 * @param argc 1
 * @param argv prms
 */
void pause(game_params *prms) {
  if (prms->state == PAUSED) {
    prms->state = MOVING;
    prms->game_info_ext.game_info.pause = 0;
  } else {
    prms->game_info_ext.game_info.pause = 1;
    prms->state = PAUSED;
  }
}

/**
 * @brief attaching
 *
 * attaching tetramino to field
 *
 * @param argc 1
 * @param argv prms
 */
void attaching(game_params *prms) {
  field_update(prms->game_info_ext.game_info.field,
               &prms->game_info_ext.current_tetramino);
  memset(&prms->game_info_ext.current_tetramino, 0, sizeof(Tetramino_t));
  update_info(&prms->game_info_ext);
  for (int i = 0; i < 10; i++) {
    if (prms->game_info_ext.game_info.field[0][i] == 1) {
      prms->state = GAME_OVER;
      reset_game_info_ext(&prms->game_info_ext);
    }
  }
  if (prms->state != GAME_OVER) {
    prms->state = SPAWN;
  }
}

/**
 * @brief exit
 *
 * set break_flag to zero
 *
 * @param argc 1
 * @param argv prms
 */
void exitstate(game_params *prms) { prms->break_flag = 0; }
