Brianna Moffett
02.26.20

Requirements completed:
In Lex file, added rules to handle variables, used strdup() to duplicate string so that YACC has a variable name to work with
In YACC file, added procedures to handle assignment of values to variables, creation of variables, and duplicate variable/undefined variable checks. Also, created union to allow Lex to return an integer or string, added procedure to fetch the address of the symbol requested
In symbol table code, modified Insert() method to take parameters (one pointer, one integer), allowing for automatic insertion of variables when Insert() is called in YACC and Lex files, removed main() (as it was unnecessary), added function to fetch the ADDRESS of a given symbol so that it can be inserted into the symbol
   
List of files:
-lab4docalc (executable)
-lab4docalc.l (lex file containing rules for program) 
-lab4docalc.y (YACC file containing procedures for calculator functions)
-Lab4tests.pdf (pdf file containing test case screenshots)
-lex.yy.c (not used anywhere in the files; is automatically generated, but is not actually included anywhere)
-makefile (compiles all programs with respective commands)
-symtabfuncs.h (header file for functions in symtable.c)
-symtable.c (contains code for symbol table)
-vars.txt (contains 27 variables to test filled reg space condition)
-readme.txt (lists the contents of the .ZIP file; you are here)
-y.tab.c
-y.tab.h

To compile:
-open linux terminal
-type "make" in command line
	-the "make" command will perform all compilation functions for you; saves lots of time!

To run:
-type "./lab4docalc" into command line
	-lab4docalc is the executable for the program

To run using vars.txt (only if you do not want to hand type each variable for testing filled regs space condition):
-type "./lab4docalc < vars.txt" into command line
