%{
#include <iostream>
#include <memory>
#include <map>
#include "table.hh"
#include "iloc.hh"
#include "x86.hh"
#include "fcg.hh"


extern int get_line_number();
extern void* arvore;

void send_error_message (Node* node, int code);
int yylex(void);
void yyerror (const char *msg);

SymbolTableStack symbol_table_stack{};
TokenVal main_token_val;
ILOC_Code::lab_t main_label = 99;
std::vector<std::vector<ILOC_Code::reg_t>> param_regs {};
std::map<TokenVal, ILOC_Code::lab_t> label_memory {};

std::vector<std::pair<TokenVal, Symbol>> var_global_list = {};
int array_size=0;
x86::Control x86_control{};
%}

%require "3.0.4"

%code requires {
    #include <memory>
    #include "table.hh"
    #include "iloc.hh"
    using namespace ILOC_Code;
}

%union {
    Node* valor_lexico;
}


%define parse.error verbose

%token<valor_lexico> TK_PR_INT
%token<valor_lexico> TK_PR_FLOAT
%token<valor_lexico> TK_PR_BOOL
%token<valor_lexico> TK_PR_CHAR
%token<valor_lexico> TK_PR_IF
%token<valor_lexico> TK_PR_THEN
%token<valor_lexico> TK_PR_ELSE
%token<valor_lexico> TK_PR_WHILE
%token<valor_lexico> TK_PR_INPUT
%token<valor_lexico> TK_PR_OUTPUT
%token<valor_lexico> TK_PR_RETURN
%token<valor_lexico> TK_PR_FOR
%token<valor_lexico> TK_OC_LE
%token<valor_lexico> TK_OC_GE
%token<valor_lexico> TK_OC_EQ
%token<valor_lexico> TK_OC_NE
%token<valor_lexico> TK_OC_AND
%token<valor_lexico> TK_OC_OR
%token<valor_lexico> TK_LIT_INT
%token<valor_lexico> TK_LIT_FLOAT
%token<valor_lexico> TK_LIT_FALSE
%token<valor_lexico> TK_LIT_TRUE
%token<valor_lexico> TK_LIT_CHAR
%token<valor_lexico> TK_IDENTIFICADOR
%token<valor_lexico> TK_ERRO
%token<valor_lexico> '!' '-' '*' '/' '%' '+' '<' '>' '=' '^'

%type<valor_lexico> programa
%type<valor_lexico> lista_elem
%type<valor_lexico> elemento
%type<valor_lexico> var_global
%type<valor_lexico> lista_id_var_global
%type<valor_lexico> id_var_global
%type<valor_lexico> lista_dimensoes
%type<valor_lexico> funcao
%type<valor_lexico> lista_parametros
%type<valor_lexico> parametro
%type<valor_lexico> corpo_funcao
%type<valor_lexico> bloco_comandos
%type<valor_lexico> lista_comandos
%type<valor_lexico> comando_simples
%type<valor_lexico> var_local
%type<valor_lexico> lista_var_local_int
%type<valor_lexico> var_local_int
%type<valor_lexico> lista_var_local_float
%type<valor_lexico> var_local_float
%type<valor_lexico> lista_var_local_bool
%type<valor_lexico> var_local_bool
%type<valor_lexico> lista_var_local_char
%type<valor_lexico> var_local_char
%type<valor_lexico> atribuicao
%type<valor_lexico> identificador
%type<valor_lexico> lista_indices
%type<valor_lexico> cham_funcao
%type<valor_lexico> lista_argumentos
%type<valor_lexico> op_retorno
%type<valor_lexico> con_fluxo
%type<valor_lexico> expressao_1
%type<valor_lexico> expressao_2
%type<valor_lexico> expressao_3
%type<valor_lexico> expressao_4
%type<valor_lexico> expressao_5
%type<valor_lexico> expressao_6
%type<valor_lexico> expressao_7
%type<valor_lexico> operando
%type<valor_lexico> literal
%type<valor_lexico> tipo_primitivo

%start programa

%%

programa: { symbol_table_stack.push_new(); } lista_elem {
            $$ = $2;
            auto main_symbol_table = symbol_table_stack.recover_symbol_table(main_token_val);
            std::vector<Command> code = create_call_commands(main_label, main_symbol_table, {});
            code.insert(code.begin(), Command{Instruct::ADD_I, RSP, 4, RSP, NO_REG});
            code.insert(code.begin(), Command{Instruct::I2I, RFP, NO_REG, RSP, NO_REG});
            lab_t end = get_new_label();
            code.push_back(Command{Instruct::JUMP_I, NO_REG, NO_REG, end, NO_REG});
            for (auto command : $2->iloc_code_element.code) {
                code.push_back(command);
            }
            // TODO: DAR PUSH BACK DUM HALT=
            code.push_back(Command{end, Instruct::NOP});
            $2->iloc_code_element.code = code;
            arvore = $$;
            symbol_table_stack.pop();
	    FCG fcg;
	    fcg.fromILOC($$->iloc_code_element.code);

        };

lista_elem: %empty { $$ = nullptr; }
          | elemento lista_elem {
                if ($$ != nullptr ) {
                    $$ = $1; 
                    $$->add_child($2);
                    if ($2 != nullptr)
                        $$->iloc_code_element.copy_code($2->iloc_code_element.code);
                } else {
                    $$ = $2;
                }
            };

elemento: var_global {$$ = $1; var_global_list.clear();}
        | funcao {$$ = $1;};

/* Definição de variáveis globais dos tipos primitivos */
var_global: tipo_primitivo lista_id_var_global ';' { $$ = nullptr; 
                                                     // adiciona todas as variaveis de uma vez na tabela
                                                     for (auto pair : var_global_list) {
                                                        Symbol& s = pair.second;
                                                        s.type = $1->get_node_type();
                                                        if (s.type == Type::CHARACTER && s.kind == Kind::ARRAY) {
                                                            send_error_message($1, ERR_CHAR_VECTOR);
                                                            exit(ERR_CHAR_VECTOR);
                                                        }
                                                        s.size *= get_size_from_type($1->get_node_type());
                                                        symbol_table_stack.emplace_top(pair);
                                                     }
                                                     delete $1;
                                                   };

lista_id_var_global: id_var_global {$$ = nullptr;}
                   | lista_id_var_global ',' id_var_global {$$ = nullptr;};

id_var_global: TK_IDENTIFICADOR {   if (symbol_table_stack.is_declared($1->get_token_val())) {
					                    send_error_message($1, ERR_DECLARED);
                                        exit(ERR_DECLARED);
                                    }
                                        Symbol s{
                                        $1->get_line_no(),
                                        Kind::VARIABLE,
                                        Type::TYPE_ERROR,
                                        1,
                                        nullptr,
                                        0
                                    };
                                    var_global_list.push_back(std::make_pair($1->get_token_val(), s));
                                    // TODO: remover log de debug
                                    x86::define_global_int(get<std::string>($1->get_token_val()));
                                    $$=nullptr; delete $1;
                                }
             | TK_IDENTIFICADOR '[' lista_dimensoes ']' { 
                                                          if (symbol_table_stack.is_declared($1->get_token_val())) {
                                                              send_error_message($1, ERR_DECLARED);
                                                              exit(ERR_DECLARED);
                                                          }
                                                          Symbol s{
                                                              $1->get_line_no(),
                                                              Kind::ARRAY,
                                                              Type::TYPE_ERROR,
                                                              (size_t) array_size,
                                                              nullptr,
                                                              0
                                                          };
                                                          var_global_list.push_back(std::make_pair($1->get_token_val(), s));
                                                          array_size = 0;
                                                          $$=nullptr; delete $1;
                                                        };

lista_dimensoes: TK_LIT_INT { array_size = get<int>($1->get_token_val()); 
                              $$=nullptr; delete $1;
                            }
               | lista_dimensoes '^' TK_LIT_INT { array_size *= get<int>($3->get_token_val()); 
                                                  $$=nullptr; delete $2; delete $3;
                                                };

/* Definição de funções */

