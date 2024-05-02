#ifndef _CONTROLLER_CREDIT_CALLBACK_H
#define _CONTROLLER_CREDIT_CALLBACK_H

#include <gtk/gtk.h>

#include "controller/credit/calculate.h"
#include "controller/credit/credit_error_handler.h"
#include "controller/value_handler.h"
#include "data_structs/credit_context.h"
#include "view/credit.h"

void on_destroy_credit(GtkWidget *widget);

void on_button_credit_calculate_clicked(GtkButton *b, gpointer user_data);

void on_button_credit_reset_clicked(GtkButton *b, gpointer credit_window);

#endif