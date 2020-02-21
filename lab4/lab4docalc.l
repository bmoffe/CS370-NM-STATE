/*                 Small LEX routine which returns two formal tokens (INTEGER and VARIABLE)
                   along with single string elements like '+'.
 
                    This LEX definition is the companion to the docalc.y YACC routine which
                   is a simple calculator

                    Shaun Cooper
                    January 2015

		    Modified by: Brianna Moffett
		    Changes made:
		    	-added parenthesis to acceptable list of tokens
*/
%{

int mydebug=1;
int ln = 0;
#include "y.tab.h"
#include "symtable.c"
%}

letter	[a-zA-Z]
digit	[0-9]
id	{letter}({letter}|{digit})*

%%
int		{if(mydebug) fprintf(stderr, "int found\n");
			return(INT);}
{id}		{if(mydebug) fprintf(stderr, "id found\n");
			yylval.string = strdup(yytext);return(VARIABLE);}
[0-9][0-9]*	{if (mydebug) fprintf(stderr,"Digit found\n"); 
                       yylval=atoi((const char *)yytext); return(INTEGER);}
[ \t]		{if (mydebug) fprintf(stderr,"Whitespace found\n");}
[=()\-+*/%&|;] 	{ if (mydebug) fprintf(stderr,"return a token %c\n",*yytext); 
                       return (*yytext);}
\n 		{ if (mydebug) fprintf(stderr,"cariage return %c\n",*yytext); 
                       return (*yytext);}

%%

int yywrap(void)
{ return 1;}


