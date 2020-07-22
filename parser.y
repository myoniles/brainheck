%{
#include <stdio.h>

int yylex();
void yyerror(const char* s);
extern int yylineno;
%}

%start Program

%token INC DEC FOR END PRINT READ MEMOP

%%
Program: MEMOP StatementList
	| StatementList
	;
StatementList: StatementList Statement |;
Statement
	: INC
	| DEC
	| READ
	| PRINT
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
