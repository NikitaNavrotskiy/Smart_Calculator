#include "controller/deposit/value_handler.h"

int deposit_value_handler(gpointer deposit_window, deposit_context_t *context) {
  int err = 0, term = 0, capital = 0, freq = 0;
  long double amount = 0.0, interest = 0.0, tax = 0.0;
  long double withdraw = 0.0, replenish = 0.0;

  GtkWidget *entry_deposit_amount =
      g_object_get_data(G_OBJECT(deposit_window), "entry_deposit_amount");
  GtkWidget *entry_deposit_term =
      g_object_get_data(G_OBJECT(deposit_window), "entry_deposit_term");
  GtkWidget *entry_deposit_term_len =
      g_object_get_data(G_OBJECT(deposit_window), "entry_deposit_rate_len");
  GtkWidget *entry_deposit_interest_rate = g_object_get_data(
      G_OBJECT(deposit_window), "entry_deposit_interest_rate");
  GtkWidget *entry_deposit_tax_rate =
      g_object_get_data(G_OBJECT(deposit_window), "entry_deposit_tax_rate");
  GtkWidget *entry_deposit_payment_freq =
      g_object_get_data(G_OBJECT(deposit_window), "entry_deposit_payment_freq");
  GtkWidget *entry_deposit_replenish =
      g_object_get_data(G_OBJECT(deposit_window), "entry_deposit_replenish");
  GtkWidget *entry_deposit_withdraw =
      g_object_get_data(G_OBJECT(deposit_window), "entry_deposit_withdraw");
  GtkWidget *button_active =
      g_object_get_data(G_OBJECT(deposit_window), "toggle_button_capital");
  capital = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(button_active));
  int err_amount = double_value_handler(entry_deposit_amount, &amount);
  int err_term = int_value_handler(entry_deposit_term, &term);
  int err_interest_rate =
      double_value_handler(entry_deposit_interest_rate, &interest);
  int err_tax_rate = double_value_handler(entry_deposit_tax_rate, &tax);
  int err_withdraw = double_value_handler(entry_deposit_withdraw, &withdraw);
  int err_replenish = double_value_handler(entry_deposit_replenish, &replenish);

  if (err_amount || err_term || err_interest_rate || err_tax_rate ||
      err_withdraw || err_replenish)
    err = 1;
  else {
    deposit_varied_value_handler(entry_deposit_term_len,
                                 entry_deposit_payment_freq, &term, &freq);
    deposit_context_value_handler(context, amount, interest, tax, term, freq,
                                  replenish, withdraw, capital);
  }
  return err;
}

void deposit_context_value_handler(deposit_context_t *context,
                                   long double amount, long double interest,
                                   long double tax, int term, int freq,
                                   long double replenish, long double withdraw,
                                   int capital) {
  context->amount = amount;
  context->interest = interest;
  context->tax = tax;
  context->months = term;
  context->freq_pay = freq;
  context->replenish = replenish;
  context->withdraw = withdraw;
  context->capital = capital;
}

void deposit_varied_value_handler(GtkWidget *term_len, GtkWidget *payment_freq,
                                  int *term, int *freq) {
  if (strncmp(gtk_entry_get_text(GTK_ENTRY(term_len)), "Year(s)", 7) == 0)
    *term *= 12;
  if (strncmp(gtk_entry_get_text(GTK_ENTRY(payment_freq)), "Once a year", 11) ==
      0)
    *freq = YEARLY;
  else if (strncmp(gtk_entry_get_text(GTK_ENTRY(payment_freq)), "Once a month",
                   12) == 0)
    *freq = MONTHLY;
}