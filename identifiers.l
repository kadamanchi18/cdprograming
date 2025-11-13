%{
    #include<stdio.h>
%}

letter [a-z A-Z]
digit [0-9]

%%

{letter}({letter}|{digit})* {printf("%s is an identifier\n",yytext);}
{digit}({digit}|(letter))* {printf("%s is an identifier\n",yytext);}
. {printf("%s is not an identifier",yytext);}

%%

int yywrap()
{
    return 0;
}

void main()
{
    yylex()
}