#include "error_handler.hh"

void send_error_message (Node* node, int code) {

//    std::cout << "[TESTE] " << std::endl << node->get_lex_val().token_type << std::endl << node->get_lex_val().token_val << std::endl;

    switch (code) {
        case ERR_UNDECLARED:
           std::cout << "[ERRO linha " << node->get_line_no()
                 << "] Variável VAR não foi declarada." << std::endl;
        case ERR_DECLARED:
           std::cout << "[ERRO linha " << node->get_line_no()
                 << "] Variável VAR foi declarada na linha X e não pode ser redeclarada." <<std::endl;
        case ERR_VARIABLE:
           std::cout << "[ERRO linha " << node->get_line_no()
                 << "] Uso indevido da variável VAR." <<std::endl;
        case ERR_ARRAY:
           std::cout << "[ERRO linha " << node->get_line_no()
                 << "] Uso indevido do arranjo ARR." <<std::endl;
        case ERR_FUNCTION:
           std::cout << "[ERRO linha " << node->get_line_no()
                 << "] Uso indevido da função VAR." <<std::endl;
        case ERR_CHAR_TO_INT:
           std::cout << "[ERRO linha " << node->get_line_no()
                 << "] Conversão char >> int não suportada." <<std::endl;
        case ERR_CHAR_TO_FLOAT:
           std::cout << "[ERRO linha " << node->get_line_no()
                 << "] Conversão char >> float não suportada." <<std::endl;
        case ERR_CHAR_TO_BOOL:
           std::cout << "[ERRO linha " << node->get_line_no()
                 << "] Conversão char >> bool não suportada." <<std::endl;
        case ERR_CHAR_VECTOR:
           std::cout << "[ERRO linha " << node->get_line_no()
                 << "] Vetores de char não são suportados." <<std::endl;
        case ERR_X_TO_CHAR:
           std::cout << "[ERRO linha " << node->get_line_no()
                 << "] Conversão TIPO_TOKEN >> char não suportada." << std::endl;
    }
}
