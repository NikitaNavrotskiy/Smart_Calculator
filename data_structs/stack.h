#ifndef _DATA_STRUCTS_STACK_H
#define _DATA_STRUCTS_STACK_H

#include <stdbool.h>
#include <stdlib.h>

#include "data_structs/node.h"

typedef struct {
  node_t *top;
  size_t size;
} _stack_t;

_stack_t *create_stack();  // constructor

void remove_stack(_stack_t *st);  // destructor

void push(_stack_t *st, double value, token_t token);

void pop(_stack_t *st);

node_t *top(const _stack_t *st);

bool empty(const _stack_t *st);

#endif