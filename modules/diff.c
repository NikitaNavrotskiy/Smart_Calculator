#include "diff.h"

long double diff_total_payment(long double loan, long double percent,
                               long double months) {
  long double percent_by_month = percent / 12 / 100;
  long double main_part = loan / months;
  long double payment = 0.0;

  for (int i = 1; i <= (int)months; i++) {
    long double left = loan - (main_part * (i - 1));
    long double percent_payment = left * (percent_by_month);
    long double monthly_payment = main_part + percent_payment;
    payment += monthly_payment;
  }

  return payment;
}

// return n-th month payment
long double diff_n_month_payment(long double loan, long double percent,
                                 long double months, int n) {
  long double remain = loan - (loan / months) * (n - 1);
  long double interest_rate = percent / 12 / 100;

  return loan / months + remain * interest_rate;
}

long double diff_overpayment(long double loan, long double payment) {
  return payment - loan;
}
