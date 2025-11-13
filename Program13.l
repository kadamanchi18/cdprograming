/*
 * Program 13: Lex File for Yacc Calculator
 * 
 * This Lex program provides the lexical analyzer for the Yacc calculator.
 * It recognizes digits and returns the DIGIT token with its value.
 */

//Yacc with lex.l //

%{
 #include<stdio.h>
 #include "y.tab.h"
%}

%%
[0-9]+ {yylval.dval=atoi(yytext); return DIGIT;}
\n|. return yytext[0];
%%

