#include "value_handler.h"

int double_value_handler(GtkWidget *entry, long double *value) {
  int err = 0;
  const char *text = gtk_entry_get_text(GTK_ENTRY(entry));

  if (validator_is_all_symbols_for_double(text))
    err = 1;
  else {
    long double loc_value = strtold(text, NULL);
    if (strncmp(text, "0", 1) != 0 && fabsl(loc_value) < 1e-19)
      err = 1;
    else
      *value = loc_value;
  }

  return err;
}

int int_value_handler(GtkWidget *entry, int *value) {
  int err = 0;
  const char *text = gtk_entry_get_text(GTK_ENTRY(entry));

  if (validator_is_all_symbols_for_int(text))
    err = 1;
  else {
    int loc_value = atoi(text);
    if (strncmp(text, "0", 1) != 0 && loc_value == 0)
      err = 1;
    else if (loc_value < 0)
      err = 1;
    else
      *value = loc_value;
  }

  return err;
}
