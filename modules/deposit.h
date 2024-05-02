#ifndef _MODULES_DEPOSIT_H
#define _MODULES_DEPOSIT_H

#define MONTHLY 12
#define YEARLY 1

long double deposit_tax_amount(long double profit, long double tax);

long double deposit_revenue(long double amount, long double profit,
                            long double tax_amount);

long double deposit_profit(long double amount, long double term,
                           long double interest, int freq, int capitalization,
                           long double replenishment, long double withdraw);

#endif