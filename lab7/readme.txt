Brianna Moffett
04.17.20

List of files:
-lab7 (executable)
-lab7.l (lex file containing rules for program) 
-lab7.y (YACC file with actions for AST)
-lex.yy.c (not used anywhere in the files; is automatically generated, but is not actually included anywhere)
-makefile (compiles all programs with respective commands)
-ast.c
-ast.h
-symtable.h
-symtable.c
-y.tab.c
-y.tab.h

To compile:
-open linux terminal
-type "make" in command line
	-the "make" command will perform all compilation functions for you; saves lots of time!

To run:
-type "./lab7 < lab7test.al" into command line
	-if you want to write the output to a file, add "> <filename>.txt" to the end of the run command

