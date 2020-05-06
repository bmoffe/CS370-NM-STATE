#ifndef EMIT_H
#define EMIT_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>
#include "ast.h"
#include "symtable.h"

#define WSIZE 4
#define LOGWSIZE 2

char * genlabel();
void emitstrings(FILE * f, ASTnode * p);
void emitglobals(FILE * f, ASTnode * p);
void emitast(FILE * f, ASTnode * p);
void emitfunctionhead(FILE * f, ASTnode * p);
void emitreturn(FILE * f, ASTnode * p);
void emitwrite(FILE * f, ASTnode * p);
void emitexpr(FILE *f, ASTnode * p);
void emitID(FILE * f, ASTnode * p);
#endif
