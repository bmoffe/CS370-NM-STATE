%{

/*
 *			**** CALC ****
 *
 * This routine will function like a desk calculator
 * There are 26 integer registers, named 'a' thru 'z'
 *
 */

/* This calculator depends on a LEX description which outputs either VARIABLE or INTEGER.
   The return type via yylval is integer 

   When we need to make yylval more complicated, we need to define a pointer type for yylval 
   and to instruct YACC to use a new type so that we can pass back better values
 
   The registers are based on 0, so we substract 'a' from each single letter we get.

   based on context, we have YACC do the correct memmory look up or the storage depending
   on position

   Shaun Cooper
    January 2015

   Modified by: Brianna Moffett
   Changes made:
   	-fixed unary minus by removing first expr token from original statement (was "expr - expr",
         is now " - expr")
	-fixed parenthesis by including both open and close parenthesis characters in lex file rule
	-fixed multiplication by adding a new rule to y file: when the program finds a '*' token, it
         performs the multiplication arithmetic
   problems  fix unary minus, fix parenthesis, add multiplication
   problems  make it so that verbose is on and off with an input argument instead of compiled in
*/


	/* begin specs */
#include <stdio.h>
#include <ctype.h>
int yylex(); /*prototype to get rid of warnings*/
#include "symtabfuncs.h"
#define maxstack 26

extern int ln;
int regs[maxstack];
int base, debugsw;
int stackpointer = 0;

void yyerror (s)
  char * s;
  {  /* Called by yyparse on error */
     printf ("%s\n", s);
  }


%}
/*  defines the start symbol, what values come back from LEX and how the operators are associated  */

%start program

%union{
	int val;
	char * str;
}

%token<val> INTEGER
%token <str> VARIABLE
%token INT
%type <val> expr
/*%type expr stat*/

%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left UMINUS


%%	/* end specs, begin rules */
program : DECLS list
        ;

DECLS	:	/*empty*/
        |	DEC DECLS
        ;

DEC	:	INT VARIABLE{
    			if (Search($2))
			{
				fprintf(stderr, "Error found on line &d: symbol %s is already defined.\n", ln, $2);
			}
			else
			{
				if(stackpointer >= maxstack)
				{
					fprintf(stderr, "Error found on line %d: no more space left in the registers.\n", ln, $2);
				}
				else{
					Insert($2, stackpointer);
					stackpointer++;
					ln++;
				}
			}
		}//end variable
	';' '\n'

list	:	/* empty */
	|	list stat '\n'
	|	list error '\n'
			{ yyerrok; }
	;

stat	:	expr
			{ fprintf(stderr,"the anwser is %d\n", $1); }
	|	VARIABLE{
			if (Search($1)){
				fprintf(stderr, "Variable %s on line %d is defined.\n", $1, ln);
			}
			else{
				fprintf(stderr, "Variable %s on line %d is never defined.\n", $1, ln);
			}
	}'=' expr
			{ regs[fetchAddr($1)] = $4; }
	;

expr	:	'(' expr ')'
			{ $$ = $2; }
	|	expr '-' expr
			{ $$ = $1 - $3; }
	|	expr '+' expr
			{ $$ = $1 + $3; }
	|	expr '/' expr
			{ $$ = $1 / $3; }
	|	expr '%' expr
			{ $$ = $1 % $3; }
	|	expr '&' expr
			{ $$ = $1 & $3; }
	|	expr '|' expr
			{ $$ = $1 | $3; }
	|	expr '*' expr
			{ $$ = $1 * $3; }
	|	'-' expr	%prec UMINUS
			{ $$ = -$2; }
	|	VARIABLE
			{ if (Search($1)){
				$$ = regs[fetchAddr($1)];
			  }
			  else{
				fprintf(stderr, "Variable %s not found. Will default to 0.\n", $1);
				$$ = 0;
			  }
			}
	|	INTEGER {$$=$1; fprintf(stderr,"found an integer\n");}
	;



%%	/* end of rules, start of program */

int main()
{ yyparse();
}
