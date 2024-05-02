#include "deposit.h"

void deposit_init(GtkWidget *main_window) {
  GtkBuilder *deposit_builder = gtk_builder_new_from_file(DEPOSIT_GLADE_FILE);
  GtkWidget *deposit_window =
      GTK_WIDGET(gtk_builder_get_object(deposit_builder, "deposit_window"));
  GtkWidget *amount = GTK_WIDGET(
      gtk_builder_get_object(deposit_builder, "entry_deposit_amount"));
  GtkWidget *term =
      GTK_WIDGET(gtk_builder_get_object(deposit_builder, "entry_deposit_term"));
  GtkWidget *term_len = GTK_WIDGET(
      gtk_builder_get_object(deposit_builder, "entry_deposit_term_len"));
  GtkWidget *interest_rate = GTK_WIDGET(
      gtk_builder_get_object(deposit_builder, "entry_deposit_interest_rate"));
  GtkWidget *tax_rate = GTK_WIDGET(
      gtk_builder_get_object(deposit_builder, "entry_deposit_tax_rate"));
  GtkWidget *payment_freq = GTK_WIDGET(
      gtk_builder_get_object(deposit_builder, "entry_deposit_payment_freq"));
  GtkWidget *replenish = GTK_WIDGET(
      gtk_builder_get_object(deposit_builder, "entry_deposit_replenish"));
  GtkWidget *withdraw = GTK_WIDGET(
      gtk_builder_get_object(deposit_builder, "entry_deposit_withdraw"));
  GtkWidget *capital = GTK_WIDGET(gtk_builder_get_object(
      deposit_builder, "checkbutton_deposit_capitalization"));
  GtkWidget *total_interest_result = GTK_WIDGET(gtk_builder_get_object(
      deposit_builder, "label_deposit_total_interest_result"));
  GtkWidget *total_tax_result = GTK_WIDGET(gtk_builder_get_object(
      deposit_builder, "label_deposit_total_tax_result"));
  GtkWidget *revenue_result = GTK_WIDGET(
      gtk_builder_get_object(deposit_builder, "label_deposit_revenue_result"));
  g_object_set_data(G_OBJECT(deposit_window),
                    "label_deposit_total_interest_result",
                    total_interest_result);
  g_object_set_data(G_OBJECT(deposit_window), "label_deposit_total_tax_result",
                    total_tax_result);
  g_object_set_data(G_OBJECT(deposit_window), "label_deposit_revenue_result",
                    revenue_result);
  g_object_set_data(G_OBJECT(deposit_window), "toggle_button_capital", capital);
  deposit_init_set_data(deposit_window, amount, term, term_len, interest_rate,
                        tax_rate, payment_freq, replenish, withdraw);
  gtk_builder_connect_signals(deposit_builder, NULL);
  g_object_set_data(G_OBJECT(main_window), "deposit_window", deposit_window);
  g_object_unref(G_OBJECT(deposit_builder));
}

void deposit_init_set_data(GtkWidget *deposit_window, GtkWidget *amount,
                           GtkWidget *term, GtkWidget *term_len,
                           GtkWidget *interest_rate, GtkWidget *tax_rate,
                           GtkWidget *payment_freq, GtkWidget *replenish,
                           GtkWidget *withdraw) {
  g_object_set_data(G_OBJECT(deposit_window), "entry_deposit_amount", amount);
  g_object_set_data(G_OBJECT(deposit_window), "entry_deposit_term", term);
  g_object_set_data(G_OBJECT(deposit_window), "entry_deposit_rate_len",
                    term_len);
  g_object_set_data(G_OBJECT(deposit_window), "entry_deposit_interest_rate",
                    interest_rate);
  g_object_set_data(G_OBJECT(deposit_window), "entry_deposit_tax_rate",
                    tax_rate);
  g_object_set_data(G_OBJECT(deposit_window), "entry_deposit_payment_freq",
                    payment_freq);
  g_object_set_data(G_OBJECT(deposit_window), "entry_deposit_replenish",
                    replenish);
  g_object_set_data(G_OBJECT(deposit_window), "entry_deposit_withdraw",
                    withdraw);
  GtkCssProvider *prov = gtk_css_provider_new();
  gtk_css_provider_load_from_path(GTK_CSS_PROVIDER(prov), DEPOSIT_STYLE_FILE,
                                  NULL);
  gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                                            GTK_STYLE_PROVIDER(prov),
                                            GTK_STYLE_PROVIDER_PRIORITY_USER);
}

void deposit_destroy(GtkWidget *widget) { gtk_widget_destroy(widget); }