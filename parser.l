%option noyywrap
%{
#include <stdio.h>
#include "parser.h"
%}
%option yylineno
%%

[\t\n ] {}

"+"+ {
	yylval.value = yyleng;
	return INC;
}
"-"+ {
	yylval.value = -1 * yyleng;
	return DEC;
}
">"+ {
	yylval.value = yyleng;
	return RIGHT;
}
"<"+ {
	yylval.value = -1 * yyleng;
	return LEFT;
}
"[" { return FOR; }
"]" { return END; }
"." { return PRINT; }
"'" { return READ; }

%%
