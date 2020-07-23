%option noyywrap
%{
#include <stdio.h>
#include "parser.h"
%}
%option yylineno
%%

\n {}
"+" { return INC; }
"-" { return DEC; }
">" { return LEFT; }
"<" { return RIGHT; }
"[" { return FOR; }
"]" { return END; }
"." { return PRINT; }
"'" { return READ; }

%%
