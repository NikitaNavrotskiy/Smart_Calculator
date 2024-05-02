#ifndef _MODULES_ALG_H
#define _MODULES_ALG_H

#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "data_structs/list.h"
#include "data_structs/node.h"
#include "data_structs/stack.h"

int is_digit(char c);

int is_small_operation(char c);

int is_function(const char *str);

int is_start_with_double(const char *str, int unar);

int get_prior(token_t tok);

int get_func(const char **str, token_t *token);

void get_small_operation(const char **str, token_t *token);

void get_ptr_to_next_token(const char **str);

void small_operation_case(const char **str, list_t *list, _stack_t *stack,
                          int *err);

double get_double(const char **str, int *has_double, int *end_of_str, int unar);

int str_to_rev_polish(const char **str, list_t *list);

void close_brace_case(const char **str, list_t *list, _stack_t *stack,
                      int *err);

double calculate_answer(const char **str, double x, int *err_glob);

#endif