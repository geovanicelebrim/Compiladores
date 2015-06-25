%{
#include <string>
#include <sstream>

using namespace std;

%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]


DELIM {ESPACO}+
NUM {DIGITO}+
REAL {NUM}+("."{NUM}+)?
CHAR \'({LETRA}|{NUM})\'


STRING {LETRA}?\"(\\.|[^\\"])*\"|{LETRA}?\'(\\.|[^\\'])*\'

ID {LETRA}({LETRA}|{NUM})*

%%

"\n"		{
				nlinha++;
			}

"#".*\n 	{}


"="			{
				yylval.label = yytext;
				return TK_ATR;
			}

"const"		{
				yylval.traducao = yytext;
				yylval.label = yytext;

				return TK_CONST;
			}

"begin"		{
				yylval.traducao = "\n{\n";
				yylval.label = yytext;

				return TK_BEGIN;
			}

"end"		{
				yylval.traducao = "\n}\n";
				yylval.label = yytext;

				return TK_END;
			}

{DELIM} 	{}

"main"		{return TK_MAIN;}


"function"		{return TK_FUNCTION;}


"int"		{
				yylval.label = yytext;
				return TK_TIPO_INT;
			}

"float"		{
				yylval.label = yytext;
				return TK_TIPO_FLOAT;
			}

"char"		{
				yylval.label = yytext;
				return TK_TIPO_CHAR;
			}

"boolean"	{
				yylval.traducao = "int";
				yylval.label = yytext;
				return TK_TIPO_BOOL;
			}

"string"	{
				yylval.traducao = "char";
				yylval.label = yytext;
				return TK_TIPO_STRING;
			}

[(){}[\];,]	{ return *yytext; }

"++"		{
				yylval.traducao = yytext;
				yylval.label = yytext;
				return TK_PLUSPLUS;
			}

"--"		{
				yylval.traducao = yytext;
				yylval.label = yytext;
				return TK_SUBSUB;
			}

"+"			{
				yylval.traducao = yytext;
				yylval.label = yytext;
				return TK_SOMA;
			}

"-"			{
				yylval.traducao = yytext;
				yylval.label = yytext;
				return TK_SUB;
			}

"*"			{
				yylval.traducao = yytext;
				yylval.label = yytext;
				return TK_MUL;
			}

"/"			{
				yylval.traducao = yytext;
				yylval.label = yytext;
				return TK_DIV;
			}

"!"			{
				yylval.traducao = yytext;
				yylval.label = yytext;
				return TK_NOT;
			}

"<"			{
				yylval.traducao = yytext;
				yylval.label = yytext;
				return TK_MENOR;
			}

">"			{
				yylval.traducao = yytext;
				yylval.label = yytext;
				return TK_MAIOR;
			}

"<="		{
				yylval.traducao = yytext;
				yylval.label = yytext;
				return TK_MENOR_IGUAL;
			}

">="		{
				yylval.traducao = yytext;
				yylval.label = yytext;
				return TK_MAIOR_IGUAL;
			}

"=="		{
				yylval.traducao = yytext;
				yylval.label = yytext;
				return TK_IGUAL;
			}

"!="		{
				yylval.traducao = yytext;
				yylval.label = yytext;
				return TK_DIFERENTE;
			}

"and"		{
				yylval.traducao = "&&";
				yylval.label = yytext;
				return TK_AND;
			}
"or"		{
				yylval.traducao = "|";
				yylval.label = yytext;
				return TK_OR;
			}
{NUM}		{	
				yylval.traducao = yytext;
				yylval.label = yytext;
				yylval.tipo = "int";
				return TK_NUM;
			}

{REAL}		{	
				yylval.traducao = yytext;
				yylval.label = yytext;
				yylval.tipo = "float";
				return TK_REAL;
			}
			
{CHAR}		{	
				yylval.traducao = yytext;
				yylval.label = yytext;
				yylval.tipo = "char";
				return TK_CHAR;
			}			

{STRING}	{	
				yylval.traducao = yytext;
				yylval.label = yytext;
				yylval.tipo = "string";
				yylval.tamanho = ((string)yytext).size() - 2;
				return TK_STRING;
			}			

"true"		{	
				yylval.traducao = "1";
				yylval.label = yytext;
				yylval.tipo = "boolean";
				return TK_LOGICO;
			}

"false"		{	
				yylval.traducao = "0";
				yylval.label = yytext;
				yylval.tipo = "boolean";
				return TK_LOGICO;
			}

"while"		{
				yylval.traducao = yytext;
				yylval.label = yytext;
				return TK_WHILE;
			}

{ID}		{ yylval.label = yytext; return TK_ID; }
.			{ *yytext; }

%%

