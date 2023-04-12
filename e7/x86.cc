#include "x86.hh"

/*
    .globl  a
        .bss
        .align 4
        .type   a, @object
        .size   a, 4
a:
        .zero   4
*/

static const char *instruct_to_string[] = {
        "nop",
        "add",
        "sub",
        "mult",
        "div",
        "add",
        "sub",
        "sub",
        "mult",
        "div",
        "div",
        "lshift",
        "lshift",
        "rshift",
        "rshift",
        "and",
        "and",
        "or",
        "or",
        "xor",
        "xor",
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


namespace x86 {

    std::string Command::to_string() {
        std::string result = instruction;
        if (!this->op1.empty()) {
            result += " " + this->op1;
        }
        if (!this->op2.empty()) {
            result += ", " + this->op2;
        }
        return result;
    }

    void CodeElement::copy_code(std::vector<Command> from) {
        for (auto& e : from) {
            this->code.push_back(e);
        }
    }

    Command define_global_int(const std::string& var_name) {
        std::string code{};
        code += "\t.globl " + var_name + "\n";
        code += "\t.align 4\n";
        code += "\t.type " + var_name + ", @object\n";
        code += "\t.size " + var_name + ", 4\n";
        code += var_name + ":\n";
        code += "\t .zero 4\n";
        return Command{ code, "", "", true };
    }

    Command iloc_to_x86(Control& x86_control, const ILOC_Code::Command& iloc_command, const std::string& op1, const std::string& op2) {
        std::string instruction{instruct_to_string[iloc_command.instruct]};
        return Command{ instruction, op1, op2, false };
    }

    /*
    enum Instruct {
		NOP,
        ADD,
        SUB,
        MULT,
        DIV,
        ADD_I,
        SUB_I,
        RSUB_I,
        MULT_I,
        DIV_I,
        RDIV_I,
        LSHIFT,
        LSHIFT_I,
        RSHIFT,
        RSHIFT_I,
        AND,
        AND_I,
        OR,
        OR_I,
        XOR,
        XOR_I,
        LOAD_I,
        LOAD,
        LOAD_AI,
        LOAD_A0,
        CLOAD,
        CLOAD_AI,
        CLOAD_A0,
        STORE,
        STORE_AI,
        STORE_AO,
        CSTORE,
        CSTORE_AI,
        CSTORE_AO,
        I2I,
        C2C,
        C2I,
        I2C,
        // Controle de fluxo
        JUMP_I,
        JUMP,
        CBR,
        CMP_LT,
        CMP_LE,
        CMP_EQ,
        CMP_GE,
        CMP_GT,
        CMP_NE
    */
}