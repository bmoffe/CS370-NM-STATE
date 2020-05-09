#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "emit.h"
#include "ast.h"
//Brianna Moffett
//CS370
//05.08.20
//emit.c
static int GLABEL = 0;
char * currfunction;

char * genlabel(){//generates temporary label for if and while statements
	char s[100];
	char * s1;
	sprintf(s, "L%d",GLABEL++);
	s1 = strdup(s);
	return s1;
}//genlabel
/* PRE: ptr to astnode
 * POST: prints all strings in MIPS format
 */
void emitstrings(FILE * f, ASTnode * p){
	if (p == NULL){return;}//if no strings left that are global, return
	if ((p->type == WRITESTMT) && (p->name !=NULL)){
		fprintf(f,"%s:\t.asciiz\t%s\n",p->label,p->name);
	}//if
	emitstrings(f,p->next);//emit the next global string
	emitstrings(f,p->s1);
	emitstrings(f,p->s2);
}//emitstrings
/* PRE: pointer to ASTnode
 * POST: returns global variables
 */
void emitglobals(FILE * f, ASTnode *p){
	if (p == NULL){return;}//if there are no more globals, return
	if ((p->type == VARDEC) && (p->symbol->level == 0)){
		fprintf(f,"%s:\t .space\t%d\n",p->name,p->symbol->mysize*WSIZE);
	}
	emitglobals(f,p->next);//emit the next global
	emitglobals(f,p->s1);
}//emitglobals
//we're gonna make our code all fancy-like by taking in 4 params, and doing formatting pushups
//PRE: 3 strings, print in assembly format in file
//	i.e.: emit(file, "L1", "add r19, r20", "#add registers 19 and 20");
//	turns up
//POST:		L1:		add r19, r20	#add registers 19 and 20
void emit(FILE * f, char * label,  char * command, char * comment){
	if(strcmp("",label)==0){fprintf(f,"\t\t%s\t\t%s\n",command,comment);}
	else{fprintf(f,"%s:\t\t%s\t\t%s\n",label,command,comment);}
}
/* PRE: pointer to ASTnode 
 * POST: emits function head for main and other functions
 */
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
/* PRE: pointer to ASTnode
 * POST: emits return statement for functions
 */
void emitreturn(FILE * f, ASTnode * p){
	if(p != NULL){
		emitexpr(f,p);
	}//if
	emit(f,"","lw $ra, 4($sp)","#restore ra");
	emit(f,"","lw $sp, ($sp)", "#restore sp");
	if(strcmp(currfunction , "main") == 0){//need to do things differently if it's main
		emit(f,"", "li $v0, 10","#leave main");
		emit(f,"","syscall","#terminate main");
	}//if
}//emitreturn
/* PRE: pointer to ASTnode
 * POST: emits expression statement in MIPS
 */
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
	sprintf(s, "sw $a0, %d($sp)", p->symbol->offset * WSIZE);//storing offset * WSIZE in $a0 register
	emit(f,"",s,"#store LHS in temp");//LHS
	if(p->s2 != NULL){//move RHS to temp register; we will handle it recursively later
		emitexpr(f, p->s2);
		sprintf(s, "move $t0, $a0");
		emit(f, "", s, "#move RHS to temp reg");
	}//if
	sprintf(s, "lw $a0, %d($sp)", p->symbol->offset * WSIZE);
	emit(f, "",s,"#load LHS for relop");
	switch(p->operator){//perform different MIPS actions for different operators
		case PLUS://addition
			sprintf(s,"add $a0, $a0, $t0");
			emit(f, "", s, "#add");
			break;
		case MINUS://subtraction
			sprintf(s,"sub $a0, $a0, $t0");
			emit(f,"",s,"#subtraction");
			break;
		case MULTI://multiply
			sprintf(s,"mult $a0, $t0");
			emit(f,"",s,"#multi");
			emit(f,"","mflo $a0","#grab product");
			break;
		case DIV://division
			sprintf(s, "div $a0, $t0");
			emit(f, "",s,"#div");
			emit(f,"","mflo $a0","#grab result");
			break;
		case MYAND://and
			sprintf(s,"and $a0, $t0, $a0");
			emit(f,"",s,"#and");
			break;
		case MYOR://or
			sprintf(s,"or $a0, $t0, $a0");
			emit(f,"",s,"#or");
			break;
		case MYNOT://not
			emit(f,"","sltiu $a0, $a0, 1", "#not");
			break;
		case EQUAL://equal to
			emit(f,"","seq $a0, $a0, $t0","#==");
			break;
		case NOTEQUAL://not equal to
			emit(f,"","seq $a0, $a0, $t0","#!=");
			emit(f,"","sltiu $a0, $a0, 1","#inverse");
			break;
		case GREATERTHANEQ://greater than or equal to
			emit(f,"","sge $a0, $a0, $t0","#>=");
			break;
		case LESSTHANEQ://less than or equal to
			emit(f,"","sle $a0, $a0, $t0","#<=");
			break;
		case GREATERTHAN://greater than
			emit(f,"","sgt $a0, $a0, $t0","#>");
			break;
		case LESSTHAN://less than
			emit(f,"","slt $a0, $a0, $t0","#<");
			break;
		default: printf("relop not implemented in emitexpr");
	}//switch
}//emitexpr
//PRE: pointer to ID node
//POST: emits mips code so $a0 is address of where ID is in mem
void emitID(FILE * f, ASTnode * p){
	char s[100];
	emit(f,"","","");//a newline, for formatting reasons
	if (p->s1 == NULL){//if ID is not an array, emit scaler ID
		if (p->symbol->level == 0){
			sprintf(s, "la $a0, %s", p->name);
			emit(f, "", s, "#global scaler");
		}//if
		else {
			sprintf(s,"add $a0, $sp, %d",p->symbol->offset * WSIZE);
			emit(f,"",s,"#ID is scaler");
		}//else
	}//if
	else{//the ID is an array, do some pushups to figure array size in MIPS
		emitexpr(f,p->s1);
		sprintf(s,"sll $t0, $a0, %d",LOGWSIZE);//logical shift left to get size taken care of
		emit(f,"",s,"");
		if(p->symbol->level == 0){
			sprintf(s,"la $a0, %s",p->name);//array is global, emit it
			emit(f,"",s,"#ID is global array");
			emit(f,"","add $a0, $a0, $t0","");
		}//if
		else{
			sprintf(s,"add $a0, $sp, %d",p->symbol->offset * WSIZE);//array is local, emit it
			 emit(f,"",s,"#ID is local array");
			emit(f,"","add $a0, $a0, $t0","");
		}//else
	}//else		
}//emitID
/* PRE: pointer to ASTnode
 * POST: emits MIPS code to output ID, number, or string to the screen
 */
