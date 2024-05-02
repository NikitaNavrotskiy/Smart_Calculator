#include "credit.h"

void credit_init(GtkWidget *main_window) {
  GtkBuilder *credit_builder = gtk_builder_new_from_file(CREDIT_GLADE_FILE);
  GtkWidget *credit_window =
      GTK_WIDGET(gtk_builder_get_object(credit_builder, "credit_window"));

  GtkWidget *amount =
      GTK_WIDGET(gtk_builder_get_object(credit_builder, "entry_credit_amount"));
  GtkWidget *term =
      GTK_WIDGET(gtk_builder_get_object(credit_builder, "entry_credit_term"));
  GtkWidget *rate_len = GTK_WIDGET(
      gtk_builder_get_object(credit_builder, "entry_credit_rate_len"));
  GtkWidget *interest_rate = GTK_WIDGET(
      gtk_builder_get_object(credit_builder, "entry_credit_interest_rate"));
  GtkWidget *type_payment = GTK_WIDGET(
      gtk_builder_get_object(credit_builder, "entry_credit_type_payment"));

  GtkWidget *payments = GTK_WIDGET(
      gtk_builder_get_object(credit_builder, "label_credit_payments"));

  GtkWidget *payments_result = GTK_WIDGET(
      gtk_builder_get_object(credit_builder, "label_credit_payments_result"));
  GtkWidget *overpayment_result = GTK_WIDGET(gtk_builder_get_object(
      credit_builder, "label_credit_overpayment_result"));
  GtkWidget *total_payment_result = GTK_WIDGET(gtk_builder_get_object(
      credit_builder, "label_credit_total_payment_result"));
  credit_init_set_data(credit_window, amount, term, rate_len, interest_rate,
                       type_payment, payments, payments_result,
                       overpayment_result, total_payment_result);
  gtk_builder_connect_signals(credit_builder, NULL);
  g_object_set_data(G_OBJECT(main_window), "credit_window", credit_window);
  g_object_unref(G_OBJECT(credit_builder));
}

void credit_init_set_data(GtkWidget *credit_window, GtkWidget *amount,
                          GtkWidget *term, GtkWidget *rate_len,
                          GtkWidget *interest_rate, GtkWidget *type_payment,
                          GtkWidget *payments, GtkWidget *payments_result,
                          GtkWidget *overpayment_result,
                          GtkWidget *total_payment_result) {
  g_object_set_data(G_OBJECT(credit_window), "entry_credit_amount", amount);
  g_object_set_data(G_OBJECT(credit_window), "entry_credit_term", term);
  g_object_set_data(G_OBJECT(credit_window), "entry_credit_rate_len", rate_len);
  g_object_set_data(G_OBJECT(credit_window), "entry_credit_interest_rate",
                    interest_rate);
  g_object_set_data(G_OBJECT(credit_window), "entry_credit_type_payment",
                    type_payment);
  g_object_set_data(G_OBJECT(credit_window), "credit_label_payments", payments);
  g_object_set_data(G_OBJECT(credit_window), "label_credit_payments_result",
                    payments_result);
  g_object_set_data(G_OBJECT(credit_window), "label_credit_overpayment_result",
                    overpayment_result);
  g_object_set_data(G_OBJECT(credit_window),
                    "label_credit_total_payment_result", total_payment_result);
  GtkCssProvider *prov = gtk_css_provider_new();
  gtk_css_provider_load_from_path(GTK_CSS_PROVIDER(prov), CREDIT_STYLE_FILE,
                                  NULL);
  gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                                            GTK_STYLE_PROVIDER(prov),
                                            GTK_STYLE_PROVIDER_PRIORITY_USER);
}

void credit_destroy(GtkWidget *credit_window) {
  gtk_widget_destroy(credit_window);
}