funcao: tipo_primitivo TK_IDENTIFICADOR { 
                if (symbol_table_stack.is_declared($2->get_token_val())) {
                    send_error_message($2, ERR_DECLARED);
                    exit(ERR_DECLARED);
                }
                Symbol s{
                    $2->get_line_no(), 
                    Kind::FUNCTION, 
                    $1->get_node_type(), 
                    get_size_from_type($1->get_node_type()), 
                    $2,
                    0
                };
                symbol_table_stack.insert_top($2->get_token_val(), s);
                symbol_table_stack.push_new();
            } 
        '(' lista_parametros
        ')' corpo_funcao { 
                $$ = $2; 
                $$->add_child($7);
                lab_t func_label = get_new_label();
                if (get<std::string>($$->get_token_val()) == "main") {
                    main_label = func_label;
                    main_token_val = $$->get_token_val();
                }
                label_memory.insert({$$->get_token_val(), func_label});

                $$->iloc_code_element.code.push_back(Command{func_label, Instruct::NOP});
                auto temp = get_new_register();
                auto n_val = get_new_register();
                $$->iloc_code_element.code.push_back(Command{Instruct::I2I, RFP, NO_REG, temp, NO_REG});
                $$->iloc_code_element.code.push_back(Command{Instruct::SUB_I, temp, 4, temp, NO_REG});
                $$->iloc_code_element.code.push_back(Command{Instruct::LOAD, temp, NO_REG, n_val, NO_REG});
                $$->iloc_code_element.code.push_back(Command{Instruct::ADD_I, n_val, 2, n_val, NO_REG});
                $$->iloc_code_element.code.push_back(Command{Instruct::STORE, n_val, NO_REG, temp, NO_REG});

/*
// TODO: chamada de função
	        $$->x86_code_element = x86::CodeElement{};
	    	$$->x86_code_element.code.push_back(x86::Command("add", x86_control.reg_as_atnt(op1), x86_control.reg_as_atnt(op2), false));

	        .globl	testingaaaa
                	.type	testingaaaa, @function
                testingaaaa:
	    auto op1 = $1->x86_code_element.temp_reg_id;
	    auto op2 = $3->x86_code_element.temp_reg_id;
	    $$->x86_code_element.temp_reg_id = op2;
	    x86_control.free_reg(op1);
*/

                if ($7 != nullptr) {
                    $$->iloc_code_element.copy_code($7->iloc_code_element.code);
                }

                $$->iloc_code_element.copy_code(create_return_commands());
                
                symbol_table_stack.pop($2->get_token_val());
                delete $1;
            };

lista_parametros: %empty {$$ = nullptr;}
                | parametro {$$ = nullptr;}
                | lista_parametros ',' parametro {$$ = nullptr;};

parametro: tipo_primitivo TK_IDENTIFICADOR  { 
                    $$=nullptr;
                    Symbol s {
                        $2->get_line_no(),
                        Kind::VARIABLE,
                        $1->get_node_type(),
                        get_size_from_type($1->get_node_type()),
                        nullptr,
                        0
                    };
                    symbol_table_stack.insert_top($2->get_token_val(), s);
                    delete $1;
                    delete $2;
                };

corpo_funcao: '{' lista_comandos '}' {$$ = $2;};


lista_comandos: %empty {$$ = nullptr;}
              | comando_simples ';' lista_comandos {
                        if ($1 != nullptr) {
                            $$ = $1; 
                            $$->add_child($3);
                            if ($3 != nullptr) {
                                $$->iloc_code_element.copy_code($3->iloc_code_element.code);
                            }
                        } else {
                            $$ = $3;
                        }
                    };

comando_simples: var_local {$$ = $1;}
               | atribuicao {$$ = $1;}
               | con_fluxo {$$ = $1;}
               | op_retorno {$$ = $1;}
               | cham_funcao {$$ = $1;}
               | bloco_comandos {$$ = $1;};

/* Bloco de comandos */
bloco_comandos: {symbol_table_stack.push_new();} '{' lista_comandos '}' {$$ = $3; symbol_table_stack.pop();};

/* Definição de variável local, permitindo apenas literais do tipo correspondente */
// TODO: fazer a conversão do valor quando mudar o tipo;
// TODO: Arrumar questões de conversão nas operações;
var_local: TK_PR_INT lista_var_local_int {$$ = $2;}
         | TK_PR_FLOAT lista_var_local_float {$$ = $2;}
         | TK_PR_BOOL lista_var_local_bool {$$ = $2;}
         | TK_PR_CHAR lista_var_local_char {$$ = $2;};


/* inteiro */
lista_var_local_int: %empty {$$ = nullptr;}
                   | var_local_int lista_var_local_int {
                        if ($1 != nullptr) {
                            $$ = $1; 
                            $$->add_child($2);
                        } else {
                            $$ = $2;
                        }
                    };
                   | var_local_int ',' lista_var_local_int 
                   {
                        if ($1 != nullptr) {
                            $$ = $1; 
                            $$->add_child($3);
                            $$->iloc_code_element.code = $1->iloc_code_element.code;
                            $$->iloc_code_element.copy_code($3->iloc_code_element.code);
                        } else {
                            $$ = $3;
                        }
                    };

var_local_int: TK_IDENTIFICADOR { $$ = nullptr;
                                    if (symbol_table_stack.is_declared($1->get_token_val())) {
                                        send_error_message($1, ERR_DECLARED);
                                        delete $1;
                                        exit(ERR_DECLARED);
                                    }
                                    /*Insere na tabela de simbolos e apaga nodo*/;
                                    Symbol s{
                                                $1->get_line_no(), 
                                                Kind::VARIABLE, 
                                                Type::INTEGER, 
                                                get_size_from_type(Type::INTEGER), 
                                                nullptr,
                                                0
                                            };
                                    symbol_table_stack.insert_top($1->get_token_val(), s);
                                    delete $1;
                                  }
             | TK_IDENTIFICADOR { 
                    if (symbol_table_stack.is_declared($1->get_token_val())) {
				        send_error_message($1, ERR_DECLARED);
                        delete $1;
                        exit(ERR_DECLARED);
                    }
                } TK_OC_LE expressao_7 { 
                    $$ = $3; 
                    $$->add_child($1); 
                    $$->add_child($4);
                    $1->set_node_type(Type::INTEGER);
                    int exit_code = get_char_err($1->get_node_type(), $4->get_node_type());
                    if (exit_code > 0) 
                        exit(exit_code);
                    Symbol symbol{
                        $1->get_line_no(), 
                        Kind::VARIABLE, 
                        Type::INTEGER, 
                        get_size_from_type(Type::INTEGER), 
                        $3,
                        0
                    };
                    symbol_table_stack.insert_top($1->get_token_val(), symbol);
                    $$->set_node_type(Type::INTEGER);

                    // código de atribuição
                    $$->iloc_code_element.copy_code($4->iloc_code_element.code);
                    Symbol s = symbol_table_stack.get_first_symbol($1->get_token_val());
                    auto dest = get_new_register();
                    auto value = $4->iloc_code_element.temporary;
                    // pega endereço de memória da variavel
                    $$->iloc_code_element.code.push_back(Command(Instruct::ADD_I, ILOC_Code::RFP, s.desloc, dest, NO_REG));
                    // salva valor nesse endereço de memória
                    $$->iloc_code_element.code.push_back(Command(Instruct::STORE, value, NO_REG, dest, NO_REG));
                };

/* ponto flutuante */
lista_var_local_float: %empty {$$ = nullptr;}
                     | var_local_float lista_var_local_float
                     {
                        if ($1 != nullptr) {
                            $$ = $1; 
                            $$->add_child($2);
                        } else {
                            $$ = $2;
                        }
                    };
                     | var_local_float ',' lista_var_local_float
                     {
                        if ($1 != nullptr) {
                            $$ = $1; 
                            $$->add_child($3);
                        } else {
                            $$ = $3;
                        }
                    };

