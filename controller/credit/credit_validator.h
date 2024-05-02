#ifndef _CONTROLLER_CREIDIT_CREDIT_VALIDATOR_H
#define _CONTROLLER_CREIDIT_CREDIT_VALIDATOR_H

#include "config/config_credit.h"
#include "controller/validator.h"
#include "data_structs/credit_context.h"

int credit_validator(const credit_context_t *context);

#endif