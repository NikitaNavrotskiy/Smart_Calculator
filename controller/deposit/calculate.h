#ifndef _CONTROLLER_DEPOSIT_CALCULATE_H
#define _CONTROLLER_DEPOSIT_CALCULATE_H

#include "controller/deposit/deposit_validator.h"
#include "data_structs/deposit_context.h"
#include "modules/deposit.h"

int deposit_calculate(deposit_context_t *context);

#endif