var_local_float: TK_IDENTIFICADOR { $$ = nullptr;
                                    if (symbol_table_stack.is_declared($1->get_token_val())) {
                                    	send_error_message($1, ERR_DECLARED);
                                        delete $1;
                                        exit(ERR_DECLARED);
                                    }
                                    /*Insere na tabela de simbolos e apaga nodo*/;
                                    Symbol s{
                                                $1->get_line_no(), 
                                                Kind::VARIABLE, 
                                                Type::FLOATING, 
                                                get_size_from_type(Type::FLOATING), 
                                                nullptr,
                                                0
                                            };
                                    symbol_table_stack.insert_top($1->get_token_val(), s);
                                    delete $1;
                                  }
               | TK_IDENTIFICADOR { if (symbol_table_stack.is_declared($1->get_token_val())) {
               				send_error_message($1, ERR_DECLARED);
                                        delete $1;
                                        exit(ERR_DECLARED);
                                    }} TK_OC_LE expressao_7 { $$ = $3; $$->add_child($1); $$->add_child($4);
                                                            // Verifica erro de conversão
                                                            $1->set_node_type(Type::FLOATING);
                                                            int exit_code = get_char_err($1->get_node_type(), $4->get_node_type());
                                                            if (exit_code > 0) exit(exit_code);
                                                            Symbol s{
                                                                $1->get_line_no(), 
                                                                Kind::VARIABLE, 
                                                                Type::FLOATING, 
                                                                get_size_from_type(Type::FLOATING), 
                                                                $3,
                                                                0
                                                            };
                                                            symbol_table_stack.insert_top($1->get_token_val(), s);
                                                            $$->set_node_type(Type::FLOATING);
                                                          };

/* booleano */
lista_var_local_bool: %empty {$$ = nullptr;}
                    | var_local_bool lista_var_local_bool
                    {
                        if ($1 != nullptr) {
                            $$ = $1; 
                            $$->add_child($2);
                        } else {
                            $$ = $2;
                        }
                    };
                    | var_local_bool ',' lista_var_local_bool
                    {
                        if ($1 != nullptr) {
                            $$ = $1; 
                            $$->add_child($3);
                        } else {
                            $$ = $3;
                        }
                    };

var_local_bool: TK_IDENTIFICADOR { $$ = nullptr; 
                                   if (symbol_table_stack.is_declared($1->get_token_val())) {
                                   	send_error_message($1, ERR_DECLARED);
                                        delete $1;
                                        exit(ERR_DECLARED);
                                   }
                                   /*Insere na tabela de simbolos e apaga nodo*/;
                                   Symbol s{
                                            $1->get_line_no(), 
                                            Kind::VARIABLE, 
                                            Type::BOOLEAN, 
                                            get_size_from_type(Type::BOOLEAN), 
                                            nullptr,
                                            0
                                        };
                                   symbol_table_stack.insert_top($1->get_token_val(), s);
                                   delete $1;
                                }
              | TK_IDENTIFICADOR { if (symbol_table_stack.is_declared($1->get_token_val())) {
              			    send_error_message($1, ERR_DECLARED);
                                    delete $1;
                                    exit(ERR_DECLARED);
                                }} TK_OC_LE expressao_7 { $$ = $3; $$->add_child($1); $$->add_child($4);
                                                          // Verifica erro de conversão
                                                          $1->set_node_type(Type::BOOLEAN);
                                                          int exit_code = get_char_err($1->get_node_type(), $4->get_node_type());
                                                          if (exit_code > 0) exit(exit_code);
                                                          Symbol s{
                                                              $1->get_line_no(), 
                                                              Kind::VARIABLE, 
                                                              Type::BOOLEAN, 
                                                              get_size_from_type(Type::BOOLEAN), 
                                                              $3,
                                                              0
                                                          };
                                                          symbol_table_stack.insert_top($1->get_token_val(), s);
                                                          $$->set_node_type(Type::BOOLEAN);
                                                      };

/* caracter */
lista_var_local_char: %empty {$$ = nullptr;}
                    | var_local_char lista_var_local_char
                    {
                        if ($1 != nullptr) {
                            $$ = $1; 
                            $$->add_child($2);
                        } else {
                            $$ = $2;
                        }
                    };
                    | var_local_char ',' lista_var_local_char
                    {
                        if ($1 != nullptr) {
                            $$ = $1; 
                            $$->add_child($3);
                        } else {
                            $$ = $3;
                        }
                    };
var_local_char: TK_IDENTIFICADOR {  if (symbol_table_stack.is_declared($1->get_token_val())) {
					send_error_message($1, ERR_DECLARED);
                                        delete $1;
                                        exit(ERR_DECLARED);
                                    }
                                    $$ = nullptr; 
                                    /*Insere na tabela de simbolos e apaga nodo*/;
                                    Symbol s{
                                            $1->get_line_no(), 
                                            Kind::VARIABLE, 
                                            Type::CHARACTER, 
                                            get_size_from_type(Type::CHARACTER), 
                                            nullptr,
                                            0
                                        };
                                    symbol_table_stack.insert_top($1->get_token_val(), s);
                                    delete $1;
                                 }
              | TK_IDENTIFICADOR {
                if (symbol_table_stack.is_declared($1->get_token_val())) {
                    send_error_message($1, ERR_DECLARED);
                    delete $1;
                    exit(ERR_DECLARED);
                }} TK_OC_LE expressao_7 { $$ = $3; $$->add_child($1); $$->add_child($4);
                                        // Verifica erro de conversão
                                        $1->set_node_type(Type::CHARACTER);
                                        int exit_code = get_char_err($1->get_node_type(), $4->get_node_type());
                                        if (exit_code > 0) exit(exit_code);
                                        Symbol s{
                                            $1->get_line_no(), 
                                            Kind::VARIABLE, 
                                            Type::CHARACTER, 
                                            get_size_from_type(Type::CHARACTER), 
                                            $3,
                                            0
                                        };
                                        symbol_table_stack.insert_top($1->get_token_val(), s);
              					        $$->set_node_type(Type::CHARACTER);
                                    };

/* Comando de Atribuição */
atribuicao: identificador '=' expressao_7 { 
                            $$ = $2; $$->add_child($1); $$->add_child($3); 
                            // verifica tipos
                            int exit_code = get_char_err($1->get_node_type(), $3->get_node_type());
                            if (exit_code > 0) {
					            send_error_message($3, exit_code);
					            exit(exit_code);
                            }
                            $$->set_node_type($1->get_node_type());

                            auto dest = $1->iloc_code_element.temporary;
                            auto value = $3->iloc_code_element.temporary;
                            $$->iloc_code_element.code = $1->iloc_code_element.code;
                            $$->iloc_code_element.copy_code($3->iloc_code_element.code);
                            $$->iloc_code_element.code.push_back(Command{Instruct::STORE, value, NO_REG, dest, NO_REG});
                        };

identificador: TK_IDENTIFICADOR { 
                                    if (symbol_table_stack.is_not_declared($1->get_token_val())) {
                                        send_error_message($1, ERR_UNDECLARED);
                                        exit(ERR_UNDECLARED);
                                    }
                                    $$ = $1; // Tem que ser var, se não é erro
                                    auto s = symbol_table_stack.get_first_symbol($1->get_token_val());
                                    int exit_code = get_bad_usage_err(s.kind, Kind::VARIABLE);
                                    if (exit_code > 0) {
                                        send_error_message($1, exit_code);
                                        exit(exit_code);
                                    }
                                    $$->set_node_type(s.type);

                                    $$->iloc_code_element = ILOC_Code::CodeElement{};
                                    $$->iloc_code_element.temporary = get_new_register();
                                    // Retorna 0 caso global, outro caso local
                                    auto table_id = symbol_table_stack.find_symbol_table($1->get_token_val());
                                    if (table_id == 0) {
                                        $$->iloc_code_element.code.push_back(Command(Instruct::ADD_I, ILOC_Code::RBSS, s.desloc, $$->iloc_code_element.temporary, NO_REG));
                                    } else {
                                        $$->iloc_code_element.code.push_back(Command(Instruct::ADD_I, ILOC_Code::RFP, s.desloc, $$->iloc_code_element.temporary, NO_REG));
                                    }
                                } 
             | TK_IDENTIFICADOR '[' lista_indices ']' { // Tem que ser Arranjo, se não é erro
                if (symbol_table_stack.is_not_declared($1->get_token_val())) {
                    send_error_message($1, ERR_UNDECLARED);
                    exit(ERR_UNDECLARED);
                }
                auto s = symbol_table_stack.get_first_symbol($1->get_token_val());
                int exit_code = get_bad_usage_err(s.kind, Kind::ARRAY);
                if (exit_code > 0) {
                    send_error_message($1, exit_code);
                    exit(exit_code);
                }
                $$ = new Node($1->get_line_no(), TokenType::COMPOSED_OPERATOR, TokenVal("[]"));
                $$->add_child($1);
                $$->add_child($3);
                $$->set_node_type(s.type);
             };

lista_indices: expressao_7 {$$ = $1;}
             | lista_indices '^' expressao_7 {$$ = $2; $$->add_child($3); $$->add_child($1);};

