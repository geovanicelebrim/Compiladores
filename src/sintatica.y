%{
#include <iostream>
#include <string>
//#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <stack>

#define YYSTYPE _atributos

using namespace std;

int nlinha = 1;
int nivel = -1;

// Estrutura dos atributos de um token

typedef struct
{
    string label;
    string traducao;
    string tipo;
    int tamanho;
} _atributos;

bool erro = false;
int yylex(void);
void yyerror(string);

// Estrutura de informações de uma variável
typedef struct _info_variavel
{
    string tipo;
    string nome_temp;
    int tamanho;
} info_variavel;

// Estrutura de operações
typedef struct _info_operacoes
{
    string tipo;
    int operando;
} info_operacoes;

// Mapa de variáveis
map<string, info_variavel> mapa_variaveis = map<string, info_variavel>();
map<string, string> mapa_variaveis_declaracao = map<string, string>();

vector< map<string, info_variavel> > pilha_variaveis = vector< map<string, info_variavel> >();
// Mapa de operações
map<string, info_operacoes> mapa_operacoes = map<string, info_operacoes>();
stack<string> pilha_labels_loop = stack<string>();
stack<string> pilha_labels_condicional = stack<string>();
// Função para gerar nomes temporários para as variáveis
string gera_variavel_temporaria(string tipo, string nome="", int tamanho=0);
void adiciona_biblioteca_cabecalho(string nome_biblioteca);
void gera_mapa_cast();
info_variavel buscaID(string id);
void alteraID(string id, info_variavel nova_varivavel);
string geraLabel();

stringstream cabecalho;

%}

%token TK_NUM TK_REAL TK_CHAR TK_STRING TK_ID
%token TK_MAIN  TK_BEGIN TK_END
%token TK_ATR TK_SOMA TK_SUB TK_MUL TK_DIV TK_LOGICO TK_AND TK_OR TK_MENOR TK_MAIOR TK_MENOR_IGUAL TK_MAIOR_IGUAL TK_IGUAL TK_DIFERENTE TK_NOT TK_PLUSPLUS TK_SUBSUB
%token TK_TIPO_INT TK_TIPO_STRING TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOL TK_CONST
%token TK_FUNCTION
%token TK_WHILE TK_FOR TK_DO TK_IF TK_ELSE TK_ELIF
%token TK_WRITE TK_READ
%token TK_GLOBAL

%start S

%left TK_SOMA TK_SUB
%left TK_MUL TK_DIV

%%
S           : TK_TIPO_INT TK_MAIN '(' ')' BLOCO
            {
                //ofstream myfile;
                //myfile.open ("example.c");
                //myfile << "Writing this to a file.\n";
                //printf(\"Resultado: %d\", " << tipo[contador] << ");\n\t 
                //cout << "$5.traducao";
                //cout << contador << "\n";

                //cout << $5.traducao << "\n\n";
                stringstream variaveis;
                for (std::map<string, string>::iterator it=mapa_variaveis_declaracao.begin(); it!=mapa_variaveis_declaracao.end(); ++it)
                        variaveis << it->second;
                adiciona_biblioteca_cabecalho("stdio.h");
                adiciona_biblioteca_cabecalho("string.h");
                if(!erro) {
                    //cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << $5.traducao << "\n\treturn 0;\n}" << endl; 
                    cout << cabecalho.str() << "\nint main(void)\n{\n" << variaveis.str() << $5.traducao << "\n}\n\t" << endl; 
                } 
                //myfile.close();
            }
            ;

BLOCO   	: BEGIN COMANDOS END
            {
                
                int i;
                for(i = 0; i < pilha_variaveis.size(); i++)
                for (std::map<string, info_variavel>::iterator it=pilha_variaveis[i].begin(); it!=pilha_variaveis[i].end(); ++it)
                {
                    stringstream variaveis;
                    if(it->second.tipo == "boolean")
                        variaveis << "\tint " << it->second.nome_temp << ";\n";
                    else if(it->second.tipo == "string")
                        variaveis << "\tchar " << it->second.nome_temp << "[" << it->second.tamanho << "];\n";
                    else if(it->second.tipo != "")
                        variaveis << "\t" << it->second.tipo << " " << it->second.nome_temp << ";\n";
                    if(mapa_variaveis_declaracao.find(variaveis.str()) == mapa_variaveis_declaracao.end())
                    {
                        mapa_variaveis_declaracao[variaveis.str()] = variaveis.str();
                    }
                }

                
                $$.traducao = $2.traducao;
                nivel--;
                pilha_variaveis.pop_back();
            };

