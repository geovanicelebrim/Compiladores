/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "src/sintatica.y" /* yacc.c:339  */

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


#line 185 "bin/y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_BIN_Y_TAB_H_INCLUDED
# define YY_YY_BIN_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_MAIN = 258,
    TK_BEGIN = 259,
    TK_END = 260,
    TK_TIPO_INT = 261,
    TK_TIPO_STRING = 262,
    TK_TIPO_FLOAT = 263,
    TK_TIPO_CHAR = 264,
    TK_TIPO_BOOL = 265,
    TK_CHAR = 266,
    TK_STRING = 267,
    TK_ID = 268,
    TK_NUM = 269,
    TK_REAL = 270,
    TK_ATR = 271,
    TK_SOMA = 272,
    TK_SUB = 273,
    TK_MUL = 274,
    TK_DIV = 275,
    TK_LOGICO = 276,
    TK_AND = 277,
    TK_OR = 278,
    TK_MENOR = 279,
    TK_MAIOR = 280,
    TK_MENOR_IGUAL = 281,
    TK_MAIOR_IGUAL = 282,
    TK_IGUAL = 283,
    TK_DIFERENTE = 284,
    TK_NOT = 285,
    TK_PLUSPLUS = 286,
    TK_SUBSUB = 287,
    TK_WHILE = 288,
    TK_FOR = 289,
    TK_DO = 290,
    TK_IF = 291,
    TK_ELSE = 292,
    TK_ELIF = 293,
    TK_BREAK = 294,
    TK_CONTINUE = 295,
    TK_SUPERBREAK = 296,
    TK_SUPERCONTINUE = 297,
    TK_WRITE = 298,
    TK_WRITELN = 299,
    TK_READ = 300,
    TK_GLOBAL = 301,
    TK_FUNCTION = 302,
    TK_RETURN = 303,
    TK_FUNC = 304,
    TK_ATE = 305
  };
#endif
/* Tokens.  */
#define TK_MAIN 258
#define TK_BEGIN 259
#define TK_END 260
#define TK_TIPO_INT 261
#define TK_TIPO_STRING 262
#define TK_TIPO_FLOAT 263
#define TK_TIPO_CHAR 264
#define TK_TIPO_BOOL 265
#define TK_CHAR 266
#define TK_STRING 267
#define TK_ID 268
#define TK_NUM 269
#define TK_REAL 270
#define TK_ATR 271
#define TK_SOMA 272
#define TK_SUB 273
#define TK_MUL 274
#define TK_DIV 275
#define TK_LOGICO 276
#define TK_AND 277
#define TK_OR 278
#define TK_MENOR 279
#define TK_MAIOR 280
#define TK_MENOR_IGUAL 281
#define TK_MAIOR_IGUAL 282
#define TK_IGUAL 283
#define TK_DIFERENTE 284
#define TK_NOT 285
#define TK_PLUSPLUS 286
#define TK_SUBSUB 287
#define TK_WHILE 288
#define TK_FOR 289
#define TK_DO 290
#define TK_IF 291
#define TK_ELSE 292
#define TK_ELIF 293
#define TK_BREAK 294
#define TK_CONTINUE 295
#define TK_SUPERBREAK 296
#define TK_SUPERCONTINUE 297
#define TK_WRITE 298
#define TK_WRITELN 299
#define TK_READ 300
#define TK_GLOBAL 301
#define TK_FUNCTION 302
#define TK_RETURN 303
#define TK_FUNC 304
#define TK_ATE 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BIN_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 336 "bin/y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   399

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  135
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  298

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      51,    52,     2,     2,    54,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    53,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   131,   131,   185,   190,   192,   216,   218,   234,   247,
     262,   277,   279,   283,   287,   291,   295,   300,   332,   339,
     345,   350,   354,   359,   396,   402,   408,   414,   425,   436,
     447,   459,   464,   469,   499,   504,   510,   524,   539,   545,
     562,   573,   583,   607,   613,   633,   653,   673,   694,   700,
     710,   716,   725,   730,   734,   753,   757,   773,   779,   784,
     799,   828,   832,   867,   904,   908,   912,   916,   920,   925,
     930,   936,   949,   959,   974,   989,   999,  1014,  1029,  1039,
    1054,  1068,  1077,  1092,  1106,  1116,  1132,  1137,  1143,  1156,
    1169,  1181,  1193,  1198,  1213,  1220,  1228,  1235,  1243,  1302,
    1310,  1354,  1362,  1386,  1394,  1408,  1423,  1435,  1443,  1459,
    1465,  1472,  1479,  1487,  1494,  1501,  1509,  1526,  1561,  1582,
    1588,  1595,  1600,  1606,  1612,  1618,  1625,  1630,  1635,  1640,
    1645,  1650,  1656,  1661,  1667,  1672
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_MAIN", "TK_BEGIN", "TK_END",
  "TK_TIPO_INT", "TK_TIPO_STRING", "TK_TIPO_FLOAT", "TK_TIPO_CHAR",
  "TK_TIPO_BOOL", "TK_CHAR", "TK_STRING", "TK_ID", "TK_NUM", "TK_REAL",
  "TK_ATR", "TK_SOMA", "TK_SUB", "TK_MUL", "TK_DIV", "TK_LOGICO", "TK_AND",
  "TK_OR", "TK_MENOR", "TK_MAIOR", "TK_MENOR_IGUAL", "TK_MAIOR_IGUAL",
  "TK_IGUAL", "TK_DIFERENTE", "TK_NOT", "TK_PLUSPLUS", "TK_SUBSUB",
  "TK_WHILE", "TK_FOR", "TK_DO", "TK_IF", "TK_ELSE", "TK_ELIF", "TK_BREAK",
  "TK_CONTINUE", "TK_SUPERBREAK", "TK_SUPERCONTINUE", "TK_WRITE",
  "TK_WRITELN", "TK_READ", "TK_GLOBAL", "TK_FUNCTION", "TK_RETURN",
  "TK_FUNC", "TK_ATE", "'('", "')'", "';'", "','", "'['", "']'", "$accept",
  "S", "VAR_GLOBAIS", "FUNC", "TIPO_ID", "ARGUMENTOS", "TIPO", "BLOCO",
  "BEGIN", "END", "COMANDOS", "COMANDO", "WRITE", "LOOP", "WHILE",
  "INI_WHILE", "FOR", "INI_FOR", "INI_DO", "CONDICIONAL", "ELSE", "ELIF",
  "IF", "INI_IF", "ATRIBUICAO", "FATIAS", "DECLARACAO", "IDS",
  "VET_DIMENSAO", "VET_INDICE", "EXP_INI", "E_OR", "E_AND", "E_REL", "EXP",
  "EXP_TEMP", "UNAL_OP", "UNAL", "VAL", "PARAMETROS", "EXP_CAST",
  "TK_REL_OP", "TK_ARIT_OP_S", "TK_ARIT_OP_M", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,    40,    41,    59,    44,    91,    93
};
# endif

#define YYPACT_NINF -219

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-219)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -219,    23,   -20,  -219,   343,     7,  -219,  -219,  -219,  -219,
    -219,    18,    41,   291,   -14,    15,  -219,    62,    61,  -219,
      97,   343,  -219,   144,    42,   150,  -219,  -219,   190,   144,
     343,  -219,   151,   158,   162,   169,   173,  -219,  -219,    35,
    -219,  -219,   319,  -219,    47,   205,   206,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,    96,    96,   214,   215,    96,
     224,     6,   190,   238,   197,  -219,   144,   200,   144,   202,
     144,  -219,   144,   203,  -219,  -219,  -219,   239,   243,  -219,
     349,    36,  -219,  -219,  -219,  -219,   248,     9,   218,    14,
     218,    17,   218,    24,   218,    25,   218,    70,    96,   260,
      96,    32,   -13,   263,  -219,   239,  -219,  -219,   225,  -219,
     225,  -219,   262,  -219,   230,  -219,  -219,  -219,  -219,   231,
     232,  -219,  -219,  -219,   190,  -219,    96,  -219,   147,   249,
    -219,    96,    47,    47,  -219,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,    47,    47,  -219,  -219,    47,  -219,   166,    96,
     233,   274,   234,   233,   245,   233,   256,   233,   297,   233,
    -219,  -219,  -219,    66,   273,   236,    96,    96,   235,  -219,
      96,    96,    96,  -219,   319,  -219,   241,    37,   281,   242,
     250,   254,    68,   261,   243,  -219,   120,    36,  -219,    -5,
    -219,   258,    96,  -219,    12,  -219,    64,  -219,    95,  -219,
     107,  -219,  -219,    96,   293,  -219,  -219,   268,  -219,  -219,
      81,  -219,  -219,    32,   262,    96,    96,    96,   144,   265,
    -219,  -219,   308,  -219,   269,   308,   308,   308,   308,  -219,
     282,  -219,  -219,   264,   275,   283,  -219,    96,   287,   105,
    -219,   118,   129,   153,   186,   326,   160,   160,  -219,   289,
     328,   330,  -219,  -219,  -219,  -219,  -219,  -219,   332,   333,
     334,   342,   344,   304,   306,   309,   310,   144,  -219,   313,
     348,   352,   353,   355,   356,  -219,  -219,  -219,  -219,  -219,
     346,   366,   367,   368,   369,   370,  -219,   329,   331,   335,
     336,   337,   371,   371,   371,   371,   371,   287
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     6,     1,     0,     0,    13,    12,    15,    16,
      14,     0,     0,     0,     0,     0,     8,     0,     0,     3,
       0,    11,     7,     0,     0,     0,    18,     2,    21,     0,
       0,    10,     0,     0,     0,     0,     0,   112,   114,   115,
     110,   111,     0,   113,     0,     0,     0,    43,    48,    49,
      57,    27,    28,    29,    30,     0,     0,     0,     0,    35,
       0,     0,    21,     0,     0,    38,     0,     0,     0,     0,
       0,    50,     0,     0,    58,    24,    25,    92,    95,    97,
      99,   101,    26,   103,   107,     5,     0,    87,    72,    87,
      84,    87,    75,    87,    81,    87,    78,     0,   121,     0,
       0,   118,   115,     0,   106,    93,   104,   105,    31,    37,
      32,    33,   116,    34,     0,   123,   122,   124,   125,     0,
       0,    22,    19,    17,    21,    41,     0,    40,     0,     0,
      55,     0,     0,     0,   132,   133,   126,   127,   128,   129,
     130,   131,     0,     0,   134,   135,     0,     9,     0,     0,
      73,     0,     0,    85,     0,    76,     0,    82,     0,    79,
      60,    61,   120,     0,     0,     0,     0,     0,   118,   116,
       0,     0,   121,   109,     0,    20,     0,     0,     0,     0,
       0,     0,    53,     0,    94,    96,    98,   100,   102,   115,
      71,     0,     0,    86,   115,    83,   115,    74,   115,    80,
     115,    77,   117,     0,     0,    91,    63,     0,    36,    62,
       0,   108,    42,     0,     0,     0,     0,     0,     0,     0,
      51,    56,     0,    89,     0,     0,     0,     0,     0,   119,
       0,    90,    23,     0,     0,     0,    52,     0,   110,     0,
      88,     0,     0,     0,     0,     0,     0,     0,    39,     0,
       0,     0,    64,    68,    65,    67,    66,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,     0,
       0,     0,     0,     0,     0,    44,    45,    47,    46,    54,
       0,     0,     0,     0,     0,     0,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -219,  -219,  -219,  -219,  -219,  -219,    82,   -23,  -219,  -219,
     -51,  -219,   338,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -123,  -218,   259,   180,    39,   -36,
     -27,   345,   266,  -111,   246,   252,   -95,   247,   -38,   227,
    -219,  -219,  -219,  -219
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,    17,    24,    11,    62,    28,   123,
      63,    64,   108,    65,    66,    67,    68,    69,    70,    71,
     220,   182,    72,    73,    74,   239,    75,    88,   150,   168,
     165,    77,    78,    79,    80,    81,    82,    83,    84,   163,
     120,   142,   143,   146
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      27,    76,   161,   101,   104,   179,    85,   241,   242,   243,
     244,   121,   115,    12,   116,   117,   118,    37,    38,   102,
      40,    41,   185,     3,    42,   148,     4,    43,   109,   109,
     152,    14,   113,   154,   119,    76,    44,   190,    98,    19,
     156,   158,   100,   125,    15,   127,    98,   129,   166,   130,
     222,    97,   103,    97,    13,   144,   145,    61,    37,    38,
     102,    40,    41,    98,   149,    42,    20,   225,    43,   149,
     160,   162,   149,   175,    22,   241,   242,   243,   244,   149,
     149,    37,    38,   102,    40,    41,    98,   167,    42,    99,
     100,    43,   100,   103,    29,    18,    30,    76,    61,   176,
      44,    45,    46,    25,   183,   218,   219,    37,    38,   102,
      40,    41,    86,    21,    42,    98,   103,    43,   202,   226,
     203,    61,   191,   263,   265,   195,    44,   197,   153,   199,
     155,   201,   157,   232,   159,   203,   211,   134,   135,   206,
     207,   213,   103,   208,   209,   162,    98,    61,    26,    23,
     227,   264,   266,    32,    33,    34,    35,    36,    98,   251,
     177,   252,   228,    31,    87,   224,   258,   259,   260,   261,
     262,    89,   251,   177,   253,    91,   229,    37,    38,   189,
      40,    41,    93,   251,    42,   254,    95,    43,   233,   234,
     235,    45,    46,   178,    26,   236,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,   178,   251,    42,   255,
     249,    43,   103,    90,    92,    94,    96,    61,   106,   107,
      44,    45,    46,    47,    48,    49,    50,   111,   112,    51,
      52,    53,    54,    55,    56,    57,    58,   114,    59,    60,
     251,    61,   256,   122,   279,    37,    38,   194,    40,    41,
     124,   126,    42,   128,   131,    43,    37,    38,   196,    40,
      41,   147,   132,    42,    44,   133,    43,    37,    38,   198,
      40,    41,   151,   164,    42,    44,   169,    43,   171,   170,
     103,   172,   181,   173,   174,    61,    44,   193,   192,   204,
     167,   103,   205,   212,   214,   215,    61,     6,     7,     8,
       9,    10,   103,   216,    16,   217,   230,    61,    37,    38,
     200,    40,    41,   221,   223,    42,   237,   246,    43,    37,
      38,   102,   238,    41,   231,   240,    42,    44,   247,    43,
      37,    38,   102,    40,    41,   248,   245,   250,    44,   257,
      43,   267,   268,   103,   269,   270,   271,   272,    61,     6,
       7,     8,     9,    10,   103,   273,   275,   274,   276,    61,
     286,   277,   278,   280,   281,   103,   134,   135,   282,   283,
      61,   284,   285,   136,   137,   138,   139,   140,   141,   287,
     288,   289,   290,   291,   292,   297,   293,   180,   186,   105,
     294,   295,   296,   188,   110,   187,     0,     0,   184,   210
};

