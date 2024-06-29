/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "tests.ts" instead.
 */

#include <check.h>

#include "../brick_game/tetris/headers/backend.h"

START_TEST(test_game_field_alloc) {
  GameInfo_t game_info;
  ck_assert_int_eq(game_field_alloc(&game_info), ALLOC_OK);
  game_field_dealloc(&game_info);
  ck_assert_ptr_eq(game_info.field, NULL);
}
END_TEST

START_TEST(test_next_field_alloc) {
  GameInfo_t game_info;
  ck_assert_int_eq(next_field_alloc(&game_info), ALLOC_OK);
  next_field_dealloc(&game_info);
  ck_assert_ptr_eq(game_info.next, NULL);
}
END_TEST

START_TEST(test_game_info_init) {
  GameInfo_t game_info;
  game_info_init(&game_info);
  ck_assert_int_eq(game_info.high_score, 0);
  ck_assert_int_eq(game_info.level, 1);
  ck_assert_int_eq(game_info.speed, 1);
  ck_assert_int_eq(game_info.pause, 0);
  ck_assert_int_eq(game_info.score, 0);
  ck_assert_ptr_ne(game_info.field, NULL);
  ck_assert_ptr_ne(game_info.next, NULL);

  game_info_deinit(&game_info);
  ck_assert_ptr_eq(game_info.field, NULL);
  ck_assert_ptr_eq(game_info.next, NULL);
}
END_TEST

START_TEST(test_tetramino_list_init) {
  TetratraminoList_T list;
  tetramino_list_init(&list);
  ck_assert_int_eq(list.size, 7);
  ck_assert_ptr_ne(list.tetraminos, NULL);
  tetramino_list_deinit(&list);
  ck_assert_int_eq(list.size, 0);
  ck_assert_ptr_eq(list.tetraminos, NULL);
}
END_TEST

START_TEST(test_tetramino_addO) {
  TetratraminoList_T list;
  list.size = 0;
  list.tetraminos = NULL;
  tetramino_add_typeO(&list);
  ck_assert_ptr_ne(list.tetraminos, NULL);
  ck_assert_int_eq(list.size, 1);
  ck_assert_int_eq(list.tetraminos[0].total_state, 1);
  ck_assert_int_eq(list.tetraminos[0].state, 0);
  ck_assert_int_eq(list.tetraminos[0].pos.x, 0);
  ck_assert_int_eq(list.tetraminos[0].pos.y, 0);
  free(list.tetraminos);
  list.size = 0;
}
END_TEST

START_TEST(test_tetramino_addI) {
  TetratraminoList_T list;
  list.size = 0;
  list.tetraminos = NULL;
  tetramino_add_typeI(&list);
  ck_assert_ptr_ne(list.tetraminos, NULL);
  ck_assert_int_eq(list.size, 1);
  ck_assert_int_eq(list.tetraminos[0].total_state, 2);
  ck_assert_int_eq(list.tetraminos[0].state, 0);
  ck_assert_int_eq(list.tetraminos[0].pos.x, 0);
  ck_assert_int_eq(list.tetraminos[0].pos.y, 0);
  free(list.tetraminos);
  list.size = 0;
}
END_TEST

START_TEST(test_tetramino_addZ) {
  TetratraminoList_T list;
  list.size = 0;
  list.tetraminos = NULL;
  tetramino_add_typeZ(&list);
  ck_assert_ptr_ne(list.tetraminos, NULL);
  ck_assert_int_eq(list.size, 1);
  ck_assert_int_eq(list.tetraminos[0].total_state, 2);
  ck_assert_int_eq(list.tetraminos[0].state, 0);
  ck_assert_int_eq(list.tetraminos[0].pos.x, 0);
  ck_assert_int_eq(list.tetraminos[0].pos.y, 0);
  free(list.tetraminos);
  list.size = 0;
}
END_TEST

START_TEST(test_tetramino_addS) {
  TetratraminoList_T list;
  list.size = 0;
  list.tetraminos = NULL;
  tetramino_add_typeS(&list);
  ck_assert_ptr_ne(list.tetraminos, NULL);
  ck_assert_int_eq(list.size, 1);
  ck_assert_int_eq(list.tetraminos[0].total_state, 2);
  ck_assert_int_eq(list.tetraminos[0].state, 0);
  ck_assert_int_eq(list.tetraminos[0].pos.x, 0);
  ck_assert_int_eq(list.tetraminos[0].pos.y, 0);
  free(list.tetraminos);
  list.size = 0;
}
END_TEST

