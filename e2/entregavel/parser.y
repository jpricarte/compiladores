%{
#include <stdio.h>
extern int get_line_number();
int yylex(void);
void yyerror (const char *msg);
%}

%define parse.error verbose


%token TK_PR_INT
%token TK_PR_FLOAT
%token TK_PR_BOOL
%token TK_PR_CHAR
%token TK_PR_IF
%token TK_PR_THEN
%token TK_PR_ELSE
%token TK_PR_WHILE
%token TK_PR_INPUT
%token TK_PR_OUTPUT
%token TK_PR_RETURN
%token TK_PR_FOR
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token TK_LIT_INT
%token TK_LIT_FLOAT
%token TK_LIT_FALSE
%token TK_LIT_TRUE
%token TK_LIT_CHAR
%token TK_IDENTIFICADOR
%token TK_ERRO

%start programa

%%

programa: lista_elem
        | %empty;

lista_elem: var_global
	      | funcao
	      | lista_elem var_global
          | lista_elem funcao;

/* Definição de variáveis globais dos tipos primitivos */
var_global: tipo_primitivo lista_id_var_global ';';

lista_id_var_global: id_var_global
                   | lista_id_var_global ',' id_var_global;

id_var_global: TK_IDENTIFICADOR
             | TK_IDENTIFICADOR '[' lista_dimensoes ']';

lista_dimensoes: TK_LIT_INT
               | lista_dimensoes '^' TK_LIT_INT;

/* Definição de funções */
funcao: tipo_primitivo TK_IDENTIFICADOR '(' lista_parametros ')' corpo_funcao;

lista_parametros: %empty
                | parametro
                | lista_parametros ',' parametro;

parametro: tipo_primitivo TK_IDENTIFICADOR;

corpo_funcao: bloco_comandos;

/* Bloco de comandos */
bloco_comandos: '{' lista_comandos '}'
              | '{' '}';

lista_comandos: comando_simples ';'
              | lista_comandos comando_simples ';' ;

comando_simples: var_local
               | atribuicao
               | con_fluxo
               | op_retorno
               | cham_funcao
               | bloco_comandos;

/* Definição de variável local, permitindo apenas literais do tipo correspondente */
var_local: TK_PR_INT lista_var_local_int
         | TK_PR_FLOAT lista_var_local_float
         | TK_PR_BOOL lista_var_local_bool
         | TK_PR_CHAR lista_var_local_char;

/* inteiro */
lista_var_local_int: var_local_int
                   | lista_var_local_int ',' var_local_int;

var_local_int: TK_IDENTIFICADOR
             | TK_IDENTIFICADOR TK_OC_LE TK_LIT_INT;

/* ponto flutuante */
lista_var_local_float: var_local_float
                     | lista_var_local_float ',' var_local_float;

var_local_float: TK_IDENTIFICADOR
               | TK_IDENTIFICADOR TK_OC_LE TK_LIT_FLOAT;

/* booleano */
lista_var_local_bool: var_local_bool
                    | lista_var_local_bool ',' var_local_bool;

var_local_bool: TK_IDENTIFICADOR
              | TK_IDENTIFICADOR TK_OC_LE TK_LIT_TRUE
              | TK_IDENTIFICADOR TK_OC_LE TK_LIT_FALSE;

/* caracter */
lista_var_local_char: var_local_char
                    | lista_var_local_char ',' var_local_char;

var_local_char: TK_IDENTIFICADOR
              | TK_IDENTIFICADOR TK_OC_LE TK_LIT_CHAR;

/* Comando de Atribuição */
atribuicao: identificador '=' expressao_7;

identificador: TK_IDENTIFICADOR
             | TK_IDENTIFICADOR '[' lista_indices ']';

lista_indices: expressao_7
             | lista_indices '^' expressao_7;

/* Chamada de função */
cham_funcao: TK_IDENTIFICADOR '(' lista_argumentos ')';

lista_argumentos: %empty
                | expressao_7
                | lista_argumentos ',' expressao_7;

/* Comando de retorno */
op_retorno: TK_PR_RETURN expressao_7;

/* Controle de fluxo */
con_fluxo: TK_PR_IF '(' expressao_7 ')' TK_PR_THEN bloco_comandos
         | TK_PR_IF '(' expressao_7 ')' TK_PR_THEN bloco_comandos TK_PR_ELSE bloco_comandos
         | TK_PR_WHILE '(' expressao_7 ')' bloco_comandos;

/* Expressão (nivel de precendencia indicado no nome da regra) */

expressao_7: expressao_6
           | expressao_7 TK_OC_OR expressao_6;

expressao_6: expressao_5 
           | expressao_6 TK_OC_AND expressao_5;

expressao_5: expressao_4
           | expressao_5 TK_OC_EQ expressao_4
           | expressao_5 TK_OC_NE expressao_4;

expressao_4: expressao_3
           | expressao_4 '<' expressao_3
           | expressao_4 '>' expressao_3
           | expressao_4 TK_OC_LE expressao_3
           | expressao_4 TK_OC_GE expressao_3;


expressao_3: expressao_2
           | expressao_3 '+' expressao_2
           | expressao_3 '-' expressao_2;

expressao_2: expressao_1
           | expressao_2 '*' expressao_1
           | expressao_2 '/' expressao_1
           | expressao_2 '%' expressao_1;

expressao_1: operando
           | '(' expressao_7 ')'
           | '-' expressao_1
           | '!' expressao_1;

operando: identificador
        | literal
        | cham_funcao;

/* regras para deixar o parser menos verboso */
literal: TK_LIT_INT
       | TK_LIT_FLOAT
       | TK_LIT_CHAR
       | TK_LIT_TRUE
       | TK_LIT_FALSE;

tipo_primitivo: TK_PR_INT
              | TK_PR_FLOAT
              | TK_PR_CHAR
              | TK_PR_BOOL;



%%
/* Declaração da função de erro */
void yyerror (const char *msg) {
    fprintf(stderr, "line %d: %s\n", get_line_number(), msg);
}

