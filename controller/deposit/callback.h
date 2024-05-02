#ifndef _CONTROLLER_DEPOSIT_CALLBACK_H
#define _CONTROLLER_DEPOSIT_CALLBACK_H

#include <controller/deposit/value_handler.h>
#include <gtk/gtk.h>

#include "controller/deposit/calculate.h"
#include "controller/deposit/deposit_error_handler.h"
#include "controller/value_handler.h"
#include "data_structs/deposit_context.h"
#include "modules/deposit.h"
#include "view/deposit.h"

void on_destroy_deposit(GtkWidget *widget);

void on_button_deposit_calculate_clicked(GtkButton *b, gpointer user_data);

void on_button_deposit_reset_clicked(GtkButton *b, gpointer deposit_window);

#endif