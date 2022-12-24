 /* Integrantes
 	Eduardo Fantini
	Jordi Pujol Ricarte
 */
%{
	#include <stdio.h>
	#include "parser.tab.h"
%}

%option noyywrap
%option yylineno

special_char	[,;:\(\)\{\}\+\-\*\/\%\^\<\>=!]
literal_char	['][\\]?[[:graph:]]?[']
literal_float 	[+-]?[[:digit:]]+[\.][[:digit:]]+
literal_scifl   [+-]?[[:digit:]]+[\.][[:digit:]]+[Ee][+-]?[[:digit:]]+

%x comment

%%
 /* Coisas para serem ignoradas: Comentários e Espaços */
[[:space:]] 			{}
"//"[^\n]* 				{}
"/*"					{BEGIN(comment);}
<comment>[[:space:]] 	{}
<comment>[^*\n]*        {} /* Tudo que não for * é ignorado*/
<comment>"*"+[^*/\n]*   {} /* Tudo que é * e não é seguido de / */
<comment>"*"+"/"  		{BEGIN(INITIAL);} /* Termina comentários, pode sair */

 /* Palavras Reservadas da linguagem, incluindo literais True e False */
"int"			{return TK_PR_INT;}
"float"			{return TK_PR_FLOAT;}
"bool"			{return TK_PR_BOOL;}
"char"			{return TK_PR_CHAR;}
"if"			{return TK_PR_IF;}
"then"			{return TK_PR_THEN;}
"else"			{return TK_PR_ELSE;}
"while"			{return TK_PR_WHILE;}
"input"			{return TK_PR_INPUT;}
"output"		{return TK_PR_OUTPUT;}
"return"		{return TK_PR_RETURN;}
"for"			{return TK_PR_FOR;}

"true"			{return TK_LIT_TRUE;}
"false"			{return TK_LIT_FALSE;}

 /* Operadores Condicionais */
"<="			{return TK_OC_LE;}
">="			{return TK_OC_GE;}
"=="			{return TK_OC_EQ;}
"!="			{return TK_OC_NE;}
"&&"			{return TK_OC_AND;}
"||"			{return TK_OC_OR;}

 /* Termos que precisam de RegEx: Identidificador e literais */
[[:alpha:]]+		{return TK_IDENTIFICADOR;}
[+-]?[[:digit:]]+	{return TK_LIT_INT;}
{literal_float}		{return TK_LIT_FLOAT;}
{literal_scifl}		{return TK_LIT_FLOAT;}
{literal_char}		{return TK_LIT_CHAR;}

 /* Caracteres especiais, retornam o próprio código ASCII */
{special_char}		{return (int) yytext[0];}

 /* Caso não encaixe em nenhum padrão acima, retorna um erro com uma mensagem */
.	{	
		return TK_ERRO;
	}

%%
