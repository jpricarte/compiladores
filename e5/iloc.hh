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

namespace ILOC_Code {
    using reg_t = unsigned int;
    const ILOC_Code::reg_t NO_REG = 0;
    const ILOC_Code::reg_t RFP = 1;
    const ILOC_Code::reg_t RSP = 2;
    const ILOC_Code::reg_t RBSS = 3;
	static ILOC_Code::reg_t counter = 4;
	
	inline ILOC_Code::reg_t get_new_register() {
	    // Retorna o valor atual e atualiza
	    return counter++;
	}
    
	enum class Instruct {
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
	
	std::string to_string(ILOC_Code::Instruct i);

    struct Command {
        ILOC_Code::Instruct instruct;
        ILOC_Code::reg_t op1;
        ILOC_Code::reg_t op2;
        ILOC_Code::reg_t dest;
      
        // Inicia todos os operadores em 0
        Command(ILOC_Code::Instruct instruct);
        // Iniciar operador como 0 caso não utilize
        Command(ILOC_Code::Instruct instruct, ILOC_Code::reg_t op1, ILOC_Code::reg_t op2, ILOC_Code::reg_t dest);
        // vai fazer uma string como: INST [r1|c] [r2|c] => <rd|L> [L]
        std::string to_string();
    };

    using lab_t = unsigned int;
    const ILOC_Code::lab_t NO_LABEL = 0;
	static ILOC_Code::lab_t label_id = 1;
	
	inline ILOC_Code::lab_t get_new_label() {
	    // Retorna o valor atual e atualiza
	    return label_id++;
	}

    struct CodeElement {
        std::vector<ILOC_Code::Instruct> code;
        ILOC_Code::reg_t temporary;
        ILOC_Code::lab_t label_true;
        ILOC_Code::lab_t label_false;
    };
    
    /* Talvez colocar algo relacionado a memoria aqui, mas dessociei da aula nesse momento */
};

#endif // ILOC_HH