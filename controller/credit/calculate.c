#include "calculate.h"

int credit_calculate(credit_context_t *context) {
  long double total_payment;
  long double overpayment;

  int err = credit_validator(context);

  if (!err) {
    if (context->type == ANNUITY) {
      long double monthly_payment = annuity_monthly_payment(
          context->amount, context->interest, context->months);
      total_payment = annuity_total_payment(monthly_payment, context->months);
      overpayment = annuity_overpayment(context->amount, total_payment);
      context->monthly_payment = monthly_payment;
    } else if (context->type == DIFFERENTIAL) {
      total_payment = diff_total_payment(context->amount, context->interest,
                                         context->months);
      overpayment = diff_overpayment(context->amount, total_payment);
      long double first_payment = diff_n_month_payment(
          context->amount, context->interest, context->months, 1);
      long double last_payment = diff_n_month_payment(
          context->amount, context->interest, context->months, context->months);
      context->first_payment = first_payment;
      context->last_payment = last_payment;
    }
  }

  context->overpayment = overpayment;
  context->total_payment = total_payment;

  return err;
}