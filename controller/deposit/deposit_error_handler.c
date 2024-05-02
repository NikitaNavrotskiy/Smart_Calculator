#include "controller/deposit/deposit_error_handler.h"

void deposit_error_handler(gpointer deposit_window) {
  GtkWidget *label_total_interest = g_object_get_data(
      G_OBJECT(deposit_window), "label_deposit_total_interest_result");
  GtkWidget *label_deposit_total_tax = g_object_get_data(
      G_OBJECT(deposit_window), "label_deposit_total_tax_result");
  GtkWidget *label_deposit_revenue = g_object_get_data(
      G_OBJECT(deposit_window), "label_deposit_revenue_result");

  gtk_label_set_text(GTK_LABEL(label_total_interest), DEPOSIT_ERROR_MSG);
  gtk_label_set_text(GTK_LABEL(label_deposit_total_tax), DEPOSIT_ERROR_MSG);
  gtk_label_set_text(GTK_LABEL(label_deposit_revenue), DEPOSIT_ERROR_MSG);
}