static const yytype_int16 yycheck[] =
{
      23,    28,    97,    39,    42,   128,    29,   225,   226,   227,
     228,    62,     6,     6,     8,     9,    10,    11,    12,    13,
      14,    15,   133,     0,    18,    16,    46,    21,    55,    56,
      16,    13,    59,    16,    61,    62,    30,   148,    51,    53,
      16,    16,    55,    66,     3,    68,    51,    70,    16,    72,
      55,    16,    46,    16,    47,    19,    20,    51,    11,    12,
      13,    14,    15,    51,    55,    18,    51,    55,    21,    55,
      97,    98,    55,   124,    13,   293,   294,   295,   296,    55,
      55,    11,    12,    13,    14,    15,    51,    55,    18,    54,
      55,    21,    55,    46,    52,    13,    54,   124,    51,   126,
      30,    31,    32,    21,   131,    37,    38,    11,    12,    13,
      14,    15,    30,    51,    18,    51,    46,    21,    52,    55,
      54,    51,   149,   246,   247,   152,    30,   154,    89,   156,
      91,   158,    93,    52,    95,    54,   174,    17,    18,   166,
     167,   177,    46,   170,   171,   172,    51,    51,     4,    52,
      55,   246,   247,     6,     7,     8,     9,    10,    51,    54,
      13,    56,    55,    13,    13,   192,     6,     7,     8,     9,
      10,    13,    54,    13,    56,    13,   203,    11,    12,    13,
      14,    15,    13,    54,    18,    56,    13,    21,   215,   216,
     217,    31,    32,    46,     4,   218,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    46,    54,    18,    56,
     237,    21,    46,    33,    34,    35,    36,    51,    13,    13,
      30,    31,    32,    33,    34,    35,    36,    13,    13,    39,
      40,    41,    42,    43,    44,    45,    46,    13,    48,    49,
      54,    51,    56,     5,   267,    11,    12,    13,    14,    15,
      53,    51,    18,    51,    51,    21,    11,    12,    13,    14,
      15,    13,    23,    18,    30,    22,    21,    11,    12,    13,
      14,    15,    54,    13,    18,    30,    13,    21,    16,    54,
      46,    51,    33,    52,    52,    51,    30,    13,    55,    16,
      55,    46,    56,    52,    13,    53,    51,     6,     7,     8,
       9,    10,    46,    53,    13,    51,    13,    51,    11,    12,
      13,    14,    15,    52,    56,    18,    51,    53,    21,    11,
      12,    13,    14,    15,    56,    56,    18,    30,    53,    21,
      11,    12,    13,    14,    15,    52,    54,    50,    30,    13,
      21,    52,    14,    46,    14,    13,    13,    13,    51,     6,
       7,     8,     9,    10,    46,    13,    52,    13,    52,    51,
      14,    52,    52,    50,    16,    46,    17,    18,    16,    16,
      51,    16,    16,    24,    25,    26,    27,    28,    29,    13,
      13,    13,    13,    13,    55,    14,    55,   128,   142,    44,
      55,    55,    55,   146,    56,   143,    -1,    -1,   132,   172
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    58,    59,     0,    46,    60,     6,     7,     8,     9,
      10,    63,     6,    47,    13,     3,    13,    61,    63,    53,
      51,    51,    13,    52,    62,    63,     4,    64,    65,    52,
      54,    13,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    18,    21,    30,    31,    32,    33,    34,    35,
      36,    39,    40,    41,    42,    43,    44,    45,    46,    48,
      49,    51,    64,    67,    68,    70,    71,    72,    73,    74,
      75,    76,    79,    80,    81,    83,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    64,    63,    13,    84,    13,
      84,    13,    84,    13,    84,    13,    84,    16,    51,    54,
      55,    86,    13,    46,    95,    88,    13,    13,    69,    87,
      69,    13,    13,    87,    13,     6,     8,     9,    10,    87,
      97,    67,     5,    66,    53,    64,    51,    64,    51,    64,
      64,    51,    23,    22,    17,    18,    24,    25,    26,    27,
      28,    29,    98,    99,    19,    20,   100,    13,    16,    55,
      85,    54,    16,    85,    16,    85,    16,    85,    16,    85,
      87,    93,    87,    96,    13,    87,    16,    55,    86,    13,
      54,    16,    51,    52,    52,    67,    87,    13,    46,    81,
      83,    33,    78,    87,    89,    90,    91,    92,    94,    13,
      90,    87,    55,    13,    13,    87,    13,    87,    13,    87,
      13,    87,    52,    54,    16,    56,    87,    87,    87,    87,
      96,    95,    52,    86,    13,    53,    53,    51,    37,    38,
      77,    52,    55,    56,    87,    55,    55,    55,    55,    87,
      13,    56,    52,    87,    87,    87,    64,    51,    14,    82,
      56,    82,    82,    82,    82,    54,    53,    53,    52,    87,
      50,    54,    56,    56,    56,    56,    56,    13,     6,     7,
       8,     9,    10,    81,    93,    81,    93,    52,    14,    14,
      13,    13,    13,    13,    13,    52,    52,    52,    52,    64,
      50,    16,    16,    16,    16,    16,    14,    13,    13,    13,
      13,    13,    55,    55,    55,    55,    55,    14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    62,    63,    63,    63,    63,    63,    64,    65,    66,
      67,    67,    67,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    69,    69,    68,    70,
      70,    70,    71,    72,    73,    73,    73,    73,    74,    75,
      68,    76,    77,    77,    78,    78,    79,    80,    68,    68,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    82,
      82,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    84,    84,    85,    85,
      86,    86,    87,    87,    88,    88,    89,    89,    90,    90,
      91,    91,    92,    92,    93,    93,    94,    94,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    96,
      96,    96,    97,    97,    97,    97,    98,    98,    98,    98,
      98,    98,    99,    99,   100,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     5,     0,     7,     0,     2,     1,     4,
       2,     0,     1,     1,     1,     1,     1,     3,     1,     1,
       3,     0,     2,     5,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     3,     1,     1,     6,
       2,     2,     4,     1,     8,     8,     8,     8,     1,     1,
       1,     4,     2,     0,     6,     0,     4,     1,     1,     7,
       3,     3,     4,     4,     7,     7,     7,     7,     7,     5,
       3,     4,     2,     3,     4,     2,     3,     4,     2,     3,
       4,     2,     3,     4,     2,     3,     3,     1,     4,     3,
       4,     3,     1,     2,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     2,     2,     2,     1,     4,     3,
       1,     1,     1,     1,     1,     1,     2,     4,     2,     3,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 132 "src/sintatica.y" /* yacc.c:1646  */
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
                    	code = cabecalho.str() + "\nusing namespace std;\n\n" + incluiLista() + variaveis.str() + (yyvsp[-5]).traducao + "\n\nint main(void)\n{\n" + (yyvsp[0]).traducao + "\n\treturn 0;\n}\n\n"; 
                    	while(code.find("\n;\n") != npos)
                    		code.replace(code.find("\n;\n"), 3, "\n");
                    	while(code.find(";;") != npos)
                    		code.replace(code.find(";;"), 2, ";");
                    	cout << code;
                    	myfile << code;
                    }
                    else
                    {
                    	code = cabecalho.str() + "\nusing namespace std;\n\n" + variaveis.str() + (yyvsp[-5]).traducao + "\n\nint main(void)\n{\n" + (yyvsp[0]).traducao + "\n\treturn 0;\n}\n\n"; 
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
            }
