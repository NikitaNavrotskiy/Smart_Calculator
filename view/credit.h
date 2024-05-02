#ifndef _VIEW_CREDIT_H
#define _VIEW_CREDIT_H

#include <gtk/gtk.h>

#include "config/config_credit.h"
#include "controller/credit/callback.h"

void credit_init(GtkWidget *main_window);

void credit_init_set_data(GtkWidget *credit_window, GtkWidget *amount,
                          GtkWidget *term, GtkWidget *rate_len,
                          GtkWidget *interest_rate, GtkWidget *type_payment,
                          GtkWidget *payments, GtkWidget *payments_result,
                          GtkWidget *overpayment_result,
                          GtkWidget *total_payment_result);

void credit_destroy(GtkWidget *credit_window);

#endif
