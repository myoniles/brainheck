%option noyywrap
%{
#include <stdio.h>
#include "parser.h"
%}
%option yylineno
%%

[\n\t\r ] {}

"+" { return INC; }
"-" { return DEC; }
"[" { return FOR; }
"]" { return END; }
"." { return PRINT; }
"'" { return READ; }
MEM=[0-9]* { return MEMOP; }

.* {}

%%
