%{
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <stack>

#define YYSTYPE _atributos

using namespace std;
static const size_t npos = -1;

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
    string nome_lista;
    string acesso_lista;
} info_variavel;

typedef struct _info_args
{
    string tipo;
    string nome;
} info_args;

typedef struct _info_func
{
    string tipo;
    string nome_temp;
    vector<string> parametros;
} info_func;

// Estrutura de operações
typedef struct _info_operacoes
{
    string tipo;
    int operando;
} info_operacoes;

// Mapa de variáveis
map<string, info_variavel> mapa_variaveis = map<string, info_variavel>();
map<string, string> mapa_variaveis_declaracao = map<string, string>();

map<string, info_func> mapa_func = map<string, info_func>();

vector< map<string, info_variavel> > pilha_variaveis = vector< map<string, info_variavel> >();
// Mapa de operações
map<string, info_operacoes> mapa_operacoes = map<string, info_operacoes>();
stack<string> pilha_labels_loop = stack<string>();
stack<string> pilha_labels_condicional = stack<string>();

vector<string> pilha_inicio_loop = vector<string>();
vector<string> pilha_fim_loop = vector<string>();
stack<string> label_final = stack<string>();
// Função para gerar nomes temporários para as variáveis
string gera_variavel_temporaria(string tipo, string nome="", int tamanho=0);
string gera_ID_funcao(string tipo, string nome);
void adiciona_biblioteca_cabecalho(string nome_biblioteca);
void gera_mapa_cast();
info_variavel buscaID(string id);
void alteraID(string id, info_variavel nova_varivavel);
string geraLabel();
string incluiLista();
bool lista = false;


string fun_temp;
vector<string> argumentos = vector<string>();

vector<string> vet_temp = vector<string>();

stringstream cabecalho;

%}

%token TK_NUM TK_REAL TK_CHAR TK_STRING TK_ID TK_MAIN TK_BEGIN TK_END TK_TIPO_INT TK_TIPO_STRING TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOL
%token TK_ATR TK_SOMA TK_SUB TK_MUL TK_DIV TK_LOGICO TK_AND TK_OR TK_MENOR TK_MAIOR TK_MENOR_IGUAL TK_MAIOR_IGUAL TK_IGUAL TK_DIFERENTE
%token TK_NOT TK_PLUSPLUS TK_SUBSUB TK_WHILE TK_FOR TK_DO TK_IF TK_ELSE TK_ELIF TK_BREAK TK_CONTINUE TK_SUPERBREAK TK_SUPERCONTINUE
%token TK_WRITE TK_WRITELN TK_READ TK_GLOBAL TK_FUNCTION TK_RETURN TK_FUNC

%start S

%left TK_SOMA TK_SUB
%left TK_MUL TK_DIV

%%
S           : FUNC TK_TIPO_INT TK_MAIN '(' ')' BLOCO
            {
                ofstream myfile;
                myfile.open ("example.c");
 
                stringstream variaveis;
                for (std::map<string, string>::iterator it=mapa_variaveis_declaracao.begin(); it!=mapa_variaveis_declaracao.end(); ++it)
                        variaveis << it->second;
                adiciona_biblioteca_cabecalho("stdio.h");
                adiciona_biblioteca_cabecalho("string.h");
                adiciona_biblioteca_cabecalho("stdlib.h");
                adiciona_biblioteca_cabecalho("iostream");

                string code;
                if(!erro)
                {
                    
                    if(lista)
                    {
                    	code = cabecalho.str() + "\nusing namespace std;\n\n" + incluiLista() + variaveis.str() + $1.traducao + "\n\nint main(void)\n{\n" + $6.traducao + "\n\treturn 0;\n}\n\n"; 
                    	
                    	while(code.find("\n;\n") != npos)
                    		code.replace(code.find("\n;\n"), 3, "");
                    	
                    	cout << code;
                    	myfile << code;
                    }
                    else
                    {
                    	code = cabecalho.str() + "\nusing namespace std;\n\n" + variaveis.str() + $1.traducao + "\n\nint main(void)\n{\n" + $6.traducao + "\n\treturn 0;\n}\n\n"; 
                    	
                    	while(code.find("\n;\n") != npos)
                    		code.replace(code.find("\n;\n"), 3, "");

                    	cout << code;
                    	myfile << code;
                    }
                } 
                myfile.close();
            };

