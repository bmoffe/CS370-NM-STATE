         /* simple lex program which removes comments from a source program
            The main key is that a variable "comment" is set when the start of a comment
            is seen and then unset when the ending set is seen.  It is possible to have
            two starts closed by on end.

            Shaun Cooper
            January 2015
 
         */
	/* Modified by: Brianna Moffett
	   Changes made:
	   -added new line number variable, added rule to track line number, added line number as param to printf in "/*" rule
	*/
        int comment = 0;
        int debug=0;  /* prints out debug statements if desired */
	int linenumber = 1; /*line number var*/
%%
\n	{printf("\n", linenumber++);}

"/*"	{
	if (comment) fprintf(stderr,
		" >>>>>>>> line %d: Possible Nested comment <<<<<<<<<<\n",linenumber);
	comment = 1;
	}

"*/"	{
          if (!comment) printf("%s",yytext); /*print out if it is not in a comment */
  	  comment = 0;
	}
.       { if (!comment) printf("%s",yytext);}

%%

int yywrap(void)
{ return 1;
}

int main()
{
  yylex();
  
}

