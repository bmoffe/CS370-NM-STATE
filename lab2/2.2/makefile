#Brianna Moffett, CS370
#this all target performs all of the commands to compile all specified files
all : lab2docalc
	yacc -d lab2docalc.y #creates the y.tab.cc and y.tab.h files
	lex lab2docalc.l #creates lex.yy.c file
	gcc y.tab.c -o lab2docalc #compiles y.tab.c and creates executable
