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


#line 163 "bin/y.tab.c" /* yacc.c:339  */

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
    TK_NUM = 258,
    TK_REAL = 259,
    TK_CHAR = 260,
    TK_STRING = 261,
    TK_ID = 262,
    TK_MAIN = 263,
    TK_BEGIN = 264,
    TK_END = 265,
    TK_TIPO_INT = 266,
    TK_TIPO_STRING = 267,
    TK_TIPO_FLOAT = 268,
    TK_TIPO_CHAR = 269,
    TK_TIPO_BOOL = 270,
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
    TK_FUNC = 304
  };
#endif
/* Tokens.  */
#define TK_NUM 258
#define TK_REAL 259
#define TK_CHAR 260
#define TK_STRING 261
#define TK_ID 262
#define TK_MAIN 263
#define TK_BEGIN 264
#define TK_END 265
#define TK_TIPO_INT 266
#define TK_TIPO_STRING 267
#define TK_TIPO_FLOAT 268
#define TK_TIPO_CHAR 269
#define TK_TIPO_BOOL 270
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

#line 312 "bin/y.tab.c" /* yacc.c:358  */

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
#define YYLAST   270

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  231

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

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
      50,    51,     2,     2,    53,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    52,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   109,   109,   150,   154,   188,   190,   200,   211,   216,
     222,   224,   228,   232,   236,   240,   245,   277,   284,   290,
     295,   299,   305,   305,   340,   347,   354,   360,   371,   381,
     391,   402,   407,   412,   445,   453,   462,   468,   486,   500,
     511,   533,   539,   557,   575,   593,   612,   618,   628,   634,
     642,   647,   651,   670,   674,   692,   698,   705,   732,   736,
     768,   784,   822,   835,   840,   856,   869,   874,   890,   903,
     907,   923,   936,   940,   956,   969,   973,   990,  1003,  1015,
    1027,  1038,  1046,  1054,  1062,  1070,  1129,  1137,  1182,  1190,
    1214,  1223,  1235,  1249,  1258,  1269,  1277,  1295,  1301,  1309,
    1316,  1324,  1331,  1338,  1346,  1358,  1392,  1416,  1422,  1429,
    1434,  1440,  1446,  1452,  1460,  1465,  1470,  1475,  1480,  1485,
    1492,  1497,  1503,  1508
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_NUM", "TK_REAL", "TK_CHAR",
  "TK_STRING", "TK_ID", "TK_MAIN", "TK_BEGIN", "TK_END", "TK_TIPO_INT",
  "TK_TIPO_STRING", "TK_TIPO_FLOAT", "TK_TIPO_CHAR", "TK_TIPO_BOOL",
  "TK_ATR", "TK_SOMA", "TK_SUB", "TK_MUL", "TK_DIV", "TK_LOGICO", "TK_AND",
  "TK_OR", "TK_MENOR", "TK_MAIOR", "TK_MENOR_IGUAL", "TK_MAIOR_IGUAL",
  "TK_IGUAL", "TK_DIFERENTE", "TK_NOT", "TK_PLUSPLUS", "TK_SUBSUB",
  "TK_WHILE", "TK_FOR", "TK_DO", "TK_IF", "TK_ELSE", "TK_ELIF", "TK_BREAK",
  "TK_CONTINUE", "TK_SUPERBREAK", "TK_SUPERCONTINUE", "TK_WRITE",
  "TK_WRITELN", "TK_READ", "TK_GLOBAL", "TK_FUNCTION", "TK_RETURN",
  "TK_FUNC", "'('", "')'", "';'", "','", "'['", "']'", "$accept", "S",
  "FUNC", "TID", "ARGUMENTOS", "TIPO", "BLOCO", "BEGIN", "END", "COMANDOS",
  "COMANDO", "WRITE", "LOOP", "WHILE", "W", "FOR", "F", "D", "CONDICIONAL",
  "ELSE", "ELIF", "IF", "I", "ATRIBUICAO", "DECLARACAO", "VET_DIMENSAO",
  "VET_INDICE", "E_OR", "E_AND", "E_REL", "E", "E_TEMP", "UNAL_OP", "UNAL",
  "VAL", "PARAMETROS", "E_CAST", "TK_REL_OP", "TK_ARIT_OP_S",
  "TK_ARIT_OP_M", YY_NULLPTR
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
      40,    41,    59,    44,    91,    93
};
# endif

#define YYPACT_NINF -114

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-114)))

#define YYTABLE_NINF -23

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -114,    36,    11,  -114,     9,   233,    23,  -114,  -114,  -114,
    -114,  -114,  -114,    39,   107,    35,   191,  -114,   106,   -35,
     117,  -114,  -114,   180,   106,   191,  -114,  -114,  -114,  -114,
    -114,    -9,   140,   151,   152,   162,   163,    28,  -114,   150,
     168,   172,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
     150,   150,   173,   181,   183,    50,   180,   119,   145,  -114,
     106,   149,   106,   158,   106,  -114,   106,   159,  -114,  -114,
     194,   196,  -114,   210,     6,  -114,  -114,  -114,  -114,   180,
     224,    88,   150,   150,    -7,    12,    13,    21,    27,    54,
     -39,   226,  -114,   194,  -114,  -114,   188,   194,   188,  -114,
     227,   192,  -114,  -114,  -114,  -114,    65,   198,  -114,  -114,
    -114,   180,  -114,   150,  -114,   128,   217,  -114,   150,   150,
     150,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,   150,
     150,  -114,  -114,   150,    59,  -114,   194,  -114,   194,    97,
       7,   150,   150,   150,   150,   197,   150,   197,   150,   197,
     247,   197,   150,   197,   199,  -114,   150,    88,   150,  -114,
      28,  -114,    82,    63,   248,   202,   204,   207,   -25,   100,
     196,  -114,    80,     6,  -114,   150,  -114,   150,  -114,   194,
      17,  -114,    57,   150,    80,  -114,  -114,   194,   194,   194,
    -114,   125,  -114,  -114,    -7,   227,   150,   150,   150,   106,
     208,  -114,  -114,   -13,   194,  -114,  -114,    67,  -114,    78,
      79,   109,  -114,   150,   119,  -114,    53,    53,  -114,   122,
    -114,   209,   211,   212,   213,   106,  -114,  -114,  -114,  -114,
    -114
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     1,     0,     0,     0,     7,    12,    11,
      14,    15,    13,     0,     0,     0,    10,     6,     0,     0,
       0,    17,     2,    20,     0,     0,     9,    98,    99,   100,
     102,   103,     0,     0,     0,     0,     0,     0,   101,     0,
       0,     0,    41,    46,    47,    55,    27,    28,    29,    30,
       0,     0,     0,     0,     0,     0,    20,     0,     0,    36,
       0,     0,     0,     0,     0,    48,     0,     0,    56,    24,
      25,    82,    84,    86,    88,    26,    90,    95,     3,    20,
       0,     0,   109,     0,   106,    63,    75,    66,    72,    69,
     103,     0,    94,    91,    92,    93,    31,    35,    32,    33,
     104,     0,   111,   110,   112,   113,     0,     0,    21,    18,
      16,    20,    39,     0,    38,     0,     0,    53,     0,     0,
       0,   120,   121,   114,   115,   116,   117,   118,   119,     0,
       0,   122,   123,     0,     0,     8,    57,    58,   108,     0,
       0,     0,     0,     0,     0,    64,     0,    76,     0,    67,
       0,    73,     0,    70,   106,   104,     0,     0,   109,    97,
       0,    19,     0,     0,     0,     0,     0,     0,    51,     0,
      81,    83,    85,    87,    89,     0,   105,     0,    80,    61,
       0,    62,     0,     0,    74,    65,    71,    68,    34,    59,
      60,     0,    96,    40,     0,     0,     0,     0,     0,     0,
       0,    49,    54,     0,   107,    79,    78,     0,    23,     0,
       0,     0,    50,     0,     0,    77,     0,     0,    37,     0,
       4,     0,     0,     0,     0,     0,    42,    43,    45,    44,
      52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -114,  -114,  -114,  -114,  -114,    -2,   -18,   235,    47,   -52,
    -114,   214,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -113,   153,    75,   -87,   -31,   147,    29,
    -108,   137,   -80,   136,   -32,   112,  -114,  -114,  -114,  -114
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    13,    19,    14,    56,    23,   110,    57,
      58,    96,    59,    60,    61,    62,    63,    64,    65,   201,
     168,    66,    67,    68,    69,   145,    84,    70,    71,    72,
      73,    74,    75,    76,    77,   139,   107,   129,   130,   133
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,   137,   165,   154,   108,    92,    78,    81,    93,   141,
     119,    82,   199,   200,    20,    83,    24,     6,    25,    97,
      97,   172,     4,    80,   106,   131,   132,   134,   143,   146,
     119,    27,    28,    29,    30,    90,     3,   148,   184,   214,
     119,    82,   112,   150,   114,    83,   116,   142,   117,    38,
     136,   138,   140,    27,    28,    29,    30,    90,     5,   161,
     163,   102,   178,   103,   104,   105,   144,   144,    37,   109,
     152,    38,   205,    15,    91,   144,   194,   190,    55,    81,
     119,   144,   162,    39,    40,    41,    18,   169,   119,    16,
     119,    27,    28,    29,    30,    90,    91,   121,   122,   164,
      55,   119,   119,   221,   223,   119,    37,   175,   144,    38,
     179,   180,   206,   182,    17,    21,   159,    83,    39,    40,
      41,   187,   215,   119,    26,   188,   189,   138,   192,   109,
     216,   217,   119,   193,    91,   163,   222,   224,    55,    32,
      33,    34,    35,    36,   203,   119,   204,    85,   176,   171,
     177,   202,   207,    27,    28,    29,    30,    90,    86,    87,
     218,   147,   149,   151,   153,   209,   210,   211,    37,    88,
      89,    38,   181,   225,   164,    94,   208,   185,   177,    95,
      99,   212,   219,    27,    28,    29,    30,    31,   100,    21,
     101,    32,    33,    34,    35,    36,    91,   111,    37,   113,
      55,    38,     8,     9,    10,    11,    12,   230,   115,   118,
      39,    40,    41,    42,    43,    44,    45,   119,   120,    46,
      47,    48,    49,    50,    51,    52,    53,   121,   122,    54,
      55,   135,   -22,   155,   123,   124,   125,   126,   127,   128,
       7,   156,   158,   157,     8,     9,    10,    11,    12,   160,
     167,   183,   186,   142,   196,   195,   197,   198,   213,    79,
     226,   220,   227,   228,   229,    98,   170,   173,   166,   174,
     191
};

