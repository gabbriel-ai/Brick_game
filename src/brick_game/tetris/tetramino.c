#include "headers/backend.h"

/**
 * @brief Init tetramino list
 *
 * Init tetramino list
 *
 * @param argc 1
 * @param argv TetratraminoList_T
 */
void tetramino_list_init(TetratraminoList_T *list) {
  list->size = 0;
  list->tetraminos = NULL;
  tetramino_fill_standart(list);
}

/**
 * @brief Deinit tetramino list
 *
 * Deinit tetramino list
 *
 * @param argc 1
 * @param argv TetratraminoList_T
 */
void tetramino_list_deinit(TetratraminoList_T *list) {
  free(list->tetraminos);
  list->size = 0;
  list->tetraminos = NULL;
}

/**
 * @brief fill tetramino_list defaults
 *
 * fill tetramino_list defaults
 *
 * @param argc 1
 * @param argv TetratraminoList_T
 */
void tetramino_fill_standart(TetratraminoList_T *list) {
  tetramino_add_typeO(list);
  tetramino_add_typeI(list);
  tetramino_add_typeZ(list);
  tetramino_add_typeS(list);
  tetramino_add_typeL(list);
  tetramino_add_typeJ(list);
  tetramino_add_typeT(list);
}

/**
 * @brief add in tetramino list typeO
 *
 * add in tetramino list typeO
 *
 * @param argc 1
 * @param argv TetratraminoList_T
 */
void tetramino_add_typeO(TetratraminoList_T *list) {
  list->size++;
  list->tetraminos =
      realloc(list->tetraminos, list->size * sizeof(Tetramino_t));
  list->tetraminos[list->size - 1] = (Tetramino_t){
      .pos = (PosBlock_t){0, 0},
      .state = 0,
      .total_state = 1,
      .states = {{{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}}}};
}

/**
 * @brief add in tetramino list typeI
 *
 * add in tetramino list typeI
 *
 * @param argc 1
 * @param argv TetratraminoList_T
 */
void tetramino_add_typeI(TetratraminoList_T *list) {
  list->size++;
  list->tetraminos =
      realloc(list->tetraminos, list->size * sizeof(Tetramino_t));
  list->tetraminos[list->size - 1] = (Tetramino_t){
      .pos = (PosBlock_t){0, 0},
      .state = 0,
      .total_state = 2,
      .states = {{{0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                 {{0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}}}};
}

/**
 * @brief add in tetramino list typeZ
 *
 * add in tetramino list typeZ
 *
 * @param argc 1
 * @param argv TetratraminoList_T
 */
void tetramino_add_typeZ(TetratraminoList_T *list) {
  list->size++;
  list->tetraminos =
      realloc(list->tetraminos, list->size * sizeof(Tetramino_t));
  list->tetraminos[list->size - 1] = (Tetramino_t){
      .pos = (PosBlock_t){0, 0},
      .state = 0,
      .total_state = 2,
      .states = {{{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 0}},
                 {{0, 0, 0, 0}, {0, 0, 1, 0}, {0, 1, 1, 0}, {0, 1, 0, 0}}}};
}

/**
 * @brief add in tetramino list typeS
 *
 * add in tetramino list typeS
 *
 * @param argc 1
 * @param argv TetratraminoList_T
 */
void tetramino_add_typeS(TetratraminoList_T *list) {
  list->size++;
  list->tetraminos =
      realloc(list->tetraminos, list->size * sizeof(Tetramino_t));
  list->tetraminos[list->size - 1] = (Tetramino_t){
      .pos = (PosBlock_t){0, 0},
      .state = 0,
      .total_state = 2,
      .states = {{{0, 0, 0, 0}, {0, 0, 1, 1}, {0, 1, 1, 0}, {0, 0, 0, 0}},
                 {{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}}}};
}

/**
 * @brief add in tetramino list typeL
 *
 * add in tetramino list typeL
 *
 * @param argc 1
 * @param argv TetratraminoList_T
 */
void tetramino_add_typeL(TetratraminoList_T *list) {
  list->size++;
  list->tetraminos =
      realloc(list->tetraminos, list->size * sizeof(Tetramino_t));
  list->tetraminos[list->size - 1] = (Tetramino_t){
      .pos = (PosBlock_t){0, 0},
      .state = 0,
      .total_state = 4,
      .states = {{{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 0}},
                 {{0, 0, 0, 0}, {0, 0, 0, 1}, {0, 1, 1, 1}, {0, 0, 0, 0}},
                 {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}},
                 {{0, 0, 0, 0}, {0, 1, 1, 1}, {0, 1, 0, 0}, {0, 0, 0, 0}}}};
}

/**
 * @brief add in tetramino list typeJ
 *
 * add in tetramino list typeJ
 *
 * @param argc 1
 * @param argv TetratraminoList_T
 */
void tetramino_add_typeJ(TetratraminoList_T *list) {
  list->size++;
  list->tetraminos =
      realloc(list->tetraminos, list->size * sizeof(Tetramino_t));
  list->tetraminos[list->size - 1] = (Tetramino_t){
      .pos = (PosBlock_t){0, 0},
      .state = 0,
      .total_state = 4,
      .states = {{{0, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 1, 1, 0}},
                 {{0, 0, 0, 0}, {0, 1, 1, 1}, {0, 0, 0, 1}, {0, 0, 0, 0}},
                 {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}},
                 {{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 1}, {0, 0, 0, 0}}}};
}

/**
 * @brief add in tetramino list typeT
 *
 * add in tetramino list typeT
 *
 * @param argc 1
 * @param argv TetratraminoList_T
 */
void tetramino_add_typeT(TetratraminoList_T *list) {
  list->size++;
  list->tetraminos =
      realloc(list->tetraminos, list->size * sizeof(Tetramino_t));
  list->tetraminos[list->size - 1] = (Tetramino_t){
      .pos = (PosBlock_t){0, 0},
      .state = 0,
      .total_state = 4,
      .states = {{{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 1, 1, 1}, {0, 0, 1, 0}},
                 {{0, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 1}, {0, 0, 1, 0}},
                 {{0, 0, 0, 0}, {0, 0, 1, 0}, {0, 1, 1, 1}, {0, 0, 0, 0}},
                 {{0, 0, 0, 0}, {0, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}}}};
}

/**
 * @brief get random tetramino
 *
 * get random tetramino
 *
 * @param argc 1
 * @param argv TetratraminoList_T
 *
 * @return Tetramino
 */
Tetramino_t get_rand_tetramino(TetratraminoList_T *list) {
  Tetramino_t tetramino;
  int type = rand() % 7;
  tetramino = list->tetraminos[type];
  tetramino.state = rand() % tetramino.total_state;
  return tetramino;
}