#include "tree.hh"
/*  FUNCOES AUXILIARES  */

extern int yylineno;

int get_line_number() {
	return yylineno;
}

void exporta(void* arvore) {}

void libera(void* arvore) {
	delete (Node*) arvore;
}