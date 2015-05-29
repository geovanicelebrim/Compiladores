%{
#include <iostream>
#include <string>
//#include <fstream>
#include <sstream>
#include <map>

#define YYSTYPE _atributos

using namespace std;

int nlinha = 1;

// Estrutura dos atributos de um token

typedef struct
{
	string label;
	string traducao;
	string tipo;
} _atributos;

// Variável que indica se ocorreram erros ao compilar o programa

bool erro = false;

int yylex(void);
void yyerror(string);

// Estrutura de informações de uma variável

typedef struct _info_variavel
{
	string tipo;
	string nome_temp;

} info_variavel;

// Estrutura de operações

typedef struct _info_operacoes
{
	string tipo;
	int operando;

} info_operacoes;

// Mapa de variáveis

map<string, info_variavel> mapa_variavel = map<string, info_variavel>();

// Mapa de operações

map<string, info_operacoes> mapa_operacoes = map<string, info_operacoes>();

// Função para gerar nomes temporários para as variáveis

string gera_variavel_temporaria(string tipo, string nome="");

void adiciona_biblioteca_cabecalho(string nome_biblioteca);

stringstream cabecalho;

%}

%token TK_NUM
%token TK_REAL
%token TK_MAIN TK_ID TK_TIPO_INT
%token TK_CONST 
%token TK_TYPE TK_ENDTYPE
%token TK_VAR TK_ENDVAR
%token TK_PROCEDURE
%token TK_FUNCTION
%token TK_ATR
%token TK_SOMA TK_SUB 
%token TK_MUL TK_DIV
%token TK_BEGIN TK_END
%token TK_FIM TK_ERROR
%token TK_NOT
%token TK_PLUSPLUS
%token TK_TIPO_FLOAT
%token TK_TIPO_CHAR
%token TK_TIPO_BOOL
%token TK_LOGICO TK_AND TK_OR

%start S

%left TK_SOMA TK_SUB
%left TK_MUL TK_DIV

%%

S 			: TK_TIPO_INT TK_MAIN'(' ')' TK_BEGIN BLOCO_NO_B
			{
				//ofstream myfile;
				//myfile.open ("example.c");
				//myfile << "Writing this to a file.\n";
				//printf(\"Resultado: %d\", " << tipo[contador] << ");\n\t 
				//cout << "$5.traducao";
				//cout << contador << "\n";

				//cout << $5.traducao << "\n\n";

				adiciona_biblioteca_cabecalho("stdio.h");

				string variaveis = "";

				for (std::map<string, info_variavel>::iterator it=mapa_variavel.begin(); it!=mapa_variavel.end(); ++it)
    				variaveis += "\t" + it->second.tipo + " " + it->second.nome_temp + ";\n";

				if(!erro) {
					//cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << $5.traducao << "\n\treturn 0;\n}" << endl; 
					cout << cabecalho.str() << "\nint main(void)\n" << $5.traducao << variaveis << $6.traducao << "\n\n\t" << endl; 
				} 
				//myfile.close();
			}
			;

BLOCO_NO_B	: COMANDOS TK_END
			{
				
				$$.traducao = $1.traducao + $2.traducao;
			}
			;

COMANDOS	: COMANDO ';' COMANDOS {
				$$.traducao = $1.traducao + $3.traducao;
			}
			|
			{
				$$.traducao = "";
				$$.label = "";
			}
			;

COMANDO 	: DECLARACAO
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
			}
			;

COMANDO 	: E
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
			}
			;

COMANDO 	: ATRIBUICAO
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
			}
			;

ATRIBUICAO  : TK_ID TK_ATR E
			{
				$$.traducao = "\t" + $3.traducao + "\n\t" + mapa_variavel[$1.label].nome_temp + " = " + $3.label;				
			}

DECLARACAO	: TK_TIPO_INT TK_ID TK_ATR E
//Declarao de int!
			{
				info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, $2.label) };

				if(mapa_operacoes[$1.label+$3.label+$4.tipo].operando == 1)
					$$.traducao = "\t" + $4.traducao + "\n\t" + atributos.nome_temp + " = " + "(" + mapa_operacoes[$1.label+$3.label+$4.tipo].tipo + ")" + $4.label + ";";
				else if(mapa_operacoes[$1.label+$3.label+$4.tipo].operando == 0)
					$$.traducao = "\t" + $4.traducao + "\n\t" + atributos.nome_temp + " = " + $4.label + ";";
				else{
					erro = true;
					cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
				}
				
			}
			| TK_TIPO_INT TK_ID
			{
				info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, $2.label)};

				$$.traducao = "\n\t" + atributos.nome_temp + " = " + "0" + ";";

			}
			| TK_TIPO_FLOAT TK_ID TK_ATR E
			{
				info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, $2.label)};

				if(mapa_operacoes[$1.label+$3.label+$4.tipo].operando == 1)
					$$.traducao = "\t" + $4.traducao + "\n\t" + atributos.nome_temp + " = " + "(" + mapa_operacoes[$1.label+$3.label+$4.tipo].tipo + ")" + $4.label + ";";
				else if(mapa_operacoes[$1.label+$3.label+$4.tipo].operando == 0)
					$$.traducao = "\t" + $4.traducao + "\n\t" + atributos.nome_temp + " = " + $4.label + ";";
				else{
					erro = true;
					cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
				}
			}
			| TK_TIPO_FLOAT TK_ID
			{
				info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, $2.label) };

				$$.traducao = "\n\t" + atributos.nome_temp + " = " + "0.0" + ";";

			}
			;

