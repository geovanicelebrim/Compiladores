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
    TK_MAIN = 260,
    TK_ID = 261,
    TK_TIPO_INT = 262,
    TK_CONST = 263,
    TK_TYPE = 264,
    TK_ENDTYPE = 265,
    TK_VAR = 266,
    TK_ENDVAR = 267,
    TK_PROCEDURE = 268,
    TK_FUNCTION = 269,
    TK_ATR = 270,
    TK_SOMA = 271,
    TK_SUB = 272,
    TK_MUL = 273,
    TK_DIV = 274,
    TK_BEGIN = 275,
    TK_END = 276,
    TK_FIM = 277,
    TK_ERROR = 278,
    TK_NOT = 279,
    TK_PLUSPLUS = 280,
    TK_TIPO_FLOAT = 281,
    TK_TIPO_CHAR = 282,
    TK_TIPO_BOOL = 283,
    TK_LOGICO = 284,
    TK_AND = 285,
    TK_OR = 286
  };
#endif
/* Tokens.  */
#define TK_NUM 258
#define TK_REAL 259
#define TK_MAIN 260
#define TK_ID 261
#define TK_TIPO_INT 262
#define TK_CONST 263
#define TK_TYPE 264
#define TK_ENDTYPE 265
#define TK_VAR 266
#define TK_ENDVAR 267
#define TK_PROCEDURE 268
#define TK_FUNCTION 269
#define TK_ATR 270
#define TK_SOMA 271
#define TK_SUB 272
#define TK_MUL 273
#define TK_DIV 274
#define TK_BEGIN 275
#define TK_END 276
#define TK_FIM 277
#define TK_ERROR 278
#define TK_NOT 279
#define TK_PLUSPLUS 280
#define TK_TIPO_FLOAT 281
#define TK_TIPO_CHAR 282
#define TK_TIPO_BOOL 283
#define TK_LOGICO 284
#define TK_AND 285
#define TK_OR 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BIN_Y_TAB_H_INCLUDED  */
