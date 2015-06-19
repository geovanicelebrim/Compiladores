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


#line 134 "bin/y.tab.c" /* yacc.c:339  */

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
    TK_MAIN = 262,
    TK_ID = 263,
    TK_TIPO_INT = 264,
    TK_TIPO_STRING = 265,
    TK_CONST = 266,
    TK_TYPE = 267,
    TK_ENDTYPE = 268,
    TK_VAR = 269,
    TK_ENDVAR = 270,
    TK_PROCEDURE = 271,
    TK_FUNCTION = 272,
    TK_ATR = 273,
    TK_SOMA = 274,
    TK_SUB = 275,
    TK_MUL = 276,
    TK_DIV = 277,
    TK_BEGIN = 278,
    TK_END = 279,
    TK_FIM = 280,
    TK_ERROR = 281,
    TK_NOT = 282,
    TK_PLUSPLUS = 283,
    TK_SUBSUB = 284,
    TK_TIPO_FLOAT = 285,
    TK_TIPO_CHAR = 286,
    TK_TIPO_BOOL = 287,
    TK_LOGICO = 288,
    TK_AND = 289,
    TK_OR = 290,
    TK_MENOR = 291,
    TK_MAIOR = 292,
    TK_MENOR_IGUAL = 293,
    TK_MAIOR_IGUAL = 294,
    TK_IGUAL = 295,
    TK_DIFERENTE = 296
  };
#endif
/* Tokens.  */
#define TK_NUM 258
#define TK_REAL 259
#define TK_CHAR 260
#define TK_STRING 261
#define TK_MAIN 262
#define TK_ID 263
#define TK_TIPO_INT 264
#define TK_TIPO_STRING 265
#define TK_CONST 266
#define TK_TYPE 267
#define TK_ENDTYPE 268
#define TK_VAR 269
#define TK_ENDVAR 270
#define TK_PROCEDURE 271
#define TK_FUNCTION 272
#define TK_ATR 273
#define TK_SOMA 274
#define TK_SUB 275
#define TK_MUL 276
#define TK_DIV 277
#define TK_BEGIN 278
#define TK_END 279
#define TK_FIM 280
#define TK_ERROR 281
#define TK_NOT 282
#define TK_PLUSPLUS 283
#define TK_SUBSUB 284
#define TK_TIPO_FLOAT 285
#define TK_TIPO_CHAR 286
#define TK_TIPO_BOOL 287
#define TK_LOGICO 288
#define TK_AND 289
#define TK_OR 290
#define TK_MENOR 291
#define TK_MAIOR 292
#define TK_MENOR_IGUAL 293
#define TK_MAIOR_IGUAL 294
#define TK_IGUAL 295
#define TK_DIFERENTE 296

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

#line 267 "bin/y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   99

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  89

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

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
      42,    43,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   106,   106,   127,   141,   145,   151,   165,   172,   192,
     196,   203,   216,   223,   236,   247,   260,   267,   279,   287,
     306,   315,   323,   332,   340,   351,   362,   371,   417,   431,
     453,   463,   469,   475,   481,   487,   495,   513,   519,   528,
     535,   542,   558,   564,   570,   576,   585,   590,   595,   600,
     605,   610,   617,   622,   628,   633
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_NUM", "TK_REAL", "TK_CHAR",
  "TK_STRING", "TK_MAIN", "TK_ID", "TK_TIPO_INT", "TK_TIPO_STRING",
  "TK_CONST", "TK_TYPE", "TK_ENDTYPE", "TK_VAR", "TK_ENDVAR",
  "TK_PROCEDURE", "TK_FUNCTION", "TK_ATR", "TK_SOMA", "TK_SUB", "TK_MUL",
  "TK_DIV", "TK_BEGIN", "TK_END", "TK_FIM", "TK_ERROR", "TK_NOT",
  "TK_PLUSPLUS", "TK_SUBSUB", "TK_TIPO_FLOAT", "TK_TIPO_CHAR",
  "TK_TIPO_BOOL", "TK_LOGICO", "TK_AND", "TK_OR", "TK_MENOR", "TK_MAIOR",
  "TK_MENOR_IGUAL", "TK_MAIOR_IGUAL", "TK_IGUAL", "TK_DIFERENTE", "'('",
  "')'", "';'", "$accept", "S", "BLOCO_NO_B", "COMANDOS", "COMANDO",
  "ATRIBUICAO", "DECLARACAO", "E_OR", "E_AND", "E_REL", "E", "E_TEMP",
  "UNAL", "VAL", "E_CAST", "TK_REL_OP", "TK_ARIT_OP_S", "TK_ARIT_OP_M", YY_NULLPTR
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
     295,   296,    40,    41,    59
};
# endif