BEGIN       : TK_BEGIN
            {
                nivel++;
                pilha_variaveis.push_back(mapa_variaveis);
                $$.traducao = $1.traducao;
            };

END         : TK_END
            {
                mapa_variaveis.clear();
                $$.traducao = $1.traducao;
            };

COMANDOS    : COMANDO ';' COMANDOS 
            {
                $$.traducao = $1.traducao + $3.traducao;
            }
            |
            {
                $$.traducao = "";
                $$.label = "";
            }
            | BLOCO COMANDOS
            {
                $$.traducao = $1.traducao + $2.traducao;
            }
            ;

COMANDO     : DECLARACAO
            {
                $$.label = $1.label;
                $$.traducao = $1.traducao;
            }
            ;

COMANDO     : E_OR
            {
                $$.label = $1.label;
                $$.traducao = $1.traducao;
            }
            ;

COMANDO     : UNAL_OP
            {
                $$.label = $1.label;
                $$.traducao = $1.traducao;
            };
//---------------------------------

COMANDO     : TK_WRITE E_OR
            {
                $$.label = $2.label;
                $$.traducao = $2.traducao + "\n\tcout << " + $2.label + ";\n";
            }
            | TK_READ TK_ID
            {
                info_variavel var = buscaID($2.label);
                $$.label = var.nome_temp;
                $$.traducao = "\n\tcin >> " + var.nome_temp + ";\n\t";
                $$.tipo = var.tipo;
                if(var.tipo == "string")
                    $$.tamanho = 1024;
                else
                    $$.tamanho = var.tamanho;
            }
            ;

//---------------------------------

//---------------------------LOOP-------------------------------------------------

COMANDO     : LOOP
            {
                $$.label = $1.label;
                $$.traducao = $1.traducao;
            }
            ;

LOOP        : D BLOCO TK_WHILE '(' E_OR ')' 
            {
                if($5.tipo != "boolean")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                }

                string a = geraLabel();
                pilha_labels_loop.push(a); pilha_labels_loop.push(a);

                $$.traducao = "\n\n" + pilha_labels_loop.top() + ":\n\n\t" + $2.traducao + $5.traducao;
                pilha_labels_loop.pop();
                $$.traducao += "\n\tif(" + $5.label + ") goto " + pilha_labels_loop.top() + ";\n"; 
                pilha_labels_loop.pop();
            }
            | FOR BLOCO
            {
                $$.traducao = "\n\n" + $1.traducao + $2.traducao + pilha_labels_loop.top();
                pilha_labels_loop.pop();
                $$.traducao += "\n\tgoto " + pilha_labels_loop.top() + ";\n";
                pilha_labels_loop.pop();
                $$.traducao += "\n" + pilha_labels_loop.top() + ":\n";
                pilha_labels_loop.pop();
            }
            |WHILE BLOCO
            {

                $$.traducao = "\n\n" + $1.traducao + $2.traducao + "\n\tgoto " + pilha_labels_loop.top() + ";\n";
                pilha_labels_loop.pop();
                $$.traducao += "\n" + pilha_labels_loop.top() + ":\n";
                pilha_labels_loop.pop();
            }; 

WHILE       : W '(' E_OR ')'
            {

                if($3.tipo != "boolean")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                }

                
                string a = geraLabel();
                string b = geraLabel();
                pilha_labels_loop.push(a); pilha_labels_loop.push(b); pilha_labels_loop.push(a); pilha_labels_loop.push(b);
                
                $$.traducao = "\n" + pilha_labels_loop.top() + ":\n\t" + $3.traducao + "\t";
                pilha_labels_loop.pop();
                $$.traducao += $3.label + " = !" + $3.label + ";\n\tif(" + $3.label + ") goto " + pilha_labels_loop.top() + ";\n"; 
                pilha_labels_loop.pop();

            };
