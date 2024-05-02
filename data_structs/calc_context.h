#ifndef _DATA_STRUCTS_CALC_CONTEXT_H
#define _DATA_STRUCTS_CALC_CONTEXT_H

#include "config/config_calc.h"

typedef struct {
  int x_flag;
  int is_zero_start_clicked;
  int scale_x;
  int scale_y;
  double x_delta;
  int offset_x;
  int offset_y;
} calc_context_t;

void calc_context_init(calc_context_t *calc_context);

#endif