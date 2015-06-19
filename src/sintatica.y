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
	int tamanho;
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

void gera_mapa_cast();

stringstream cabecalho;

%}

%token TK_NUM
%token TK_REAL
%token TK_CHAR
%token TK_STRING
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_STRING
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
%token TK_SUBSUB
%token TK_TIPO_FLOAT
%token TK_TIPO_CHAR
%token TK_TIPO_BOOL
%token TK_LOGICO 
%token TK_AND TK_OR
%token TK_MENOR
%token TK_MAIOR
%token TK_MENOR_IGUAL
%token TK_MAIOR_IGUAL
%token TK_IGUAL
%token TK_DIFERENTE

%start S

%left TK_SOMA TK_SUB
%left TK_MUL TK_DIV

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO_NO_B
			{
				//ofstream myfile;
				//myfile.open ("example.c");
				//myfile << "Writing this to a file.\n";
				//printf(\"Resultado: %d\", " << tipo[contador] << ");\n\t 
				//cout << "$5.traducao";
				//cout << contador << "\n";

				//cout << $5.traducao << "\n\n";

				adiciona_biblioteca_cabecalho("stdio.h");
				adiciona_biblioteca_cabecalho("string.h");
				if(!erro) {
					//cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << $5.traducao << "\n\treturn 0;\n}" << endl; 
					cout << cabecalho.str() << "\nint main(void)\n" << $5.traducao << "\n\n\t" << endl; 
				} 
				//myfile.close();
			}
			;

BLOCO_NO_B	: TK_BEGIN COMANDOS TK_END
			{
				string variaveis = "";

				for (std::map<string, info_variavel>::iterator it=mapa_variavel.begin(); it!=mapa_variavel.end(); ++it)
    				if(it->second.tipo == "boolean")
    					variaveis += "\tint " + it->second.nome_temp + ";\n";
    				else if(it->second.tipo != "string")
    					variaveis += "\t" + it->second.tipo + " " + it->second.nome_temp + ";\n";

				$$.traducao = $1.traducao + variaveis + $2.traducao + $3.traducao;
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
/* PERMITIR EXPRESSÃO SEM VARIÁVEIS-------------------
COMANDO 	: E_OR
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
			}
			;
------------------------------------------------------*/
COMANDO 	: ATRIBUICAO
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
			}
			;

ATRIBUICAO  : TK_ID TK_ATR E_OR
			{

				string tipo = mapa_variavel[$1.label].tipo;

				if(mapa_operacoes[tipo+$2.label+$3.tipo].operando == 1)
					$$.traducao = "\t" + $3.traducao + "\n\t" + mapa_variavel[$1.label].nome_temp + " = " + "(" + mapa_operacoes[tipo+$2.label+$3.tipo].tipo + ")" + $3.label + ";\n";
				else if(mapa_operacoes[tipo+$2.label+$3.tipo].operando == 0)
					$$.traducao = "\t" + $3.traducao + "\n\t" + mapa_variavel[$1.label].nome_temp + " = " + $3.label + ";\n";
				else{
					erro = true;
					cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
				}

				if($3.tipo == "null" || $3.tipo == "")
				{
					erro = true;
					cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
				}
			}
			| TK_ID TK_ATR TK_LOGICO
			{
				$$.traducao = "\n\t" + mapa_variavel[$1.label].nome_temp + " = " + $3.traducao + ";\n";
			}
			| TK_ID TK_ATR TK_CHAR
			{
				
				$$.traducao = "\n\t" + mapa_variavel[$1.label].nome_temp + " = " + $3.label + ";\n";
			}
			;

