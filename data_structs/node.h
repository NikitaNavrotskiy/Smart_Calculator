#ifndef _DATA_STRUCTS_NODE_H
#define _DATA_STRUCTS_NODE_H

#include <stdlib.h>

typedef enum {
  NUM,
  OPEN_BRACE,
  CLOSE_BRACE,
  X,
  UNAR_PLUS,
  UNAR_MINUS,
  SUM,
  SUB,
  MUL,
  DIV,
  POW,
  MOD,
  COS,
  SIN,
  TAN,
  ACOS,
  ASIN,
  ATAN,
  SQRT,
  LN,
  LOG10
} token_t;

typedef struct node {
  double value;
  token_t token;
  struct node *next;
} node_t;

node_t *create_node(double value, token_t token, node_t *next);

void remove_node(node_t *nd);

#endif