static const yytype_uint8 yycheck[] =
{
      18,    81,   115,    90,    56,    37,    24,    16,    39,    16,
      23,    50,    37,    38,    16,    54,    51,     8,    53,    50,
      51,   129,    11,    25,    55,    19,    20,    79,    16,    16,
      23,     3,     4,     5,     6,     7,     0,    16,   146,    52,
      23,    50,    60,    16,    62,    54,    64,    54,    66,    21,
      81,    82,    83,     3,     4,     5,     6,     7,    47,   111,
       7,    11,    55,    13,    14,    15,    54,    54,    18,    10,
      16,    21,    55,    50,    46,    54,   163,   157,    50,    16,
      23,    54,   113,    30,    31,    32,    51,   118,    23,    50,
      23,     3,     4,     5,     6,     7,    46,    17,    18,    46,
      50,    23,    23,   216,   217,    23,    18,    48,    54,    21,
     141,   142,    55,   144,     7,     9,    51,    54,    30,    31,
      32,   152,    55,    23,     7,   156,   157,   158,   160,    10,
      52,    52,    23,    51,    46,     7,   216,   217,    50,    11,
      12,    13,    14,    15,   175,    23,   177,     7,    51,   120,
      53,    51,   183,     3,     4,     5,     6,     7,     7,     7,
      51,    86,    87,    88,    89,   196,   197,   198,    18,     7,
       7,    21,   143,    51,    46,     7,    51,   148,    53,     7,
       7,   199,   213,     3,     4,     5,     6,     7,     7,     9,
       7,    11,    12,    13,    14,    15,    46,    52,    18,    50,
      50,    21,    11,    12,    13,    14,    15,   225,    50,    50,
      30,    31,    32,    33,    34,    35,    36,    23,    22,    39,
      40,    41,    42,    43,    44,    45,    46,    17,    18,    49,
      50,     7,    52,     7,    24,    25,    26,    27,    28,    29,
       7,    53,    50,    16,    11,    12,    13,    14,    15,    51,
      33,    54,     5,    54,    52,     7,    52,    50,    50,    24,
      51,   214,    51,    51,    51,    51,   119,   130,   115,   133,
     158
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    57,    58,     0,    11,    47,     8,     7,    11,    12,
      13,    14,    15,    59,    61,    50,    50,     7,    51,    60,
      61,     9,    62,    63,    51,    53,     7,     3,     4,     5,
       6,     7,    11,    12,    13,    14,    15,    18,    21,    30,
      31,    32,    33,    34,    35,    36,    39,    40,    41,    42,
      43,    44,    45,    46,    49,    50,    62,    65,    66,    68,
      69,    70,    71,    72,    73,    74,    77,    78,    79,    80,
      83,    84,    85,    86,    87,    88,    89,    90,    62,    63,
      61,    16,    50,    54,    82,     7,     7,     7,     7,     7,
       7,    46,    90,    83,     7,     7,    67,    83,    67,     7,
       7,     7,    11,    13,    14,    15,    83,    92,    65,    10,
      64,    52,    62,    50,    62,    50,    62,    62,    50,    23,
      22,    17,    18,    24,    25,    26,    27,    28,    29,    93,
      94,    19,    20,    95,    65,     7,    83,    88,    83,    91,
      83,    16,    54,    16,    54,    81,    16,    81,    16,    81,
      16,    81,    16,    81,    82,     7,    53,    16,    50,    51,
      51,    65,    83,     7,    46,    79,    80,    33,    76,    83,
      84,    85,    86,    87,    89,    48,    51,    53,    55,    83,
      83,    85,    83,    54,    86,    85,     5,    83,    83,    83,
      88,    91,    90,    51,    82,     7,    52,    52,    50,    37,
      38,    75,    51,    83,    83,    55,    55,    83,    51,    83,
      83,    83,    62,    50,    52,    55,    52,    52,    51,    83,
      64,    79,    88,    79,    88,    51,    51,    51,    51,    51,
      62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    58,    59,    59,    60,    60,
      60,    61,    61,    61,    61,    61,    62,    63,    64,    65,
      65,    65,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    67,    67,    66,    68,    68,    68,
      69,    70,    71,    71,    71,    71,    72,    73,    66,    74,
      75,    75,    76,    76,    77,    78,    66,    79,    79,    79,
      79,    79,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    81,    81,    82,
      82,    83,    83,    84,    84,    85,    85,    86,    86,    87,
      87,    88,    88,    88,    89,    89,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    91,    91,    91,
      92,    92,    92,    92,    93,    93,    93,    93,    93,    93,
      94,    94,    95,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     7,    12,     0,     2,     1,     4,     2,
       0,     1,     1,     1,     1,     1,     3,     1,     1,     3,
       0,     2,     0,     5,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     3,     1,     1,     6,     2,     2,
       4,     1,     8,     8,     8,     8,     1,     1,     1,     4,
       2,     0,     6,     0,     4,     1,     1,     3,     3,     4,
       4,     4,     4,     2,     3,     4,     2,     3,     4,     2,
       3,     4,     2,     3,     4,     2,     3,     4,     3,     4,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     2,     2,     2,     2,     1,     4,     3,     1,     1,
       1,     1,     1,     1,     2,     4,     2,     3,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
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
#line 110 "src/sintatica.y" /* yacc.c:1646  */
    {
                ofstream myfile;
                myfile.open ("./generated/example.c");
 
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
                    	code = cabecalho.str() + "\nusing namespace std;\n\n" + incluiLista() + variaveis.str() + (yyvsp[-5]).traducao + "\n\nint main(void)\n{\n" + (yyvsp[0]).traducao + "\n\treturn 0;\n}\n\n"; 
                    	
                    	while(code.find("\n;\n") != npos)
                    		code.replace(code.find("\n;\n"), 3, "\n");
                    	
                    	cout << code;
                    	myfile << code;
                    }
                    else
                    {
                    	code = cabecalho.str() + "\nusing namespace std;\n\n" + variaveis.str() + (yyvsp[-5]).traducao + "\n\nint main(void)\n{\n" + (yyvsp[0]).traducao + "\n\treturn 0;\n}\n\n"; 
                    	
                    	while(code.find("\n;\n") != npos)
                    		code.replace(code.find("\n;\n"), 3, "");

                    	cout << code;
                    	myfile << code;
                    }
                } 
                myfile.close();
            }
