#ifndef _CONTROLLER_DEPOSIT_DEPOSIT_VALIDATOR_H
#define _CONTROLLER_DEPOSIT_DEPOSIT_VALIDATOR_H

#include "config/config_deposit.h"
#include "controller/validator.h"
#include "data_structs/deposit_context.h"

int deposit_validator(const deposit_context_t *context);

#endif