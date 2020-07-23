%option noyywrap
%{
#include <stdio.h>
#include "parser.h"
%}
%option yylineno
%%

[\t\n ] {}

"+" {
	yylval.value = 1;
	return INC;
}
"-" {
	yylval.value = -1;
	return DEC;
}
">" {
	yylval.value = 1;
	return RIGHT;
}
"<" {
	yylval.value = -1;
	return LEFT;
}
"[" { return FOR; }
"]" { return END; }
"." { return PRINT; }
"'" { return READ; }

%%