W           : TK_WHILE
            {
                nivel++;
                pilha_variaveis.push_back(mapa_variaveis);
            };

FOR         : F '(' ATRIBUICAO ';' E_OR ';' ATRIBUICAO ')'
            {
                if($5.tipo != "boolean")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                }
                string a = geraLabel();
                string b = geraLabel();
                pilha_labels_loop.push(a); pilha_labels_loop.push(b); pilha_labels_loop.push(a); pilha_labels_loop.push(b);

                $$.traducao = $3.traducao + pilha_labels_loop.top() + ":\n\t" + $5.traducao + "\t";
                pilha_labels_loop.pop();
                $$.traducao += $5.label + " = !" + $5.label + ";\n\tif(" + $5.label + ") goto " + pilha_labels_loop.top() + ";\n";
                pilha_labels_loop.pop();
                pilha_labels_loop.push($7.traducao);
            };

F           : TK_FOR
            {
                nivel++;
                pilha_variaveis.push_back(mapa_variaveis);
            };

D           : TK_DO
            {
                nivel++;
                pilha_variaveis.push_back(mapa_variaveis);
            };

//------------------CONDICIONAL----------------------------------------------------------

COMANDO     : CONDICIONAL
            {
                $$.label = $1.label;
                $$.traducao = $1.traducao;
            };

CONDICIONAL : IF BLOCO
			{
				pilha_labels_condicional.pop();
                $$.traducao = "\n\n" + $1.traducao + $2.traducao + "\n" + pilha_labels_condicional.top() + ":\n";
                pilha_labels_condicional.pop(); pilha_labels_condicional.pop();
			}
			| IF BLOCO ELSE BLOCO
			{
				$$.traducao = "\n\n" + $1.traducao + $2.traducao + "\ngoto " + pilha_labels_condicional.top() + ";\n\t";
				pilha_labels_condicional.pop();
				$$.traducao += "\n" + pilha_labels_condicional.top() + ":\n" + $4.traducao;
                pilha_labels_condicional.pop();
                $$.traducao += "\n" + pilha_labels_condicional.top() + ":\n";
                pilha_labels_condicional.pop();
			};

ELSE 		: TK_ELSE
			{
				nivel++;
                pilha_variaveis.push_back(mapa_variaveis);
			}

IF 			: I '(' E_OR ')' 
			{
				if($3.tipo != "boolean")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                }

                string a = geraLabel();
                string b = geraLabel();
                pilha_labels_condicional.push(a); pilha_labels_condicional.push(b); pilha_labels_condicional.push(a); pilha_labels_condicional.push(b);
        
                $$.traducao = $3.traducao + "\t" + $3.label + " = !" + $3.label + ";\n\tif(" + $3.label + ") goto " + pilha_labels_condicional.top() + ";\n"; 
                pilha_labels_condicional.pop();

			};

I 			: TK_IF
			{
				nivel++;
                pilha_variaveis.push_back(mapa_variaveis);
			};

//----------------------------------------------------------------------------

COMANDO     : ATRIBUICAO
            {
                $$.label = $1.label;
                $$.traducao = $1.traducao;
            }
            ;

