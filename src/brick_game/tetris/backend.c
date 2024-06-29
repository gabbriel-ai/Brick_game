#include "headers/backend.h"
/**
 * @brief Check collide tetramino
 *
 * Check collision tetramino
 *
 * @param argc 2
 * @param argv game_field tetramino
 *
 * @return Is tetramino collide
 */
bool is_collide(int **game_field, Tetramino_t *tetramino) {
  if (is_collide_walls(tetramino) || is_collide_field(game_field, tetramino)) {
    return true;
  }
  return false;
}
/**
 * @brief Check collide tetramino with walls
 *
 * Check collision tetramino with walls
 *
 * @param argc 1
 * @param argv tetramino
 *
 * @return Is tetramino collide with wall
 */
bool is_collide_walls(Tetramino_t *tetramino) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if ((tetramino->pos.x + j - 2 < 0 || tetramino->pos.x + j - 2 > 9 ||
           tetramino->pos.y + i - 2 > 19) &&
          tetramino->states[tetramino->state][i][j] == 1) {
        return true;
      }
    }
  }
  return false;
}
/**
 * @brief Check collide tetramino with field
 *
 * Check collision tetramino with field
 *
 * @param argc 2
 * @param argv game_field tetramino
 *
 * @return Is tetramino collide with field
 */
bool is_collide_field(int **game_field, Tetramino_t *tetramino) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (is_valid_pos(tetramino, j, i) &&
          tetramino->states[tetramino->state][i][j] == 1) {
        if (game_field[tetramino->pos.y + i - 2][tetramino->pos.x + j - 2] ==
            1) {
          return true;
        }
      }
    }
  }
  return false;
}
/**
 * @brief check Tetramino on valid position
 *
 * check Tetramino on valid position
 *
 * @param argc 3
 * @param argv tetramino field_pos_x field_pos_y
 *
 * @return Is valid position
 */
bool is_valid_pos(Tetramino_t *tetramino, int pos_x, int pos_y) {
  if (tetramino->pos.x + pos_x - 2 >= 0 && tetramino->pos.x + pos_x - 2 <= 9 &&
      tetramino->pos.y + pos_y - 2 >= 0 && tetramino->pos.y + pos_y - 2 <= 19) {
    return true;
  }
  return false;
}

/**
 * @brief Update info in game_info_ext
 *
 *  Update info in game_info_ext
 *
 * @param argc 1
 * @param argv GameInfoExtended_t
 */
void update_info(GameInfoExtended_t *game_info_ext) {
  int lines = 0;
  for (int i = 19; i >= 0; i--) {
    if (is_line_full(game_info_ext->game_info.field, i)) {
      clear_line(game_info_ext->game_info.field, i);
      shift_down(game_info_ext->game_info.field, i);
      lines++;
      i++;
    }
  }
  update_score(game_info_ext, lines);
  update_speed(game_info_ext);
}

/**
 * @brief Update score in game_info_ext
 *
 *  Update score in game_info_ext
 *
 * @param argc 2
 * @param argv GameInfoExtended_t, clear_lines
 */
void update_score(GameInfoExtended_t *game_info_ext, int lines) {
  if (lines == 1) {
    game_info_ext->game_info.score += 100;
  } else if (lines == 2) {
    game_info_ext->game_info.score += 300;
  } else if (lines == 3) {
    game_info_ext->game_info.score += 700;
  } else if (lines >= 4) {
    game_info_ext->game_info.score += 1500;
  }
  if (game_info_ext->game_info.score > game_info_ext->game_info.high_score) {
    game_info_ext->game_info.high_score = game_info_ext->game_info.score;
  }
}

/**
 * @brief Update speed and level by score
 *
 * Update speed and level by score
 *
 * @param argc 1
 * @param argv GameInfoExtended_t
 */
void update_speed(GameInfoExtended_t *game_info_ext) {
  int level = game_info_ext->game_info.score / 600 + 1;
  if (level > 10) {
    level = 10;
  }
  game_info_ext->game_info.level = level;
  game_info_ext->game_info.speed = level;
}

