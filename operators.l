%{
#include<stdio.h>
%}

opera (\+|\-|\*|\/|&&|=|==|<|>|<=|>=|!=|^|~|\+\+|\-\-|<<|>>)

%%

{opera} {printf("%s is an oper\n",yytext);}
. {printf("%s is not an op\n",yytext);}

%%

int yywrap()
{
    return 0;
}

void main()
{
    yylex();
}