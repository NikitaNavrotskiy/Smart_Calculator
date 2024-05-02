#ifndef _MODULES_DIFF_H
#define _MODULES_DIFF_H

long double diff_total_payment(long double loan, long double percent,
                               long double months);

long double diff_n_month_payment(long double loan, long double percent,
                                 long double months, int n);

long double diff_overpayment(long double loan, long double payment);

#endif