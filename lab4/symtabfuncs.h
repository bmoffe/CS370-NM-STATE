#ifndef SYMTABFUNCS_H
#define SYMTABFUNCS_H
#include<stdio.h>
/* #include<conio.h> */
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
/*
 * Modifed by: Brianna Moffett
 * Changes made:
 *  -created header file
 */
void Insert(char * sym, int offset);
void Display();
void Delete();
int Search(char sym[]);
void Modify();
int fetchAddr(char * sym);
struct SymbTab
{
    char * symbol;
    int addr;
    struct SymbTab *next;};
#endif
