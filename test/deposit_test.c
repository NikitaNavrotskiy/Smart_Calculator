#include "test.h"

START_TEST(deposit_test_1) {
  deposit_context_t cont;
  cont.amount = 200000;
  cont.capital = 1;
  cont.freq_pay = YEARLY;
  cont.interest = 5;
  cont.months = 12;
  cont.tax = 0;
  cont.replenish = 0;
  cont.withdraw = 0;

  int err = deposit_calculate(&cont);

  long double tol = 1e-0;
  long double expect_interest = 10000.82;
  long double expect_tax = 0.00;
  long double expect_revenue = 210000.82;

  ck_assert_ldouble_eq_tol(cont.total_interest_res, expect_interest, tol);
  ck_assert_ldouble_eq_tol(cont.total_tax_res, expect_tax, tol);
  ck_assert_ldouble_eq_tol(cont.revenue_res, expect_revenue, tol);
  ck_assert_int_eq(err, 0);
}

START_TEST(deposit_test_2) {
  deposit_context_t cont;
  cont.amount = 200000;
  cont.capital = 0;
  cont.freq_pay = MONTHLY;
  cont.interest = 13;
  cont.months = 15;
  cont.tax = 13;
  cont.replenish = 200000;
  cont.withdraw = 10000;

  int err = deposit_calculate(&cont);

  long double tol = 1e-0;
  long double expect_interest = 248625.00;
  long double expect_tax = 32321.20;
  long double expect_revenue = 416304.00;

  ck_assert_ldouble_eq_tol(cont.total_interest_res, expect_interest, tol);
  ck_assert_ldouble_eq_tol(cont.total_tax_res, expect_tax, tol);
  ck_assert_ldouble_eq_tol(cont.revenue_res, expect_revenue, tol);
  ck_assert_int_eq(err, 0);
}

START_TEST(deposit_test_3) {
  deposit_context_t cont;
  cont.amount = 0;
  cont.capital = 0;
  cont.freq_pay = MONTHLY;
  cont.interest = 13;
  cont.months = 15;
  cont.tax = 13;
  cont.replenish = 200000;
  cont.withdraw = 10000;

  int err = deposit_calculate(&cont);

  ck_assert_int_eq(err, 1);
}

START_TEST(deposit_test_4) {
  deposit_context_t cont;
  cont.amount = 200000;
  cont.capital = 1;
  cont.freq_pay = MONTHLY;
  cont.interest = 0.1;
  cont.months = 0;
  cont.tax = 13;
  cont.replenish = 200000;
  cont.withdraw = 10000;

  int err = deposit_calculate(&cont);

  ck_assert_int_eq(err, 1);
}

START_TEST(deposit_test_5) {
  deposit_context_t cont;
  cont.amount = 200000;
  cont.capital = 1;
  cont.freq_pay = MONTHLY;
  cont.interest = 0.1;
  cont.months = 3;
  cont.tax = 13;
  cont.replenish = -200000;
  cont.withdraw = -10000;

  int err = deposit_calculate(&cont);

  ck_assert_int_eq(err, 1);
}

Suite *suite_deposit() {
  Suite *s;
  TCase *tc;
  s = suite_create("deposit_test");
  tc = tcase_create("case_deposit");

  tcase_add_test(tc, deposit_test_1);
  tcase_add_test(tc, deposit_test_2);
  tcase_add_test(tc, deposit_test_3);
  tcase_add_test(tc, deposit_test_4);
  tcase_add_test(tc, deposit_test_5);

  suite_add_tcase(s, tc);
  return s;
}