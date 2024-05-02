#include "stack.h"

_stack_t *create_stack() {
  _stack_t *tmp = (_stack_t *)calloc(sizeof(_stack_t), 1);

  tmp->top = NULL;
  tmp->size = 0;

  return tmp;
}

void remove_stack(_stack_t *st) {
  if (st) {
    while (!empty(st)) pop(st);
    free(st);
  }

  st = NULL;
}

void push(_stack_t *st, double value, token_t token) {
  node_t *tmp = create_node(value, token, st->top);

  st->top = tmp;
  st->size++;
}

void pop(_stack_t *st) {
  if (st->top) {
    node_t *tmp = st->top;
    st->top = st->top->next;
    st->size--;
    remove_node(tmp);
  }
}

node_t *top(const _stack_t *st) { return st->top; }

bool empty(const _stack_t *st) { return st->top == NULL; }
