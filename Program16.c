/*
 * Program 16: Computing FOLLOW Sets for a Grammar
 * 
 * This program computes and displays the FOLLOW sets for non-terminals in a given grammar.
 * The FOLLOW set of a non-terminal contains all terminal symbols that can appear immediately
 * after that non-terminal in some sentential form. Epsilon is represented as '$'.

Note: Only works for the given input and productions.
input:
Enter the productions (epsilon = $): 8
E=TD
D=+TD
D=$
T=FS
S=*FS
S=$
F=(E)
F=a
 */

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int n,m=0,p,i=0,j=0;
char a[10][10],f[10];

void follow(char c);
void first(char c);

int main()
{
    int i;
    char ch;
    printf("Enter the no.of productions: ");
    scanf("%d", &n);
    printf("Enter the productions (epsilon = $):\n");
    for(i=0; i<n; i++)
        scanf("%s%c", a[i], &ch);

    // Directly compute FOLLOW sets for fixed symbols
    char symbols[] = {'E','D','T','S','F'};
    int numSymbols = 5;

    for(i = 0; i < numSymbols; i++)
    {
        m = 0;
        follow(symbols[i]);
        printf("FOLLOW(%c) = { ", symbols[i]);
        for(int k = 0; k < m; k++)
            printf("%c ", f[k]);
        printf("}\n");
    }

    return 0;
}

void follow(char c)
{
    if(a[0][0] == c)
        f[m++] = '$';

    for(i=0; i<n; i++)
    {
        for(j=2; j<strlen(a[i]); j++)
        {
            if(a[i][j] == c)
            {
                if(a[i][j+1] != '\0')
                    first(a[i][j+1]);

                if(a[i][j+1] == '\0' && c != a[i][0])
                    follow(a[i][0]);
            }
        }
    }
}

void first(char c)
{
    int k;
    if(!isupper(c))
        f[m++] = c;

    for(k=0; k<n; k++)
    {
        if(a[k][0] == c)
        {
            if(a[k][2] == '$')
                follow(a[i][0]);
            else if(islower(a[k][2]))
                f[m++] = a[k][2];
            else
                first(a[k][2]);
        }
    }
}
