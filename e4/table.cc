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

int SymbolTableStack::find_symbol_table(TokenVal key) {
    int i = this->stack.size()-1;
    for (; i>=0; i--) {
        if (this->stack[i].find(key) != this->stack[i].end())
            break;
    }
    return i;
}

void SymbolTableStack::emplace_top(Node_p node) {}

void SymbolTableStack::insert_top(TokenVal lv, Symbol s) {
    this->top().insert({lv, s});
    // printf("inserido\n");
}