DECLARACAO	: TK_TIPO_INT TK_ID TK_ATR E_REL
			{
				info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, $2.label) };

				if(mapa_operacoes[$1.label+$3.label+$4.tipo].operando == 1)
					$$.traducao = "\t" + $4.traducao + "\n\t" + atributos.nome_temp + " = " + "(" + mapa_operacoes[$1.label+$3.label+$4.tipo].tipo + ")" + $4.label + ";";
				else if(mapa_operacoes[$1.label+$3.label+$4.tipo].operando == 0)
					$$.traducao = "\t" + $4.traducao + "\n\t" + atributos.nome_temp + " = " + $4.label + ";";
				else{
					erro = true;
				}
				
			}
			| TK_TIPO_INT TK_ID
			{
				info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, $2.label)};

				$$.traducao = "\n\t" + atributos.nome_temp + " = " + "0" + ";";

			}
			| TK_TIPO_FLOAT TK_ID TK_ATR E_REL
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
				//$$.tipo = mapa_variavel[$2.label].tipo;

				//$$.tipo = $2.tipo;

			}
			| TK_TIPO_BOOL TK_ID TK_ATR E_OR
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
			| TK_TIPO_BOOL TK_ID
			{
				info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, $2.label) };

				$$.traducao = "\n\t" + atributos.nome_temp + " = " + "1" + ";";

			}
			| TK_TIPO_CHAR TK_ID TK_ATR TK_CHAR
			{
				info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, $2.label) };
				
				if(mapa_operacoes[$1.label+$3.label+$4.tipo].operando == 1)
					$$.traducao = "\n\t" + atributos.nome_temp + " = " + "(" + mapa_operacoes[$1.label+$3.label+$4.tipo].tipo + ")" + $4.label + ";";
				else if(mapa_operacoes[$1.label+$3.label+$4.tipo].operando == 0)
					$$.traducao = "\n\t" + atributos.nome_temp + " = " + $4.label + ";";
				else{
					erro = true;
				}
			}
			| TK_TIPO_CHAR TK_ID
			{
				info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, $2.label)};

				$$.traducao = "\n\t" + atributos.nome_temp + " = " + "\'\'" + ";";
			}
			;

			| TK_TIPO_STRING TK_ID TK_ATR TK_STRING
			{
				info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, $2.label) };
				
				if(mapa_operacoes[$1.label+$3.label+$4.tipo].operando == 1)
					$$.traducao = "\n\t" + atributos.nome_temp + " = " + "(" + mapa_operacoes[$1.label+$3.label+$4.tipo].tipo + ")" + $4.label + ";";
				else if(mapa_operacoes[$1.label+$3.label+$4.tipo].operando == 0)
				{
					stringstream tamanho;
					tamanho << $4.label.size() - 2;
					
					$$.traducao = "\n\t" + $1.label + " " + atributos.nome_temp + "[" + tamanho.str() + "];\n";
					$$.traducao += "\tstrcpy(" + atributos.nome_temp + ", " + $4.label + ");\n";
				}
				else{
					erro = true;
				}

			}
			| TK_TIPO_STRING TK_ID
			{
				info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, $2.label)};

				$$.traducao = "\n\t" + $1.label + " " + atributos.nome_temp + "[1];\n";
				$$.traducao += "\tstrcpy(" + atributos.nome_temp + ", \"\");\n";
			}
			;

E_OR		: E_OR TK_OR E_AND
			{
			
				string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo);
				$$.label = nome_variavel_temporaria;
				$$.tipo = mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo;
				$$.traducao = $1.traducao + $3.traducao + "\n\t" + $$.label + " = " +$1.label + " " + $2.traducao + " " + $3.label + ";\n";
			}
			| E_AND
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
				$$.tipo = $1.tipo;
				$$.tamanho = $1.tamanho;
			}
			;

E_AND	: 	E_AND TK_AND E_REL
			{
				string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo);
				$$.label = nome_variavel_temporaria;
				$$.tipo = mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo;

				$$.traducao = $1.traducao + $3.traducao + "\n\t" + $$.label + " = " +$1.label + " " + $2.traducao + " " + $3.label + ";\n";
			}
			| E_REL
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
				$$.tipo = $1.tipo;
				$$.tamanho = $1.tamanho;
			}
			;



E_REL		: E TK_REL_OP E
			{

				string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo);
				$$.label = nome_variavel_temporaria;

				$$.tipo = mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo;

				$$.traducao = $1.traducao + $3.traducao + "\n\t" + $$.label + " = " +$1.label + " " + $2.label + " " + $3.label + ";\n";
				
			}
			| E
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
				$$.tipo = $1.tipo;
				$$.tamanho = $1.tamanho;
			}
			;

