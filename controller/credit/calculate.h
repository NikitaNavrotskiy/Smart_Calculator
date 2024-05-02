#ifndef _CONTROLLER_CREDIT_CALCULATE_H
#define _CONTROLLER_CREDIT_CALCULATE_H

#include "controller/credit/credit_validator.h"
#include "data_structs/credit_context.h"
#include "modules/annuity.h"
#include "modules/diff.h"

int credit_calculate(credit_context_t *context);

#endif