#ifndef _MODULES_ANNUITY_H
#define _MODULES_ANNUITY_H

#include <math.h>

long double annuity_monthly_payment(long double loan, long double percent,
                                    long double months);

long double annuity_overpayment(long double loan, long double payment);

long double annuity_total_payment(long double payment_for_month,
                                  long double months);

#endif