#ifndef _CONTROLLER_CREDIT_VALUE_HANDLER
#define _CONTROLLER_CREDIT_VALUE_HANDLER

#include <gtk/gtk.h>
#include <math.h>
#include <stdlib.h>

#include "controller/value_handler.h"
#include "data_structs/credit_context.h"

int credit_value_handler(gpointer credit_window, credit_context_t *context);

void credit_context_value_handler(credit_context_t *context, long double amount,
                                  long double interest, int term, int type);

void credit_varied_value_handler(GtkWidget *rate_len, GtkWidget *type_payment,
                                 int *term, int *type);

#endif