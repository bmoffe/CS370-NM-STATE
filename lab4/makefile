all :	
	yacc -d lab4docalc.y #creates the y.tab.cc and y.tab.h files
	lex lab4docalc.l #creates lex.yy.c file
	gcc y.tab.c lex.yy.c symtable.c -o lab4docalc #compiles y.tab.c and creates executetable
