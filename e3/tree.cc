#include <iostream>
#include <algorithm>
#include "tree.hh"

using namespace std;

Node::Node(LexicalVal lex_val) : lex_val(lex_val) {}

Node::Node(int line_no, TokenType token_type, TokenVal token_val) {
    this->lex_val = LexicalVal{line_no, token_type, token_val};
}

void Node::insert_child(Node* child) {
    if (child != nullptr) {
        this->children.push_back(Node_p(child));
    }
}

bool Node::is_useless() {
    switch (this->lex_val.token_type) {
        case TokenType::SPECIAL_CHAR:
            if (find(useless_chars.begin(), useless_chars.end(), get<char>(this->lex_val.token_val)) != useless_chars.end()) {
                return true;
            }
            break;
        case TokenType::RESERVED_WORD:
            break;
        case TokenType::COMPOSED_OPERATOR:
            break;
        case TokenType::IDENTIFIER:
            break;
        case TokenType::LIT_INT:
            break;
        case TokenType::LIT_FLOAT:
            break;
        case TokenType::LIT_CHAR:
            break;
        case TokenType::LIT_BOOL:
            break;
    }
    return false;
}