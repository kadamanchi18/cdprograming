//first fn
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

char production[MAX][50];
int n;

// To avoid infinite recursion on left recursion
int visited[26];  // For non-terminals A-Z

void addToResultSet(char *result, char val);
void findFirst(char *result, char c);
void findFirstOfString(char *result, char *str);

int main() {
    int i;
    char choice;
    char c;
    char result[50];

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (e.g., E->E+T|T):\n");
    for (i = 0; i < n; i++) {
        scanf("%49s", production[i]);
    }

    do {
        printf("\nFind FIRST of: ");
        scanf(" %c", &c);
        for (i = 0; i < 26; i++) visited[i] = 0;  // reset visited before each query
        strcpy(result, "");
        findFirst(result, c);
        printf("FIRST(%c) = { ", c);
        for (i = 0; result[i] != '\0'; i++) {
            printf("%c ", result[i]);
        }
        printf("}\n");
        printf("\nFind FIRST of another symbol? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

void addToResultSet(char *result, char val) {
    int k;
    for (k = 0; result[k] != '\0'; k++) {
        if (result[k] == val) return;
    }
    result[k] = val;
    result[k + 1] = '\0';
}

void findFirst(char *result, char c) {
    int i;

    // If terminal or epsilon, add and return
    if (!isupper(c)) {
        addToResultSet(result, c);
        return;
    }

    // If already visited, return to prevent infinite recursion
    if (visited[c - 'A']) {
        return;
    }
    visited[c - 'A'] = 1;

    // For each production starting with c
    for (i = 0; i < n; i++) {
        if (production[i][0] == c) {
            char *ptr = strchr(production[i], '>');
            if (ptr == NULL) continue;
            char *rhs = ptr + 1;
            char alt[50];
            int j = 0, k;

            for (k = 0;; k++) {
                if (rhs[k] == '|' || rhs[k] == '\0') {
                    alt[j] = '\0';
                    findFirstOfString(result, alt);
                    j = 0;
                    if (rhs[k] == '\0') break;
                } else {
                    alt[j++] = rhs[k];
                }
            }
        }
    }

    visited[c - 'A'] = 0;  // reset visited for other calls
}

void findFirstOfString(char *result, char *str) {
    char temp[50];
    int i = 0;
    int epsilonFound;

    while (str[i] != '\0') {
        strcpy(temp, "");
        findFirst(temp, str[i]);

        for (int k = 0; temp[k] != '\0'; k++) {
            if (temp[k] != '$') {
                addToResultSet(result, temp[k]);
            }
        }

        epsilonFound = strchr(temp, '$') != NULL;
        if (!epsilonFound)
            return;

        i++;
    }

    addToResultSet(result, '$');
}
