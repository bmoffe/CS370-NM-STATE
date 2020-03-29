#include <stdio.h>
#include <malloc.h>
#ifndef AST_H
#define AST_H
enum ASTtype
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
enum OPERATORS{
	PLUS,
	MINUS,
	MULTI,
	DIV,
	MOD,
	INTDEC,
	VOIDDEC,
	BOOLDEC,
	LESSTHANEQ,
	GREATERTHANEQ,
	LESSTHAN,
	GREATERTHAN,
	EQUAL,
	NOTEQUAL,
};
typedef struct ASTnodetype{
	enum ASTtype type;
	enum OPERATORS operator;
	char * name;
	int value;
	struct ASTnodetype *next;
	struct ASTnodetype *s1, *s2;
} ASTnode;
void ASTprint(ASTnode *p, int level);
ASTnode *ASTcreatenode(enum ASTtype newtype);
void ASThitchleft(ASTnode *p, ASTnode *q);
ASTnode *program;
#endif
