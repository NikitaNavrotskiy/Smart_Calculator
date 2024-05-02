#ifndef _VIEW_CALC_H
#define _VIEW_CALC_H

#include <gtk/gtk.h>
#include <locale.h>

#include "config/config_calc.h"
#include "controller/calc/callback.h"
#include "data_structs/calc_context.h"

void calc_init(GtkWidget *main_window, GtkBuilder *builder,
               calc_context_t *calc_context, GtkWidget *drawing_area,
               GtkWidget *label_answer);

void calc_init_drawing_area(GtkWidget *drawing_area,
                            calc_context_t *calc_context);

#endif