#line 1604 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 151 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-6]).traducao + "\nvoid " + (yyvsp[-4]).traducao + "(" + (yyvsp[-2]).traducao + ")\n{\n\t" + (yyvsp[0]).traducao + "\n\treturn;\n}\n";
			}
#line 1612 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 155 "src/sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-9]).tipo != (yyvsp[-2]).tipo)
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Retorno inválido!\n";
                }

				(yyval).traducao = (yyvsp[-11]).traducao + "\n" + (yyvsp[-9]).traducao + "(" + (yyvsp[-7]).traducao + ")\n{\n\t" + (yyvsp[-4]).traducao + (yyvsp[-2]).traducao + "\n\treturn " + (yyvsp[-2]).label + ";\n}\n";

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
#line 1650 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 188 "src/sintatica.y" /* yacc.c:1646  */
    { (yyval).traducao = "";}
#line 1656 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 191 "src/sintatica.y" /* yacc.c:1646  */
    {
				fun_temp = (yyvsp[0]).label;
				string nome_temp = gera_ID_funcao((yyvsp[-1]).label, (yyvsp[0]).label);
				(yyval).traducao = (yyvsp[-1]).label + " " + nome_temp;
				(yyval).tipo = (yyvsp[-1]).label;
				(yyval).label = nome_temp;
				mapa_func[(yyvsp[0]).label].parametros = vector<string>();

			}
#line 1670 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 201 "src/sintatica.y" /* yacc.c:1646  */
    {
				string nome_temporario = gera_ID_funcao("void", (yyvsp[0]).label);
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = nome_temporario;
				(yyval).tipo = (yyvsp[0]).tipo;
				(yyval).tamanho = (yyvsp[0]).tamanho;
				fun_temp = (yyvsp[0]).label;
				mapa_func[(yyvsp[0]).label].parametros = vector<string>();
			}
#line 1684 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 212 "src/sintatica.y" /* yacc.c:1646  */
    {
				mapa_func[fun_temp].parametros.push_back((yyvsp[-1]).label);
				(yyval).traducao = (yyvsp[-3]).traducao + ", " + (yyvsp[-1]).label + " " + (yyvsp[0]).label;
			}
#line 1693 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 217 "src/sintatica.y" /* yacc.c:1646  */
    {
				mapa_func[fun_temp].parametros.push_back((yyvsp[-1]).label);
				(yyval).traducao = (yyvsp[-1]).label + " " + (yyvsp[0]).label;

			}
#line 1703 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 222 "src/sintatica.y" /* yacc.c:1646  */
    { (yyval).traducao = "";}
#line 1709 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 225 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
			}
#line 1717 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 229 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
			}
#line 1725 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 233 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
			}
#line 1733 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 237 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
			}
#line 1741 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 241 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
			}
#line 1749 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 246 "src/sintatica.y" /* yacc.c:1646  */
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

                while(((yyvsp[-1]).traducao.find(";") == 0) || ((yyvsp[-1]).traducao.find("\n") == 0))
            		(yyvsp[-1]).traducao.replace(0,1,"");

                (yyval).traducao = (yyvsp[-1]).traducao;
                nivel--;
                pilha_variaveis.pop_back();
            }
#line 1784 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 278 "src/sintatica.y" /* yacc.c:1646  */
    {
                nivel++;
                pilha_variaveis.push_back(mapa_variaveis);
                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 1794 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 285 "src/sintatica.y" /* yacc.c:1646  */
    {
                mapa_variaveis.clear();
                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 1803 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 291 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao;
            }
#line 1811 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 295 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = "";
                (yyval).label = "";
            }
#line 1820 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 300 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[-1]).traducao + (yyvsp[0]).traducao;
            }
#line 1828 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 306 "src/sintatica.y" /* yacc.c:1646  */
    {
            	if(mapa_func[(yyvsp[-3]).label].nome_temp == "")
                {
                	erro = true;
                	cout << "Erro na linha " << nlinha <<": Função \"" << (yyvsp[-3]).label << "\" não declarada." << endl << endl;
                }

                int i;
                if(mapa_func[(yyvsp[-3]).label].parametros.size() == argumentos.size())
                {
                	for(i = 0; i < argumentos.size(); i++)
                	{
                		if(mapa_func[(yyvsp[-3]).label].parametros[i] != argumentos[i])
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

                info_func var = mapa_func[(yyvsp[-3]).label];
                (yyval).label = var.nome_temp + "(" + (yyvsp[-1]).traducao + ")";
                (yyval).traducao = (yyvsp[-1]).label + "\n\t" + var.nome_temp + "(" + (yyvsp[-1]).traducao + ");\n";
                (yyval).tipo = var.tipo;
                //$$.tamanho = var.tamanho;
            }
#line 1866 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 341 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 1875 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 348 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 1884 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 355 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 1893 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 361 "src/sintatica.y" /* yacc.c:1646  */
    {
				if(pilha_fim_loop.size() > 0)
					(yyval).traducao = "\n\tgoto " + pilha_fim_loop.back() + ";\n";
				else
				{
					erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
				}

			}
#line 1908 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 372 "src/sintatica.y" /* yacc.c:1646  */
    {
				if(pilha_inicio_loop.size() > 0)
					(yyval).traducao = "\n\tgoto " + pilha_inicio_loop.back() + ";\n";
				else
				{
					erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
				}
			}
#line 1922 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 382 "src/sintatica.y" /* yacc.c:1646  */
    {
				if(pilha_fim_loop.size() > 0)
					(yyval).traducao = "\n\tgoto " + pilha_fim_loop[0] + ";\n";
				else
				{
					erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
				}
			}
#line 1936 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 392 "src/sintatica.y" /* yacc.c:1646  */
    {
				if(pilha_inicio_loop.size() > 0)
					(yyval).traducao = "\n\tgoto " + pilha_inicio_loop[0] + ";\n";
				else
				{
					erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
				}
			}
#line 1950 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 403 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 1959 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 408 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao + "\n\tcout << endl;\n";
            }
#line 1968 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 413 "src/sintatica.y" /* yacc.c:1646  */
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
                	string nome_temp_leitura = gera_variavel_temporaria("string", "", 6);
                	string nome_temp_teste = gera_variavel_temporaria("int", "");
					string lb1 = geraLabel(); string lb2 = geraLabel(); string lb3 = geraLabel();

                	(yyval).traducao = "\n\tcin >> " + nome_temp_leitura + ";\n\t" + nome_temp_teste + " = strcmp(" + nome_temp_leitura + ", \"true\" );\n\t";
                	(yyval).traducao += "if(!" + nome_temp_teste + " == 0) goto " + lb1 + ";\n\t" + var.nome_temp + " = 1;\n\tgoto " + lb3 + ";\n" + lb1 + ":\n\t";
                	(yyval).traducao += nome_temp_teste + " = strcmp(" + nome_temp_leitura + ", \"false\" );\n\t";
                	(yyval).traducao += "if(!" + nome_temp_teste + " == 0) goto " + lb2 + ";\n\t" + var.nome_temp + " = 0;\n\tgoto " + lb3 + ";\n" + lb2 + ":\n\t";
                	(yyval).traducao += "cout << \"Valor: \" << " + nome_temp_leitura + " << \" inválido!\\n\";\n\texit(1);\n" + lb3 + ":\n\t";

                	(yyval).tamanho = var.tamanho;
                }
                else
                {
                	(yyval).traducao = "\n\tcin >> " + var.nome_temp + ";\n\t";
                    (yyval).tamanho = var.tamanho;
                }
            }
