#include "calc_context.h"

void calc_context_init(calc_context_t *calc_context) {
  calc_context->x_flag = X_FLAG;
  calc_context->offset_x = OFFSET_X;
  calc_context->offset_y = OFFSET_Y;
  calc_context->scale_x = SCALE_X;
  calc_context->scale_y = SCALE_Y;
  calc_context->x_delta = X_DELTA;
  calc_context->is_zero_start_clicked = IS_ZERO_START_CLICKED;
}