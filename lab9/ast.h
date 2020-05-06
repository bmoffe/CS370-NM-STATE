#include <stdio.h>
#include <malloc.h>
#ifndef AST_H
#define AST_H

enum ASTtype //list of nodes that we can create from the semantic action in YACC file
{
	VARDEC,
	FUNDEC,
	PROGRAM,
	PARAM,
	INTTYPE,
	VOIDTYPE,
	BOOLTYPE,
	IDENTIFIER,
	BLOCK,
	EXPRSTMT,
	ASSIGNSTMT,
	IFSTMT,
	IFELSE,
	WHILESTMT,
	READSTMT,
	WRITESTMT,
	RETURNSTMT,
	EXPR,
	CALL,
	NUMBER,
	ARGSLIST,
};
enum OPERATORS{ //list of operators that can be associated with variables, functions, etc
	PLUS,
	MINUS,
	MULTI,
	DIV,
	MOD,
	INTDEC,
	VOIDDEC,
	BOOLDEC,
	MYNOT,
	MYAND,
	MYOR,
	LESSTHANEQ,
	GREATERTHANEQ,
	LESSTHAN,
	GREATERTHAN,
	EQUAL,
	NOTEQUAL,
};
typedef struct ASTnodetype{ //defining the ASTnode structure
	enum ASTtype type;
	enum OPERATORS operator;
	enum OPERATORS semtype;
	char * name;
	char * label;
	int value;
	struct SymbTab * symbol;
	struct ASTnodetype *next;
	struct ASTnodetype *s1, *s2;
} ASTnode;
void ASTprint(ASTnode *p, int level); //ast print
ASTnode *ASTcreatenode(enum ASTtype newtype); //astcreatenode
ASTnode *program; //program node that we feed to ASTprint in YACC main
#endif