#line 1689 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 186 "src/sintatica.y" /* yacc.c:1646  */
    {
				gera_variavel_temporaria((yyvsp[-2]).label,(yyvsp[-1]).label, 0, true);
				(yyval).traducao = (yyvsp[-4]).traducao + "\n\t";
			}
#line 1698 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 190 "src/sintatica.y" /* yacc.c:1646  */
    {(yyval).traducao = "";}
#line 1704 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 193 "src/sintatica.y" /* yacc.c:1646  */
    {
				for (int i = 0; i < retorno.size(); ++i)
				{
					if(retorno[i] != (yyvsp[-4]).tipo)
					{
	                    add_erro("Erro na função \"" + nome_temp_funcao + "\". Uma função do tipo \"" + (yyvsp[-4]).tipo + "\" não pode ter um retorno com o tipo \"" + retorno[i] + "\".");
	                    break;
                	}
				}
				retorno.clear();
				if((yyvsp[-4]).tipo == "")
					(yyval).traducao = (yyvsp[-6]).traducao + "\nvoid " + (yyvsp[-4]).traducao + "(" + (yyvsp[-2]).traducao + ")\n{\n" + (yyvsp[0]).traducao + "\n\treturn;\n}\n";
				else if((yyvsp[-4]).tipo == "int")
					(yyval).traducao = (yyvsp[-6]).traducao + "\n" + (yyvsp[-4]).traducao + "(" + (yyvsp[-2]).traducao + ")\n{\n" + (yyvsp[0]).traducao + "\n\treturn 0;\n}\n";
                else if((yyvsp[-4]).tipo == "float")
                    (yyval).traducao = (yyvsp[-6]).traducao + "\n" + (yyvsp[-4]).traducao + "(" + (yyvsp[-2]).traducao + ")\n{\n" + (yyvsp[0]).traducao + "\n\treturn 0.0;\n}\n";
                else if((yyvsp[-4]).tipo == "boolean")
                    (yyval).traducao = (yyvsp[-6]).traducao + "\n" + (yyvsp[-4]).traducao + "(" + (yyvsp[-2]).traducao + ")\n{\n" + (yyvsp[0]).traducao + "\n\treturn 0;\n}\n";
                else if((yyvsp[-4]).tipo == "char")
                    (yyval).traducao = (yyvsp[-6]).traducao + "\n" + (yyvsp[-4]).traducao + "(" + (yyvsp[-2]).traducao + ")\n{\n" + (yyvsp[0]).traducao + "\n\treturn '0';\n}\n";
                else if((yyvsp[-4]).tipo == "string")
                    (yyval).traducao = (yyvsp[-6]).traducao + "\n" + (yyvsp[-4]).traducao + "(" + (yyvsp[-2]).traducao + ")\n{\n" + (yyvsp[0]).traducao + "\n\treturn NULL;\n}\n";
			}
#line 1732 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 216 "src/sintatica.y" /* yacc.c:1646  */
    { (yyval).traducao = "";}
#line 1738 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 219 "src/sintatica.y" /* yacc.c:1646  */
    {
				nome_temp_funcao = (yyvsp[0]).label;
				string nome_temp = gera_ID_funcao((yyvsp[-1]).label, (yyvsp[0]).label);
				if((yyvsp[-1]).label == "string")
					(yyval).traducao = "char *" + nome_temp;
				else if((yyvsp[-1]).label == "boolean")
					(yyval).traducao = "int " + nome_temp;
				else
					(yyval).traducao = (yyvsp[-1]).label + " " + nome_temp;
				(yyval).tipo = (yyvsp[-1]).label;
				(yyval).label = nome_temp;
				mapa_funcao[(yyvsp[0]).label].parametros = vector<string>();
				nivel++;
                pilha_variaveis.push_back(map<string, info_variavel>());
			}
#line 1758 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 235 "src/sintatica.y" /* yacc.c:1646  */
    {
				string nome_temporario = gera_ID_funcao("void", (yyvsp[0]).label);
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = nome_temporario;
				(yyval).tipo = "";
				(yyval).tamanho = (yyvsp[0]).tamanho;
				nome_temp_funcao = (yyvsp[0]).label;
				mapa_funcao[(yyvsp[0]).label].parametros = vector<string>();
				nivel++;
                pilha_variaveis.push_back(map<string, info_variavel>());
			}
#line 1774 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 248 "src/sintatica.y" /* yacc.c:1646  */
    {
				string var_temp = gera_variavel_temporaria((yyvsp[-1]).label, (yyvsp[0]).label);
				info_variavel var = buscaID((yyvsp[0]).label);
				var.declarar = false;
				alteraID((yyvsp[0]).label, var);
				mapa_funcao[nome_temp_funcao].parametros.push_back((yyvsp[-1]).label);
				if((yyvsp[-1]).label == "boolean")
					(yyval).traducao = (yyvsp[-3]).traducao + ", int " + var_temp;
				else if((yyvsp[-1]).label == "string")
					(yyval).traducao = (yyvsp[-3]).traducao + ", char *" + var_temp;
				else
					(yyval).traducao = (yyvsp[-3]).traducao + ", " + (yyvsp[-1]).label + " " + var_temp;
				
			}
#line 1793 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 263 "src/sintatica.y" /* yacc.c:1646  */
    {
				string var_temp = gera_variavel_temporaria((yyvsp[-1]).label, (yyvsp[0]).label);
				info_variavel var = buscaID((yyvsp[0]).label);
				var.declarar = false;
				alteraID((yyvsp[0]).label, var);
				mapa_funcao[nome_temp_funcao].parametros.push_back((yyvsp[-1]).label);
				if((yyvsp[-1]).label == "boolean")
					(yyval).traducao = "int " + var_temp;
				else if((yyvsp[-1]).label == "string")
					(yyval).traducao = "char *" + var_temp;
				else
					(yyval).traducao = (yyvsp[-1]).label + " " + var_temp;
				
			}
#line 1812 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 277 "src/sintatica.y" /* yacc.c:1646  */
    { (yyval).traducao = "";}
#line 1818 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 280 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
			}
#line 1826 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 284 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
			}
#line 1834 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 288 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
			}
#line 1842 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 292 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
			}
#line 1850 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 296 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
			}
#line 1858 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 301 "src/sintatica.y" /* yacc.c:1646  */
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

                while(((yyvsp[-1]).traducao.find(";") == 0) || ((yyvsp[-1]).traducao.find("\n") == 0))
            		(yyvsp[-1]).traducao.replace(0,1,"");

                (yyval).traducao = (yyvsp[-1]).traducao;
                nivel--;
                pilha_variaveis.pop_back();
            }
#line 1893 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 333 "src/sintatica.y" /* yacc.c:1646  */
    {
                nivel++;
                pilha_variaveis.push_back(map<string, info_variavel>());
                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 1903 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 340 "src/sintatica.y" /* yacc.c:1646  */
    {
                map<string, info_variavel>().clear();
                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 1912 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 346 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao;
            }
#line 1920 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 350 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = "";
                (yyval).label = "";
            }
#line 1929 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 355 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = "\n" + (yyvsp[-1]).traducao + (yyvsp[0]).traducao;
            }
#line 1937 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 360 "src/sintatica.y" /* yacc.c:1646  */
    {
            	if(mapa_funcao[(yyvsp[-3]).label].nome_temp == "")
                {
                	stringstream msg_erro;
                	msg_erro << "Erro na linha " << numero_linha << ": Função \"" << (yyvsp[-3]).label << "\" não declarada.";
                	add_erro(msg_erro.str());
                }

                int i;
                if(mapa_funcao[(yyvsp[-3]).label].parametros.size() == argumentos.size())
                {
                	for(i = 0; i < argumentos.size(); i++)
                	{
                		if(mapa_funcao[(yyvsp[-3]).label].parametros[i] != argumentos[i])
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

                info_funcao var = mapa_funcao[(yyvsp[-3]).label];
                (yyval).label = var.nome_temp + "(" + (yyvsp[-1]).traducao + ")";
                (yyval).traducao = (yyvsp[-1]).label + "\n\t" + var.nome_temp + "(" + (yyvsp[-1]).traducao + ");\n";
                (yyval).tipo = var.tipo;
            }
#line 1977 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 397 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 1986 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 403 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 1995 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 409 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 2004 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 415 "src/sintatica.y" /* yacc.c:1646  */
    {
				if(pilha_fim_loop.size() > 0)
					(yyval).traducao = "\n\tgoto " + pilha_fim_loop.back() + ";\n";
				else
				{
					stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Para usar o comando break é necessário estar dentro de um loop.\n";
                    add_erro(msg_erro.str());
				}
			}
#line 2019 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 426 "src/sintatica.y" /* yacc.c:1646  */
    {
				if(pilha_inicio_loop.size() > 0)
					(yyval).traducao = "\n\tgoto " + pilha_inicio_loop.back() + ";\n";
				else
				{
					stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Para usar o comando continue é necessário estar dentro de um loop.\n";
                    add_erro(msg_erro.str());
				}
			}
#line 2034 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 437 "src/sintatica.y" /* yacc.c:1646  */
    {
				if(pilha_fim_loop.size() > 0)
					(yyval).traducao = "\n\tgoto " + pilha_fim_loop[0] + ";\n";
				else
				{
					stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Para usar o comando superBreak é necessário estar dentro de um loop.";
                    add_erro(msg_erro.str());
				}
			}
#line 2049 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 448 "src/sintatica.y" /* yacc.c:1646  */
    {
				if(pilha_inicio_loop.size() > 0)
					(yyval).traducao = "\n\tgoto " + pilha_inicio_loop[0] + ";\n";
				else
				{
					stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Para usar o comando superContinue é necessário estar dentro de um loop.";
                    add_erro(msg_erro.str());
				}
			}
#line 2064 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 460 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 2073 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 465 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao + "\n\tcout << endl;\n";
            }
#line 2082 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 470 "src/sintatica.y" /* yacc.c:1646  */
    {
                info_variavel var = buscaID((yyvsp[0]).label);
                (yyval).label = var.nome_temp;
                (yyval).tipo = var.tipo;
                if(var.tipo == "string")
                {
                    (yyval).tamanho = 1024;
                    var.tamanho = 1024;
                    alteraID((yyvsp[0]).label, var);
                    (yyval).traducao = "\n\tcin.getline(" + var.nome_temp + ", 1024);\n\t";
                }
                else if(var.tipo == "boolean")
                {
                	string nome_temp_leitura = gera_variavel_temporaria("string", "teste", 6);
                	string nome_temp_teste = gera_variavel_temporaria("int", "teste2");
				
                	(yyval).traducao = "\n\tcin >> " + nome_temp_leitura + ";\n\t" + nome_temp_teste + " = strcmp(" + nome_temp_leitura + ", \"true\" );\n\t";
                	(yyval).traducao += "if(" + nome_temp_teste + " == 0) " + var.nome_temp + " = 1;\n\t";
                	(yyval).traducao += "if(" + nome_temp_teste + " != 0) " + var.nome_temp + " = 0;\n\t";

                	(yyval).tamanho = var.tamanho;
                }
                else
                {
                	(yyval).traducao = "\n\tcin >> " + var.nome_temp + ";\n\t";
                    (yyval).tamanho = var.tamanho;
                }
            }
#line 2115 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 500 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao + "\n\treturn " + (yyvsp[0]).label + ";\n\t";
				retorno.push_back((yyvsp[0]).tipo);
			}
