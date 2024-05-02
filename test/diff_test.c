#include "test.h"

START_TEST(diff_test_1) {
  credit_context_t cont;
  cont.amount = 200000;
  cont.months = 3;
  cont.interest = 12;
  cont.type = DIFFERENTIAL;

  long double tol = 1e-2;
  long double expect_first_pay = 68666.67;
  long double expect_last_pay = 67333.33;
  long double expect_total = 204000.00;
  long double expect_overpay = 4000.00;

  int err = credit_calculate(&cont);

  ck_assert_ldouble_eq_tol(cont.first_payment, expect_first_pay, tol);
  ck_assert_ldouble_eq_tol(cont.last_payment, expect_last_pay, tol);
  ck_assert_ldouble_eq_tol(cont.overpayment, expect_overpay, tol);
  ck_assert_ldouble_eq_tol(cont.total_payment, expect_total, tol);
  ck_assert_int_eq(err, 0);
}

START_TEST(diff_test_2) {
  credit_context_t cont;
  cont.amount = 300000000;
  cont.months = 12;
  cont.interest = 20;
  cont.type = DIFFERENTIAL;

  long double tol = 1e+0;
  long double expect_first_pay = 30000000;
  long double expect_last_pay = 25416666.67;
  long double expect_total = 332500000.00;
  long double expect_overpay = 32500000.00;

  int err = credit_calculate(&cont);

  ck_assert_ldouble_eq_tol(cont.first_payment, expect_first_pay, tol);
  ck_assert_ldouble_eq_tol(cont.last_payment, expect_last_pay, tol);
  ck_assert_ldouble_eq_tol(cont.overpayment, expect_overpay, tol);
  ck_assert_ldouble_eq_tol(cont.total_payment, expect_total, tol);
  ck_assert_int_eq(err, 0);
}

START_TEST(diff_test_3) {
  credit_context_t cont;
  cont.amount = -1;
  cont.months = 12;
  cont.interest = 20;
  cont.type = DIFFERENTIAL;

  int err = credit_calculate(&cont);

  ck_assert_int_eq(err, 1);
}

START_TEST(diff_test_4) {
  credit_context_t cont;
  cont.amount = 0;
  cont.months = 12;
  cont.interest = 20;
  cont.type = DIFFERENTIAL;

  int err = credit_calculate(&cont);

  ck_assert_int_eq(err, 1);
}

START_TEST(diff_test_5) {
  credit_context_t cont;
  cont.amount = 23;
  cont.months = -12;
  cont.interest = 20;
  cont.type = DIFFERENTIAL;

  int err = credit_calculate(&cont);

  ck_assert_int_eq(err, 1);
}

START_TEST(diff_test_6) {
  credit_context_t cont;
  cont.amount = 23;
  cont.months = 3;
  cont.interest = 0.1;
  cont.type = DIFFERENTIAL;

  long double tol = 1e-2;
  long double expect_monthly_pay = 7.67;
  long double expect_total = 23.00;
  long double expect_overpay = 0.00;

  int err = credit_calculate(&cont);

  ck_assert_ldouble_eq_tol(cont.first_payment, expect_monthly_pay, tol);
  ck_assert_ldouble_eq_tol(cont.last_payment, expect_monthly_pay, tol);
  ck_assert_ldouble_eq_tol(cont.overpayment, expect_overpay, tol);
  ck_assert_ldouble_eq_tol(cont.total_payment, expect_total, tol);

  ck_assert_int_eq(err, 0);
}

START_TEST(diff_test_7) {
  credit_context_t cont;
  cont.amount = 23;
  cont.months = 1;
  cont.interest = 0;
  cont.type = DIFFERENTIAL;

  int err = credit_calculate(&cont);

  ck_assert_int_eq(err, 1);
}

START_TEST(diff_test_8) {
  credit_context_t cont;
  cont.amount = 23;
  cont.months = 1;
  cont.interest = -10;
  cont.type = DIFFERENTIAL;

  int err = credit_calculate(&cont);

  ck_assert_int_eq(err, 1);
}

Suite *suite_diff() {
  Suite *s;
  TCase *tc;
  s = suite_create("diff_test");
  tc = tcase_create("case_diff");

  tcase_add_test(tc, diff_test_1);
  tcase_add_test(tc, diff_test_2);
  tcase_add_test(tc, diff_test_3);
  tcase_add_test(tc, diff_test_4);
  tcase_add_test(tc, diff_test_5);
  tcase_add_test(tc, diff_test_6);
  tcase_add_test(tc, diff_test_7);
  tcase_add_test(tc, diff_test_8);

  suite_add_tcase(s, tc);
  return s;
}