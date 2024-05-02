#include "controller/credit/credit_validator.h"

int credit_validator(const credit_context_t *context) {
  int err = 0;

  err = validator_amount(context->amount);
  if (!err) {
    err = validator_percents(context->interest, CREDIT_MAX_INTEREST);
    if (!err) err = validator_term(context->months, CREDIT_MAX_TERM);
  }
  return err;
}
