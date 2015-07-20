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

// Atributos de um token
typedef struct
{
    string label;
    string traducao;
    string tipo;
    int tamanho;
} _atributos;

// Atributos de uma variável
typedef struct _info_variavel
{
    string tipo;
    string nome_temp;
    int tamanho;
    string nome_lista;
    string acesso_lista;
    bool declarar;
} info_variavel;

// Atributos de uma função
typedef struct _info_func
{
    string tipo;
    string nome_temp;
    vector<string> parametros;
} info_funcao;

// Atributos de operações
typedef struct _info_operacoes
{
    string tipo;
    int operando;
} info_operacoes;

// Mapa de variáveis globais
map<string, info_variavel> mapa_variaveis_globais = map<string, info_variavel>();
// Mapa auxiliar para realizar a declaração das variáveis
map<string, string> mapa_variaveis_declaracao = map<string, string>();
// Mapa de funções
map<string, info_funcao> mapa_funcao = map<string, info_funcao>();
// Mapa de operações
map<string, info_operacoes> mapa_operacoes = map<string, info_operacoes>();
// Mapa de erros
map<string, string> mapa_erros = map<string, string>();
// "Pilha" de mapa de variáveis
vector< map<string, info_variavel> > pilha_variaveis = vector< map<string, info_variavel> >();
// "Pilha" de inicio de loop, para loop dentro de loop
vector<string> pilha_inicio_loop = vector<string>();
// "Pilha" de fim de loop, para loop dentro de loop
vector<string> pilha_fim_loop = vector<string>();
// Vetor de argumentos de uma função
vector<string> argumentos = vector<string>();
// Vetor de rotornos de uma função
vector<string> retorno = vector<string>();
// Vetor auxiliar de indices temporários para mapeamento de vetor
vector<string> indices_temporarios = vector<string>();
// Vetor auxiliar de indices temporários para mapeamento fatias
vector<string> indices_fatias = vector<string>();
// Vetor de IDs temporários para multipla declaração
vector<string> multiplos_ids = vector<string>();
// Pilha de labels auxiliar para fatias
vector<string> label_fatias_inicio = vector<string>();
// Pilha de labels auxiliar para fatias
vector<string> label_fatias_fim = vector<string>();
// Pilha de labels de loop
stack<string> pilha_labels_loop = stack<string>();
// Pilha de labels de saltos conticionais
stack<string> pilha_labels_condicional = stack<string>();
// Pilha de labels de saltos conticionais
stack<string> label_final = stack<string>();

// Função para gerar nomes temporários para as variáveis
string gera_variavel_temporaria(string tipo, string nome="", int tamanho=0, bool global=false);
// Função para gerar nomes temporários para as funções
string gera_ID_funcao(string tipo, string nome);
// Função para gerar um nome de um label
string geraLabel();
// Função para incluir a lista encadeada usada para mapeamento de indices no código
string incluiLista();
// Função que realiza o slice para todos os tipos de variáveis
string slice(_atributos a, _atributos b, _atributos c, _atributos d, string inicio, _atributos e, string fim);
// Função para buscar um ID na pilha de mapa de variáveis
info_variavel buscaID(string id);
// Função para carregar o mapa de operações
void carrega_mapa_operacoes();
// Função para alterar um ID da pilha de mapa de variáveis
void alteraID(string id, info_variavel nova_varivavel);
// Função para adicionar os erros no mapa de erros
void add_erro(string msg);
// Funções do YACC
int yylex(void);
void yyerror(string);





int numero_linha = 1;
int nivel = -1;
bool erro = false;
bool insere_lista = false;
string nome_temp_funcao;

%}

%token TK_MAIN TK_BEGIN TK_END TK_TIPO_INT TK_TIPO_STRING TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOL
%token TK_CHAR TK_STRING TK_ID TK_NUM TK_REAL TK_ATR TK_SOMA TK_SUB TK_MUL TK_DIV TK_LOGICO TK_AND 
%token TK_OR TK_MENOR TK_MAIOR TK_MENOR_IGUAL TK_MAIOR_IGUAL TK_IGUAL TK_DIFERENTE TK_NOT TK_PLUSPLUS 
%token TK_SUBSUB TK_WHILE TK_FOR TK_DO TK_IF TK_ELSE TK_ELIF TK_BREAK TK_CONTINUE TK_SUPERBREAK TK_SUPERCONTINUE
%token TK_WRITE TK_WRITELN TK_READ TK_GLOBAL TK_FUNCTION TK_RETURN TK_FUNC TK_ATE

%start S

%left TK_SOMA TK_SUB
%left TK_MUL TK_DIV
%%
S           : VAR_GLOBAIS FUNC TK_TIPO_INT TK_MAIN '(' ')' BLOCO
            {
                ofstream myfile;
 				stringstream variaveis;
 				stringstream cabecalho;
 				string code;
 				myfile.open ("./code.c");
 				for (std::map<string, info_variavel>::iterator it=mapa_variaveis_globais.begin(); it!=mapa_variaveis_globais.end(); ++it)
                {
                    if(it->second.tipo == "boolean")
                        variaveis << "int " << it->second.nome_temp << ";\n";
                    else if(it->second.tipo == "string")
                        variaveis << "char " << it->second.nome_temp << "[" << it->second.tamanho << "];\n";
                    else if(it->second.tipo != "")
                        variaveis << it->second.tipo << " " << it->second.nome_temp << ";\n";
                }
                for (std::map<string, string>::iterator it=mapa_variaveis_declaracao.begin(); it!=mapa_variaveis_declaracao.end(); ++it)
                        variaveis << it->second;
                cabecalho << "#include " << "<stdio.h>\n#include " << "<string.h>\n#include " << "<stdlib.h>\n#include " << "<iostream>\n";
                if(!erro)
                {
                    if(insere_lista)
                    {
                    	code = cabecalho.str() + "\nusing namespace std;\n\n" + incluiLista() + variaveis.str() + $2.traducao + "\n\nint main(void)\n{\n" + $7.traducao + "\n\treturn 0;\n}\n\n"; 
                    	while(code.find("\n;\n") != npos)
                    		code.replace(code.find("\n;\n"), 3, "\n");
                    	while(code.find(";;") != npos)
                    		code.replace(code.find(";;"), 2, ";");
                    	cout << code;
                    	myfile << code;
                    }
                    else
                    {
                    	code = cabecalho.str() + "\nusing namespace std;\n\n" + variaveis.str() + $2.traducao + "\n\nint main(void)\n{\n" + $7.traducao + "\n\treturn 0;\n}\n\n"; 
                    	while(code.find("\n;\n") != npos)
                    		code.replace(code.find("\n;\n"), 3, "");
                    	while(code.find(";;") != npos)
                    		code.replace(code.find(";;"), 2, ";");
                    	cout << code;
                    	myfile << code;
                    }
                }
                else
                {
                	for (std::map<string, string>::iterator it=mapa_erros.begin(); it!=mapa_erros.end(); ++it)
                        cout << "\033[1;31m-" << it->second << "\033[0m\n";
                }
                myfile.close();
                if(!erro)
                {
                	system("g++ code.c -o code");
                }
            };

VAR_GLOBAIS : VAR_GLOBAIS TK_GLOBAL TIPO TK_ID ';'
			{
				gera_variavel_temporaria($3.label,$4.label, 0, true);
				$$.traducao = $1.traducao + "\n\t";
			}
			|{$$.traducao = "";};

