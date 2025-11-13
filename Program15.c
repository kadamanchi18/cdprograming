/*
 * Program 15: Lexical Analyzer Implementation in C
 * 
 * This program implements a lexical analyzer that reads from a file and identifies
 * different types of tokens: keywords, identifiers, operators, and numbers.
 * It processes C-like code and classifies each token appropriately.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char buffer[]) {
    char keywords[32][10] = {
        "auto", "break", "case", "char", "const",
        "continue", "default", "do", "double", "else",
        "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while"
    };
    
    int i;
    for (i = 0; i < 32; i++) {
        if (strcmp(keywords[i], buffer) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char ch, buffer[15];
    char operators[] = "+-*/%=";
    FILE *fp;
    int i, j = 0;
    
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening the file\n");
        exit(0);
    }
    
    printf("Tokens found:\n");
    
    while ((ch = fgetc(fp)) != EOF) {
        // Check for operators
        for (i = 0; i < strlen(operators); ++i) {
            if (ch == operators[i]) {
                printf("Operator: '%c'\n", ch);
                break;
            }
        }
        
        // Handle alphanumeric characters (letters and digits)
        if (isalnum(ch)) {
            buffer[j++] = ch;
        }
        // Handle whitespace - process accumulated token
        else if ((ch == ' ' || ch == '\n' || ch == '\t') && (j != 0)) {
            buffer[j] = '\0';
            j = 0;
            
            if (isKeyword(buffer) == 1) {
                printf("Keyword: %s\n", buffer);
            } else {
                printf("Identifier: %s\n", buffer);
            }
        }
        // Handle digits (though this is logically unreachable due to isalnum check above)
        else if (isdigit(ch)) {
            printf("Number: %c\n", ch);
        }
        // Handle other characters (parentheses, semicolons, etc.)
        else if (ch != ' ' && ch != '\n' && ch != '\t') {
            if (j != 0) {
                buffer[j] = '\0';
                j = 0;
                if (isKeyword(buffer) == 1) {
                    printf("Keyword: %s\n", buffer);
                } else {
                    printf("Identifier: %s\n", buffer);
                }
            }
            printf("Special symbol: '%c'\n", ch);
        }
    }
    
    // Process any remaining token in buffer
    if (j != 0) {
        buffer[j] = '\0';
        if (isKeyword(buffer) == 1) {
            printf("Keyword: %s\n", buffer);
        } else {
            printf("Identifier: %s\n", buffer);
        }
    }
    
    fclose(fp);
    return 0;
}

