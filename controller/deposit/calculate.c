#include "calculate.h"

int deposit_calculate(deposit_context_t *context) {
  long double total_interest_result;
  long double total_tax_result;
  long double revenue_result;

  int err = deposit_validator(context);

  if (!err) {
    total_interest_result = deposit_profit(
        context->amount, context->months, context->interest, context->freq_pay,
        context->capital, context->replenish, context->withdraw);
    total_tax_result = deposit_tax_amount(total_interest_result, context->tax);
    revenue_result = deposit_revenue(context->amount, total_interest_result,
                                     total_tax_result);
    context->total_interest_res = total_interest_result;
    context->total_tax_res = total_tax_result;
    context->revenue_res = revenue_result;
  }

  return err;
}