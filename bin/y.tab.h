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
    TK_ID = 262,
    TK_MAIN = 263,
    TK_BEGIN = 264,
    TK_END = 265,
    TK_ATR = 266,
    TK_SOMA = 267,
    TK_SUB = 268,
    TK_MUL = 269,
    TK_DIV = 270,
    TK_LOGICO = 271,
    TK_AND = 272,
    TK_OR = 273,
    TK_MENOR = 274,
    TK_MAIOR = 275,
    TK_MENOR_IGUAL = 276,
    TK_MAIOR_IGUAL = 277,
    TK_IGUAL = 278,
    TK_DIFERENTE = 279,
    TK_NOT = 280,
    TK_PLUSPLUS = 281,
    TK_SUBSUB = 282,
    TK_TIPO_INT = 283,
    TK_TIPO_STRING = 284,
    TK_TIPO_FLOAT = 285,
    TK_TIPO_CHAR = 286,
    TK_TIPO_BOOL = 287,
    TK_CONST = 288,
    TK_FUNCTION = 289,
    TK_WHILE = 290,
    TK_FOR = 291,
    TK_DO = 292,
    TK_WRITE = 293,
    TK_READ = 294
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
#define TK_ATR 266
#define TK_SOMA 267
#define TK_SUB 268
#define TK_MUL 269
#define TK_DIV 270
#define TK_LOGICO 271
#define TK_AND 272
#define TK_OR 273
#define TK_MENOR 274
#define TK_MAIOR 275
#define TK_MENOR_IGUAL 276
#define TK_MAIOR_IGUAL 277
#define TK_IGUAL 278
#define TK_DIFERENTE 279
#define TK_NOT 280
#define TK_PLUSPLUS 281
#define TK_SUBSUB 282
#define TK_TIPO_INT 283
#define TK_TIPO_STRING 284
#define TK_TIPO_FLOAT 285
#define TK_TIPO_CHAR 286
#define TK_TIPO_BOOL 287
#define TK_CONST 288
#define TK_FUNCTION 289
#define TK_WHILE 290
#define TK_FOR 291
#define TK_DO 292
#define TK_WRITE 293
#define TK_READ 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BIN_Y_TAB_H_INCLUDED  */
