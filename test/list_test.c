#include "test.h"

START_TEST(list_test_1) {
  list_t *lst = create_list();

  ck_assert_ptr_nonnull(lst);

  push_back(lst, 1.1, NUM);
  ck_assert_double_eq_tol(lst->head->value, 1.1, 1e-10);

  push_back(lst, 2.2, NUM);
  ck_assert_double_eq_tol(lst->head->next->value, 2.2, 1e-10);

  push_back(lst, 3.3, NUM);
  ck_assert_double_eq_tol(lst->head->next->next->value, 3.3, 1e-10);

  remove_list(lst);
}

START_TEST(list_test_2) {
  list_t *lst = create_list();

  ck_assert_ptr_nonnull(lst);

  push_front(lst, 1.1, NUM);
  ck_assert_double_eq_tol(lst->head->value, 1.1, 1e-10);

  push_front(lst, 2.2, NUM);
  ck_assert_double_eq_tol(lst->head->value, 2.2, 1e-10);

  push_front(lst, 3.3, NUM);
  ck_assert_double_eq_tol(lst->head->value, 3.3, 1e-10);

  remove_list(lst);
}

START_TEST(list_test_3) {
  list_t *lst = create_list();

  ck_assert_ptr_nonnull(lst);

  push_back(lst, 4.3, NUM);
  push_back(lst, 3.3, NUM);
  push_back(lst, 2.3, NUM);

  remove_list(lst);
}

Suite *suite_list() {
  Suite *s;
  TCase *tc;
  s = suite_create("list_test");
  tc = tcase_create("case_list");

  tcase_add_test(tc, list_test_1);
  tcase_add_test(tc, list_test_2);
  tcase_add_test(tc, list_test_3);

  suite_add_tcase(s, tc);
  return s;
}