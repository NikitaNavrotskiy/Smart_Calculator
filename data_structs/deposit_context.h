#ifndef _DATA_STRUCTS_DEPOSIT_CONTEXT_H
#define _DATA_STRUCTS_DEPOSIT_CONTEXT_H

typedef struct {
  long double amount;
  long double interest;
  long double tax;
  int months;
  int freq_pay;
  int capital;
  long double replenish;
  long double withdraw;
  long double total_interest_res;
  long double total_tax_res;
  long double revenue_res;
} deposit_context_t;

#endif