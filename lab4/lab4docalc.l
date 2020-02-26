/*                 Small LEX routine which returns two formal tokens (INTEGER and VARIABLE)
                   along with single string elements like '+'.
 
                    This LEX definition is the companion to the docalc.y YACC routine which
                   is a simple calculator

                    Shaun Cooper
                    January 2015

		    Modified by: Brianna Moffett
		    Changes made:
		    	-added parenthesis to acceptable list of tokens
		    Changes made (02.26.20):
			-added rules to return VARIABLE and INTEGER tokens
			-added semicolon to list of acceptable tokens
*/
%{

int mydebug=1;
int ln = 1;
#include "y.tab.h"
%}

letter	[a-zA-Z]
digit	[0-9]
id	{letter}({letter}|{digit})*

%%
int		{if(mydebug) fprintf(stderr, "int found\n");/*if we find "int", return INT token*/
			return(INT);}
{id}		{if(mydebug) fprintf(stderr, "id found\n"); /*if ID is found, return VARIABLE token with the value of whatever this variable is named (i.e. 'x'*/
			yylval.str = strdup(yytext);return(VARIABLE);}
[0-9][0-9]*	{if (mydebug) fprintf(stderr,"Digit found\n"); /*if digit is found, return INTEGER token*/
                       yylval.val=atoi((const char *)yytext); return(INTEGER);}
[ \t]		{if (mydebug) fprintf(stderr,"Whitespace found\n");}
[=()\-+*/%&|;] 	{ if (mydebug) fprintf(stderr,"return a token %c\n",*yytext); 
                       return (*yytext);}
\n 		{ if (mydebug) fprintf(stderr,"cariage return %c\n"
,*yytext); 
                       return (*yytext);}

%%

int yywrap(void)
{ return 1;}