FUNC 		: FUNC TK_FUNCTION TID '(' ARGUMENTOS ')' BLOCO
			{
				
				$$.traducao = $1.traducao + "\nvoid " + $3.traducao + "(" + $5.traducao + ")\n{\n\t" + $7.traducao + "\n}\n";
			}
			| FUNC TK_FUNCTION TID '(' ARGUMENTOS ')' BEGIN COMANDOS TK_RETURN E_OR ';' END
			{
				if($3.tipo != $10.tipo)
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Retorno inválido!\n";
                }

				$$.traducao = $1.traducao + "\n" + $3.traducao + "(" + $5.traducao + ")\n{\n\t" + $8.traducao + $10.traducao + "\n\treturn " + $10.label + ";\n}\n";

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
                    
                    if(it->second.nome_lista.size() > 0)
                    	variaveis.str("");

                    if(mapa_variaveis_declaracao.find(variaveis.str()) == mapa_variaveis_declaracao.end())
                    {
                        mapa_variaveis_declaracao[variaveis.str()] = variaveis.str();
                    }
                }

                nivel--;
                pilha_variaveis.pop_back();
			}
			|{ $$.traducao = "";};

TID 		: TIPO TK_ID
			{
				fun_temp = $2.label;
				string nome_temp = gera_ID_funcao($1.label, $2.label);
				$$.traducao = $1.label + " " + nome_temp;
				$$.tipo = $1.label;
				$$.label = nome_temp;
				mapa_func[$2.label].parametros = vector<string>();

			}
			| TK_ID
			{
				string nome_temporario = gera_ID_funcao("void", $1.label);
				$$.label = $1.label;
				$$.traducao = nome_temporario;
				$$.tipo = $1.tipo;
				$$.tamanho = $1.tamanho;
				fun_temp = $1.label;
				mapa_func[$1.label].parametros = vector<string>();
			};

ARGUMENTOS	: ARGUMENTOS ',' TIPO TK_ID
			{
				mapa_func[fun_temp].parametros.push_back($3.label);
				$$.traducao = $1.traducao + ", " + $3.label + " " + $4.label;
			}
			| TIPO TK_ID
			{
				mapa_func[fun_temp].parametros.push_back($1.label);
				$$.traducao = $1.label + " " + $2.label;

			}
			|{ $$.traducao = "";};

TIPO 		: TK_TIPO_STRING
			{
				$$.label = $1.label;
			}
			| TK_TIPO_INT
			{
				$$.label = $1.label;
			}	
			| TK_TIPO_BOOL
			{
				$$.label = $1.label;
			}
			| TK_TIPO_FLOAT
			{
				$$.label = $1.label;
			}
			| TK_TIPO_CHAR
			{
				$$.label = $1.label;
			};

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
                    
                    if(it->second.nome_lista.size() > 0)
                    	variaveis.str("");

                    if(mapa_variaveis_declaracao.find(variaveis.str()) == mapa_variaveis_declaracao.end())
                    {
                        mapa_variaveis_declaracao[variaveis.str()] = variaveis.str();
                    }
                }

                while(($2.traducao.find(";") == 0) || ($2.traducao.find("\n") == 0))
            		$2.traducao.replace(0,1,"");

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

COMANDO 	: | TK_FUNC TK_ID '(' PARAMETROS ')'
            {
            	if(mapa_func[$2.label].nome_temp == "")
                {
                	erro = true;
                	cout << "Erro na linha " << nlinha <<": Função \"" << $2.label << "\" não declarada." << endl << endl;
                }

                int i;
                if(mapa_func[$2.label].parametros.size() == argumentos.size())
                {
                	for(i = 0; i < argumentos.size(); i++)
                	{
                		if(mapa_func[$2.label].parametros[i] != argumentos[i])
                		{
                			erro = true;
                			cout << "Erro na linha " << nlinha <<": Parâmetros inválidos, verifique os tipos." << endl << endl;
                			break;
                		}
                	}
                }
                else
                {
                	erro = true;
                	cout << "Erro na linha " << nlinha <<": Número de parâmetros incorreto." << endl << endl;
                }
                argumentos.erase(argumentos.begin(), argumentos.end());

                info_func var = mapa_func[$2.label];
                $$.label = var.nome_temp + "(" + $4.traducao + ")";
                $$.traducao = $4.label + "\n\t" + var.nome_temp + "(" + $4.traducao + ");\n";
                $$.tipo = var.tipo;
                //$$.tamanho = var.tamanho;
            };

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