/* Chamada de função */
cham_funcao: TK_IDENTIFICADOR { // Tem que ser função, se não é erro
                    if (symbol_table_stack.is_not_declared($1->get_token_val())) {
                        send_error_message($1, ERR_UNDECLARED);
                        exit(ERR_UNDECLARED);
                    }
                    auto s = symbol_table_stack.get_first_symbol($1->get_token_val());
                    int exit_code = get_bad_usage_err(s.kind, Kind::FUNCTION);
                    if (exit_code > 0) {
                        send_error_message($1, exit_code);
                        exit(exit_code);
                    }
                    param_regs.push_back({});
                }
			 '(' lista_argumentos ')' {
                    // carrega tabela de simbolos da função
                    auto func_symbol_table = symbol_table_stack.recover_symbol_table($1->get_token_val());
                    auto func_label = label_memory[$1->get_token_val()];
                    $$ = $1; 
                    $$->set_is_func_call(true); 
                    $$->add_child($4);
                    if ($4 != nullptr) {
                        $$->iloc_code_element.code = $4->iloc_code_element.code;
                    }
                    $$->iloc_code_element.copy_code(create_call_commands(func_label, func_symbol_table, param_regs.back()));
                    param_regs.pop_back();
                };

// Código retornado carrega 
lista_argumentos: %empty {$$ = nullptr;}
                | expressao_7 { $$ = $1; param_regs.back().push_back($1->iloc_code_element.temporary);}
                | expressao_7 ',' lista_argumentos {
                        param_regs.back().push_back($1->iloc_code_element.temporary);
                        $$ = $1;
                        $$->add_child($3);
                        if ($3 != nullptr) {
                            $$->iloc_code_element.copy_code($3->iloc_code_element.code);
                        }
                    };

/* Comando de retorno */
op_retorno: TK_PR_RETURN expressao_7 { 
                $$ = $1; 
                $$->add_child($2);
                $$->set_node_type($2->get_node_type());
                $$->iloc_code_element.code = $2->iloc_code_element.code;
                auto temp = get_new_register();
                $$->iloc_code_element.copy_code({
                    Command{Instruct::I2I, RFP, NO_REG, temp, NO_REG}, // i2i do rfp para o novo reg
                    Command{Instruct::SUB_I, temp, 8, temp, NO_REG}, // subtrai 8 do novo reg, apontando para o valor de retorno
                    Command{Instruct::STORE, $2->iloc_code_element.temporary, NO_REG, temp, NO_REG}, // salva o que estiver em $2->iloc_code_element.temporary no endereço do novo reg
                });
                // adiciona o resto do código de retorno
                $$->iloc_code_element.copy_code(create_return_commands());
                $$->iloc_code_element.temporary = temp;

                for (auto c : $$->x86_code_element.code) {
                    std::cout << c.to_string() << std::endl;
                }
            };

/* Controle de fluxo */
con_fluxo: TK_PR_IF '(' expressao_7 ')' TK_PR_THEN bloco_comandos {$$ = $1; $$->add_child($3); $$->add_child($6);
								   $$->set_node_type($3->get_node_type());
								   if ($3->get_node_type() == Type::CHARACTER) {
								   	send_error_message($3, ERR_CHAR_TO_BOOL);
								   	exit(ERR_CHAR_TO_BOOL);
								   }

								   ILOC_Code::CodeElement code_elem = ILOC_Code::CodeElement{};
								    code_elem.label_true = get_new_label();
								    code_elem.label_false = get_new_label();
								    code_elem.copy_code($3->iloc_code_element.code);
								    code_elem.code.push_back(Command(Instruct::CBR, $3->iloc_code_element.temporary, NO_REG, code_elem.label_true, code_elem.label_false));
								    code_elem.code.push_back(Command(code_elem.label_true, Instruct::NOP));
								    code_elem.copy_code($6->iloc_code_element.code);
								    code_elem.code.push_back(Command(code_elem.label_false, Instruct::NOP));
								    $$->iloc_code_element = code_elem;
								    }
         | TK_PR_IF '(' expressao_7 ')' TK_PR_THEN bloco_comandos TK_PR_ELSE bloco_comandos 
         {
            $$ = $1;
            $$->add_child($3);
            $$->add_child($6);
            $$->add_child($8);
            $$->set_node_type($3->get_node_type());
            if ($3->get_node_type() == Type::CHARACTER) {
            	send_error_message($3, ERR_CHAR_TO_BOOL);
            	exit(ERR_CHAR_TO_BOOL);
            }

	    ILOC_Code::CodeElement code_elem = ILOC_Code::CodeElement{};
	    code_elem.label_true = get_new_label();
	    code_elem.label_false = get_new_label();
	    code_elem.copy_code($3->iloc_code_element.code);
	    code_elem.code.push_back(Command(Instruct::CBR, $3->iloc_code_element.temporary, NO_REG, code_elem.label_true, code_elem.label_false));
	    code_elem.code.push_back(Command(code_elem.label_true, Instruct::NOP));
	    code_elem.copy_code($6->iloc_code_element.code);
	    code_elem.code.push_back(Command(code_elem.label_false, Instruct::NOP));
	    code_elem.copy_code($8->iloc_code_element.code);
	    $$->iloc_code_element = code_elem;

         }
         | TK_PR_WHILE '(' expressao_7 ')' bloco_comandos {
                        $$ = $1; $$->add_child($3); $$->add_child($5);
                        $$->set_node_type($3->get_node_type());
                        if ($3->get_node_type() == Type::CHARACTER) {
                            send_error_message($3, ERR_CHAR_TO_BOOL);
                            exit(ERR_CHAR_TO_BOOL);
                        }

                        ILOC_Code::CodeElement code_elem = ILOC_Code::CodeElement{};
                        lab_t label_begin = get_new_label();
                        code_elem.label_true = get_new_label();
                        code_elem.label_false = get_new_label();
                        code_elem.code.push_back(Command(label_begin, Instruct::NOP));
                        code_elem.copy_code($3->iloc_code_element.code);
                        code_elem.code.push_back(Command(Instruct::CBR, $3->iloc_code_element.temporary, NO_REG, code_elem.label_true, code_elem.label_false));
                        code_elem.code.push_back(Command(code_elem.label_true, Instruct::NOP));
                        code_elem.copy_code($5->iloc_code_element.code);
                        code_elem.code.push_back(Command(Instruct::JUMP_I, NO_REG, NO_REG, label_begin, NO_REG));
                        code_elem.code.push_back(Command(code_elem.label_false, Instruct::NOP));
                        $$->iloc_code_element = code_elem;
                    };

/* Expressão (nivel de precendencia indicado no nome da regra) */
// TODO: Inserir casos base das expressões
expressao_7: expressao_6 { $$ = $1; }
           | expressao_7 TK_OC_OR expressao_6 { $$ = $2; $$->add_child($1); $$->add_child($3);
           					$$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
           					if ($1->get_node_type() == Type::CHARACTER) {
           						send_error_message($3, ERR_CHAR_TO_BOOL);
							    exit(ERR_CHAR_TO_BOOL);
           					} else if ($3->get_node_type() == Type::CHARACTER) {
           						send_error_message($3, ERR_CHAR_TO_BOOL);
							    exit(ERR_CHAR_TO_BOOL);
                            }
                            $$->iloc_code_element = ILOC_Code::CodeElement{};
                            $$->iloc_code_element.code = $1->iloc_code_element.code;
                            $$->iloc_code_element.copy_code($3->iloc_code_element.code);
                            $$->iloc_code_element.temporary = get_new_register();
                            $$->iloc_code_element.code.push_back(Command(Instruct::OR, $1->iloc_code_element.temporary, $3->iloc_code_element.temporary, $$->iloc_code_element.temporary, NO_REG));

			    $$->x86_code_element = x86::CodeElement{};
		    	    $$->x86_code_element.code = $1->x86_code_element.code;
		      	    $$->x86_code_element.copy_code($3->x86_code_element.code);
			    auto op1 = $1->x86_code_element.temp_reg_id;
			    auto op2 = $3->x86_code_element.temp_reg_id;
			    $$->x86_code_element.temp_reg_id = op2;
			    $$->x86_code_element.code.push_back(x86::Command("or", x86_control.reg_as_atnt(op1), x86_control.reg_as_atnt(op2), false));
			    x86_control.free_reg(op1);
                        };

