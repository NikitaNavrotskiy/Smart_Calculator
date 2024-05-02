#include "alg.h"

int is_digit(char c) {
  int res = 0;
  if (c <= '9' && c >= '0') res = 1;
  return res;
}

int is_small_operation(char c) {
  int res = 0;
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') res = 1;
  return res;
}

int get_prior(token_t tok) {
  int res = 0;

  if (tok == POW)
    res = 3;
  else if (tok == MUL || tok == DIV)
    res = 2;
  else if (tok == SUB || tok == SUM)
    res = 1;
  return res;
}

int is_function(const char *str) {
  int res = 0;
  if (strlen(str) > 3 &&
      ((!strncmp("acos", str, 4) || !strncmp("asin", str, 4) ||
        !strncmp("atan", str, 4) || !strncmp("sqrt", str, 4))))
    res = 1;
  else if (strlen(str) >= 2 && !strncmp("ln", str, 2))
    res = 1;
  else if (strlen(str) > 2 &&
           ((!strncmp("cos", str, 3) || !strncmp("mod", str, 3) ||
             !strncmp("sin", str, 3) || !strncmp("tan", str, 3)) ||
            !strncmp("log", str, 3)))
    res = 1;
  else
    res = 0;
  return res;
}

int get_func(const char **str, token_t *token) {
  int res = 0;
  if (is_function(*str)) {
    if (!strncmp("ln", *str, 2)) {
      *token = LN;
      (*str) += 2;
    } else if (!strncmp("mod", *str, 3)) {
      *token = MOD;
      (*str) += 3;
    } else if (!strncmp("log", *str, 3)) {
      *token = LOG10;
      (*str) += 3;
    } else if (!strncmp("sin", *str, 3)) {
      *token = SIN;
      (*str) += 3;
    } else if (!strncmp("cos", *str, 3)) {
      *token = COS;
      (*str) += 3;
    } else if (!strncmp("tan", *str, 3)) {
      *token = TAN;
      (*str) += 3;
    } else if (!strncmp("acos", *str, 4)) {
      *token = ACOS;
      (*str) += 4;
    } else if (!strncmp("asin", *str, 4)) {
      *token = ASIN;
      (*str) += 4;
    } else if (!strncmp("sqrt", *str, 4)) {
      *token = SQRT;
      (*str) += 4;
    } else if (!strncmp("atan", *str, 4)) {
      *token = ATAN;
      (*str) += 4;
    } else
      res = 0;
  }
  return res;
}

int is_start_with_double(const char *str, int unar) {
  int res = 0;
  if (is_digit(*str) ||
      ((*str == '-' || *str == '+') && unar && is_digit(*(str + 1))))
    res = 1;
  return res;
}

void get_ptr_to_next_token(const char **str) {
  while (is_digit(**str) || **str == '.' || **str == ',') (*str)++;
}

double get_double(const char **str, int *has_double, int *end_of_str,
                  int unar) {
  double res = 0.0;

  if (is_start_with_double(*str, unar)) {
    res = strtod(*str, NULL);
    if (res < 0.0) (*str)++;
    *has_double = 1;
    get_ptr_to_next_token(str);
    if (**(str++) == '\0') *end_of_str = 1;
  } else
    *has_double = 0;

  return res;
}

void get_small_operation(const char **str, token_t *token) {
  switch (**str) {
    case '+':
      *token = SUM;
      break;
    case '-':
      *token = SUB;
      break;
    case '*':
      *token = MUL;
      break;
    case '/':
      *token = DIV;
      break;
    case '^':
      *token = POW;
      break;
    default:
      token = NULL;
      break;
  }
  (*str)++;
}

void close_brace_case(const char **str, list_t *list, _stack_t *stack,
                      int *err) {
  int was_oper_brace = 0;
  (*str)++;
  node_t *loc_tmp;
  int loc_res = 0;
  while (!loc_res) {
    loc_tmp = top(stack);
    if (loc_tmp)
      if (loc_tmp->token == OPEN_BRACE) {
        loc_res = 1;
        was_oper_brace = 1;
      } else {
        push_back(list, loc_tmp->value, loc_tmp->token);
        pop(stack);
      }
    else {
      *err = 1;
      loc_res = 1;
    }
  }
  if (was_oper_brace == 0)
    *err = 1;
  else {
    if (loc_tmp->token == OPEN_BRACE) pop(stack);
    loc_tmp = top(stack);
    if (loc_tmp && (loc_tmp->token >= 11 && loc_tmp->token <= 20)) {
      push_back(list, 0.0, loc_tmp->token);
      pop(stack);
    }
  }
}

void small_operation_case(const char **str, list_t *list, _stack_t *stack,
                          int *err) {
  int stop = 0;
  token_t tok = NUM;
  node_t *tmp2;
  get_small_operation(str, &tok);

  while (!stop && !*err) {
    if (!empty(stack)) {
      tmp2 = top(stack);
      int prior1 = get_prior(tok);
      int prior2 = get_prior(tmp2->token);
      if (prior2 != 0 && prior2 >= prior1 && tmp2->token >= 6 &&
          tmp2->token <= 10) {
        push_back(list, tmp2->value, tmp2->token);
        pop(stack);
      } else
        stop = 1;
    } else
      stop = 1;
  }
  push(stack, 0.0, tok);
}

