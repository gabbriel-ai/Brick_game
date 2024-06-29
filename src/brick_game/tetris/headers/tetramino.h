#ifndef TETRAMINO_H
#define TETRAMINO_H

void tetramino_list_init(TetratraminoList_T *list);
void tetramino_fill_standart(TetratraminoList_T *list);
void tetramino_list_deinit(TetratraminoList_T *list);

void tetramino_add_typeO(TetratraminoList_T *list);
void tetramino_add_typeI(TetratraminoList_T *list);
void tetramino_add_typeZ(TetratraminoList_T *list);
void tetramino_add_typeS(TetratraminoList_T *list);
void tetramino_add_typeL(TetratraminoList_T *list);
void tetramino_add_typeJ(TetratraminoList_T *list);
void tetramino_add_typeT(TetratraminoList_T *list);

Tetramino_t get_rand_tetramino(TetratraminoList_T *list);

#endif