#define YYPACT_NINF -32

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-32)))

#define YYTABLE_NINF -11

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -2,    18,    44,    -8,   -32,     6,    39,    28,   -32,    45,
      59,    60,    61,    68,    69,    54,    38,   -32,   -32,    19,
      62,    63,    65,    66,    67,   -32,    28,   -32,   -32,    42,
     -32,     8,     8,     8,     8,   -32,     1,    52,    55,   -32,
      34,    -7,   -32,   -32,    37,    82,    37,    85,    37,   -32,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -17,
      48,    37,    37,   -32,   -32,   -32,   -32,   -32,   -32,   -32,
     -32,    37,    37,   -32,   -32,    37,   -32,   -32,   -32,   -32,
      52,   -32,     8,    55,   -32,    36,    -7,   -32,   -32
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     5,     2,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     6,     0,
      12,    20,    14,    18,    16,     3,     5,    38,    39,    40,
      41,     0,     0,     0,     0,     9,     0,     8,    22,    24,
      26,    28,    30,    35,     0,     0,     0,     0,     0,     4,
      40,    31,    32,    33,    34,    43,    42,    44,    45,     0,
       0,     0,     0,    52,    53,    46,    47,    48,    49,    50,
      51,     0,     0,    54,    55,     0,    11,    19,    13,    17,
      15,    37,     0,    21,    23,    25,    27,    29,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -32,   -32,   -32,    70,   -32,   -32,   -32,   -28,    31,   -27,
      22,    23,    24,   -31,   -32,   -32,   -32,   -32
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     8,    15,    16,    17,    18,    37,    38,    39,
      40,    41,    42,    43,    60,    71,    72,    75
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      51,    52,    53,    54,    27,    28,    50,     1,    59,    30,
      55,    27,    28,    50,    73,    74,    30,    76,    61,    78,
      80,    31,    27,    28,    29,     3,    81,    30,    32,    33,
      34,    56,    57,    58,     5,    84,     9,    10,    11,    31,
      27,    28,    50,    36,     4,    30,    32,    33,    34,     6,
      36,    88,    35,    63,    64,    63,    64,    31,    12,    13,
      14,    36,     7,    19,    32,    33,    34,    20,    21,    22,
      65,    66,    67,    68,    69,    70,    23,    24,    25,    36,
      44,    45,    26,    46,    47,    48,   -10,    61,    77,    62,
      79,    82,    83,    85,     0,    86,    49,     0,     0,    87
};

