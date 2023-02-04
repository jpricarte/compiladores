#include <iostream>
#include "tree.hh"

Node::Node(LexicalVal lex_val) : lex_val(lex_val) {}
Node::Node(int line_no, TokenType token_type, TokenVal token_val) {
    this->lex_val = LexicalVal{line_no, token_type, token_val};
}
