#include <iostream>
#include "tree.hh"
/*  FUNCOES AUXILIARES  */

extern int yylineno;

int get_line_number() {
	return yylineno;
}

void exporta(void* arvore) {
	Node* arv = (Node*) arvore;
	std::cout << arvore << " [label=\"" << " " << "\"]" << std::endl;
	
	for (auto child : arv->children) {
		
	}
}

void libera(void* arvore) {
	delete (Node*) arvore;
}