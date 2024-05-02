#include "annuity.h"

// loan - amount of credit, percent - percent of credit (not diveded by 100,
// months - amount of months)

long double annuity_monthly_payment(long double loan, long double percent,
                                    long double months) {
  long double percent_by_month = percent / 12 / 100;

  long double res =
      loan * (percent_by_month +
              (percent_by_month) / (powl(1 + percent_by_month, months) - 1));
  return res;
}

long double annuity_overpayment(long double loan, long double payment) {
  return payment - loan;
}

long double annuity_total_payment(long double payment_for_month,
                                  long double months) {
  return payment_for_month * months;
}
