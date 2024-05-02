#include "callback.h"

void add_text_to_label(GtkButton *b, gpointer user_data) {
  GtkWidget *label_answer = GTK_WIDGET(user_data);
  int *is_zero_start_clicked =
      (int *)g_object_get_data(G_OBJECT(label_answer), "is_zero_start_clicked");
  gchar *res_text;
  const gchar *cur = gtk_label_get_text(GTK_LABEL(label_answer));
  const gchar *text_from_button = gtk_button_get_label(b);
  if (g_str_equal(cur, (const gchar *)"0") && !(*is_zero_start_clicked)) {
    res_text = g_strdup_printf("%s", text_from_button);
    *is_zero_start_clicked = 1;
  } else if (strlen(cur) >= 5 && strncmp(cur, "ERROR", 5) == 0)
    res_text = g_strdup_printf("%s", text_from_button);
  else
    res_text = g_strdup_printf("%s%s", cur, text_from_button);

  gtk_label_set_text(GTK_LABEL(label_answer), (const gchar *)res_text);

  g_free(res_text);
  g_object_set_data(G_OBJECT(label_answer), "is_zero_start_clicked",
                    is_zero_start_clicked);
}

void delete_text_from_label(gpointer user_data) {
  GtkWidget *label_answer = GTK_WIDGET(user_data);
  int *is_zero_start_clicked =
      (int *)g_object_get_data(G_OBJECT(label_answer), "is_zero_start_clicked");
  gtk_label_set_text(GTK_LABEL(label_answer), (const gchar *)"0");
  *is_zero_start_clicked = 0;
  g_object_set_data(G_OBJECT(label_answer), "is_zero_start_clicked",
                    is_zero_start_clicked);
}

void add_open_brace_to_text(gpointer user_data) {
  GtkWidget *label_answer = GTK_WIDGET(user_data);
  gchar *res_text;
  const gchar *cur = gtk_label_get_text(GTK_LABEL(label_answer));

  res_text = g_strdup_printf("%s(", cur);

  gtk_label_set_text(GTK_LABEL(label_answer), (const gchar *)res_text);

  g_free(res_text);
}

void delete_one_sym_from_text(gpointer user_data) {
  GtkWidget *label_answer = GTK_WIDGET(user_data);
  int *is_zero_start_clicked =
      (int *)g_object_get_data(G_OBJECT(label_answer), "is_zero_start_clicked");
  gchar *cur = (gchar *)gtk_label_get_text(GTK_LABEL(label_answer));
  gchar *new_str;

  gint len = g_utf8_strlen(cur, -1);
  if (len == 1) {
    new_str = g_strdup_printf("%c", (gchar)'0');
    *is_zero_start_clicked = 0;
  } else if (len > 1)
    new_str = g_strndup(cur, len - 1);
  gtk_label_set_text(GTK_LABEL(label_answer), new_str);
  g_free(new_str);
  g_object_set_data(G_OBJECT(label_answer), "is_zero_start_clicked",
                    is_zero_start_clicked);
}

void remove_zeroes(char *str) {
  int flag = 0;
  size_t size = strlen(str);
  for (int i = size - 1; i >= 0 && !flag; i--) {
    if (str[i] == '0' || str[i] == '.' || str[i] == ',') {
      char tmp = str[i];
      str[i] = '\0';
      if (tmp == '.' || tmp == ',') flag = 1;
    } else
      flag = 1;
  }
}

void on_button_zero_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  GtkWidget *label_answer = GTK_WIDGET(user_data);
  int *is_zero_start_clicked =
      (int *)g_object_get_data(G_OBJECT(label_answer), "is_zero_start_clicked");
  add_text_to_label(b, user_data);
  *is_zero_start_clicked = 1;
  g_object_set_data(G_OBJECT(label_answer), "is_zero_start_clicked",
                    is_zero_start_clicked);
}

void on_button_one_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
}

void on_button_two_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
}

void on_button_three_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
}

void on_button_four_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
}

void on_button_five_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
}

