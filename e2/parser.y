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
var_global: TK_PR_INT lista_id_var_global ';'
	      | TK_PR_FLOAT lista_id_var_global ';'
	      | TK_PR_BOOL lista_id_var_global ';'
	      | TK_PR_CHAR lista_id_var_global ';';

lista_id_var_global: id_var_global
                   | lista_id_var_global ',' id_var_global;

id_var_global: TK_IDENTIFICADOR
             | TK_IDENTIFICADOR ':' lista_dimensoes;

lista_dimensoes: TK_LIT_INT
               | lista_dimensoes '^' TK_LIT_INT;

/* Definição de funções */
funcao: TK_PR_INT TK_IDENTIFICADOR '(' lista_parametros ')' corpo_funcao
      | TK_PR_FLOAT TK_IDENTIFICADOR '(' lista_parametros ')' corpo_funcao
      | TK_PR_BOOL TK_IDENTIFICADOR '(' lista_parametros ')' corpo_funcao
      | TK_PR_CHAR TK_IDENTIFICADOR '(' lista_parametros ')' corpo_funcao;

lista_parametros: %empty
                | parametro
                | lista_parametros ',' parametro;

parametro: TK_PR_INT TK_IDENTIFICADOR
         | TK_PR_FLOAT TK_IDENTIFICADOR
         | TK_PR_BOOL TK_IDENTIFICADOR
         | TK_PR_CHAR TK_IDENTIFICADOR;

corpo_funcao: bloco_comandos;

/* Bloco de comandos */
bloco_comandos: '{' lista_comandos '}'
              | %empty;

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
atribuicao: id_atribuicao '=' expressao;

id_atribuicao: TK_IDENTIFICADOR
             | TK_IDENTIFICADOR ':' lista_indices;

lista_indices: expressao
             | lista_indices '^' expressao;

/* Chamada de função */
cham_funcao: TK_IDENTIFICADOR '(' lista_argumentos ')';

lista_argumentos: %empty
                | expressao
                | lista_argumentos ',' expressao;

/* Controle de fluxo */
con_fluxo: '*';

/* Comando de fetorno */
op_retorno: '-';

/* Expressão (usado nos comandos simples) */
expressao: '%';

%%
/* Declaração da função de erro */
void yyerror (const char *msg) {
    fprintf(stderr, "line %d: %s\n", get_line_number(), msg);
}