FUNC 		: FUNC TK_FUNCTION TIPO_ID '(' ARGUMENTOS ')' BLOCO
			{
				for (int i = 0; i < retorno.size(); ++i)
				{
					if(retorno[i] != $3.tipo)
					{
	                    add_erro("Erro na função \"" + nome_temp_funcao + "\". Uma função do tipo \"" + $3.tipo + "\" não pode ter um retorno com o tipo \"" + retorno[i] + "\".");
	                    break;
                	}
				}
				retorno.clear();
				if($3.tipo == "")
					$$.traducao = $1.traducao + "\nvoid " + $3.traducao + "(" + $5.traducao + ")\n{\n" + $7.traducao + "\n\treturn;\n}\n";
				else if($3.tipo == "int")
					$$.traducao = $1.traducao + "\n" + $3.traducao + "(" + $5.traducao + ")\n{\n" + $7.traducao + "\n\treturn 0;\n}\n";
                else if($3.tipo == "float")
                    $$.traducao = $1.traducao + "\n" + $3.traducao + "(" + $5.traducao + ")\n{\n" + $7.traducao + "\n\treturn 0.0;\n}\n";
                else if($3.tipo == "boolean")
                    $$.traducao = $1.traducao + "\n" + $3.traducao + "(" + $5.traducao + ")\n{\n" + $7.traducao + "\n\treturn 0;\n}\n";
                else if($3.tipo == "char")
                    $$.traducao = $1.traducao + "\n" + $3.traducao + "(" + $5.traducao + ")\n{\n" + $7.traducao + "\n\treturn '0';\n}\n";
                else if($3.tipo == "string")
                    $$.traducao = $1.traducao + "\n" + $3.traducao + "(" + $5.traducao + ")\n{\n" + $7.traducao + "\n\treturn NULL;\n}\n";
			}
			|{ $$.traducao = "";};

TIPO_ID 	: TIPO TK_ID
			{
				nome_temp_funcao = $2.label;
				string nome_temp = gera_ID_funcao($1.label, $2.label);
				if($1.label == "string")
					$$.traducao = "char *" + nome_temp;
				else if($1.label == "boolean")
					$$.traducao = "int " + nome_temp;
				else
					$$.traducao = $1.label + " " + nome_temp;
				$$.tipo = $1.label;
				$$.label = nome_temp;
				mapa_funcao[$2.label].parametros = vector<string>();
				nivel++;
                pilha_variaveis.push_back(map<string, info_variavel>());
			}
			| TK_ID
			{
				string nome_temporario = gera_ID_funcao("void", $1.label);
				$$.label = $1.label;
				$$.traducao = nome_temporario;
				$$.tipo = "";
				$$.tamanho = $1.tamanho;
				nome_temp_funcao = $1.label;
				mapa_funcao[$1.label].parametros = vector<string>();
				nivel++;
                pilha_variaveis.push_back(map<string, info_variavel>());
			};

ARGUMENTOS	: ARGUMENTOS ',' TIPO TK_ID
			{
				string var_temp = gera_variavel_temporaria($3.label, $4.label);
				info_variavel var = buscaID($4.label);
				var.declarar = false;
				alteraID($4.label, var);
				mapa_funcao[nome_temp_funcao].parametros.push_back($3.label);
				if($3.label == "boolean")
					$$.traducao = $1.traducao + ", int " + var_temp;
				else if($3.label == "string")
					$$.traducao = $1.traducao + ", char *" + var_temp;
				else
					$$.traducao = $1.traducao + ", " + $3.label + " " + var_temp;
				
			}
			| TIPO TK_ID
			{
				string var_temp = gera_variavel_temporaria($1.label, $2.label);
				info_variavel var = buscaID($2.label);
				var.declarar = false;
				alteraID($2.label, var);
				mapa_funcao[nome_temp_funcao].parametros.push_back($1.label);
				if($1.label == "boolean")
					$$.traducao = "int " + var_temp;
				else if($1.label == "string")
					$$.traducao = "char *" + var_temp;
				else
					$$.traducao = $1.label + " " + var_temp;
				
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
                        variaveis << "int " << it->second.nome_temp << ";\n";
                    else if(it->second.tipo == "string")
                        variaveis << "char " << it->second.nome_temp << "[" << it->second.tamanho << "];\n";
                    else if(it->second.tipo != "")
                        variaveis << it->second.tipo << " " << it->second.nome_temp << ";\n";
                    
                    if((it->second.nome_lista.size() > 0) || (!it->second.declarar))
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
                pilha_variaveis.push_back(map<string, info_variavel>());
                $$.traducao = $1.traducao;
            };

END         : TK_END
            {
                map<string, info_variavel>().clear();
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
                $$.traducao = "\n" + $1.traducao + $2.traducao;
            };

COMANDO 	: TK_FUNC TK_ID '(' PARAMETROS ')'
            {
            	if(mapa_funcao[$2.label].nome_temp == "")
                {
                	stringstream msg_erro;
                	msg_erro << "Erro na linha " << numero_linha << ": Função \"" << $2.label << "\" não declarada.";
                	add_erro(msg_erro.str());
                }

                int i;
                if(mapa_funcao[$2.label].parametros.size() == argumentos.size())
                {
                	for(i = 0; i < argumentos.size(); i++)
                	{
                		if(mapa_funcao[$2.label].parametros[i] != argumentos[i])
                		{
                			stringstream msg_erro;
                			msg_erro << "Erro na linha " << numero_linha <<": Artumentos inválidos, verifique os tipos.";
                			add_erro(msg_erro.str());
                			break;
                		}
                	}
                }
                else
                {
                	stringstream msg_erro;
                	msg_erro << "Erro na linha " << numero_linha <<": Número de argumentos incorreto."; 
                	add_erro(msg_erro.str());
                }
                argumentos.erase(argumentos.begin(), argumentos.end());

                info_funcao var = mapa_funcao[$2.label];
                $$.label = var.nome_temp + "(" + $4.traducao + ")";
                $$.traducao = $4.label + "\n\t" + var.nome_temp + "(" + $4.traducao + ");\n";
                $$.tipo = var.tipo;
            };

COMANDO     : DECLARACAO
            {
                $$.label = $1.label;
                $$.traducao = $1.traducao;
            };

