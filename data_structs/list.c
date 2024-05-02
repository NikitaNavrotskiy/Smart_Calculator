#include "list.h"

list_t *create_list() {
  list_t *tmp = (list_t *)calloc(sizeof(list_t), 1);

  tmp->head = NULL;

  return tmp;
}

void remove_list(list_t *lst) {
  if (lst) {
    if (lst->head) {
      if (lst->head->next) {
        node_t *tmp = lst->head, *tmp_next = lst->head->next;
        for (; tmp_next; tmp = tmp_next, tmp_next = tmp_next->next)
          remove_node(tmp);
        remove_node(tmp);
      } else
        remove_node(lst->head);
    }
    free(lst);
  }
}

void push_back(list_t *lst, double value, token_t token) {
  node_t *new = create_node(value, token, NULL);

  if (lst->head) {
    node_t *tmp = lst->head;
    while (tmp->next) tmp = tmp->next;

    tmp->next = new;
  } else
    lst->head = new;
}

void push_front(list_t *lst, double value, token_t token) {
  lst->head = create_node(value, token, lst->head);
}
