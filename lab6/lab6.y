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
	Changes made: (04.01.20):
	 -added semantic actions for creating AST
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
        
vardec   : typespec varlist ';' /*vardec*/ {$$ = $2; /*when we find a varlist, we point to typespec, then loop through the varlist to set the type*/
					    ASTnode * p = $$;
				            while(p != NULL){
					      p -> operator = $1;
					      p = p -> s1;}}
	 ;
         
varlist  : ID /*vardec*/ {$$ = ASTcreatenode(VARDEC); /*vars can be a single variable, and array, or either of those followed by a varlist*/
                          $$ -> name = $1;}
			   
         | ID '[' NUM ']'
			  	    {$$ = ASTcreatenode(VARDEC);
			  	     $$ -> name = $1;
			  	     $$ -> value = $3;}
         | ID ',' varlist {$$ = ASTcreatenode(VARDEC);
			   $$ -> name = $1;
			   $$ -> s1 = $3;}
         | ID '[' NUM ']' ',' varlist {$$ = ASTcreatenode(VARDEC);
				       $$ -> name = $1;
				       $$ -> value = $3;
				       $$ -> s1 = $6;}
         ;
         
typespec : INT {$$ = INTTYPE; /*integer type*/
	    }
         | VOID {$$ = VOIDTYPE; /*void type*/
		   }
         | BOOLEAN {$$ = BOOLTYPE; /*boolean type*/
		      }
         ;
         
fundec   : typespec ID '(' params ')' compoundstmt {$$ = ASTcreatenode(FUNDEC);/*function delcaration*/
						    $$ -> operator = $1;/*this is typespec*/
						    $$ -> name = $2; /*this is ID*/
						    $$ -> s1 = $4; /*this is params*/
						    $$ -> s2 = $6;} /*this is compound stmt*/
         ;
         
params   : VOID {$$ = NULL;} /*parameters*/
         | paramlist {$$ = $1;}
         ;

paramlist : param {$$ = $1;} /*parameters list*/
          | param ',' paramlist {$$ = $1;
				 $$ -> next = $3;}
          ;
          
param     : typespec ID {$$ = ASTcreatenode(PARAM); /*param; when we het here, create PARAM node and set operator and name*/
	  		 $$ -> operator = $1;
			 $$ -> name = $2;}
          | typespec ID '[' NUM ']' {$$ = ASTcreatenode(PARAM); /*array param; create PARAM node, set operator, name, and value*/
				     $$ -> operator = $1;
				     $$ -> name = $2;
				     $$ -> value = $4;}
          ;
          
compoundstmt : MYBEGIN localdec statementlist END {$$ = ASTcreatenode(BLOCK); /*create BLOCK node and point s1 and s2 to localdec and statementlist, repsectively*/
							$$ -> s1 = $2;
							$$ -> s2 = $3;
						   }
             ;
             
localdec     : /*localdec*/ /*empty*/ {$$ = NULL;} /*localdec; if not empty, point next of vardec to localdec, then set $$ to vardec (which tells the program to look at the rules for vardec and go from there*/
             | vardec localdec {$1 -> next = $2; $$ = $1;}
             ;
             
statementlist : /*statement list*/ /*empty*/ {$$ = NULL;} /*when not empty, set next of statement to statementlist, then set $$ to statement*/
              | statement statementlist {
						$1 -> next = $2;
						$$ = $1;
					}
              ;
              
statement     : expressionstmt {$$ = $1;} /*expressionstmt*/
              | compoundstmt {$$ = $1;} /*coumpoundstmt*/
              | selectionstmt {$$ = $1;} /*selectionstmt*/
              | iterationstmt {$$ = $1;} /*iterationstmt*/
              | assignmentstmt {$$ = $1;} /*assignmentstmt*/
              | returnstmt {$$ = $1;} /*returnstmt*/
              | readstmt {$$ = $1;} /*readstmt*/
              | writestmt {$$ = $1;} /*writestmt*/
              ;

expressionstmt : expression ';' {$$ = ASTcreatenode(EXPRSTMT); /*create expression statement node, then point s1 to expression*/
	       			 $$ -> s1 = $1;}
               | ';' { $$ = ASTcreatenode(EXPRSTMT); /*point s1 to null if there is no expression following*/
		      $$ -> s1 = NULL;}
               ;
               
selectionstmt  : IF expression THEN statement {$$ = ASTcreatenode(IFSTMT); /*if statement, with no else*/
	   				       $$ -> s1 = $2;
					       $$ -> s2 = ASTcreatenode(IFELSE);
					       $$ -> s2 -> s1 = $4;}
               | IF expression THEN statement ELSE statement {$$ = ASTcreatenode(IFSTMT); /*if statement, with an else*/
							      $$ -> s1 = $2;
							      $$ -> s2 = ASTcreatenode(IFELSE);
					 		      $$ -> s2 -> s1 = $4;
							      $$ -> s2 -> s2 = $6;}
               ;
               
iterationstmt  : WHILE expression DO statement {$$ = ASTcreatenode(WHILESTMT); /*while loop*/
	       					$$ -> s1 = $2;
						$$ -> s2 = $4;}
               ;
               