E 			: E TK_ARIT_OP_S E_TEMP
			{
				if($1.tipo == "string" && $3.tipo == "string")	
				{
/*					string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo);
					$$.label = nome_variavel_temporaria;

					stringstream tamanho;
					tamanho << $1.label.size() + $3.label.size() - 4;
					
					$$.traducao = "\n\t" + nome_variavel_temporaria + "[" + tamanho.str() + "];\n"
					if(mapa_operacoes[$1.tipo+$2.label+$3.tipo].operando == 0) 
					{
						$$.traducao += $3.traducao + "\t" + $1.traducao + "\n\t";
						$$.traducao += "\tstrcpy(" + nome_variavel_temporaria + ", " + $1.label + ");\n";
						$$.traducao += "\tstrcpy(" + nome_variavel_temporaria + ", " + $3.label + ");\n";
					}
					else if(mapa_operacoes[$1.tipo+$2.label+$3.tipo].operando == 1) 
					{
						$$.traducao = $3.traducao + "\t" + $1.traducao + "\n\t" + nome_variavel_temporaria + " = " + "(" + mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo + ")" + $1.label + ";\n\t";
						$$.traducao += nome_variavel_temporaria + " = " + nome_variavel_temporaria + " " + $2.label + " " + $3.label + ";";
					} else {
						$$.traducao = $3.traducao + "\t" + $1.traducao + "\n\t" + nome_variavel_temporaria + " = " + "(" + mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo + ")" + $3.label + ";";
						$$.traducao += "\n\t" + nome_variavel_temporaria + " = " + $1.label + " " + $2.label + " " + nome_variavel_temporaria + ";";
					}
					$$.tipo = mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo;
*/
				} else
				{
					string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo);
					$$.label = nome_variavel_temporaria;

					if(mapa_operacoes[$1.tipo+$2.label+$3.tipo].operando == 0) {
						$$.traducao = $3.traducao + "\t" + $1.traducao + "\n\t" + nome_variavel_temporaria + " = " + $1.label + " " + $2.label + " " + $3.label + ";";
					}
					else if(mapa_operacoes[$1.tipo+$2.label+$3.tipo].operando == 1) 
					{
						$$.traducao = $3.traducao + "\t" + $1.traducao + "\n\t" + nome_variavel_temporaria + " = " + "(" + mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo + ")" + $1.label + ";\n\t";
						$$.traducao += nome_variavel_temporaria + " = " + nome_variavel_temporaria + " " + $2.label + " " + $3.label + ";";
					} else {
						$$.traducao = $3.traducao + "\t" + $1.traducao + "\n\t" + nome_variavel_temporaria + " = " + "(" + mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo + ")" + $3.label + ";";
						$$.traducao += "\n\t" + nome_variavel_temporaria + " = " + $1.label + " " + $2.label + " " + nome_variavel_temporaria + ";";
					}
					$$.tipo = mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo;
				}
			}
			| E_TEMP
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao;
				$$.tipo = $1.tipo;
				/*
				string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[$1.tipo].tipo);
				$$.label = nome_variavel_temporaria;
				$$.tipo = mapa_operacoes[$1.tipo].tipo;
				$$.traducao = $1.traducao + "\n\t" + nome_variavel_temporaria + " = " + $1.label+ ";";
				*/
			}
			;

E_TEMP		: E_TEMP TK_ARIT_OP_M UNAL
			{
				string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo);

				$$.label = nome_variavel_temporaria;

				cout << nome_variavel_temporaria << endl;

				if(mapa_operacoes[$1.tipo+$2.label+$3.tipo].operando == 0) 
				{
					$$.traducao = $3.traducao + $1.traducao + "\n\t" + nome_variavel_temporaria + " = " + $1.label + " " + $2.label + " " + $3.label + ";";
				} else if(mapa_operacoes[$1.tipo+$2.label+$3.tipo].operando == 1) 
				{
					$$.traducao = $3.traducao + "\t" + $1.traducao + "\n\t" + nome_variavel_temporaria + " = " + "(" + mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo + ")" + $1.label + ";\n\t";
					$$.traducao += nome_variavel_temporaria + " = " + nome_variavel_temporaria + " " + $2.label + " " + $3.label + ";";
				} else {
					$$.traducao = $3.traducao + "\t" + $1.traducao + "\n\t" + nome_variavel_temporaria + " = " + "(" + mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo + ")" + $3.label + ";";
					$$.traducao += "\n\t" + nome_variavel_temporaria + " = " + $1.label + " " + $2.label + " " + nome_variavel_temporaria + ";";
				}
				
				$$.tipo = mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo;
			}	
			| UNAL
			{
				
				$$.label = $1.label;
				$$.traducao = $1.traducao;
				$$.tipo = $1.tipo;
				
			};


UNAL		: TK_SUB VAL
			{
				$$.label = $1.label + $2.label;
				$$.tipo = $2.tipo;
				$$.traducao = "";
			}
			|TK_NOT VAL
			{
				$$.label = $1.label + $2.label;
				$$.tipo = $2.tipo;
				$$.traducao = "";
			}
			|TK_PLUSPLUS VAL
			{
				$$.label = $1.label + $2.label;
				$$.tipo = $2.tipo;
				$$.traducao = "";
			}
			|TK_SUBSUB VAL
			{
				$$.label = $1.label + $2.label;
				$$.tipo = $2.tipo;
				$$.traducao = "";
			}
			| VAL
			{
				$$.label = $1.label;
				$$.tipo = $1.tipo;
				$$.traducao = $1.traducao;
			}
			;

