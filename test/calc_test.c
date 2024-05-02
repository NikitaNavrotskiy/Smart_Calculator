#include "test.h"

START_TEST(calc_test_1) {
  const char *str = "x";
  int err = 0;
  double x = 0.0;
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, x, 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_2) {
  const char *str = "(()";
  int err = 0;
  double x = 0.0;
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, 0.0, 1e-15);
  ck_assert_int_eq(err, 1);
}

START_TEST(calc_test_3) {
  const char *str = "())";
  int err = 0;
  double x = 0.0;
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, 0.0, 1e-15);
  ck_assert_int_eq(err, 1);
}

START_TEST(calc_test_4) {
  const char *str = "cos(acos(x))";
  int err = 0;
  double x = 0.56;
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, x, 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_5) {
  const char *str = "acos(cos(x))";
  int err = 0;
  double x = 0.56;
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, x, 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_6) {
  const char *str = "acos(35)";
  int err = 0;
  double x = 0.56;
  double res = calculate_answer(&str, x, &err);

  ck_assert_int_eq(isnan(res), 1);
  ck_assert_int_eq(err, 1);
}

START_TEST(calc_test_7) {
  const char *str = "sin(x)";
  int err = 0;
  double x = 0.56;
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, sin(x), 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_8) {
  const char *str = "asin(45)";
  int err = 0;
  double x = 0.56;
  double res = calculate_answer(&str, x, &err);

  ck_assert_int_eq(isnan(res), 1);
  ck_assert_int_eq(err, 1);
}

START_TEST(calc_test_9) {
  const char *str = "asin(sin(x))";
  int err = 0;
  double x = 0.56;
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, x, 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_10) {
  const char *str = "atan(tan(x))";
  int err = 0;
  double x = 0.56;
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, atan(tan(x)), 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_11) {
  const char *str = "tan(x)";
  int err = 0;
  double x = 1.0;
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, tan(x), 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_12) {
  const char *str = "sqrt(x)";
  int err = 0;
  double x = -2;
  double res = calculate_answer(&str, x, &err);

  ck_assert_int_eq(isnan(res), 1);
  ck_assert_int_eq(err, 1);
}

START_TEST(calc_test_13) {
  const char *str = "sqrt(x)";
  int err = 0;
  double x = 4;
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, sqrt(x), 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_14) {
  const char *str = "ln(x)";
  int err = 0;
  double x = exp(1.0);
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, log(exp(1.0)), 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_15) {
  const char *str = "ln(x)";
  int err = 0;
  double x = 0.0;
  double res = calculate_answer(&str, x, &err);

  ck_assert_int_eq(isinf(res), -1);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_16) {
  const char *str = "ln(x)";
  int err = 0;
  double x = -0.56;
  double res = calculate_answer(&str, x, &err);

  ck_assert_int_eq(isnan(res), 1);
  ck_assert_int_eq(err, 1);
}

START_TEST(calc_test_17) {
  const char *str = "log(x)";
  int err = 0;
  double x = 10.0;
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, log10(10.0), 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_18) {
  const char *str = "log(x)";
  int err = 0;
  double x = -0.56;
  double res = calculate_answer(&str, x, &err);

  ck_assert_int_eq(isnan(res), 1);
  ck_assert_int_eq(err, 1);
}

