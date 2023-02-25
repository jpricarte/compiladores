%{
#include <iostream>
#include <memory>
#include "table.hh"
extern int get_line_number();
extern void* arvore;
int yylex(void);
void yyerror (const char *msg);
SymbolTableStack symbol_table_stack{};
%}

%require "3.0.4"

%code requires {
    #include <memory>
    #include "tree.hh"
    #include "table.hh"
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

programa: { symbol_table_stack.push_new(); } lista_elem {$$ = $2; arvore = $$; symbol_table_stack.pop(); };

lista_elem: %empty {$$ = nullptr;}
          | elemento lista_elem {
            if ($$!=nullptr) {
                $$ = $1; 
                $$->add_child($2);
            } else {
                $$ = $2;
            }
        };

elemento: var_global {$$ = $1;}
        | funcao {$$ = $1;};

/* Definição de variáveis globais dos tipos primitivos */
var_global: tipo_primitivo lista_id_var_global ';' {$$ = nullptr;};

lista_id_var_global: id_var_global {$$ = nullptr;}
                   | lista_id_var_global ',' id_var_global {$$ = nullptr;};

id_var_global: TK_IDENTIFICADOR {$$=nullptr; delete $1;}
             | TK_IDENTIFICADOR '[' lista_dimensoes ']' {$$=nullptr; delete $1;};

lista_dimensoes: TK_LIT_INT {$$=nullptr; delete $1;}
               | lista_dimensoes '^' TK_LIT_INT {$$=nullptr; delete $2; delete $3;};

/* Definição de funções */
funcao: tipo_primitivo TK_IDENTIFICADOR '(' lista_parametros ')' corpo_funcao {
    $$ = $2; 
    $$->add_child($6);
    };

lista_parametros: %empty {$$ = nullptr;}
                | parametro {$$ = nullptr;}
                | lista_parametros ',' parametro {$$ = nullptr;};

parametro: tipo_primitivo TK_IDENTIFICADOR {$$=nullptr; delete $2;};

corpo_funcao: bloco_comandos {$$ = $1;};

/* Bloco de comandos */
bloco_comandos: '{' { symbol_table_stack.push_new(); } lista_comandos '}' {$$ = $3; symbol_table_stack.pop(); };

lista_comandos: %empty {$$ = nullptr;}
              | comando_simples ';' lista_comandos {
                if ($1 != nullptr) {
                    $$ = $1; 
                    $$->add_child($3);
                } else {
                    $$ = $3;
                }};

comando_simples: var_local {$$ = $1;}
               | atribuicao {$$ = $1;}
               | con_fluxo {$$ = $1;}
               | op_retorno {$$ = $1;}
               | cham_funcao {$$ = $1;}
               | bloco_comandos {$$ = $1;};

/* Definição de variável local, permitindo apenas literais do tipo correspondente */
// TODO: fazer a conversão do valor quando mudar o tipo;
// TODO: Arrumar questões de conversão nas operações;
var_local: TK_PR_INT lista_var_local_int {$$ = $2;}
         | TK_PR_FLOAT lista_var_local_float {$$ = $2;}
         | TK_PR_BOOL lista_var_local_bool {$$ = $2;}
         | TK_PR_CHAR lista_var_local_char {$$ = $2;};


/* inteiro */
lista_var_local_int: %empty {$$ = nullptr;}
                   | var_local_int lista_var_local_int 
                   {
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
                        } else {
                            $$ = $3;
                        }
                    };

