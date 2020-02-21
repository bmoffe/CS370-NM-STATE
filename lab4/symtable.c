/*
 * Modified by: Brianna Moffett
 * Changes made:
 *  -made header and included it in file
 *  -added comments to code
 *  -removed headers for functions and placed them in header file 
 */
#include<stdio.h>
/* #include<conio.h> */
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include "symtabfuncs.h"
    int size = 0;
    struct SymbTab *first,*last;
//    void main(){
//	Insert("foo", 0);
//    }
    void Insert(char * sym, int offset) /*inserts symbol into table*/
    {
        int n;
        n=Search(sym);
        if(n==1)
            printf("\n\tThe label exists already in the symbol table\n\tDuplicate can.t be inserted");
        else
        {
            struct SymbTab *p;
            p=malloc(sizeof(struct SymbTab));
            p->symbol = strdup(sym);
            p->next=NULL;
            if(size==0)
            {
                first=p;
                last=p;
            }
            else
            {
                last->next=p;
                last=p;
            }
            size++;
        }
    }/*of insert*/
    void Display() /*displays the table*/
    {
        int i;
        struct SymbTab *p;
        p=first;
        printf("\t\tSYMBOL\t\tADDRESS\n");
        for(i=0;i<size;i++)
        {
            printf("\t\t%s\t\t%d\n",p->symbol,p->addr);
            p=p->next;
        }
    }/*of display*/
    int Search(char sym[]) /*searches table for specified symbol*/
    {
        int i,flag=0;
        struct SymbTab *p;
        p=first;
        for(i=0;i<size;i++)
        {
            if(strcmp(p->symbol,sym)==0)
                flag=1;
            p=p->next;
        }
        return flag;
    }/*of search*/
    void Delete() /*removes a symbol from the table*/
    {
        int a;
        char l[10];
        struct SymbTab *p,*q;
        p=first;
    } /*of delete*/

    int fetchAddr(char * sym){
	int i, address;
	struct SymbTab *p;
	p = first;
	for (i = 0; i < size; i++){
		if (strcmp(p->symbol, sym) == 0){
			address = p->addr;
		}
		p = p->next;
	}
	return address;
   }/*of fetch*/
    
    
