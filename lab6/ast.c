#include "ast.h"
#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
static int mydebug;
void ASTprint(ASTnode *p, int level){
	int i;
	if (p == NULL){return;}
	else{
		for (i = 0; i < level; i++){
			switch (p->type){
				case VARDEC: printf("var");
					     if(p -> operator == INTTYPE){
						     printf("int");
					     }
					     if (p -> operator == VOIDTYPE){
						     printf("void");
					     }
					     if (p -> operator == BOOLTYPE){
						     printf("boolean");
					     }
					     printf(" %s", p->name);
					     if (p -> value > 0){
						     printf("[%d]", p -> value);
					     }
					     printf("\n");
					     break;
				case FUNDEC: printf("function declaration");
					     if (p -> operator == INTDEC){
						     printf("int");
					     }
					     if (p -> operator == VOIDDEC){
						     printf("void");
					     }
					     if (p -> operator == BOOLDEC){
						     printf("boolean");
					     }
					     printf("FUNCTION %s \n", p -> name);
					     if (p -> s1 == NULL){
						     printf("(void)");
					     }
					     else{
						     printf("(\n");
						     ASTprint(p -> s1, level + 2);
						     printf(")");
					     }
					     printf("\n");
					     ASTprint(p -> s1, level + 2);
					     break;
				case PARAM: printf("params");
			       		     if (p -> operator == INTTYPE){
				 		     printf("int");
					     }
		       			     if (p -> operator == VOIDTYPE){
			 			     printf("void");
					     }
					     if (p -> operator == BOOLTYPE){
						     printf("boolean");
					     }
					     printf("%s \n", p -> name);
					     ASTprint(p -> s1, level + 1);
					     break;
			        case BLOCK: printf("block \n");
					    ASTprint(p -> s1, level + 1);
					    ASTprint(p -> s2, level + 2);
					    break;
				case ASSIGNSTMT: printf("assign \n");
					         ASTprint(p -> s1, level + 1);
					         ASTprint(p -> s2, level + 1);
					         break;
			        case IFSTMT: printf("if \n");
					     ASTprint(p -> s1, level + 1);
					     ASTprint(p -> s2, level + 2);
					     if (p -> s2 != NULL){
						    for (i = 0; i < level; i++){
							    printf(" ");
							    printf("else \n");
							    ASTprint(p -> s2, level + 2);
						    }
					     }
					     break;
				case WHILESTMT: printf("while \n");
				                ASTprint(p -> s1, level + 1);
				                ASTprint(p -> s2, level + 2);
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
				case RETURNSTMT:/* printf("return");*/
					         if (p -> s1 == NULL){
							 printf("return \n");
						 }
						 else{
							 printf("return with expr \n");
							 ASTprint(p -> s1, level + 1);
						 }
						 break;
				case CALL: printf("call: %s \n", p -> name);
					   ASTprint(p -> s1, level + 1);
					   break;
				case EXPRSTMT: printf("expr \n");
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
					   ASTprint(p -> s1, level + 1);
					   ASTprint(p -> s2, level + 1);
					   break;
				case NUMBER: printf("num with val %d \n", p -> value);
					  ASTprint(p -> s1, level + 1);
					  break;
				case IDENTIFIER:
					  if (p -> s1 == NULL){
						  printf("id %s \n", p -> name);
						  ASTprint(p -> s1, level + 1);
					  }
					  else {
						  printf("id %s \n", p -> name);
						  for (i = 0; i < level; i++){
							  printf(" ");
						  }
						  printf("aray ref [ \n");
						  ASTprint(p -> s1, level + 1);
						  for (i = 0; i < level; i++){
							  printf("] \n");/*array end*/
						  }
					  }
					  break;
				default: printf("unknown type");
			}
		}
	}
}
ASTnode *ASTcreatnode(enum ASTtype newtype){
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
void ASThitchleft(ASTnode *a, ASTnode *b){

}
