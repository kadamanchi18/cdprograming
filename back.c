#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;

// Utility: match a character
int match(char c) {
    if (input[pos] == c) {
        pos++;
        return 1;
    }
    return 0;
}

// A → "ab" | "a"
int A() {
    int backup = pos;

    if (match('a') && match('b'))  // try "ab"
        return 1;

    pos = backup;  // backtrack
    if (match('a'))               // try "a"
        return 1;

    pos = backup;  // reset
    return 0;
}

// C → "c"
int C() {
    return match('c');
}

// S → C A "d" "#"
int S() {
    int backup = pos;

    if (C() && A() && match('d') && match('#'))
        return 1;

    pos = backup;  // reset
    return 0;
}

int main() {
    printf("Enter string: ");
    scanf("%s", input);

    if (S() && input[pos] == '\0')
        printf("Accepted ✅\n");
    else
        printf("Rejected ❌\n");

    return 0;
}
