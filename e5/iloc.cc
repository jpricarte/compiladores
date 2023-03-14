#include "iloc.hh"

using namespace ILOC_Code;


Command::Command(Instruct instruct) {
    this->instruct = instruct;
    this->op1 = NO_REG;
    this->op2 = NO_REG;
    this->dest = NO_REG;
}

Command::Command(Instruct instruct, reg_t op1, reg_t op2, reg_t dest) {
    this->instruct = instruct;
    this->op1 = op1;
    this->op2 = op2;
    this->dest = dest;
}