ATRIBUICAO  : TK_ID TK_ATR E_OR
            {
            	if((buscaID($1.label).tipo == "string" && $3.tipo == "string")||(buscaID($1.label).tipo == "string" && $3.tipo == "char"))
                {
                    info_variavel var = buscaID($1.label);
                    var.tamanho = $3.tamanho;   alteraID($1.label, var);                 
                    $$.traducao = "\t" + $3.traducao + "\n\tstrcpy(" + buscaID($1.label).nome_temp + ", " + $3.label + ");\n";
                }
                else    
                {
                    string tipo = buscaID($1.label).tipo;

                    if(mapa_operacoes[tipo+$2.label+$3.tipo].operando == 1)
                        $$.traducao = "\t" + $3.traducao + "\n\t" + buscaID($1.label).nome_temp + " = " + "(" + mapa_operacoes[tipo+$2.label+$3.tipo].tipo + ")" + $3.label + ";\n";
                    else if(mapa_operacoes[tipo+$2.label+$3.tipo].operando == 0)
                        $$.traducao = "\t" + $3.traducao + "\n\t" + buscaID($1.label).nome_temp + " = " + $3.label + ";\n";
                    else{
                        erro = true;
                        cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
                    }
                }
                if($3.tipo == "null" || $3.tipo == "")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
                }
            }
            | TK_ID TK_ATR UNAL_OP
            {
            	$$.traducao = $3.traducao + "\n\t" + buscaID($1.label).nome_temp + " = " + $3.label + ";\n";
            }
            | TK_GLOBAL TK_ID TK_ATR E_OR
            {
            	info_variavel var = pilha_variaveis[0][$2.label];
                if(var.nome_temp == "")
                {
                	erro = true;
                	cout << "Erro na linha " << nlinha <<": Variável \"" << $2.label << "\" não declarada." << endl << endl;
                }
            	if($4.tipo == "null" || $4.tipo == "")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
                }
            	if((var.tipo == "string" && $4.tipo == "string")||(var.tipo == "string" && $4.tipo == "char"))
                {
                    var.tamanho = $3.tamanho;   alteraID($2.label, var);                 
                    $$.traducao = "\t" + $4.traducao + "\n\tstrcpy(" + buscaID($1.label).nome_temp + ", " + $4.label + ");\n";
                }
                else    
                {
                    string tipo = var.tipo;

                    if(mapa_operacoes[tipo+$3.label+$4.tipo].operando == 1)
                        $$.traducao = "\t" + $4.traducao + "\n\t" + var.nome_temp + " = " + "(" + mapa_operacoes[tipo+$3.label+$4.tipo].tipo + ")" + $4.label + ";\n";
                    else if(mapa_operacoes[tipo+$3.label+$4.tipo].operando == 0)
                        $$.traducao = "\t" + $4.traducao + "\n\t" + var.nome_temp + " = " + $4.label + ";\n";
                    else{
                        erro = true;
                        cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
                    }
                }
            }
            | TK_GLOBAL TK_ID TK_ATR UNAL_OP
            {
            	info_variavel var = pilha_variaveis[0][$2.label];
                if(var.nome_temp == "")
                {
                	erro = true;
                	cout << "Erro na linha " << nlinha <<": Variável \"" << $2.label << "\" não declarada." << endl << endl;
                }
            	if($4.tipo == "null" || $4.tipo == "")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
                }
            	$$.traducao = $4.traducao + "\n\t" + var.nome_temp + " = " + $4.label + ";\n";
            };

DECLARACAO  : TK_TIPO_INT TK_ID TK_ATR E_REL
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
                info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, $2.label)};
                $$.traducao = "\n\t" + atributos.nome_temp + " = " + "0.0" + ";";
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
                info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, $2.label)};
                $$.traducao = "\n\t" + atributos.nome_temp + " = " + "1" + ";";
            }
            | TK_TIPO_CHAR TK_ID TK_ATR TK_CHAR
            {
                info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, $2.label,1)};
                
                if(mapa_operacoes[$1.label+$3.label+$4.tipo].operando == 1)
                    $$.traducao = "\n\t" + atributos.nome_temp + " = " + "(" + mapa_operacoes[$1.label+$3.label+$4.tipo].tipo + ")" + $4.label + ";";
                else if(mapa_operacoes[$1.label+$3.label+$4.tipo].operando == 0)
                    $$.traducao = "\n\t" + atributos.nome_temp + " = " + $4.label + ";";
                else{
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
                }
            }
            | TK_TIPO_CHAR TK_ID
            {
                info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, $2.label,1)};
                $$.traducao = "\n\t" + atributos.nome_temp + " = " + "\'\'" + ";";
            }
            | TK_TIPO_STRING TK_ID TK_ATR E
            {
                info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, $2.label, $4.tamanho)};
                if((mapa_operacoes[$1.label+$3.label+$4.tipo].operando == 0) && (mapa_operacoes[$1.label+$3.label+$4.tipo].tipo != ""))
                {
                    $$.traducao = $4.traducao + "\n\tstrcpy(" + atributos.nome_temp + ", " + $4.label + ");\n";
                }
                else
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
                }
            }
            | TK_TIPO_STRING TK_ID
            {
                info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, $2.label,0)};
                $$.traducao = "\n\tstrcpy(" + atributos.nome_temp + ", \"\");\n";
            };

