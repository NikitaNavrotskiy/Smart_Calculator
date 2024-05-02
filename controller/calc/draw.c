#include "callback.h"

void move_right(gpointer user_data) {
  GtkWidget *drawing_area = GTK_WIDGET(user_data);
  int *offset_x = g_object_get_data(G_OBJECT(drawing_area), "offset_x");
  *offset_x -= 10;
  gtk_widget_queue_draw(drawing_area);
  g_object_set_data(G_OBJECT(drawing_area), "offset_x", offset_x);
}

void move_left(gpointer user_data) {
  GtkWidget *drawing_area = GTK_WIDGET(user_data);
  int *offset_x = g_object_get_data(G_OBJECT(drawing_area), "offset_x");
  *offset_x += 10;
  gtk_widget_queue_draw(drawing_area);
  g_object_set_data(G_OBJECT(drawing_area), "offset_x", offset_x);
}

void move_up(gpointer user_data) {
  GtkWidget *drawing_area = GTK_WIDGET(user_data);
  int *offset_y = g_object_get_data(G_OBJECT(drawing_area), "offset_y");
  *offset_y += 10;
  gtk_widget_queue_draw(drawing_area);
  g_object_set_data(G_OBJECT(drawing_area), "offset_y", offset_y);
}

void move_down(gpointer user_data) {
  GtkWidget *drawing_area = GTK_WIDGET(user_data);
  int *offset_y = g_object_get_data(G_OBJECT(drawing_area), "offset_y");
  *offset_y -= 10;
  gtk_widget_queue_draw(drawing_area);
  g_object_set_data(G_OBJECT(drawing_area), "offset_y", offset_y);
}

void scale_up(gpointer user_data) {
  GtkWidget *drawing_area = GTK_WIDGET(user_data);
  int *scale_x = g_object_get_data(G_OBJECT(drawing_area), "scale_x");
  int *scale_y = g_object_get_data(G_OBJECT(drawing_area), "scale_y");
  *scale_x += 5;
  *scale_y += 5;
  gtk_widget_queue_draw(drawing_area);
  g_object_set_data(G_OBJECT(drawing_area), "scale_x", scale_x);
  g_object_set_data(G_OBJECT(drawing_area), "scale_y", scale_y);
}

void scale_down(gpointer user_data) {
  GtkWidget *drawing_area = GTK_WIDGET(user_data);
  int *scale_x = g_object_get_data(G_OBJECT(drawing_area), "scale_x");
  int *scale_y = g_object_get_data(G_OBJECT(drawing_area), "scale_y");
  if (*scale_x > 10 && *scale_y > 10) {
    *scale_x -= 5;
    *scale_y -= 5;
  }
  gtk_widget_queue_draw(drawing_area);
  g_object_set_data(G_OBJECT(drawing_area), "scale_x", scale_x);
  g_object_set_data(G_OBJECT(drawing_area), "scale_y", scale_y);
}

void cord_prepare(cairo_t *cr, int width, int height, int *offset_x,
                  int *offset_y) {
  cairo_set_source_rgba(cr, 0.3, 0.0, 0.0, 0.5);
  cairo_paint(cr);

  cairo_set_source_rgb(cr, 0.9, 0.9, 0.9);
  cairo_set_line_width(cr, 0.5);

  cairo_move_to(cr, 0, height / 2.0 + *offset_y);
  cairo_line_to(cr, width, height / 2.0 + *offset_y);
  cairo_stroke(cr);

  cairo_move_to(cr, width / 2.0 + *offset_x, 0);
  cairo_line_to(cr, width / 2.0 + *offset_x, height);
  cairo_stroke(cr);
}

void set_cord_x(cairo_t *cr, int width, int height, int *offset_x,
                int *offset_y, int scale) {
  for (int x = 0; x < width / 2 - *offset_x; x += scale) {
    char num_x[20];
    cairo_set_font_size(cr, (scale - 9) * 0.2);
    if (x == 0)
      cairo_move_to(cr, x + width / 2 + *offset_x + 10,
                    height / 2.0 + scale / 3 + *offset_y);
    else
      cairo_move_to(cr, x + width / 2 + *offset_x,
                    height / 2.0 + scale / 3 + *offset_y);
    sprintf(num_x, "%d", x / scale);
    cairo_show_text(cr, (const char *)num_x);
    cairo_move_to(cr, x + width / 2 + *offset_x, height / 2.0 + 3 + *offset_y);
    cairo_line_to(cr, x + width / 2 + *offset_x, height / 2.0 - 3 + *offset_y);
    cairo_stroke(cr);
  }

  for (int x = -1; x > -width / 2 - *offset_x; x -= scale) {
    if (x / scale != 0) {
      char _num_x[20];
      cairo_set_font_size(cr, (scale - 9) * 0.2);
      cairo_move_to(cr, x + width / 2 + *offset_x,
                    height / 2.0 + scale / 3 + *offset_y);
      sprintf(_num_x, "%d", x / scale);
      cairo_show_text(cr, (const char *)_num_x);
      cairo_move_to(cr, x + width / 2 + *offset_x,
                    height / 2.0 + 3 + *offset_y);
      cairo_line_to(cr, x + width / 2 + *offset_x,
                    height / 2.0 - 3 + *offset_y);
      cairo_stroke(cr);
    }
  }
}

