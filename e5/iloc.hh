/*
    Inicia o deslocamento global como 0;
    APÓS inserir um elemento na tabela de simbolos, soma ao deslocamento 
    o tamanho do item na tabela.
    O Nodo precisa ter um .code, que vai ser um vector<Command>
    e um .temp, que vai ser um reg_t indicando onde esse comando vai salvar o resultado
*/
#ifndef ILOC_HH
#define ILOC_HH

#include <string>
#include <vector>
#include <sstream>

namespace ILOC_Code {
    using reg_t = int;
    const ILOC_Code::reg_t NO_REG = 0;
    const ILOC_Code::reg_t RBSS = 1;
    const ILOC_Code::reg_t RFP = 2;
    const ILOC_Code::reg_t RSP = 3;
    const ILOC_Code::reg_t RPC = 4;
	static ILOC_Code::reg_t counter = 5;
	
	inline ILOC_Code::reg_t get_new_register() {
	    // Retorna o valor atual e atualiza
	    return counter++;
	}

    const ILOC_Code::reg_t RET_ADDR_DESLOC = -4;
    const ILOC_Code::reg_t RET_VALUE_DESLOC = -8;
    
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
	};

    using lab_t = int;
    const ILOC_Code::lab_t NO_LABEL = 0;
    static ILOC_Code::lab_t label_id = 1;

    inline ILOC_Code::lab_t get_new_label() {
        // Retorna o valor atual e atualiza
        return label_id++;
    }

    struct Command {
        // INST [r1|c] [r2|c] => <rd|L> [L]
        // inst  op1    op2       op3   op4
        ILOC_Code::lab_t label;
        ILOC_Code::Instruct instruct;
        ILOC_Code::reg_t op1;
        ILOC_Code::reg_t op2;
        ILOC_Code::reg_t op3;
        ILOC_Code::reg_t op4;

        // Inicia todos os operadores em 0
        Command(ILOC_Code::lab_t label, ILOC_Code::Instruct instruct);
        // Iniciar operador como 0 caso não utilize
        Command(ILOC_Code::Instruct instruct, ILOC_Code::reg_t op1, ILOC_Code::reg_t op2, ILOC_Code::reg_t op3, ILOC_Code::reg_t op4);
        // vai fazer uma string como: INST [r1|c] [r2|c] => <rd|L> [L]
        std::string to_string();
    };

    struct CodeElement {
        std::vector<ILOC_Code::Command> code;
        ILOC_Code::reg_t temporary;
        ILOC_Code::lab_t label_true;
        ILOC_Code::lab_t label_false;

        void copy_code(std::vector<ILOC_Code::Command> from);
    };
    
};

/* FORMATO DO REGISTRO DE ATIVAÇÃO

     ______________________
    |      valor_ret       |
    |       addr_ret       |
    |======================| -> Base da pilha (RFP)
    |        param0        |
    |        param1        |
    |          ...         |
    |        paramN        |
    |- - - - - - - - - - - |
    |         var0         |
    |         var1         |
    |          ...         |
    |         varN         |
    |- - - - - - - - - - - |
    |    vinc_estatico     |
    |    vinc_dinamico     |
    |     


*/

#endif // ILOC_HH