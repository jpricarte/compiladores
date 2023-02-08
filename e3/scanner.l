 /* Integrantes
 	Eduardo Fantini
	Jordi Pujol Ricarte
 */
%{
	#include <iostream>
    #include <algorithm>
	#include <string>
	#include "parser.tab.h"
	#include "tree.hh"
%}

%option noyywrap
%option yylineno

special_char	[,;:\(\)\{\}\+\-\*\/\%\^\<\>=!\[\]]
literal_char	['][\\]?[^']?[']
literal_float 	[-]?[[:digit:]]+[\.][[:digit:]]+
literal_scifl   [-]?[[:digit:]]+[\.][[:digit:]]+[Ee][+-]?[[:digit:]]+
literal_int		[-]?[[:digit:]]+
identificador	[[:alpha:]]+

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
"int"   {
    yylval.valor_lexico = nullptr;
    return TK_PR_INT;
}
"float" {
    yylval.valor_lexico = nullptr;
    return TK_PR_FLOAT;
}
"bool"  {
    yylval.valor_lexico = nullptr;
    return TK_PR_BOOL;
}
"char"  {
    yylval.valor_lexico = nullptr;
    return TK_PR_CHAR;
}

"if" {
    yylval.valor_lexico = new Node(yylineno, TokenType::RESERVED_WORD, TokenVal("if"));
    return TK_PR_IF;
}
"then" {
    yylval.valor_lexico = nullptr;
    return TK_PR_THEN;
}
"else" {
    yylval.valor_lexico = nullptr;
    return TK_PR_ELSE;
}

"input" {
    yylval.valor_lexico = nullptr;
    return TK_PR_INPUT;
}
"output" {
    yylval.valor_lexico = nullptr;
    return TK_PR_OUTPUT;
}

"while" {
    yylval.valor_lexico = new Node(yylineno, TokenType::RESERVED_WORD, TokenVal("while"));
    return TK_PR_WHILE;
}


"return" {
    yylval.valor_lexico = new Node(yylineno, TokenType::RESERVED_WORD, TokenVal("return"));
    return TK_PR_RETURN;
}

"for" {
    yylval.valor_lexico = nullptr;
    return TK_PR_FOR;
}

"true" {
    yylval.valor_lexico = new Node(yylineno, TokenType::LIT_BOOL, TokenVal(true));
    return TK_LIT_TRUE;
}
"false" {
    yylval.valor_lexico = new Node(yylineno, TokenType::LIT_BOOL, TokenVal(false));
    return TK_LIT_FALSE;
}

 /* Operadores Condicionais */
"<=" {
    yylval.valor_lexico = new Node(yylineno, TokenType::COMPOSED_OPERATOR, TokenVal("<="));
    return TK_OC_LE;
}
">=" {
    yylval.valor_lexico = new Node(yylineno, TokenType::COMPOSED_OPERATOR, TokenVal(">="));
    return TK_OC_GE;
}
"==" {
    yylval.valor_lexico = new Node(yylineno, TokenType::COMPOSED_OPERATOR, TokenVal("=="));
    return TK_OC_EQ;
}
"!=" {
    yylval.valor_lexico = new Node(yylineno, TokenType::COMPOSED_OPERATOR, TokenVal("!="));
    return TK_OC_NE;
}
"&&" {
    yylval.valor_lexico = new Node(yylineno, TokenType::COMPOSED_OPERATOR, TokenVal("&&"));
    return TK_OC_AND;
}
"||" {
    yylval.valor_lexico = new Node(yylineno, TokenType::COMPOSED_OPERATOR, TokenVal("||"));
    return TK_OC_OR;
}

 /* Termos que precisam de RegEx: Identidificador e literais */
{identificador} {
    yylval.valor_lexico = new Node(yylineno, TokenType::IDENTIFIER, TokenVal(yytext));
	return TK_IDENTIFICADOR;
}
{literal_int} {
    yylval.valor_lexico = new Node(yylineno, TokenType::LIT_INT, TokenVal(std::stoi(yytext)));
	return TK_LIT_INT;
}
{literal_float} {
    yylval.valor_lexico = new Node(yylineno, TokenType::LIT_FLOAT, TokenVal(std::stof(yytext)));
	return TK_LIT_FLOAT;
}
{literal_scifl} {
    yylval.valor_lexico = new Node(yylineno, TokenType::LIT_FLOAT, TokenVal(std::stof(yytext)));
	return TK_LIT_FLOAT;
}
{literal_char} {
    std::string char_dec(yytext);
    std::erase(char_dec, '\'');
    yylval.valor_lexico = new Node(yylineno, TokenType::LIT_CHAR, TokenVal(char_dec[0]));
	return TK_LIT_CHAR;
}
 /* Caracteres especiais, retornam o próprio código ASCII */
{special_char} {
    yylval.valor_lexico = nullptr;
    // Ignora caracteres que não irão para a arvore sintática
    if (std::find(useless_chars.begin(), useless_chars.end(), yytext[0]) == useless_chars.end()) {
        yylval.valor_lexico = new Node(yylineno, TokenType::SPECIAL_CHAR, TokenVal(yytext[0]));
    }
	return (int) yytext[0];
}

 /* Caso não encaixe em nenhum padrão acima, retorna um erro com uma mensagem */
.	{return TK_ERRO;}

%%
