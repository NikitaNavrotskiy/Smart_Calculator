#ifndef _TEST_H
#define _TEST_H

#include <check.h>

#include "../controller/credit/calculate.h"
#include "../controller/deposit/calculate.h"
#include "../data_structs/credit_context.h"
#include "../data_structs/deposit_context.h"
#include "../data_structs/list.h"
#include "../data_structs/stack.h"
#include "../modules/alg.h"
#include "../modules/annuity.h"
#include "../modules/deposit.h"
#include "../modules/diff.h"

void run_one_test(Suite *test);
void run_tests();

Suite *suite_stack();
Suite *suite_list();

Suite *suite_calc();
Suite *suite_annuity();
Suite *suite_diff();
Suite *suite_deposit();

#endif
