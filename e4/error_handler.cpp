#include "error_handler.hh"

void send_error_message (Node* node, int code) {
    int line_no = node->get_line_no();
    auto token_val = node->get_token_val();
    string token_type = token_type_to_string(node->get_token_type());

    switch (code) {
        case ERR_UNDECLARED:
           std::cout << "[ERRO linha " << line_no
                 << "] Variável " << token_val << " não foi declarada." << std::endl;
        case ERR_DECLARED:
            // NOTE: daria pra pegar o numero da linha da declaração anterior acessando a tabela de simbolos
           std::cout << "[ERRO linha " << line_no
                 << "] Variável " << token_val << " foi declarada na linha X e não pode ser redeclarada." <<std::endl;
        case ERR_VARIABLE:
           std::cout << "[ERRO linha " << line_no
                 << "] Uso indevido da variável " << token_val << "." <<std::endl;
        case ERR_ARRAY:
           std::cout << "[ERRO linha " << line_no
                 << "] Uso indevido do arranjo " << token_val << "." <<std::endl;
        case ERR_FUNCTION:
           std::cout << "[ERRO linha " << line_no
                 << "] Uso indevido da função " << token_val << "." <<std::endl;
        case ERR_CHAR_TO_INT:
           std::cout << "[ERRO linha " << line_no
                 << "] Conversão char >> int não suportada." <<std::endl;
        case ERR_CHAR_TO_FLOAT:
           std::cout << "[ERRO linha " << line_no
                 << "] Conversão char >> float não suportada." <<std::endl;
        case ERR_CHAR_TO_BOOL:
           std::cout << "[ERRO linha " << line_no
                 << "] Conversão char >> bool não suportada." <<std::endl;
        case ERR_CHAR_VECTOR:
           std::cout << "[ERRO linha " << line_no
                 << "] Vetores de char não são suportados." <<std::endl;
        case ERR_X_TO_CHAR:
           std::cout << "[ERRO linha " << line_no
                 << "] Conversão " << token_type << " >> char não suportada." << std::endl;
    }
}