E_OR        : E_OR TK_OR E_AND
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
            };

E_AND   	: E_AND TK_AND E_REL
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
            };

E_REL       : E TK_REL_OP E
            {
            	if(mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo == "" || mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo == "null")
            	{
            		erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
            	}
            	if(($1.tipo == "string") && ($3.tipo == "string"))
            	{
            		//Maior
            		string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo);
	                $$.label = nome_variavel_temporaria;
	                $$.tipo = mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo;
	                if($2.label == ">")
	                {
	                	$$.traducao = $1.traducao + $3.traducao + "\n\t" + nome_variavel_temporaria + " = strcmp(" +$1.label + ", " + $3.label + ");\n";		
	                	$$.traducao += "\tif(" + nome_variavel_temporaria + " > 0) " + nome_variavel_temporaria + " = 1;\n";
	                	$$.traducao += "\tif(" + nome_variavel_temporaria + " == 0) " + nome_variavel_temporaria + " = 0;\n";
	                	$$.traducao += "\tif(" + nome_variavel_temporaria + " < 0) " + nome_variavel_temporaria + " = 0;\n";
	                } else if ($2.label == "<")
	                {
	                	$$.traducao = $1.traducao + $3.traducao + "\n\t" + nome_variavel_temporaria + " = strcmp(" +$1.label + ", " + $3.label + ");\n";		
	                	$$.traducao += "\tif(" + nome_variavel_temporaria + " > 0) " + nome_variavel_temporaria + " = 0;\n";
	                	$$.traducao += "\tif(" + nome_variavel_temporaria + " == 0) " + nome_variavel_temporaria + " = 0;\n";
	                	$$.traducao += "\tif(" + nome_variavel_temporaria + " < 0) " + nome_variavel_temporaria + " = 1;\n";
	                } else if ($2.label == "==")
	                {
	                	$$.traducao = $1.traducao + $3.traducao + "\n\t" + nome_variavel_temporaria + " = strcmp(" +$1.label + ", " + $3.label + ");\n";		
	                	$$.traducao += "\tif(" + nome_variavel_temporaria + " > 0) " + nome_variavel_temporaria + " = 0;\n";
	                	$$.traducao += "\tif(" + nome_variavel_temporaria + " == 0) " + nome_variavel_temporaria + " = 1;\n";
	                	$$.traducao += "\tif(" + nome_variavel_temporaria + " < 0) " + nome_variavel_temporaria + " = 0;\n";
	                } else if ($2.label == "!=")
	                {
	                	$$.traducao = $1.traducao + $3.traducao + "\n\t" + nome_variavel_temporaria + " = strcmp(" +$1.label + ", " + $3.label + ");\n";		
	                	$$.traducao += "\tif(" + nome_variavel_temporaria + " > 0) " + nome_variavel_temporaria + " = 1;\n";
	                	$$.traducao += "\tif(" + nome_variavel_temporaria + " == 0) " + nome_variavel_temporaria + " = 0;\n";
	                	$$.traducao += "\tif(" + nome_variavel_temporaria + " < 0) " + nome_variavel_temporaria + " = 1;\n";
	                } else if ($2.label == ">=")
	                {
	                	$$.traducao = $1.traducao + $3.traducao + "\n\t" + nome_variavel_temporaria + " = strcmp(" +$1.label + ", " + $3.label + ");\n";		
	                	$$.traducao += "\tif(" + nome_variavel_temporaria + " > 0) " + nome_variavel_temporaria + " = 1;\n";
	                	$$.traducao += "\tif(" + nome_variavel_temporaria + " == 0) " + nome_variavel_temporaria + " = 1;\n";
	                	$$.traducao += "\tif(" + nome_variavel_temporaria + " < 0) " + nome_variavel_temporaria + " = 0;\n";
	                } else if ($2.label == "<=")
	                {
	                	$$.traducao = $1.traducao + $3.traducao + "\n\t" + nome_variavel_temporaria + " = strcmp(" +$1.label + ", " + $3.label + ");\n";		
	                	$$.traducao += "\tif(" + nome_variavel_temporaria + " > 0) " + nome_variavel_temporaria + " = 0;\n";
	                	$$.traducao += "\tif(" + nome_variavel_temporaria + " == 0) " + nome_variavel_temporaria + " = 1;\n";
	                	$$.traducao += "\tif(" + nome_variavel_temporaria + " < 0) " + nome_variavel_temporaria + " = 1;\n";
	                }
            	}
            	else
            	{
	                string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo);
	                $$.label = nome_variavel_temporaria;
	                $$.tipo = mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo;
	                $$.traducao = $1.traducao + $3.traducao + "\n\t" + nome_variavel_temporaria + " = " +$1.label + " " + $2.label + " " + $3.label + ";\n";
	            }
            }
            | E
            {
                $$.label = $1.label;
                $$.traducao = $1.traducao;
                $$.tipo = $1.tipo;
                $$.tamanho = $1.tamanho;
            };

