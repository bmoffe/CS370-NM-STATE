all :	lab4
	yacc -d lab4docalc.y #creates the y.tab.cc and y.tab.h files
	lex lab4docalc.l #creates lex.yy.c file
	gcc y.tab.c -o lab4docalc #compiles y.tab.c and creates executable

lab4:	symtable.c symtabfuncs.h
	gcc -o lab4 symtable.c
