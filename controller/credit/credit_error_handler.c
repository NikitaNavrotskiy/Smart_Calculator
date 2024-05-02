#include "controller/credit/credit_error_handler.h"

void credit_error_handler(gpointer credit_window) {
  GtkWidget *label_credit_payments_result = g_object_get_data(
      G_OBJECT(credit_window), "label_credit_payments_result");
  GtkWidget *label_credit_overpayment_result = g_object_get_data(
      G_OBJECT(credit_window), "label_credit_overpayment_result");
  GtkWidget *label_credit_total_payment_result = g_object_get_data(
      G_OBJECT(credit_window), "label_credit_total_payment_result");
  gtk_label_set_text(GTK_LABEL(label_credit_payments_result), CREDIT_ERROR_MSG);
  gtk_label_set_text(GTK_LABEL(label_credit_overpayment_result),
                     CREDIT_ERROR_MSG);
  gtk_label_set_text(GTK_LABEL(label_credit_total_payment_result),
                     CREDIT_ERROR_MSG);
}