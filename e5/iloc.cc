#include "iloc.hh"
#include <iostream>
#include <algorithm>
#include <string>

using namespace ILOC_Code;


Command::Command(ILOC_Code::lab_t label, Instruct instruct) {
    this->label = label;
    this->instruct = instruct;
    this->op1 = NO_REG;
    this->op2 = NO_REG;
    this->op3 = NO_REG;
    this->op4 = NO_REG;
}

Command::Command(Instruct instruct, reg_t op1, reg_t op2, reg_t op3, reg_t op4) {
    this->instruct = instruct;
    this->op1 = op1;
    this->op2 = op2;
    this->op3 = op3;
    this->op4 = op4;
}

static const char *instruct_to_string[] ={
        "nop",
        "add",
        "sub",
        "mult",
        "div",
        "addI",
        "subI",
        "rsubI",
        "multI",
        "divI",
        "rdivI",
        "lshift",
        "lshiftI",
        "rshift",
        "rshiftI",
        "and",
        "andI",
        "or",
        "orI",
        "xor",
        "xorI",
        "loadI",
        "load",
        "loadAI",
        "loadA0",
        "cload",
        "cloadAI",
        "cloadA0",
        "store",
        "storeAI",
        "storeAO",
        "cstore",
        "cstoreAI",
        "cstoreAO",
        "i2i",
        "c2c",
        "c2i",
        "i2c",
        // Controle de fluxo
        "jumpI",
        "jump",
        "cbr",
        "cmp_LT",
        "cmp_LE",
        "cmp_EQ",
        "cmp_GE",
        "cmp_GT",
        "cmp_NE"
};

bool is_in(reg_t key, std::vector<reg_t> vec) {
    if (std::find(vec.begin(), vec.end(), key) != vec.end())
        return true;
    return false;
}

std::string get_reg_name(reg_t r) {
    if (r == 1)
        return "bss";
    if (r == 2)
        return "fp";
    if (r == 3)
        return "sp";
    return std::to_string(r);
}

std::string Command::to_string() {
    // INST [r1|c] [r2|c] => <rd|L> [L]
    // rbss -> 1 | rfp -> 2 | rsp -> 3

    std::ostringstream oss;

    // Uso de Registradores/Constantes/Labels/xNulo em cada instrução
    std::vector<reg_t> xxxx {0};
    std::vector<reg_t> RRRx {1, 2, 3, 4, 11, 13, 15, 17, 19, 24, 27, 41, 42, 43, 44, 45, 46};
    std::vector<reg_t> RCRx {5, 6, 7, 8, 9, 10, 12, 14, 16, 18, 20, 23, 26};
    std::vector<reg_t> CxRx {21};
    std::vector<reg_t> RxRx {22, 25, 28, 31, 34, 35, 36, 37};
    std::vector<reg_t> RxRC {29, 32};
    std::vector<reg_t> RxRR {30, 33};
    std::vector<reg_t> xxLx {38};
    std::vector<reg_t> xxRx {39};
    std::vector<reg_t> RxLL {40};

    // Formando string de retorno
    if (is_in(this->instruct, xxxx))
        oss << "L" << this->label << ": ";
    oss << instruct_to_string[this->instruct];
    if (this->op1 >= 0) {
        if (is_in(this->instruct, RRRx))
            oss << " r" << get_reg_name(this->op1);
        if (is_in(this->instruct, RCRx))
            oss << " r" << get_reg_name(this->op1);
        if (is_in(this->instruct, CxRx))
            oss << " " << this->op1;
        if (is_in(this->instruct, RxRx))
            oss << " r" << get_reg_name(this->op1);
        if (is_in(this->instruct, RxRC))
            oss << " r" << get_reg_name(this->op1);
        if (is_in(this->instruct, RxRR))
            oss << " r" << get_reg_name(this->op1);
        if (is_in(this->instruct, RxLL))
            oss << " r" << get_reg_name(this->op1);
    }
    if (this->op2 >= 0) {

        if (is_in(this->instruct, RRRx))
            oss << ", r" << get_reg_name(this->op2);
        if (is_in(this->instruct, RCRx))
            oss << ", " << op2;
    }

    if (!is_in(this->instruct, xxxx))
        oss << " =>";

    if (is_in(this->instruct, RRRx))
        oss << " r" << get_reg_name(this->op3);
    if (is_in(this->instruct, RCRx))
        oss << " r" << get_reg_name(this->op3);
    if (is_in(this->instruct, CxRx))
        oss << " r" << get_reg_name(this->op3);
    if (is_in(this->instruct, RxRx))
        oss << " r" << get_reg_name(this->op3);
    if (is_in(this->instruct, RxRC))
        oss << " r" << get_reg_name(this->op3);
    if (is_in(this->instruct, RxRR))
        oss << " r" << get_reg_name(this->op3);
    if (is_in(this->instruct, xxLx))
        oss << " L" << op3;
    if (is_in(this->instruct, xxRx))
        oss << " r" << get_reg_name(this->op3);
    if (is_in(this->instruct, RxLL))
        oss << " L" << op3;

    if (this->op4 >= 0) {
        if (is_in(this->instruct, RxRC))
            oss << ", " << op4;
        if (is_in(this->instruct, RxRR))
            oss << ", r" << get_reg_name(this->op4);
        if (is_in(this->instruct, RxLL))
            oss << ", L" << op4;
    }

    oss << std::endl;
    std::cout << oss.str();

    return oss.str();
}

void CodeElement::copy_code(std::vector<ILOC_Code::Command> from) {
    for (auto& e : from) {
        this->code.push_back(e);
    }
}