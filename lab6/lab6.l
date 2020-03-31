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
		    Changes made (03.03.20)
			-added token return statements
*/
%{

#include "ast.h"
int mydebug=1;
int ln = 1;
#include "y.tab.h"
%}



%%
int		{return(INT);} /*int token*/
void            {return(VOID);} /*void token*/
boolean         {return(BOOLEAN);} /*boolean token*/
true		{return(TRUE);} /*true token*/
false		{return(FALSE);} /*false token*/
if		{return(IF);} /*if token*/
then		{return(THEN);} /*then token*/
else		{return(ELSE);} /*else token*/
do 		{return(DO);} /*do token*/
while		{return(WHILE);} /*while token*/
return		{return(MYRETURN);} /*return token*/
read		{return(READ);} /*read token*/
write		{return(WRITE);} /*write token*/
"<="		{return(LE);} /*less than or equal to token*/
">="		{return(GE);} /*greater than or equal to token*/
"=="		{return(EQ);} /*equal token*/
"!="		{return(NE);} /*not equal token*/
"<"		{return(LT);} /*less than token*/
">"		{return(GT);} /*greater than token*/
or		{return(OR);} /*or token*/
and		{return(AND);} /*and token*/
not		{return(NOT);} /*not token*/
begin 		{return(MYBEGIN);} /*begin token*/
end		{return(END);} /*end token*/
[a-zA-Z][a-zA-Z0-9]*		{/*if(mydebug) fprintf(stderr, "id found\n");*/ /*if ID is found, return VARIABLE token with the value of whatever this variable is named (i.e. 'x'*/
			yylval.str = strdup(yytext);return(ID);}
[0-9][0-9]* 	{/*if (mydebug) fprintf(stderr,"Digit found\n");*/
                       yylval.val=atoi((const char *)yytext); return(NUM);}
[ \t]		/*{if(mydebug) fprintf(stderr, "whitespace found\n");}*/
[<>=()\-+*/%&\[\];,]		{/*if(mydebug) fprintf(stderr, "return a token %c\n", *yytext);*/
					return(*yytext);}
\n		{ln++;}

%%

int yywrap(void)
{ return 1;}


