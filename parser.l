%option noyywrap
%{
#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include "parser.h"
%}
%option yylineno
%%

[\t\n ] {}
[a-zA-Z0-9]* {}

("+"+|"-"+)+ {
	std::string str(yytext);
	int neg =
	yylval.value = yyleng - 2*std::count(str.begin(), str.end(), '-');
	return VAL;
}
(">"+|"<"+)+ {
	std::string str(yytext);
	yylval.value = yyleng - 2*std::count(str.begin(), str.end(), '<');
	return POS;
}
"[" { return FOR; }
"]" { return END; }
"." { return PRINT; }
"'" { return READ; }

%%