VAL			: '(' E_CAST ')' VAL
			{
				
				string nome_variavel_temporaria = gera_variavel_temporaria($2.tipo);
				$$.label = nome_variavel_temporaria;

				if(mapa_operacoes["("+$2.label+")"+$4.tipo].tipo == "null" || mapa_operacoes["("+$2.label+")"+$4.tipo].tipo == "")
				{
					erro = true;
					cout << "Erro na linha: " << nlinha << ". Cast inválido!\n";
				}
				else
				{
					$$.traducao = $4.traducao +"\n\t" + $$.label + " = "+ "(" + $2.label + ")"+ $4.label + ";";
				}
					$$.tipo = $2.tipo;

			}
			| '(' E_OR ')'
			{
				$$.label = $2.label;
				$$.traducao = $2.traducao;
				$$.tipo = $2.tipo;
			}
			| TK_NUM
			{
				
				string nome_variavel_temporaria = gera_variavel_temporaria($1.tipo);
				$$.label = nome_variavel_temporaria;
				$$.tipo = $1.tipo;
				$$.traducao ="\n\t" + nome_variavel_temporaria + " = " + $1.label + ";";
				
			}
			| TK_REAL
			{
				string nome_variavel_temporaria = gera_variavel_temporaria($1.tipo);
				$$.label = nome_variavel_temporaria;
				$$.tipo = $1.tipo;
				$$.traducao ="\n\t" + nome_variavel_temporaria + " = " + $1.label + ";";
			}
			| TK_CHAR
			{	
				string nome_variavel_temporaria = gera_variavel_temporaria($1.tipo);
				$$.label = nome_variavel_temporaria;
				$$.tipo = $1.tipo;
				$$.traducao ="\n\t" + nome_variavel_temporaria + " = " + $1.label + ";";
			}
			|TK_ID
			{
				if(mapa_variavel.find($1.label) == mapa_variavel.end()) {
					cout << "Erro na linha " << nlinha <<": Variável \"" << $1.label << "\" não declarada." << endl << endl;

					erro = true;
				}

				$$.label = mapa_variavel[$1.label].nome_temp;
				$$.traducao = "";
				$$.tipo = mapa_variavel[$1.label].tipo;
				
			}
			;


E_CAST		: TK_TIPO_FLOAT
			{
				$$.traducao = $1.traducao;
				$$.label = $1.label;
				$$.tipo = "float";
			}
			| TK_TIPO_INT
			{
				$$.traducao = $1.traducao;
				$$.label = $1.label;
				$$.tipo = "int";
			}
			| TK_TIPO_CHAR
			{
				$$.traducao = $1.traducao;
				$$.label = $1.label;
				$$.tipo = "char";
			}
			| TK_TIPO_BOOL
			{
				$$.traducao = $1.traducao;
				$$.label = $1.label;
				$$.tipo = "boolean";
			}
			;


TK_REL_OP	: TK_MENOR
			{
				$$.traducao = $1.traducao;
				$$.label = $1.label;
			}
			| TK_MAIOR
			{
				$$.traducao = $1.traducao;
				$$.label = $1.label;
			}
			| TK_MENOR_IGUAL
			{
				$$.traducao = $1.traducao;
				$$.label = $1.label;
			}
			| TK_MAIOR_IGUAL
			{
				$$.traducao = $1.traducao;
				$$.label = $1.label;
			}
			| TK_IGUAL
			{
				$$.traducao = $1.traducao;
				$$.label = $1.label;
			}
			| TK_DIFERENTE
			{
				$$.traducao = $1.traducao;
				$$.label = $1.label;
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
		cout << "Erro na linha " << nlinha <<": Você já declarou a variável \"" << nome << "\"." << endl << endl;
		erro = true;
	}


	return nome_temporario.str();
}

void gera_mapa_cast() {
	FILE* file2 = fopen("./src/mapa_cast.txt", "r");
	
	char chave[30] = "";
	
	char resultado[20] = "";
	int operando;
	
	while(fscanf(file2, "%s\t%s\t%d\n", chave, resultado, &operando)) {
		
		info_operacoes cast = {resultado, operando};
		mapa_operacoes[chave] = cast;
		
		if(feof(file2)) {
			break;
		}
	}
	
	fclose(file2);
}

void adiciona_biblioteca_cabecalho(string nome_biblioteca) {
	cabecalho << "#include <" << nome_biblioteca << ">" << endl;
}

int main( int argc, char* argv[] )
{
	gera_mapa_cast();
	yyparse();

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << " on line " << nlinha << endl;
	exit (0);
}				
