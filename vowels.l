%{
#include<stdio.h>
%}

vow [aeiouAEIOU]
cons [qwrtypsdfghjklzxcvbnmQWRTYPSDFGHJKLZXCVBNM]

%%

{vow} {printf("%s is a vowel\n",yytext);}
{cons} {printf("%s is a consonent\n",yytext);}
. {printf("%s is neither v or c",yytext);}
%%

int yywrap()
{
    return 0;
}

void main()
{
    yylex();
}