START_TEST(calc_test_19) {
  const char *str = "atan(x)";
  int err = 0;
  double x = 45.0;
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, atan(x), 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_20) {
  const char *str = "cos(acos(x))";
  int err = 0;
  double x = 0.56;
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, x, 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_21) {
  const char *str = "4mod5";
  int err = 0;
  double res = calculate_answer(&str, 0.0, &err);

  ck_assert_double_eq_tol(res, fmod(4.0, 5.0), 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_22) {
  const char *str = "5mod4";
  int err = 0;
  double res = calculate_answer(&str, 0.0, &err);

  ck_assert_double_eq_tol(res, fmod(5.0, 4.0), 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_23) {
  const char *str = "4^0";
  int err = 0;
  double res = calculate_answer(&str, 0.0, &err);

  ck_assert_double_eq_tol(res, 1.0, 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_24) {
  const char *str = "0^4";
  int err = 0;
  double res = calculate_answer(&str, 0.0, &err);

  ck_assert_double_eq_tol(res, pow(0.0, 4.0), 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_25) {
  const char *str = "4+5";
  int err = 0;
  double x = 0.56;
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, 9.0, 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_26) {
  const char *str = "4-5";
  int err = 0;
  double x = 0.56;
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, -1.0, 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_27) {
  const char *str = "7*8";
  int err = 0;
  double x = 0.56;
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, 7 * 8.0, 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_28) {
  const char *str = "2/0";
  int err = 0;
  double x = 0.56;
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, 0.0, 1e-15);
  ck_assert_int_eq(err, 1);
}

START_TEST(calc_test_29) {
  const char *str = "2/3";
  int err = 0;
  double x = 0.56;
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, 2 / 3.0, 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_30) {
  const char *str = "-cos(sin(tan(4modx)))";
  int err = 0;
  double x = 0.56;
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, -(cos(sin(tan(fmod(4, x))))), 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_31) {
  const char *str = "2*8-3*4+7*8-3^2";
  int err = 0;
  double x = 0.56;
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, 2 * 8 - 3 * 4 + 7 * 8 - pow(3, 2), 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_32) {
  const char *str = "(3+4)*6";
  int err = 0;
  double x = 0.56;
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, (3 + 4) * 6.0, 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_33) {
  const char *str = "6*(3+4)";
  int err = 0;
  double x = 0.56;
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, 6 * (3 + 4), 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_34) {
  const char *str = "7*-(8-9)";
  int err = 0;
  double x = 0.56;
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, 7 * -(8 - 9), 1e-15);
  ck_assert_int_eq(err, 0);
}

START_TEST(calc_test_35) {
  const char *str = "1.12334232+2.4525453";
  int err = 0;
  double x = 0.56;
  double res = calculate_answer(&str, x, &err);

  ck_assert_double_eq_tol(res, 1.12334232 + 2.4525453, 1e-15);
  ck_assert_int_eq(err, 0);
}

Suite *suite_calc() {
  Suite *s;
  TCase *tc;
  s = suite_create("calc_test");
  tc = tcase_create("case_calc");

  tcase_add_test(tc, calc_test_1);
  tcase_add_test(tc, calc_test_2);
  tcase_add_test(tc, calc_test_3);
  tcase_add_test(tc, calc_test_4);
  tcase_add_test(tc, calc_test_5);
  tcase_add_test(tc, calc_test_6);
  tcase_add_test(tc, calc_test_7);
  tcase_add_test(tc, calc_test_8);
  tcase_add_test(tc, calc_test_9);
  tcase_add_test(tc, calc_test_10);
  tcase_add_test(tc, calc_test_11);
  tcase_add_test(tc, calc_test_12);
  tcase_add_test(tc, calc_test_13);
  tcase_add_test(tc, calc_test_14);
  tcase_add_test(tc, calc_test_15);
  tcase_add_test(tc, calc_test_16);
  tcase_add_test(tc, calc_test_17);
  tcase_add_test(tc, calc_test_18);
  tcase_add_test(tc, calc_test_19);
  tcase_add_test(tc, calc_test_20);
  tcase_add_test(tc, calc_test_21);
  tcase_add_test(tc, calc_test_22);
  tcase_add_test(tc, calc_test_23);
  tcase_add_test(tc, calc_test_24);
  tcase_add_test(tc, calc_test_25);
  tcase_add_test(tc, calc_test_26);
  tcase_add_test(tc, calc_test_27);
  tcase_add_test(tc, calc_test_28);
  tcase_add_test(tc, calc_test_29);
  tcase_add_test(tc, calc_test_30);
  tcase_add_test(tc, calc_test_31);
  tcase_add_test(tc, calc_test_31);
  tcase_add_test(tc, calc_test_32);
  tcase_add_test(tc, calc_test_33);
  tcase_add_test(tc, calc_test_34);
  tcase_add_test(tc, calc_test_35);

  suite_add_tcase(s, tc);
  return s;
}