%code requires {
	#define DEFAULT_MEM 30000
}

%{
#include <stdio.h>

int yylex();
void yyerror(const char* s);
extern int yylineno;

char mem[30000] = {0};
char* ptr = mem;

void printbyte(char a){
	int i;
	for (i = 0; i < 8; i++) {
			printf("%d", !!((a << i) & 0x80));
	}
}
%}

%start Program

%token INC DEC FOR END PRINT READ LEFT RIGHT

%%
Program: StatementList;
StatementList: StatementList Statement
	|
	;
Statement
	: LEFT
	| RIGHT
	| INC
	| DEC
	| Loop
	| READ	{}
	| PRINT {}
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
