#include "calc.h"

void calc_init(GtkWidget *main_window, GtkBuilder *builder,
               calc_context_t *calc_context, GtkWidget *drawing_area,
               GtkWidget *label_answer) {
  GtkWidget *entry_calc_x =
      GTK_WIDGET(gtk_builder_get_object(builder, "entry_calc_x"));
  g_object_set_data(G_OBJECT(label_answer), "x_flag", &calc_context->x_flag);
  g_object_set_data(G_OBJECT(label_answer), "is_zero_start_clicked",
                    &calc_context->is_zero_start_clicked);
  g_object_set_data(G_OBJECT(label_answer), "drawing_area", drawing_area);
  g_object_set_data(G_OBJECT(label_answer), "entry_calc_x", entry_calc_x);
  gtk_label_set_max_width_chars(GTK_LABEL(label_answer), 30);
  gtk_label_set_ellipsize(GTK_LABEL(label_answer), PANGO_ELLIPSIZE_START);
  gtk_label_set_xalign(GTK_LABEL(label_answer), 0.0);

  gtk_builder_connect_signals(builder, NULL);
  GtkCssProvider *prov = gtk_css_provider_new();
  gtk_css_provider_load_from_path(GTK_CSS_PROVIDER(prov), CALC_STYLE_FILE,
                                  NULL);
  gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                                            GTK_STYLE_PROVIDER(prov),
                                            GTK_STYLE_PROVIDER_PRIORITY_USER);
  g_signal_connect(main_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
}

void calc_init_drawing_area(GtkWidget *drawing_area,
                            calc_context_t *calc_context) {
  g_object_set_data(G_OBJECT(drawing_area), "scale_x", &calc_context->scale_x);
  g_object_set_data(G_OBJECT(drawing_area), "scale_y", &calc_context->scale_y);
  g_object_set_data(G_OBJECT(drawing_area), "x_delta", &calc_context->x_delta);
  g_object_set_data(G_OBJECT(drawing_area), "offset_x",
                    &calc_context->offset_x);
  g_object_set_data(G_OBJECT(drawing_area), "offset_y",
                    &calc_context->offset_y);
}
