#include "controller/credit/value_handler.h"

int credit_value_handler(gpointer credit_window, credit_context_t *context) {
  int err = 0;
  long double amount = 0.0, interest = 0.0;
  int term = 0, type = 0;

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

  int err_credit_amount = double_value_handler(entry_credit_amount, &amount);
  int err_credit_term = int_value_handler(entry_credit_term, &term);
  int err_credit_interest_rate =
      double_value_handler(entry_credit_interest_rate, &interest);

  if (err_credit_amount || err_credit_term || err_credit_interest_rate)
    err = 1;
  else {
    credit_varied_value_handler(entry_credit_rate_len,
                                entry_credit_type_payment, &term, &type);
    credit_context_value_handler(context, amount, interest, term, type);
  }
  return err;
}

void credit_context_value_handler(credit_context_t *context, long double amount,
                                  long double interest, int term, int type) {
  context->amount = amount;
  context->interest = interest;
  context->months = term;
  context->type = type;
}

void credit_varied_value_handler(GtkWidget *rate_len, GtkWidget *type_payment,
                                 int *term, int *type) {
  if (strncmp(gtk_entry_get_text(GTK_ENTRY(rate_len)), "Year(s)", 7) == 0)
    *term *= 12;
  if (strncmp(gtk_entry_get_text(GTK_ENTRY(type_payment)), "Annuity", 8) == 0)
    *type = ANNUITY;
  else if ((strncmp(gtk_entry_get_text(GTK_ENTRY(type_payment)), "Differential",
                    12) == 0))
    *type = DIFFERENTIAL;
}