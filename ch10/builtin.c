#include "types.h"
#include "eval.h"
#include "builtin.h"

#define LASSERT(args, cond, err)                \
    if (!cond) {                                \
        lval_free(args);                        \
        return lval_err(err);                   \
    }


lval* builtin(lval* a, char* func) {
    if (strcmp(func, "list") == 0) { return builtin_list(a); }
    if (strcmp(func, "head") == 0) { return builtin_head(a); }
    if (strcmp(func, "tail") == 0) { return builtin_tail(a); }
    if (strcmp(func, "join") == 0) { return builtin_join(a); }
    if (strcmp(func, "eval") == 0) { return builtin_eval(a); }
    if (strstr("+-/*%", func)) { return builtin_op(a, func); }

    lval_free(a);
    return lval_err("Unkown function!");
}

lval* builtin_op(lval* a, char* op) {
    for (int i = 0; i < a->count; i++) {
        if (a->cell[i]->type != LVAL_NUM) {
            lval_free(a);
            return lval_err("Cannot operate on no-number!");
        }
    }

    lval* x = lval_pop(a, 0);

    if (strcmp(op, "-") == 0 && a->count == 0) { x->num = -x->num; }

    while (a->count > 0) {
        lval* y = lval_pop(a, 0);

        if (strcmp(op, "+") == 0) { x->num += y->num; }
        if (strcmp(op, "-") == 0) { x->num -= y->num; }
        if (strcmp(op, "*") == 0) { x->num *= y->num; }
        if (strcmp(op, "/") == 0) {
            if (y->num == 0) {
                x = lval_err("Division by zero!");
                break;
            }

            x->num /= y->num;
        }

        if (strcmp(op, "%") == 0) {
            if (y->num == 0) {
                x = lval_err("Division by zero!");
                break;
            }

            x->num %= y->num;
        }

        lval_free(y);
    }

    lval_free(a);

    return x;
}

lval* builtin_head(lval* a) {
    LASSERT(a, a->count == 1,                  "Function 'head' passed too many arguments!");
    LASSERT(a, a->cell[0]->type == LVAL_QEXPR, "Function 'head' passed wrong arguments! ");
    LASSERT(a, a->cell[0]->count != 0,         "Function 'head' passed {}! ");

    lval* v = lval_take(a, 0);

    while (v->count > 1) {
        lval_free(lval_pop(v, 1));
    }
    return v;
}

lval* builtin_tail(lval* a) {
    LASSERT(a, a->count == 1,                  "Function 'tail' passed too many arguments!");
    LASSERT(a, a->cell[0]->type == LVAL_QEXPR, "Function 'tail' passed wrong arguments! ");
    LASSERT(a, a->cell[0]->count != 0,         "Function 'tail' passed {}! ");

    lval* v = lval_take(a, 0);

    lval_free(lval_take(v, 0));
    return v;
}

lval* builtin_list(lval* a) {
    a->type = LVAL_QEXPR;
    return a;
}

lval* builtin_eval(lval *a) {
    LASSERT(a, a->count == 1, "Function 'eval' passed too many arguments!");
    LASSERT(a, a->cell[0]->type == LVAL_QEXPR, "Function 'eval' passed wrong arguments!");

    lval* x = lval_take(a, 0);
    x->type = LVAL_SEXPR;

    return lval_eval(x);
}

lval* builtin_join(lval* a) {
    for (int i = 0; i < a->count; i++) {
        LASSERT(a, a->cell[i]->type == LVAL_QEXPR, "Function 'join' passed wrong arguments!");
    }

    lval* x = lval_pop(a, 0);
    while (a->count) { x = lval_join(x, lval_pop(a, 0)); }
    lval_free(a);

    return x;
}