#line 2004 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 446 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				if((yyvsp[0]).tipo == "boolean")
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\n\tif(" + (yyvsp[0]).label + ") cout << \"true\";\n\tif(!" + (yyvsp[0]).label + ") cout << \"false\";\n";
				else
					(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\n\tcout << " + (yyvsp[0]).label + ";\n";
			}
#line 2016 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 454 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				if((yyvsp[0]).tipo == "boolean")
					(yyval).traducao = (yyvsp[0]).traducao + "\n\tif(" + (yyvsp[0]).label + ") cout << \"true\";\n\tif(!" + (yyvsp[0]).label + ") cout << \"false\";\n";	
				else
					(yyval).traducao = (yyvsp[0]).traducao + "\n\tcout << " + (yyvsp[0]).label + ";\n";
			}
#line 2028 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 463 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 2037 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 469 "src/sintatica.y" /* yacc.c:1646  */
    {
                if((yyvsp[-1]).tipo != "boolean")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
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
#line 2059 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 487 "src/sintatica.y" /* yacc.c:1646  */
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
#line 2077 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 501 "src/sintatica.y" /* yacc.c:1646  */
    {

                (yyval).traducao = "\n\n" + (yyvsp[-1]).traducao + (yyvsp[0]).traducao + "\n\tgoto " + pilha_labels_loop.top() + ";\n";
                pilha_labels_loop.pop();
                (yyval).traducao += "\n" + pilha_labels_loop.top() + ":\n";
                pilha_labels_loop.pop();
                pilha_inicio_loop.pop_back();
                pilha_fim_loop.pop_back();
            }
#line 2091 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 512 "src/sintatica.y" /* yacc.c:1646  */
    {

                if((yyvsp[-1]).tipo != "boolean")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                }

                
                string a = geraLabel();
                string b = geraLabel();
                pilha_labels_loop.push(a); pilha_labels_loop.push(b); pilha_labels_loop.push(a); pilha_labels_loop.push(b);
                pilha_inicio_loop.push_back(pilha_labels_loop.top());
                pilha_fim_loop.push_back(a);
                (yyval).traducao = "\n" + pilha_labels_loop.top() + ":\n\t" + (yyvsp[-1]).traducao + "\t";
                pilha_labels_loop.pop();
                (yyval).traducao += (yyvsp[-1]).label + " = !" + (yyvsp[-1]).label + ";\n\tif(" + (yyvsp[-1]).label + ") goto " + pilha_labels_loop.top() + ";\n"; 
                pilha_labels_loop.pop();

            }
#line 2116 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 534 "src/sintatica.y" /* yacc.c:1646  */
    {
                nivel++;
                pilha_variaveis.push_back(mapa_variaveis);
            }
#line 2125 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 540 "src/sintatica.y" /* yacc.c:1646  */
    {
                if((yyvsp[-3]).tipo != "boolean")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                }
                string a = geraLabel();
                string b = geraLabel();
                pilha_labels_loop.push(a); pilha_labels_loop.push(b); pilha_labels_loop.push(a); pilha_labels_loop.push(b);
                pilha_inicio_loop.push_back(pilha_labels_loop.top());
                pilha_fim_loop.push_back(a);
                (yyval).traducao = (yyvsp[-5]).traducao + pilha_labels_loop.top() + ":\n\t" + (yyvsp[-3]).traducao + "\t";
                pilha_labels_loop.pop();
                (yyval).traducao += (yyvsp[-3]).label + " = !" + (yyvsp[-3]).label + ";\n\tif(" + (yyvsp[-3]).label + ") goto " + pilha_labels_loop.top() + ";\n";
                pilha_labels_loop.pop();
                pilha_labels_loop.push((yyvsp[-1]).traducao);
            }
#line 2147 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 558 "src/sintatica.y" /* yacc.c:1646  */
    {
                if((yyvsp[-3]).tipo != "boolean")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                }
                string a = geraLabel();
                string b = geraLabel();
                pilha_labels_loop.push(a); pilha_labels_loop.push(b); pilha_labels_loop.push(a); pilha_labels_loop.push(b);
                pilha_inicio_loop.push_back(pilha_labels_loop.top());
                pilha_fim_loop.push_back(a);
                (yyval).traducao = (yyvsp[-5]).traducao + pilha_labels_loop.top() + ":\n\t" + (yyvsp[-3]).traducao + "\t";
                pilha_labels_loop.pop();
                (yyval).traducao += (yyvsp[-3]).label + " = !" + (yyvsp[-3]).label + ";\n\tif(" + (yyvsp[-3]).label + ") goto " + pilha_labels_loop.top() + ";\n";
                pilha_labels_loop.pop();
                pilha_labels_loop.push((yyvsp[-1]).traducao);
            }
#line 2169 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 576 "src/sintatica.y" /* yacc.c:1646  */
    {
                if((yyvsp[-3]).tipo != "boolean")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                }
                string a = geraLabel();
                string b = geraLabel();
                pilha_labels_loop.push(a); pilha_labels_loop.push(b); pilha_labels_loop.push(a); pilha_labels_loop.push(b);
                pilha_inicio_loop.push_back(pilha_labels_loop.top());
                pilha_fim_loop.push_back(a);
                (yyval).traducao = (yyvsp[-5]).traducao + "\n" + pilha_labels_loop.top() + ":\n\t" + (yyvsp[-3]).traducao + "\t";
                pilha_labels_loop.pop();
                (yyval).traducao += (yyvsp[-3]).label + " = !" + (yyvsp[-3]).label + ";\n\tif(" + (yyvsp[-3]).label + ") goto " + pilha_labels_loop.top() + ";\n";
                pilha_labels_loop.pop();
                pilha_labels_loop.push((yyvsp[-1]).traducao);
            }
#line 2191 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 594 "src/sintatica.y" /* yacc.c:1646  */
    {
                if((yyvsp[-3]).tipo != "boolean")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                }
                string a = geraLabel();
                string b = geraLabel();
                pilha_labels_loop.push(a); pilha_labels_loop.push(b); pilha_labels_loop.push(a); pilha_labels_loop.push(b);
                pilha_inicio_loop.push_back(pilha_labels_loop.top());
                pilha_fim_loop.push_back(a);
                (yyval).traducao = (yyvsp[-5]).traducao + "\n" + pilha_labels_loop.top() + ":\n\t" + (yyvsp[-3]).traducao + "\t";
                pilha_labels_loop.pop();
                (yyval).traducao += (yyvsp[-3]).label + " = !" + (yyvsp[-3]).label + ";\n\tif(" + (yyvsp[-3]).label + ") goto " + pilha_labels_loop.top() + ";\n";
                pilha_labels_loop.pop();
                pilha_labels_loop.push((yyvsp[-1]).traducao);
            }
#line 2213 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 613 "src/sintatica.y" /* yacc.c:1646  */
    {
                nivel++;
                pilha_variaveis.push_back(mapa_variaveis);
            }
#line 2222 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 619 "src/sintatica.y" /* yacc.c:1646  */
    {
            	string a = geraLabel(); string b = geraLabel();
                pilha_labels_loop.push(b); pilha_labels_loop.push(a);	pilha_labels_loop.push(a);
                pilha_inicio_loop.push_back(pilha_labels_loop.top());
                pilha_fim_loop.push_back(b);
                nivel++;
                pilha_variaveis.push_back(mapa_variaveis);
            }