static const yytype_int8 yycheck[] =
{
      31,    32,    33,    34,     3,     4,     5,     9,    36,     8,
       9,     3,     4,     5,    21,    22,     8,    44,    35,    46,
      48,    20,     3,     4,     5,     7,    43,     8,    27,    28,
      29,    30,    31,    32,    42,    62,     8,     9,    10,    20,
       3,     4,     5,    42,     0,     8,    27,    28,    29,    43,
      42,    82,    33,    19,    20,    19,    20,    20,    30,    31,
      32,    42,    23,    18,    27,    28,    29,     8,     8,     8,
      36,    37,    38,    39,    40,    41,     8,     8,    24,    42,
      18,    18,    44,    18,    18,    18,    44,    35,     6,    34,
       5,    43,    61,    71,    -1,    72,    26,    -1,    -1,    75
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    46,     7,     0,    42,    43,    23,    47,     8,
       9,    10,    30,    31,    32,    48,    49,    50,    51,    18,
       8,     8,     8,     8,     8,    24,    44,     3,     4,     5,
       8,    20,    27,    28,    29,    33,    42,    52,    53,    54,
      55,    56,    57,    58,    18,    18,    18,    18,    18,    48,
       5,    58,    58,    58,    58,     9,    30,    31,    32,    52,
      59,    35,    34,    19,    20,    36,    37,    38,    39,    40,
      41,    60,    61,    21,    22,    62,    54,     6,    54,     5,
      52,    43,    43,    53,    54,    55,    56,    57,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    48,    48,    49,    49,    50,    50,
      50,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    52,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    57,    57,    57,    57,    57,    58,    58,    58,    58,
      58,    58,    59,    59,    59,    59,    60,    60,    60,    60,
      60,    60,    61,    61,    62,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     3,     0,     1,     1,     3,     3,
       3,     4,     2,     4,     2,     4,     2,     4,     2,     4,
       2,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     2,     2,     2,     2,     1,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
#line 107 "src/sintatica.y" /* yacc.c:1646  */
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
					cout << cabecalho.str() << "\nint main(void)\n" << (yyvsp[0]).traducao << "\n\n\t" << endl; 
				} 
				//myfile.close();
			}
#line 1425 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 128 "src/sintatica.y" /* yacc.c:1646  */
    {
				string variaveis = "";

				for (std::map<string, info_variavel>::iterator it=mapa_variavel.begin(); it!=mapa_variavel.end(); ++it)
    				if(it->second.tipo == "boolean")
    					variaveis += "\tint " + it->second.nome_temp + ";\n";
    				else if(it->second.tipo != "string")
    					variaveis += "\t" + it->second.tipo + " " + it->second.nome_temp + ";\n";

				(yyval).traducao = (yyvsp[-2]).traducao + variaveis + (yyvsp[-1]).traducao + (yyvsp[0]).traducao;
			}
#line 1441 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 141 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao;
			}
#line 1449 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 145 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "";
				(yyval).label = "";
			}
