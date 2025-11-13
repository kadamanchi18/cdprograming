/*
 * Program 14: YACC Top-Down Parser for Arithmetic Expressions
 * 
 * This YACC program implements a top-down parser for arithmetic expressions
 * using a grammar after eliminating left recursion.
 * Grammar:
 *   E  -> T E'
 *   E' -> + T E' | ε
 *   T  -> F T'
 *   T' -> * F T' | ε
 *   F  -> ( E ) | id
 * 
 * The parser validates expressions containing addition (+), multiplication (*),
 * parentheses, and the terminal symbol 'id'.
 */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex();
%}

%token ID PLUS STAR LPAREN RPAREN

%%

line: E '\n' { printf("Valid Expression\n"); exit(0); }
    ;

E: T E_Prime
    ;

E_Prime: PLUS T E_Prime
       | /* epsilon */
       ;

T: F T_Prime
    ;

T_Prime: STAR F T_Prime
       | /* epsilon */
       ;

F: LPAREN E RPAREN
 | ID
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
}

int main() {
    printf("Enter an expression: ");
    yyparse();
    return 0;
}