#line 2235 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 629 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 2244 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 635 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = "\n\n" + (yyvsp[-3]).traducao + (yyvsp[-2]).traducao + "\ngoto " + label_final.top() + ";\n" + pilha_labels_condicional.top() + ":\n";
                pilha_labels_condicional.pop();
                label_final.pop();
               	(yyval).traducao += (yyvsp[-1]).traducao + (yyvsp[0]).traducao + label_final.top() + ":\n";
			}
#line 2255 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 643 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 2263 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 647 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
			}
#line 2271 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 652 "src/sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2]).tipo != "boolean")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                }

                string a = geraLabel();
                label_final.push(label_final.top());	label_final.push(label_final.top());
                pilha_labels_condicional.push(a); pilha_labels_condicional.push(a);
        
                (yyval).traducao = "\n\t" + (yyvsp[-5]).traducao + "\n\t" + (yyvsp[-2]).traducao + "\t" + (yyvsp[-2]).label + " = !" + (yyvsp[-2]).label + ";\n\tif(" + (yyvsp[-2]).label + ") goto " + pilha_labels_condicional.top() + ";\n"; 
                pilha_labels_condicional.pop();
                (yyval).traducao += (yyvsp[0]).traducao + "\ngoto " + label_final.top() + ";\n" + pilha_labels_condicional.top() + ":\n";
                pilha_labels_condicional.pop();
                label_final.pop();
			}
#line 2293 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 670 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
			}
#line 2301 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 675 "src/sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-1]).tipo != "boolean")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                }


                string a = geraLabel();	string b = geraLabel();
                label_final.push(a);	label_final.push(a);
                pilha_labels_condicional.push(b); pilha_labels_condicional.push(b);
        
                (yyval).traducao = (yyvsp[-1]).traducao + "\t" + (yyvsp[-1]).label + " = !" + (yyvsp[-1]).label + ";\n\tif(" + (yyvsp[-1]).label + ") goto " + pilha_labels_condicional.top() + ";\n"; 
                pilha_labels_condicional.pop();

			}
#line 2322 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 693 "src/sintatica.y" /* yacc.c:1646  */
    {
				nivel++;
                pilha_variaveis.push_back(mapa_variaveis);
			}
#line 2331 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 699 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
            }
