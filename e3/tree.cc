#include <iostream>
#include <algorithm>
#include "tree.hh"

using namespace std;

Node::Node(LexicalVal lex_val) : lex_val(lex_val) {}

Node::Node(int line_no, TokenType token_type, TokenVal token_val) {
    this->lex_val = LexicalVal{line_no, token_type, token_val};
}

void Node::add_child(Node* child) {
    if (child != nullptr) {
        this->children.push_back(Node_p(child));
    }
}
