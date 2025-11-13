//expr.y top-dow parser
 %{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(void);
%}

%token ID
%token PLUS STAR LPAREN RPAREN

%%
line : E '\n'     { printf("Valid Expression\n"); }
     | '\n'
     ;

E : T E_Prime
  ;

E_Prime : PLUS T E_Prime
         | /* epsilon */
         ;

T : F T_Prime
  ;

T_Prime : STAR F T_Prime
         | /* epsilon */
         ;

F : LPAREN E RPAREN
  | ID
  ;
%%

void yyerror(const char *s) {
    fprintf(stderr, "yyerror: %s\n", s);
}

int main(void) {
    printf("Enter an expression: ");
    yyparse();
    return 0;
}