E           : E TK_ARIT_OP_S E_TEMP
            {
                if(($1.tipo == "string" && $3.tipo == "string")||($1.tipo == "string" && $3.tipo == "char")||($1.tipo == "char" && $3.tipo == "string"))
                {
                    string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo, "", $1.tamanho+$3.tamanho);
                    $$.label = nome_variavel_temporaria;

                    $$.tamanho = $1.tamanho+$3.tamanho;
                    if(mapa_operacoes[$1.tipo+$2.label+$3.tipo].operando == 0) 
                    {
                        $$.traducao = $3.traducao + "\t" + $1.traducao + "\n";
                        $$.traducao += "\tstrcpy(" + nome_variavel_temporaria + ", strcat(" + $1.label + ", " + $3.label + "));\n";
                    }
                    else if (mapa_operacoes[$1.tipo+$2.label+$3.tipo].operando != 0 || mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo == "")
                    {
                        erro = true;
                        cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                    }
                    $$.tipo = "string";

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

                    if (mapa_operacoes[$1.tipo+$2.label+$3.tipo].operando != 0 || mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo == "")
                    {
                        erro = true;
                        cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                    }
                    $$.tipo = mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo;
                }
            }
            | E_TEMP
            {
                $$.label = $1.label;
                $$.traducao = $1.traducao;
                $$.tipo = $1.tipo;
                $$.tamanho = $1.tamanho;
            };

E_TEMP      : E_TEMP TK_ARIT_OP_M UNAL
            {
                string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo);
                $$.label = nome_variavel_temporaria;

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

                if (mapa_operacoes[$1.tipo+$2.label+$3.tipo].operando != 0 || mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo == "")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                }
                $$.tipo = mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo;
            }   
            | UNAL
            {
                
                $$.label = $1.label;
                $$.traducao = $1.traducao;
                $$.tipo = $1.tipo;
                $$.tamanho = $1.tamanho;
            };

UNAL_OP		: TK_NOT E_OR
			{
				if ($2.tipo != "boolean")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                }
                $$.label = $2.label;
                $$.traducao = "\n\t" + $2.traducao + "\n\t" + $2.label + " = !" + $2.label + ";\n";
                $$.tipo = $2.tipo;
                $$.tamanho = $2.tamanho;
			}
			| TK_PLUSPLUS TK_ID
            {
                info_variavel var = buscaID($2.label);
                $$.label = var.nome_temp;
                $$.traducao = "\n\t" + var.nome_temp + " = " + var.nome_temp + " + 1;\n";
                $$.tipo = var.tipo;
                $$.tamanho = var.tamanho;
                
            }
            | TK_SUBSUB TK_ID
            {
                info_variavel var = buscaID($2.label);
                $$.label = var.nome_temp;
                $$.traducao = "\n\t" + var.nome_temp + " = " + var.nome_temp + " - 1;\n";
                $$.tipo = var.tipo;
                $$.tamanho = var.tamanho;
            };

