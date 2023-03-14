#include "iloc.hh"
#include <iostream>
#include <algorithm>

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

bool is_in(unsigned int key, std::vector<unsigned int> vec) {
    if (std::find(vec.begin(), vec.end(), key) != vec.end())
        return true;
    return false;
}

std::string Command::to_string() {
    // INST [r1|c] [r2|c] => <rd|L> [L]
    // checar se é imediato ou registrador

    std::ostringstream oss;

    std::vector<unsigned int> xxxx {0};
    std::vector<unsigned int> RRRx {1, 2, 3, 4, 11, 13, 15, 17, 19, 24, 27, 41, 42, 43, 44, 45, 46};
    std::vector<unsigned int> RCRx {5, 6, 7, 8, 9, 10, 12, 14, 16, 18, 20, 23, 26};
    std::vector<unsigned int> CxRx {21};
    std::vector<unsigned int> RxRx {22, 25, 28, 31, 34, 35, 36, 37};
    std::vector<unsigned int> RxRC {29, 32};
    std::vector<unsigned int> RxRR {30, 33};
    std::vector<unsigned int> xxLx {38};
    std::vector<unsigned int> xxRx {39};
    std::vector<unsigned int> RxLL {40};

    oss << instruct_to_string[this->instruct];
    if (this->op1) {
        if (is_in(this->instruct, RRRx))
            oss << " r" << this->op1;
        if (is_in(this->instruct, RCRx))
            oss << " r" << this->op1;
        if (is_in(this->instruct, CxRx))
            oss << " " << this->op1;
        if (is_in(this->instruct, RxRx))
            oss << " r" << this->op1;
        if (is_in(this->instruct, RxRC))
            oss << " r" << this->op1;
        if (is_in(this->instruct, RxRR))
            oss << " r" << this->op1;
        if (is_in(this->instruct, RxLL))
            oss << " r" << this->op1;
    }
    if (this->op2) {

        if (is_in(this->instruct, RRRx))
            oss << ", r" << this->op2;
        if (is_in(this->instruct, RCRx))
            oss << ", " << this->op2;
    }

    oss << " =>";

    if (is_in(this->instruct, RRRx))
        oss << " r" << this->op3;
    if (is_in(this->instruct, RCRx))
        oss << " r" << this->op3;
    if (is_in(this->instruct, CxRx))
        oss << " r" << this->op3;
    if (is_in(this->instruct, RxRx))
        oss << " r" << this->op3;
    if (is_in(this->instruct, RxRC))
        oss << " r" << this->op3;
    if (is_in(this->instruct, RxRR))
        oss << " r" << this->op3;
    if (is_in(this->instruct, xxLx))
        oss << " l" << this->op3;
    if (is_in(this->instruct, xxRx))
        oss << " r" << this->op3;
    if (is_in(this->instruct, RxLL))
        oss << " l" << this->op3;

    if (this->op4) {
        if (is_in(this->instruct, RxRC))
            oss << ", " << this->op4;
        if (is_in(this->instruct, RxRR))
            oss << ", r" << this->op4;
        if (is_in(this->instruct, RxLL))
            oss << ", l" << this->op4;
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