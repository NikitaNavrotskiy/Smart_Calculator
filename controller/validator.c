#include "validator.h"

int validator_is_digit(char c) {
  return ((c <= '9' && c >= '0') || c == '-' || c == '+');
}

int validator_is_dot(char c) { return (c == '.' || c == ','); }

int validator_is_all_symbols_for_double(const char *str) {
  int err = 0;
  size_t len = strlen(str);

  for (size_t i = 0; i < len && !err; i++) {
    if (!validator_is_digit(str[i]) && !validator_is_dot(str[i])) err = 1;
    if (str[i] == '.') *(char *)(str + i) = ',';
  }

  return err;
}

int validator_is_all_symbols_for_int(const char *str) {
  int err = 0;
  size_t len = strlen(str);

  for (size_t i = 0; i < len && !err; i++) {
    if (!validator_is_digit(str[i])) err = 1;
  }

  return err;
}

int validator_percents(long double percent, long double max_interest) {
  return (percent > max_interest || percent <= 1e-19);
}

int validator_amount(long double amount) { return amount <= 0; }

int validator_term(int term, int max_term) {
  return (term < 1 || term > max_term);
}