COMANDO 	: TK_BREAK
			{
				if(pilha_fim_loop.size() > 0)
					$$.traducao = "\n\tgoto " + pilha_fim_loop.back() + ";\n";
				else
				{
					erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
				}

			}
			| TK_CONTINUE
			{
				if(pilha_inicio_loop.size() > 0)
					$$.traducao = "\n\tgoto " + pilha_inicio_loop.back() + ";\n";
				else
				{
					erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
				}
			}
			| TK_SUPERBREAK
			{
				if(pilha_fim_loop.size() > 0)
					$$.traducao = "\n\tgoto " + pilha_fim_loop[0] + ";\n";
				else
				{
					erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
				}
			}
			| TK_SUPERCONTINUE
			{
				if(pilha_inicio_loop.size() > 0)
					$$.traducao = "\n\tgoto " + pilha_inicio_loop[0] + ";\n";
				else
				{
					erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
				}
			};

COMANDO     : TK_WRITE WRITE
            {
                $$.label = $2.label;
                $$.traducao = $2.traducao;
            }
            | TK_WRITELN WRITE
            {
                $$.label = $2.label;
                $$.traducao = $2.traducao + "\n\tcout << endl;\n";
            }
            | TK_READ TK_ID
            {
                info_variavel var = buscaID($2.label);
                $$.label = var.nome_temp;
                $$.tipo = var.tipo;
                if(var.tipo == "string")
                {
                    $$.tamanho = 1024;
                    var.tamanho = 1024;
                    alteraID($2.label, var);
                    $$.traducao = "\n\tcin.getline(" + var.nome_temp + ", 1024);\n\t";
                }
                else
                {
                	$$.traducao = "\n\tcin >> " + var.nome_temp + ";\n\t";
                    $$.tamanho = var.tamanho;
                }
            };

WRITE 		: WRITE ',' E_OR
			{
				$$.label = $3.label;
				$$.traducao = $1.traducao + $3.traducao + "\n\tcout << " + $3.label + ";\n";
			}
			| E_OR
			{
				$$.label = $1.label;
				$$.traducao = $1.traducao + "\n\tcout << " + $1.label + ";\n";
			};

COMANDO     : LOOP
            {
                $$.label = $1.label;
                $$.traducao = $1.traducao;
            };

