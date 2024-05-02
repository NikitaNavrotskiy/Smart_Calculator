#ifndef _CONTROLLER_VALUE_HANDLER
#define _CONTROLLER_VALUE_HANDLER

#include <gtk/gtk.h>
#include <math.h>
#include <stdlib.h>

#include "controller/validator.h"
#include "data_structs/credit_context.h"
#include "data_structs/deposit_context.h"

int double_value_handler(GtkWidget *entry, long double *value);

int int_value_handler(GtkWidget *entry, int *value);

int credit_value_handler(gpointer credit_window, credit_context_t *context);

#endif