#line 1458 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 152 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 1467 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 166 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 1476 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 173 "src/sintatica.y" /* yacc.c:1646  */
    {

				string tipo = mapa_variavel[(yyvsp[-2]).label].tipo;

				if(mapa_operacoes[tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 1)
					(yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + mapa_variavel[(yyvsp[-2]).label].nome_temp + " = " + "(" + mapa_operacoes[tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo + ")" + (yyvsp[0]).label + ";\n";
				else if(mapa_operacoes[tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 0)
					(yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + mapa_variavel[(yyvsp[-2]).label].nome_temp + " = " + (yyvsp[0]).label + ";\n";
				else{
					erro = true;
					cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
				}

				if((yyvsp[0]).tipo == "null" || (yyvsp[0]).tipo == "")
				{
					erro = true;
					cout << "Erro na linha: " << nlinha << ". Atribuição inválida!\n";
				}
			}
#line 1500 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 193 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = "\n\t" + mapa_variavel[(yyvsp[-2]).label].nome_temp + " = " + (yyvsp[0]).traducao + ";\n";
			}
#line 1508 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 197 "src/sintatica.y" /* yacc.c:1646  */
    {
				
				(yyval).traducao = "\n\t" + mapa_variavel[(yyvsp[-2]).label].nome_temp + " = " + (yyvsp[0]).label + ";\n";
			}
#line 1517 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 204 "src/sintatica.y" /* yacc.c:1646  */
    {
				info_variavel atributos = { (yyvsp[-3]).label, gera_variavel_temporaria((yyvsp[-3]).label, (yyvsp[-2]).label) };

				if(mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 1)
					(yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + atributos.nome_temp + " = " + "(" + mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo + ")" + (yyvsp[0]).label + ";";
				else if(mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 0)
					(yyval).traducao = "\t" + (yyvsp[0]).traducao + "\n\t" + atributos.nome_temp + " = " + (yyvsp[0]).label + ";";
				else{
					erro = true;
				}
				
			}
#line 1534 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 217 "src/sintatica.y" /* yacc.c:1646  */
    {
				info_variavel atributos = { (yyvsp[-1]).label, gera_variavel_temporaria((yyvsp[-1]).label, (yyvsp[0]).label)};

				(yyval).traducao = "\n\t" + atributos.nome_temp + " = " + "0" + ";";

			}
#line 1545 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 224 "src/sintatica.y" /* yacc.c:1646  */
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
#line 1562 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 237 "src/sintatica.y" /* yacc.c:1646  */
    {
				info_variavel atributos = { (yyvsp[-1]).label, gera_variavel_temporaria((yyvsp[-1]).label, (yyvsp[0]).label) };


				(yyval).traducao = "\n\t" + atributos.nome_temp + " = " + "0.0" + ";";
				//$$.tipo = mapa_variavel[$2.label].tipo;

				//$$.tipo = $2.tipo;

			}
#line 1577 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 248 "src/sintatica.y" /* yacc.c:1646  */
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
#line 1594 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 261 "src/sintatica.y" /* yacc.c:1646  */
    {
				info_variavel atributos = { (yyvsp[-1]).label, gera_variavel_temporaria((yyvsp[-1]).label, (yyvsp[0]).label) };

				(yyval).traducao = "\n\t" + atributos.nome_temp + " = " + "1" + ";";

			}
#line 1605 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 268 "src/sintatica.y" /* yacc.c:1646  */
    {
				info_variavel atributos = { (yyvsp[-3]).label, gera_variavel_temporaria((yyvsp[-3]).label, (yyvsp[-2]).label) };
				
				if(mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 1)
					(yyval).traducao = "\n\t" + atributos.nome_temp + " = " + "(" + mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo + ")" + (yyvsp[0]).label + ";";
				else if(mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 0)
					(yyval).traducao = "\n\t" + atributos.nome_temp + " = " + (yyvsp[0]).label + ";";
				else{
					erro = true;
				}
			}
#line 1621 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 280 "src/sintatica.y" /* yacc.c:1646  */
    {
				info_variavel atributos = { (yyvsp[-1]).label, gera_variavel_temporaria((yyvsp[-1]).label, (yyvsp[0]).label)};

				(yyval).traducao = "\n\t" + atributos.nome_temp + " = " + "\'\'" + ";";
			}
#line 1631 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 288 "src/sintatica.y" /* yacc.c:1646  */
    {
				info_variavel atributos = { (yyvsp[-3]).label, gera_variavel_temporaria((yyvsp[-3]).label, (yyvsp[-2]).label) };
				
				if(mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 1)
					(yyval).traducao = "\n\t" + atributos.nome_temp + " = " + "(" + mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo + ")" + (yyvsp[0]).label + ";";
				else if(mapa_operacoes[(yyvsp[-3]).label+(yyvsp[-1]).label+(yyvsp[0]).tipo].operando == 0)
				{
					stringstream tamanho;
					tamanho << (yyvsp[0]).label.size() - 2;
					
					(yyval).traducao = "\n\t" + (yyvsp[-3]).label + " " + atributos.nome_temp + "[" + tamanho.str() + "];\n";
					(yyval).traducao += "\tstrcpy(" + atributos.nome_temp + ", " + (yyvsp[0]).label + ");\n";
				}
				else{
					erro = true;
				}

			}
#line 1654 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 307 "src/sintatica.y" /* yacc.c:1646  */
    {
				info_variavel atributos = { (yyvsp[-1]).label, gera_variavel_temporaria((yyvsp[-1]).label, (yyvsp[0]).label)};

				(yyval).traducao = "\n\t" + (yyvsp[-1]).label + " " + atributos.nome_temp + "[1];\n";
				(yyval).traducao += "\tstrcpy(" + atributos.nome_temp + ", \"\");\n";
			}
#line 1665 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 316 "src/sintatica.y" /* yacc.c:1646  */
    {
			
				string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo);
				(yyval).label = nome_variavel_temporaria;
				(yyval).tipo = mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo;
				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\n\t" + (yyval).label + " = " +(yyvsp[-2]).label + " " + (yyvsp[-1]).traducao + " " + (yyvsp[0]).label + ";\n";
			}
#line 1677 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 324 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).tipo = (yyvsp[0]).tipo;
				(yyval).tamanho = (yyvsp[0]).tamanho;
			}
#line 1688 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 333 "src/sintatica.y" /* yacc.c:1646  */
    {
				string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo);
				(yyval).label = nome_variavel_temporaria;
				(yyval).tipo = mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo;

				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\n\t" + (yyval).label + " = " +(yyvsp[-2]).label + " " + (yyvsp[-1]).traducao + " " + (yyvsp[0]).label + ";\n";
			}
#line 1700 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 341 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).tipo = (yyvsp[0]).tipo;
				(yyval).tamanho = (yyvsp[0]).tamanho;
			}
#line 1711 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 352 "src/sintatica.y" /* yacc.c:1646  */
    {

				string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo);
				(yyval).label = nome_variavel_temporaria;

				(yyval).tipo = mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo;

				(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + "\n\t" + (yyval).label + " = " +(yyvsp[-2]).label + " " + (yyvsp[-1]).label + " " + (yyvsp[0]).label + ";\n";
				
			}
#line 1726 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 363 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).tipo = (yyvsp[0]).tipo;
				(yyval).tamanho = (yyvsp[0]).tamanho;
			}
