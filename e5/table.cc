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

void SymbolTableStack::pop(TokenVal key) {
    SymbolTable st = this->stack.back();
    symbol_table_memory.insert({ key, st });
    this->stack.pop_back(); 
    curr_desloc.pop_back();
}

SymbolTable& SymbolTableStack::recover_symbol_table(TokenVal key) {
    return this->symbol_table_memory[key];
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



std::vector<ILOC_Code::Command> create_call_commands(ILOC_Code::lab_t func_label, SymbolTable table, std::vector<ILOC_Code::reg_t> param_regs) {
    const int INT_SIZE = 4;
    std::vector<ILOC_Code::Command> code_list {};

    ILOC_Code::reg_t r_new_fp = ILOC_Code::get_new_register();
    code_list.push_back(ILOC_Code::Command{ILOC_Code::Instruct::I2I, ILOC_Code::RSP, ILOC_Code::NO_REG, r_new_fp, ILOC_Code::NO_REG});
    code_list.push_back(ILOC_Code::Command{ILOC_Code::Instruct::ADD_I, r_new_fp, 2 * INT_SIZE, r_new_fp, ILOC_Code::NO_REG});
    code_list.push_back(ILOC_Code::Command{ILOC_Code::Instruct::STORE, ILOC_Code::RFP, ILOC_Code::NO_REG, r_new_fp, ILOC_Code::NO_REG});
    code_list.push_back(ILOC_Code::Command{ILOC_Code::Instruct::I2I, r_new_fp, ILOC_Code::NO_REG, ILOC_Code::RFP, ILOC_Code::NO_REG});

    int i = INT_SIZE;
    for (auto reg=param_regs.rbegin(); reg != param_regs.rend(); reg++) {
        code_list.push_back(ILOC_Code::Command{ILOC_Code::Instruct::STORE_AI, *reg, ILOC_Code::NO_REG, ILOC_Code::RFP, i});
        i += INT_SIZE;
    }

    // guarda 
    int stack_size = table.size() * INT_SIZE;
    int rsp_index = stack_size + INT_SIZE;
    code_list.push_back(ILOC_Code::Command{ILOC_Code::Instruct::I2I, ILOC_Code::RFP, ILOC_Code::NO_REG, ILOC_Code::RSP, ILOC_Code::NO_REG});
    code_list.push_back(ILOC_Code::Command{ILOC_Code::Instruct::ADD_I, ILOC_Code::RSP, rsp_index, ILOC_Code::RSP, ILOC_Code::NO_REG});

    // guarda endereço de retorno
    ILOC_Code::reg_t r_ret_addr = ILOC_Code::get_new_register();
    code_list.push_back(ILOC_Code::Command{ILOC_Code::Instruct::I2I, ILOC_Code::RFP, ILOC_Code::NO_REG, r_ret_addr, ILOC_Code::NO_REG});
    code_list.push_back(ILOC_Code::Command{ILOC_Code::Instruct::SUB_I, r_ret_addr, INT_SIZE, r_ret_addr, ILOC_Code::NO_REG});
    code_list.push_back(ILOC_Code::Command{ILOC_Code::Instruct::STORE, ILOC_Code::RPC, ILOC_Code::NO_REG, r_ret_addr, ILOC_Code::NO_REG});
    code_list.push_back(ILOC_Code::Command{ILOC_Code::Instruct::JUMP_I, ILOC_Code::NO_REG, ILOC_Code::NO_REG, func_label, ILOC_Code::NO_REG});
    return code_list;
}

std::vector<ILOC_Code::Command> create_return_commands() {
    const int INT_SIZE = 4;

    ILOC_Code::reg_t r_current_fp = ILOC_Code::get_new_register();


    std::vector<ILOC_Code::Command> result;
    result.push_back(ILOC_Code::Command{ILOC_Code::Instruct::I2I, ILOC_Code::RFP, ILOC_Code::NO_REG, r_current_fp, ILOC_Code::NO_REG});
    result.push_back(ILOC_Code::Command{ILOC_Code::Instruct::SUB_I, r_current_fp, 2 * INT_SIZE, ILOC_Code::RSP, ILOC_Code::NO_REG});
    result.push_back(ILOC_Code::Command{ILOC_Code::Instruct::LOAD, ILOC_Code::RFP, ILOC_Code::NO_REG, ILOC_Code::RFP, ILOC_Code::NO_REG});
    result.push_back(ILOC_Code::Command{ILOC_Code::Instruct::SUB_I, r_current_fp, INT_SIZE, r_current_fp, ILOC_Code::NO_REG});
    result.push_back(ILOC_Code::Command{ILOC_Code::Instruct::JUMP, ILOC_Code::NO_REG, ILOC_Code::NO_REG, r_current_fp, ILOC_Code::NO_REG});

    return result;
}

