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
    MOD = 273,
    IF = 274,
    THEN = 275,
    ELSE = 276,
    ENDIF = 277,
    LT = 278,
    GT = 279,
    EQ = 280,
    NEQ = 281,
    GTE = 282,
    LTE = 283,
    DO = 284,
    WHILE = 285,
    ENDWHILE = 286,
    BREAK = 287,
    CONTINUE = 288,
    REPEAT = 289,
    UNTIL = 290,
    STRING = 291
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
#define MOD 273
#define IF 274
#define THEN 275
#define ELSE 276
#define ENDIF 277
#define LT 278
#define GT 279
#define EQ 280
#define NEQ 281
#define GTE 282
#define LTE 283
#define DO 284
#define WHILE 285
#define ENDWHILE 286
#define BREAK 287
#define CONTINUE 288
#define REPEAT 289
#define UNTIL 290
#define STRING 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "task1.y" /* yacc.c:1909  */

    struct tnode* node;

#line 130 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
