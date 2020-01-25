/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    START = 258,
    END = 259,
    DECL = 260,
    ENDDECL = 261,
    INT = 262,
    STR = 263,
    NUM = 264,
    ASSIGN = 265,
    READ = 266,
    WRITE = 267,
    ID = 268,
    PLUS = 269,
    MINUS = 270,
    MUL = 271,
    DIV = 272,
    IF = 273,
    THEN = 274,
    ELSE = 275,
    ENDIF = 276,
    LT = 277,
    GT = 278,
    EQ = 279,
    NEQ = 280,
    GTE = 281,
    LTE = 282,
    DO = 283,
    WHILE = 284,
    ENDWHILE = 285,
    BREAK = 286,
    CONTINUE = 287,
    REPEAT = 288,
    UNTIL = 289,
    STRING = 290
  };
#endif
/* Tokens.  */
#define START 258
#define END 259
#define DECL 260
#define ENDDECL 261
#define INT 262
#define STR 263
#define NUM 264
#define ASSIGN 265
#define READ 266
#define WRITE 267
#define ID 268
#define PLUS 269
#define MINUS 270
#define MUL 271
#define DIV 272
#define IF 273
#define THEN 274
#define ELSE 275
#define ENDIF 276
#define LT 277
#define GT 278
#define EQ 279
#define NEQ 280
#define GTE 281
#define LTE 282
#define DO 283
#define WHILE 284
#define ENDWHILE 285
#define BREAK 286
#define CONTINUE 287
#define REPEAT 288
#define UNTIL 289
#define STRING 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "task1.y" /* yacc.c:1909  */

    struct tnode* node;

#line 128 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