void emitwrite(FILE * f, ASTnode * p){
	char s[100];
	if(p->s1 != NULL){//we are writing a number here
		emitexpr(f, p->s1);
		emit(f,"","li $v0 1","");
		emit(f,"","syscall","");
	}//if
	else{
		emit(f,"","li $v0 4","");//we are writing a string here
		sprintf(s, "la $a0, %s", p->label);
		emit(f, "",s,"#write a string");	
		emit(f,"","syscall","");
	}//else
}//emitwrite
/* PRE: pointer to ASTnode
 * POST: emits read statement in MIPS, enables user to input number or string
 */
void emitread(FILE * f, ASTnode * p){
	emitID(f, p->s1);
	emit(f, "", "li $v0, 5", "");
	emit(f, "", "syscall", "");
	emit(f, "", "sw $v0, ($a0)", "#store read into new location");
}//emitread
/* PRE: pointer to ASTnode
 * POST: emits assignment statement in MIPS
 */
void emitassign(FILE * f, ASTnode * p){
	char s[100];
	emitexpr(f, p->s2);
	sprintf(s, "sw $a0, %d($sp)", p->symbol->offset * WSIZE);
	emit(f,"",s,"#move RHS into temp reg");
	emitID(f,p->s1);
	sprintf(s, "lw $t0, %d($sp)", p->symbol->offset * WSIZE);
	emit(f,"",s,"#do some fancy");
	emit(f,"","sw $t0, ($a0)","#more fancy");
}//emitassign
/* PRE: pointer to ASTnode
 * POST: emits selection statement in MIPS
 */
void emitselect(FILE * f, ASTnode * p){
	char * L1;
	char * L2;
	char s[100];
	L1 = genlabel();
	L2 = genlabel();
	emitexpr(f, p->s1);
	emit(f, "", "li $t0, 0", "#sets $t0 to 0");
        sprintf(s, "beq $a0, $0, %s", L1);
	emit(f,"",s,"#positive condition");//if positive, perform action at positive condition
	emitast(f, p->s2->s1);
	sprintf(s,"j %s", L2);
	emit(f,"", s, "#positive done, jump out of conditional");
	emit(f,L1,"","#negative");//if negative, perform action at negative condition
	emitast(f,p->s2->s2);
	emit(f,L2,"","#done");
}//emitselect
/* PRE: pointer to ASTnode
 * POST: emits iterative loop (WHILE) in MIPS
 */
void emitwhile (FILE * f, ASTnode * p){
	char s[100];
	char * L1;
	char * L2;
	L1 = genlabel();
	L2 = genlabel();
	emit(f,L1,"","#loop");//and so, our loop begins
	emitexpr(f,p->s1);
	sprintf(s, "beq $a0, $0, %s", L2);
	emit(f,"",s,"#positive condition");
	emitast(f,p->s2);
	sprintf(s,"j %s",L1);//true condition
	emit(f,"",s,"#check if condition is still true, if yes, loop again");
	emit(f,L2,"","#another DO");
}//emitwhile
/* PRE: pointer to ASTnode
 * POST: emits AST; calls other functions within the tree to emit different portions of MIPS code
 */
void emitast(FILE * f, ASTnode * p){
	if (p ==NULL){return;}//tree is mull, return
	switch(p->type){//switch statement goes through the node and figures out what it's type is, then calls function to emit MIPS code
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
	emitast(f,p->next);//recursive call to emit AST
}//emitast