#line 2340 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 706 "src/sintatica.y" /* yacc.c:1646  */
    {
            	if((buscaID((yyvsp[-2]).label).tipo == "string" && (yyvsp[0]).tipo == "string")||(buscaID((yyvsp[-2]).label).tipo == "string" && (yyvsp[0]).tipo == "char"))
                {
                    info_variavel var = buscaID((yyvsp[-2]).label);
                    var.tamanho = (yyvsp[0]).tamanho;   alteraID((yyvsp[-2]).label, var);                 
                    (yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\tstrcpy(" + buscaID((yyvsp[-2]).label).nome_temp + ", " + (yyvsp[0]).label + ");\n";
                }
                else
                {
                    string tipo = buscaID((yyvsp[-2]).label).tipo;

                    if(mapa_operacoes[tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 1)
                        (yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + buscaID((yyvsp[-2]).label).nome_temp + " = " + "(" + mapa_operacoes[tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo + ")" + (yyvsp[0]).label + ";\n";
                    else if(mapa_operacoes[tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 0)
                        (yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + buscaID((yyvsp[-2]).label).nome_temp + " = " + (yyvsp[0]).label + ";\n";
                    else{
                        erro = true;
                        cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
                    }
                }
                if((yyvsp[0]).tipo == "null" || (yyvsp[0]).tipo == "")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
                }
            }
#line 2371 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 733 "src/sintatica.y" /* yacc.c:1646  */
    {
            	(yyval).traducao = (yyvsp[0]).traducao + "\n\t" + buscaID((yyvsp[-2]).label).nome_temp + " = " + (yyvsp[0]).label + ";\n";
            }
#line 2379 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 737 "src/sintatica.y" /* yacc.c:1646  */
    {
            	info_variavel var = pilha_variaveis[0][(yyvsp[-2]).label];
                if(var.nome_temp == "")
                {
                	erro = true;
                	cout << "Erro na linha " << nlinha <<": Variável \"" << (yyvsp[-2]).label << "\" não declarada." << endl << endl;
                }
            	if((yyvsp[0]).tipo == "null" || (yyvsp[0]).tipo == "")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
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
                    else{
                        erro = true;
                        cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
                    }
                }
            }
#line 2415 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 769 "src/sintatica.y" /* yacc.c:1646  */
    {
            	//Rever isto aqui...---------------------------------
            	info_variavel var = pilha_variaveis[0][(yyvsp[-2]).label];
                if(var.nome_temp == "")
                {
                	erro = true;
                	cout << "Erro na linha " << nlinha <<": Variável \"" << (yyvsp[-2]).label << "\" não declarada." << endl << endl;
                }
            	if((yyvsp[0]).tipo == "null" || (yyvsp[0]).tipo == "")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
                }
            	(yyval).traducao = (yyvsp[0]).traducao + "\n\t" + var.nome_temp + " = " + (yyvsp[0]).label + ";\n";
            }
#line 2435 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 785 "src/sintatica.y" /* yacc.c:1646  */
    {
            	string var_temp = gera_variavel_temporaria("int");
            	info_variavel var = buscaID((yyvsp[-3]).label);
            	var.acesso_lista = geraLabel();
            	alteraID((yyvsp[-3]).label, var);

            	string acesso_lista = "\n\tnode *" + buscaID((yyvsp[-3]).label).acesso_lista + ";\n\t" + buscaID((yyvsp[-3]).label).acesso_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID((yyvsp[-3]).label).acesso_lista + ");\n\tif(!" + buscaID((yyvsp[-3]).label).acesso_lista + ") cout << \"Sem memoria disponivel!\\n\";";
            	for (int i = 0; i < vet_temp.size(); ++i)
            	{
            		acesso_lista += "\n\tinsereFim(" + buscaID((yyvsp[-3]).label).acesso_lista + ", " + vet_temp[i] + ");";
            	}
            	vet_temp.clear();
            	
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
	                    erro = true;
	                    cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
	                }
	                if(mapa_operacoes[buscaID((yyvsp[-3]).label).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo == "null" || mapa_operacoes[buscaID((yyvsp[-3]).label).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo == "")
	                {
	                    erro = true;
	                    cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
	                }
	            }
            }
#line 2476 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 823 "src/sintatica.y" /* yacc.c:1646  */
    {
                info_variavel atributos = { (yyvsp[-3]).label, gera_variavel_temporaria((yyvsp[-3]).label, (yyvsp[-2]).label)};

                if(mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 1)
                    (yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + atributos.nome_temp + " = " + "(" + mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo + ")" + (yyvsp[0]).label + ";";
                else if(mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 0)
                    (yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + atributos.nome_temp + " = " + (yyvsp[0]).label + ";";
                else{
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
                }
            }
#line 2493 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 836 "src/sintatica.y" /* yacc.c:1646  */
    {
                info_variavel atributos = { (yyvsp[-1]).label, gera_variavel_temporaria((yyvsp[-1]).label, (yyvsp[0]).label)};
                (yyval).traducao = "\n\t" + atributos.nome_temp + " = " + "0" + ";";
            }
#line 2502 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 841 "src/sintatica.y" /* yacc.c:1646  */
    {
            	lista = true;
            	gera_variavel_temporaria((yyvsp[-2]).label, (yyvsp[-1]).label);
            	info_variavel var = buscaID((yyvsp[-1]).label);
            	var.nome_lista = geraLabel();
            	alteraID((yyvsp[-1]).label, var);

            	string insere_lista = "\n\tnode *" + buscaID((yyvsp[-1]).label).nome_lista + ";\n\t" + buscaID((yyvsp[-1]).label).nome_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID((yyvsp[-1]).label).nome_lista + ");\n\tif(!" + buscaID((yyvsp[-1]).label).nome_lista + ") cout << \"Sem memoria disponivel!\\n\";";
            	for (int i = 0; i < vet_temp.size(); ++i)
            	{
            		insere_lista += "\n\tinsereFim(" + buscaID((yyvsp[-1]).label).nome_lista + ", " + vet_temp[i] + ");";
            	}
            	vet_temp.clear();
            	(yyval).traducao = "\n" + (yyvsp[0]).traducao + "\n\t" + insere_lista + "\n\n\t" + (yyvsp[-2]).label + " " + buscaID((yyvsp[-1]).label).nome_temp + "[" + (yyvsp[0]).label + "];\n";
            }
#line 2522 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 857 "src/sintatica.y" /* yacc.c:1646  */
    {
                info_variavel atributos = { (yyvsp[-3]).label, gera_variavel_temporaria((yyvsp[-3]).label, (yyvsp[-2]).label)};

                if(mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 1)
                    (yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + atributos.nome_temp + " = " + "(" + mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo + ")" + (yyvsp[0]).label + ";";
                else if(mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 0)
                    (yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + atributos.nome_temp + " = " + (yyvsp[0]).label + ";";
                else{
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
                }
            }
#line 2539 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 870 "src/sintatica.y" /* yacc.c:1646  */
    {
                info_variavel atributos = { (yyvsp[-1]).label, gera_variavel_temporaria((yyvsp[-1]).label, (yyvsp[0]).label)};
                (yyval).traducao = "\n\t" + atributos.nome_temp + " = " + "0.0" + ";";
            }
#line 2548 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 875 "src/sintatica.y" /* yacc.c:1646  */
    {
            	lista = true;
            	gera_variavel_temporaria((yyvsp[-2]).label, (yyvsp[-1]).label);
            	info_variavel var = buscaID((yyvsp[-1]).label);
            	var.nome_lista = geraLabel();
            	alteraID((yyvsp[-1]).label, var);

            	string insere_lista = "\n\tnode *" + buscaID((yyvsp[-1]).label).nome_lista + ";\n\t" + buscaID((yyvsp[-1]).label).nome_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID((yyvsp[-1]).label).nome_lista + ");\n\tif(!" + buscaID((yyvsp[-1]).label).nome_lista + ") cout << \"Sem memoria disponivel!\\n\";";
            	for (int i = 0; i < vet_temp.size(); ++i)
            	{
            		insere_lista += "\n\tinsereFim(" + buscaID((yyvsp[-1]).label).nome_lista + ", " + vet_temp[i] + ");";
            	}
            	vet_temp.clear();
            	(yyval).traducao = "\n" + (yyvsp[0]).traducao + "\n\t" + insere_lista + "\n\n\t" + (yyvsp[-2]).label + " " + buscaID((yyvsp[-1]).label).nome_temp + "[" + (yyvsp[0]).label + "];\n";
            }
#line 2568 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 891 "src/sintatica.y" /* yacc.c:1646  */
    {
                info_variavel atributos = { (yyvsp[-3]).label, gera_variavel_temporaria((yyvsp[-3]).label, (yyvsp[-2]).label)};

                if(mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 1)
                    (yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + atributos.nome_temp + " = " + "(" + mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo + ")" + (yyvsp[0]).label + ";";
                else if(mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 0)
                    (yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + atributos.nome_temp + " = " + (yyvsp[0]).label + ";";
                else{
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
                }
            }
#line 2585 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 904 "src/sintatica.y" /* yacc.c:1646  */
    {
                info_variavel atributos = { (yyvsp[-1]).label, gera_variavel_temporaria((yyvsp[-1]).label, (yyvsp[0]).label)};
                (yyval).traducao = "\n\t" + atributos.nome_temp + " = " + "1" + ";";
            }
#line 2594 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 908 "src/sintatica.y" /* yacc.c:1646  */
    {
            	lista = true;
            	gera_variavel_temporaria((yyvsp[-2]).label, (yyvsp[-1]).label);
            	info_variavel var = buscaID((yyvsp[-1]).label);
            	var.nome_lista = geraLabel();
            	alteraID((yyvsp[-1]).label, var);

            	string insere_lista = "\n\tnode *" + buscaID((yyvsp[-1]).label).nome_lista + ";\n\t" + buscaID((yyvsp[-1]).label).nome_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID((yyvsp[-1]).label).nome_lista + ");\n\tif(!" + buscaID((yyvsp[-1]).label).nome_lista + ") cout << \"Sem memoria disponivel!\\n\";";
            	for (int i = 0; i < vet_temp.size(); ++i)
            	{
            		insere_lista += "\n\tinsereFim(" + buscaID((yyvsp[-1]).label).nome_lista + ", " + vet_temp[i] + ");";
            	}
            	vet_temp.clear();
            	(yyval).traducao = "\n" + (yyvsp[0]).traducao + "\n\t" + insere_lista + "\n\n\t" + (yyvsp[-2]).traducao + " " + buscaID((yyvsp[-1]).label).nome_temp + "[" + (yyvsp[0]).label + "];\n";
            }
#line 2614 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 924 "src/sintatica.y" /* yacc.c:1646  */
    {
                info_variavel atributos = { (yyvsp[-3]).label, gera_variavel_temporaria((yyvsp[-3]).label, (yyvsp[-2]).label,1)};
                
                if(mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 1)
                    (yyval).traducao = "\n\t" + atributos.nome_temp + " = " + "(" + mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo + ")" + (yyvsp[0]).label + ";";
                else if(mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 0)
                    (yyval).traducao = "\n\t" + atributos.nome_temp + " = " + (yyvsp[0]).label + ";";
                else{
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
                }
            }
#line 2631 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 937 "src/sintatica.y" /* yacc.c:1646  */
    {
                info_variavel atributos = { (yyvsp[-1]).label, gera_variavel_temporaria((yyvsp[-1]).label, (yyvsp[0]).label,1)};
                (yyval).traducao = "\n\t" + atributos.nome_temp + " = " + "\'\'" + ";";
            }
#line 2640 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 941 "src/sintatica.y" /* yacc.c:1646  */
    {
            	lista = true;
            	gera_variavel_temporaria((yyvsp[-2]).label, (yyvsp[-1]).label);
            	info_variavel var = buscaID((yyvsp[-1]).label);
            	var.nome_lista = geraLabel();
            	alteraID((yyvsp[-1]).label, var);

            	string insere_lista = "\n\tnode *" + buscaID((yyvsp[-1]).label).nome_lista + ";\n\t" + buscaID((yyvsp[-1]).label).nome_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID((yyvsp[-1]).label).nome_lista + ");\n\tif(!" + buscaID((yyvsp[-1]).label).nome_lista + ") cout << \"Sem memoria disponivel!\\n\";";
            	for (int i = 0; i < vet_temp.size(); ++i)
            	{
            		insere_lista += "\n\tinsereFim(" + buscaID((yyvsp[-1]).label).nome_lista + ", " + vet_temp[i] + ");";
            	}
            	vet_temp.clear();
            	(yyval).traducao = "\n" + (yyvsp[0]).traducao + "\n\t" + insere_lista + "\n\n\t" + (yyvsp[-2]).label + " " + buscaID((yyvsp[-1]).label).nome_temp + "[" + (yyvsp[0]).label + "];\n";
            }
#line 2660 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 957 "src/sintatica.y" /* yacc.c:1646  */
    {
                info_variavel atributos = { (yyvsp[-3]).label, gera_variavel_temporaria((yyvsp[-3]).label, (yyvsp[-2]).label, (yyvsp[0]).tamanho)};
                if((mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 0) && (mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo != ""))
                {
                    (yyval).traducao = (yyvsp[0]).traducao + "\n\tstrcpy(" + atributos.nome_temp + ", " + (yyvsp[0]).label + ");\n";
                }
                else
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
                }
            }
#line 2677 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 970 "src/sintatica.y" /* yacc.c:1646  */
    {
                info_variavel atributos = { (yyvsp[-1]).label, gera_variavel_temporaria((yyvsp[-1]).label, (yyvsp[0]).label,0)};
                (yyval).traducao = "\n\tstrcpy(" + atributos.nome_temp + ", \"\");\n";
            }
#line 2686 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 974 "src/sintatica.y" /* yacc.c:1646  */
    {
            	lista = true;
            	gera_variavel_temporaria((yyvsp[-2]).label, (yyvsp[-1]).label);
            	info_variavel var = buscaID((yyvsp[-1]).label);
            	var.nome_lista = geraLabel();
            	alteraID((yyvsp[-1]).label, var);

            	string insere_lista = "\n\tnode *" + buscaID((yyvsp[-1]).label).nome_lista + ";\n\t" + buscaID((yyvsp[-1]).label).nome_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID((yyvsp[-1]).label).nome_lista + ");\n\tif(!" + buscaID((yyvsp[-1]).label).nome_lista + ") cout << \"Sem memoria disponivel!\\n\";";
            	for (int i = 0; i < vet_temp.size(); ++i)
            	{
            		insere_lista += "\n\tinsereFim(" + buscaID((yyvsp[-1]).label).nome_lista + ", " + vet_temp[i] + ");";
            	}
            	vet_temp.clear();
            	(yyval).traducao = "\n" + (yyvsp[0]).traducao + "\n\t" + insere_lista + "\n\n\tstr " + buscaID((yyvsp[-1]).label).nome_temp + "[" + (yyvsp[0]).label + "];\n";
            }
#line 2706 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 991 "src/sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-1]).tipo != "int")
				{
					erro = true;
					cout << "Tipo inválido para tamanho de vetor.\n";
				}
				string var = gera_variavel_temporaria("int");

				vet_temp.push_back((yyvsp[-1]).label);
				(yyval).traducao = (yyvsp[-3]).traducao + (yyvsp[-1]).traducao + "\n\t" + var + " = " + (yyvsp[-3]).label + " * " + (yyvsp[-1]).label + ";\n";
				(yyval).label = var;
			}
#line 2723 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1004 "src/sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-1]).tipo != "int")
				{
					erro = true;
					cout << "Tipo inválido para tamanho de vetor.\n";
				}
				vet_temp.push_back((yyvsp[-1]).label);
				(yyval).traducao = (yyvsp[-1]).traducao;
				(yyval).label = (yyvsp[-1]).label;
			}
#line 2738 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1016 "src/sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-1]).tipo != "int")
				{
					erro = true;
					cout << "Tipo inválido para indice de vetor.\n";
				}
				string var = gera_variavel_temporaria("int");

				vet_temp.push_back((yyvsp[-1]).label);
				(yyval).traducao = (yyvsp[-3]).traducao + (yyvsp[-1]).traducao + ";\n";
			}
#line 2754 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1028 "src/sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-1]).tipo != "int")
				{
					erro = true;
					cout << "Tipo inválido para indice de vetor.\n";
				}
				vet_temp.push_back((yyvsp[-1]).label);
				(yyval).traducao = (yyvsp[-1]).traducao;
			}
#line 2768 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1039 "src/sintatica.y" /* yacc.c:1646  */
    {
            
                string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo);
                (yyval).label = nome_variavel_temporaria;
                (yyval).tipo = mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo;
                (yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\n\t" + (yyval).label + " = " +(yyvsp[-2]).label + " " + (yyvsp[-1]).traducao + " " + (yyvsp[0]).label + ";\n";
            }
#line 2780 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1047 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).tamanho = (yyvsp[0]).tamanho;
            }
#line 2791 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1055 "src/sintatica.y" /* yacc.c:1646  */
    {
                string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo);
                (yyval).label = nome_variavel_temporaria;
                (yyval).tipo = mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo;

                (yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\n\t" + (yyval).label + " = " +(yyvsp[-2]).label + " " + (yyvsp[-1]).traducao + " " + (yyvsp[0]).label + ";\n";
            }
#line 2803 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1063 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).tamanho = (yyvsp[0]).tamanho;
            }
#line 2814 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1071 "src/sintatica.y" /* yacc.c:1646  */
    {
            	if(mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo == "" || mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo == "null")
            	{
            		erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
            	}
            	if(((yyvsp[-2]).tipo == "string") && ((yyvsp[0]).tipo == "string"))
            	{
            		//Maior
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
#line 2877 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1130 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).tamanho = (yyvsp[0]).tamanho;
            }
#line 2888 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1138 "src/sintatica.y" /* yacc.c:1646  */
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
                        erro = true;
                        cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
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
                        erro = true;
                        cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                    }
                    (yyval).tipo = mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo;
                }
            }
