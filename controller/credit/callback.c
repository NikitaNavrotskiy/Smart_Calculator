#include "callback.h"

void on_destroy_credit(GtkWidget *widget) { credit_destroy(widget); }

void on_entry_credit_type_payment_changed(GtkEntry *entry, gpointer user_data) {
  if (!GTK_IS_ENTRY(entry)) return;
  GtkWidget *label_credit_payments =
      g_object_get_data(G_OBJECT(user_data), "credit_label_payments");
  const char *label_text = gtk_entry_get_text(entry);

  if (strncmp("Annuity", label_text, 8) == 0)
    gtk_label_set_text(GTK_LABEL(label_credit_payments), "Monthly payments:");
  else if (strncmp("Differential", label_text, 12) == 0)
    gtk_label_set_text(GTK_LABEL(label_credit_payments),
                       "First & Last payments:");
}

void on_button_credit_calculate_clicked(GtkButton *b, gpointer user_data) {
  if (!GTK_IS_BUTTON(b)) return;
  int err = 0;
  credit_context_t context = {0};

  GtkWidget *label_credit_payments_result =
      g_object_get_data(G_OBJECT(user_data), "label_credit_payments_result");
  GtkWidget *label_credit_overpayment_result =
      g_object_get_data(G_OBJECT(user_data), "label_credit_overpayment_result");
  GtkWidget *label_credit_total_payment_result = g_object_get_data(
      G_OBJECT(user_data), "label_credit_total_payment_result");

  err = credit_value_handler(user_data, &context);
  if (!err) {
    err = credit_calculate(&context);
    if (!err) {
      gchar *monthly_payment;
      if (context.type == ANNUITY)
        monthly_payment = g_strdup_printf("%.2Lf", context.monthly_payment);
      else if (context.type == DIFFERENTIAL)
        monthly_payment = g_strdup_printf("%.2Lf\n%.2Lf", context.first_payment,
                                          context.last_payment);
      gtk_label_set_text(GTK_LABEL(label_credit_payments_result),
                         monthly_payment);
      gchar *new_overpayment = g_strdup_printf("%.2Lf", context.overpayment);
      gchar *new_total = g_strdup_printf("%.2Lf", context.total_payment);
      gtk_label_set_text(GTK_LABEL(label_credit_overpayment_result),
                         new_overpayment);
      gtk_label_set_text(GTK_LABEL(label_credit_total_payment_result),
                         new_total);
      g_free(new_overpayment);
      g_free(new_total);
      g_free(monthly_payment);
    }
  }
  if (err) credit_error_handler(user_data);
}

void on_button_credit_reset_clicked(GtkButton *b, gpointer credit_window) {
  if (!GTK_IS_BUTTON(b)) return;
  GtkWidget *entry_credit_amount =
      g_object_get_data(G_OBJECT(credit_window), "entry_credit_amount");
  GtkWidget *entry_credit_term =
      g_object_get_data(G_OBJECT(credit_window), "entry_credit_term");
  GtkWidget *entry_credit_rate_len =
      g_object_get_data(G_OBJECT(credit_window), "entry_credit_rate_len");
  GtkWidget *entry_credit_interest_rate =
      g_object_get_data(G_OBJECT(credit_window), "entry_credit_interest_rate");
  GtkWidget *entry_credit_type_payment =
      g_object_get_data(G_OBJECT(credit_window), "entry_credit_type_payment");
  GtkWidget *payments_result = g_object_get_data(
      G_OBJECT(credit_window), "label_credit_payments_result");
  GtkWidget *overpayment_result = g_object_get_data(
      G_OBJECT(credit_window), "label_credit_overpayment_result");
  GtkWidget *total_payment_result = g_object_get_data(
      G_OBJECT(credit_window), "label_credit_total_payment_result");
  GtkWidget *label_credit_payments =
      g_object_get_data(G_OBJECT(credit_window), "credit_label_payments");
  gtk_label_set_text(GTK_LABEL(label_credit_payments), "Monthly payments:");
  gtk_entry_set_text(GTK_ENTRY(entry_credit_amount), "");
  gtk_entry_set_text(GTK_ENTRY(entry_credit_term), "");
  gtk_entry_set_text(GTK_ENTRY(entry_credit_interest_rate), "");
  gtk_entry_set_text(GTK_ENTRY(entry_credit_rate_len), "Year(s)");
  gtk_entry_set_text(GTK_ENTRY(entry_credit_type_payment), "Annuity");
  gtk_label_set_text(GTK_LABEL(payments_result), "");
  gtk_label_set_text(GTK_LABEL(overpayment_result), "");
  gtk_label_set_text(GTK_LABEL(total_payment_result), "");
}