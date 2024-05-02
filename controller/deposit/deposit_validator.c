#include "controller/deposit/deposit_validator.h"

int deposit_validator(const deposit_context_t *context) {
  int err = 0;

  err = validator_amount(context->amount);

  if (!err) {
    err = validator_percents(context->interest, DEPOSIT_MAX_INTEREST);
    if (!err)
      err = validator_percents(context->tax, DEPOSIT_MAX_TAX) &&
            context->tax != 0;
  }

  if (!err) {
    err = validator_term(context->months, DEPOSIT_MAX_TERM);
    if (!err)
      err = validator_amount(context->replenish) && context->withdraw != 0;
  }

  if (!err) {
    err = validator_amount(context->withdraw) && context->withdraw != 0;
  }

  return err;
}