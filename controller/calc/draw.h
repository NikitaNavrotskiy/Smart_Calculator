#ifndef _CONTROLLER_CALC_DRAW_H
#define _CONTROLLER_CALC_DRAW_H

#include "controller/calc/callback.h"

void move_right(gpointer user_data);

void move_left(gpointer user_data);

void move_up(gpointer user_data);

void move_down(gpointer user_data);

void scale_up(gpointer user_data);

void scale_down(gpointer user_data);

void cord_prepare(cairo_t *cr, int width, int height, int *offset_x,
                  int *offset_y);

void set_cord_x(cairo_t *cr, int width, int height, int *offset_x,
                int *offset_y, int scale);

void set_cord_y(cairo_t *cr, int width, int height, int *offset_x,
                int *offset_y, int scale);

void set_cord_axises(cairo_t *cr, gint width, gint height, int scale,
                     GtkWidget *drawing_area);

#endif