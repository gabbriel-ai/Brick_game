#ifndef GAMEINFO_H
#define GAMEINFO_H

int game_field_alloc(GameInfo_t *game_info);
int next_field_alloc(GameInfo_t *game_info);
void game_field_dealloc(GameInfo_t *game_info);
void next_field_dealloc(GameInfo_t *game_info);

void game_info_init(GameInfo_t *game_info);
void game_info_ext_init(GameInfoExtended_t *game_info_ext);
void game_info_ext_deinit(GameInfoExtended_t *game_info_ext);
void game_info_deinit(GameInfo_t *game_info);

void field_update(int **game_field, Tetramino_t *tetramino);
void field_clear(int **game_field, Tetramino_t *tetramino);

void tetramino_next_copy(int src[][4], int **dst);
#endif