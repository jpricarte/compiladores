#include "iloc.hh"
#include <string>
#include <iostream>

using namespace ILOC_Code;


Command::Command(Instruct instruct) {
    this->instruct = instruct;
    this->op1 = NO_REG;
    this->op2 = NO_REG;
    this->op3 = NO_REG;
}

Command::Command(Instruct instruct, reg_t op1, reg_t op2, reg_t op3, reg_t op4) {
    this->instruct = instruct;
    this->op1 = op1;
    this->op2 = op2;
    this->op3 = op3;
    this->op4 = op4;
}

std::string Command::to_string() {
    // INST [r1|c] [r2|c] => <rd|L> [L]
    // checar se é imediato ou registrador

    std::ostringstream oss;

    oss << instruct_to_string[this->instruct];
    if (this->op1) {oss << " " << this->op1;}
    if (this->op2) {oss << ", " << this->op2;}
    oss << " => ";
    oss << this->op3;
    if (this->op4) {oss << ", " << this->op4 << std::endl;}

    std::cout << oss.str();

    return oss.str();
}

void CodeElement::copy_code(std::vector<ILOC_Code::Command> from) {
    for (auto& e : from) {
        this->code.push_back(e);
    }
}