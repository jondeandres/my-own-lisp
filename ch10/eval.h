#include "types.h"

#ifndef EVAL_H
#define EVAL_H

lval* lval_eval_sexpr(lval*);
lval* lval_eval(lval*);
lval* builtin_op(lval*, char*);
lval* builtin_head(lval*);
lval* builtin_tail(lval*);

#endif