int finish_str_to_rev_polish(_stack_t *stack, list_t *list) {
  node_t *node_tmp;
  int err = 0;
  int loc_res = 0;
  while (!loc_res) {
    node_tmp = top(stack);
    if (node_tmp == NULL)
      loc_res = 1;
    else if (node_tmp->token == OPEN_BRACE || node_tmp->token == CLOSE_BRACE) {
      err = 1;
      loc_res = 1;
    } else if (node_tmp) {
      push_back(list, 0.0, node_tmp->token);
      pop(stack);
    }
  }
  return err;
}

int str_to_rev_polish(const char **str, list_t *list) {
  int count_braces = 0;
  _stack_t *stack = create_stack();
  double tmp = 0.0;
  int err = 0, loc_res = 0, end = 0, has_double = 0, is_unar = 1;
  token_t token_tmp;
  while (**str && !err && !end) {
    if (**str == '-' && *(*str + 1) == '(') {
      push_back(list, -1.0, NUM);
      push(stack, 0.0, MUL);
      (*str)++;
    } else if (**str == 'x') {
      push_back(list, 0.0, X);
      (*str)++;
      is_unar = 0;
    } else if (is_start_with_double(*str, is_unar)) {
      tmp = get_double(str, &has_double, &end, is_unar);
      if (has_double) push_back(list, tmp, NUM);
      is_unar = 0;
    } else if (is_function(*str)) {
      loc_res = get_func(str, &token_tmp);
      if (loc_res == 0)
        push(stack, 0.0, token_tmp);
      else
        err = 1;
      if (token_tmp == MOD) is_unar = 1;
    } else if (**str == '(') {
      count_braces++;
      (*str)++;
      push(stack, 0.0, OPEN_BRACE);
      is_unar = 1;
    } else if (**str == ')') {
      count_braces--;
      close_brace_case(str, list, stack, &err);
      is_unar = 0;
    } else if (is_small_operation(**str)) {
      small_operation_case(str, list, stack, &err);
      is_unar = 1;
    } else
      end = 1;
  }
  if (count_braces != 0) err = 1;
  if (!err) err = finish_str_to_rev_polish(stack, list);
  remove_stack(stack);
  return err;
}

double calculate_small_operation(_stack_t *stack, token_t oper, int *err) {
  double res = 0.0, a = 0.0, b = 0.0;
  if (empty(stack))
    *err = 1;
  else {
    a = stack->top->value;
    pop(stack);
  }
  if ((!empty(stack) && top(stack)->token != NUM && oper == SUB) ||
      (empty(stack) && oper == SUB))
    res = -a;
  else if (!empty(stack)) {
    b = stack->top->value;
    pop(stack);
  } else
    *err = 1;
  if (*err == 0) {
    switch (oper) {
      case SUM:
        res = b + a;
        break;
      case SUB:
        res = b - a;
        break;
      case MUL:
        res = b * a;
        break;
      case DIV:
        if (fabs(a) < 1e-15)
          *err = 1;
        else
          res = b / a;
        break;
      case POW:
        if (a == 0 && b == 0)
          *err = 1;
        else
          res = pow(b, a);
        break;
      case MOD:
        res = fmod(b, a);
        break;
      default:
        break;
    }
  }
  return res;
}

double calculate_func(_stack_t *stack, token_t oper, int *err) {
  double res = 0.0, a = 0.0;
  if (empty(stack))
    *err = 1;
  else {
    a = stack->top->value;
    pop(stack);
  }
  if (*err == 0) {
    switch (oper) {
      case COS:
        res = cos(a);
        break;
      case SIN:
        res = sin(a);
        break;
      case TAN:
        res = tan(a);
        break;
      case ACOS:
        res = acos(a);
        break;
      case ASIN:
        res = asin(a);
        break;
      case ATAN:
        res = atan(a);
        break;
      case SQRT:
        res = sqrt(a);
        break;
      case LN:
        res = log(a);
        break;
      case LOG10:
        res = log10(a);
        break;
      default:
        break;
    }
  }
  if (isnan(res)) *err = 1;
  return res;
}

int is_tok_small_oper(token_t tok) {
  return (tok == SUM || tok == SUB || tok == MUL || tok == DIV || tok == POW);
}

int is_tok_func(token_t tok) {
  return (tok == COS || tok == SIN || tok == TAN || tok == ACOS ||
          tok == ASIN || tok == ATAN || tok == SQRT || tok == LN ||
          tok == LOG10);
}

double calculate_answer(const char **str, double x, int *err_glob) {
  double res = 0.0;
  int err = 0;
  node_t *tmp;
  _stack_t *stack = create_stack();
  list_t *list = create_list();
  err = str_to_rev_polish(str, list);

  tmp = list->head;

  while (tmp && !err) {
    double tmp_double = 0.0;
    token_t tok = tmp->token;
    if (tok == NUM)
      push(stack, tmp->value, tok);
    else if (tok == X)
      push(stack, x, NUM);
    else if (is_tok_small_oper(tok) || tok == MOD) {
      tmp_double = calculate_small_operation(stack, tok, &err);
      push(stack, tmp_double, NUM);
    } else if (is_tok_func(tok)) {
      tmp_double = calculate_func(stack, tok, &err);
      push(stack, tmp_double, NUM);
    }
    tmp = tmp->next;
  }
  if (!empty(stack))
    res = top(stack)->value;
  else
    err = 1;
  *err_glob = err;
  remove_list(list);
  remove_stack(stack);

  return res;
}