expressao_6: expressao_5 { $$ = $1; }
           | expressao_6 TK_OC_AND expressao_5 { $$ = $2; $$->add_child($1); $$->add_child($3);
                            $$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
                            if ($1->get_node_type() == Type::CHARACTER) {
           					 	send_error_message($1, ERR_CHAR_TO_BOOL);
							    exit(ERR_CHAR_TO_BOOL);
                            } else if ($3->get_node_type() == Type::CHARACTER) {
           					 	send_error_message($3, ERR_CHAR_TO_BOOL);
                                exit(ERR_CHAR_TO_BOOL);
                            }
                            $$->iloc_code_element = ILOC_Code::CodeElement{};
                            $$->iloc_code_element.code = $1->iloc_code_element.code;
                            $$->iloc_code_element.copy_code($3->iloc_code_element.code);
                            $$->iloc_code_element.temporary = get_new_register();
                            $$->iloc_code_element.code.push_back(Command(Instruct::AND, $1->iloc_code_element.temporary, $3->iloc_code_element.temporary, $$->iloc_code_element.temporary, NO_REG));

			    $$->x86_code_element = x86::CodeElement{};
		    	    $$->x86_code_element.code = $1->x86_code_element.code;
		    	    $$->x86_code_element.copy_code($3->x86_code_element.code);
			    auto op1 = $1->x86_code_element.temp_reg_id;
			    auto op2 = $3->x86_code_element.temp_reg_id;
			    $$->x86_code_element.temp_reg_id = op2;
			    $$->x86_code_element.code.push_back(x86::Command("and", x86_control.reg_as_atnt(op1), x86_control.reg_as_atnt(op2), false));
			    x86_control.free_reg(op1);
                        };


expressao_5: expressao_4 { $$ = $1; }
           | expressao_5 TK_OC_EQ expressao_4 { $$ = $2; $$->add_child($1); $$->add_child($3);
           					$$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
           					if ($1->get_node_type() == Type::CHARACTER) {
           						if ($3->get_node_type() == Type::INTEGER) {
           							send_error_message($1, ERR_CHAR_TO_INT);
                                    exit(ERR_CHAR_TO_INT);
                                    } else if ($3->get_node_type() == Type::FLOATING) {
                                    send_error_message($1, ERR_CHAR_TO_FLOAT);
                                    exit(ERR_CHAR_TO_FLOAT);
                                } else if ($3->get_node_type() == Type::BOOLEAN) {
                                    send_error_message($1, ERR_CHAR_TO_BOOL);
                                    exit(ERR_CHAR_TO_BOOL);
                                }
           					} else if ($3->get_node_type() == Type::CHARACTER) {
           						if ($1->get_node_type() == Type::INTEGER) {
                                    send_error_message($3, ERR_CHAR_TO_INT);
                                    exit(ERR_CHAR_TO_INT);
                                } else if ($1->get_node_type() == Type::FLOATING) {
                                    send_error_message($3, ERR_CHAR_TO_FLOAT);
                                    exit(ERR_CHAR_TO_FLOAT);
                                } else if ($1->get_node_type() == Type::BOOLEAN) {
                                    send_error_message($3, ERR_CHAR_TO_BOOL);
                                    exit(ERR_CHAR_TO_BOOL);
                                }
           				    }
                            $$->iloc_code_element = ILOC_Code::CodeElement{};
                            $$->iloc_code_element.code = $1->iloc_code_element.code;
                            $$->iloc_code_element.copy_code($3->iloc_code_element.code);
                            $$->iloc_code_element.temporary = get_new_register();
                            $$->iloc_code_element.code.push_back(Command(Instruct::CMP_EQ, $1->iloc_code_element.temporary, $3->iloc_code_element.temporary, $$->iloc_code_element.temporary, NO_REG));

			    $$->x86_code_element = x86::CodeElement{};
		   	    $$->x86_code_element.code = $1->x86_code_element.code;
		  	    $$->x86_code_element.copy_code($3->x86_code_element.code);
/*
		    auto op1 = $1->x86_code_element.temp_reg_id;
		    auto op2 = $3->x86_code_element.temp_reg_id;
		    $$->x86_code_element.temp_reg_id = op2;
		    $$->x86_code_element.code.push_back(x86::Command("add", x86_control.reg_as_atnt(op1), x86_control.reg_as_atnt(op2), false));
		    x86_control.free_reg(op1);
*/
                        }
           | expressao_5 TK_OC_NE expressao_4 { $$ = $2; $$->add_child($1); $$->add_child($3);
           					$$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
           					if ($1->get_node_type() == Type::CHARACTER) {
           						if ($3->get_node_type() == Type::INTEGER) {
                                    send_error_message($1, ERR_CHAR_TO_INT);
                                    exit(ERR_CHAR_TO_INT);
                                } else if ($3->get_node_type() == Type::FLOATING) {
                                    send_error_message($1, ERR_CHAR_TO_FLOAT);
                                    exit(ERR_CHAR_TO_FLOAT);
                                } else if ($3->get_node_type() == Type::BOOLEAN) {
                                    send_error_message($1, ERR_CHAR_TO_BOOL);
                                    exit(ERR_CHAR_TO_BOOL);
                                }
           					} else if ($3->get_node_type() == Type::CHARACTER) {
           						if ($1->get_node_type() == Type::INTEGER) {
                                    send_error_message($3, ERR_CHAR_TO_INT);
                                    exit(ERR_CHAR_TO_INT);
                                } else if ($1->get_node_type() == Type::FLOATING) {
                                    send_error_message($3, ERR_CHAR_TO_FLOAT);
                                    exit(ERR_CHAR_TO_FLOAT);
                                } else if ($1->get_node_type() == Type::BOOLEAN) {
                                    send_error_message($3, ERR_CHAR_TO_BOOL);
                                    exit(ERR_CHAR_TO_BOOL);
                                }
           					}
                            $$->iloc_code_element = ILOC_Code::CodeElement{};
                            $$->iloc_code_element.code = $1->iloc_code_element.code;
                            $$->iloc_code_element.copy_code($3->iloc_code_element.code);
                            $$->iloc_code_element.temporary = get_new_register();
                            $$->iloc_code_element.code.push_back(Command(Instruct::CMP_NE, $1->iloc_code_element.temporary, $3->iloc_code_element.temporary, $$->iloc_code_element.temporary, NO_REG));

			   $$->x86_code_element = x86::CodeElement{};
		    	   $$->x86_code_element.code = $1->x86_code_element.code;
		    	   $$->x86_code_element.copy_code($3->x86_code_element.code);
/*
		    auto op1 = $1->x86_code_element.temp_reg_id;
		    auto op2 = $3->x86_code_element.temp_reg_id;
		    $$->x86_code_element.temp_reg_id = op2;
		    $$->x86_code_element.code.push_back(x86::Command("add", x86_control.reg_as_atnt(op1), x86_control.reg_as_atnt(op2), false));
		    x86_control.free_reg(op1);
*/
                        };

