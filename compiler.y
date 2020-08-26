%code requires {
	#define DEFAULT_MEM 30000
	#include "AST.h"
}

%{
#include <stdio.h>

int yylex();
void yyerror(const char* s);
extern int yylineno;

%}

%union{
	int value;
	AstListNode* list;
	AstNode* exp;
}

%start Program

%token INC DEC FOR END PRINT READ LEFT RIGHT

%%
Program: StatementList
	;
StatementList: StatementList Statement
	| Statement
	;
Statement
	: Observant
	| ValChange
	;
Observant
	: READ
	| PRINT
	| Loop
	;
ValChange
	: PosList ValList
	;
PosList
	: PosList Pos
	|
	;
ValList
	: ValList Val
	| Val
	;
Pos
	: LEFT
	| RIGHT
	;
Val
	: INC
	| DEC
	;
Loop
	: FOR StatementList	END
	;
%%
extern FILE* yyin;
main( int argc, char** argv)
{
	FILE *myfile = fopen(argv[1], "r");
	if (!myfile)
		return(yyparse());
	yyin = myfile;
	do { yyparse();} while(!feof(yyin));
}

void yyerror( const char* s)
{
	//fprintf(stderr, "%s on line %d\n", s, yylineno);
	fprintf(stderr, "Syntax errors in line %d\n", yylineno);
	exit(-1);
}
