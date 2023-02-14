#include <iostream>
#include "tree.hh"
#include "table.hh"
/*  FUNCOES AUXILIARES  */

extern int yylineno;
bool debug = false;

void print_arvore(std::shared_ptr<Node> arvore);

int get_line_number() {
	return yylineno;
}

void exporta(void* arvore) {
    if (arvore != nullptr) {
        auto arv = std::shared_ptr<Node>((Node*) arvore);
        print_arvore(arv);
    }
}

void print_arvore(std::shared_ptr<Node> arvore) {
	std::cout << arvore << " [label=\"" << arvore->to_string() << "\"]" << std::endl;
	
	// erro no parse: shared_ptr<Node> -> void*
	for (auto& child : arvore->children) {
		std::cout << arvore << "," << child << std::endl;
		print_arvore(child);
	}
}

void libera(void* arvore) {
}