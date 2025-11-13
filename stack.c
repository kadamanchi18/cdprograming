//Stack CD
#include <stdio.h>
#include <string.h>

#define MAX 10


struct Frame {
    char function[20];
    char locals[30];
};


struct Frame stack[MAX];
int top = -1;


void push(char func[], char vars[]) {
    if (top == MAX - 1) {
        printf("\nStack Overflow!\n");
        return;
    }
    top++;
    strcpy(stack[top].function, func);
    strcpy(stack[top].locals, vars);
    printf("\nFunction '%s' called — frame pushed.\n", func);
}


void pop() {
    if (top == -1) {
        printf("\nStack Underflow!\n");
        return;
    }
    printf("\nFunction '%s' ended — frame popped.\n", stack[top].function);
    top--;
}


void display() {
    if (top == -1) {
        printf("\nStack is empty.\n");
        return;
    }
    printf("\nCurrent Stack (Top to Bottom):\n");
    for (int i = top; i >= 0; i--) {
        printf("Function: %s | Locals: %s\n", stack[i].function, stack[i].locals);
    }
}

int main() {
    int choice;
    char func[20], vars[30];

    printf("=== Stack Allocation Simulation ===\n");

    while (1) {
        printf("\n1. Call Function (Push)\n2. Return Function (Pop)\n3. Display Stack\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter Function Name: ");
            scanf("%s", func);
            printf("Enter Local Variables: ");
            scanf("%s", vars);
            push(func, vars);
        } 
        else if (choice == 2) {
            pop();
        } 
        else if (choice == 3) {
            display();
        } 
        else if (choice == 4) {
            printf("\nProgram Ended.\n");
            break;
        } 
        else {
            printf("\nInvalid choice!\n");
        }
    }

    return 0;
}