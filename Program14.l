/*
 * Program 14: Lexical Analyzer for Arithmetic Expressions
 * 
 * This Lex program acts as a lexical analyzer for arithmetic expressions.
 * It recognizes tokens such as PLUS (+), STAR (*), LPAREN (( ), RPAREN ( )),
 * and identifiers (sequences of letters and numbers starting with a letter).
 * It is designed to be used in conjunction with the Yacc parser (Program14.y).
 */

%{
#include "y.tab.h"
#include <stdio.h>
extern void yyerror(const char *s);
%}

%%

"+"         { return PLUS; }
"*"         { return STAR; }
"("         { return LPAREN; }
")"         { return RPAREN; }
[a-zA-Z][a-zA-Z0-9]* { return ID; }
[ \t]+      { /* ignore spaces */ }
\n          { return '\n'; }
.           { yyerror("Invalid character"); }

%%

int yywrap() {
    return 1;
}