LOOP        : D BLOCO TK_WHILE '(' E_OR ')' 
            {
                if($5.tipo != "boolean")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                }

                $$.traducao = "\n\n" + pilha_labels_loop.top() + ":\n\n\t" + $2.traducao + $5.traducao;
                pilha_labels_loop.pop();
                $$.traducao += "\n\tif(" + $5.label + ") goto " + pilha_labels_loop.top() + ";\n"; 
                pilha_labels_loop.pop();
                $$.traducao += pilha_labels_loop.top() + ":\n";
                pilha_labels_loop.pop();
                pilha_inicio_loop.pop_back();
                pilha_fim_loop.pop_back();

            }
            | FOR BLOCO
            {

            	

                $$.traducao = "\n\n" + $1.traducao + $2.traducao + pilha_labels_loop.top();
                pilha_labels_loop.pop();
                $$.traducao += "\n\tgoto " + pilha_labels_loop.top() + ";\n";
                pilha_labels_loop.pop();
                $$.traducao += "\n" + pilha_labels_loop.top() + ":\n";
                pilha_labels_loop.pop();
                pilha_inicio_loop.pop_back();
                pilha_fim_loop.pop_back();
            }
            |WHILE BLOCO
            {

                $$.traducao = "\n\n" + $1.traducao + $2.traducao + "\n\tgoto " + pilha_labels_loop.top() + ";\n";
                pilha_labels_loop.pop();
                $$.traducao += "\n" + pilha_labels_loop.top() + ":\n";
                pilha_labels_loop.pop();
                pilha_inicio_loop.pop_back();
                pilha_fim_loop.pop_back();
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
                pilha_inicio_loop.push_back(pilha_labels_loop.top());
                pilha_fim_loop.push_back(a);
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
                pilha_inicio_loop.push_back(pilha_labels_loop.top());
                pilha_fim_loop.push_back(a);
                $$.traducao = $3.traducao + pilha_labels_loop.top() + ":\n\t" + $5.traducao + "\t";
                pilha_labels_loop.pop();
                $$.traducao += $5.label + " = !" + $5.label + ";\n\tif(" + $5.label + ") goto " + pilha_labels_loop.top() + ";\n";
                pilha_labels_loop.pop();
                pilha_labels_loop.push($7.traducao);
            }
            | F '(' ATRIBUICAO ';' E_OR ';' UNAL_OP ')'
            {
                if($5.tipo != "boolean")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                }
                string a = geraLabel();
                string b = geraLabel();
                pilha_labels_loop.push(a); pilha_labels_loop.push(b); pilha_labels_loop.push(a); pilha_labels_loop.push(b);
                pilha_inicio_loop.push_back(pilha_labels_loop.top());
                pilha_fim_loop.push_back(a);
                $$.traducao = $3.traducao + pilha_labels_loop.top() + ":\n\t" + $5.traducao + "\t";
                pilha_labels_loop.pop();
                $$.traducao += $5.label + " = !" + $5.label + ";\n\tif(" + $5.label + ") goto " + pilha_labels_loop.top() + ";\n";
                pilha_labels_loop.pop();
                pilha_labels_loop.push($7.traducao);
            }
            | F '(' DECLARACAO ';' E_OR ';' UNAL_OP ')'
            {
                if($5.tipo != "boolean")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                }
                string a = geraLabel();
                string b = geraLabel();
                pilha_labels_loop.push(a); pilha_labels_loop.push(b); pilha_labels_loop.push(a); pilha_labels_loop.push(b);
                pilha_inicio_loop.push_back(pilha_labels_loop.top());
                pilha_fim_loop.push_back(a);
                $$.traducao = $3.traducao + "\n" + pilha_labels_loop.top() + ":\n\t" + $5.traducao + "\t";
                pilha_labels_loop.pop();
                $$.traducao += $5.label + " = !" + $5.label + ";\n\tif(" + $5.label + ") goto " + pilha_labels_loop.top() + ";\n";
                pilha_labels_loop.pop();
                pilha_labels_loop.push($7.traducao);
            }
            | F '(' DECLARACAO ';' E_OR ';' ATRIBUICAO ')'
            {
                if($5.tipo != "boolean")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                }
                string a = geraLabel();
                string b = geraLabel();
                pilha_labels_loop.push(a); pilha_labels_loop.push(b); pilha_labels_loop.push(a); pilha_labels_loop.push(b);
                pilha_inicio_loop.push_back(pilha_labels_loop.top());
                pilha_fim_loop.push_back(a);
                $$.traducao = $3.traducao + "\n" + pilha_labels_loop.top() + ":\n\t" + $5.traducao + "\t";
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
            	string a = geraLabel(); string b = geraLabel();
                pilha_labels_loop.push(b); pilha_labels_loop.push(a);	pilha_labels_loop.push(a);
                pilha_inicio_loop.push_back(pilha_labels_loop.top());
                pilha_fim_loop.push_back(b);
                nivel++;
                pilha_variaveis.push_back(mapa_variaveis);
            };

COMANDO     : CONDICIONAL
            {
                $$.label = $1.label;
                $$.traducao = $1.traducao;
            };

CONDICIONAL : IF BLOCO ELIF ELSE
			{
                $$.traducao = "\n\n" + $1.traducao + $2.traducao + "\ngoto " + label_final.top() + ";\n" + pilha_labels_condicional.top() + ":\n";
                pilha_labels_condicional.pop();
                label_final.pop();
               	$$.traducao += $3.traducao + $4.traducao + label_final.top() + ":\n";
			};

ELSE 		: TK_ELSE BLOCO
			{
				$$.traducao = $2.traducao;
			}
			|
			{
				$$.traducao = "";
			};

ELIF 		: ELIF TK_ELIF '(' E_OR ')' BLOCO
			{
				if($4.tipo != "boolean")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                }

                string a = geraLabel();
                label_final.push(label_final.top());	label_final.push(label_final.top());
                pilha_labels_condicional.push(a); pilha_labels_condicional.push(a);
        
                $$.traducao = "\n\t" + $1.traducao + "\n\t" + $4.traducao + "\t" + $4.label + " = !" + $4.label + ";\n\tif(" + $4.label + ") goto " + pilha_labels_condicional.top() + ";\n"; 
                pilha_labels_condicional.pop();
                $$.traducao += $6.traducao + "\ngoto " + label_final.top() + ";\n" + pilha_labels_condicional.top() + ":\n";
                pilha_labels_condicional.pop();
                label_final.pop();
			}
			|
			{
				$$.traducao = "";
			};

