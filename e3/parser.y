%{
#include <iostream>
#include <memory>
extern int get_line_number();
extern void* arvore;
int yylex(void);
void yyerror (const char *msg);
%}

%require "3.0.4"

%code requires {
    #include <memory>
    #include "tree.hh"
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

programa: lista_elem {$$ = $1; arvore = $$;}
        | %empty {$$ = nullptr; arvore = $$;};

lista_elem: var_global {$$ = nullptr;}
	      | funcao {$$ = $1;}
	      | var_global lista_elem {$$ = $2;}
          | funcao lista_elem {$$ = $1; $$->add_child($2);};

/* Definição de variáveis globais dos tipos primitivos */
var_global: tipo_primitivo lista_id_var_global ';' {$$ = nullptr;};

lista_id_var_global: id_var_global {$$ = nullptr;}
                   | lista_id_var_global ',' id_var_global {$$ = nullptr;};

id_var_global: TK_IDENTIFICADOR {$$=nullptr; delete $1;}
             | TK_IDENTIFICADOR '[' lista_dimensoes ']' {$$=nullptr; delete $1;};

lista_dimensoes: TK_LIT_INT {$$=nullptr; delete $1;}
               | lista_dimensoes '^' TK_LIT_INT {$$=nullptr; delete $3;};

/* Definição de funções */
funcao: tipo_primitivo TK_IDENTIFICADOR '(' lista_parametros ')' corpo_funcao {$$ = $2; $$->add_child($6);};

lista_parametros: %empty {$$ = nullptr;}
                | parametro {$$ = nullptr;}
                | lista_parametros ',' parametro {$$ = nullptr;};

parametro: tipo_primitivo TK_IDENTIFICADOR {$$=nullptr; delete $2;};

corpo_funcao: bloco_comandos {$$ = $1;};

/* Bloco de comandos */
bloco_comandos: '{' lista_comandos '}' {$$ = $2;}
              /* TODO: verificar se temos que adicionar um filho em caso de bloco vazio */
              | '{' '}' {$$ = nullptr;};

lista_comandos: comando_simples ';' {$$ = $1;}
              | comando_simples lista_comandos ';'  {$$ = $1; $$->add_child($2);};

comando_simples: var_local {$$ = $1;}
               | atribuicao {$$ = $1;}
               | con_fluxo {$$ = $1;}
               | op_retorno {$$ = $1;}
               | cham_funcao {$$ = $1;}
               /* TODO: entender a parte do bloco de comandos em comandos simples */
               | bloco_comandos {$$ = $1;};

/* Definição de variável local, permitindo apenas literais do tipo correspondente */
var_local: TK_PR_INT lista_var_local_int {$$ = $2;}
         | TK_PR_FLOAT lista_var_local_float {$$ = $2;}
         | TK_PR_BOOL lista_var_local_bool {$$ = $2;}
         | TK_PR_CHAR lista_var_local_char {$$ = $2;};

/* inteiro */
lista_var_local_int: var_local_int {$$ = $1;}
                   | var_local_int ',' lista_var_local_int {$$ = $1; $$->add_child($3);};

var_local_int: TK_IDENTIFICADOR {$$ = nullptr; delete $1;}
             | TK_IDENTIFICADOR TK_OC_LE TK_LIT_INT {$$ = $2; $$->add_child($1); $$->add_child($3);};

/* ponto flutuante */
lista_var_local_float: var_local_float {$$ = $1;}
                     | lista_var_local_float ',' var_local_float {$$ = $1; $$->add_child($3);};

var_local_float: TK_IDENTIFICADOR {$$ = nullptr; delete $1;}
               | TK_IDENTIFICADOR TK_OC_LE TK_LIT_FLOAT {$$ = $2; $$->add_child($1); $$->add_child($3);};

/* booleano */
lista_var_local_bool: var_local_bool {$$ = $1;}
                    | lista_var_local_bool ',' var_local_bool {$$ = $1; $$->add_child($3);};

var_local_bool: TK_IDENTIFICADOR {$$ = nullptr; delete $1;}
              | TK_IDENTIFICADOR TK_OC_LE TK_LIT_TRUE {$$ = $2; $$->add_child($1); $$->add_child($3);}
              | TK_IDENTIFICADOR TK_OC_LE TK_LIT_FALSE {$$ = $2; $$->add_child($1); $$->add_child($3);};

/* caracter */
lista_var_local_char: var_local_char {$$ = $1;}
                    | lista_var_local_char ',' var_local_char {$$ = $1; $$->add_child($3);};

var_local_char: TK_IDENTIFICADOR {$$ = nullptr; delete $1;}
              | TK_IDENTIFICADOR TK_OC_LE TK_LIT_CHAR {$$ = $2; $$->add_child($1); $$->add_child($3);};

/* Comando de Atribuição */
atribuicao: identificador '=' expressao_7 {$$ = $2; $$->add_child($1); $$->add_child($3);};

identificador: TK_IDENTIFICADOR {$$ = $1;}
             | TK_IDENTIFICADOR '[' lista_indices ']' {
                $$ = new Node($1->get_line_no(), TokenType::COMPOSED_OPERATOR, TokenVal("[]"));
                $$->add_child($1);
                $$->add_child($3);
             };

/* TODO: ver qual opção de arvore devemos fazer (com filho vazio ou sem filho vazio) */
lista_indices: expressao_7 {$$ = $1;}
             | lista_indices '^' expressao_7 {$$ = $2; $$->add_child($3); $$->add_child($1);};

/* Chamada de função */
cham_funcao: TK_IDENTIFICADOR '(' lista_argumentos ')' {$$ = $1; $$->add_child($3);};

/* TODO: Recursão a esquerda ou a direita? */
lista_argumentos: %empty {$$ = nullptr;}
                | expressao_7 {$$ = $1;}
                | expressao_7 ',' lista_argumentos {$$ = $1; $$->add_child($3);};

/* Comando de retorno */
op_retorno: TK_PR_RETURN expressao_7 { $$ = $1; $$->add_child($2);};

/* Controle de fluxo */
con_fluxo: TK_PR_IF '(' expressao_7 ')' TK_PR_THEN bloco_comandos {$$ = $1; $$->add_child($3); $$->add_child($6);}
         | TK_PR_IF '(' expressao_7 ')' TK_PR_THEN bloco_comandos TK_PR_ELSE bloco_comandos 
         {
            $$ = $1; 
            $$->add_child($3); 
            $$->add_child($6); 
            $$->add_child($8);
         }
         | TK_PR_WHILE '(' expressao_7 ')' bloco_comandos {$$ = $1; $$->add_child($3); $$->add_child($5);};

/* Expressão (nivel de precendencia indicado no nome da regra) */

expressao_7: expressao_6 { $$ = $1; }
           | expressao_7 TK_OC_OR expressao_6 { $$ = $2; $$->add_child($1); $$->add_child($3); };

expressao_6: expressao_5 { $$ = $1; }
           | expressao_6 TK_OC_AND expressao_5 { $$ = $2; $$->add_child($1); $$->add_child($3); };

expressao_5: expressao_4 { $$ = $1; }
           | expressao_5 TK_OC_EQ expressao_4 { $$ = $2; $$->add_child($1); $$->add_child($3); }
           | expressao_5 TK_OC_NE expressao_4 { $$ = $2; $$->add_child($1); $$->add_child($3); };

expressao_4: expressao_3 { $$ = $1; }
           | expressao_4 '<' expressao_3 { $$ = $2; $$->add_child($1); $$->add_child($3); }
           | expressao_4 '>' expressao_3 { $$ = $2; $$->add_child($1); $$->add_child($3); }
           | expressao_4 TK_OC_LE expressao_3 { $$ = $2; $$->add_child($1); $$->add_child($3); }
           | expressao_4 TK_OC_GE expressao_3 { $$ = $2; $$->add_child($1); $$->add_child($3); };


expressao_3: expressao_2 { $$ = $1; }
           | expressao_3 '+' expressao_2 { $$ = $2; $$->add_child($1); $$->add_child($3); }
           | expressao_3 '-' expressao_2 { $$ = $2; $$->add_child($1); $$->add_child($3); };

expressao_2: expressao_1
           | expressao_2 '*' expressao_1 { $$ = $2; $$->add_child($1); $$->add_child($3); }
           | expressao_2 '/' expressao_1 { $$ = $2; $$->add_child($1); $$->add_child($3); }
           | expressao_2 '%' expressao_1 { $$ = $2; $$->add_child($1); $$->add_child($3); };

expressao_1: operando { $$ = $1; }
           | '(' expressao_7 ')' { $$ = $2; }
           | '-' expressao_1 { $$ = $1; $$->add_child($2);}
           | '!' expressao_1 { $$ = $1; $$->add_child($2);} ;

operando: identificador { $$ = $1; }
        | literal { $$ = $1; }
        | cham_funcao { $$ = $1; };

/* regras para deixar o parser menos verboso */
literal: TK_LIT_INT { $$ = $1; }
       | TK_LIT_FLOAT { $$ = $1; }
       | TK_LIT_CHAR { $$ = $1; }
       | TK_LIT_TRUE { $$ = $1; }
       | TK_LIT_FALSE { $$ = $1; };

tipo_primitivo: TK_PR_INT { $$ = nullptr; }
              | TK_PR_FLOAT { $$ = nullptr; }
              | TK_PR_CHAR { $$ = nullptr; }
              | TK_PR_BOOL { $$ = nullptr; };



%%
/* Declaração da função de erro */
void yyerror (const char *msg) {
    std::cerr << "line " << get_line_number() << ": " << msg << std::endl;
}

