/* A Bison parser, made by GNU Bison 3.4.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    NUM = 258,
    INT = 259,
    VOID = 260,
    BOOLEAN = 261,
    IF = 262,
    ELSE = 263,
    THEN = 264,
    WHILE = 265,
    DO = 266,
    READ = 267,
    WRITE = 268,
    MYRETURN = 269,
    LE = 270,
    GE = 271,
    LT = 272,
    GT = 273,
    EQ = 274,
    NE = 275,
    ID = 276,
    TRUE = 277,
    FALSE = 278,
    AND = 279,
    OR = 280,
    MYBEGIN = 281,
    END = 282,
    NOT = 283
  };
#endif
/* Tokens.  */
#define NUM 258
#define INT 259
#define VOID 260
#define BOOLEAN 261
#define IF 262
#define ELSE 263
#define THEN 264
#define WHILE 265
#define DO 266
#define READ 267
#define WRITE 268
#define MYRETURN 269
#define LE 270
#define GE 271
#define LT 272
#define GT 273
#define EQ 274
#define NE 275
#define ID 276
#define TRUE 277
#define FALSE 278
#define AND 279
#define OR 280
#define MYBEGIN 281
#define END 282
#define NOT 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 67 "lab6.y"

	int val;
	char * str;
        ASTnode * node;
	enum OPERATORS operator;

#line 120 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
