#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "tree.hh"

using namespace std;
extern bool debug;

Node::Node(LexicalVal lex_val) : lex_val(lex_val) {
    if (debug)
        clog << this->to_string() << endl;
}

Node::Node(int line_no, TokenType token_type, TokenVal token_val) {
    this->lex_val = LexicalVal{line_no, token_type, token_val};
    if (debug)
        clog << this->to_string() << endl;
}

Node::~Node() { 
    if (debug)
        std::clog << "deleting " << this->to_string() << " from line " << this->get_line_no() << std::endl;
}

void Node::add_child(Node* child) {
    if (child != nullptr) {
        this->children.push_back(Node_p(child));
    }
}

void Node::add_null_child() {
    this->children.push_back(nullptr);
}

std::string node_type_to_string (Type tt) {
    switch (tt) {
        case Type::BOOLEAN:
            return "bool";
        case Type::CHARACTER:
            return "char";
        case Type::INTEGER:
            return "int";
        case Type::FLOATING:
            return "float";
        default:
            return "Algo deu errado.";
    }
}

string Node::token_val_to_string() {
    switch (this->node_type) {
        case Type::INTEGER:
            return std::to_string(get<int>(this->lex_val.token_val));
        case Type::FLOATING:
            return std::to_string(get<float>(this->lex_val.token_val));
        case Type::CHARACTER:
            return std::string(&get<char>(this->lex_val.token_val), 1);
        case Type::BOOLEAN:
            return std::to_string(get<bool>(this->lex_val.token_val));
        default:
            return "Algo deu errado.";
    }
}

string Node::to_string() {
    switch (this->lex_val.token_type) {
        case TokenType::SPECIAL_CHAR:
            return std::string(&get<char>(this->lex_val.token_val), 1);
        case TokenType::RESERVED_WORD:
        case TokenType::COMPOSED_OPERATOR:
            return get<string>(this->lex_val.token_val); 
        case TokenType::IDENTIFIER:
            if (this->is_func_call) {
                return std::string("call ")+get<string>(this->lex_val.token_val);
            }
            else return get<string>(this->lex_val.token_val);            
        case TokenType::LIT_INT:
            return std::to_string(get<int>(this->lex_val.token_val));
        case TokenType::LIT_FLOAT:
            return std::to_string(get<float>(this->lex_val.token_val));
        case TokenType::LIT_CHAR:
            return std::string(&get<char>(this->lex_val.token_val), 1);
        case TokenType::LIT_BOOL:
            return std::to_string(get<bool>(this->lex_val.token_val));
        default:
            return "";
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