COMANDO     : EXP_INI
            {
                $$.label = $1.label;
                $$.traducao = $1.traducao;
            };

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
					stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Para usar o comando break é necessário estar dentro de um loop.\n";
                    add_erro(msg_erro.str());
				}
			}
			| TK_CONTINUE
			{
				if(pilha_inicio_loop.size() > 0)
					$$.traducao = "\n\tgoto " + pilha_inicio_loop.back() + ";\n";
				else
				{
					stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Para usar o comando continue é necessário estar dentro de um loop.\n";
                    add_erro(msg_erro.str());
				}
			}
			| TK_SUPERBREAK
			{
				if(pilha_fim_loop.size() > 0)
					$$.traducao = "\n\tgoto " + pilha_fim_loop[0] + ";\n";
				else
				{
					stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Para usar o comando superBreak é necessário estar dentro de um loop.";
                    add_erro(msg_erro.str());
				}
			}
			| TK_SUPERCONTINUE
			{
				if(pilha_inicio_loop.size() > 0)
					$$.traducao = "\n\tgoto " + pilha_inicio_loop[0] + ";\n";
				else
				{
					stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Para usar o comando superContinue é necessário estar dentro de um loop.";
                    add_erro(msg_erro.str());
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
                else if(var.tipo == "boolean")
                {
                	string nome_temp_leitura = gera_variavel_temporaria("string", "teste", 6);
                	string nome_temp_teste = gera_variavel_temporaria("int", "teste2");
				
                	$$.traducao = "\n\tcin >> " + nome_temp_leitura + ";\n\t" + nome_temp_teste + " = strcmp(" + nome_temp_leitura + ", \"true\" );\n\t";
                	$$.traducao += "if(" + nome_temp_teste + " == 0) " + var.nome_temp + " = 1;\n\t";
                	$$.traducao += "if(" + nome_temp_teste + " != 0) " + var.nome_temp + " = 0;\n\t";

                	$$.tamanho = var.tamanho;
                }
                else
                {
                	$$.traducao = "\n\tcin >> " + var.nome_temp + ";\n\t";
                    $$.tamanho = var.tamanho;
                }
            };

COMANDO 	: TK_RETURN EXP_INI
			{
				$$.traducao = $2.traducao + "\n\treturn " + $2.label + ";\n\t";
				retorno.push_back($2.tipo);
			}
			| TK_RETURN
			{
				$$.traducao = "\n\treturn;\n\t";
				retorno.push_back("");
			};

WRITE 		: WRITE ',' EXP_INI
			{
				$$.label = $3.label;
				if($3.tipo == "void")
				{
					stringstream msg_erro;
					msg_erro << "Erro na linha: " << numero_linha << ": A função não possui valor de retorno.";
					add_erro(msg_erro.str());
				}
				if($3.tipo == "boolean")
					$$.traducao = $1.traducao + $3.traducao + "\n\tif(" + $3.label + ") cout << \"true\";\n\tif(!" + $3.label + ") cout << \"false\";\n";
				else
					$$.traducao = $1.traducao + $3.traducao + "\n\tcout << " + $3.label + ";\n";
			}
			| EXP_INI
			{
				$$.label = $1.label;
				if($1.tipo == "void")
				{
					stringstream msg_erro;
					msg_erro << "Erro na linha: " << numero_linha << ": A função não possui valor de retorno.";
					add_erro(msg_erro.str());
				}
				if($1.tipo == "boolean")
					$$.traducao = $1.traducao + "\n\tif(" + $1.label + ") cout << \"true\";\n\tif(!" + $1.label + ") cout << \"false\";\n";	
				else
					$$.traducao = $1.traducao + "\n\tcout << " + $1.label + ";\n";
			};

COMANDO     : LOOP
            {
                $$.label = $1.label;
                $$.traducao = $1.traducao;
            };

LOOP        : INI_DO BLOCO TK_WHILE '(' EXP_INI ')' 
            {
                if($5.tipo != "boolean")
                {
                	stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". É esperado uma operação cujo resultado seja boolean entre os parênteses.";
                    add_erro(msg_erro.str());
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

WHILE       : INI_WHILE '(' EXP_INI ')'
            {

                if($3.tipo != "boolean")
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". É esperado uma operação cujo resultado seja boolean entre os parênteses.";
                    add_erro(msg_erro.str());
                }

                
                string a = geraLabel();
                string b = geraLabel();
                pilha_labels_loop.push(a); pilha_labels_loop.push(b); pilha_labels_loop.push(a); pilha_labels_loop.push(b);
                pilha_inicio_loop.push_back(pilha_labels_loop.top());
                pilha_fim_loop.push_back(a);
                $$.traducao = "\n" + pilha_labels_loop.top() + ":\n\t" + $3.traducao + "\t";
                pilha_labels_loop.pop();
                string var = gera_variavel_temporaria("int");
                $$.traducao += var + " = !" + $3.label + ";\n\tif(" + var + ") goto " + pilha_labels_loop.top() + ";\n"; 
                pilha_labels_loop.pop();

            };

INI_WHILE   : TK_WHILE
            {
                nivel++;
                pilha_variaveis.push_back(map<string, info_variavel>());
            };

FOR         : INI_FOR '(' ATRIBUICAO ';' EXP_INI ';' ATRIBUICAO ')'
            {
                if($5.tipo != "boolean")
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". É esperado uma operação cujo resultado seja boolean entre os parênteses.";
                    add_erro(msg_erro.str());
                }
                string a = geraLabel();
                string b = geraLabel();
                pilha_labels_loop.push(a); pilha_labels_loop.push(b); pilha_labels_loop.push(a); pilha_labels_loop.push(b);
                pilha_inicio_loop.push_back(pilha_labels_loop.top());
                pilha_fim_loop.push_back(a);
                $$.traducao = $3.traducao + pilha_labels_loop.top() + ":\n\t" + $5.traducao + "\t";
                pilha_labels_loop.pop();
                string var = gera_variavel_temporaria("int");
                $$.traducao += var + " = !" + $5.label + ";\n\tif(" + var + ") goto " + pilha_labels_loop.top() + ";\n";
                pilha_labels_loop.pop();
                pilha_labels_loop.push($7.traducao);
            }
            | INI_FOR '(' ATRIBUICAO ';' EXP_INI ';' UNAL_OP ')'
            {
                if($5.tipo != "boolean")
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". É esperado uma operação cujo resultado seja boolean entre os parênteses.";
                    add_erro(msg_erro.str());
                }
                string a = geraLabel();
                string b = geraLabel();
                pilha_labels_loop.push(a); pilha_labels_loop.push(b); pilha_labels_loop.push(a); pilha_labels_loop.push(b);
                pilha_inicio_loop.push_back(pilha_labels_loop.top());
                pilha_fim_loop.push_back(a);
                $$.traducao = $3.traducao + pilha_labels_loop.top() + ":\n\t" + $5.traducao + "\t";
                pilha_labels_loop.pop();
                string var = gera_variavel_temporaria("int");
                $$.traducao += var + " = !" + $5.label + ";\n\tif(" + var + ") goto " + pilha_labels_loop.top() + ";\n";
                pilha_labels_loop.pop();
                pilha_labels_loop.push($7.traducao);
            }
            | INI_FOR '(' DECLARACAO ';' EXP_INI ';' UNAL_OP ')'
            {
                if($5.tipo != "boolean")
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". É esperado uma operação cujo resultado seja boolean entre os parênteses.";
                    add_erro(msg_erro.str());
                }
                string a = geraLabel();
                string b = geraLabel();
                pilha_labels_loop.push(a); pilha_labels_loop.push(b); pilha_labels_loop.push(a); pilha_labels_loop.push(b);
                pilha_inicio_loop.push_back(pilha_labels_loop.top());
                pilha_fim_loop.push_back(a);
                $$.traducao = $3.traducao + "\n" + pilha_labels_loop.top() + ":\n\t" + $5.traducao + "\t";
                pilha_labels_loop.pop();
                string var = gera_variavel_temporaria("int");
                $$.traducao += var + " = !" + $5.label + ";\n\tif(" + var + ") goto " + pilha_labels_loop.top() + ";\n";
                pilha_labels_loop.pop();
                pilha_labels_loop.push($7.traducao);
            }
            | INI_FOR '(' DECLARACAO ';' EXP_INI ';' ATRIBUICAO ')'
            {
                if($5.tipo != "boolean")
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". É esperado uma operação cujo resultado seja boolean entre os parênteses.";
                    add_erro(msg_erro.str());
                }
                string a = geraLabel();
                string b = geraLabel();
                pilha_labels_loop.push(a); pilha_labels_loop.push(b); pilha_labels_loop.push(a); pilha_labels_loop.push(b);
                pilha_inicio_loop.push_back(pilha_labels_loop.top());
                pilha_fim_loop.push_back(a);
                $$.traducao = $3.traducao + "\n" + pilha_labels_loop.top() + ":\n\t" + $5.traducao + "\t";
                pilha_labels_loop.pop();
                string var = gera_variavel_temporaria("int");
                $$.traducao += var + " = !" + $5.label + ";\n\tif(" + var + ") goto " + pilha_labels_loop.top() + ";\n";
                pilha_labels_loop.pop();
                pilha_labels_loop.push($7.traducao);
            };

INI_FOR     : TK_FOR
            {
                nivel++;
                pilha_variaveis.push_back(map<string, info_variavel>());
            };

INI_DO      : TK_DO
            {
            	string a = geraLabel(); string b = geraLabel();
                pilha_labels_loop.push(b); pilha_labels_loop.push(a);	pilha_labels_loop.push(a);
                pilha_inicio_loop.push_back(pilha_labels_loop.top());
                pilha_fim_loop.push_back(b);
                nivel++;
                pilha_variaveis.push_back(map<string, info_variavel>());
            };

COMANDO     : CONDICIONAL
            {
                $$.label = $1.label;
                $$.traducao = $1.traducao;
            };

