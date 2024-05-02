#include "deposit.h"

long double deposit_tax_amount(long double profit, long double tax) {
  return profit * tax / 100;
}

long double deposit_revenue(long double amount, long double profit,
                            long double tax_amount) {
  return amount + profit - tax_amount;
}

long double deposit_profit(long double amount, long double term,
                           long double interest, int freq, int capitalization,
                           long double replenishment, long double withdraw) {
  long double profit = 0.0;

  if (term >= freq) {
    for (int i = 1; i <= term; i++) {
      long double loc_profit = 0.0;
      if (freq == MONTHLY)
        loc_profit += amount * (interest / 12 / 100);
      else if (freq == YEARLY && i % 12 == 0)
        loc_profit += amount * (interest / 100);
      amount += (replenishment - withdraw);
      if (capitalization) amount += loc_profit;
      profit += loc_profit;
    }
  }

  return profit;
}
