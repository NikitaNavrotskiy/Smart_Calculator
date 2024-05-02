#include "test.h"

START_TEST(stack_test_1) {
  double n1 = 3.14, n2 = 5435.435, n3 = 212.1, n4 = 2.3, n5 = 67.32;
  _stack_t *st = create_stack();

  ck_assert_ptr_nonnull(st);
  ck_assert_ptr_null(st->top);
  ck_assert_uint_eq((unsigned int)st->size, 0);

  push(st, n1, NUM);
  ck_assert_double_eq_tol(n1, st->top->value, 1e-9);
  ck_assert_uint_eq((unsigned int)st->size, 1);

  push(st, n2, NUM);
  ck_assert_double_eq_tol(n2, st->top->value, 1e-9);
  ck_assert_uint_eq((unsigned int)st->size, 2);

  push(st, n3, NUM);
  ck_assert_double_eq_tol(n3, st->top->value, 1e-9);
  ck_assert_uint_eq((unsigned int)st->size, 3);

  push(st, n4, NUM);
  ck_assert_double_eq_tol(n4, st->top->value, 1e-9);
  ck_assert_uint_eq((unsigned int)st->size, 4);

  push(st, n5, NUM);
  ck_assert_double_eq_tol(n5, st->top->value, 1e-9);
  ck_assert_uint_eq((unsigned int)st->size, 5);

  pop(st);
  ck_assert_double_eq_tol(n4, st->top->value, 1e-9);
  ck_assert_uint_eq((unsigned int)st->size, 4);

  pop(st);
  ck_assert_double_eq_tol(n3, st->top->value, 1e-9);
  ck_assert_uint_eq((unsigned int)st->size, 3);

  pop(st);
  ck_assert_double_eq_tol(n2, st->top->value, 1e-9);
  ck_assert_uint_eq((unsigned int)st->size, 2);

  pop(st);
  ck_assert_double_eq_tol(n1, st->top->value, 1e-9);
  ck_assert_uint_eq((unsigned int)st->size, 1);

  pop(st);
  ck_assert_ptr_nonnull(st);
  ck_assert_ptr_null(st->top);
  ck_assert_uint_eq((unsigned int)st->size, 0);

  ck_assert_int_eq(empty(st), 1);

  remove_stack(st);
}

START_TEST(stack_test_2) {
  double n1 = 3.14, n2 = 5435.435, n3 = 212.1, n4 = 2.3, n5 = 67.32;
  _stack_t *st = create_stack();

  ck_assert_int_eq(empty(st), 1);
  ck_assert_ptr_nonnull(st);
  ck_assert_ptr_null(st->top);
  ck_assert_uint_eq((unsigned int)st->size, 0);

  push(st, n1, NUM);
  ck_assert_int_eq(empty(st), 0);
  ck_assert_double_eq_tol(n1, top(st)->value, 1e-9);
  ck_assert_uint_eq((unsigned int)st->size, 1);

  push(st, n2, NUM);
  ck_assert_int_eq(empty(st), 0);
  ck_assert_double_eq_tol(n2, top(st)->value, 1e-9);
  ck_assert_uint_eq((unsigned int)st->size, 2);

  push(st, n3, NUM);
  ck_assert_int_eq(empty(st), 0);
  ck_assert_double_eq_tol(n3, top(st)->value, 1e-9);
  ck_assert_uint_eq((unsigned int)st->size, 3);

  push(st, n4, NUM);
  ck_assert_int_eq(empty(st), 0);
  ck_assert_double_eq_tol(n4, top(st)->value, 1e-9);
  ck_assert_uint_eq((unsigned int)st->size, 4);

  push(st, n5, NUM);
  ck_assert_int_eq(empty(st), 0);
  ck_assert_double_eq_tol(n5, top(st)->value, 1e-9);
  ck_assert_uint_eq((unsigned int)st->size, 5);

  remove_stack(st);
}

START_TEST(stack_test_3) {
  _stack_t *st = create_stack();

  ck_assert_int_eq(top(st) == NULL, 1);
  pop(st);
  pop(st);
  pop(st);
  remove_stack(st);
}

START_TEST(stack_test_4) {
  _stack_t *st = create_stack();

  push(st, 1.1, NUM);
  push(st, 2.2, NUM);
  push(st, 3.3, NUM);

  remove_stack(st);
}

Suite *suite_stack() {
  Suite *s;
  TCase *tc;
  s = suite_create("stack_test");
  tc = tcase_create("case_stack");

  tcase_add_test(tc, stack_test_1);
  tcase_add_test(tc, stack_test_2);
  tcase_add_test(tc, stack_test_3);
  tcase_add_test(tc, stack_test_4);

  suite_add_tcase(s, tc);
  return s;
}