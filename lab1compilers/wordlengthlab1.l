%{
     /*  This lex routine uses a counting array to match alphabeticstrings 
         and make a frequency count.
  
         The real item to notice is that yywrap() is called at EOF and then is run
         to do what we need to do.   yywrap() returns true when we have a successful 
         end to the program.  We may want to return false (0) if we want to lexing process 
         to fail 

        Shaun Cooper
        January 2015
   */

   /*
	wordlengthlab1.l
	Brianna Moffett
	Jan. 24th, 2020
	
	input: sequence of characters/numbers
	output: number of words, number of number sequences
	input assumes that there are no special characters (such as ], }, or *), otherwise, it skips 		them

	Changes made:
	1. created global variable ("count")
	2. added lex directive to count number of number sequences entered by the user
	3. added display statement to display count of number sequences
   */
	int lgths[100];
	int count = 0;
%}
%%
   /*
	Statements within curly brackets help the program run multiple commands within the same 	context.
   */
[a-zA-Z]+	{lgths[yyleng]++;}
[0-9]+		{count++;}
.	|
\n	;
%%
/*
	precondition: input should not be special characters
	postcondition: non-negative count of words and number sequences
*/
int yywrap()
{
	int i;
	printf("Length  No. words\n");
	for (i=1; i<100; i++) {
		if (lgths[i] > 0) {
			printf("%5d%10d\n",i,lgths[i]);
		}
	}
	printf("No. of numbers is %d\n", count);
	return(1);
}

int main()
{  yylex();

}
