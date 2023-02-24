#include "table.hh"

Type type_infer (Type symbol_1, Type symbol_2) {
/*
 *  Dado dois simbolos, faz inferência e retorna o tipo.
 */

    if (symbol_1 == symbol_2) {
        return symbol_1;
    }

    if (symbol_1 == Type::FLOATING || symbol_2 == Type::FLOATING)
        return Type::FLOATING;

    if (symbol_1 == Type::INTEGER || symbol_2 == Type::INTEGER)
        return Type::INTEGER;

    else return Type::TYPE_ERROR;
}

size_t get_size_from_type(const Type t) {
    switch(t) {
        case Type::INTEGER:
            return 4;
        case Type::FLOATING:
            return 8;
        case Type::BOOLEAN:
        case Type::CHARACTER:
            return 1;
        default:
            return 0;
    }
}

void SymbolTableStack::emplace_top(Node_p node) {
    Symbol s{};
    s.line_no = node->get_line_no();
    s.type = node->get_node_type();
    s.size = get_size_from_type(s.type);
    s.assoc_node = node;

    this->top().insert({node->get_token_val(), s});
}

void SymbolTableStack::insert_top(Symbol s) {
    TokenVal val = s.assoc_node->get_token_val();
    this->top().insert({val, s});
}


/*
struct Symbol {
    int line_no;
    Kind kind;
    Type type; // Declarado em tree.hh
    size_t size;
    Node_p assoc_node;
};

struct LexicalVal {
    int line_no;
    TokenType token_type;
    TokenVal token_val;
};

struct Node {
    LexicalVal lex_val;
    std::vector<std::shared_ptr<Node>> children;
    bool is_func_call = false;
    Type node_type;
};
*/