#line 2124 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 505 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "\n\treturn;\n\t";
				retorno.push_back("");
			}
#line 2133 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 511 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				if((yyvsp[0]).tipo == "void")
				{
					stringstream msg_erro;
					msg_erro << "Erro na linha: " << numero_linha << ": A função não possui valor de retorno.";
					add_erro(msg_erro.str());
				}
				if((yyvsp[0]).tipo == "boolean")
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\n\tif(" + (yyvsp[0]).label + ") cout << \"true\";\n\tif(!" + (yyvsp[0]).label + ") cout << \"false\";\n";
				else
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\n\tcout << " + (yyvsp[0]).label + ";\n";
			}
#line 2151 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 525 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				if((yyvsp[0]).tipo == "void")
				{
					stringstream msg_erro;
					msg_erro << "Erro na linha: " << numero_linha << ": A função não possui valor de retorno.";
					add_erro(msg_erro.str());
				}
				if((yyvsp[0]).tipo == "boolean")
					(yyval).traducao = (yyvsp[0]).traducao + "\n\tif(" + (yyvsp[0]).label + ") cout << \"true\";\n\tif(!" + (yyvsp[0]).label + ") cout << \"false\";\n";	
				else
					(yyval).traducao = (yyvsp[0]).traducao + "\n\tcout << " + (yyvsp[0]).label + ";\n";
			}
#line 2169 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 540 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 2178 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 546 "src/sintatica.y" /* yacc.c:1646  */
    {
                if((yyvsp[-1]).tipo != "boolean")
                {
                	stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". É esperado uma operação cujo resultado seja boolean entre os parênteses.";
                    add_erro(msg_erro.str());
                }
                (yyval).traducao = "\n\n" + pilha_labels_loop.top() + ":\n\n\t" + (yyvsp[-4]).traducao + (yyvsp[-1]).traducao;
                pilha_labels_loop.pop();
                (yyval).traducao += "\n\tif(" + (yyvsp[-1]).label + ") goto " + pilha_labels_loop.top() + ";\n"; 
                pilha_labels_loop.pop();
                (yyval).traducao += pilha_labels_loop.top() + ":\n";
                pilha_labels_loop.pop();
                pilha_inicio_loop.pop_back();
                pilha_fim_loop.pop_back();
            }
#line 2199 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 563 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = "\n\n" + (yyvsp[-1]).traducao + (yyvsp[0]).traducao + pilha_labels_loop.top();
                pilha_labels_loop.pop();
                (yyval).traducao += "\n\tgoto " + pilha_labels_loop.top() + ";\n";
                pilha_labels_loop.pop();
                (yyval).traducao += "\n" + pilha_labels_loop.top() + ":\n";
                pilha_labels_loop.pop();
                pilha_inicio_loop.pop_back();
                pilha_fim_loop.pop_back();
            }
#line 2214 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 574 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = "\n\n" + (yyvsp[-1]).traducao + (yyvsp[0]).traducao + "\n\tgoto " + pilha_labels_loop.top() + ";\n";
                pilha_labels_loop.pop();
                (yyval).traducao += "\n" + pilha_labels_loop.top() + ":\n";
                pilha_labels_loop.pop();
                pilha_inicio_loop.pop_back();
                pilha_fim_loop.pop_back();
            }
#line 2227 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 584 "src/sintatica.y" /* yacc.c:1646  */
    {

                if((yyvsp[-1]).tipo != "boolean")
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
                (yyval).traducao = "\n" + pilha_labels_loop.top() + ":\n\t" + (yyvsp[-1]).traducao + "\t";
                pilha_labels_loop.pop();
                string var = gera_variavel_temporaria("int");
                (yyval).traducao += var + " = !" + (yyvsp[-1]).label + ";\n\tif(" + var + ") goto " + pilha_labels_loop.top() + ";\n"; 
                pilha_labels_loop.pop();

            }
#line 2254 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 608 "src/sintatica.y" /* yacc.c:1646  */
    {
                nivel++;
                pilha_variaveis.push_back(map<string, info_variavel>());
            }
#line 2263 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 614 "src/sintatica.y" /* yacc.c:1646  */
    {
                if((yyvsp[-3]).tipo != "boolean")
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
                (yyval).traducao = (yyvsp[-5]).traducao + pilha_labels_loop.top() + ":\n\t" + (yyvsp[-3]).traducao + "\t";
                pilha_labels_loop.pop();
                string var = gera_variavel_temporaria("int");
                (yyval).traducao += var + " = !" + (yyvsp[-3]).label + ";\n\tif(" + var + ") goto " + pilha_labels_loop.top() + ";\n";
                pilha_labels_loop.pop();
                pilha_labels_loop.push((yyvsp[-1]).traducao);
            }
#line 2287 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 634 "src/sintatica.y" /* yacc.c:1646  */
    {
                if((yyvsp[-3]).tipo != "boolean")
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
                (yyval).traducao = (yyvsp[-5]).traducao + pilha_labels_loop.top() + ":\n\t" + (yyvsp[-3]).traducao + "\t";
                pilha_labels_loop.pop();
                string var = gera_variavel_temporaria("int");
                (yyval).traducao += var + " = !" + (yyvsp[-3]).label + ";\n\tif(" + var + ") goto " + pilha_labels_loop.top() + ";\n";
                pilha_labels_loop.pop();
                pilha_labels_loop.push((yyvsp[-1]).traducao);
            }
#line 2311 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 654 "src/sintatica.y" /* yacc.c:1646  */
    {
                if((yyvsp[-3]).tipo != "boolean")
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
                (yyval).traducao = (yyvsp[-5]).traducao + "\n" + pilha_labels_loop.top() + ":\n\t" + (yyvsp[-3]).traducao + "\t";
                pilha_labels_loop.pop();
                string var = gera_variavel_temporaria("int");
                (yyval).traducao += var + " = !" + (yyvsp[-3]).label + ";\n\tif(" + var + ") goto " + pilha_labels_loop.top() + ";\n";
                pilha_labels_loop.pop();
                pilha_labels_loop.push((yyvsp[-1]).traducao);
            }
#line 2335 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 674 "src/sintatica.y" /* yacc.c:1646  */
    {
                if((yyvsp[-3]).tipo != "boolean")
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
                (yyval).traducao = (yyvsp[-5]).traducao + "\n" + pilha_labels_loop.top() + ":\n\t" + (yyvsp[-3]).traducao + "\t";
                pilha_labels_loop.pop();
                string var = gera_variavel_temporaria("int");
                (yyval).traducao += var + " = !" + (yyvsp[-3]).label + ";\n\tif(" + var + ") goto " + pilha_labels_loop.top() + ";\n";
                pilha_labels_loop.pop();
                pilha_labels_loop.push((yyvsp[-1]).traducao);
            }
#line 2359 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 695 "src/sintatica.y" /* yacc.c:1646  */
    {
                nivel++;
                pilha_variaveis.push_back(map<string, info_variavel>());
            }
#line 2368 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 701 "src/sintatica.y" /* yacc.c:1646  */
    {
            	string a = geraLabel(); string b = geraLabel();
                pilha_labels_loop.push(b); pilha_labels_loop.push(a);	pilha_labels_loop.push(a);
                pilha_inicio_loop.push_back(pilha_labels_loop.top());
                pilha_fim_loop.push_back(b);
                nivel++;
                pilha_variaveis.push_back(map<string, info_variavel>());
            }
#line 2381 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 711 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 2390 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 717 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = "\n" + (yyvsp[-3]).traducao + (yyvsp[-2]).traducao + "\ngoto " + label_final.top() + ";\n" + pilha_labels_condicional.top() + ":\n";
                pilha_labels_condicional.pop();
                label_final.pop();
           		(yyval).traducao += (yyvsp[-1]).traducao + (yyvsp[0]).traducao + label_final.top() + ":\n";
           		label_final.pop();
			}
#line 2402 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 726 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 2410 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 730 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
			}
#line 2418 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 735 "src/sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2]).tipo != "boolean")
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". É esperado uma operação cujo resultado seja boolean entre os parênteses.";
                    add_erro(msg_erro.str());
                }
                string a = geraLabel();
                label_final.push(label_final.top());
                pilha_labels_condicional.push(a); pilha_labels_condicional.push(a);
                string var = gera_variavel_temporaria("int");
                (yyval).traducao = "\n\t" + (yyvsp[-5]).traducao + "\n\t" + (yyvsp[-2]).traducao + "\t" + var + " = !" + (yyvsp[-2]).label + ";\n\tif(" + var + ") goto " + pilha_labels_condicional.top() + ";\n"; 
                pilha_labels_condicional.pop();
                (yyval).traducao += (yyvsp[0]).traducao + "\ngoto " + label_final.top() + ";\n" + pilha_labels_condicional.top() + ":\n";
                pilha_labels_condicional.pop();
                label_final.pop();
			}
#line 2440 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 753 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
			}
#line 2448 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 758 "src/sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-1]).tipo != "boolean")
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". É esperado uma operação cujo resultado seja boolean entre os parênteses.";
                    add_erro(msg_erro.str());
                }
                string a = geraLabel();	string b = geraLabel();
                label_final.push(a);	label_final.push(a);
                pilha_labels_condicional.push(b); pilha_labels_condicional.push(b);
                string var = gera_variavel_temporaria("int");
                (yyval).traducao = (yyvsp[-1]).traducao + "\t" + var + " = !" + (yyvsp[-1]).label + ";\n\tif(" + var + ") goto " + pilha_labels_condicional.top() + ";\n"; 
                pilha_labels_condicional.pop();
			}
#line 2467 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 774 "src/sintatica.y" /* yacc.c:1646  */
    {
				nivel++;
                pilha_variaveis.push_back(map<string, info_variavel>());
			}
#line 2476 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 780 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 2485 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 785 "src/sintatica.y" /* yacc.c:1646  */
    {
            	if(((yyvsp[-6]).label != (yyvsp[0]).label) || ((yyvsp[-4]).label != (yyvsp[-2]).label))
            	{
            		stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Esperava que as variáveis estivessem cruzadas: a,b = b,a.";
                    add_erro(msg_erro.str());
            	}
            	string var_temp = gera_variavel_temporaria(buscaID((yyvsp[-6]).label).tipo);
                if(buscaID((yyvsp[-6]).label).tipo == "string")
                    (yyval).traducao = "\n\tstrcpy(" + var_temp + ", " + buscaID((yyvsp[-6]).label).nome_temp + ");\n\tstrcpy(" + buscaID((yyvsp[-6]).label).nome_temp + ", " + buscaID((yyvsp[-4]).label).nome_temp + ");\n\tstrcpy(" +  buscaID((yyvsp[-4]).label).nome_temp + ", " + var_temp + ");\n";
                else
                    (yyval).traducao = "\n\t" + var_temp + " = " + buscaID((yyvsp[-6]).label).nome_temp + ";\n\t" + buscaID((yyvsp[-6]).label).nome_temp + " = " + buscaID((yyvsp[-4]).label).nome_temp + ";\n\t" +  buscaID((yyvsp[-4]).label).nome_temp + " = " + var_temp + ";\n";
            }
