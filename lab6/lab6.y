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
#include "ast.h"
int yylex(); /*prototype to get rid of warnings*/

extern int mydebug;
extern int ln;
extern int level;
extern ASTnode *program;
enum OPERATORS mytype;
void yyerror (s)
  char * s;
  {  /* Called by yyparse on error */
     fprintf (stderr, "%s on line number %d\n", s, ln);
  }


%}
/*  defines the start symbol, what values come back from LEX and how the operators are associated  */

%start program

%union{
	int val;
	char * str;
        ASTnode * node;
	enum OPERATORS operator;
}

%token <val> NUM INT VOID BOOLEAN IF ELSE THEN WHILE DO READ WRITE MYRETURN LE GE LT GT EQ NE
%token <str> ID
%token TRUE FALSE AND OR MYBEGIN END NOT
%type <node> program declist dec vardec varlist fundec params paramlist param compoundstmt localdec statementlist statement expressionstmt selectionstmt iterationstmt assignmentstmt simpleexpression additiveexpression returnstmt readstmt writestmt expression variable args arglist call factor term
%type <operator> relop addop multop typespec

%%	/* end specs, begin rules */
program : declist {program = $1;} /*program → declaration-list*/
        ;
        
declist : dec {$$ = $1;}/*declaration-list → declaration { declaration }*/
        | dec declist {$$ = $1;
		       $1 -> next = $2;}
        ;
        
dec     : vardec {$$ = $1;}/*declaration → var-declaration | fun-declaration*/
        | fundec {$$ = $1;}
        ;
        
vardec   : typespec varlist ';' /*vardec*/ {$$ = $2;
					    ASTnode * p = $$;
				            while(p != NULL){
					      p -> operator = $1;
					      p = p -> s1;}}
	 ;
         
varlist  : ID /*vardec*/ {$$ = ASTcreatenode(VARDEC);
                          $$ -> name = $1;}
			   
         | ID '[' NUM ']'/* {fprintf(stderr, "Const found %d\n", $3);*/
			  	    {$$ = ASTcreatenode(VARDEC);
			  	     $$ -> name = $1;
			  	     $$ -> value = $3;}
         | ID ',' varlist {$$ = ASTcreatenode(VARDEC);
			   $$ -> name = $1;
			   $$ -> s1 = $3;}
         | ID '[' NUM ']' ',' varlist {$$ = ASTcreatenode(VARDEC);
				       $$ -> name = $1;
				       $$ -> value = $3;
				       $$ -> s1 = $6;} /*{fprintf(stderr, "Const found %d\n", $3);}*/
         ;
         
typespec : INT {$$ = INTTYPE;
	    }
         | VOID {$$ = VOIDTYPE;
		   }
         | BOOLEAN {$$ = BOOLTYPE;
		      }
         ;
         
fundec   : typespec ID '(' params ')' compoundstmt {$$ = ASTcreatenode(FUNDEC);
						    $$ -> operator = $1;
						    $$ -> name = $2;
						    $$ -> s1 = $4;
						    $$ -> s2 = $6;} /*function declaration*/
         ;
         
params   : VOID {$$ = NULL;} /*parameters*/
         | paramlist {$$ = $1;}
         ;

paramlist : param {$$ = $1;} /*parameters list*/
          | param ',' paramlist {$$ = $1;
				 $$ -> next = $3;}
          ;
          
param     : typespec ID {$$ = ASTcreatenode(PARAM);
	  		 $$ -> operator = $1;
			 $$ -> name = $2;}
          | typespec ID '[' NUM ']' {$$ = ASTcreatenode(PARAM);
				     $$ -> operator = $1;
				     $$ -> name = $2;
				     $$ -> value = $4;}
          ;
          
compoundstmt : MYBEGIN localdec statementlist END {$$ = ASTcreatenode(BLOCK);
							$$ -> s1 = $2;
							$$ -> s2 = $3;
						   }
             ;
             
localdec     : /*localdec*/ /*empty*/ {$$ = NULL;}
             | vardec localdec {$1 -> next = $2; $$ = $1;}
             ;
             
statementlist : /*statement list*/ /*empty*/ {$$ = NULL;}
              | statement statementlist {
						$1 -> next = $2;
						$$ = $1;
					}
              ;
              
statement     : expressionstmt {$$ = $1;}
              | compoundstmt {$$ = $1;}
              | selectionstmt {$$ = $1;}
              | iterationstmt {$$ = $1;}
              | assignmentstmt {$$ = $1;}
              | returnstmt {$$ = $1;}
              | readstmt {$$ = $1;}
              | writestmt {$$ = $1;}
              ;

expressionstmt : expression ';' {$$ = ASTcreatenode(EXPRSTMT);
	       			 $$ -> s1 = $1;}
               | ';' { $$ = ASTcreatenode(EXPRSTMT);
		      $$ -> s1 = NULL;}
               ;
               