E 			: E TK_ARIT_OP_S E_TEMP
			{
				string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo);
				$$.label = nome_variavel_temporaria;

				if(mapa_operacoes[$1.tipo+$2.label+$3.tipo].operando == 0)
					$$.traducao = $3.traducao + "\t" + $1.traducao + "\n\t" + nome_variavel_temporaria + " = " + $1.label + " " + $2.label + " " + $3.label + ";";
				else if(mapa_operacoes[$1.tipo+$2.label+$3.tipo].operando == 1)
					$$.traducao = $3.traducao + "\t" + $1.traducao + "\n\t" + nome_variavel_temporaria + " = " + "(" + mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo + ")" + $1.label + " " + $2.label + " " + $3.label + ";";
				else
					$$.traducao = $3.traducao + "\t" + $1.traducao + "\n\t" + nome_variavel_temporaria + " = " + $1.label + " " + $2.label + " " + "(" + mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo + ")" + $3.label + ";";
				$$.tipo = mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo;


			}
			| E_TEMP
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
			}
			;

E_TEMP		: E_TEMP TK_ARIT_OP_M UNAL
			{
				string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo);

				$$.label = nome_variavel_temporaria;

				if(mapa_operacoes[$1.tipo+$2.label+$3.tipo].operando == 0)
					$$.traducao = $1.traducao + "\n\t" + nome_variavel_temporaria + " = " + $1.label + " " + $2.label + " " + $3.label + ";";
				else if(mapa_operacoes[$1.tipo+$2.label+$3.tipo].operando == 1)
					$$.traducao = $1.traducao + "\n\t" + nome_variavel_temporaria + " = " + "(" + mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo + ")" + $1.label + " " + $2.label + " " + $3.label + ";";
				else
					$$.traducao = $1.traducao + "\n\t" + nome_variavel_temporaria + " = " + $1.label + " " + $2.label + " " + "(" + mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo + ")" + $3.label + ";";
				
				$$.tipo = mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo;
			}	
			| UNAL
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
			};
UNAL		: TK_SUB VAL
			{
				$$.label = $1.label + $2.label;
				$$.traducao = "";
			}
			|TK_NOT VAL
			{
				$$.label = $1.label + $2.label;
				$$.traducao = "";
			}
			|TK_PLUSPLUS VAL
			{
				$$.label = $1.label + $2.label;
				$$.traducao = "";
			}
			| VAL
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
			}
			;

VAL			: TK_NUM
			{
				$$.label = $1.label;
				$$.traducao = "";
			}
			| TK_REAL
			{
				$$.label = $1.label;
				$$.traducao = "";
			}
			| TK_ID
			{
				if(mapa_variavel.find($1.label) == mapa_variavel.end()) {
					cout << "Erro na linha " << nlinha <<": Que porra de variável \"" << $1.label << "\" é essa?" << endl << endl;

					erro = true;
				}

				$$.label = mapa_variavel[$1.label].nome_temp;
				$$.traducao = $$.label;
			}
			;

TK_ARIT_OP_S: TK_SOMA
			{
				$$.traducao = $1.traducao;
				$$.label = $1.label;
			}
			| TK_SUB 
			{
				$$.traducao = $1.traducao;
				$$.label = $1.label;
			};

TK_ARIT_OP_M: TK_MUL
			{
				$$.traducao = $1.traducao;
				$$.label = $1.label;
			}
			| TK_DIV
			{
				$$.traducao = $1.traducao;
				$$.label = $1.label;
			}
			;


%%

#include "lex.yy.c"

int yyparse();

int contador = 0;

string gera_variavel_temporaria(string tipo, string nome) {

	stringstream nome_temporario;
	string nome_aux;

	nome_temporario << "temp_" << tipo << "_";

	if (!nome.empty()) {
		nome_temporario << nome << "_" << contador;
		nome_aux = nome;
	} else {
		nome_temporario << "EXP_" << contador;
		nome_aux = nome_temporario.str();
	}

	contador++;


	info_variavel atributos = {tipo, nome_temporario.str()};
	if(mapa_variavel.find(nome_aux) == mapa_variavel.end()) {
		mapa_variavel[nome_aux] = atributos;
			
	} else {
		cout << "Erro na linha " << nlinha <<": Você já declarou a variável \"" << nome << "\", animal!" << endl << endl;
		erro = true;
	}


	return nome_temporario.str();
}

void adiciona_biblioteca_cabecalho(string nome_biblioteca) {
	cabecalho << "#include <" << nome_biblioteca << ">" << endl;
}

int main( int argc, char* argv[] )
{
	
//Terminar de fazer a tabela
	mapa_operacoes["int=float"] = {"null", -1};
	mapa_operacoes["int+float"] = {"float", 1};
	mapa_operacoes["float=int"] = {"float", 1};
	mapa_operacoes["float*int"] = {"float", 2};	

	yyparse();

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << " on line " << nlinha << endl;
	exit (0);
}				