#line 2503 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 800 "src/sintatica.y" /* yacc.c:1646  */
    {
            	if((buscaID((yyvsp[-2]).label).tipo == "string" && (yyvsp[0]).tipo == "string")||(buscaID((yyvsp[-2]).label).tipo == "string" && (yyvsp[0]).tipo == "char"))
                {
                    info_variavel var = buscaID((yyvsp[-2]).label);
                    var.tamanho += (yyvsp[0]).tamanho;   alteraID((yyvsp[-2]).label, var);                 
                    (yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\tstrcpy(" + buscaID((yyvsp[-2]).label).nome_temp + ", " + (yyvsp[0]).label + ");\n";
                }
                else
                {
                    string tipo = buscaID((yyvsp[-2]).label).tipo;
                    if(mapa_operacoes[tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 1)
                        (yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + buscaID((yyvsp[-2]).label).nome_temp + " = " + "(" + mapa_operacoes[tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo + ")" + (yyvsp[0]).label + ";\n";
                    else if(mapa_operacoes[tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 0)
                        (yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + buscaID((yyvsp[-2]).label).nome_temp + " = " + (yyvsp[0]).label + ";\n";
                    else
                    {
                        stringstream msg_erro;
                        msg_erro << "Erro na linha: " << numero_linha << ". Um valor do tipo \"" << (yyvsp[0]).tipo << "\" não pode ser atribuido à uma variável do tipo \"" << tipo << "\".";
                        add_erro(msg_erro.str());
                    }
                }
                if((yyvsp[0]).tipo == "null" || (yyvsp[0]).tipo == "")
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Operação inválida.";
                    add_erro(msg_erro.str());
                }
            }
#line 2536 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 829 "src/sintatica.y" /* yacc.c:1646  */
    {
            	(yyval).traducao = (yyvsp[0]).traducao + "\n\t" + buscaID((yyvsp[-2]).label).nome_temp + " = " + (yyvsp[0]).label + ";\n";
            }
#line 2544 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 833 "src/sintatica.y" /* yacc.c:1646  */
    {
            	if(mapa_variaveis_globais.find((yyvsp[-2]).label) == mapa_variaveis_globais.end())
                {
                	stringstream msg_erro;
                	msg_erro << "Erro na linha " << numero_linha << ": Variável global \"" << (yyvsp[-2]).label << "\" não declarada.";
                	add_erro(msg_erro.str());
                }
           		info_variavel var = mapa_variaveis_globais[(yyvsp[-2]).label];
            	if((yyvsp[0]).tipo == "null" || (yyvsp[0]).tipo == "")
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Operação inválida.";
                    add_erro(msg_erro.str());
                }
            	if((var.tipo == "string" && (yyvsp[0]).tipo == "string")||(var.tipo == "string" && (yyvsp[0]).tipo == "char"))
                {
                    var.tamanho = (yyvsp[-1]).tamanho;   alteraID((yyvsp[-2]).label, var);                 
                    (yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\tstrcpy(" + buscaID((yyvsp[-3]).label).nome_temp + ", " + (yyvsp[0]).label + ");\n";
                }
                else    
                {
                    string tipo = var.tipo;
                    if(mapa_operacoes[tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 1)
                        (yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + var.nome_temp + " = " + "(" + mapa_operacoes[tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo + ")" + (yyvsp[0]).label + ";\n";
                    else if(mapa_operacoes[tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 0)
                        (yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + var.nome_temp + " = " + (yyvsp[0]).label + ";\n";
                    else
                    {
                        stringstream msg_erro;
                        msg_erro << "Erro na linha: " << numero_linha << ". Um valor do tipo \"" << (yyvsp[0]).tipo << "\" não pode ser atribuido à uma variável do tipo \"" << tipo << "\".";
                        add_erro(msg_erro.str());
                    }
                }
            }
#line 2583 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 868 "src/sintatica.y" /* yacc.c:1646  */
    {
            	string var_temp = gera_variavel_temporaria("int");
            	info_variavel var = buscaID((yyvsp[-3]).label);
            	var.acesso_lista = geraLabel();
            	alteraID((yyvsp[-3]).label, var);
            	string acesso_lista = "\n\tnode *" + buscaID((yyvsp[-3]).label).acesso_lista + ";\n\t" + buscaID((yyvsp[-3]).label).acesso_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID((yyvsp[-3]).label).acesso_lista + ");\n\tif(!" + buscaID((yyvsp[-3]).label).acesso_lista + ") cout << \"Sem memoria disponivel!\\n\";";
            	for (int i = 0; i < indices_temporarios.size(); ++i)
            	{
            		acesso_lista += "\n\tinsereFim(" + buscaID((yyvsp[-3]).label).acesso_lista + ", " + indices_temporarios[i] + ");";
            	}
            	indices_temporarios.clear();
            	if(var.tipo == "string" && (yyvsp[0]).tipo == "string")
            	{
            		(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\n\t" + acesso_lista + "\n\t" + var_temp + " = mapper(" + buscaID((yyvsp[-3]).label).acesso_lista + ", " + buscaID((yyvsp[-3]).label).nome_lista + ");\n\t";
            		(yyval).traducao += "strcpy(" + buscaID((yyvsp[-3]).label).nome_temp + "[" + var_temp +  "].c, " + (yyvsp[0]).label + ");\n";
            	}
            	else
            	{
	            	if(mapa_operacoes[buscaID((yyvsp[-3]).label).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 1)
	                    (yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\n\t" + acesso_lista + "\n\t" + var_temp + " = mapper(" + buscaID((yyvsp[-3]).label).acesso_lista + ", " + buscaID((yyvsp[-3]).label).nome_lista + ");\n\t" + buscaID((yyvsp[-3]).label).nome_temp + "[" + var_temp +  "] = (" + mapa_operacoes[buscaID((yyvsp[-3]).label).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo + ")" + (yyvsp[0]).label + ";\n";
	                else if(mapa_operacoes[buscaID((yyvsp[-3]).label).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 0)
	                    (yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\n\t" + acesso_lista + "\n\t" + var_temp + " = mapper(" + buscaID((yyvsp[-3]).label).acesso_lista + ", " + buscaID((yyvsp[-3]).label).nome_lista + ");\n\t" + buscaID((yyvsp[-3]).label).nome_temp + "[" + var_temp +  "] = " + (yyvsp[0]).label + ";\n";
	                else
	                {
	                    stringstream msg_erro;
	                    msg_erro << "Erro na linha: " << numero_linha << ". Um valor do tipo \"" << (yyvsp[0]).tipo << "\" não pode ser atribuido à uma variável do tipo \"" << buscaID((yyvsp[-3]).label).tipo << "\".";
	                    add_erro(msg_erro.str());
	                }
	                if(mapa_operacoes[buscaID((yyvsp[-3]).label).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo == "null" || mapa_operacoes[buscaID((yyvsp[-3]).label).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo == "")
	                {
	                    stringstream msg_erro;
	                    msg_erro << "Erro na linha: " << numero_linha << ". Operação inválida.";
	                    add_erro(msg_erro.str());
	                }
	            }
            }
#line 2624 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 905 "src/sintatica.y" /* yacc.c:1646  */
    {
            	(yyval).traducao = slice((yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), "[", (yyvsp[-2]), "]");
            }
#line 2632 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 909 "src/sintatica.y" /* yacc.c:1646  */
    {
            	(yyval).traducao = slice((yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), "[", (yyvsp[-2]), "]");
            }
#line 2640 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 913 "src/sintatica.y" /* yacc.c:1646  */
    {
            	(yyval).traducao = slice((yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), "[", (yyvsp[-2]), "]");
            }
#line 2648 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 917 "src/sintatica.y" /* yacc.c:1646  */
    {
            	(yyval).traducao = slice((yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), "[", (yyvsp[-2]), "]");
            }
#line 2656 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 921 "src/sintatica.y" /* yacc.c:1646  */
    {
            	(yyval).traducao = slice((yyvsp[-6]), (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), "[", (yyvsp[-2]), "]");
            }
#line 2664 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 926 "src/sintatica.y" /* yacc.c:1646  */
    {
				indices_fatias.push_back((yyvsp[-2]).label); indices_fatias.push_back((yyvsp[0]).label);
				(yyval).traducao = "";
			}
#line 2673 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 931 "src/sintatica.y" /* yacc.c:1646  */
    {
				indices_fatias.push_back((yyvsp[-2]).label); indices_fatias.push_back((yyvsp[0]).label);
				(yyval).traducao = "";
			}
#line 2682 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 937 "src/sintatica.y" /* yacc.c:1646  */
    {
                info_variavel atributos = { (yyvsp[-3]).label, gera_variavel_temporaria((yyvsp[-3]).label, (yyvsp[-2]).label)};
                if(mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 1)
                    (yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + atributos.nome_temp + " = " + "(" + mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo + ")" + (yyvsp[0]).label + ";";
                else if(mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 0)
                    (yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + atributos.nome_temp + " = " + (yyvsp[0]).label + ";";
                else{
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Um valor do tipo \"" << (yyvsp[0]).tipo << "\" não pode ser atribuido à uma variável do tipo \"" << (yyvsp[-3]).label << "\".";
                    add_erro(msg_erro.str());
                }
            }
#line 2699 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 950 "src/sintatica.y" /* yacc.c:1646  */
    {
            	(yyval).traducao = "";
            	for (int i = 0; i < multiplos_ids.size(); ++i)
            	{
            		info_variavel atributos = { (yyvsp[-1]).label, gera_variavel_temporaria((yyvsp[-1]).label, multiplos_ids[i])};
                	(yyval).traducao += "\n\t" + atributos.nome_temp + " = " + "0" + ";";
            	}
            	multiplos_ids.clear();
            }
#line 2713 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 960 "src/sintatica.y" /* yacc.c:1646  */
    {
            	insere_lista = true;
            	gera_variavel_temporaria((yyvsp[-2]).label, (yyvsp[-1]).label);
            	info_variavel var = buscaID((yyvsp[-1]).label);
            	var.nome_lista = geraLabel();
            	alteraID((yyvsp[-1]).label, var);
            	string insere_lista = "\n\tnode *" + buscaID((yyvsp[-1]).label).nome_lista + ";\n\t" + buscaID((yyvsp[-1]).label).nome_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID((yyvsp[-1]).label).nome_lista + ");\n\tif(!" + buscaID((yyvsp[-1]).label).nome_lista + ") cout << \"Sem memoria disponivel!\\n\";";
            	for (int i = 0; i < indices_temporarios.size(); ++i)
            	{
            		insere_lista += "\n\tinsereFim(" + buscaID((yyvsp[-1]).label).nome_lista + ", " + indices_temporarios[i] + ");";
            	}
            	indices_temporarios.clear();
            	(yyval).traducao = "\n" + (yyvsp[0]).traducao + "\n\t" + insere_lista + "\n\n\t" + (yyvsp[-2]).label + " " + buscaID((yyvsp[-1]).label).nome_temp + "[" + (yyvsp[0]).label + "];\n";
            }
#line 2732 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 975 "src/sintatica.y" /* yacc.c:1646  */
    {
                info_variavel atributos = { (yyvsp[-3]).label, gera_variavel_temporaria((yyvsp[-3]).label, (yyvsp[-2]).label)};

                if(mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 1)
                    (yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + atributos.nome_temp + " = " + "(" + mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo + ")" + (yyvsp[0]).label + ";";
                else if(mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 0)
                    (yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + atributos.nome_temp + " = " + (yyvsp[0]).label + ";";
                else
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Um valor do tipo \"" << (yyvsp[0]).tipo << "\" não pode ser atribuido à uma variável do tipo \"" << (yyvsp[-3]).label << "\".";
                    add_erro(msg_erro.str());
                }
            }
#line 2751 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 990 "src/sintatica.y" /* yacc.c:1646  */
    {
            	(yyval).traducao = "";
            	for (int i = 0; i < multiplos_ids.size(); ++i)
            	{
	                info_variavel atributos = { (yyvsp[-1]).label, gera_variavel_temporaria((yyvsp[-1]).label, multiplos_ids[i])};
	                (yyval).traducao += "\n\t" + atributos.nome_temp + " = " + "0.0" + ";";
	            }
	            multiplos_ids.clear();
            }
#line 2765 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1000 "src/sintatica.y" /* yacc.c:1646  */
    {
            	insere_lista = true;
            	gera_variavel_temporaria((yyvsp[-2]).label, (yyvsp[-1]).label);
            	info_variavel var = buscaID((yyvsp[-1]).label);
            	var.nome_lista = geraLabel();
            	alteraID((yyvsp[-1]).label, var);
            	string insere_lista = "\n\tnode *" + buscaID((yyvsp[-1]).label).nome_lista + ";\n\t" + buscaID((yyvsp[-1]).label).nome_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID((yyvsp[-1]).label).nome_lista + ");\n\tif(!" + buscaID((yyvsp[-1]).label).nome_lista + ") cout << \"Sem memoria disponivel!\\n\";";
            	for (int i = 0; i < indices_temporarios.size(); ++i)
            	{
            		insere_lista += "\n\tinsereFim(" + buscaID((yyvsp[-1]).label).nome_lista + ", " + indices_temporarios[i] + ");";
            	}
            	indices_temporarios.clear();
            	(yyval).traducao = "\n" + (yyvsp[0]).traducao + "\n\t" + insere_lista + "\n\n\t" + (yyvsp[-2]).label + " " + buscaID((yyvsp[-1]).label).nome_temp + "[" + (yyvsp[0]).label + "];\n";
            }
#line 2784 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1015 "src/sintatica.y" /* yacc.c:1646  */
    {
                info_variavel atributos = { (yyvsp[-3]).label, gera_variavel_temporaria((yyvsp[-3]).label, (yyvsp[-2]).label)};

                if(mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 1)
                    (yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + atributos.nome_temp + " = " + "(" + mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo + ")" + (yyvsp[0]).label + ";";
                else if(mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 0)
                    (yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + atributos.nome_temp + " = " + (yyvsp[0]).label + ";";
                else
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Um valor do tipo \"" << (yyvsp[0]).tipo << "\" não pode ser atribuido à uma variável do tipo \"" << (yyvsp[-3]).label << "\".";
                    add_erro(msg_erro.str());
                }
            }
#line 2803 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1030 "src/sintatica.y" /* yacc.c:1646  */
    {
            	(yyval).traducao = "";
            	for (int i = 0; i < multiplos_ids.size(); ++i)
            	{
	                info_variavel atributos = { (yyvsp[-1]).label, gera_variavel_temporaria((yyvsp[-1]).label, multiplos_ids[i])};
	                (yyval).traducao += "\n\t" + atributos.nome_temp + " = " + "1" + ";";
	            }
	            multiplos_ids.clear();
            }
#line 2817 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1040 "src/sintatica.y" /* yacc.c:1646  */
    {
            	insere_lista = true;
            	gera_variavel_temporaria((yyvsp[-2]).label, (yyvsp[-1]).label);
            	info_variavel var = buscaID((yyvsp[-1]).label);
            	var.nome_lista = geraLabel();
            	alteraID((yyvsp[-1]).label, var);
            	string insere_lista = "\n\tnode *" + buscaID((yyvsp[-1]).label).nome_lista + ";\n\t" + buscaID((yyvsp[-1]).label).nome_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID((yyvsp[-1]).label).nome_lista + ");\n\tif(!" + buscaID((yyvsp[-1]).label).nome_lista + ") cout << \"Sem memoria disponivel!\\n\";";
            	for (int i = 0; i < indices_temporarios.size(); ++i)
            	{
            		insere_lista += "\n\tinsereFim(" + buscaID((yyvsp[-1]).label).nome_lista + ", " + indices_temporarios[i] + ");";
            	}
            	indices_temporarios.clear();
            	(yyval).traducao = "\n" + (yyvsp[0]).traducao + "\n\t" + insere_lista + "\n\n\t" + (yyvsp[-2]).traducao + " " + buscaID((yyvsp[-1]).label).nome_temp + "[" + (yyvsp[0]).label + "];\n";
            }
#line 2836 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1055 "src/sintatica.y" /* yacc.c:1646  */
    {
                info_variavel atributos = { (yyvsp[-3]).label, gera_variavel_temporaria((yyvsp[-3]).label, (yyvsp[-2]).label,1)};  
                if(mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 1)
                    (yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + atributos.nome_temp + " = " + "(" + mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo + ")" + (yyvsp[0]).label + ";";
                else if(mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 0)
                    (yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + atributos.nome_temp + " = " + (yyvsp[0]).label + ";";
                else
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Um valor do tipo \"" << (yyvsp[0]).tipo << "\" não pode ser atribuido à uma variável do tipo \"" << (yyvsp[-3]).label << "\".";
                    add_erro(msg_erro.str());
                }
            }
#line 2854 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1069 "src/sintatica.y" /* yacc.c:1646  */
    {
            	(yyval).traducao = "";
            	for (int i = 0; i < multiplos_ids.size(); ++i)
            	{
	                info_variavel atributos = { (yyvsp[-1]).label, gera_variavel_temporaria((yyvsp[-1]).label, multiplos_ids[i],1)};
	            }
	            multiplos_ids.clear();
            }
#line 2867 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1078 "src/sintatica.y" /* yacc.c:1646  */
    {
            	insere_lista = true;
            	gera_variavel_temporaria((yyvsp[-2]).label, (yyvsp[-1]).label);
            	info_variavel var = buscaID((yyvsp[-1]).label);
            	var.nome_lista = geraLabel();
            	alteraID((yyvsp[-1]).label, var);
            	string insere_lista = "\n\tnode *" + buscaID((yyvsp[-1]).label).nome_lista + ";\n\t" + buscaID((yyvsp[-1]).label).nome_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID((yyvsp[-1]).label).nome_lista + ");\n\tif(!" + buscaID((yyvsp[-1]).label).nome_lista + ") cout << \"Sem memoria disponivel!\\n\";";
            	for (int i = 0; i < indices_temporarios.size(); ++i)
            	{
            		insere_lista += "\n\tinsereFim(" + buscaID((yyvsp[-1]).label).nome_lista + ", " + indices_temporarios[i] + ");";
            	}
            	indices_temporarios.clear();
            	(yyval).traducao = "\n" + (yyvsp[0]).traducao + "\n\t" + insere_lista + "\n\n\t" + (yyvsp[-2]).label + " " + buscaID((yyvsp[-1]).label).nome_temp + "[" + (yyvsp[0]).label + "];\n";
            }
#line 2886 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1093 "src/sintatica.y" /* yacc.c:1646  */
    {
                info_variavel atributos = { (yyvsp[-3]).label, gera_variavel_temporaria((yyvsp[-3]).label, (yyvsp[-2]).label, 1024 + (yyvsp[0]).tamanho)};
                if((mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 0) && (mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo != ""))
                {
                    (yyval).traducao = (yyvsp[0]).traducao + "\n\tstrcpy(" + atributos.nome_temp + ", " + (yyvsp[0]).label + ");\n";
                }
                else
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Um valor do tipo \"" << (yyvsp[0]).tipo << "\" não pode ser atribuido à uma variável do tipo \"" << (yyvsp[-3]).label << "\".";
                    add_erro(msg_erro.str());
                }
            }
#line 2904 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1107 "src/sintatica.y" /* yacc.c:1646  */
    {
            	(yyval).traducao = "";
            	for (int i = 0; i < multiplos_ids.size(); ++i)
            	{
	                info_variavel atributos = { (yyvsp[-1]).label, gera_variavel_temporaria((yyvsp[-1]).label, multiplos_ids[i], 1024)};
	                (yyval).traducao += "\n\tstrcpy(" + atributos.nome_temp + ", \"\");\n";
	            }
	            multiplos_ids.clear();
            }
#line 2918 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1117 "src/sintatica.y" /* yacc.c:1646  */
    {
            	insere_lista = true;
            	gera_variavel_temporaria((yyvsp[-2]).label, (yyvsp[-1]).label);
            	info_variavel var = buscaID((yyvsp[-1]).label);
            	var.nome_lista = geraLabel();
            	alteraID((yyvsp[-1]).label, var);
            	string insere_lista = "\n\tnode *" + buscaID((yyvsp[-1]).label).nome_lista + ";\n\t" + buscaID((yyvsp[-1]).label).nome_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID((yyvsp[-1]).label).nome_lista + ");\n\tif(!" + buscaID((yyvsp[-1]).label).nome_lista + ") cout << \"Sem memoria disponivel!\\n\";";
            	for (int i = 0; i < indices_temporarios.size(); ++i)
            	{
            		insere_lista += "\n\tinsereFim(" + buscaID((yyvsp[-1]).label).nome_lista + ", " + indices_temporarios[i] + ");";
            	}
            	indices_temporarios.clear();
            	(yyval).traducao = "\n" + (yyvsp[0]).traducao + "\n\t" + insere_lista + "\n\n\tstr " + buscaID((yyvsp[-1]).label).nome_temp + "[" + (yyvsp[0]).label + "];\n";
            }
#line 2937 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1133 "src/sintatica.y" /* yacc.c:1646  */
    {
				multiplos_ids.push_back((yyvsp[0]).label);
				(yyval).traducao = "";
			}
#line 2946 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1138 "src/sintatica.y" /* yacc.c:1646  */
    {
				multiplos_ids.push_back((yyvsp[0]).label);
				(yyval).traducao = "";
			}
#line 2955 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1144 "src/sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-1]).tipo != "int")
				{
					stringstream msg_erro;
					msg_erro << "Erro na linha: " << numero_linha << ". Esperava um valor do tipo \"int\" para definir o tamanho de um vetor.";
					add_erro(msg_erro.str());
				}
				string var = gera_variavel_temporaria("int");
				indices_temporarios.push_back((yyvsp[-1]).label);
				(yyval).traducao = (yyvsp[-3]).traducao + (yyvsp[-1]).traducao + "\n\t" + var + " = " + (yyvsp[-3]).label + " * " + (yyvsp[-1]).label + ";\n";
				(yyval).label = var;
			}
#line 2972 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1157 "src/sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-1]).tipo != "int")
				{
					stringstream msg_erro;
					msg_erro << "Erro na linha: " << numero_linha << ". Esperava um valor do tipo \"int\" para definir o tamanho de um vetor.";
					add_erro(msg_erro.str());
				}
				indices_temporarios.push_back((yyvsp[-1]).label);
				(yyval).traducao = (yyvsp[-1]).traducao;
				(yyval).label = (yyvsp[-1]).label;
			}
#line 2988 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1170 "src/sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-1]).tipo != "int")
				{
					stringstream msg_erro;
					msg_erro << "Erro na linha: " << numero_linha << ". Esperava um valor do tipo \"int\" para o indice do vetor.";
					add_erro(msg_erro.str());
				}
				string var = gera_variavel_temporaria("int");
				indices_temporarios.push_back((yyvsp[-1]).label);
				(yyval).traducao = (yyvsp[-3]).traducao + (yyvsp[-1]).traducao + ";\n";
			}
#line 3004 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1182 "src/sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-1]).tipo != "int")
				{
					stringstream msg_erro;
					msg_erro << "Erro na linha: " << numero_linha << ". Esperava um valor do tipo \"int\" para o indice do vetor.";
					add_erro(msg_erro.str());
				}
				indices_temporarios.push_back((yyvsp[-1]).label);
				(yyval).traducao = (yyvsp[-1]).traducao;
			}
#line 3019 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1194 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
			}
#line 3028 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1199 "src/sintatica.y" /* yacc.c:1646  */
    {
				string var_negada = gera_variavel_temporaria("boolean");
				if((yyvsp[0]).tipo != "boolean")
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Esperava um valor do tipo \"boolean\".";
                    add_erro(msg_erro.str());
                }
                (yyval).label = var_negada;
                (yyval).traducao = "\n\t" + (yyvsp[0]).traducao + "\n\t" + var_negada + " = !" + (yyvsp[0]).label + ";\n";
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).tamanho = (yyvsp[0]).tamanho;
			}
#line 3046 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1214 "src/sintatica.y" /* yacc.c:1646  */
    {
                string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo);
                (yyval).label = nome_variavel_temporaria;
                (yyval).tipo = mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo;
                (yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\n\t" + (yyval).label + " = " +(yyvsp[-2]).label + " " + (yyvsp[-1]).traducao + " " + (yyvsp[0]).label + ";\n";
            }
#line 3057 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1221 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).tamanho = (yyvsp[0]).tamanho;
            }
#line 3068 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1229 "src/sintatica.y" /* yacc.c:1646  */
    {
                string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo);
                (yyval).label = nome_variavel_temporaria;
                (yyval).tipo = mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo;
                (yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\n\t" + (yyval).label + " = " +(yyvsp[-2]).label + " " + (yyvsp[-1]).traducao + " " + (yyvsp[0]).label + ";\n";
            }
#line 3079 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1236 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).tamanho = (yyvsp[0]).tamanho;
            }
#line 3090 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1244 "src/sintatica.y" /* yacc.c:1646  */
    {
            	if(mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo == "" || mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo == "null")
            	{
            		stringstream msg_erro;
            		msg_erro << "Erro na linha: " << numero_linha << ". Operação inválida.";
            		add_erro(msg_erro.str());
            	}
            	if(((yyvsp[-2]).tipo == "string") && ((yyvsp[0]).tipo == "string"))
            	{
            		string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo);
	                (yyval).label = nome_variavel_temporaria;
	                (yyval).tipo = mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo;
	                if((yyvsp[-1]).label == ">")
	                {
	                	(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\n\t" + nome_variavel_temporaria + " = strcmp(" +(yyvsp[-2]).label + ", " + (yyvsp[0]).label + ");\n";		
	                	(yyval).traducao += "\tif(" + nome_variavel_temporaria + " > 0) " + nome_variavel_temporaria + " = 1;\n";
	                	(yyval).traducao += "\tif(" + nome_variavel_temporaria + " == 0) " + nome_variavel_temporaria + " = 0;\n";
	                	(yyval).traducao += "\tif(" + nome_variavel_temporaria + " < 0) " + nome_variavel_temporaria + " = 0;\n";
	                } else if ((yyvsp[-1]).label == "<")
	                {
	                	(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\n\t" + nome_variavel_temporaria + " = strcmp(" +(yyvsp[-2]).label + ", " + (yyvsp[0]).label + ");\n";		
	                	(yyval).traducao += "\tif(" + nome_variavel_temporaria + " > 0) " + nome_variavel_temporaria + " = 0;\n";
	                	(yyval).traducao += "\tif(" + nome_variavel_temporaria + " == 0) " + nome_variavel_temporaria + " = 0;\n";
	                	(yyval).traducao += "\tif(" + nome_variavel_temporaria + " < 0) " + nome_variavel_temporaria + " = 1;\n";
	                } else if ((yyvsp[-1]).label == "==")
	                {
	                	(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\n\t" + nome_variavel_temporaria + " = strcmp(" +(yyvsp[-2]).label + ", " + (yyvsp[0]).label + ");\n";		
	                	(yyval).traducao += "\tif(" + nome_variavel_temporaria + " > 0) " + nome_variavel_temporaria + " = 0;\n";
	                	(yyval).traducao += "\tif(" + nome_variavel_temporaria + " == 0) " + nome_variavel_temporaria + " = 1;\n";
	                	(yyval).traducao += "\tif(" + nome_variavel_temporaria + " < 0) " + nome_variavel_temporaria + " = 0;\n";
	                } else if ((yyvsp[-1]).label == "!=")
	                {
	                	(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\n\t" + nome_variavel_temporaria + " = strcmp(" +(yyvsp[-2]).label + ", " + (yyvsp[0]).label + ");\n";		
	                	(yyval).traducao += "\tif(" + nome_variavel_temporaria + " > 0) " + nome_variavel_temporaria + " = 1;\n";
	                	(yyval).traducao += "\tif(" + nome_variavel_temporaria + " == 0) " + nome_variavel_temporaria + " = 0;\n";
	                	(yyval).traducao += "\tif(" + nome_variavel_temporaria + " < 0) " + nome_variavel_temporaria + " = 1;\n";
	                } else if ((yyvsp[-1]).label == ">=")
	                {
	                	(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\n\t" + nome_variavel_temporaria + " = strcmp(" +(yyvsp[-2]).label + ", " + (yyvsp[0]).label + ");\n";		
	                	(yyval).traducao += "\tif(" + nome_variavel_temporaria + " > 0) " + nome_variavel_temporaria + " = 1;\n";
	                	(yyval).traducao += "\tif(" + nome_variavel_temporaria + " == 0) " + nome_variavel_temporaria + " = 1;\n";
	                	(yyval).traducao += "\tif(" + nome_variavel_temporaria + " < 0) " + nome_variavel_temporaria + " = 0;\n";
	                } else if ((yyvsp[-1]).label == "<=")
	                {
	                	(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\n\t" + nome_variavel_temporaria + " = strcmp(" +(yyvsp[-2]).label + ", " + (yyvsp[0]).label + ");\n";		
	                	(yyval).traducao += "\tif(" + nome_variavel_temporaria + " > 0) " + nome_variavel_temporaria + " = 0;\n";
	                	(yyval).traducao += "\tif(" + nome_variavel_temporaria + " == 0) " + nome_variavel_temporaria + " = 1;\n";
	                	(yyval).traducao += "\tif(" + nome_variavel_temporaria + " < 0) " + nome_variavel_temporaria + " = 1;\n";
	                }
            	}
            	else
            	{
	                string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo);
	                (yyval).label = nome_variavel_temporaria;
	                (yyval).tipo = mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo;
	                (yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\n\t" + nome_variavel_temporaria + " = " +(yyvsp[-2]).label + " " + (yyvsp[-1]).label + " " + (yyvsp[0]).label + ";\n";
	            }
            }
#line 3153 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1303 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).tamanho = (yyvsp[0]).tamanho;
            }
#line 3164 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1311 "src/sintatica.y" /* yacc.c:1646  */
    {
                if(((yyvsp[-2]).tipo == "string" && (yyvsp[0]).tipo == "string")||((yyvsp[-2]).tipo == "string" && (yyvsp[0]).tipo == "char")||((yyvsp[-2]).tipo == "char" && (yyvsp[0]).tipo == "string"))
                {
                    string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo, "", (yyvsp[-2]).tamanho+(yyvsp[0]).tamanho);
                    (yyval).label = nome_variavel_temporaria;
                    (yyval).tamanho = (yyvsp[-2]).tamanho+(yyvsp[0]).tamanho;
                    if(mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 0) 
                    {
                        (yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyvsp[-2]).traducao + "\n";
                        (yyval).traducao += "\tstrcpy(" + nome_variavel_temporaria + ", strcat(" + (yyvsp[-2]).label + ", " + (yyvsp[0]).label + "));\n";
                    }
                    else if ((mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo == "") || (mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo == "null"))
                    {
                        stringstream msg_erro;
                        msg_erro << "Erro na linha: " << numero_linha << ". Operação inválida.";
                        add_erro(msg_erro.str());
                    }
                    (yyval).tipo = "string";

                } else
                {
                    string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo);
                    (yyval).label = nome_variavel_temporaria;
                    if(mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 0) {
                        (yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyvsp[-2]).traducao + "\n\t" + nome_variavel_temporaria + " = " + (yyvsp[-2]).label + " " + (yyvsp[-1]).label + " " + (yyvsp[0]).label + ";";
                    }
                    else if(mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 1) 
                    {
                        (yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyvsp[-2]).traducao + "\n\t" + nome_variavel_temporaria + " = " + "(" + mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo + ")" + (yyvsp[-2]).label + ";\n\t";
                        (yyval).traducao += nome_variavel_temporaria + " = " + nome_variavel_temporaria + " " + (yyvsp[-1]).label + " " + (yyvsp[0]).label + ";";
                    } else {
                        (yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyvsp[-2]).traducao + "\n\t" + nome_variavel_temporaria + " = " + "(" + mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo + ")" + (yyvsp[0]).label + ";";
                        (yyval).traducao += "\n\t" + nome_variavel_temporaria + " = " + (yyvsp[-2]).label + " " + (yyvsp[-1]).label + " " + nome_variavel_temporaria + ";";
                    }
                    if ((mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo == "") || (mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo == "null"))
                    {
                        stringstream msg_erro;
                        msg_erro << "Erro na linha: " << numero_linha << ". Operação inválida.";
                        add_erro(msg_erro.str());
                    }
                    (yyval).tipo = mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo;
                }
            }
#line 3212 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1355 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).tamanho = (yyvsp[0]).tamanho;
            }
#line 3223 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1363 "src/sintatica.y" /* yacc.c:1646  */
    {
                string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo);
                (yyval).label = nome_variavel_temporaria;
                if(mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 0) 
                {
                    (yyval).traducao = (yyvsp[0]).traducao + (yyvsp[-2]).traducao + "\n\t" + nome_variavel_temporaria + " = " + (yyvsp[-2]).label + " " + (yyvsp[-1]).label + " " + (yyvsp[0]).label + ";";
                } else if(mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 1) 
                {
                    (yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyvsp[-2]).traducao + "\n\t" + nome_variavel_temporaria + " = " + "(" + mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo + ")" + (yyvsp[-2]).label + ";\n\t";
                    (yyval).traducao += nome_variavel_temporaria + " = " + nome_variavel_temporaria + " " + (yyvsp[-1]).label + " " + (yyvsp[0]).label + ";";
                } else 
                {
                    (yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyvsp[-2]).traducao + "\n\t" + nome_variavel_temporaria + " = " + "(" + mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo + ")" + (yyvsp[0]).label + ";";
                    (yyval).traducao += "\n\t" + nome_variavel_temporaria + " = " + (yyvsp[-2]).label + " " + (yyvsp[-1]).label + " " + nome_variavel_temporaria + ";";
                }
                if (mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo == "null" || mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo == "")
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Operação inválida.";
                    add_erro(msg_erro.str());
                }
                (yyval).tipo = mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo;
            }
#line 3251 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1387 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).tamanho = (yyvsp[0]).tamanho;
            }
#line 3262 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1395 "src/sintatica.y" /* yacc.c:1646  */
    {
            	if (buscaID((yyvsp[0]).label).tipo != "int")
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Esperava um valor do tipo \"int\".";
                    add_erro(msg_erro.str());
                }
                info_variavel var = buscaID((yyvsp[0]).label);
                (yyval).label = var.nome_temp;
                (yyval).traducao = "\n\t" + var.nome_temp + " = " + var.nome_temp + " + 1;\n";
                (yyval).tipo = var.tipo;
                (yyval).tamanho = var.tamanho;
            }
#line 3280 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1409 "src/sintatica.y" /* yacc.c:1646  */
    {
            	if (buscaID((yyvsp[0]).label).tipo != "int")
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Esperava um valor do tipo \"int\".";
                    add_erro(msg_erro.str());
                }
                info_variavel var = buscaID((yyvsp[0]).label);
                (yyval).label = var.nome_temp;
                (yyval).traducao = "\n\t" + var.nome_temp + " = " + var.nome_temp + " - 1;\n";
                (yyval).tipo = var.tipo;
                (yyval).tamanho = var.tamanho;
            }
#line 3298 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1424 "src/sintatica.y" /* yacc.c:1646  */
    {
                if ((yyvsp[0]).tipo == "boolean" || (yyvsp[0]).tipo == "string" || (yyvsp[0]).tipo == "char")
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Não é possível realizar uma operação aritmética com um valor do tipo \"" << (yyvsp[0]).tipo << "\".";
                    add_erro(msg_erro.str());
                }
                (yyval).label = (yyvsp[-1]).label + (yyvsp[0]).label;
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 3314 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1436 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).tamanho = (yyvsp[0]).tamanho;
            }
#line 3325 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1444 "src/sintatica.y" /* yacc.c:1646  */
    {
                string nome_variavel_temporaria = gera_variavel_temporaria((yyvsp[-2]).tipo);
                (yyval).label = nome_variavel_temporaria;
                if(mapa_operacoes["("+(yyvsp[-2]).label+")"+(yyvsp[0]).tipo].tipo == "null" || mapa_operacoes["("+(yyvsp[-2]).label+")"+(yyvsp[0]).tipo].tipo == "")
                {
                    stringstream msg_erro;
                    msg_erro << "Erro na linha: " << numero_linha << ". Não é possível realizar este cast.";
                    add_erro(msg_erro.str());
                }
                else
                {
                    (yyval).traducao = (yyvsp[0]).traducao +"\n\t" + (yyval).label + " = "+ "(" + (yyvsp[-2]).label + ")"+ (yyvsp[0]).label + ";";
                }
                    (yyval).tipo = (yyvsp[-2]).tipo;
            }
#line 3345 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1460 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[-1]).label;
                (yyval).traducao = (yyvsp[-1]).traducao;
                (yyval).tipo = (yyvsp[-1]).tipo;
            }
#line 3355 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1466 "src/sintatica.y" /* yacc.c:1646  */
    {
                string nome_variavel_temporaria = gera_variavel_temporaria((yyvsp[0]).tipo);
                (yyval).label = nome_variavel_temporaria;
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).traducao ="\n\t" + nome_variavel_temporaria + " = " + (yyvsp[0]).label + ";";
            }
#line 3366 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1473 "src/sintatica.y" /* yacc.c:1646  */
    {
                string nome_variavel_temporaria = gera_variavel_temporaria((yyvsp[0]).tipo);
                (yyval).label = nome_variavel_temporaria;
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).traducao ="\n\t" + nome_variavel_temporaria + " = " + (yyvsp[0]).label + ";";
            }
#line 3377 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1480 "src/sintatica.y" /* yacc.c:1646  */
    {   
                string nome_variavel_temporaria = gera_variavel_temporaria((yyvsp[0]).tipo);
                (yyval).label = nome_variavel_temporaria;
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).tamanho = 1;
                (yyval).traducao ="\n\t" + nome_variavel_temporaria + " = " + (yyvsp[0]).label + ";";
            }
#line 3389 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1488 "src/sintatica.y" /* yacc.c:1646  */
    {   
                string nome_variavel_temporaria = gera_variavel_temporaria((yyvsp[0]).tipo);
                (yyval).label = nome_variavel_temporaria;
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).traducao ="\n\t" + nome_variavel_temporaria + " = " + (yyvsp[0]).traducao + ";\n";
            }
#line 3400 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1495 "src/sintatica.y" /* yacc.c:1646  */
    {   
                string nome_variavel_temporaria = gera_variavel_temporaria((yyvsp[0]).tipo, "", (yyvsp[0]).tamanho);
                (yyval).label = nome_variavel_temporaria;
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).traducao = "\n\tstrcpy(" + nome_variavel_temporaria + ", " + (yyvsp[0]).label + ");";
            }
