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
	Changes made: (04.17.20):
	 -added type checking, usage checking, declaration checking, and insertion actions
	 -added an include for symtable.h
*/


	/* begin specs */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "symtable.h"
#include "ast.h"
#include "emit.h"
int yylex(); /*prototype to get rid of warnings*/
int max(int x, int y);
static int mydebug=0;
extern int ln;
static int offset = 0;
static int goffset = 0;
static int maxoffset = 0;
int level = 0;
extern ASTnode *program;
enum OPERATORS mytype;
void yyerror (s)
  char * s;
  {  /* Called by yyparse on error */
     fprintf (stderr, "%s on line number %d\n", s, ln);
  }
int max(int x, int y){
	if (x < y){return y;}
	else{return x;}
}
%}
/*  defines the start symbol, what values come back from LEX and how the operators are associated  */

%start program

%union{
	int val;
	char * str;
	char * label;
        ASTnode * node;
	enum OPERATORS operator;
}
%token <str> STRING
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
					      p -> symbol -> Type = $1;
					      p = p -> s1;}}
	 ;
         
varlist  : ID /*vardec*/ {if (Search($1,level,0) != NULL){/*if the symbol is in the table, err; else, insert it*/
	 			yyerror($1);
				yyerror("symbol already in use");
				exit(1);
			     }
			     else{
	 		        $$ = ASTcreatenode(VARDEC); /*vars can be a single variable, and array, or either of those followed by a varlist*/
				$$-> symbol = Insert($1, -1, 0, level, 1, offset, NULL);
				$$ -> name = $1;
				offset += 1;
				Display();}
                                $$ -> name = $1;
			     }
			   
         | ID '[' NUM ']' /*if the symbol is being used, err; else, insert*/
			  	    {if (Search($1, level, 0)){
					yyerror($1);
					yyerror("symbol in use");
					exit(1);
				    }
				    else{
				     $$ = ASTcreatenode(VARDEC);
				     $$ -> symbol = Insert($1, -1, 2, level, $3, offset, NULL);
				     offset += $3;
				     Display();}
			  	     $$ -> name = $1;
			  	     $$ -> value = $3;}
				    
         | ID ',' varlist {if(Search($1, level, 0)){/*recursively checks for in use symbols, then inserts if current symbol is not in the table*/
				yyerror($1);
				yyerror("symbol in use");
				exit(1);}
			   else{
				$$ = ASTcreatenode(VARDEC);
				$$ -> symbol = Insert($1, -1, 0, level, 1, offset, NULL);
				offset += 1;
				Display();}
			   	$$ -> name = $1;
			   	$$ -> s1 = $3;}
         | ID '[' NUM ']' ',' varlist {if (Search($1, level, 0)){/*recursively checks for in use symbols, then inserts if current
symbol is not in the table*/
					yyerror($1);
					yyerror("symbol in use");
					exit(1);}
				        else{
				       	     $$ = ASTcreatenode(VARDEC);
					     $$ -> symbol = Insert($1, -1, 2, level, $3, offset, NULL);
					     offset += $3;
					     Display();}
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
         
fundec   : typespec ID '(' params ')'{if(Search($2,level,0)){
	 					yyerror($2);
						yyerror("duplicate");
						exit(1);
				      }
				      else{
					goffset = offset;
					offset = 2;
					maxoffset = offset;
				      }}compoundstmt {$$ = ASTcreatenode(FUNDEC);/*function delcaration*/
						     $$ -> operator = $1;/*this is typespec*/
						     $$ -> name = $2; /*this is ID*/
						     $$ -> s1 = $4; /*this is params*/
						     $$ -> s2 = $7;
						     maxoffset=max(offset,maxoffset);
						     $$ -> symbol = Insert($2, $1, 1, level, 0, offset, $4);
						     $$ -> symbol -> mysize=maxoffset;
						     $$ -> value = maxoffset;
						     offset -= Delete(1);
						     level = 0;
						     offset=goffset;}
         ;
         
params   : VOID {$$ = NULL;} /*parameters*/
         | paramlist {$$ = $1;}
         ;

paramlist : param {$$ = $1;} /*parameters list*/
          | param ',' paramlist {$$ = $1;
				 $$ -> next = $3;}
          ;
param     : typespec ID {if (Search($2, level + 1, 0)){/*if the symbol is in the table, err, else, insert*/
				yyerror($2);
				yyerror("symbol in use");
				exit(1);}
				
			 $$ = ASTcreatenode(PARAM); /*param; when we het here, create PARAM node and set operator and name*/
			 $$ -> symbol = Insert($2, $1, 0, level + 1, 1, offset, 0);
			 offset += 1;
			 if(mydebug){Display();}
	  		 $$ -> operator = $1;
		         $$ -> semtype = $1;
			 $$ -> value = 0;
			 $$ -> name = $2;}

          | typespec ID '[' ']' {if(Search($2, level + 1, 0)){/*if the symbol is in the table, err, else, insert*/
					yyerror($2);
					yyerror("symbol in use");
					exit(1);}

				     $$ = ASTcreatenode(PARAM); /*array param; create PARAM node, set operator, name, and value*/
				     $$ -> symbol = Insert($2, $1, 2, level + 1, 1, offset, 0);
			     	     offset += 1;
				     Display();
				     $$ -> semtype = $1;
				     $$ -> operator = $1;
				     $$ -> name = $2;
				     $$ -> value = -1;}
          ;
compoundstmt : MYBEGIN {level++; printf("Block level is %d\n", level);}localdec statementlist END {/*tracks block level for functions*/
	     						$$ = ASTcreatenode(BLOCK);
							$$ -> s1 = $3;
							$$ -> s2 = $4;
							Display();
							maxoffset=max(maxoffset,offset);
							offset -= Delete(level);
							level--;
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
               | WRITE STRING ';'{$$ = ASTcreatenode(WRITESTMT);
				  $$ -> name = $2;
				  $$ -> label = genlabel();}
	       ;
               
assignmentstmt : variable '=' simpleexpression ';' {$$ = ASTcreatenode(ASSIGNSTMT); /*assignment; point s1 to variable, point s2 to simpleexpression*/
	       					    if ($1 -> semtype != $3 -> semtype){/*if types mismatch, err*/
							yyerror("type mismatch");
							exit(1);
					 	    }
	       					    $$ -> name = createtemp();
						    $$ -> symbol = Insert($$->name, INTDEC, 0, level,1,offset, 0);
						    offset++; 
						    $$ -> s1 = $1;
						    $$ -> s2 = $3;}
               ;
               
expression     : simpleexpression {$$= $1;} /*expression*/
               ;
               
variable       : ID {struct SymbTab * p; /*if we try to do math on a void variable or undeclared variable, err*/
	       	     p = Search($1, level, 1);
	       	     if (p == NULL || p ->mysize > 1 || p -> Type == VOIDTYPE){
			yyerror($1);
			yyerror("variable undeclared or variable cannot be used this way");
			exit(1);}
					if (p -> IsAFunc != 0){
						yyerror($1);
						yyerror("not an array");
						exit(1);
					}
			
	       	     	$$ = ASTcreatenode(IDENTIFIER); /*variable; create IDENTIFIER node, then set its name to ID, and point s1 to null since it has nothing following it*/ /*if we try to do math on a void variable or undeclared variable, or use a variable in the wrong manner, err*/
			$$ -> symbol = p;
			$$ -> semtype = p -> Type;
	       	     	$$ -> name = $1;
		     	$$ -> s1 = NULL;}
               | ID '[' expression ']' {struct SymbTab * p; 
					p = Search($1, level, 1);
					if (p == NULL){
						yyerror($1);
						yyerror("variable undeclared");
						exit(1);}
					if (p -> IsAFunc != 2){
						yyerror($1);
						yyerror("not an array");
						exit(1);
					}
					$$ = ASTcreatenode(IDENTIFIER); /*do the same as before, but point s1 to expression now*/
					$$ -> symbol = p;
					$$ -> semtype = p -> Type;
					$$ -> name = $1;
					$$ -> s1 = $3;}
               ;
               
simpleexpression : additiveexpression {$$ = $1;} /*simple expression*/
                 | simpleexpression relop additiveexpression {$$ = ASTcreatenode(EXPR); /*create EXPRnode and point s1 to simpleexpression, operator to relop, and s2 to additiveexpression*/
					 if ($1 -> semtype != $3 -> semtype){/*if types mismatch, err*/
						yyerror("type mismatch");
						exit(1);
					 }
					 $$ -> name = createtemp();
					 $$ -> symbol = Insert($$->name,INTDEC,0,level,1,offset,0);
					 offset++;
					 $$ -> semtype = $1 -> semtype;
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
		   | additiveexpression addop term  {
					 if ($1 -> semtype != $3 -> semtype){/*if types mismatch, err*/
						yyerror("type mismatch");
						exit(1);
					 }
						    $$ = ASTcreatenode(EXPR); /*create EXPR node and point s1 to additiveexpression, operator to addop, and s2 to term*/
						    $$ -> name = createtemp();
						    $$ -> symbol = Insert($$->name, INTDEC,0,level,1,offset,0);
						    offset++;
						    $$ -> semtype = $1 -> semtype;
		   				    $$ -> s1 = $1;
						    $$ -> operator = $2;
						    $$ -> s2 = $3;}
                   ;
                   
addop              : '+' {$$ = PLUS;} /*plus operator*/
                   | '-' {$$ = MINUS;} /*minus operator*/
                   ;
                   
term               : factor {$$ = $1;} /*term*/
                   | term multop factor {
		     			if ($1 -> semtype != $3 -> semtype){/*if types mismatch, err*/
						yyerror("type mismatch");
						exit(1);
					}
					$$ = ASTcreatenode(EXPR); /*create EXPR node, point s1 to term, operator to multop, and s2 to factor*/
				        $$ -> semtype = $1 -> semtype;
					$$ -> s1 = $1;
					$$ -> operator = $2;
					$$ -> s2 = $3;
					$$ -> name = createtemp();
					$$ -> symbol = Insert($$ -> name, INTTYPE, 0, level, 1, offset, 0);
					offset++;}
                   ;
                   
multop             : '*' {$$ = MULTI;} /*multiply*/
                   | '/' {$$ = DIV;} /*divide*/
                   | AND {$$ = MYAND;} /*and; and is a reserved word, so you should create your own and type*/
                   | OR  {$$ = MYOR;} /*or; or is a reserved word as well, so you should do what you did with and*/
                   ;
                
factor             : '(' expression ')' {$$ = $2;} /*expression*/
                   | NUM {$$ = ASTcreatenode(NUMBER); /*number*/
			  $$ -> semtype = INTTYPE;/*set semantic type to int*/
			  $$ -> value = $1;}
                   | variable {$$ = $1;} /*variable*/
                   | call {$$ = $1;} /*function call*/
                   | TRUE {$$ = ASTcreatenode(NUMBER); /*true result of if-else statement; this is set to one*/
			  $$ -> semtype = BOOLTYPE;/*set semantic type to boolean*/
		           $$ -> value = 1;}
                   | FALSE {$$ = ASTcreatenode(NUMBER); /*false result of if-else statement; this is set to zero*/
			  $$ -> semtype = BOOLTYPE;/*set semantic type to boolean*/
		            $$ -> value = 0;}
                   | NOT factor {
				 if ($2 -> semtype != BOOLTYPE){/*if types mismatch, err*/
					yyerror("type mismatch");
					exit(1);}

				 $$ = ASTcreatenode(EXPR); /*create EXPR node, point operator to your own NOT type (as not is a reserved word) and s1 to factor*/
				 $$ -> name = createtemp();
				 $$ -> symbol = Insert($$->name,INTDEC,0,level,1,offset,0);
				 $$ -> operator = MYNOT;
				 $$ -> semtype = BOOLTYPE;
				 $$ -> s1 = $2;}
                   ;
                   
call               : ID '(' args ')' {struct SymbTab * p;/*if function is undefined, err*/
					p = Search($1,0,0);
		   		      if (p == NULL){
					yyerror($1);
					yyerror("function name undefined");/*need to check if function*/
					exit(1);
				      }
				      if (p -> IsAFunc != 1){
					yyerror($1);
					yyerror("not a function");/*need to check if function*/
					exit(1);
				      }
		   		      $$ = ASTcreatenode(CALL); /*function call; point name to ID, and s1 to args*/
		   		      $$ -> name = $1;
				      $$ -> semtype = p -> Type;
				      $$ -> symbol = p;
				      $$ -> s1 = $3;}
                   ;

args               : /*empty*/ {$$ = NULL;}
                   | arglist {$$ = $1;} /*arglist*/
                   ;
                   
arglist            : expression {$$ = ASTcreatenode(ARGSLIST); /*create ARGSLIST node, point s1 to expression and next of arglist to null*/
		   		 $$ -> name = createtemp();
				 $$ -> symbol = Insert($$ -> name, $1 -> semtype, 0, level, 1, offset, 0);/*insert args into symbol table*/
				 offset++;
		   		 $$ -> s1 = $1;
				 $$ -> semtype = $1 -> semtype;
				 $$ -> next = NULL;}
                   | expression ',' arglist {$$ = ASTcreatenode(ARGSLIST); /*do the same thing here, except now next should point to arglist*/
					     $$ -> name = createtemp();
					     $$ -> symbol = Insert($$ -> name, $1 -> semtype, 0, level, 1, offset, 0);
				 	     $$ -> semtype = $1 -> semtype;
					     offset++;
					     $$ -> s1 = $1;
					     $$ -> next = $3;}
                   ;
%%	/* end of rules, start of program */
/*int max(int x, int y){
	if (x > y){return(x);}
	else{return(y);}
}*/

int main(int argc, char *argv[]) /*main; call ASTprint, feed it program and 0*/
{
  int i=0;
  char s[100];
  FILE * file;
  int foundit = 0;
  while (i < argc){
	if (strcmp(argv[i], "-d") == 0){
		mydebug = 1;
	 	i = i + 1;
	}
	else if(strcmp(argv[i], "-o") == 0){
		if (argc > i + 1){
			foundit = 1;
		}
		sprintf(s, "%s.asm",argv[i+1]);
		i = i+2;
	}
	else {i = i+1;}
  }
  if(foundit == 0){
	printf("must provide -o arg\n");
	exit(1);
  }
  file=fopen(s,"w");
  if (file == NULL){
	printf("cannot open %s\n",s);
	exit(1);
  }
  yyparse();
  fprintf(stderr, "The input has been syntactically checked.\n");
  ASTprint(program, 0);
  fprintf(file,"\n.data\n");
  emitstrings(file, program);
  fprintf(file, "NL:\t.asciiz\t\"\\n\"\n");
  fprintf(file,"\n.align 2\n");
  emitglobals(file, program);
  fprintf(file,"\n.text\n");
  printf("pls work\n");
  emitast(file, program);
  printf("pls work\n");
}
