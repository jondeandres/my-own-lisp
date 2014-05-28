#include <stdio.h>
#include <stdlib.h>
#include <editline/readline.h>
#include <mpc.h>

#ifndef TYPES_H
#define TYPES_H

enum { LVAL_ERR, LVAL_NUM, LVAL_SYM, LVAL_SEXPR };

typedef struct lval {
    int type;

    long num;
    /* Error and Symbol have string data */
    char* err;
    char* sym;

    /* Count and Pointer to list of lval* */
    int count;
    struct lval** cell;

} lval;

lval* lval_num(long);
lval* lval_err(char*);
lval* lval_sym(char*);
lval* lval_sexpr(void);

void lval_free(lval*);
lval* lval_add(lval*, lval*);
lval* lval_pop(lval*, int);
lval* lval_take(lval*, int);

#endif
