%{
#include <stdio.h>
#include <string.h>
%}

digit   [0-9]
letter  [a-zA-Z]

%%

"//".*                        { printf("%s is a single-line comment\n", yytext); }

"/*"([^*]|[*][^/])*"*/"       { printf("%s is a multi-line comment\n", yytext); }

{letter}({letter}|{digit})*\( {
                                 char na[100];
                                 strncpy(na, yytext, yyleng-1);  // copy without '('
                                 na[yyleng-1] = '\0';
                                 printf("%s is a function\n", na);
                              }

.|\n                          { ; }   

%%

int yywrap() { return 0; }

int main() {
    yylex();
    return 0;
}