#line 2937 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1183 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).tamanho = (yyvsp[0]).tamanho;
            }
#line 2948 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1191 "src/sintatica.y" /* yacc.c:1646  */
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
                } else {
                    (yyval).traducao = (yyvsp[0]).traducao + "\t" + (yyvsp[-2]).traducao + "\n\t" + nome_variavel_temporaria + " = " + "(" + mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo + ")" + (yyvsp[0]).label + ";";
                    (yyval).traducao += "\n\t" + nome_variavel_temporaria + " = " + (yyvsp[-2]).label + " " + (yyvsp[-1]).label + " " + nome_variavel_temporaria + ";";
                }

                if (mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando != 0 || mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo == "")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                }
                (yyval).tipo = mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo;
            }
#line 2976 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1215 "src/sintatica.y" /* yacc.c:1646  */
    {
                
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).tamanho = (yyvsp[0]).tamanho;
            }
#line 2988 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1224 "src/sintatica.y" /* yacc.c:1646  */
    {
				if ((yyvsp[0]).tipo != "boolean")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                }
                (yyval).label = (yyvsp[0]).label;
                (yyval).traducao = "\n\t" + (yyvsp[0]).traducao + "\n\t" + (yyvsp[0]).label + " = !" + (yyvsp[0]).label + ";\n";
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).tamanho = (yyvsp[0]).tamanho;
			}
#line 3004 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1236 "src/sintatica.y" /* yacc.c:1646  */
    {
            	if ((yyvsp[0]).tipo != "int")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                }
                info_variavel var = buscaID((yyvsp[0]).label);
                (yyval).label = var.nome_temp;
                (yyval).traducao = "\n\t" + var.nome_temp + " = " + var.nome_temp + " + 1;\n";
                (yyval).tipo = var.tipo;
                (yyval).tamanho = var.tamanho;
                
            }
#line 3022 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1250 "src/sintatica.y" /* yacc.c:1646  */
    {
                info_variavel var = buscaID((yyvsp[0]).label);
                (yyval).label = var.nome_temp;
                (yyval).traducao = "\n\t" + var.nome_temp + " = " + var.nome_temp + " - 1;\n";
                (yyval).tipo = var.tipo;
                (yyval).tamanho = var.tamanho;
            }
#line 3034 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1259 "src/sintatica.y" /* yacc.c:1646  */
    {
                if ((yyvsp[0]).tipo == "boolean" || (yyvsp[0]).tipo == "string" || (yyvsp[0]).tipo == "char")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Operação inválida!\n";
                }
                (yyval).label = (yyvsp[-1]).label + (yyvsp[0]).label;
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).traducao = "";
            }
#line 3049 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1270 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[0]).label;
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).tamanho = (yyvsp[0]).tamanho;
            }
#line 3060 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1278 "src/sintatica.y" /* yacc.c:1646  */
    {
                
                string nome_variavel_temporaria = gera_variavel_temporaria((yyvsp[-2]).tipo);
                (yyval).label = nome_variavel_temporaria;

                if(mapa_operacoes["("+(yyvsp[-2]).label+")"+(yyvsp[0]).tipo].tipo == "null" || mapa_operacoes["("+(yyvsp[-2]).label+")"+(yyvsp[0]).tipo].tipo == "")
                {
                    erro = true;
                    cout << "Erro na linha: " << nlinha << ". Cast inválido!\n";
                }
                else
                {
                    (yyval).traducao = (yyvsp[0]).traducao +"\n\t" + (yyval).label + " = "+ "(" + (yyvsp[-2]).label + ")"+ (yyvsp[0]).label + ";";
                }
                    (yyval).tipo = (yyvsp[-2]).tipo;

            }
