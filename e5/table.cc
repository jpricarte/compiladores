#include "table.hh"
#include <iostream>

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

    if (symbol_1 == Type::CHARACTER) {
        return symbol_2;
    } else if (symbol_2 == Type::CHARACTER) {
        return symbol_1;
    }

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

int get_char_err(Type to, Type from) {
    if (from == Type::CHARACTER){
        switch (to) {
            case Type::INTEGER:
                return ERR_CHAR_TO_INT;
            case Type::FLOATING:
                return ERR_CHAR_TO_FLOAT;
            case Type::BOOLEAN:
                return ERR_CHAR_TO_BOOL;
            case Type::CHARACTER:
                return 0;
            default:
                return 1;
        }
    } else {
        if (to == Type::CHARACTER)
            return ERR_X_TO_CHAR;
        else
            return 0;
    }
}

int get_bad_usage_err(Kind expected, Kind received) {
    if (expected != received)
        switch (expected) {
            case Kind::VARIABLE:
                return ERR_VARIABLE;
            case Kind::FUNCTION:
                return ERR_FUNCTION;
            case Kind::ARRAY:
                return ERR_ARRAY;
            case Kind::LITERAL: // não acontece, apenas para omitir warning
                return 0;
        }
    return 0;
}

int SymbolTableStack::find_symbol_table(TokenVal key) {
    int i = this->stack.size()-1;
    for (; i>=0; i--) {
        if (this->stack[i].contains(key))
            break;
    }
    return i;
}

void SymbolTableStack::emplace_top(std::pair<TokenVal, Symbol> p) {
    this->insert_top(p.first, p.second);
}

void SymbolTableStack::insert_top(TokenVal lv, Symbol s, bool lookup_first) {
    if (lookup_first && this->top().contains(lv)) {
        return;
    }
    this->set_desloc(s);
    this->top().insert({lv, s});

    // printf("inserido\n");
}

Symbol SymbolTableStack::get_first_symbol(TokenVal key) {
    int index = this->find_symbol_table(key);
    if (index >= 0) {
        return this->stack[index][key];
    }
    else exit(ERR_UNDECLARED);
}

size_t SymbolTableStack::set_desloc(Symbol& s) {
    // Sera o deslocamento na pilha atual começando em 0 * tam do simbolo
    s.desloc = this->curr_desloc[this->stack.size()-1];
    this->curr_desloc[this->stack.size()-1] += s.size;
    return s.desloc;
}