returnstmt     : MYRETURN ';' {$$ = ASTcreatenode(RETURNSTMT); /*return statement*/
	       		       $$ -> s1 = NULL;}
               | MYRETURN expression ';' {$$ = ASTcreatenode(RETURNSTMT);
					  $$ -> s1 = $2;}
               ;
               
readstmt       : READ variable ';' {$$ = ASTcreatenode(READSTMT); /*read statement*/
	       			    $$ -> s1 = $2;}
               ;

writestmt      : WRITE expression ';' {$$ = ASTcreatenode(WRITESTMT); /*write statement*/
	       			       $$ -> s1 = $2;}
               ;
               
assignmentstmt : variable '=' simpleexpression ';' {$$ = ASTcreatenode(ASSIGNSTMT); /*assignment; point s1 to variable, point s2 to simpleexpression*/
	       					    $$ -> s1 = $1;
						    $$ -> s2 = $3;}
               ;
               
expression     : simpleexpression {$$= $1;} /*expression*/
               ;
               
variable       : ID {$$ = ASTcreatenode(IDENTIFIER); /*variable; create IDENTIFIER node, then set its name to ID, and point s1 to null since it has nothing following it*/
	       	     $$ -> name = $1;
		     $$ -> s1 = NULL;}
               | ID '[' expression ']' {$$ = ASTcreatenode(IDENTIFIER); /*do the same as before, but point s1 to expression now*/
					$$ -> name = $1;
					$$ -> s1 = $3;}
               ;
               
simpleexpression : additiveexpression {$$ = $1;} /*simple expression*/
                 | simpleexpression relop additiveexpression {$$ = ASTcreatenode(EXPR); /*create EXPRnode and point s1 to simpleexpression, operator to relop, and s2 to additiveexpression*/
							      $$ -> s1 = $1;
							      $$ -> operator = $2;
							      $$ -> s2 = $3;}
                 ;
                 
relop            : LE {$$ = LESSTHANEQ;} /*less than or equal*/
                 | LT {$$ = LESSTHAN;} /*less than*/
                 | GT {$$ = GREATERTHAN;} /*greater than*/
                 | GE {$$ = GREATERTHANEQ;} /*greater than or equal*/
                 | EQ {$$ = EQUAL;} /*equal*/
                 | NE {$$ = NOTEQUAL;} /*not equal*/
                 ;
                 
additiveexpression : term {$$ = $1;} /*term*/
		   | additiveexpression addop term {$$ = ASTcreatenode(EXPR); /*create EXPR node and point s1 to additiveexpression, operator to addop, and s2 to term*/
		   				    $$ -> s1 = $1;
						    $$ -> operator = $2;
						    $$ -> s2 = $3;}
                   ;
                   
addop              : '+' {$$ = PLUS;} /*plus operator*/
                   | '-' {$$ = MINUS;} /*minus operator*/
                   ;
                   
term               : factor {$$ = $1;} /*term*/
                   | term multop factor {$$ = ASTcreatenode(EXPR); /*create EXPR node, point s1 to term, operator to multop, and s2 to factor*/
					 $$ -> s1 = $1;
					 $$ -> operator = $2;
					 $$ -> s2 = $3;}
                   ;
                   
multop             : '*' {$$ = MULTI;} /*multiply*/
                   | '/' {$$ = DIV;} /*divide*/
                   | AND {$$ = MYAND;} /*and; and is a reserved word, so you should create your own and type*/
                   | OR  {$$ = MYOR;} /*or; or is a reserved word as well, so you should do what you did with and*/
                   ;
                
factor             : '(' expression ')' {$$ = $2;} /*expression*/
                   | NUM {$$ = ASTcreatenode(NUMBER); /*number*/
			  $$ -> value = $1;}
                   | variable {$$ = $1;} /*variable*/
                   | call {$$ = $1;} /*function call*/
                   | TRUE {$$ = ASTcreatenode(NUMBER); /*true result of if-else statement; this is set to one*/
		           $$ -> value = 1;}
                   | FALSE {$$ = ASTcreatenode(NUMBER); /*false result of if-else statement; this is set to zero*/
		            $$ -> value = 0;}
                   | NOT factor {$$ = ASTcreatenode(EXPR); /*create EXPR node, point operator to your own NOT type (as not is a reserved word) and s1 to factor*/
				 $$ -> operator = MYNOT;
				 $$ -> s1 = $2;}
                   ;
                   
call               : ID '(' args ')' {$$ = ASTcreatenode(CALL); /*function call; point name to ID, and s1 to args*/
		   		      $$ -> name = $1;
				      $$ -> s1 = $3;}
                   ;

args               : /*empty*/ {$$ = NULL;}
                   | arglist {$$ = $1;} /*arglist*/
                   ;
                   
arglist            : expression {$$ = ASTcreatenode(ARGSLIST); /*create ARGSLIST node, point s1 to expression and next of arglist to null*/
		   		 $$ -> s1 = $1;
				 $$ -> next = NULL;}
                   | expression ',' arglist {$$ = ASTcreatenode(ARGSLIST); /*do the same thing here, except now next should point to arglist*/
					     $$ -> s1 = $1;
					     $$ -> next = $3;}
                   ;
%%	/* end of rules, start of program */

int main(int argv, char *arg[]) /*main; call ASTprint, feed it program and 0*/
{ 
  yyparse();
  fprintf(stderr, "The input has been syntactically checked.");
  ASTprint(program, 0);
}
