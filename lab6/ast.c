#include "ast.h"
#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
static int mydebug;


void printspace(int num){//print spaces
	int i;
	for (i = 0; i < num; i++){
		printf("  ");
	}
}


void printtype(enum OPERATORS op){//print types

     if(op == INTTYPE){
          printf("int ");
     }
     if (op == VOIDTYPE){
          printf("void ");
     }
     if (op == BOOLTYPE){
          printf("boolean ");
     }

}


void ASTprint(ASTnode *p, int level){//ASTprint fucntion
	int i;
	//printf("I am here.\n");
	if (p == NULL){return;}
	printspace(level);
			switch (p->type){ //switch for each node case
				case VARDEC: printf("VARIABLE ");//vardec
					     printtype(p -> operator);
					     printf(" %s", p->name);
					     if (p -> value > 0){//if variable is array
						     printf("[%d]", p -> value);
					     }
					     printf("\n");
					     ASTprint(p -> s1, level);
					     break;
				case FUNDEC: printf("FUNCTION "); //function
					     printtype(p -> operator);
					     printf("FUNCTION %s \n", p -> name);
					     if (p -> s1 == NULL){
						     printf("(void)");
					     }
					     else{
						     printf("(\n");
						     ASTprint(p -> s1, level + 1);
						     printf(")");
					     }
					     printf("\n");
					     ASTprint(p -> s2, level + 1);
					     break;
				case PARAM: printf("PARAMS ");//params
					    printtype(p -> operator);
					     printf("%s \n", p -> name);
					     ASTprint(p -> s1, level + 1);
					     break;
			        case BLOCK: printf("BLOCK \n");//block
					    ASTprint(p -> s1, level + 1);
					    ASTprint(p -> s2, level + 1);
					    break;
				case ASSIGNSTMT: printf("ASSIGNMENT \n");//assignment
					         ASTprint(p -> s1, level + 1);
					         ASTprint(p -> s2, level + 1);
					         break;
			        case IFSTMT: printf("IF \n");//if statement
					     ASTprint(p -> s1, level + 1);
					     ASTprint(p -> s2 -> s1, level + 1);
					     if (p -> s2 -> s2 != NULL){
						            printspace(level);
							    printf("ELSE \n");
							    ASTprint(p -> s2 -> s2, level + 1);
					     }
					     break;
				case WHILESTMT: printf("WHILE \n");//while
				                ASTprint(p -> s1, level + 1);
				                ASTprint(p -> s2, level + 1);
					        break;
				case ARGSLIST: printf("ARGLIST \n");//argslist
					       ASTprint(p -> s1, level + 1);
					       break;
			        case WRITESTMT: printf("WRITE \n");//write
				                ASTprint(p -> s1, level + 1);
				                break;
				case READSTMT: printf("READ \n");//read
					       ASTprint(p -> s1, level + 1);
					       break;
				case RETURNSTMT:printf("WRITE ");//return
					         if (p -> s1 == NULL){
							 printf("empty \n");
						 }
						 else{
							 printf("WITH EXPRESSION \n");//return with expression
							 ASTprint(p -> s1, level + 1);
						 }
						 break;
				case CALL: printf("CALL: %s \n", p -> name);//function call
					   ASTprint(p -> s1, level + 1);
					   break;
				case EXPRSTMT: printf("EXPRESSION STATEMENT \n");//expression
					       ASTprint(p -> s1, level + 1);
					       break;
				case EXPR:
					   if (p -> operator == PLUS){//plus
						   printf("PLUS \n");
					   }
					   if (p -> operator == MINUS){//minus
						   printf("MINUS \n");
					   }
					   if (p -> operator == MULTI){//multiply
						   printf("TIMES \n");
					   }
					   if (p -> operator == DIV){//divide
						   printf("DIVIDE \n");
					   }
					   if (p -> operator == LESSTHANEQ){//less than or equal
						   printf("<= \n");
					   }
					   if (p -> operator == GREATERTHANEQ){//greater than or equal
						   printf(">= \n");
					   }
					   if (p -> operator == LESSTHAN){//less than
						   printf("< \n");
					   }
					   if (p -> operator == GREATERTHAN){//greater than
						   printf("> \n");
					   }
					   if (p -> operator == EQUAL){//equal
						   printf("= \n");
					   }
					   if (p -> operator == NOTEQUAL){//not equal
						   printf("!= \n");
					   }
					   if (p -> operator == MYNOT){//not
						   printf("NOT \n");
					   }
					   if (p -> operator == MYAND){//and
						   printf("AND \n");
					   }
					   if (p -> operator == MYOR){//or
						   printf("OR \n");
					   }
					   ASTprint(p -> s1, level + 1);
					   ASTprint(p -> s2, level + 1);
					   break;
				case NUMBER: /*printspace(level);*/ //number
					     printf("NUMBER WITH VALUE %d \n", p -> value);
					     ASTprint(p -> s1, level + 1);
					     break;
				case IDENTIFIER: //identifier
					  if (p -> s1 == NULL){//non-array variable
						  printf("ID %s \n", p -> name);
						  ASTprint(p -> s1, level + 1);
					  }
					  else { //array variable
						  printf("ID %s \n", p -> name);
						  printspace(level);
						  printf("array ref [ \n");
						  ASTprint(p -> s1, level + 1);
						  printspace(level);
						  printf("] \n");/*array end*/
					  }
					  break;
				default: printf("unknown type"); //default
			}//END OF SWTICH
			ASTprint(p -> next, level);//recursive call to ASTprint
}



ASTnode *ASTcreatenode(enum ASTtype newtype){ //creates new node
	ASTnode *p	;
	if (mydebug) fprintf(stderr, "creating node \n");
	p = (ASTnode *) malloc(sizeof(ASTnode));
	p -> type = newtype;
	p -> next = NULL;
	p -> s1 = NULL;
	p -> s2 = NULL;
	p -> value = 0;
	return(p);
}