selectionstmt  : IF expression THEN statement {$$ = ASTcreatenode(IFSTMT);
	   				       $$ -> s1 = $2;
					       $$ -> s2 = ASTcreatenode(IFELSE);
					       $$ -> s2 -> s1 = $4;}
               | IF expression THEN statement ELSE statement {$$ = ASTcreatenode(IFSTMT);
							      $$ -> s1 = $2;
							      $$ -> s2 = ASTcreatenode(IFELSE);
					 		      $$ -> s2 -> s1 = $4;
							      $$ -> s2 -> s2 = $6;}
               ;
               
iterationstmt  : WHILE expression DO statement {$$ = ASTcreatenode(WHILESTMT);
	       					$$ -> s1 = $2;
						$$ -> s2 = $4;}
               ;
               
returnstmt     : MYRETURN ';' {$$ = ASTcreatenode(RETURNSTMT);
	       		       $$ -> s1 = NULL;}
               | MYRETURN expression ';' {$$ = ASTcreatenode(RETURNSTMT);
					  $$ -> s1 = $2;}
               ;
               
readstmt       : READ variable ';' {$$ = ASTcreatenode(READSTMT);
	       			    $$ -> s1 = $2;}
               ;

writestmt      : WRITE expression ';' {$$ = ASTcreatenode(WRITESTMT);
	       			       $$ -> s1 = $2;}
               ;
               
assignmentstmt : variable '=' simpleexpression ';' {$$ = ASTcreatenode(ASSIGNSTMT);
	       					    $$ -> s1 = $1;
						    $$ -> s2 = $3;}
               ;
               
expression     : simpleexpression {$$= $1;}
               ;
               
variable       : ID {$$ = ASTcreatenode(IDENTIFIER);
	       	     $$ -> name = $1;
		     $$ -> s1 = NULL;}
               | ID '[' expression ']' {$$ = ASTcreatenode(IDENTIFIER);
					$$ -> name = $1;
					$$ -> s1 = $3;}
               ;
               
simpleexpression : additiveexpression {$$ = $1;}
                 | simpleexpression relop additiveexpression {$$ = ASTcreatenode(EXPR);
							      $$ -> s1 = $1;
							      $$ -> operator = $2;
							      $$ -> s2 = $3;}
                 ;
                 
relop            : LE {$$ = LESSTHANEQ;}
                 | LT {$$ = LESSTHAN;}
                 | GT {$$ = GREATERTHAN;}
                 | GE {$$ = GREATERTHANEQ;}
                 | EQ {$$ = EQUAL;}
                 | NE {$$ = NOTEQUAL;}
                 ;
                 
additiveexpression : term {$$ = $1;}
		   | additiveexpression addop term {$$ = ASTcreatenode(EXPR);
		   				    $$ -> s1 = $1;
						    $$ -> operator = $2;
						    $$ -> s2 = $3;}
                   ;
                   
addop              : '+' {$$ = PLUS;}
                   | '-' {$$ = MINUS;}
                   ;
                   
term               : factor {$$ = $1;}
                   | term multop factor {$$ = ASTcreatenode(EXPR);
					 $$ -> s1 = $1;
					 $$ -> operator = $2;
					 $$ -> s2 = $3;}
                   ;
                   
multop             : '*' {$$ = MULTI;}
                   | '/' {$$ = DIV;}
                   | AND {$$ = MYAND;}
                   | OR  {$$ = MYOR;}
                   ;
                
factor             : '(' expression ')' {$$ = $2;}
                   | NUM {$$ = ASTcreatenode(NUMBER);
			  $$ -> value = $1;}
                   | variable {$$ = $1;}
                   | call {$$ = $1;}
                   | TRUE {$$ = ASTcreatenode(NUMBER);
		           $$ -> value = 1;}
                   | FALSE {$$ = ASTcreatenode(NUMBER);
		            $$ -> value = 0;}
                   | NOT factor {$$ = ASTcreatenode(EXPR);
				 $$ -> operator = MYNOT;
				 $$ -> s1 = $2;}
                   ;
                   
call               : ID '(' args ')' {$$ = ASTcreatenode(CALL);
		   		      $$ -> name = $1;
				      $$ -> s1 = $3;}
                   ;

args               : /*empty*/ {$$ = NULL;}
                   | arglist {$$ = $1;}
                   ;
                   
arglist            : expression {$$ = ASTcreatenode(ARGSLIST);
		   		 $$ -> s1 = $1;
				 $$ -> next = NULL;}
                   | expression ',' arglist {$$ = ASTcreatenode(ARGSLIST);
					     $$ -> s1 = $1;
					     $$ -> next = $3;}
                   ;
%%	/* end of rules, start of program */

int main(int argv, char *arg[])
{ 
  yyparse();
  fprintf(stderr, "The input has been checked.");
  ASTprint(program, 0);
}
