/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
