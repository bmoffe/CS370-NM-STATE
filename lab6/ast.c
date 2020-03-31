#include "ast.h"
#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
static int mydebug;


void printspace(int num){
	int i;
	for (i = 0; i < num; i++){
		printf("  ");
	}
}


void printtype(enum OPERATORS op){

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


void ASTprint(ASTnode *p, int level){
	int i;
	//printf("I am here.\n");
	if (p == NULL){return;}
	printspace(level);
			switch (p->type){
				case VARDEC: printf("var ");
					     printtype(p -> operator);
					     printf(" %s", p->name);
					     if (p -> value > 0){
						     printf("[%d]", p -> value);
					     }
					     printf("\n");
					     ASTprint(p -> s1, level);
					     break;
				case FUNDEC: printf("function ");
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
				case PARAM: printf("params ");
					    printtype(p -> operator);
					     printf("%s \n", p -> name);
					     ASTprint(p -> s1, level + 1);
					     break;
			        case BLOCK: printf("block \n");
					    ASTprint(p -> s1, level + 1);
					    ASTprint(p -> s2, level + 1);
					    break;
				case ASSIGNSTMT: printf("assign \n");
					         ASTprint(p -> s1, level + 1);
					         ASTprint(p -> s2, level + 1);
					         break;
			        case IFSTMT: printf("if \n");
					     ASTprint(p -> s1, level + 1);
					     ASTprint(p -> s2 -> s1, level + 1);
					     if (p -> s2 -> s2 != NULL){
						            printspace(level);
							    printf("else \n");
							    ASTprint(p -> s2 -> s2, level + 1);
					     }
					     break;
				case WHILESTMT: printf("while \n");
				                ASTprint(p -> s1, level + 1);
				                ASTprint(p -> s2, level + 1);
					        break;
				case ARGSLIST: printf("arg list \n");
					       ASTprint(p -> s1, level + 1);
					       break;
			        case WRITESTMT: printf("write \n");
				                ASTprint(p -> s1, level + 1);
				                break;
				case READSTMT: printf("read \n");
					       ASTprint(p -> s1, level + 1);
					       break;
				case RETURNSTMT:printf("return ");
					         if (p -> s1 == NULL){
							 printf("empty \n");
						 }
						 else{
							 printf("with expr \n");
							 ASTprint(p -> s1, level + 1);
						 }
						 break;
				case CALL: printf("call: %s \n", p -> name);
					   ASTprint(p -> s1, level + 1);
					   break;
				case EXPRSTMT: printf("expr statement \n");
					       ASTprint(p -> s1, level + 1);
					       break;
				case EXPR:
					   if (p -> operator == PLUS){
						   printf("plus op \n");
					   }
					   if (p -> operator == MINUS){
						   printf("minus op \n");
					   }
					   if (p -> operator == MULTI){
						   printf("multiply op \n");
					   }
					   if (p -> operator == DIV){
						   printf("div op \n");
					   }
					   if (p -> operator == LESSTHANEQ){
						   printf("<= \n");
					   }
					   if (p -> operator == GREATERTHANEQ){
						   printf(">= \n");
					   }
					   if (p -> operator == LESSTHAN){
						   printf("< \n");
					   }
					   if (p -> operator == GREATERTHAN){
						   printf("> \n");
					   }
					   if (p -> operator == EQUAL){
						   printf("= \n");
					   }
					   if (p -> operator == NOTEQUAL){
						   printf("!= \n");
					   }
					   if (p -> operator == MYNOT){
						   printf("NOT \n");
					   }
					   if (p -> operator == MYAND){
						   printf("AND \n");
					   }
					   if (p -> operator == MYOR){
						   printf("OR \n");
					   }
					   ASTprint(p -> s1, level + 1);
					   ASTprint(p -> s2, level + 1);
					   break;
				case NUMBER: /*printspace(level);*/
					     printf("num with val %d \n", p -> value);
					     ASTprint(p -> s1, level + 1);
					     break;
				case IDENTIFIER:
					  if (p -> s1 == NULL){
						  printf("id %s \n", p -> name);
						  ASTprint(p -> s1, level + 1);
					  }
					  else {
						  printf("id %s \n", p -> name);
						  printspace(level);
						  printf("array ref [ \n");
						  ASTprint(p -> s1, level + 1);
						  printspace(level);
						  printf("] \n");/*array end*/
					  }
					  break;
				default: printf("unknown type");
			}//END OF SWTICH
			ASTprint(p -> next, level);
}



ASTnode *ASTcreatenode(enum ASTtype newtype){
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
