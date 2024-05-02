#ifndef _CONTROLLER_DEPOSIT_VALUE_HANDLER
#define _CONTROLLER_DEPOSIT_VALUE_HANDLER

#include <gtk/gtk.h>
#include <math.h>
#include <stdlib.h>

#include "controller/value_handler.h"
#include "data_structs/deposit_context.h"
#include "modules/deposit.h"

int deposit_value_handler(gpointer deposit_window, deposit_context_t *context);

void deposit_context_value_handler(deposit_context_t *context,
                                   long double amount, long double interest,
                                   long double tax, int term, int freq,
                                   long double replenish, long double withdraw,
                                   int capital);

void deposit_varied_value_handler(GtkWidget *term_len, GtkWidget *payment_freq,
                                  int *term, int *freq);

#endif