#include "test.h"

START_TEST(annuity_test_1) {
  credit_context_t cont;
  cont.amount = 200000;
  cont.months = 3;
  cont.interest = 12;
  cont.type = ANNUITY;

  long double tol = 1e-2;
  long double expect_monthly_pay = 68004.42;
  long double expect_total = 204013.26;
  long double expect_overpay = 4013.26;

  int err = credit_calculate(&cont);

  ck_assert_ldouble_eq_tol(cont.monthly_payment, expect_monthly_pay, tol);
  ck_assert_ldouble_eq_tol(cont.overpayment, expect_overpay, tol);
  ck_assert_ldouble_eq_tol(cont.total_payment, expect_total, tol);
  ck_assert_int_eq(err, 0);
}

START_TEST(annuity_test_2) {
  credit_context_t cont;
  cont.amount = 300000000;
  cont.months = 12;
  cont.interest = 20;
  cont.type = ANNUITY;

  long double tol = 1e-1;
  long double expect_monthly_pay = 27790351.77;
  long double expect_total = 333484221.24;
  long double expect_overpay = 33484221.24;

  int err = credit_calculate(&cont);

  ck_assert_ldouble_eq_tol(cont.monthly_payment, expect_monthly_pay, tol);
  ck_assert_ldouble_eq_tol(cont.overpayment, expect_overpay, tol);
  ck_assert_ldouble_eq_tol(cont.total_payment, expect_total, tol);
  ck_assert_int_eq(err, 0);
}

START_TEST(annuity_test_3) {
  credit_context_t cont;
  cont.amount = -1;
  cont.months = 12;
  cont.interest = 20;
  cont.type = ANNUITY;

  int err = credit_calculate(&cont);

  ck_assert_int_eq(err, 1);
}

START_TEST(annuity_test_4) {
  credit_context_t cont;
  cont.amount = 0;
  cont.months = 12;
  cont.interest = 20;
  cont.type = ANNUITY;

  int err = credit_calculate(&cont);

  ck_assert_int_eq(err, 1);
}

START_TEST(annuity_test_5) {
  credit_context_t cont;
  cont.amount = 23;
  cont.months = -12;
  cont.interest = 20;
  cont.type = ANNUITY;

  int err = credit_calculate(&cont);

  ck_assert_int_eq(err, 1);
}

START_TEST(annuity_test_6) {
  credit_context_t cont;
  cont.amount = 23;
  cont.months = 1;
  cont.interest = 0.1;
  cont.type = ANNUITY;

  long double tol = 1e-2;
  long double expect_monthly_pay = 23.00;
  long double expect_total = 23.00;
  long double expect_overpay = 0.00;

  int err = credit_calculate(&cont);

  ck_assert_ldouble_eq_tol(cont.monthly_payment, expect_monthly_pay, tol);
  ck_assert_ldouble_eq_tol(cont.overpayment, expect_overpay, tol);
  ck_assert_ldouble_eq_tol(cont.total_payment, expect_total, tol);

  ck_assert_int_eq(err, 0);
}

START_TEST(annuity_test_7) {
  credit_context_t cont;
  cont.amount = 23;
  cont.months = 1;
  cont.interest = 0;
  cont.type = ANNUITY;

  int err = credit_calculate(&cont);

  ck_assert_int_eq(err, 1);
}

START_TEST(annuity_test_8) {
  credit_context_t cont;
  cont.amount = 23;
  cont.months = 1;
  cont.interest = -10;
  cont.type = ANNUITY;

  int err = credit_calculate(&cont);

  ck_assert_int_eq(err, 1);
}

Suite *suite_annuity() {
  Suite *s;
  TCase *tc;
  s = suite_create("annuity_test");
  tc = tcase_create("case_annuity");

  tcase_add_test(tc, annuity_test_1);
  tcase_add_test(tc, annuity_test_2);
  tcase_add_test(tc, annuity_test_3);
  tcase_add_test(tc, annuity_test_4);
  tcase_add_test(tc, annuity_test_5);
  tcase_add_test(tc, annuity_test_6);
  tcase_add_test(tc, annuity_test_7);
  tcase_add_test(tc, annuity_test_8);

  suite_add_tcase(s, tc);
  return s;
}