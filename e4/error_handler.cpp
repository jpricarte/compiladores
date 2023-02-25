#include "error_handler.hh"

void send_error_message (Node* node, int code) {

    cout << "[TESTE] " << endl << node.get_lex_val().token_type << endl << node.get_lex_val().token_val << endl;

    switch (code) {
        case ERR_UNDECLARED:
            cout << "[ERRO linha " << node->get_line_no()
                 << "] Variável VAR não foi declarada." << endl;
        case ERR_DECLARED:
            cout << "[ERRO linha " << node->get_line_no()
                 << "] Variável VAR foi declarada na linha X e não pode ser redeclarada." << endl;
        case ERR_VARIABLE:
            cout << "[ERRO linha " << node->get_line_no()
                 << "] Uso indevido da variável VAR." << endl;
        case ERR_ARRAY:
            cout << "[ERRO linha " << node->get_line_no()
                 << "] Uso indevido do arranjo ARR." << endl;
        case ERR_FUNCTION:
            cout << "[ERRO linha " << node->get_line_no()
                 << "] Uso indevido da função VAR." << endl;
        case ERR_CHAR_TO_INT:
            cout << "[ERRO linha " << node->get_line_no()
                 << "] Conversão char >> int não suportada." << endl;
        case ERR_CHAR_TO_FLOAT:
            cout << "[ERRO linha " << node->get_line_no()
                 << "] Conversão char >> float não suportada." << endl;
        case ERR_CHAR_TO_BOOL:
            cout << "[ERRO linha " << node->get_line_no()
                 << "] Conversão char >> bool não suportada." << endl;
        case ERR_CHAR_VECTOR:
            cout << "[ERRO linha " << node->get_line_no()
                 << "] Vetores de char não são suportados." << endl;
        case ERR_X_TO_CHAR:
            cout << "[ERRO linha " << node->get_line_no()
                 << "] Conversão " << node->get_lex_val.token_type << " >> char não suportada." << endl;
    }
}
