#include <iostream>
#include <string>
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

string Node::to_string() {
    switch (this->lex_val.token_type) {
        case TokenType::SPECIAL_CHAR:
            return std::to_string(get<char>(this->lex_val.token_val));
        case TokenType::RESERVED_WORD:
        case TokenType::COMPOSED_OPERATOR:
        case TokenType::IDENTIFIER:
            return get<string>(this->lex_val.token_val);            
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