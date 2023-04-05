#include <iostream>
#include "tree.hh"

/*  FUNCOES AUXILIARES  */

extern int yylineno;
bool debug = false;

int get_line_number() {
	return yylineno;
}

void exporta(void* arvore) {
    if (arvore != nullptr) {
        auto arv = std::shared_ptr<Node>((Node*) arvore);
        // print_arvore(arv);
        for (auto command : arv->iloc_code_element.code) {
            command.to_string();
        }
    }
}

void libera(void* arvore) {
}