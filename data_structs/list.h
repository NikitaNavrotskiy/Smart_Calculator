#ifndef _DATA_STRUCTS_LIST_H
#define _DATA_STRUCTS_LIST_H

#include <stdlib.h>

#include "data_structs/node.h"

typedef struct {
  node_t *head;
} list_t;

list_t *create_list();

void remove_list(list_t *lst);

void push_back(list_t *lst, double value, token_t token);

void push_front(list_t *lst, double value, token_t token);

#endif