#line 3082 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1296 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).label = (yyvsp[-1]).label;
                (yyval).traducao = (yyvsp[-1]).traducao;
                (yyval).tipo = (yyvsp[-1]).tipo;
            }
#line 3092 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1302 "src/sintatica.y" /* yacc.c:1646  */
    {
                
                string nome_variavel_temporaria = gera_variavel_temporaria((yyvsp[0]).tipo);
                (yyval).label = nome_variavel_temporaria;
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).traducao ="\n\t" + nome_variavel_temporaria + " = " + (yyvsp[0]).label + ";";
            }
#line 3104 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1310 "src/sintatica.y" /* yacc.c:1646  */
    {
                string nome_variavel_temporaria = gera_variavel_temporaria((yyvsp[0]).tipo);
                (yyval).label = nome_variavel_temporaria;
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).traducao ="\n\t" + nome_variavel_temporaria + " = " + (yyvsp[0]).label + ";";
            }
#line 3115 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1317 "src/sintatica.y" /* yacc.c:1646  */
    {   
                string nome_variavel_temporaria = gera_variavel_temporaria((yyvsp[0]).tipo);
                (yyval).label = nome_variavel_temporaria;
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).tamanho = 1;
                (yyval).traducao ="\n\t" + nome_variavel_temporaria + " = " + (yyvsp[0]).label + ";";
            }
#line 3127 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1325 "src/sintatica.y" /* yacc.c:1646  */
    {   
                string nome_variavel_temporaria = gera_variavel_temporaria((yyvsp[0]).tipo);
                (yyval).label = nome_variavel_temporaria;
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).traducao ="\n\t" + nome_variavel_temporaria + " = " + (yyvsp[0]).traducao + ";\n";
            }
#line 3138 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1332 "src/sintatica.y" /* yacc.c:1646  */
    {   
                string nome_variavel_temporaria = gera_variavel_temporaria((yyvsp[0]).tipo, "", (yyvsp[0]).tamanho);
                (yyval).label = nome_variavel_temporaria;
                (yyval).tipo = (yyvsp[0]).tipo;
                (yyval).traducao = "\n\tstrcpy(" + nome_variavel_temporaria + ", " + (yyvsp[0]).label + ");";
            }
#line 3149 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1339 "src/sintatica.y" /* yacc.c:1646  */
    {
                info_variavel var = buscaID((yyvsp[0]).label);
                (yyval).label = var.nome_temp;
                (yyval).traducao = "";
                (yyval).tipo = var.tipo;
                (yyval).tamanho = var.tamanho;
            }
#line 3161 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1347 "src/sintatica.y" /* yacc.c:1646  */
    {
                info_variavel var = pilha_variaveis[0][(yyvsp[0]).label];
                if(var.nome_temp == "")
                {
                	erro = true;
                	cout << "Erro na linha " << nlinha <<": Variável \"" << (yyvsp[0]).label << "\" não declarada." << endl << endl;
                }
                (yyval).label = var.nome_temp;
                (yyval).traducao = "";
                (yyval).tipo = var.tipo;
                (yyval).tamanho = var.tamanho;
            }
#line 3178 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1359 "src/sintatica.y" /* yacc.c:1646  */
    {
            	if(mapa_func[(yyvsp[-3]).label].nome_temp == "")
                {
                	erro = true;
                	cout << "Erro na linha " << nlinha <<": Função \"" << (yyvsp[-3]).label << "\" não declarada." << endl << endl;
                }

                int i;
                if(mapa_func[(yyvsp[-3]).label].parametros.size() == argumentos.size())
                {
                	for(i = 0; i < argumentos.size(); i++)
                	{
                		if(mapa_func[(yyvsp[-3]).label].parametros[i] != argumentos[i])
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

                info_func var = mapa_func[(yyvsp[-3]).label];
                (yyval).label = var.nome_temp + "(" + (yyvsp[-1]).traducao + ")";
                (yyval).traducao = (yyvsp[-1]).label;// + "\n\t" + var.nome_temp + "(" + $3.traducao + ")---;\n";
                (yyval).tipo = var.tipo;
                //$$.tamanho = var.tamanho;
            }
#line 3216 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1393 "src/sintatica.y" /* yacc.c:1646  */
    {
            	string var_temp = gera_variavel_temporaria("int");
            	info_variavel var = buscaID((yyvsp[-1]).label);
            	var.acesso_lista = geraLabel();
            	alteraID((yyvsp[-1]).label, var);

            	string acesso_lista = "\n\tnode *" + buscaID((yyvsp[-1]).label).acesso_lista + ";\n\t" + buscaID((yyvsp[-1]).label).acesso_lista + " = (node *) malloc(sizeof(node));\n\tinicia(" + buscaID((yyvsp[-1]).label).acesso_lista + ");\n\tif(!" + buscaID((yyvsp[-1]).label).acesso_lista + ") cout << \"Sem memoria disponivel!\\n\";";
            	for (int i = 0; i < vet_temp.size(); ++i)
            	{
            		acesso_lista += "\n\tinsereFim(" + buscaID((yyvsp[-1]).label).acesso_lista + ", " + vet_temp[i] + ");";
            	}
            	vet_temp.clear();

            	(yyval).traducao = (yyvsp[0]).traducao + "\n\t" + acesso_lista + "\n\t" + var_temp + " = mapper(" + buscaID((yyvsp[-1]).label).acesso_lista + ", " + buscaID((yyvsp[-1]).label).nome_lista + ");\n\t";// + buscaID($1.label).nome_temp + "[" + var_temp +  "] = " + $4.label + ";\n";

            	(yyval).tipo = var.tipo;
            	if(var.tipo == "string")
            		(yyval).label = buscaID((yyvsp[-1]).label).nome_temp + "[" + var_temp +  "].c";
            	else
            		(yyval).label = buscaID((yyvsp[-1]).label).nome_temp + "[" + var_temp +  "]";
            	(yyval).tamanho = var.tamanho;
            }
#line 3243 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1417 "src/sintatica.y" /* yacc.c:1646  */
    {
				argumentos.push_back((yyvsp[0]).tipo);
				(yyval).label = (yyvsp[-2]).label + (yyvsp[0]).traducao;
				(yyval).traducao = (yyvsp[-2]).traducao + ", " + (yyvsp[0]).label;
			}
#line 3253 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1423 "src/sintatica.y" /* yacc.c:1646  */
    {
				argumentos.push_back((yyvsp[0]).tipo);
				(yyval).label = (yyvsp[0]).traducao;
				(yyval).traducao = (yyvsp[0]).label;
				(yyval).tipo = (yyvsp[0]).tipo;
			}
#line 3264 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1429 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = "";
				(yyval).traducao = "";
			}
#line 3273 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1435 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
                (yyval).tipo = "float";
            }
#line 3283 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1441 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
                (yyval).tipo = "int";
            }
#line 3293 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1447 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
                (yyval).tipo = "char";
            }
#line 3303 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1453 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
                (yyval).tipo = "boolean";
            }
#line 3313 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1461 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
            }
#line 3322 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1466 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
            }
#line 3331 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1471 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
            }
#line 3340 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1476 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
            }
#line 3349 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1481 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
            }
#line 3358 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1486 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
            }
#line 3367 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1493 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
            }
#line 3376 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1498 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
            }
#line 3385 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1504 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
            }
#line 3394 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1509 "src/sintatica.y" /* yacc.c:1646  */
    {
                (yyval).traducao = (yyvsp[0]).traducao;
                (yyval).label = (yyvsp[0]).label;
            }
#line 3403 "bin/y.tab.c" /* yacc.c:1646  */
    break;


#line 3407 "bin/y.tab.c" /* yacc.c:1646  */
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
#line 1515 "src/sintatica.y" /* yacc.c:1906  */


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
