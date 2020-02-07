# makefile for Lab 1
# Brianna Moffett
# Jan. 24th, 2020

#all target for lab1 file, checks for the executable

all:	lab1

# this target compiles lex.yy.c file

lab1:	lex.yy.c
	gcc -o lab1 lex.yy.c

# this target lexs the .l file, generating a c program from the lex routines within

lex.yy.c:	wordlengthlab1.l
	lex wordlengthlab1.l

