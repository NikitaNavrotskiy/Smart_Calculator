#ifndef _VIEW_DEPOSIT_H
#define _VIEW_DEPOSIT_H

#include <gtk/gtk.h>

#include "config/config_deposit.h"

void deposit_init(GtkWidget *main_window);

void deposit_init_set_data(GtkWidget *deposit_window, GtkWidget *amount,
                           GtkWidget *term, GtkWidget *term_len,
                           GtkWidget *interest_rate, GtkWidget *tax_rate,
                           GtkWidget *payment_freq, GtkWidget *replenish,
                           GtkWidget *withdraw);

void deposit_destroy(GtkWidget *widget);

#endif