UNAL        : TK_SUB VAL
            {
                if ($2.tipo == "boolean" || $2.tipo == "string" || $2.tipo == "char")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                }
                $$.label = $1.label + $2.label;
                $$.tipo = $2.tipo;
                $$.traducao = "";
            }
            | VAL
            {
                $$.label = $1.label;
                $$.tipo = $1.tipo;
                $$.traducao = $1.traducao;
                $$.tamanho = $1.tamanho;
            };

VAL         : '(' E_CAST ')' VAL
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
                $$.tamanho = 1;
                $$.traducao ="\n\t" + nome_variavel_temporaria + " = " + $1.label + ";";
            }
            | TK_LOGICO
            {   
                string nome_variavel_temporaria = gera_variavel_temporaria($1.tipo);
                $$.label = nome_variavel_temporaria;
                $$.tipo = $1.tipo;
                $$.traducao ="\n\t" + nome_variavel_temporaria + " = " + $1.traducao + ";\n";
            }
            | TK_STRING
            {   
                string nome_variavel_temporaria = gera_variavel_temporaria($1.tipo, "", $1.tamanho);
                $$.label = nome_variavel_temporaria;
                $$.tipo = $1.tipo;
                $$.traducao = "\n\tstrcpy(" + nome_variavel_temporaria + ", " + $1.label + ");";
            }
            | TK_ID
            {
                info_variavel var = buscaID($1.label);
                $$.label = var.nome_temp;
                $$.traducao = "";
                $$.tipo = var.tipo;
                $$.tamanho = var.tamanho;
            }
            | TK_GLOBAL TK_ID
            {
                info_variavel var = pilha_variaveis[0][$2.label];
                if(var.nome_temp == "")
                {
                	erro = true;
                	cout << "Erro na linha " << nlinha <<": Variável \"" << $2.label << "\" não declarada." << endl << endl;
                }
                $$.label = var.nome_temp;
                $$.traducao = "";
                $$.tipo = var.tipo;
                $$.tamanho = var.tamanho;
            };

E_CAST      : TK_TIPO_FLOAT
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

TK_REL_OP   : TK_MENOR
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

string gera_variavel_temporaria(string tipo, string nome, int tamanho) 
{

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

    info_variavel atributos = {tipo, nome_temporario.str(), tamanho};
    if(pilha_variaveis[nivel].find(nome_aux) == pilha_variaveis[nivel].end()) {
        pilha_variaveis[nivel][nome_aux] = atributos;

    } else {
        cout << "Erro na linha " << nlinha <<": Você já declarou a variável \"" << nome << "\"." << endl << endl;
        erro = true;
    }
    return nome_temporario.str();
}

info_variavel buscaID(string id)
{
    int i;
    bool existeVariavel;
    for(i = nivel; i > -1; i--)
    {

        if(pilha_variaveis[i][id].nome_temp == "")
        {
            existeVariavel = false;
        }
        else
        {
            existeVariavel = true;
            return pilha_variaveis[i][id];
        }
    }
    if(!existeVariavel)
    {
        cout << "Erro na linha " << nlinha <<": Variável \"" << id << "\" não declarada." << endl << endl;
        erro = true;
        info_variavel var = {"","",-1};
        return var;
    }
}

void alteraID(string id, info_variavel nova_varivavel)
{
    int i;
    bool existeVariavel;
    for(i = nivel; i > -1; i--)
    {

        if(pilha_variaveis[i][id].nome_temp == "")
        {
            existeVariavel = false;
        }
        else
        {
            existeVariavel = true;
            pilha_variaveis[i][id] = nova_varivavel;
            break;
        }
    }
    if(!existeVariavel)
    {
        cout << "Erro na linha " << nlinha <<": Variável \"" << id << "\" não declarada." << endl << endl;
        erro = true;
    }
}

string geraLabel()
{
    stringstream nome_temporario;
    nome_temporario << "temp_Label_" << contador;
    contador++;
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

void adiciona_biblioteca_cabecalho(string nome_biblioteca)
{
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
