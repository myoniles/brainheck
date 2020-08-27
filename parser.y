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

%token FOR END PRINT READ VAL POS

%type <value> VAL POS
%type <list> StatementList
%type <exp> Statement Loop

%%
Program: StatementList{
	if ($1 != NULL)
		$1->traverse();
	}
	;
StatementList: StatementList Statement { $$ = new AstListNode($2, $1); }
	| {$$=NULL;}
	;
Statement
	: READ	{ $$ = new AstReadNode(); }
	| PRINT { $$ = new AstPrintNode(); }
	| POS   { $$ = new AstPositionNode($1); }
	| VAL   { $$ = new AstValueNode($1); }
	| Loop
	;
Loop
	: FOR StatementList	END { $$ =  new AstLoopNode($2); }
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
