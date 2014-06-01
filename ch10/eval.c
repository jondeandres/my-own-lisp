#include "types.h"
#include "eval.h"
#include "builtin.h"

lval* lval_eval_sexpr(lval* v) {
    for (int i = 0; i < v->count; i++) {
        v->cell[i] = lval_eval(v->cell[i]);
    }

    for (int i = 0; i < v->count; i++) {
        if (v->cell[i]->type == LVAL_ERR) { return lval_take(v, i); }
    }

    if (v->count == 0) { return v; }

    if (v->count == 1) { return lval_take(v, 0); }

    lval* f = lval_pop(v, 0);

    if (f->type != LVAL_SYM) {
        lval_free(f);
        lval_free(v);
        return lval_err("S-Expression doesn't start with symbol!");
    }

    lval* result = builtin(v, f->sym);
    lval_free(f);

    return result;
}

lval* lval_eval(lval* v)
{
    if (v->type == LVAL_SEXPR) {
        return lval_eval_sexpr(v);
    }

    return v;
}

