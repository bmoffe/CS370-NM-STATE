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
    STRING = 258,
    NUM = 259,
    INT = 260,
    VOID = 261,
    BOOLEAN = 262,
    IF = 263,
    ELSE = 264,
    THEN = 265,
    WHILE = 266,
    DO = 267,
    READ = 268,
    WRITE = 269,
    MYRETURN = 270,
    LE = 271,
    GE = 272,
    LT = 273,
    GT = 274,
    EQ = 275,
    NE = 276,
    ID = 277,
    TRUE = 278,
    FALSE = 279,
    AND = 280,
    OR = 281,
    MYBEGIN = 282,
    END = 283,
    NOT = 284
  };
#endif
/* Tokens.  */
#define STRING 258
#define NUM 259
#define INT 260
#define VOID 261
#define BOOLEAN 262
#define IF 263
#define ELSE 264
#define THEN 265
#define WHILE 266
#define DO 267
#define READ 268
#define WRITE 269
#define MYRETURN 270
#define LE 271
#define GE 272
#define LT 273
#define GT 274
#define EQ 275
#define NE 276
#define ID 277
#define TRUE 278
#define FALSE 279
#define AND 280
#define OR 281
#define MYBEGIN 282
#define END 283
#define NOT 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 80 "lab9.y"

	int val;
	char * str;
	char * label;
        ASTnode * node;
	enum OPERATORS operator;

#line 123 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