IF 			: I '(' E_OR ')' 
			{
				if($3.tipo != "boolean")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                }


                string a = geraLabel();	string b = geraLabel();
                label_final.push(a);	label_final.push(a);
                pilha_labels_condicional.push(b); pilha_labels_condicional.push(b);
        
                $$.traducao = $3.traducao + "\t" + $3.label + " = !" + $3.label + ";\n\tif(" + $3.label + ") goto " + pilha_labels_condicional.top() + ";\n"; 
                pilha_labels_condicional.pop();

			};

I 			: TK_IF
			{
				nivel++;
                pilha_variaveis.push_back(mapa_variaveis);
			};

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
            	//Rever isto aqui...---------------------------------
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
            }
            | TK_ID VET_INDICE TK_ATR E_OR
            {
            	string var_temp = gera_variavel_temporaria("int");
            	info_variavel var = buscaID($1.label);
            	var.acesso_lista = geraLabel();
            	alteraID($1.label, var);

            	string acesso_lista = "\n\tnode *" + buscaID($1.label).acesso_lista + ";\n\t" + buscaID($1.label).acesso_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID($1.label).acesso_lista + ");\n\tif(!" + buscaID($1.label).acesso_lista + ") cout << \"Sem memoria disponivel!\\n\";";
            	for (int i = 0; i < vet_temp.size(); ++i)
            	{
            		acesso_lista += "\n\tinsereFim(" + buscaID($1.label).acesso_lista + ", " + vet_temp[i] + ");";
            	}
            	vet_temp.clear();

            	if(mapa_operacoes[$1.tipo+$3.label+$4.tipo].operando == 1)
            	{
                    $$.traducao = $2.traducao + $4.traducao + "\n\t" + acesso_lista + "\n\t" + var_temp + " = mapper(" + buscaID($1.label).acesso_lista + ", " + buscaID($1.label).nome_lista + ");\n\t" + buscaID($1.label).nome_temp + "[" + var_temp +  "] = (" + mapa_operacoes[$1.tipo+$3.label+$4.tipo].tipo + ")" + $4.label + ";\n";
            	}
                else if(mapa_operacoes[$1.tipo+$3.label+$4.tipo].operando == 0)
                    $$.traducao = $2.traducao + $4.traducao + "\n\t" + acesso_lista + "\n\t" + var_temp + " = mapper(" + buscaID($1.label).acesso_lista + ", " + buscaID($1.label).nome_lista + ");\n\t" + buscaID($1.label).nome_temp + "[" + var_temp +  "] = " + $4.label + ";\n";
                else{
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
                }
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
            | TK_TIPO_INT TK_ID VET_DIMENSAO
            {
            	lista = true;
            	gera_variavel_temporaria($1.label, $2.label);
            	info_variavel var = buscaID($2.label);
            	var.nome_lista = geraLabel();
            	alteraID($2.label, var);

            	string insere_lista = "\n\tnode *" + buscaID($2.label).nome_lista + ";\n\t" + buscaID($2.label).nome_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID($2.label).nome_lista + ");\n\tif(!" + buscaID($2.label).nome_lista + ") cout << \"Sem memoria disponivel!\\n\";";
            	for (int i = 0; i < vet_temp.size(); ++i)
            	{
            		insere_lista += "\n\tinsereFim(" + buscaID($2.label).nome_lista + ", " + vet_temp[i] + ");";
            	}
            	vet_temp.clear();
            	$$.traducao = "\n" + $3.traducao + "\n\t" + insere_lista + "\n\n\t" + $1.label + " " + buscaID($2.label).nome_temp + "[" + $3.label + "];\n";
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

VET_DIMENSAO : VET_DIMENSAO '[' E_OR ']'
			{
				if($3.tipo != "int")
				{
					erro = true;
					cout << "Tipo inválido para tamanho de vetor.\n";
				}
				string var = gera_variavel_temporaria("int");

				vet_temp.push_back($3.label);
				$$.traducao = $1.traducao + $3.traducao + "\n\t" + var + " = " + $1.label + " * " + $3.label + ";\n";
				$$.label = var;
			}
			| '[' E_OR ']'
			{
				if($2.tipo != "int")
				{
					erro = true;
					cout << "Tipo inválido para tamanho de vetor.\n";
				}
				vet_temp.push_back($2.label);
				$$.traducao = $2.traducao;
				$$.label = $2.label;
			}

VET_INDICE : VET_INDICE '[' E_OR ']'
			{
				if($3.tipo != "int")
				{
					erro = true;
					cout << "Tipo inválido para indice de vetor.\n";
				}
				string var = gera_variavel_temporaria("int");

				vet_temp.push_back($3.label);
				$$.traducao = $1.traducao + $3.traducao + ";\n";
			}
			| '[' E_OR ']'
			{
				if($2.tipo != "int")
				{
					erro = true;
					cout << "Tipo inválido para indice de vetor.\n";
				}
				vet_temp.push_back($2.label);
				$$.traducao = $2.traducao;
			}

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
                $$.tamanho = $1.tamanho;
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
                    else if ((mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo == "") || (mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo == "null"))
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

                    if ((mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo == "") || (mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo == "null"))
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
            }| TK_ID '(' PARAMETROS ')'
            {
            	if(mapa_func[$1.label].nome_temp == "")
                {
                	erro = true;
                	cout << "Erro na linha " << nlinha <<": Função \"" << $1.label << "\" não declarada." << endl << endl;
                }

                int i;
                if(mapa_func[$1.label].parametros.size() == argumentos.size())
                {
                	for(i = 0; i < argumentos.size(); i++)
                	{
                		if(mapa_func[$1.label].parametros[i] != argumentos[i])
                		{
                			erro = true;
                			cout << "Erro na linha " << nlinha <<": Parâmetros inválidos, verifique os tipos." << endl << endl;
                			break;
                		}
                	}
                }
                else
                {
                	erro = true;
                	cout << "Erro na linha " << nlinha <<": Número de parâmetros incorreto." << endl << endl;
                }
                argumentos.erase(argumentos.begin(), argumentos.end());

                info_func var = mapa_func[$1.label];
                $$.label = var.nome_temp + "(" + $3.traducao + ")";
                $$.traducao = $3.label;// + "\n\t" + var.nome_temp + "(" + $3.traducao + ")---;\n";
                $$.tipo = var.tipo;
                //$$.tamanho = var.tamanho;
            }
            | TK_ID VET_INDICE 
            {
            	string var_temp = gera_variavel_temporaria("int");
            	info_variavel var = buscaID($1.label);
            	var.acesso_lista = geraLabel();
            	alteraID($1.label, var);

            	string acesso_lista = "\n\tnode *" + buscaID($1.label).acesso_lista + ";\n\t" + buscaID($1.label).acesso_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID($1.label).acesso_lista + ");\n\tif(!" + buscaID($1.label).acesso_lista + ") cout << \"Sem memoria disponivel!\\n\";";
            	for (int i = 0; i < vet_temp.size(); ++i)
            	{
            		acesso_lista += "\n\tinsereFim(" + buscaID($1.label).acesso_lista + ", " + vet_temp[i] + ");";
            	}
            	vet_temp.clear();

            	$$.traducao = $2.traducao + "\n\t" + acesso_lista + "\n\t" + var_temp + " = mapper(" + buscaID($1.label).acesso_lista + ", " + buscaID($1.label).nome_lista + ");\n\t";// + buscaID($1.label).nome_temp + "[" + var_temp +  "] = " + $4.label + ";\n";

            	$$.tipo = var.tipo;
            	$$.label = buscaID($1.label).nome_temp + "[" + var_temp +  "]";
            	$$.tamanho = var.tamanho;
            };

PARAMETROS	: PARAMETROS ',' E_OR
			{
				argumentos.push_back($3.tipo);
				$$.label = $1.label + $3.traducao;
				$$.traducao = $1.traducao + ", " + $3.label;
			}
			| E_OR
			{
				argumentos.push_back($1.tipo);
				$$.label = $1.traducao;
				$$.traducao = $1.label;
				$$.tipo = $1.tipo;
			}
			|{
				$$.label = "";
				$$.traducao = "";
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
string gera_ID_funcao(string tipo, string nome) 
{

    stringstream nome_temp_func;
    string nome_aux;

    nome_temp_func << "temp_" << tipo << "_";

    if (!nome.empty()) {
        nome_temp_func << nome << "_" << contador;
        nome_aux = nome;
    } else {
        nome_temp_func << "EXP_" << contador;
        nome_aux = nome_temp_func.str();
    }

    contador++;

    info_func atributos = {tipo, nome_temp_func.str()};
    if(mapa_func.find(nome_aux) == mapa_func.end()) {
        mapa_func[nome_aux] = atributos;

    } else {
        cout << "Erro na linha " << nlinha <<": Você já declarou a função \"" << nome << "\"." << endl << endl;
        erro = true;
    }
    return nome_temp_func.str();
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

string incluiLista()
{
	stringstream code;
	string line;
	ifstream myfile ("./src/lista.txt");
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			code << line << "\n";
		}
		myfile.close();
	}
	return code.str();
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