CONDICIONAL : IF BLOCO ELIF ELSE
			{
                $$.traducao = "\n" + $1.traducao + $2.traducao + "\ngoto " + label_final.top() + ";\n" + pilha_labels_condicional.top() + ":\n";
                pilha_labels_condicional.pop();
                label_final.pop();
           		$$.traducao += $3.traducao + $4.traducao + label_final.top() + ":\n";
           		label_final.pop();
			};

ELSE 		: TK_ELSE BLOCO
			{
				$$.traducao = $2.traducao;
			}
			|
			{
				$$.traducao = "";
			};

ELIF 		: ELIF TK_ELIF '(' EXP_INI ')' BLOCO
			{
				if($4.tipo != "boolean")
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". É esperado uma operação cujo resultado seja boolean entre os parênteses.";
                    add_erro(msg_erro.str());
                }
                string a = geraLabel();
                label_final.push(label_final.top());
                pilha_labels_condicional.push(a); pilha_labels_condicional.push(a);
                string var = gera_variavel_temporaria("int");
                $$.traducao = "\n\t" + $1.traducao + "\n\t" + $4.traducao + "\t" + var + " = !" + $4.label + ";\n\tif(" + var + ") goto " + pilha_labels_condicional.top() + ";\n"; 
                pilha_labels_condicional.pop();
                $$.traducao += $6.traducao + "\ngoto " + label_final.top() + ";\n" + pilha_labels_condicional.top() + ":\n";
                pilha_labels_condicional.pop();
                label_final.pop();
			}
			|
			{
				$$.traducao = "";
			};

IF 			: INI_IF '(' EXP_INI ')' 
			{
				if($3.tipo != "boolean")
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". É esperado uma operação cujo resultado seja boolean entre os parênteses.";
                    add_erro(msg_erro.str());
                }
                string a = geraLabel();	string b = geraLabel();
                label_final.push(a);	label_final.push(a);
                pilha_labels_condicional.push(b); pilha_labels_condicional.push(b);
                string var = gera_variavel_temporaria("int");
                $$.traducao = $3.traducao + "\t" + var + " = !" + $3.label + ";\n\tif(" + var + ") goto " + pilha_labels_condicional.top() + ";\n"; 
                pilha_labels_condicional.pop();
			};

INI_IF 		: TK_IF
			{
				nivel++;
                pilha_variaveis.push_back(map<string, info_variavel>());
			};

COMANDO     : ATRIBUICAO
            {
                $$.label = $1.label;
                $$.traducao = $1.traducao;
            }
            | TK_ID ',' TK_ID TK_ATR TK_ID ',' TK_ID
            {
            	if(($1.label != $7.label) || ($3.label != $5.label))
            	{
            		stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Esperava que as variáveis estivessem cruzadas: a,b = b,a.";
                    add_erro(msg_erro.str());
            	}
            	string var_temp = gera_variavel_temporaria(buscaID($1.label).tipo);
                if(buscaID($1.label).tipo == "string")
                    $$.traducao = "\n\tstrcpy(" + var_temp + ", " + buscaID($1.label).nome_temp + ");\n\tstrcpy(" + buscaID($1.label).nome_temp + ", " + buscaID($3.label).nome_temp + ");\n\tstrcpy(" +  buscaID($3.label).nome_temp + ", " + var_temp + ");\n";
                else
                    $$.traducao = "\n\t" + var_temp + " = " + buscaID($1.label).nome_temp + ";\n\t" + buscaID($1.label).nome_temp + " = " + buscaID($3.label).nome_temp + ";\n\t" +  buscaID($3.label).nome_temp + " = " + var_temp + ";\n";
            };

ATRIBUICAO  : TK_ID TK_ATR EXP_INI
            {
            	if((buscaID($1.label).tipo == "string" && $3.tipo == "string")||(buscaID($1.label).tipo == "string" && $3.tipo == "char"))
                {
                    info_variavel var = buscaID($1.label);
                    var.tamanho += $3.tamanho;   alteraID($1.label, var);                 
                    $$.traducao = "\t" + $3.traducao + "\n\tstrcpy(" + buscaID($1.label).nome_temp + ", " + $3.label + ");\n";
                }
                else
                {
                    string tipo = buscaID($1.label).tipo;
                    if(mapa_operacoes[tipo+$2.label+$3.tipo].operando == 1)
                        $$.traducao = "\t" + $3.traducao + "\n\t" + buscaID($1.label).nome_temp + " = " + "(" + mapa_operacoes[tipo+$2.label+$3.tipo].tipo + ")" + $3.label + ";\n";
                    else if(mapa_operacoes[tipo+$2.label+$3.tipo].operando == 0)
                        $$.traducao = "\t" + $3.traducao + "\n\t" + buscaID($1.label).nome_temp + " = " + $3.label + ";\n";
                    else
                    {
                        stringstream msg_erro;
                        msg_erro << "Erro na linha: " << numero_linha << ". Um valor do tipo \"" << $3.tipo << "\" não pode ser atribuido à uma variável do tipo \"" << tipo << "\".";
                        add_erro(msg_erro.str());
                    }
                }
                if($3.tipo == "null" || $3.tipo == "")
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Operação inválida.";
                    add_erro(msg_erro.str());
                }
            }
            | TK_ID TK_ATR UNAL_OP
            {
            	$$.traducao = $3.traducao + "\n\t" + buscaID($1.label).nome_temp + " = " + $3.label + ";\n";
            }
            | TK_GLOBAL TK_ID TK_ATR EXP_INI
            {
            	if(mapa_variaveis_globais.find($2.label) == mapa_variaveis_globais.end())
                {
                	stringstream msg_erro;
                	msg_erro << "Erro na linha " << numero_linha << ": Variável global \"" << $2.label << "\" não declarada.";
                	add_erro(msg_erro.str());
                }
           		info_variavel var = mapa_variaveis_globais[$2.label];
            	if($4.tipo == "null" || $4.tipo == "")
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Operação inválida.";
                    add_erro(msg_erro.str());
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
                    else
                    {
                        stringstream msg_erro;
                        msg_erro << "Erro na linha: " << numero_linha << ". Um valor do tipo \"" << $4.tipo << "\" não pode ser atribuido à uma variável do tipo \"" << tipo << "\".";
                        add_erro(msg_erro.str());
                    }
                }
            }
            | TK_ID VET_INDICE TK_ATR EXP_INI
            {
            	string var_temp = gera_variavel_temporaria("int");
            	info_variavel var = buscaID($1.label);
            	var.acesso_lista = geraLabel();
            	alteraID($1.label, var);
            	string acesso_lista = "\n\tnode *" + buscaID($1.label).acesso_lista + ";\n\t" + buscaID($1.label).acesso_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID($1.label).acesso_lista + ");\n\tif(!" + buscaID($1.label).acesso_lista + ") cout << \"Sem memoria disponivel!\\n\";";
            	for (int i = 0; i < indices_temporarios.size(); ++i)
            	{
            		acesso_lista += "\n\tinsereFim(" + buscaID($1.label).acesso_lista + ", " + indices_temporarios[i] + ");";
            	}
            	indices_temporarios.clear();
            	if(var.tipo == "string" && $4.tipo == "string")
            	{
            		$$.traducao = $2.traducao + $4.traducao + "\n\t" + acesso_lista + "\n\t" + var_temp + " = mapper(" + buscaID($1.label).acesso_lista + ", " + buscaID($1.label).nome_lista + ");\n\t";
            		$$.traducao += "strcpy(" + buscaID($1.label).nome_temp + "[" + var_temp +  "].c, " + $4.label + ");\n";
            	}
            	else
            	{
	            	if(mapa_operacoes[buscaID($1.label).tipo+$3.label+$4.tipo].operando == 1)
	                    $$.traducao = $2.traducao + $4.traducao + "\n\t" + acesso_lista + "\n\t" + var_temp + " = mapper(" + buscaID($1.label).acesso_lista + ", " + buscaID($1.label).nome_lista + ");\n\t" + buscaID($1.label).nome_temp + "[" + var_temp +  "] = (" + mapa_operacoes[buscaID($1.label).tipo+$3.label+$4.tipo].tipo + ")" + $4.label + ";\n";
	                else if(mapa_operacoes[buscaID($1.label).tipo+$3.label+$4.tipo].operando == 0)
	                    $$.traducao = $2.traducao + $4.traducao + "\n\t" + acesso_lista + "\n\t" + var_temp + " = mapper(" + buscaID($1.label).acesso_lista + ", " + buscaID($1.label).nome_lista + ");\n\t" + buscaID($1.label).nome_temp + "[" + var_temp +  "] = " + $4.label + ";\n";
	                else
	                {
	                    stringstream msg_erro;
	                    msg_erro << "Erro na linha: " << numero_linha << ". Um valor do tipo \"" << $4.tipo << "\" não pode ser atribuido à uma variável do tipo \"" << buscaID($1.label).tipo << "\".";
	                    add_erro(msg_erro.str());
	                }
	                if(mapa_operacoes[buscaID($1.label).tipo+$3.label+$4.tipo].tipo == "null" || mapa_operacoes[buscaID($1.label).tipo+$3.label+$4.tipo].tipo == "")
	                {
	                    stringstream msg_erro;
	                    msg_erro << "Erro na linha: " << numero_linha << ". Operação inválida.";
	                    add_erro(msg_erro.str());
	                }
	            }
            }
            | TK_TIPO_INT TK_ID TK_ATR TK_ID '[' FATIAS ']'
            {
            	$$.traducao = slice($1, $2, $3, $4, "[", $5, "]");
            }
            | TK_TIPO_FLOAT TK_ID TK_ATR TK_ID '[' FATIAS ']'
            {
            	$$.traducao = slice($1, $2, $3, $4, "[", $5, "]");
            }
            | TK_TIPO_BOOL TK_ID TK_ATR TK_ID '[' FATIAS ']'
            {
            	$$.traducao = slice($1, $2, $3, $4, "[", $5, "]");
            }
            | TK_TIPO_CHAR TK_ID TK_ATR TK_ID '[' FATIAS ']'
            {
            	$$.traducao = slice($1, $2, $3, $4, "[", $5, "]");
            }
            | TK_TIPO_STRING TK_ID TK_ATR TK_ID '[' FATIAS ']'
            {
            	$$.traducao = slice($1, $2, $3, $4, "[", $5, "]");
            };