/**
 * @brief Is line full
 *
 * Check is line full
 *
 * @param argc 2
 * @param argv game_field, line
 *
 * @return bool
 */
bool is_line_full(int **game_field, int y) {
  for (int i = 0; i < 10; i++) {
    if (game_field[y][i] == 0) {
      return false;
    }
  }
  return true;
}

/**
 * @brief clear line
 *
 * clear line
 *
 * @param argc 2
 * @param argv game_field, line
 */
void clear_line(int **game_field, int y) {
  for (int i = 0; i < 10; i++) {
    game_field[y][i] = 0;
  }
}

/**
 * @brief shift down
 *
 * shift all values down
 *
 * @param argc 2
 * @param argv game_field, line
 */
void shift_down(int **game_field, int y) {
  for (int i = y; i >= 1; i--) {
    for (int j = 0; j < 10; j++) {
      game_field[i][j] = game_field[i - 1][j];
    }
  }
  for (int i = 0; i < 10; i++) {
    game_field[0][i] = 0;
  }
}

/**
 * @brief reset Extended game_info
 *
 * reset to start value Extendad game_ifno
 *
 * @param argc 1
 * @param argv game_info_ext
 */
void reset_game_info_ext(GameInfoExtended_t *game_info_ext) {
  memset(&game_info_ext->current_tetramino, 0, sizeof(Tetramino_t));
  reset_game_info(&game_info_ext->game_info);
  game_info_ext->next_tetramino =
      get_rand_tetramino(&game_info_ext->default_tetronimus);
  tetramino_next_copy(
      game_info_ext->next_tetramino.states[game_info_ext->next_tetramino.state],
      game_info_ext->game_info.next);
}

/**
 * @brief reset game_info
 *
 * reset to start value game_ifno
 *
 * @param argc 1
 * @param argv game_info
 */
void reset_game_info(GameInfo_t *game_info) {
  reset_field(game_info->field);
  if (game_info->score > game_info->high_score) {
    game_info->score = game_info->high_score;
  }
  game_info->score = 0;
  game_info->pause = 0;
  game_info->speed = 1;
  game_info->level = 1;
}

/**
 * @brief reset field
 *
 * fill field zeros
 *
 * @param argc 1
 * @param argv game_field
 */
void reset_field(int **game_field) {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      game_field[i][j] = 0;
    }
  }
}

/**
 * @brief get HighScore from file
 *
 * get HighScore from file
 *
 * @param argc 0
 * @return Int
 */
int get_high_score() {
  int score = 0;
  FILE *fptr;
  mkdir("data", 0700);
  fptr = fopen("./data/highscore", "r");
  if (fptr == NULL) {
    fptr = fopen("./data/highscore", "w");
    fprintf(fptr, "%d", 0);
    fclose(fptr);
    return score;
  }
  fseek(fptr, 0, SEEK_END);
  if (ftell(fptr) == 0) {
    score = 0;
  }
  fseek(fptr, 0, SEEK_SET);
  fscanf(fptr, "%d", &score);
  fclose(fptr);
  return score;
}

/**
 * @brief save HighScore to file
 *
 * save HighScore to file
 *
 * @param argc 1
 * @param argv game_params
 */
void write_high_score(game_params *prms) {
  if (prms->game_info_ext.game_info.score >
      prms->game_info_ext.game_info.high_score) {
    FILE *fptr;
    fptr = fopen("./data/highscore", "w");
    if (fptr != NULL) {
      fprintf(fptr, "%d", prms->game_info_ext.game_info.score);
    }
    fclose(fptr);
  }
}

/**
 * @brief update_time
 *
 * add delta to between presses to gameParams
 *
 * @param argc 1
 * @param argv game_params
 */
void update_time(game_params *prms) {
  double tenths = current_mils() / 1000.0;
  if (prms->last_time == 0) {
    prms->last_time = tenths;
  } else {
    prms->time += tenths - prms->last_time;
    prms->last_time = tenths;
  }
}

/**
 * @brief get current time in millis
 *
 * get current time in millis
 *
 * @param argc 0
 * @return long int
 */
long int current_mils() {
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return tp.tv_sec * 1000 + tp.tv_usec / 1000;
}
