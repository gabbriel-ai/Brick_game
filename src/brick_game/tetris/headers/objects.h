#ifndef OBJECTS_H
#define OBJECTS_H

typedef enum {
  Start,
  Pause,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  Action
} UserAction_t;

typedef struct {
  int **field;
  int **next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

typedef struct {
  int x;
  int y;
} PosBlock_t;

typedef struct {
  PosBlock_t pos;
  int state;
  int total_state;
  int states[4][4][4];
} Tetramino_t;

typedef struct {
  Tetramino_t *tetraminos;
  int size;
} TetratraminoList_T;

typedef struct {
  GameInfo_t game_info;
  Tetramino_t next_tetramino;
  Tetramino_t current_tetramino;
  TetratraminoList_T default_tetronimus;
} GameInfoExtended_t;

#endif