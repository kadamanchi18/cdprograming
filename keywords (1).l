  GNU nano 6.2                        keu.l *                               %{
#include<stdio.h>
%}

Keyword auto|break|const|case|char|continue|do|double|default|else|enum|extorn|for|float|goto|if|int|long|return|register|short|switch|signed|sizeof|struct|static|typeof|union|unsigned|volatile|void|while
letter [a-z A-Z]
digit [0-9]


%%

{Keyword} {printf("%s is a keyword\n",yytext);}
({letter}|{digit})* {printf("%s is not a keyword\n",yytext);}


%%

int yywrap()
{
    return 0;
}

void main()
{
    yylex();
}