FATIAS 		: FATIAS ',' TK_NUM TK_ATE TK_NUM
			{
				indices_fatias.push_back($3.label); indices_fatias.push_back($5.label);
				$$.traducao = "";
			}
			| TK_NUM TK_ATE TK_NUM
			{
				indices_fatias.push_back($1.label); indices_fatias.push_back($3.label);
				$$.traducao = "";
			};

DECLARACAO  : TK_TIPO_INT TK_ID TK_ATR E_REL
            {
                info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, $2.label)};
                if(mapa_operacoes[$1.label+$3.label+$4.tipo].operando == 1)
                    $$.traducao = "\t" + $4.traducao + "\n\t" + atributos.nome_temp + " = " + "(" + mapa_operacoes[$1.label+$3.label+$4.tipo].tipo + ")" + $4.label + ";";
                else if(mapa_operacoes[$1.label+$3.label+$4.tipo].operando == 0)
                    $$.traducao = "\t" + $4.traducao + "\n\t" + atributos.nome_temp + " = " + $4.label + ";";
                else{
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Um valor do tipo \"" << $4.tipo << "\" não pode ser atribuido à uma variável do tipo \"" << $1.label << "\".";
                    add_erro(msg_erro.str());
                }
            }
            | TK_TIPO_INT IDS
            {
            	$$.traducao = "";
            	for (int i = 0; i < multiplos_ids.size(); ++i)
            	{
            		info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, multiplos_ids[i])};
                	$$.traducao += "\n\t" + atributos.nome_temp + " = " + "0" + ";";
            	}
            	multiplos_ids.clear();
            }
            | TK_TIPO_INT TK_ID VET_DIMENSAO
            {
            	insere_lista = true;
            	gera_variavel_temporaria($1.label, $2.label);
            	info_variavel var = buscaID($2.label);
            	var.nome_lista = geraLabel();
            	alteraID($2.label, var);
            	string insere_lista = "\n\tnode *" + buscaID($2.label).nome_lista + ";\n\t" + buscaID($2.label).nome_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID($2.label).nome_lista + ");\n\tif(!" + buscaID($2.label).nome_lista + ") cout << \"Sem memoria disponivel!\\n\";";
            	for (int i = 0; i < indices_temporarios.size(); ++i)
            	{
            		insere_lista += "\n\tinsereFim(" + buscaID($2.label).nome_lista + ", " + indices_temporarios[i] + ");";
            	}
            	indices_temporarios.clear();
            	$$.traducao = "\n" + $3.traducao + "\n\t" + insere_lista + "\n\n\t" + $1.label + " " + buscaID($2.label).nome_temp + "[" + $3.label + "];\n";
            }
            | TK_TIPO_FLOAT TK_ID TK_ATR EXP_INI
            {
                info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, $2.label)};

                if(mapa_operacoes[$1.label+$3.label+$4.tipo].operando == 1)
                    $$.traducao = "\t" + $4.traducao + "\n\t" + atributos.nome_temp + " = " + "(" + mapa_operacoes[$1.label+$3.label+$4.tipo].tipo + ")" + $4.label + ";";
                else if(mapa_operacoes[$1.label+$3.label+$4.tipo].operando == 0)
                    $$.traducao = "\t" + $4.traducao + "\n\t" + atributos.nome_temp + " = " + $4.label + ";";
                else
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Um valor do tipo \"" << $4.tipo << "\" não pode ser atribuido à uma variável do tipo \"" << $1.label << "\".";
                    add_erro(msg_erro.str());
                }
            }
            | TK_TIPO_FLOAT IDS
            {
            	$$.traducao = "";
            	for (int i = 0; i < multiplos_ids.size(); ++i)
            	{
	                info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, multiplos_ids[i])};
	                $$.traducao += "\n\t" + atributos.nome_temp + " = " + "0.0" + ";";
	            }
	            multiplos_ids.clear();
            }
            | TK_TIPO_FLOAT TK_ID VET_DIMENSAO
            {
            	insere_lista = true;
            	gera_variavel_temporaria($1.label, $2.label);
            	info_variavel var = buscaID($2.label);
            	var.nome_lista = geraLabel();
            	alteraID($2.label, var);
            	string insere_lista = "\n\tnode *" + buscaID($2.label).nome_lista + ";\n\t" + buscaID($2.label).nome_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID($2.label).nome_lista + ");\n\tif(!" + buscaID($2.label).nome_lista + ") cout << \"Sem memoria disponivel!\\n\";";
            	for (int i = 0; i < indices_temporarios.size(); ++i)
            	{
            		insere_lista += "\n\tinsereFim(" + buscaID($2.label).nome_lista + ", " + indices_temporarios[i] + ");";
            	}
            	indices_temporarios.clear();
            	$$.traducao = "\n" + $3.traducao + "\n\t" + insere_lista + "\n\n\t" + $1.label + " " + buscaID($2.label).nome_temp + "[" + $3.label + "];\n";
            }
            | TK_TIPO_BOOL TK_ID TK_ATR EXP_INI
            {
                info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, $2.label)};

                if(mapa_operacoes[$1.label+$3.label+$4.tipo].operando == 1)
                    $$.traducao = "\t" + $4.traducao + "\n\t" + atributos.nome_temp + " = " + "(" + mapa_operacoes[$1.label+$3.label+$4.tipo].tipo + ")" + $4.label + ";";
                else if(mapa_operacoes[$1.label+$3.label+$4.tipo].operando == 0)
                    $$.traducao = "\t" + $4.traducao + "\n\t" + atributos.nome_temp + " = " + $4.label + ";";
                else
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Um valor do tipo \"" << $4.tipo << "\" não pode ser atribuido à uma variável do tipo \"" << $1.label << "\".";
                    add_erro(msg_erro.str());
                }
            }
            | TK_TIPO_BOOL IDS
            {
            	$$.traducao = "";
            	for (int i = 0; i < multiplos_ids.size(); ++i)
            	{
	                info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, multiplos_ids[i])};
	                $$.traducao += "\n\t" + atributos.nome_temp + " = " + "1" + ";";
	            }
	            multiplos_ids.clear();
            }
            | TK_TIPO_BOOL TK_ID VET_DIMENSAO
            {
            	insere_lista = true;
            	gera_variavel_temporaria($1.label, $2.label);
            	info_variavel var = buscaID($2.label);
            	var.nome_lista = geraLabel();
            	alteraID($2.label, var);
            	string insere_lista = "\n\tnode *" + buscaID($2.label).nome_lista + ";\n\t" + buscaID($2.label).nome_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID($2.label).nome_lista + ");\n\tif(!" + buscaID($2.label).nome_lista + ") cout << \"Sem memoria disponivel!\\n\";";
            	for (int i = 0; i < indices_temporarios.size(); ++i)
            	{
            		insere_lista += "\n\tinsereFim(" + buscaID($2.label).nome_lista + ", " + indices_temporarios[i] + ");";
            	}
            	indices_temporarios.clear();
            	$$.traducao = "\n" + $3.traducao + "\n\t" + insere_lista + "\n\n\t" + $1.traducao + " " + buscaID($2.label).nome_temp + "[" + $3.label + "];\n";
            }
            | TK_TIPO_CHAR TK_ID TK_ATR EXP_INI
            {
                info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, $2.label,1)};  
                if(mapa_operacoes[$1.label+$3.label+$4.tipo].operando == 1)
                    $$.traducao = "\t" + $4.traducao + "\n\t" + atributos.nome_temp + " = " + "(" + mapa_operacoes[$1.label+$3.label+$4.tipo].tipo + ")" + $4.label + ";";
                else if(mapa_operacoes[$1.label+$3.label+$4.tipo].operando == 0)
                    $$.traducao = "\t" + $4.traducao + "\n\t" + atributos.nome_temp + " = " + $4.label + ";";
                else
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Um valor do tipo \"" << $4.tipo << "\" não pode ser atribuido à uma variável do tipo \"" << $1.label << "\".";
                    add_erro(msg_erro.str());
                }
            }
            | TK_TIPO_CHAR IDS
            {
            	$$.traducao = "";
            	for (int i = 0; i < multiplos_ids.size(); ++i)
            	{
	                info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, multiplos_ids[i],1)};
	            }
	            multiplos_ids.clear();
            }
            | TK_TIPO_CHAR TK_ID VET_DIMENSAO
            {
            	insere_lista = true;
            	gera_variavel_temporaria($1.label, $2.label);
            	info_variavel var = buscaID($2.label);
            	var.nome_lista = geraLabel();
            	alteraID($2.label, var);
            	string insere_lista = "\n\tnode *" + buscaID($2.label).nome_lista + ";\n\t" + buscaID($2.label).nome_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID($2.label).nome_lista + ");\n\tif(!" + buscaID($2.label).nome_lista + ") cout << \"Sem memoria disponivel!\\n\";";
            	for (int i = 0; i < indices_temporarios.size(); ++i)
            	{
            		insere_lista += "\n\tinsereFim(" + buscaID($2.label).nome_lista + ", " + indices_temporarios[i] + ");";
            	}
            	indices_temporarios.clear();
            	$$.traducao = "\n" + $3.traducao + "\n\t" + insere_lista + "\n\n\t" + $1.label + " " + buscaID($2.label).nome_temp + "[" + $3.label + "];\n";
            }
            | TK_TIPO_STRING TK_ID TK_ATR EXP_INI
            {
                info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, $2.label, 1024 + $4.tamanho)};
                if((mapa_operacoes[$1.label+$3.label+$4.tipo].operando == 0) && (mapa_operacoes[$1.label+$3.label+$4.tipo].tipo != ""))
                {
                    $$.traducao = $4.traducao + "\n\tstrcpy(" + atributos.nome_temp + ", " + $4.label + ");\n";
                }
                else
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Um valor do tipo \"" << $4.tipo << "\" não pode ser atribuido à uma variável do tipo \"" << $1.label << "\".";
                    add_erro(msg_erro.str());
                }
            }
            | TK_TIPO_STRING IDS
            {
            	$$.traducao = "";
            	for (int i = 0; i < multiplos_ids.size(); ++i)
            	{
	                info_variavel atributos = { $1.label, gera_variavel_temporaria($1.label, multiplos_ids[i], 1024)};
	                $$.traducao += "\n\tstrcpy(" + atributos.nome_temp + ", \"\");\n";
	            }
	            multiplos_ids.clear();
            }
            | TK_TIPO_STRING TK_ID VET_DIMENSAO
            {
            	insere_lista = true;
            	gera_variavel_temporaria($1.label, $2.label);
            	info_variavel var = buscaID($2.label);
            	var.nome_lista = geraLabel();
            	alteraID($2.label, var);
            	string insere_lista = "\n\tnode *" + buscaID($2.label).nome_lista + ";\n\t" + buscaID($2.label).nome_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID($2.label).nome_lista + ");\n\tif(!" + buscaID($2.label).nome_lista + ") cout << \"Sem memoria disponivel!\\n\";";
            	for (int i = 0; i < indices_temporarios.size(); ++i)
            	{
            		insere_lista += "\n\tinsereFim(" + buscaID($2.label).nome_lista + ", " + indices_temporarios[i] + ");";
            	}
            	indices_temporarios.clear();
            	$$.traducao = "\n" + $3.traducao + "\n\t" + insere_lista + "\n\n\tstr " + buscaID($2.label).nome_temp + "[" + $3.label + "];\n";
            };

