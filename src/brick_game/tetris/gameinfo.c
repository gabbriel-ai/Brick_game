#include "headers/backend.h"

/**
 * @brief init Extended game info
 *
 * load game info
 * load tetraminous list
 * load next tetramino
 *
 * @param argc 1
 * @param argv GameInfoExtended
 */
void game_info_ext_init(GameInfoExtended_t *game_info_ext) {
  game_info_init(&game_info_ext->game_info);
  tetramino_list_init(&game_info_ext->default_tetronimus);
  memset(&game_info_ext->current_tetramino, 0, sizeof(Tetramino_t));
  game_info_ext->next_tetramino =
      get_rand_tetramino(&game_info_ext->default_tetronimus);
  tetramino_next_copy(
      game_info_ext->next_tetramino.states[game_info_ext->next_tetramino.state],
      game_info_ext->game_info.next);
}

/**
 * @brief deinit Extended game info
 *
 * Unload game info
 * Unload tetraminous list
 * Unlodo
 *
 * @param argc 1
 * @param argv GameInfoExtended
 */
void game_info_ext_deinit(GameInfoExtended_t *game_info_ext) {
  game_info_deinit(&game_info_ext->game_info);
  tetramino_list_deinit(&game_info_ext->default_tetronimus);
}

/**
 * @brief init game info
 *
 * load game field
 * load mext_field
 * set values to start
 *
 * @param argc 1
 * @param argv GameInfo
 */
void game_info_init(GameInfo_t *game_info) {
  game_field_alloc(game_info);
  next_field_alloc(game_info);
  game_info->score = 0;
  game_info->high_score = 0;
  game_info->level = 1;
  game_info->speed = 1;
  game_info->pause = 0;
}

/**
 * @brief init game info
 *
 * free game field
 * free mext_field
 * set values to zeros
 *
 * @param argc 1
 * @param argv GameInfo
 */
void game_info_deinit(GameInfo_t *game_info) {
  game_field_dealloc(game_info);
  next_field_dealloc(game_info);
}

/**
 * @brief alloc game_field
 *
 * alloc game_field
 *
 * @param argc 1
 * @param argv GameInfo
 */
int game_field_alloc(GameInfo_t *game_info) {
  game_info->field = malloc(20 * sizeof(int *));
  if (!game_info->field) {
    return ALLOC_ERROR;
  }
  for (int i = 0; i < 20; i++) {
    game_info->field[i] = calloc(10, sizeof(int));
    if (!game_info->field[i]) {
      return ALLOC_ERROR;
    }
  }
  return ALLOC_OK;
}

/**
 * @brief alloc next_field
 *
 * alloc next_field
 *
 * @param argc 1
 * @param argv GameInfo
 */
int next_field_alloc(GameInfo_t *game_info) {
  game_info->next = malloc(4 * sizeof(int *));
  if (!game_info->next) {
    return ALLOC_ERROR;
  }
  for (int i = 0; i < 4; i++) {
    game_info->next[i] = calloc(4, sizeof(int));
    if (!game_info->next[i]) {
      return ALLOC_ERROR;
    }
  }
  return ALLOC_OK;
}

/**
 * @brief dealloc game_field
 *
 * dealloc game_field
 *
 * @param argc 1
 * @param argv GameInfo
 */
void game_field_dealloc(GameInfo_t *game_info) {
  for (int i = 0; i < 20; i++) {
    free(game_info->field[i]);
  }
  free(game_info->field);
  game_info->field = NULL;
}

/**
 * @brief dealloc next_field
 *
 * dealloc next_field
 *
 * @param argc 1
 * @param argv GameInfo
 */
void next_field_dealloc(GameInfo_t *game_info) {
  for (int i = 0; i < 4; i++) {
    free(game_info->next[i]);
  }
  free(game_info->next);
  game_info->next = NULL;
}

/**
 * @brief load tetramino in field
 *
 * load tetramino in field
 *
 * @param argc 2
 * @param argv game_field, tetramino
 */
void field_update(int **game_field, Tetramino_t *tetramino) {
  if (tetramino) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (tetramino->pos.x + j - 2 >= 0 && tetramino->pos.x + j - 2 <= 9 &&
            tetramino->pos.y + i - 2 >= 0 && tetramino->pos.y + i - 2 <= 19 &&
            tetramino->states[tetramino->state][i][j] == 1) {
          game_field[tetramino->pos.y + i - 2][tetramino->pos.x + j - 2] =
              tetramino->states[tetramino->state][i][j];
        }
      }
    }
  }
}

/**
 * @brief unload tetramino in field
 *
 * unload tetramino in field
 *
 * @param argc 2
 * @param argv game_field, tetramino
 */
void field_clear(int **game_field, Tetramino_t *tetramino) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (tetramino->pos.x + j - 2 >= 0 && tetramino->pos.x + j - 2 <= 9 &&
          tetramino->pos.y + i - 2 >= 0 && tetramino->pos.y + i - 2 <= 19 &&
          tetramino->states[tetramino->state][i][j] == 1) {
        if (tetramino->states[tetramino->state][i][j] == 1) {
          game_field[tetramino->pos.y + i - 2][tetramino->pos.x + j - 2] = 0;
        }
      }
    }
  }
}

/**
 * @brief load tetramino to next field
 *
 * load tetramino to next field
 *
 * @param argc 2
 * @param argv tetramino_state next_field
 */
void tetramino_next_copy(int src[][4], int **dst) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      dst[i][j] = src[i][j];
    }
  }
};