void set_cord_y(cairo_t *cr, int width, int height, int *offset_x,
                int *offset_y, int scale) {
  for (int y_ = 0; y_ < height / 2 - *offset_y; y_ += scale) {
    int y = -y_;
    if (y / scale != 0) {
      char num_y[20];
      cairo_set_font_size(cr, (scale - 9) * 0.2);
      cairo_move_to(cr, width / 2 + 10 + *offset_x,
                    height / 2.0 - y + *offset_y);
      sprintf(num_y, "%d", y / scale);
      cairo_show_text(cr, (const char *)num_y);
    }
    cairo_move_to(cr, width / 2.0 + 3 + *offset_x, y_ + height / 2 + *offset_y);
    cairo_line_to(cr, width / 2.0 - 3 + *offset_x, y_ + height / 2 + *offset_y);
    cairo_stroke(cr);
  }
  for (int y_ = -1; y_ > -height / 2 - *offset_y; y_ -= scale) {
    int y = -y_;
    if (y / scale != 0) {
      char _num_y[20];
      cairo_set_font_size(cr, (scale - 9) * 0.2);
      cairo_move_to(cr, width / 2 + 10 + *offset_x,
                    -y + height / 2.0 + *offset_y);

      sprintf(_num_y, "%d", y / scale);
      cairo_show_text(cr, (const char *)_num_y);
    }
    cairo_move_to(cr, width / 2.0 + 3 + *offset_x, y_ + height / 2 + *offset_y);
    cairo_line_to(cr, width / 2.0 - 3 + *offset_x, y_ + height / 2 + *offset_y);
    cairo_stroke(cr);
  }
}

void set_cord_axises(cairo_t *cr, gint width, gint height, int scale,
                     GtkWidget *drawing_area) {
  int *offset_x = g_object_get_data(G_OBJECT(drawing_area), "offset_x");
  int *offset_y = g_object_get_data(G_OBJECT(drawing_area), "offset_y");

  cord_prepare(cr, width, height, offset_x, offset_y);

  set_cord_x(cr, width, height, offset_x, offset_y, scale);
  set_cord_y(cr, width, height, offset_x, offset_y, scale);
}

void on_drawing_area_graph_draw(GtkWidget *widget, cairo_t *cr,
                                gpointer user_data) {
  GtkWidget *label_answer = GTK_WIDGET(user_data);
  int *scale_x = g_object_get_data(G_OBJECT(widget), "scale_x");
  int *scale_y = g_object_get_data(G_OBJECT(widget), "scale_y");
  int *offset_x = g_object_get_data(G_OBJECT(widget), "offset_x");
  int *offset_y = g_object_get_data(G_OBJECT(widget), "offset_y");
  double *x_delta = g_object_get_data(G_OBJECT(widget), "x_delta");
  const char *str = (const char *)gtk_label_get_text(GTK_LABEL(label_answer));
  const char *tmp;
  int scale = *scale_x;
  gint width, height;
  GdkRGBA color = {0.9, 0.9, 0.9, 1.0};

  width = gtk_widget_get_allocated_width(widget);
  height = gtk_widget_get_allocated_height(widget);

  set_cord_axises(cr, width, height, scale, widget);

  gdk_cairo_set_source_rgba(cr, &color);
  cairo_set_line_width(cr, 2.0);
  double y_prev = 0.0;
  int err_prev = 1;

  for (double x = -width / 2; x <= width / 2; x += *x_delta * 100 / scale) {
    int err = 0;
    tmp = str;
    double y = calculate_answer(&str, x, &err);
    if (!err && !isnan(y) && !isinf(y) && !err_prev && !isnan(y_prev) &&
        !isinf(y_prev))
      cairo_line_to(cr, x * *scale_x + width / 2 + *offset_x,
                    height / 2 - y * *scale_y + *offset_y);
    else if (!err && !isnan(y) && !isinf(y))
      cairo_move_to(cr, x * *scale_x + width / 2 + *offset_x,
                    height / 2 - y * *scale_y + *offset_y);
    str = tmp;
    y_prev = y;
    err_prev = err;
  }

  cairo_stroke(cr);
}