IDS 		: IDS ',' TK_ID
			{
				multiplos_ids.push_back($3.label);
				$$.traducao = "";
			}
			| TK_ID
			{
				multiplos_ids.push_back($1.label);
				$$.traducao = "";
			};

VET_DIMENSAO: VET_DIMENSAO '[' EXP_INI ']'
			{
				if($3.tipo != "int")
				{
					stringstream msg_erro;
					msg_erro << "Erro na linha: " << numero_linha << ". Esperava um valor do tipo \"int\" para definir o tamanho de um vetor.";
					add_erro(msg_erro.str());
				}
				string var = gera_variavel_temporaria("int");
				indices_temporarios.push_back($3.label);
				$$.traducao = $1.traducao + $3.traducao + "\n\t" + var + " = " + $1.label + " * " + $3.label + ";\n";
				$$.label = var;
			}
			| '[' EXP_INI ']'
			{
				if($2.tipo != "int")
				{
					stringstream msg_erro;
					msg_erro << "Erro na linha: " << numero_linha << ". Esperava um valor do tipo \"int\" para definir o tamanho de um vetor.";
					add_erro(msg_erro.str());
				}
				indices_temporarios.push_back($2.label);
				$$.traducao = $2.traducao;
				$$.label = $2.label;
			}

VET_INDICE 	: VET_INDICE '[' EXP_INI ']'
			{
				if($3.tipo != "int")
				{
					stringstream msg_erro;
					msg_erro << "Erro na linha: " << numero_linha << ". Esperava um valor do tipo \"int\" para o indice do vetor.";
					add_erro(msg_erro.str());
				}
				string var = gera_variavel_temporaria("int");
				indices_temporarios.push_back($3.label);
				$$.traducao = $1.traducao + $3.traducao + ";\n";
			}
			| '[' EXP_INI ']'
			{
				if($2.tipo != "int")
				{
					stringstream msg_erro;
					msg_erro << "Erro na linha: " << numero_linha << ". Esperava um valor do tipo \"int\" para o indice do vetor.";
					add_erro(msg_erro.str());
				}
				indices_temporarios.push_back($2.label);
				$$.traducao = $2.traducao;
			}

