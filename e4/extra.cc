#include <iostream>
#include "tree.hh"

#define ERR_UNDECLARED 10 //2.2
#define ERR_DECLARED 11 //2.2
#define ERR_VARIABLE 20 //2.3
#define ERR_ARRAY 21 //2.3
#define ERR_FUNCTION 22 //2.3
#define ERR_CHAR_TO_INT 31 //2.4
#define ERR_CHAR_TO_FLOAT 32 //2.4
#define ERR_CHAR_TO_BOOL 33 //2.4
#define ERR_CHAR_VECTOR 34 //2.4
#define ERR_X_TO_CHAR 35 //2.4

/*  FUNCOES AUXILIARES  */

extern int yylineno;
bool debug = false;

int get_line_number() {
	return yylineno;
}

void exporta(void* arvore) {
    if (arvore != nullptr) {
        auto arv = std::shared_ptr<Node>((Node*) arvore);
        print_arvore(arv);
    }
}

void libera(void* arvore) {
}