#include "types.h"
#include "print.h"
#include "read.h"
#include "eval.h"

static const char* grammar = " \
    number : /-?[0-9]+/ ;                               \
    symbol : \"list\"  | \"head\"  | \"tail\"  | \"join\"  | \"eval\"  | '+' | '-' | '*' | '/' | '%'; \
    sexpr  : '(' <expr>* ')' ;                          \
    qexpr  : '{' <expr>* '}' ;                          \
    expr   : <number> | <symbol> | <sexpr> | <qexpr> ;  \
    lispy  : /^/ <expr>* /$/ ;                          \
";

int main(int argc, char** argv)
{
  mpc_parser_t* Number = mpc_new("number");
  mpc_parser_t* Symbol = mpc_new("symbol");
  mpc_parser_t* Sexpr = mpc_new("sexpr");
  mpc_parser_t* Qexpr = mpc_new("qexpr");
  mpc_parser_t* Expr = mpc_new("expr");
  mpc_parser_t* Lispy = mpc_new("lispy");

  mpca_lang(MPC_LANG_DEFAULT,
            grammar,
            Number, Symbol, Sexpr, Qexpr, Expr, Lispy);


  puts("Lispy Version 0.0.0.1");
  puts("Press Ctrl+c to Exit\n");

  while(1) {
    char *input = readline("lispy> ");

    add_history(input);

    mpc_result_t r;
    if (mpc_parse("<stdin>", input, Lispy, &r)) {
      lval* tree = lval_read(r.output);

      lval* x = lval_eval(tree);

      lval_println(x);
      lval_free(x);
      mpc_ast_delete(r.output);
    } else {
      mpc_err_print(r.error);
      mpc_err_delete(r.error);
    }

    free(input);
  }

  mpc_cleanup(6, Number, Symbol, Sexpr, Qexpr, Expr, Lispy);

  return 0;
}