#line 3411 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1502 "src/sintatica.y" /* yacc.c:1646  */
    {
                info_variavel var = buscaID((yyvsp[0]).label);
                (yyval).label = var.nome_temp;
                (yyval).traducao = "";
                (yyval).tipo = var.tipo;
                (yyval).tamanho = var.tamanho;
            }
#line 3423 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1510 "src/sintatica.y" /* yacc.c:1646  */
    {
                if(mapa_variaveis_globais.find((yyvsp[0]).label) == mapa_variaveis_globais.end())
                {
                	stringstream msg_erro;
                	msg_erro << "Erro na linha " << numero_linha <<": Variável global \"" << (yyvsp[0]).label << "\" não declarada.";
                	add_erro(msg_erro.str());
                }
                else
                {
                	info_variavel var = mapa_variaveis_globais[(yyvsp[0]).label];
                	(yyval).label = var.nome_temp;
	                (yyval).traducao = "";
	                (yyval).tipo = var.tipo;
	                (yyval).tamanho = var.tamanho;
                }
            }
#line 3444 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1527 "src/sintatica.y" /* yacc.c:1646  */
    {
            	if(mapa_funcao[(yyvsp[-3]).label].nome_temp == "")
                {
                	stringstream msg_erro;
                	msg_erro << "Erro na linha " << numero_linha << ": Função \"" << (yyvsp[-3]).label << "\" não declarada.";
                	add_erro(msg_erro.str());
                }
                int i;
                if(mapa_funcao[(yyvsp[-3]).label].parametros.size() == argumentos.size())
                {
                	for(i = 0; i < argumentos.size(); i++)
                	{
                		if(mapa_funcao[(yyvsp[-3]).label].parametros[i] != argumentos[i])
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
                info_funcao var = mapa_funcao[(yyvsp[-3]).label];
                (yyval).label = var.nome_temp + "(" + (yyvsp[-1]).traducao + ")";
                (yyval).traducao = (yyvsp[-1]).label;
                (yyval).tipo = var.tipo;
                (yyval).tamanho = 1024;
            }
#line 3483 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1562 "src/sintatica.y" /* yacc.c:1646  */
    {
            	string var_temp = gera_variavel_temporaria("int");
            	info_variavel var = buscaID((yyvsp[-1]).label);
            	var.acesso_lista = geraLabel();
            	alteraID((yyvsp[-1]).label, var);
            	string acesso_lista = "\n\tnode *" + buscaID((yyvsp[-1]).label).acesso_lista + ";\n\t" + buscaID((yyvsp[-1]).label).acesso_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID((yyvsp[-1]).label).acesso_lista + ");\n\tif(!" + buscaID((yyvsp[-1]).label).acesso_lista + ") cout << \"Sem memoria disponivel!\\n\";";
            	for (int i = 0; i < indices_temporarios.size(); ++i)
            	{
            		acesso_lista += "\n\tinsereFim(" + buscaID((yyvsp[-1]).label).acesso_lista + ", " + indices_temporarios[i] + ");";
            	}
            	indices_temporarios.clear();
            	(yyval).traducao = (yyvsp[0]).traducao + "\n\t" + acesso_lista + "\n\t" + var_temp + " = mapper(" + buscaID((yyvsp[-1]).label).acesso_lista + ", " + buscaID((yyvsp[-1]).label).nome_lista + ");\n\t";
            	(yyval).tipo = var.tipo;
            	if(var.tipo == "string")
            		(yyval).label = buscaID((yyvsp[-1]).label).nome_temp + "[" + var_temp +  "].c";
            	else
            		(yyval).label = buscaID((yyvsp[-1]).label).nome_temp + "[" + var_temp +  "]";
            	(yyval).tamanho = var.tamanho;
            }
#line 3507 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1583 "src/sintatica.y" /* yacc.c:1646  */
    {
				argumentos.push_back((yyvsp[0]).tipo);
				(yyval).label = (yyvsp[-2]).label + (yyvsp[0]).traducao;
				(yyval).traducao = (yyvsp[-2]).traducao + ", " + (yyvsp[0]).label;
			}
#line 3517 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1589 "src/sintatica.y" /* yacc.c:1646  */
    {
				argumentos.push_back((yyvsp[0]).tipo);
				(yyval).label = (yyvsp[0]).traducao;
				(yyval).traducao = (yyvsp[0]).label;
				(yyval).tipo = (yyvsp[0]).tipo;
			}
#line 3528 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1595 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = "";
				(yyval).traducao = "";
			}
#line 3537 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1601 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
                (yyval).tipo = "float";
            }
#line 3547 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1607 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
                (yyval).tipo = "int";
            }
#line 3557 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1613 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
                (yyval).tipo = "char";
            }
#line 3567 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1619 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
                (yyval).tipo = "boolean";
            }
#line 3577 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1626 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
            }
#line 3586 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1631 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
            }
#line 3595 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1636 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
            }
#line 3604 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1641 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
            }
#line 3613 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1646 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
            }
#line 3622 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1651 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
            }
#line 3631 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1657 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
            }
#line 3640 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1662 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
            }
#line 3649 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1668 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
            }
#line 3658 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1673 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
            }
#line 3667 "bin/y.tab.c" /* yacc.c:1646  */
    break;


#line 3671 "bin/y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1678 "src/sintatica.y" /* yacc.c:1906  */


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
