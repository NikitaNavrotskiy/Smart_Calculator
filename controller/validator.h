#ifndef _CONTROLLER_VALIDATOR_H
#define _CONTROLLER_VALIDATOR_H

#include <string.h>

int validator_is_digit(char c);

int validator_is_dot(char c);

int validator_is_all_symbols_for_double(const char *str);

int validator_is_all_symbols_for_int(const char *str);

int validator_percents(long double percent, long double max_interest);

int validator_amount(long double amount);

int validator_term(int term, int max_term);

#endif