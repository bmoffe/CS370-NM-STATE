all :	lab6 #all target
	
lab6:	y.tab.c
	gcc y.tab.c lex.yy.c ast.c -o lab6 #compiles lex.yy.c and creates executable 
y.tab.c:clean
	yacc -d lab6.y #compiles YACC file
	lex lab6.l #compiles LEX file
clean:
	rm -f y.tab.c y.tab.h #ensures that y.tab.c and y.tab.h are fresh every time we compile
