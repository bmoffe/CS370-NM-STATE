#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "emit.h"
#include "ast.h"

static int GLABEL = 0;
char * currfunction;

char * genlabel(){
	char s[100];
	char * s1;
	sprintf(s, "L%d",GLABEL++);
	s1 = strdup(s);
	return s1;
}
/*ptr to astnode
 * prints all strings in MIPS format
 * */
void emitstrings(FILE * f, ASTnode * p){
	if (p == NULL){return;}
	if ((p->type == WRITESTMT) && (p->name !=NULL)){
		fprintf(f,"%s:\t.asciiz\t%s\n",p->label,p->name);
	}
	emitstrings(f,p->next);
	emitstrings(f,p->s1);
	emitstrings(f,p->s2);
}
void emitglobals(FILE * f, ASTnode *p){
	if (p == NULL){return;}
	if ((p->type == VARDEC) && (p->symbol->level == 0)){
		fprintf(f,"%s:\t .space\t%d\n",p->name,p->symbol->mysize*WSIZE);
	}
	emitglobals(f,p->next);
	emitglobals(f,p->s1);
}
//we're gonna make our code all fancy-like by taking in 4 params, and doing formatting pushups
//precon: 3 strings, print in assembly format in file
//	i.e.: emit(file, "L1", "add r19, r20", "#add registers 19 and 20");
//	turns up
//		L1:		add r19, r20	#add registers 19 and 20
void emit(FILE * f, char * label,  char * command, char * comment){
	if(strcmp("",label)==0){fprintf(f,"\t\t%s\t\t%s\n",command,comment);}
	else{fprintf(f,"%s:\t\t%s\t\t%s\n",label,command,comment);}
}
void emitfunctionhead(FILE * f, ASTnode * p){
	char s[100];
	emit(f,p->name,"", "#start of function");
	currfunction = p->name;
	sprintf(s,"subu $a0, $sp, %d",p->value*WSIZE);
	emit(f,"",s,"#adjust stack for function setup");
	emit(f,"","sw $sp, ($a0)","");
	emit(f,"","sw $ra, 4($a0)","");
	emit(f,"","move $sp, $a0","");
}//emitfunctionhead
void emitreturn(FILE * f, ASTnode * p){
	if(p != NULL){
		emitexpr(f,p);
	}
	emit(f,"","lw $ra, 4($sp)","#restore ra");
	emit(f,"","lw $sp, ($sp)", "#restore sp");
	if(strcmp(currfunction , "main") == 0){//need to do things differently if it's main
		emit(f,"", "li $v0, 10","#leave main");
		emit(f,"","syscall","#terminate main");
	}
	else {
		//jump back to where $ra references
	}	
}
void emitexpr(FILE * f, ASTnode * p){
	/*base case time*/
	char s[100];
	switch(p->type){
		case NUMBER:
			sprintf(s,"li $a0, %d", p->value);
			emit(f,"",s,"#expression is a number\n");
			return;
			break;
		case IDENTIFIER:
			emitID(f, p); //$a0 is address of ID
			emit(f, "", "lw $a0, ($a0)","#fetch val for ID");
			return;
			break;
			//fprintf
		case CALL:
			printf("found CALL in emitexpr");
			printf("expr not implemented");
			exit(1);
	}//switch
	emitexpr(f, p->s1);
	sprintf(s, "sw $a0, %d($sp)", p->symbol->offset * WSIZE);
	emit(f,"",s,"#store LHS in temp");
	if(p->s2 != NULL){
		emitexpr(f, p->s2);
		sprintf(s, "move $t0, $a0");
		emit(f, "", s, "#move RHS to temp reg");
	}
	sprintf(s, "lw $a0, %d($sp)", p->symbol->offset * WSIZE);
	emit(f, "",s,"#load LHS for relop");
	switch(p->operator){
		case PLUS:
			sprintf(s,"add $a0, $a0, $t0");
			emit(f, "", s, "#add");
			printf("plusop\n");
			break;
		case MINUS:
			sprintf(s,"sub $a0, $a0, $t0");
			emit(f,"",s,"#subtraction");
			printf("minus\n");
			break;
		case MULTI:
			sprintf(s,"mult $a0, $t0");
			emit(f,"",s,"#multi");
			emit(f,"","mflo $a0","#grab product");
			printf("multi\n");
			break;
		case DIV:
			sprintf(s, "div $a0, $t0");
			emit(f, "",s,"#div");
			emit(f,"","mflo $a0","#grab result");
			printf("div\n");
			break;
		case MYAND:
			sprintf(s,"and $a0, $t0");
			emit(f,"",s,"#and");
			printf("and\n");
			break;
		case MYOR:
			sprintf(s,"or $a0, $t0");
			emit(f,"",s,"#or");
			printf("or\n");
			break;
		case MYNOT:
			emit(f,"","sltiu $a0, $a0, 1", "#not");
			printf("not\n");
			break;
		case EQUAL:
			emit(f,"","seq $a0, $a0, $t0","#==");
			break;
		case NOTEQUAL:
			emit(f,"","seq $a0, $a0, $t0","#!=");
			emit(f,"","sltiu $a0, $a0, 1","#inverse");
			break;
		case GREATERTHANEQ:
			emit(f,"","sge $a0, $a0, $t0","#>=");
			break;
		case LESSTHANEQ:
			emit(f,"","sle $a0, $a0, $t0","#<=");
			break;
		case GREATERTHAN:
			emit(f,"","sgt $a0, $a0, $t0","#>");
			break;
		case LESSTHAN:
			emit(f,"","slt $a0, $a0, $t0","#<");
			break;
		default: printf("relop not implemented in emitexpr");
	}//switch
}
//pre: pointer to ID node
//produce mips code so $a0 is address of where ID is in mem
void emitID(FILE * f, ASTnode * p){
	char s[100];
	if (p->symbol->level == 0){
		sprintf(s, "la $a0, %s", p->name);
		emit(f, "", s, "#globals");
	}
	else{
	//	printf("god is dead\n");
		sprintf(s, "add $a0, $sp, %d",p->symbol->offset * WSIZE);
	//	printf("god is dead\n");
		emit(f, "",s,"#ID is scaler");
		emit(f, "","","");
	}
}
void emitwrite(FILE * f, ASTnode * p){
	char s[100];
	if(p->s1 != NULL){
		emitexpr(f, p->s1);
		emit(f,"","li $v0 1","");
		emit(f,"","syscall","");
	}
	else{
		emit(f,"","li $v0 4","");
		sprintf(s, "la $a0, %s", p->label);
		emit(f, "",s,"#write a string");	
		emit(f,"","syscall","");
	}
}//emitwrite
void emitread(FILE * f, ASTnode * p){
	emitID(f, p->s1);
	emit(f, "", "li $v0, 5", "");
	emit(f, "", "syscall", "");
	emit(f, "", "sw $v0, ($a0)", "#store read into new location");
}
void emitassign(FILE * f, ASTnode * p){
	char s[100];
	emitexpr(f, p->s2);
	sprintf(s, "sw $a0, %d($sp)", p->symbol->offset * WSIZE);
	emit(f,"",s,"#move RHS into temp reg");
	emitID(f,p->s1);
	sprintf(s, "lw $t0, %d($sp)", p->symbol->offset * WSIZE);
	emit(f,"",s,"#do some fancy shit");
	emit(f,"","sw $t0, ($a0)","#more fancy");
}
void emitselect(FILE * f, ASTnode * p){
	printf("if is working");
	char * L1;
	char * L2;
	char s[100];
	L1 = genlabel();
	L2 = genlabel();
	emitexpr(f, p->s1);
	emit(f, "", "li $t0, 0", "#sets $t0 to 0");
        sprintf(s, "beq $a0, $0, %s", L1);
	emit(f,"",s,"#positive condition");
	emitast(f, p->s2->s1);
	sprintf(s,"j %s", L2);
	emit(f,"", s, "#positive done, jump out of conditional");
	emit(f,L1,"","#negative");
	emitast(f,p->s2->s2);
	emit(f,L2,"","#done");
}
void emitwhile (FILE * f, ASTnode * p){
	char s[100];
	char * L1;
	char * L2;
	L1 = genlabel();
	L2 = genlabel();
	emit(f,L1,"","#loop");
	emitexpr(f,p->s1);
	sprintf(s, "beq $a0, $0, %s", L2);
	emit(f,"",s,"#positive condition");
	emitast(f,p->s2);
	sprintf(s,"j %s",L1);
	emit(f,"",s,"#check if condition is still true, if yes, loop again");
	emit(f,L2,"","#another DO");
}
void emitast(FILE * f, ASTnode * p){
	if (p ==NULL){return;}
	char * L1;
	char * L2;
	switch(p->type){
		case VARDEC:
			break;
		case FUNDEC:
			emitfunctionhead(f,p);
			emitast(f,p->s2);
			emitreturn(f,NULL);
			break;
		case BLOCK:
			emitast(f, p->s2);
			break;
		case WRITESTMT:
			emitwrite(f,p);
			break;
		case READSTMT:
			emitread(f, p);
			break;
		case IFSTMT:
			emitselect(f,p);
			break;
		case ASSIGNSTMT:
			emitassign(f,p);
			break;
		case WHILESTMT:
			emitwhile(f,p);
			break;
		default : printf("emit ast type unimplemented\n");
	}//of switch
	emitast(f,p->next);
}//emitast
