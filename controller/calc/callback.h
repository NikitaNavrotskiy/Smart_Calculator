#ifndef _CONTROLLER_CALC_CALLBACK_H
#define _CONTROLLER_CALC_CALLBACK_H

#include <gtk/gtk.h>

#include "controller/calc/draw.h"
#include "controller/value_handler.h"
#include "float.h"
#include "modules/alg.h"
#include "view/credit.h"
#include "view/deposit.h"

void add_text_to_label(GtkButton *b, gpointer user_data);

void delete_text_from_label(gpointer user_data);

void add_open_brace_to_text(gpointer user_data);

void delete_one_sym_from_text(gpointer user_data);

void remove_zeroes(char *str);

void on_button_zero_clicked(GtkButton *b, gpointer user_data);

void on_button_one_clicked(GtkButton *b, gpointer user_data);

void on_button_two_clicked(GtkButton *b, gpointer user_data);

void on_button_three_clicked(GtkButton *b, gpointer user_data);

void on_button_four_clicked(GtkButton *b, gpointer user_data);

void on_button_five_clicked(GtkButton *b, gpointer user_data);

void on_button_six_clicked(GtkButton *b, gpointer user_data);

void on_button_seven_clicked(GtkButton *b, gpointer user_data);

void on_button_eight_clicked(GtkButton *b, gpointer user_data);

void on_button_nine_clicked(GtkButton *b, gpointer user_data);

void on_button_dot_clicked(GtkButton *b, gpointer user_data);

void on_button_add_clicked(GtkButton *b, gpointer user_data);

void on_button_sub_clicked(GtkButton *b, gpointer user_data);

void on_button_mul_clicked(GtkButton *b, gpointer user_data);

void on_button_div_clicked(GtkButton *b, gpointer user_data);

void on_button_x_clicked(GtkButton *b, gpointer user_data);

void on_button_del_clicked(GtkButton *b, gpointer user_data);

void on_button_open_brace_clicked(GtkButton *b, gpointer user_data);

void on_button_close_brace_clicked(GtkButton *b, gpointer user_data);

void on_button_clear_all_clicked(GtkButton *b, gpointer user_data);

void on_button_mod_clicked(GtkButton *b, gpointer user_data);

void on_button_power_clicked(GtkButton *b, gpointer user_data);

void on_button_equal_clicked(GtkButton *b, gpointer user_data);

void on_button_cos_clicked(GtkButton *b, gpointer user_data);

void on_button_sin_clicked(GtkButton *b, gpointer user_data);

void on_button_tan_clicked(GtkButton *b, gpointer user_data);

void on_button_acos_clicked(GtkButton *b, gpointer user_data);

void on_button_asin_clicked(GtkButton *b, gpointer user_data);

void on_button_atan_clicked(GtkButton *b, gpointer user_data);

void on_button_sqrt_clicked(GtkButton *b, gpointer user_data);

void on_button_ln_clicked(GtkButton *b, gpointer user_data);

void on_button_log10_clicked(GtkButton *b, gpointer user_data);

void on_drawing_area_graph_draw(GtkWidget *widget, cairo_t *cr,
                                gpointer user_data);

void on_button_move_up_clicked(GtkButton *b, gpointer user_data);

void on_button_move_down_clicked(GtkButton *b, gpointer user_data);

void on_button_move_left_clicked(GtkButton *b, gpointer user_data);

void on_button_move_right_clicked(GtkButton *b, gpointer user_data);

void on_button_scale_up_clicked(GtkButton *b, gpointer user_data);

void on_button_scale_down_clicked(GtkButton *b, gpointer user_data);

void on_button_credit_clicked(GtkButton *b, gpointer user_data);

void on_button_deposit_clicked(GtkButton *b, gpointer user_data);

#endif