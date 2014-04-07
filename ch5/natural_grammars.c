#include <mpc.h>

int main(int argc, char *argv[])
{
     mpc_parser_t* Adjetive = mpc_new("adjetive");
     mpc_parser_t* Noun = mpc_new("noun");
     mpc_parser_t* Phrase = mpc_new("phrase");
     mpc_parser_t* Doge = mpc_new("doge");

     mpca_lang(MPC_LANG_DEFAULT,
               "                                                         \
adjetive : \"wow\" | \"many\" | \"so\" | \"such\";                  \
noun     : \"lisp\" | \"language\" | \"c\" | \"book\" | \"build\";  \
phrase   : <adjetive> <noun>;                                       \
doge     : <phrase>*;                                               \
",
               Adjetive, Noun, Phrase, Doge);


/* Some parsing here */
     mpc_cleanup(4, Adjeive, Noun, Phrase, Doge);

     return 0;
}

