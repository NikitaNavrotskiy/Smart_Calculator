#include "callback.h"

void on_destroy_deposit(GtkWidget *widget) { deposit_destroy(widget); }

void on_button_deposit_calculate_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;

  int err = 0;
  deposit_context_t cont = {0};

  GtkWidget *label_total_interest = g_object_get_data(
      G_OBJECT(user_data), "label_deposit_total_interest_result");
  GtkWidget *label_deposit_total_tax =
      g_object_get_data(G_OBJECT(user_data), "label_deposit_total_tax_result");
  GtkWidget *label_deposit_revenue =
      g_object_get_data(G_OBJECT(user_data), "label_deposit_revenue_result");

  err = deposit_value_handler(user_data, &cont);
  if (!err) {
    err = deposit_calculate(&cont);
    if (!err) {
      gchar *new_interest = g_strdup_printf("%.2Lf", cont.total_interest_res);
      gchar *new_tax = g_strdup_printf("%.2Lf", cont.total_tax_res);
      gchar *new_revenue = g_strdup_printf("%.2Lf", cont.revenue_res);

      gtk_label_set_text(GTK_LABEL(label_total_interest), new_interest);
      gtk_label_set_text(GTK_LABEL(label_deposit_total_tax), new_tax);
      gtk_label_set_text(GTK_LABEL(label_deposit_revenue), new_revenue);

      g_free(new_interest);
      g_free(new_tax);
      g_free(new_revenue);
    }
  }
  if (err) deposit_error_handler(user_data);
}

void on_button_deposit_reset_clicked(GtkButton *b, gpointer deposit_window) {
  if (!GTK_IS_BUTTON(b)) return;

  GtkWidget *amount =
      g_object_get_data(G_OBJECT(deposit_window), "entry_deposit_amount");
  GtkWidget *term =
      g_object_get_data(G_OBJECT(deposit_window), "entry_deposit_term");
  GtkWidget *term_len =
      g_object_get_data(G_OBJECT(deposit_window), "entry_deposit_rate_len");
  GtkWidget *interest = g_object_get_data(G_OBJECT(deposit_window),
                                          "entry_deposit_interest_rate");
  GtkWidget *tax =
      g_object_get_data(G_OBJECT(deposit_window), "entry_deposit_tax_rate");
  GtkWidget *freq =
      g_object_get_data(G_OBJECT(deposit_window), "entry_deposit_payment_freq");
  GtkWidget *replenish =
      g_object_get_data(G_OBJECT(deposit_window), "entry_deposit_replenish");
  GtkWidget *withdraw =
      g_object_get_data(G_OBJECT(deposit_window), "entry_deposit_withdraw");
  GtkWidget *label_total_interest = g_object_get_data(
      G_OBJECT(deposit_window), "label_deposit_total_interest_result");
  GtkWidget *label_deposit_total_tax = g_object_get_data(
      G_OBJECT(deposit_window), "label_deposit_total_tax_result");
  GtkWidget *label_deposit_revenue = g_object_get_data(
      G_OBJECT(deposit_window), "label_deposit_revenue_result");
  GtkWidget *toggle_button_capital =
      g_object_get_data(G_OBJECT(deposit_window), "toggle_button_capital");
  gtk_entry_set_text(GTK_ENTRY(amount), "");
  gtk_entry_set_text(GTK_ENTRY(term), "");
  gtk_entry_set_text(GTK_ENTRY(interest), "");
  gtk_entry_set_text(GTK_ENTRY(tax), "");
  gtk_entry_set_text(GTK_ENTRY(freq), "Once a month");
  gtk_entry_set_text(GTK_ENTRY(term_len), "Years(s)");
  gtk_entry_set_text(GTK_ENTRY(replenish), "");
  gtk_entry_set_text(GTK_ENTRY(withdraw), "");
  gtk_label_set_text(GTK_LABEL(label_total_interest), "");
  gtk_label_set_text(GTK_LABEL(label_deposit_total_tax), "");
  gtk_label_set_text(GTK_LABEL(label_deposit_revenue), "");
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle_button_capital), FALSE);
}