expressao_4: expressao_3 { $$ = $1; }
           | expressao_4 '<' expressao_3 { $$ = $2; $$->add_child($1); $$->add_child($3);
           				    $$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
           				    if ($1->get_node_type() == Type::CHARACTER) {
                                if ($3->get_node_type() == Type::INTEGER) {
                                    send_error_message($1, ERR_CHAR_TO_INT);
                                    exit(ERR_CHAR_TO_INT);
                                } else if ($3->get_node_type() == Type::FLOATING) {
                                    send_error_message($1, ERR_CHAR_TO_FLOAT);
                                    exit(ERR_CHAR_TO_FLOAT);
                                }
           				    } else if ($3->get_node_type() == Type::CHARACTER) {
                                if ($1->get_node_type() == Type::INTEGER) {
                                    send_error_message($3, ERR_CHAR_TO_INT);
                                    exit(ERR_CHAR_TO_INT);
                                } else if ($1->get_node_type() == Type::FLOATING) {
                                    send_error_message($3, ERR_CHAR_TO_FLOAT);
                                    exit(ERR_CHAR_TO_FLOAT);
                                }
           				    }
                            $$->iloc_code_element = ILOC_Code::CodeElement{};
                            $$->iloc_code_element.code = $1->iloc_code_element.code;
                            $$->iloc_code_element.copy_code($3->iloc_code_element.code);
                            $$->iloc_code_element.temporary = get_new_register();
                            $$->iloc_code_element.code.push_back(Command(Instruct::CMP_LT, $1->iloc_code_element.temporary, $3->iloc_code_element.temporary, $$->iloc_code_element.temporary, NO_REG));

			    $$->x86_code_element = x86::CodeElement{};
		            $$->x86_code_element.code = $1->x86_code_element.code;
		  	    $$->x86_code_element.copy_code($3->x86_code_element.code);
/*
		    auto op1 = $1->x86_code_element.temp_reg_id;
		    auto op2 = $3->x86_code_element.temp_reg_id;
		    $$->x86_code_element.temp_reg_id = op2;
		    $$->x86_code_element.code.push_back(x86::Command("add", x86_control.reg_as_atnt(op1), x86_control.reg_as_atnt(op2), false));
		    x86_control.free_reg(op1);
*/
                        }
           | expressao_4 '>' expressao_3 { $$ = $2; $$->add_child($1); $$->add_child($3);
                            $$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
                            if ($1->get_node_type() == Type::CHARACTER) {
                                if ($3->get_node_type() == Type::INTEGER) {
                                    send_error_message($1, ERR_CHAR_TO_INT);
                                    exit(ERR_CHAR_TO_INT);
                                } else if ($3->get_node_type() == Type::FLOATING) {
                                    send_error_message($1, ERR_CHAR_TO_FLOAT);
                                    exit(ERR_CHAR_TO_FLOAT);
                                }
                            } else if ($3->get_node_type() == Type::CHARACTER) {
                                if ($1->get_node_type() == Type::INTEGER) {
                                    send_error_message($3, ERR_CHAR_TO_INT);
                                    exit(ERR_CHAR_TO_INT);
                                } else if ($1->get_node_type() == Type::FLOATING) {
                                    send_error_message($3, ERR_CHAR_TO_FLOAT);
                                    exit(ERR_CHAR_TO_FLOAT);
                                }
                            }
                            $$->iloc_code_element = ILOC_Code::CodeElement{};
                            $$->iloc_code_element.code = $1->iloc_code_element.code;
                            $$->iloc_code_element.copy_code($3->iloc_code_element.code);
                            $$->iloc_code_element.temporary = get_new_register();
                            $$->iloc_code_element.code.push_back(Command(Instruct::CMP_GT, $1->iloc_code_element.temporary, $3->iloc_code_element.temporary, $$->iloc_code_element.temporary, NO_REG));

			    $$->x86_code_element = x86::CodeElement{};
		   	    $$->x86_code_element.code = $1->x86_code_element.code;
		            $$->x86_code_element.copy_code($3->x86_code_element.code);
/*
		    auto op1 = $1->x86_code_element.temp_reg_id;
		    auto op2 = $3->x86_code_element.temp_reg_id;
		    $$->x86_code_element.temp_reg_id = op2;
		    $$->x86_code_element.code.push_back(x86::Command("add", x86_control.reg_as_atnt(op1), x86_control.reg_as_atnt(op2), false));
		    x86_control.free_reg(op1);
*/
                        }
           | expressao_4 TK_OC_LE expressao_3 { $$ = $2; $$->add_child($1); $$->add_child($3);
           					$$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
           					if ($1->get_node_type() == Type::CHARACTER) {
                                if ($3->get_node_type() == Type::INTEGER) {
                                    send_error_message($1, ERR_CHAR_TO_INT);
                                    exit(ERR_CHAR_TO_INT);
                                } else if ($3->get_node_type() == Type::FLOATING) {
                                    send_error_message($1, ERR_CHAR_TO_FLOAT);
                                    exit(ERR_CHAR_TO_FLOAT);
                                }
						    } else if ($3->get_node_type() == Type::CHARACTER) {
                                if ($1->get_node_type() == Type::INTEGER) {
                                    send_error_message($3, ERR_CHAR_TO_INT);
                                    exit(ERR_CHAR_TO_INT);
                                } else if ($1->get_node_type() == Type::FLOATING) {
                                    send_error_message($3, ERR_CHAR_TO_FLOAT);
                                    exit(ERR_CHAR_TO_FLOAT);
                                }
						    }
                            $$->iloc_code_element = ILOC_Code::CodeElement{};
                            $$->iloc_code_element.code = $1->iloc_code_element.code;
                            $$->iloc_code_element.copy_code($3->iloc_code_element.code);
                            $$->iloc_code_element.temporary = get_new_register();
                            $$->iloc_code_element.code.push_back(Command(Instruct::CMP_LE, $1->iloc_code_element.temporary, $3->iloc_code_element.temporary, $$->iloc_code_element.temporary, NO_REG));

			$$->x86_code_element = x86::CodeElement{};
		        $$->x86_code_element.code = $1->x86_code_element.code;
		        $$->x86_code_element.copy_code($3->x86_code_element.code);
/*
		    auto op1 = $1->x86_code_element.temp_reg_id;
		    auto op2 = $3->x86_code_element.temp_reg_id;
		    $$->x86_code_element.temp_reg_id = op2;
		    $$->x86_code_element.code.push_back(x86::Command("add", x86_control.reg_as_atnt(op1), x86_control.reg_as_atnt(op2), false));
		    x86_control.free_reg(op1);
*/
                        }
           | expressao_4 TK_OC_GE expressao_3 { $$ = $2; $$->add_child($1); $$->add_child($3);
                            $$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
                            if ($1->get_node_type() == Type::CHARACTER) {
                                if ($3->get_node_type() == Type::INTEGER) {
                                    send_error_message($1, ERR_CHAR_TO_INT);
                                    exit(ERR_CHAR_TO_INT);
                                } else if ($3->get_node_type() == Type::FLOATING) {
                                    send_error_message($1, ERR_CHAR_TO_FLOAT);
                                    exit(ERR_CHAR_TO_FLOAT);
                                }
                            } else if ($3->get_node_type() == Type::CHARACTER) {
                                if ($1->get_node_type() == Type::INTEGER) {
                                    send_error_message($3, ERR_CHAR_TO_INT);
                                    exit(ERR_CHAR_TO_INT);
                                } else if ($1->get_node_type() == Type::FLOATING) {
                                    send_error_message($3, ERR_CHAR_TO_FLOAT);
                                    exit(ERR_CHAR_TO_FLOAT);
                                }
                            }
                            $$->iloc_code_element = ILOC_Code::CodeElement{};
                            $$->iloc_code_element.code = $1->iloc_code_element.code;
                            $$->iloc_code_element.copy_code($3->iloc_code_element.code);
                            $$->iloc_code_element.temporary = get_new_register();
                            $$->iloc_code_element.code.push_back(Command(Instruct::CMP_GE, $1->iloc_code_element.temporary, $3->iloc_code_element.temporary, $$->iloc_code_element.temporary, NO_REG));

                            $$->x86_code_element = x86::CodeElement{};
			    $$->x86_code_element.code = $1->x86_code_element.code;
			    $$->x86_code_element.copy_code($3->x86_code_element.code);
/*
			    auto op1 = $1->x86_code_element.temp_reg_id;
			    auto op2 = $3->x86_code_element.temp_reg_id;
			    $$->x86_code_element.temp_reg_id = op2;
		     	    $$->x86_code_element.code.push_back(x86::Command("add", x86_control.reg_as_atnt(op1), x86_control.reg_as_atnt(op2), false));
			    x86_control.free_reg(op1);
  */
                            };