EXP_INI		: E_OR
			{
				$$.label = $1.label;
                $$.traducao = $1.traducao;
			}
			| TK_NOT E_OR
			{
				string var_negada = gera_variavel_temporaria("boolean");
				if($2.tipo != "boolean")
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Esperava um valor do tipo \"boolean\".";
                    add_erro(msg_erro.str());
                }
                $$.label = var_negada;
                $$.traducao = "\n\t" + $2.traducao + "\n\t" + var_negada + " = !" + $2.label + ";\n";
                $$.tipo = $2.tipo;
                $$.tamanho = $2.tamanho;
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
                $$.tamanho = $1.tamanho;
            };

E_REL       : EXP TK_REL_OP EXP
            {
            	if(mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo == "" || mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo == "null")
            	{
            		stringstream msg_erro;
            		msg_erro << "Erro na linha: " << numero_linha << ". Operação inválida.";
            		add_erro(msg_erro.str());
            	}
            	if(($1.tipo == "string") && ($3.tipo == "string"))
            	{
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
            | EXP
            {
                $$.label = $1.label;
                $$.traducao = $1.traducao;
                $$.tipo = $1.tipo;
                $$.tamanho = $1.tamanho;
            };

EXP         : EXP TK_ARIT_OP_S EXP_TEMP
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
                        stringstream msg_erro;
                        msg_erro << "Erro na linha: " << numero_linha << ". Operação inválida.";
                        add_erro(msg_erro.str());
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
                        stringstream msg_erro;
                        msg_erro << "Erro na linha: " << numero_linha << ". Operação inválida.";
                        add_erro(msg_erro.str());
                    }
                    $$.tipo = mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo;
                }
            }
            | EXP_TEMP
            {
                $$.label = $1.label;
                $$.traducao = $1.traducao;
                $$.tipo = $1.tipo;
                $$.tamanho = $1.tamanho;
            };

EXP_TEMP    : EXP_TEMP TK_ARIT_OP_M UNAL
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
                } else 
                {
                    $$.traducao = $3.traducao + "\t" + $1.traducao + "\n\t" + nome_variavel_temporaria + " = " + "(" + mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo + ")" + $3.label + ";";
                    $$.traducao += "\n\t" + nome_variavel_temporaria + " = " + $1.label + " " + $2.label + " " + nome_variavel_temporaria + ";";
                }
                if (mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo == "null" || mapa_operacoes[$1.tipo+$2.label+$3.tipo].tipo == "")
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Operação inválida.";
                    add_erro(msg_erro.str());
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

UNAL_OP		: TK_PLUSPLUS TK_ID
            {
            	if (buscaID($2.label).tipo != "int")
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Esperava um valor do tipo \"int\".";
                    add_erro(msg_erro.str());
                }
                info_variavel var = buscaID($2.label);
                $$.label = var.nome_temp;
                $$.traducao = "\n\t" + var.nome_temp + " = " + var.nome_temp + " + 1;\n";
                $$.tipo = var.tipo;
                $$.tamanho = var.tamanho;
            }
            | TK_SUBSUB TK_ID
            {
            	if (buscaID($2.label).tipo != "int")
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Esperava um valor do tipo \"int\".";
                    add_erro(msg_erro.str());
                }
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
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Não é possível realizar uma operação aritmética com um valor do tipo \"" << $2.tipo << "\".";
                    add_erro(msg_erro.str());
                }
                $$.label = $1.label + $2.label;
                $$.tipo = $2.tipo;
                $$.traducao = $2.traducao;
            }
            | VAL
            {
                $$.label = $1.label;
                $$.tipo = $1.tipo;
                $$.traducao = $1.traducao;
                $$.tamanho = $1.tamanho;
            };

VAL         : '(' EXP_CAST ')' VAL
            {
                string nome_variavel_temporaria = gera_variavel_temporaria($2.tipo);
                $$.label = nome_variavel_temporaria;
                if(mapa_operacoes["("+$2.label+")"+$4.tipo].tipo == "null" || mapa_operacoes["("+$2.label+")"+$4.tipo].tipo == "")
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Não é possível realizar este cast.";
                    add_erro(msg_erro.str());
                }
                else
                {
                    $$.traducao = $4.traducao +"\n\t" + $$.label + " = "+ "(" + $2.label + ")"+ $4.label + ";";
                }
                    $$.tipo = $2.tipo;
            }
            | '(' EXP_INI ')'
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
                if(mapa_variaveis_globais.find($2.label) == mapa_variaveis_globais.end())
                {
                	stringstream msg_erro;
                	msg_erro << "Erro na linha " << numero_linha <<": Variável global \"" << $2.label << "\" não declarada.";
                	add_erro(msg_erro.str());
                }
                else
                {
                	info_variavel var = mapa_variaveis_globais[$2.label];
                	$$.label = var.nome_temp;
	                $$.traducao = "";
	                $$.tipo = var.tipo;
	                $$.tamanho = var.tamanho;
                }
            }
            | TK_ID '(' PARAMETROS ')'
            {
            	if(mapa_funcao[$1.label].nome_temp == "")
                {
                	stringstream msg_erro;
                	msg_erro << "Erro na linha " << numero_linha << ": Função \"" << $1.label << "\" não declarada.";
                	add_erro(msg_erro.str());
                }
                int i;
                if(mapa_funcao[$1.label].parametros.size() == argumentos.size())
                {
                	for(i = 0; i < argumentos.size(); i++)
                	{
                		if(mapa_funcao[$1.label].parametros[i] != argumentos[i])
                		{
                			stringstream msg_erro;
                			msg_erro << "Erro na linha " << numero_linha <<": Parâmetros inválidos, verifique os tipos.";
                			add_erro(msg_erro.str());
                			break;
                		}
                	}
                }
                else
                {
                	stringstream msg_erro;
                	msg_erro << "Erro na linha " << numero_linha <<": Número de parâmetros incorreto.";
                	add_erro(msg_erro.str());
                }
                argumentos.erase(argumentos.begin(), argumentos.end());
                info_funcao var = mapa_funcao[$1.label];
                $$.label = var.nome_temp + "(" + $3.traducao + ")";
                $$.traducao = $3.label;
                $$.tipo = var.tipo;
                $$.tamanho = 1024;
            }
            | TK_ID VET_INDICE 
            {
            	string var_temp = gera_variavel_temporaria("int");
            	info_variavel var = buscaID($1.label);
            	var.acesso_lista = geraLabel();
            	alteraID($1.label, var);
            	string acesso_lista = "\n\tnode *" + buscaID($1.label).acesso_lista + ";\n\t" + buscaID($1.label).acesso_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID($1.label).acesso_lista + ");\n\tif(!" + buscaID($1.label).acesso_lista + ") cout << \"Sem memoria disponivel!\\n\";";
            	for (int i = 0; i < indices_temporarios.size(); ++i)
            	{
            		acesso_lista += "\n\tinsereFim(" + buscaID($1.label).acesso_lista + ", " + indices_temporarios[i] + ");";
            	}
            	indices_temporarios.clear();
            	$$.traducao = $2.traducao + "\n\t" + acesso_lista + "\n\t" + var_temp + " = mapper(" + buscaID($1.label).acesso_lista + ", " + buscaID($1.label).nome_lista + ");\n\t";
            	$$.tipo = var.tipo;
            	if(var.tipo == "string")
            		$$.label = buscaID($1.label).nome_temp + "[" + var_temp +  "].c";
            	else
            		$$.label = buscaID($1.label).nome_temp + "[" + var_temp +  "]";
            	$$.tamanho = var.tamanho;
            };

