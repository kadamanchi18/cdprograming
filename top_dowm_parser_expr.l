//expr.l top-down parser

%{
#include "expr.tab.h"
#include <stdio.h>
%}

%%
"+"             { return PLUS; }
"*"             { return STAR; }
"("             { return LPAREN; }
")"             { return RPAREN; }
[a-zA-Z][a-zA-Z0-9]*   { return ID; }
[ \t]           { /* ignore spaces and tabs */ }
\n              { return '\n'; }
.               { yyerror("Invalid character"); }
%%

int yywrap(void) {
    return 1;
}/*
bison -d expr.y
flex expr.l
gcc expr.tab.c lex.yy.c -o expr
./expr
*/