var_local_int: TK_IDENTIFICADOR { $$ = nullptr;
                                    if (symbol_table_stack.is_declared($1->get_token_val())) {
                                        delete $1;
                                        exit(ERR_DECLARED);
                                    }
                                    /*Insere na tabela de simbolos e apaga nodo*/;
                                    Symbol s{
                                                $1->get_line_no(), 
                                                Kind::VARIABLE, 
                                                Type::INTEGER, 
                                                get_size_from_type(Type::INTEGER), 
                                                nullptr
                                            };
                                    symbol_table_stack.insert_top($1->get_token_val(), s);
                                    delete $1;
                                  }
             | TK_IDENTIFICADOR { if (symbol_table_stack.is_declared($1->get_token_val())) {
                                        delete $1;
                                        exit(ERR_DECLARED);
                                  }} TK_OC_LE expressao_7 { $$ = $3; $$->add_child($1); $$->add_child($4);
                                                            $1->set_node_type(Type::INTEGER);
                                                            int exit_code = get_char_err($1->get_node_type(), $4->get_node_type());
                                                            if (exit_code > 0) exit(exit_code);
                                                            Symbol s{
                                                                $1->get_line_no(), 
                                                                Kind::VARIABLE, 
                                                                Type::INTEGER, 
                                                                get_size_from_type(Type::INTEGER), 
                                                                $3
                                                            };
                                                            symbol_table_stack.insert_top($1->get_token_val(), s);
                                                            $$->set_node_type(Type::INTEGER);
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
                                        delete $1;
                                        exit(ERR_DECLARED);
                                    }
                                    /*Insere na tabela de simbolos e apaga nodo*/;
                                    Symbol s{
                                                $1->get_line_no(), 
                                                Kind::VARIABLE, 
                                                Type::FLOATING, 
                                                get_size_from_type(Type::FLOATING), 
                                                nullptr
                                            };
                                    symbol_table_stack.insert_top($1->get_token_val(), s);
                                    delete $1;
                                  }
               | TK_IDENTIFICADOR { if (symbol_table_stack.is_declared($1->get_token_val())) {
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
                                                                $3
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
                                        delete $1;
                                        exit(ERR_DECLARED);
                                   }
                                   /*Insere na tabela de simbolos e apaga nodo*/;
                                   Symbol s{
                                            $1->get_line_no(), 
                                            Kind::VARIABLE, 
                                            Type::BOOLEAN, 
                                            get_size_from_type(Type::BOOLEAN), 
                                            nullptr
                                        };
                                   symbol_table_stack.insert_top($1->get_token_val(), s);
                                   delete $1;
                                }
              | TK_IDENTIFICADOR { if (symbol_table_stack.is_declared($1->get_token_val())) {
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
                                                              $3
                                                          };
                                                          symbol_table_stack.insert_top($1->get_token_val(), s);
                                                          $$->set_node_type(Type::BOOLEAN);
                                                      };

/* caracter */
// TODO ERR_CHAR_VECTOR?
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
                                            nullptr
                                        };
                                    symbol_table_stack.insert_top($1->get_token_val(), s);
                                    delete $1;
                                 }
              | TK_IDENTIFICADOR {
                if (symbol_table_stack.is_declared($1->get_token_val())) {
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
                                            $3
                                        };
                                        symbol_table_stack.insert_top($1->get_token_val(), s);
              					        $$->set_node_type(Type::CHARACTER);
                                    };

/* Comando de Atribuição */
atribuicao: identificador { if (!symbol_table_stack.is_declared($1->get_token_val())) exit(ERR_UNDECLARED); } 
            '=' expressao_7 { $$ = $3; $$->add_child($1); $$->add_child($4); 
                              // verifica tipos
                              int exit_code = get_char_err($1->get_node_type(), $4->get_node_type());
                              if (exit_code > 0) exit(exit_code);
                              $$->set_node_type($1->get_node_type());
                            };

identificador: TK_IDENTIFICADOR {$$ = $1;}
             | TK_IDENTIFICADOR '[' lista_indices ']' {
                $$ = new Node($1->get_line_no(), TokenType::COMPOSED_OPERATOR, TokenVal("[]"));
                $$->add_child($1);
                $$->add_child($3);
             };

lista_indices: expressao_7 {$$ = $1;}
             | lista_indices '^' expressao_7 {$$ = $2; $$->add_child($3); $$->add_child($1);};

/* Chamada de função */
cham_funcao: TK_IDENTIFICADOR '(' lista_argumentos ')' {$$ = $1; $$->set_is_func_call(true); $$->add_child($3);};

lista_argumentos: %empty {$$ = nullptr;}
                | expressao_7 {$$ = $1;}
                | expressao_7 ',' lista_argumentos {$$ = $1; $$->add_child($3);};

/* Comando de retorno */
op_retorno: TK_PR_RETURN expressao_7 { $$ = $1; $$->add_child($2);
				       $$->set_node_type($2->get_node_type());};

/* Controle de fluxo */
con_fluxo: TK_PR_IF '(' expressao_7 ')' TK_PR_THEN bloco_comandos {$$ = $1; $$->add_child($3); $$->add_child($6);
								   $$->set_node_type($3->get_node_type());
								   if ($3->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_BOOL);}}
         | TK_PR_IF '(' expressao_7 ')' TK_PR_THEN bloco_comandos TK_PR_ELSE bloco_comandos 
         {
            $$ = $1;
            $$->add_child($3);
            $$->add_child($6);
            $$->add_child($8);
            $$->set_node_type($3->get_node_type());
            if ($3->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_BOOL);}
         }
         | TK_PR_WHILE '(' expressao_7 ')' bloco_comandos {$$ = $1; $$->add_child($3); $$->add_child($5);
         						   $$->set_node_type($3->get_node_type());
         						   if ($3->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_BOOL);}};

/* Expressão (nivel de precendencia indicado no nome da regra) */

expressao_7: expressao_6 { $$ = $1; }
           | expressao_7 TK_OC_OR expressao_6 { $$ = $2; $$->add_child($1); $$->add_child($3);
           					$$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
           					if ($1->get_node_type() == Type::CHARACTER || $3->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_BOOL);}};

