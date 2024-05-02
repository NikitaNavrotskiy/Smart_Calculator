#ifndef _DATA_STRUCTS_CREDIT_CONTEXT_H
#define _DATA_STRUCTS_CREDIT_CONTEXT_H

#define ANNUITY 4
#define DIFFERENTIAL 5

typedef struct {
  long double amount;
  long double interest;
  int months;
  int type;
  long double first_payment;
  long double last_payment;
  long double monthly_payment;
  long double total_payment;
  long double overpayment;
} credit_context_t;

#endif