#line 1737 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 372 "src/sintatica.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2]).tipo == "string" && (yyvsp[0]).tipo == "string")	
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
					(yyval).tipo = mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo;
				}
			}
#line 1787 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 418 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).tipo = (yyvsp[0]).tipo;
				/*
				string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[$1.tipo].tipo);
				$$.label = nome_variavel_temporaria;
				$$.tipo = mapa_operacoes[$1.tipo].tipo;
				$$.traducao = $1.traducao + "\n\t" + nome_variavel_temporaria + " = " + $1.label+ ";";
				*/
			}
#line 1803 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 432 "src/sintatica.y" /* yacc.c:1646  */
    {
				string nome_variavel_temporaria = gera_variavel_temporaria(mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo);

				(yyval).label = nome_variavel_temporaria;

				cout << nome_variavel_temporaria << endl;

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
				
				(yyval).tipo = mapa_operacoes[(yyvsp[-2]).tipo+(yyvsp[-1]).label+(yyvsp[0]).tipo].tipo;
			}
#line 1829 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 454 "src/sintatica.y" /* yacc.c:1646  */
    {
				
				(yyval).label = (yyvsp[0]).label;
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).tipo = (yyvsp[0]).tipo;
				
			}
#line 1841 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 464 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[-1]).label + (yyvsp[0]).label;
				(yyval).tipo = (yyvsp[0]).tipo;
				(yyval).traducao = "";
			}
#line 1851 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 470 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[-1]).label + (yyvsp[0]).label;
				(yyval).tipo = (yyvsp[0]).tipo;
				(yyval).traducao = "";
			}
#line 1861 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 476 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[-1]).label + (yyvsp[0]).label;
				(yyval).tipo = (yyvsp[0]).tipo;
				(yyval).traducao = "";
			}
#line 1871 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 482 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[-1]).label + (yyvsp[0]).label;
				(yyval).tipo = (yyvsp[0]).tipo;
				(yyval).traducao = "";
			}
