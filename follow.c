FOLLOW function
#include <stdio.h>
#include <string.h>

void calculateFollow(char nonTerminal, char followSet[]) {
    followSet[0] = '\0';
     switch (nonTerminal) {
        case 'E':
            strcat(followSet, "),$");
            break;
        case 'X':
            strcat(followSet, "),$");
            break;
        case 'T':
            strcat(followSet, "+,),$");
            break;
        case 'Y':
            strcat(followSet, "+,),$");
            break;
        case 'F':
            strcat(followSet, "*+,),$");
            break;
        default:
            break;
    }
}

int main() {
    char followSet[50];
    printf("FOLLOW Sets for the grammar:\n");
    calculateFollow('E', followSet);
    printf("FOLLOW(E)  = {%s}\n", followSet);
    calculateFollow('X', followSet);
    printf("FOLLOW(E') = {%s}\n", followSet);
    calculateFollow('T', followSet);
    printf("FOLLOW(T)  = {%s}\n", followSet);
    calculateFollow('Y', followSet);
    printf("FOLLOW(T') = {%s}\n", followSet);
    calculateFollow('F', followSet);
    printf("FOLLOW(F)  = {%s}\n", followSet);
    return 0;
}