START_TEST(test_tetramino_addL) {
  TetratraminoList_T list;
  list.size = 0;
  list.tetraminos = NULL;
  tetramino_add_typeL(&list);
  ck_assert_ptr_ne(list.tetraminos, NULL);
  ck_assert_int_eq(list.size, 1);
  ck_assert_int_eq(list.tetraminos[0].total_state, 4);
  ck_assert_int_eq(list.tetraminos[0].state, 0);
  ck_assert_int_eq(list.tetraminos[0].pos.x, 0);
  ck_assert_int_eq(list.tetraminos[0].pos.y, 0);
  free(list.tetraminos);
  list.size = 0;
}
END_TEST

START_TEST(test_tetramino_addJ) {
  TetratraminoList_T list;
  list.size = 0;
  list.tetraminos = NULL;
  tetramino_add_typeJ(&list);
  ck_assert_ptr_ne(list.tetraminos, NULL);
  ck_assert_int_eq(list.size, 1);
  ck_assert_int_eq(list.tetraminos[0].total_state, 4);
  ck_assert_int_eq(list.tetraminos[0].state, 0);
  ck_assert_int_eq(list.tetraminos[0].pos.x, 0);
  ck_assert_int_eq(list.tetraminos[0].pos.y, 0);
  free(list.tetraminos);
  list.size = 0;
}
END_TEST

START_TEST(test_tetramino_addT) {
  TetratraminoList_T list;
  list.size = 0;
  list.tetraminos = NULL;
  tetramino_add_typeT(&list);
  ck_assert_ptr_ne(list.tetraminos, NULL);
  ck_assert_int_eq(list.size, 1);
  ck_assert_int_eq(list.tetraminos[0].total_state, 4);
  ck_assert_int_eq(list.tetraminos[0].state, 0);
  ck_assert_int_eq(list.tetraminos[0].pos.x, 0);
  ck_assert_int_eq(list.tetraminos[0].pos.y, 0);
  free(list.tetraminos);
  list.size = 0;
}
END_TEST

START_TEST(test_get_rand_tetramino) {
  TetratraminoList_T list;
  tetramino_list_init(&list);
  Tetramino_t tetramino = {0};
  tetramino = get_rand_tetramino(&list);
  ck_assert_int_ne(tetramino.total_state, 0);
  tetramino_list_deinit(&list);
}
END_TEST

START_TEST(test_game_info_ext_init) {
  GameInfoExtended_t game_info_ext;
  game_info_ext_init(&game_info_ext);
  ck_assert_ptr_ne(game_info_ext.default_tetronimus.tetraminos, NULL);
  game_info_ext_deinit(&game_info_ext);
  ck_assert_ptr_eq(game_info_ext.default_tetronimus.tetraminos, NULL);
}
END_TEST

START_TEST(test_field_update) {
  GameInfo_t game_info;
  game_info_init(&game_info);
  TetratraminoList_T list;
  tetramino_list_init(&list);
  Tetramino_t tetramino = list.tetraminos[0];
  tetramino.pos.x = 5;
  tetramino.pos.y = 5;
  field_update(game_info.field, &tetramino);
  int result[20][10];
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      result[i][j] = 0;
    }
  }
  result[4][5] = 1;
  result[4][4] = 1;
  result[5][4] = 1;
  result[5][5] = 1;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      ck_assert_int_eq(result[i][j], game_info.field[i][j]);
    }
  }
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      result[i][j] = 0;
    }
  }
  field_clear(game_info.field, &tetramino);
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      ck_assert_int_eq(result[i][j], game_info.field[i][j]);
    }
  }
  tetramino_list_deinit(&list);
  game_info_deinit(&game_info);
}
END_TEST

START_TEST(test_is_collide) {
  GameInfo_t game_info;
  game_info_init(&game_info);
  Tetramino_t tetramino;
  TetratraminoList_T list;
  tetramino_list_init(&list);
  tetramino = list.tetraminos[0];
  tetramino_list_deinit(&list);
  tetramino.pos.x = 0;
  tetramino.pos.y = 5;
  field_update(game_info.field, &tetramino);
  ck_assert_int_eq(is_collide_walls(&tetramino), 1);
  ck_assert_int_eq(is_collide_field(game_info.field, &tetramino), 1);
  ck_assert_int_eq(is_collide(game_info.field, &tetramino), 1);
  field_clear(game_info.field, &tetramino);
  ck_assert_int_eq(is_collide_walls(&tetramino), 1);
  ck_assert_int_eq(is_collide_field(game_info.field, &tetramino), 0);
  ck_assert_int_eq(is_collide(game_info.field, &tetramino), 1);
  tetramino.pos.x = 3;
  tetramino.pos.y = 5;
  ck_assert_int_eq(is_collide_walls(&tetramino), 0);
  ck_assert_int_eq(is_collide_field(game_info.field, &tetramino), 0);
  ck_assert_int_eq(is_collide(game_info.field, &tetramino), 0);
  game_info_deinit(&game_info);
  tetramino_list_deinit(&list);
}
END_TEST

