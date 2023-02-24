#include "table.hh"

Type type_infer (Type symbol_1, Type symbol_2) {
/*
 *  Dado dois simbolos, faz inferência e retorna o tipo.
 */

    if (symbol_1 == symbol_2) {
        if (symbol_1 == Type::INTEGER)
            return Type::INTEGER;
        if (symbol_1 == Type::FLOATING)
            return Type::FLOATING;
        if (symbol_1 == Type::BOOLEAN)
            return Type::BOOLEAN;
    }

    if (symbol_1 == Type::FLOATING || symbol_2 == Type::FLOATING)
        return Type::FLOATING;

    if (symbol_1 == Type::INTEGER || symbol_2 == Type::INTEGER)
        return Type::INTEGER;

    else return Type::TYPE_ERROR;
}