PARAMETROS	: PARAMETROS ',' EXP_INI
			{
				argumentos.push_back($3.tipo);
				$$.label = $1.label + $3.traducao;
				$$.traducao = $1.traducao + ", " + $3.label;
			}
			| EXP_INI
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

EXP_CAST    : TK_TIPO_FLOAT
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
            };

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
            };

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
            };

%%

#include "lex.yy.c"

int yyparse();
int contador = 0;

string gera_variavel_temporaria(string tipo, string nome, int tamanho, bool global) 
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
    atributos.declarar = true;
    if(tipo == "string")
    	atributos.tamanho = 1024;
    if(global)
    {
    	atributos.nome_temp += "_global";
    	if(mapa_variaveis_globais.find(nome_aux) == mapa_variaveis_globais.end())
    		mapa_variaveis_globais[nome_aux] = atributos;
	    else
	    {
	        stringstream msg_erro;
	        msg_erro << "Erro na linha " << numero_linha <<": Você já declarou a variável \"" << nome << "\".";
	        add_erro(msg_erro.str());
	    }
	    return nome_temporario.str();
    }
    if(pilha_variaveis[nivel].find(nome_aux) == pilha_variaveis[nivel].end())
    {
        pilha_variaveis[nivel][nome_aux] = atributos;
    } else
    {
        stringstream msg_erro;
        msg_erro << "Erro na linha " << numero_linha <<": Você já declarou a variável \"" << nome << "\".";
        add_erro(msg_erro.str());
    }
    return nome_temporario.str();
}
string gera_ID_funcao(string tipo, string nome) 
{
    stringstream nome_temp_func;
    string nome_aux;
    nome_temp_func << "temp_" << tipo << "_";
    if (!nome.empty()) 
    {
        nome_temp_func << nome << "_" << contador;
        nome_aux = nome;
    }
    else 
    {
        nome_temp_func << "EXP_" << contador;
        nome_aux = nome_temp_func.str();
    }
    contador++;
    info_funcao atributos = {tipo, nome_temp_func.str()};
    if(mapa_funcao.find(nome_aux) == mapa_funcao.end())
    {
        mapa_funcao[nome_aux] = atributos;
    }
    else
    {
        stringstream msg_erro;
        msg_erro << "Erro na linha " << numero_linha <<": Você já declarou a função \"" << nome << "\".";
        add_erro(msg_erro.str());
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
        stringstream msg_erro;
        msg_erro << "Erro na linha " << numero_linha <<": Variável \"" << id << "\" não declarada.";
        add_erro(msg_erro.str());
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
        stringstream msg_erro;
        msg_erro << "Erro na linha " << numero_linha <<": Variável \"" << id << "\" não declarada.";
        add_erro(msg_erro.str());
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

void carrega_mapa_operacoes()
{
    FILE* file2 = fopen("./src/mapa_cast.txt", "r");    
    char chave[30] = "";
    char resultado[20] = "";
    int operando;
    while(fscanf(file2, "%s\t%s\t%d\n", chave, resultado, &operando))
    {    
        info_operacoes cast = {resultado, operando};
        mapa_operacoes[chave] = cast;
        
        if(feof(file2))
            break;
    }
    fclose(file2);
}

void add_erro(string msg)
{
	if(mapa_erros.find(msg) == mapa_erros.end())
		mapa_erros[msg] = msg;
	erro = true;
}

string slice(_atributos a, _atributos b, _atributos c, _atributos d, string inicio, _atributos e, string fim)
{
    string traducao;
	if(a.label != buscaID(d.label).tipo)
	{
		stringstream msg_erro;
		msg_erro << "Erro na linha: " << numero_linha << ". Esta operação só pode ser feita com variáveis do mesmo tipo.";
		add_erro(msg_erro.str());
	}
	gera_variavel_temporaria(a.label, b.label);
	info_variavel var = buscaID(b.label);
	var.nome_lista = geraLabel();
	var.acesso_lista = geraLabel();
	alteraID(b.label, var);
	traducao = "\n\tnode *" + buscaID(b.label).nome_lista + ";\n\t" + buscaID(b.label).nome_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID(b.label).nome_lista + ");\n\tif(!" + buscaID(b.label).nome_lista + ") cout << \"Sem memoria disponivel!\\n\";\n";
	string tamanho_declaracao = gera_variavel_temporaria("int");
	vector<string> vet_tamanho_declaracao = vector<string>();
	for (int i = 0; i < indices_fatias.size(); i=i+2)
	{
		string var = gera_variavel_temporaria("int");
		vet_tamanho_declaracao.push_back(var);
		traducao += "\n\t" + var + " = " + indices_fatias[i+1] + " - " + indices_fatias[i] + ";\n\tif(" + var + " > 1)";
		traducao += "\n\tinsereFim(" + buscaID(b.label).nome_lista + ", " + var + ");\n";
	}
	traducao += "\n\t" + tamanho_declaracao + " = 1;";
	for (int i = 0; i < vet_tamanho_declaracao.size(); ++i)
	{
		traducao += "\n\t" + tamanho_declaracao + " = " + tamanho_declaracao + " * " + vet_tamanho_declaracao[i] + ";";
	}
	if(var.tipo == "boolean")
		traducao += "\n\tint " + var.nome_temp + "[" + tamanho_declaracao + "];\n";
	else if(var.tipo == "string")
		traducao += "\n\tstr " + var.nome_temp + "[" + tamanho_declaracao + "];\n";
	else
		traducao += "\n\t" + var.tipo + " " + var.nome_temp + "[" + tamanho_declaracao + "];\n";
	string loop = "";
	vector<string> var_indices = vector<string>();
	string contador = gera_variavel_temporaria("int");
	traducao += "\n\t" + contador + " = 0;\n\t";
	for (int i = 0; i < indices_fatias.size(); i=i+2)
	{
		string label_fim = geraLabel();
		string label_inicio = geraLabel();
		label_fatias_fim.push_back(label_fim);
		label_fatias_inicio.push_back(label_inicio);
			string var = gera_variavel_temporaria("int");
			string teste = gera_variavel_temporaria("int");
			var_indices.push_back(var);
		loop = "\n\t" + var + " = " + indices_fatias[i] + ";\n" + label_inicio + ":\n\t" + teste + " = " + var + " < " + indices_fatias[i+1] + ";\n\tif(!" + teste + ")goto " + label_fim + ";\n" + loop + "\n";
	}
	loop += "\n\tnode *" + var.acesso_lista + ";\n\t" + var.acesso_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + var.acesso_lista + ");\n\tif(!" + var.acesso_lista + ") cout << \"Sem memoria disponivel!\\n\";\n";
	for (int i = var_indices.size()-1; i >= 0 ; --i)
	{
		loop += "\tinsereFim(" + var.acesso_lista + ", " + var_indices[i] + ");\n";
	}
	string indice = gera_variavel_temporaria("int");
	loop += "\n\t" + indice + " = mapper(" + var.acesso_lista + ", " + buscaID(d.label).nome_lista + ");\n\t";
	traducao += loop + var.nome_temp + "[" + contador + "] = " + buscaID(d.label).nome_temp + "[" + indice + "];\n\t" + contador + " = " + contador + " + 1;\n";
	for (int i = 0; i < var_indices.size(); ++i)
	{
		traducao += "\n\t" + var_indices[i] + " = " + var_indices[i] + " + 1;\n" + "goto " + label_fatias_inicio[i] + ";\n" + label_fatias_fim[i] + ":\n\t";
	}
	label_fatias_fim.clear();
	label_fatias_inicio.clear();
	indices_fatias.clear();
    return traducao;
}

int main( int argc, char* argv[] )
{
    carrega_mapa_operacoes();
    yyparse();
    return 0;
}

void yyerror( string MSG )
{
    cout << MSG << " on line " << numero_linha << endl;
    exit (0);
}               