START_TEST(test_update_info) {
  game_params *prms = get_current_game_prms();
  game_params_init(prms);
  for (int i = 0; i < 10; i++) {
    prms->game_info_ext.game_info.field[19][i] = 1;
  }
  prms->game_info_ext.game_info.field[18][5] = 1;
  update_info(&prms->game_info_ext);
  for (int i = 0; i < 10; i++) {
    if (i == 5) {
      ck_assert_int_eq(prms->game_info_ext.game_info.field[19][i], 1);
    } else {
      ck_assert_int_eq(prms->game_info_ext.game_info.field[19][i], 0);
    }
  }
  ck_assert_int_eq(prms->game_info_ext.game_info.score, 100);
  prms->game_info_ext.game_info.score = 0;
  for (int i = 19; i >= 18; i--) {
    for (int j = 0; j < 10; j++) {
      prms->game_info_ext.game_info.field[i][j] = 1;
    }
  }
  update_info(&prms->game_info_ext);
  ck_assert_int_eq(prms->game_info_ext.game_info.score, 300);
  prms->game_info_ext.game_info.score = 0;
  for (int i = 19; i >= 17; i--) {
    for (int j = 0; j < 10; j++) {
      prms->game_info_ext.game_info.field[i][j] = 1;
    }
  }
  update_info(&prms->game_info_ext);
  ck_assert_int_eq(prms->game_info_ext.game_info.score, 700);
  prms->game_info_ext.game_info.score = 0;
  for (int i = 19; i >= 15; i--) {
    for (int j = 0; j < 10; j++) {
      prms->game_info_ext.game_info.field[i][j] = 1;
    }
  }
  update_info(&prms->game_info_ext);
  ck_assert_int_eq(prms->game_info_ext.game_info.score, 1500);
  prms->game_info_ext.game_info.score = 7000;
  update_speed(&prms->game_info_ext);
  game_params_deinit(prms);
}
END_TEST

START_TEST(test_reset_game_info_ext) {
  GameInfoExtended_t game_info_ext;
  game_info_ext_init(&game_info_ext);
  game_info_ext.game_info.score = 6000;
  reset_game_info_ext(&game_info_ext);
  ck_assert_int_eq(game_info_ext.game_info.score, 0);
  game_info_ext_deinit(&game_info_ext);
}
END_TEST

START_TEST(test_update_time) {
  game_params *prms = get_current_game_prms();
  game_params_init(prms);
  update_time(prms);
  ck_assert_int_eq(prms->time, 0);
  prms->time = 10;
  ck_assert_int_ne(prms->time, 0);
  game_params_deinit(prms);
}
END_TEST

