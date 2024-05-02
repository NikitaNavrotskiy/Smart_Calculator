#include "calc.h"
#include "credit.h"
#include "deposit.h"

int main(int argc, char *argv[]) {
  setlocale(LC_NUMERIC, "C");
  calc_context_t calc_context = {0};

  calc_context_init(&calc_context);
  gtk_init(&argc, &argv);

  GtkBuilder *calc_builder = gtk_builder_new_from_file(CALC_GLADE_FILE);

  GtkWidget *main_window =
      GTK_WIDGET(gtk_builder_get_object(calc_builder, "main_window"));

  GtkWidget *label_answer =
      GTK_WIDGET(gtk_builder_get_object(calc_builder, "label_answer"));
  GtkWidget *drawing_area =
      GTK_WIDGET(gtk_builder_get_object(calc_builder, "drawing_area_graph"));
  calc_init(main_window, calc_builder, &calc_context, drawing_area,
            label_answer);
  calc_init_drawing_area(drawing_area, &calc_context);

  gtk_widget_show_all(main_window);
  gtk_main();

  g_object_unref(G_OBJECT(calc_builder));

  return 0;
}