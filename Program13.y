/*
 * Program 13: Yacc Calculator with Lex
 * 
 * This Yacc program implements a calculator that evaluates arithmetic expressions
 * containing addition (+) and multiplication (*) operations with parentheses.
 * It uses a separate Lex file (Program13.l) for lexical analysis.
 * Grammar: E -> E+E/E*E/(E)/DIGIT
 */

//Yacc with lex.y //

%{
 /*E->E+E/E*E/(E)/DIGIT*/
%}

%union
 {
  int dval;
 }

%token <dval> DIGIT

%type <dval> expr
 %type <dval> term
%type <dval> factor

%%

line:expr '\n' {printf("%d",$1);exit(0);}
    ;

expr:expr '+' term {$$=$1+$3;}
    |term
    ;

term:term '*' factor {$$=$1*$3;}
    |factor
    ;

factor: '(' expr ')' {$$=$2;}
      |DIGIT
      ;

%%
int main()
 {
  yyparse();
 }

 yyerror(char *s)
 {
 printf("%s",s);
 }