expressao_3: expressao_2 { $$ = $1; }
           | expressao_3 '+' expressao_2 { $$ = $2; $$->add_child($1); $$->add_child($3);
           				    $$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
           				    if ($1->get_node_type() == Type::CHARACTER) {
                                if ($3->get_node_type() == Type::INTEGER) {
                                    send_error_message($1, ERR_CHAR_TO_INT);
                                    exit(ERR_CHAR_TO_INT);
                                } else if ($3->get_node_type() == Type::FLOATING) {
                                    send_error_message($1, ERR_CHAR_TO_FLOAT);
                                    exit(ERR_CHAR_TO_FLOAT);
                                }
                            } else if ($3->get_node_type() == Type::CHARACTER) {
                                if ($1->get_node_type() == Type::INTEGER) {
                                    send_error_message($3, ERR_CHAR_TO_INT);
                                    exit(ERR_CHAR_TO_INT);
                                } else if ($1->get_node_type() == Type::FLOATING) {
                                    send_error_message($3, ERR_CHAR_TO_FLOAT);
                                    exit(ERR_CHAR_TO_FLOAT);
                                }
                            }
                            $$->iloc_code_element = ILOC_Code::CodeElement{};
                            $$->iloc_code_element.code = $1->iloc_code_element.code;
                            $$->iloc_code_element.copy_code($3->iloc_code_element.code);
                            $$->iloc_code_element.temporary = get_new_register();
                            $$->iloc_code_element.code.push_back(Command(Instruct::ADD, $1->iloc_code_element.temporary, $3->iloc_code_element.temporary, $$->iloc_code_element.temporary, NO_REG));

                            $$->x86_code_element = x86::CodeElement{};
                            $$->x86_code_element.code = $1->x86_code_element.code;
                            $$->x86_code_element.copy_code($3->x86_code_element.code);
                            auto op1 = $1->x86_code_element.temp_reg_id;
                            auto op2 = $3->x86_code_element.temp_reg_id;
                            $$->x86_code_element.temp_reg_id = op2;
                            $$->x86_code_element.code.push_back(x86::Command("add", x86_control.reg_as_atnt(op1), x86_control.reg_as_atnt(op2), false));
                            x86_control.free_reg(op1);

                        }
           | expressao_3 '-' expressao_2 { $$ = $2; $$->add_child($1); $$->add_child($3);
                                $$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
                                if ($1->get_node_type() == Type::CHARACTER) {
                                    if ($3->get_node_type() == Type::INTEGER) {
                                        send_error_message($1, ERR_CHAR_TO_INT);
                                        exit(ERR_CHAR_TO_INT);
                                    } else if ($3->get_node_type() == Type::FLOATING) {
                                        send_error_message($1, ERR_CHAR_TO_FLOAT);
                                        exit(ERR_CHAR_TO_FLOAT);
                                    }
                                } else if ($3->get_node_type() == Type::CHARACTER) {
                                    if ($1->get_node_type() == Type::INTEGER) {
                                        send_error_message($3, ERR_CHAR_TO_INT);
                                        exit(ERR_CHAR_TO_INT);
                                    } else if ($1->get_node_type() == Type::FLOATING) {
                                        send_error_message($3, ERR_CHAR_TO_FLOAT);
                                        exit(ERR_CHAR_TO_FLOAT);
                                    }
                                }
                                $$->iloc_code_element = ILOC_Code::CodeElement{};
                                $$->iloc_code_element.code = $1->iloc_code_element.code;
                                $$->iloc_code_element.copy_code($3->iloc_code_element.code);
                                $$->iloc_code_element.temporary = get_new_register();
                                $$->iloc_code_element.code.push_back(Command(Instruct::SUB, $1->iloc_code_element.temporary, $3->iloc_code_element.temporary, $$->iloc_code_element.temporary, NO_REG));

                                $$->x86_code_element = x86::CodeElement{};
                                $$->x86_code_element.code = $1->x86_code_element.code;
                                $$->x86_code_element.copy_code($3->x86_code_element.code);
                                auto op1 = $1->x86_code_element.temp_reg_id;
                                auto op2 = $3->x86_code_element.temp_reg_id;
                                $$->x86_code_element.temp_reg_id = op2;
                                $$->x86_code_element.code.push_back(x86::Command("sub", x86_control.reg_as_atnt(op1), x86_control.reg_as_atnt(op2), false));
                                x86_control.free_reg(op1);
                            };

expressao_2: expressao_1 { $$ = $1; }
           | expressao_2 '*' expressao_1 { $$ = $2; $$->add_child($1); $$->add_child($3);
                            $$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
                            if ($1->get_node_type() == Type::CHARACTER) {
                                if ($3->get_node_type() == Type::INTEGER) {
                                    send_error_message($1, ERR_CHAR_TO_INT);
                                    exit(ERR_CHAR_TO_INT);
                                } else if ($3->get_node_type() == Type::FLOATING) {
                                    send_error_message($1, ERR_CHAR_TO_FLOAT);
                                    exit(ERR_CHAR_TO_FLOAT);
                                }
                            } else if ($3->get_node_type() == Type::CHARACTER) {
                                if ($1->get_node_type() == Type::INTEGER) {
                                    send_error_message($3, ERR_CHAR_TO_INT);
                                    exit(ERR_CHAR_TO_INT);
                                } else if ($1->get_node_type() == Type::FLOATING) {
                                    send_error_message($3, ERR_CHAR_TO_FLOAT);
                                    exit(ERR_CHAR_TO_FLOAT);
                                }
                            }
                            $$->iloc_code_element = ILOC_Code::CodeElement{};
                            $$->iloc_code_element.code = $1->iloc_code_element.code;
                            $$->iloc_code_element.copy_code($3->iloc_code_element.code);
                            $$->iloc_code_element.temporary = get_new_register();
                            $$->iloc_code_element.code.push_back(Command(Instruct::MULT, $1->iloc_code_element.temporary, $3->iloc_code_element.temporary, $$->iloc_code_element.temporary, NO_REG));

                            $$->x86_code_element = x86::CodeElement{};
                            $$->x86_code_element.code = $1->x86_code_element.code;
                            $$->x86_code_element.copy_code($3->x86_code_element.code);
                            auto op1 = $1->x86_code_element.temp_reg_id;
                            auto op2 = $3->x86_code_element.temp_reg_id;
                            $$->x86_code_element.temp_reg_id = op2;
                            $$->x86_code_element.code.push_back(x86::Command("mul", x86_control.reg_as_atnt(op1), x86_control.reg_as_atnt(op2), false));
                            x86_control.free_reg(op1);
                       }
           | expressao_2 '/' expressao_1 { $$ = $2; $$->add_child($1); $$->add_child($3);
                            $$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
                            if ($1->get_node_type() == Type::CHARACTER) {
                                if ($3->get_node_type() == Type::INTEGER) {
                                    send_error_message($1, ERR_CHAR_TO_INT);
                                    exit(ERR_CHAR_TO_INT);
                                } else if ($3->get_node_type() == Type::FLOATING) {
                                    send_error_message($1, ERR_CHAR_TO_FLOAT);
                                    exit(ERR_CHAR_TO_FLOAT);
                                }
                            } else if ($3->get_node_type() == Type::CHARACTER) {
                                if ($1->get_node_type() == Type::INTEGER) {
                                    send_error_message($3, ERR_CHAR_TO_INT);
                                    exit(ERR_CHAR_TO_INT);
                                } else if ($1->get_node_type() == Type::FLOATING) {
                                    send_error_message($3, ERR_CHAR_TO_FLOAT);
                                    exit(ERR_CHAR_TO_FLOAT);
                                }
                            }
                            $$->iloc_code_element = ILOC_Code::CodeElement{};
                            $$->iloc_code_element.code = $1->iloc_code_element.code;
                            $$->iloc_code_element.copy_code($3->iloc_code_element.code);
                            $$->iloc_code_element.temporary = get_new_register();
                            $$->iloc_code_element.code.push_back(Command(Instruct::DIV, $1->iloc_code_element.temporary, $3->iloc_code_element.temporary, $$->iloc_code_element.temporary, NO_REG));
                            // TODO: isso vai dar errado, ver sintaxe do idiv
                            $$->x86_code_element = x86::CodeElement{};
                            $$->x86_code_element.code = $1->x86_code_element.code;
                            $$->x86_code_element.copy_code($3->x86_code_element.code);
                            auto op1 = $1->x86_code_element.temp_reg_id;
                            auto op2 = $3->x86_code_element.temp_reg_id;
                            $$->x86_code_element.temp_reg_id = op2;
                            $$->x86_code_element.code.push_back(x86::Command("idiv", x86_control.reg_as_atnt(op1), x86_control.reg_as_atnt(op2), false));
                            x86_control.free_reg(op1);
                        }
           | expressao_2 '%' expressao_1 { $$ = $2; $$->add_child($1); $$->add_child($3);
           				    $$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
           				    if ($1->get_node_type() == Type::CHARACTER) {
                            if ($3->get_node_type() == Type::INTEGER) {
                                send_error_message($1, ERR_CHAR_TO_INT);
                                exit(ERR_CHAR_TO_INT);
                            } else if ($3->get_node_type() == Type::FLOATING) {
                                send_error_message($1, ERR_CHAR_TO_FLOAT);
                                exit(ERR_CHAR_TO_FLOAT);
						    }
					    } else if ($3->get_node_type() == Type::CHARACTER) {
                            if ($1->get_node_type() == Type::INTEGER) {
                                send_error_message($3, ERR_CHAR_TO_INT);
                                exit(ERR_CHAR_TO_INT);
                            } else if ($1->get_node_type() == Type::FLOATING) {
                                send_error_message($3, ERR_CHAR_TO_FLOAT);
                                exit(ERR_CHAR_TO_FLOAT);
                            }
					    }
                        $$->iloc_code_element = $1->iloc_code_element;
                        $$->iloc_code_element.temporary = $1->iloc_code_element.temporary;
                        $$->x86_code_element = $1->x86_code_element;
                        $$->x86_code_element.temp_reg_id = $1->x86_code_element.temp_reg_id;
                       };