expressao_6: expressao_5 { $$ = $1; }
           | expressao_6 TK_OC_AND expressao_5 { $$ = $2; $$->add_child($1); $$->add_child($3);
           					 $$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
           					 if ($1->get_node_type() == Type::CHARACTER || $3->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_BOOL);}};


expressao_5: expressao_4 { $$ = $1; }
           | expressao_5 TK_OC_EQ expressao_4 { $$ = $2; $$->add_child($1); $$->add_child($3);
           					$$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
           					if ($1->get_node_type() == Type::CHARACTER || $3->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
           | expressao_5 TK_OC_NE expressao_4 { $$ = $2; $$->add_child($1); $$->add_child($3);
           					$$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
           					if ($1->get_node_type() == Type::CHARACTER || $3->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}};

expressao_4: expressao_3 { $$ = $1; }
           | expressao_4 '<' expressao_3 { $$ = $2; $$->add_child($1); $$->add_child($3);
           				   $$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
           				   if ($1->get_node_type() == Type::CHARACTER || $3->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
           | expressao_4 '>' expressao_3 { $$ = $2; $$->add_child($1); $$->add_child($3);
           				   $$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
           				   if ($1->get_node_type() == Type::CHARACTER || $3->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
           | expressao_4 TK_OC_LE expressao_3 { $$ = $2; $$->add_child($1); $$->add_child($3);
           					$$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
           					if ($1->get_node_type() == Type::CHARACTER || $3->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
           | expressao_4 TK_OC_GE expressao_3 { $$ = $2; $$->add_child($1); $$->add_child($3);
           					$$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
           					if ($1->get_node_type() == Type::CHARACTER || $3->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}};


expressao_3: expressao_2 { $$ = $1; }
           | expressao_3 '+' expressao_2 { $$ = $2; $$->add_child($1); $$->add_child($3);
           				   $$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
           				   if ($1->get_node_type() == Type::CHARACTER || $3->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
           | expressao_3 '-' expressao_2 { $$ = $2; $$->add_child($1); $$->add_child($3);
           				   $$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
           				   if ($1->get_node_type() == Type::CHARACTER || $3->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}};

expressao_2: expressao_1 { $$ = $1; }
           | expressao_2 '*' expressao_1 { $$ = $2; $$->add_child($1); $$->add_child($3);
           				   $$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
           				   if ($1->get_node_type() == Type::CHARACTER || $3->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
           | expressao_2 '/' expressao_1 { $$ = $2; $$->add_child($1); $$->add_child($3);
           				   $$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
           				   if ($1->get_node_type() == Type::CHARACTER || $3->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
           | expressao_2 '%' expressao_1 { $$ = $2; $$->add_child($1); $$->add_child($3);
           				   $$->set_node_type(type_infer($1->get_node_type(), $3->get_node_type()));
           				   if ($1->get_node_type() == Type::CHARACTER || $3->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}};

expressao_1: operando { $$ = $1; }
           | '(' expressao_7 ')' { $$ = $2; }
           | '-' expressao_1 { $$ = $1; $$->add_child($2); $$->set_node_type($2->get_node_type());
           		       if ($2->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
           | '!' expressao_1 { $$ = $1; $$->add_child($2); $$->set_node_type($2->get_node_type());
           		       if ($2->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_BOOL);}} ;

operando: identificador { $$ = $1;  $$->set_node_type($1->get_node_type()); }
        | literal { $$ = $1; $$->set_node_type($1->get_node_type()); }
        | cham_funcao { $$ = $1; $$->set_node_type($1->get_node_type()); };

/* regras para deixar o parser menos verboso */
literal: TK_LIT_INT { $$ = $1; $$->set_node_type(Type::INTEGER); }
       | TK_LIT_FLOAT { $$ = $1; $$->set_node_type(Type::FLOATING); }
       | TK_LIT_CHAR { $$ = $1; $$->set_node_type(Type::CHARACTER); }
       | TK_LIT_TRUE { $$ = $1; $$->set_node_type(Type::BOOLEAN); }
       | TK_LIT_FALSE { $$ = $1; $$->set_node_type(Type::BOOLEAN); };

tipo_primitivo: TK_PR_INT { $$ = $1; $$->set_node_type(Type::INTEGER); }
              | TK_PR_FLOAT { $$ = $1; $$->set_node_type(Type::FLOATING); }
              | TK_PR_CHAR { $$ = $1; $$->set_node_type(Type::CHARACTER); }
              | TK_PR_BOOL { $$ = $1; $$->set_node_type(Type::BOOLEAN); };



%%
/* Declaração da função de erro */
void yyerror (const char *msg) {
    std::cerr << "line " << get_line_number() << ": " << msg << std::endl;
}