void on_button_six_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
}

void on_button_seven_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
}

void on_button_eight_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
}

void on_button_nine_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
}

void on_button_dot_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
}

void on_button_add_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
}

void on_button_sub_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
}

void on_button_mul_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
}

void on_button_div_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
}

void on_button_x_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  GtkWidget *label_answer = GTK_WIDGET(user_data);
  int *x_flag = (int *)g_object_get_data(G_OBJECT(label_answer), "x_flag");
  add_text_to_label(b, user_data);
  *x_flag = 1;
  g_object_set_data(G_OBJECT(label_answer), "x_flag", x_flag);
}

void on_button_del_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  GtkWidget *label_answer = GTK_WIDGET(user_data);
  const char *str = (const char *)gtk_label_get_text(GTK_LABEL(label_answer));
  if (strlen(str) >= 5 && strncmp("ERROR", str, 5) == 0)
    delete_text_from_label(user_data);
  else
    delete_one_sym_from_text(user_data);
}

void on_button_open_brace_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
}

void on_button_close_brace_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
}

void on_button_clear_all_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  delete_text_from_label(user_data);
}

void on_button_mod_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
}

void on_button_power_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
}

void on_button_equal_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  GtkWidget *label_answer = GTK_WIDGET(user_data);
  GtkWidget *drawing_area =
      g_object_get_data(G_OBJECT(label_answer), "drawing_area");
  GtkWidget *entry_calc_x =
      g_object_get_data(G_OBJECT(label_answer), "entry_calc_x");
  long double x;
  int err_x = double_value_handler(entry_calc_x, &x);
  int *x_flag = (int *)g_object_get_data(G_OBJECT(label_answer), "x_flag");
  int *is_zero_start_clicked =
      (int *)g_object_get_data(G_OBJECT(label_answer), "is_zero_start_clicked");
  double res = 0.0;
  int err = 0;
  const char *cur =
      (const char *)(gchar *)gtk_label_get_text(GTK_LABEL(label_answer));
  gchar *new_str;
  if (*x_flag == 0 || !err_x) {
    gtk_widget_queue_draw(drawing_area);
    res = calculate_answer(&cur, x, &err);
    if (err == 1) {
      new_str = (char *)g_strdup("ERROR");
      *is_zero_start_clicked = 1;
    } else
      new_str = (char *)g_strdup_printf((const gchar *)"%.9lf", res);
    remove_zeroes(new_str);
    gtk_label_set_text(GTK_LABEL(label_answer), (const gchar *)new_str);
    g_free(new_str);
  } else
    gtk_widget_queue_draw(drawing_area);
  g_object_set_data(G_OBJECT(label_answer), "x_flag", x_flag);
  g_object_set_data(G_OBJECT(label_answer), "is_zero_start_clicked",
                    is_zero_start_clicked);
}

void on_button_cos_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
  add_open_brace_to_text(user_data);
}

void on_button_sin_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
  add_open_brace_to_text(user_data);
}

void on_button_tan_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
  add_open_brace_to_text(user_data);
}

void on_button_acos_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
  add_open_brace_to_text(user_data);
}

void on_button_asin_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
  add_open_brace_to_text(user_data);
}

void on_button_atan_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
  add_open_brace_to_text(user_data);
}

void on_button_sqrt_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
  add_open_brace_to_text(user_data);
}

void on_button_ln_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
  add_open_brace_to_text(user_data);
}

void on_button_log10_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  add_text_to_label(b, user_data);
  add_open_brace_to_text(user_data);
}

void on_button_move_up_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  move_up(user_data);
}

void on_button_move_down_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  move_down(user_data);
}

void on_button_move_left_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  move_left(user_data);
}

void on_button_move_right_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  move_right(user_data);
}

void on_button_scale_up_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  scale_up(user_data);
}

void on_button_scale_down_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  scale_down(user_data);
}

void on_button_credit_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  credit_init(GTK_WIDGET(user_data));
}

void on_button_deposit_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  deposit_init(GTK_WIDGET(user_data));
}
