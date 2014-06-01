#include "types.h"

#ifndef BUILTIN_H
#define BUILTIN_H

lval* builtin(lval*, char*);
lval* builtin_op(lval*, char*);
lval* builtin_head(lval*);
lval* builtin_tail(lval*);
lval* builtin_list(lval*);
lval* builtin_eval(lval*);
lval* builtin_join(lval*);

#endif