START_TEST(test_sigact) {
  game_params *prms = get_current_game_prms();
  game_params_init(prms);
  userInput(Start, 0);
  ck_assert_int_eq(prms->state, MOVING);
  game_params_deinit(prms);

  game_params_init(prms);
  userInput(Start, 0);
  int old_pos_x = prms->game_info_ext.current_tetramino.pos.x;
  userInput(Left, 0);
  ck_assert_int_eq(prms->state, MOVING);
  ck_assert_int_eq(prms->game_info_ext.current_tetramino.pos.x, old_pos_x - 1);
  game_params_deinit(prms);

  game_params_init(prms);
  userInput(Start, 0);
  old_pos_x = prms->game_info_ext.current_tetramino.pos.x;
  userInput(Left, 0);
  old_pos_x = prms->game_info_ext.current_tetramino.pos.x;
  userInput(Left, 0);
  old_pos_x = prms->game_info_ext.current_tetramino.pos.x;
  userInput(Left, 0);
  old_pos_x = prms->game_info_ext.current_tetramino.pos.x;
  userInput(Left, 0);
  old_pos_x = prms->game_info_ext.current_tetramino.pos.x;
  userInput(Left, 0);
  old_pos_x = prms->game_info_ext.current_tetramino.pos.x;
  ck_assert_int_eq(prms->state, MOVING);
  ck_assert_int_eq(prms->game_info_ext.current_tetramino.pos.x, old_pos_x);
  game_params_deinit(prms);

  game_params_init(prms);
  userInput(Start, 0);
  old_pos_x = prms->game_info_ext.current_tetramino.pos.x;
  userInput(Right, 0);
  ck_assert_int_eq(prms->state, MOVING);
  ck_assert_int_eq(prms->game_info_ext.current_tetramino.pos.x, old_pos_x + 1);
  game_params_deinit(prms);

  game_params_init(prms);
  userInput(Start, 0);
  old_pos_x = prms->game_info_ext.current_tetramino.pos.x;
  userInput(Right, 0);
  old_pos_x = prms->game_info_ext.current_tetramino.pos.x;
  userInput(Right, 0);
  old_pos_x = prms->game_info_ext.current_tetramino.pos.x;
  userInput(Right, 0);
  old_pos_x = prms->game_info_ext.current_tetramino.pos.x;
  userInput(Right, 0);
  old_pos_x = prms->game_info_ext.current_tetramino.pos.x;
  userInput(Right, 0);
  old_pos_x = prms->game_info_ext.current_tetramino.pos.x;
  userInput(Right, 0);
  old_pos_x = prms->game_info_ext.current_tetramino.pos.x;
  userInput(Right, 0);
  old_pos_x = prms->game_info_ext.current_tetramino.pos.x;
  ck_assert_int_eq(prms->state, MOVING);
  ck_assert_int_eq(prms->game_info_ext.current_tetramino.pos.x, old_pos_x);
  game_params_deinit(prms);

  game_params_init(prms);
  userInput(Start, 0);
  userInput(Down, 0);
  ck_assert_int_eq(prms->state, ATTACHING);
  ck_assert_int_eq(prms->game_info_ext.current_tetramino.pos.y, 19);
  game_params_deinit(prms);

  game_params_init(prms);
  userInput(Start, 0);
  int old_state = prms->game_info_ext.current_tetramino.state;
  userInput(Action, 0);
  ck_assert_int_eq(prms->state, MOVING);
  ck_assert_int_ne(prms->game_info_ext.current_tetramino.state, old_state);
  game_params_deinit(prms);

  game_params_init(prms);
  userInput(Start, 0);
  userInput(Pause, 0);
  ck_assert_int_eq(prms->state, PAUSED);
  userInput(Pause, 0);
  ck_assert_int_eq(prms->state, MOVING);
  game_params_deinit(prms);

  game_params_init(prms);
  userInput(Terminate, 0);
  ck_assert_int_eq(prms->break_flag, 0);
  game_params_deinit(prms);

  game_params_init(prms);
  userInput(Start, 0);
  while (prms->state != ATTACHING) {
    userInput(Down, 0);
  }
  userInput(Down, 0);
  ck_assert_int_eq(prms->state, SPAWN);
  game_params_deinit(prms);

  game_params_init(prms);
  userInput(Start, 0);
  while (prms->state != GAME_OVER) {
    userInput(Down, 0);
  }
  ck_assert_int_eq(prms->state, GAME_OVER);
  game_params_deinit(prms);
}
END_TEST

START_TEST(test_update_current_state) {
  game_params *prms = get_current_game_prms();
  game_params_init(prms);
  GameInfo_t temp;
  temp = updateCurrentState();
  ck_assert_int_eq(temp.high_score, prms->game_info_ext.game_info.high_score);
  game_params_deinit(prms);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, test_game_field_alloc);
  tcase_add_test(tc1_1, test_next_field_alloc);
  tcase_add_test(tc1_1, test_game_info_init);
  tcase_add_test(tc1_1, test_game_info_ext_init);

  tcase_add_test(tc1_1, test_tetramino_list_init);
  tcase_add_test(tc1_1, test_tetramino_addO);
  tcase_add_test(tc1_1, test_tetramino_addI);
  tcase_add_test(tc1_1, test_tetramino_addZ);
  tcase_add_test(tc1_1, test_tetramino_addS);
  tcase_add_test(tc1_1, test_tetramino_addL);
  tcase_add_test(tc1_1, test_tetramino_addJ);
  tcase_add_test(tc1_1, test_tetramino_addT);
  tcase_add_test(tc1_1, test_get_rand_tetramino);

  tcase_add_test(tc1_1, test_field_update);

  tcase_add_test(tc1_1, test_is_collide);

  tcase_add_test(tc1_1, test_update_info);

  tcase_add_test(tc1_1, test_reset_game_info_ext);

  tcase_add_test(tc1_1, test_update_time);
  tcase_add_test(tc1_1, test_sigact);
  tcase_add_test(tc1_1, test_update_current_state);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}