expressao_1: operando { $$ = $1; }
           | '(' expressao_7 ')' { $$ = $2; }
           | '-' expressao_1 { $$ = $1; $$->add_child($2); $$->set_node_type($2->get_node_type());
           		       if ($2->get_node_type() == Type::CHARACTER) {
           		       		send_error_message($2, ERR_CHAR_TO_INT);
           		       		exit(ERR_CHAR_TO_INT);
           		       	}
                        $$->iloc_code_element = $2->iloc_code_element;
                        $$->iloc_code_element.temporary = $2->iloc_code_element.temporary;
                        $$->x86_code_element = $1->x86_code_element;
                        $$->x86_code_element.temp_reg_id = $1->x86_code_element.temp_reg_id;
                        }
           | '!' expressao_1 { $$ = $1; $$->add_child($2); $$->set_node_type($2->get_node_type());
           		       if ($2->get_node_type() == Type::CHARACTER) {
           		       		send_error_message($2, ERR_CHAR_TO_BOOL);
           		       		exit(ERR_CHAR_TO_BOOL);
           		       	}
                        $$->iloc_code_element = $2->iloc_code_element;
                        $$->iloc_code_element.temporary = $2->iloc_code_element.temporary;
                        $$->x86_code_element = $1->x86_code_element;
                        $$->x86_code_element.temp_reg_id = $1->x86_code_element.temp_reg_id;
                        } ;

operando: identificador { $$ = $1;  $$->set_node_type($1->get_node_type());
                            // Load do endereço salvo no registrador dentro da temporária
                            auto old_reg = $1->iloc_code_element.temporary;
                            $$->iloc_code_element.temporary = get_new_register();
                            $$->iloc_code_element.code.push_back(Command{Instruct::LOAD, old_reg, NO_REG, $$->iloc_code_element.temporary, NO_REG});
                        }
        | literal { $$ = $1; $$->set_node_type($1->get_node_type());
                    int lit_val = std::get<int>($$->get_token_val());
                    ILOC_Code::CodeElement iloc_elem{};
                    iloc_elem.temporary = ILOC_Code::get_new_register();
                    iloc_elem.code.push_back(Command{Instruct::LOAD_I, (reg_t) lit_val, NO_REG, iloc_elem.temporary, NO_REG});
                    $$->iloc_code_element = iloc_elem;
                    x86::CodeElement x86_elem{};
                    int reg_id = x86_control.alloc_reg();
                    std::string op1 = "$" + std::to_string(lit_val);
                    std::string op2 = "%" + x86_control.registers[reg_id];
                    x86_elem.code.push_back(x86::Command{"movl", op1, op2, false});
                    x86_elem.temp_reg_id = reg_id;
                    $$->x86_code_element = x86_elem;
                }
        | cham_funcao { $$ = $1; $$->set_node_type($1->get_node_type()); };

/* regras para deixar o parser menos verboso */
literal: TK_LIT_INT { $$ = $1; $$->set_node_type(Type::INTEGER); 
                      Symbol s {
                          $1->get_line_no(),
                          Kind::LITERAL,
                          Type::INTEGER,
                          get_size_from_type(Type::INTEGER),
                          $1,
                          0
                      };
                      symbol_table_stack.insert_top($1->get_token_val(), s, true);
                    }
       | TK_LIT_FLOAT { $$ = $1; $$->set_node_type(Type::FLOATING);
                        Symbol s {
                            $1->get_line_no(),
                            Kind::LITERAL,
                            Type::FLOATING,
                            get_size_from_type(Type::FLOATING),
                            $1,
                            0
                        };
                      symbol_table_stack.insert_top($1->get_token_val(), s, true);
                      }
       | TK_LIT_CHAR { $$ = $1; $$->set_node_type(Type::CHARACTER);
                       Symbol s {
                            $1->get_line_no(),
                            Kind::LITERAL,
                            Type::CHARACTER,
                            get_size_from_type(Type::CHARACTER),
                            $1,
                            0
                        };
                      symbol_table_stack.insert_top($1->get_token_val(), s, true);
                     }
       | TK_LIT_TRUE { $$ = $1; $$->set_node_type(Type::BOOLEAN);
                       Symbol s {
                            $1->get_line_no(),
                            Kind::LITERAL,
                            Type::BOOLEAN,
                            get_size_from_type(Type::BOOLEAN),
                            $1, 
                            0
                        };
                      symbol_table_stack.insert_top($1->get_token_val(), s, true);
                     }
       | TK_LIT_FALSE { $$ = $1; $$->set_node_type(Type::BOOLEAN);
                        Symbol s {
                            $1->get_line_no(),
                            Kind::LITERAL,
                            Type::BOOLEAN,
                            get_size_from_type(Type::BOOLEAN),
                            $1,
                            0
                        };
                      symbol_table_stack.insert_top($1->get_token_val(), s, true);
                      };

tipo_primitivo: TK_PR_INT { $$ = $1; $$->set_node_type(Type::INTEGER); }
              | TK_PR_FLOAT { $$ = $1; $$->set_node_type(Type::FLOATING); }
              | TK_PR_CHAR { $$ = $1; $$->set_node_type(Type::CHARACTER); }
              | TK_PR_BOOL { $$ = $1; $$->set_node_type(Type::BOOLEAN); };



%%
/* Declaração da função de erro */
void yyerror (const char *msg) {
    std::cerr << "line " << get_line_number() << ": " << msg << std::endl;
}

void send_error_message (Node* node, int code) {
    int line_no = node->get_line_no();
    std::string token_val = node->to_string();

//    std::string token_type = token_type_to_string(node->get_token_type());
    std::string token_type = node_type_to_string(node->get_node_type());

    if (code == ERR_UNDECLARED) {
        std::cout << "[ERRO linha " << line_no
                  << "] Variável " << token_val << " não foi declarada." << std::endl;
    } else if (code == ERR_DECLARED) {
        // NOTE: daria pra pegar o numero da linha da declaração anterior acessando a tabela de simbolos
        std::cout << "[ERRO linha " << line_no
                  << "] Variável " << token_val << " foi declarada na linha X e não pode ser redeclarada." <<std::endl;
    } else if (code == ERR_VARIABLE) {
        std::cout << "[ERRO linha " << line_no
                  << "] Uso indevido da variável " << token_val << "." <<std::endl;
    } else if (code == ERR_ARRAY) {
        std::cout << "[ERRO linha " << line_no
                  << "] Uso indevido do arranjo " << token_val << "." <<std::endl;
    } else if (code == ERR_FUNCTION) {
        std::cout << "[ERRO linha " << line_no
                  << "] Uso indevido da função " << token_val << "." <<std::endl;
    } else if (code == ERR_CHAR_TO_INT) {
        std::cout << "[ERRO linha " << line_no
                  << "] Conversão char >> int não suportada." <<std::endl;
    } else if (code == ERR_CHAR_TO_FLOAT) {
        std::cout << "[ERRO linha " << line_no
                  << "] Conversão char >> float não suportada." <<std::endl;
    } else if (code == ERR_CHAR_TO_BOOL) {
        std::cout << "[ERRO linha " << line_no
                  << "] Conversão char >> bool não suportada." <<std::endl;
    } else if (code == ERR_CHAR_VECTOR) {
        std::cout << "[ERRO linha " << line_no
                  << "] Vetores de char não são suportados." <<std::endl;
    } else if (code == ERR_X_TO_CHAR) {
        std::cout << "[ERRO linha " << line_no
                  << "] Conversão " << token_type << " >> char não suportada." << std::endl;
    }
}
