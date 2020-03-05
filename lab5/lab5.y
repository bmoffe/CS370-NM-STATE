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
	Changes made: (02.24.20)
	 -added symbol table implementation to calculator
	 -added rulesets for variables/IDs
	 -removed "#include lex.yy.c" from include statements
	 -included symbol table code in YACC file
	Changes made: (03.03.20)
	 -removed symbol table and calculator rules
	 -added rulesets for variables/IDs
	 -added CFG rules for Algol-C language definition
*/


	/* begin specs */
#include <stdio.h>
#include <ctype.h>
int yylex(); /*prototype to get rid of warnings*/

extern int mydebug;
extern int ln;

void yyerror (s)
  char * s;
  {  /* Called by yyparse on error */
     printf ("%s on line number %d\n", s, ln);
  }


%}
/*  defines the start symbol, what values come back from LEX and how the operators are associated  */

%start program

%union{
	int val;
	char * str;
}

%token <val> NUM
%token <str> ID
%token INT VOID BOOLEAN TRUE FALSE IF THEN ELSE DO WHILE MYRETURN READ WRITE LT LE GT GE EQ NE NOT AND OR MYBEGIN END



%%	/* end specs, begin rules */
program : declist /*program → declaration-list*/
        ;
        
declist : dec /*declaration-list → declaration { declaration }*/
        | dec declist
        ;
        
dec     : vardec /*declaration → var-declaration | fun-declaration*/
        | fundec
        ;
        
vardec   : typespec varlist ';' /*vadec*/
         ;
         
varlist  : ID /*varlist*/
         | ID '[' NUM ']' {fprintf(stderr, "Const found %d\n", $3);}
         | ID ',' varlist
         | ID '[' NUM ']' ',' varlist {fprintf(stderr, "Const found %d\n", $3);}
         ;
         
typespec : INT /*type specifier*/
         | VOID
         | BOOLEAN
         ;
         
fundec   : typespec ID '(' params ')' compoundstmt /*function declaration*/
         ;
         
params   : VOID /*parameters*/
         | paramlist
         ;

paramlist : param /*parameters list*/
          | param ',' paramlist
          ;
          
param     : typespec ID /*param*/
          | typespec ID '[' ']'
          ;
          
compoundstmt : MYBEGIN localdec statementlist END /*compound statement*/
             ;
             
localdec     : /*localdec*/ /*empty*/
             | vardec localdec
             ;
             
statementlist : /*statement list*/ /*empty*/
              | statement statementlist
              ;
              
statement     : expressionstmt /*statement*/
              | compoundstmt
              | selectionstmt
              | iterationstmt
              | assignmentstmt
              | returnstmt
              | readstmt
              | writestmt
              ;

expressionstmt : expression ';' /*expression statement*/
               | ';'
               ;
               
selectionstmt  : IF expression THEN statement /*selection statement*/
               | IF expression THEN statement ELSE statement
               ;
               
iterationstmt  : WHILE expression DO statement /*iteration statement*/
               ;
               
returnstmt     : MYRETURN ';' /*return statement*/
               | MYRETURN expression';'
               ;
               
readstmt       : READ variable ';' /*read statement*/
               ;

writestmt      : WRITE expression ';' /*write statement*/
               ;
               
assignmentstmt : variable '=' simpleexpression ';' /*assignment statement*/
               ;
               
expression     : simpleexpression /*expression*/
               ;
               
variable       : ID /*variable*/
               | ID '[' expression ']'
               ;
               
simpleexpression : additiveexpression /*simple expression*/
                 | simpleexpression relop additiveexpression
                 ;
                 
relop            : LE /*relational operators*/
                 | LT
                 | GT
                 | GE
                 | EQ
                 | NE
                 ;
                 
additiveexpression : term /*additive expression*/
                   | additiveexpression addop term
                   ;
                   
addop              : '+' /*addition operators*/
                   | '-'
                   ;
                   
term               : factor /*term*/
                   | term multop factor
                   ;
                   
multop             : '*' /*multiply operators*/
                   | '/'
                   | AND
                   | OR
                   ;
                
factor             : '(' expression ')' /*factor*/
                   | NUM {fprintf(stderr, "Const found %d\n", $1);}
                   | variable
                   | call
                   | TRUE
                   | FALSE
                   | NOT factor
                   ;
                   
call               : ID '(' args ')' /*function call*/
                   ;

args               : /*empty*/ /*arguments*/
                   | arglist
                   ;
                   
arglist            : expression /*arguments list*/
                   | expression ',' arglist
                   ;
%%	/* end of rules, start of program */

int main()
{ yyparse();
}