#line 1881 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 488 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[0]).label;
				(yyval).tipo = (yyvsp[0]).tipo;
				(yyval).traducao = (yyvsp[0]).traducao;
			}
#line 1891 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 496 "src/sintatica.y" /* yacc.c:1646  */
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
#line 1913 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 514 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).label = (yyvsp[-1]).label;
				(yyval).traducao = (yyvsp[-1]).traducao;
				(yyval).tipo = (yyvsp[-1]).tipo;
			}
#line 1923 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 520 "src/sintatica.y" /* yacc.c:1646  */
    {
				
				string nome_variavel_temporaria = gera_variavel_temporaria((yyvsp[0]).tipo);
				(yyval).label = nome_variavel_temporaria;
				(yyval).tipo = (yyvsp[0]).tipo;
				(yyval).traducao ="\n\t" + nome_variavel_temporaria + " = " + (yyvsp[0]).label + ";";
				
			}
#line 1936 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 529 "src/sintatica.y" /* yacc.c:1646  */
    {
				string nome_variavel_temporaria = gera_variavel_temporaria((yyvsp[0]).tipo);
				(yyval).label = nome_variavel_temporaria;
				(yyval).tipo = (yyvsp[0]).tipo;
				(yyval).traducao ="\n\t" + nome_variavel_temporaria + " = " + (yyvsp[0]).label + ";";
			}
#line 1947 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 536 "src/sintatica.y" /* yacc.c:1646  */
    {	
				string nome_variavel_temporaria = gera_variavel_temporaria((yyvsp[0]).tipo);
				(yyval).label = nome_variavel_temporaria;
				(yyval).tipo = (yyvsp[0]).tipo;
				(yyval).traducao ="\n\t" + nome_variavel_temporaria + " = " + (yyvsp[0]).label + ";";
			}
#line 1958 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 543 "src/sintatica.y" /* yacc.c:1646  */
    {
				if(mapa_variavel.find((yyvsp[0]).label) == mapa_variavel.end()) {
					cout << "Erro na linha " << nlinha <<": Variável \"" << (yyvsp[0]).label << "\" não declarada." << endl << endl;

					erro = true;
				}

				(yyval).label = mapa_variavel[(yyvsp[0]).label].nome_temp;
				(yyval).traducao = "";
				(yyval).tipo = mapa_variavel[(yyvsp[0]).label].tipo;
				
			}
#line 1975 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 559 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).label = (yyvsp[0]).label;
				(yyval).tipo = "float";
			}
#line 1985 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 565 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).label = (yyvsp[0]).label;
				(yyval).tipo = "int";
			}
#line 1995 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 571 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).label = (yyvsp[0]).label;
				(yyval).tipo = "char";
			}
#line 2005 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 577 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).label = (yyvsp[0]).label;
				(yyval).tipo = "boolean";
			}
#line 2015 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 586 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).label = (yyvsp[0]).label;
			}
#line 2024 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 591 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).label = (yyvsp[0]).label;
			}
#line 2033 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 596 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).label = (yyvsp[0]).label;
			}
#line 2042 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 601 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).label = (yyvsp[0]).label;
			}
#line 2051 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 606 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).label = (yyvsp[0]).label;
			}
#line 2060 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 611 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).label = (yyvsp[0]).label;
			}
#line 2069 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 618 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).label = (yyvsp[0]).label;
			}
#line 2078 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 623 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).label = (yyvsp[0]).label;
			}
#line 2087 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 629 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).label = (yyvsp[0]).label;
			}
#line 2096 "bin/y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 634 "src/sintatica.y" /* yacc.c:1646  */
    {
				(yyval).traducao = (yyvsp[0]).traducao;
				(yyval).label = (yyvsp[0]).label;
			}
#line 2105 "bin/y.tab.c" /* yacc.c:1646  */
    break;


#line 2109 "bin/y.tab.c" /* yacc.c:1646  */
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
#line 641 "src/sintatica.y" /* yacc.c:1906  */


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
