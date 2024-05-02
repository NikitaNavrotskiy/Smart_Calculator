#include "node.h"

node_t *create_node(double value, token_t token, node_t *next) {
  node_t *tmp = (node_t *)calloc(sizeof(node_t), 1);

  tmp->next = next;
  tmp->token = token;
  tmp->value = value;

  return tmp;
}

void remove_node(node_t *nd) {
  if (nd->next) nd->next = NULL;
  free(nd);
}
