#include <stdio.h>
#include "stack.h"


void printStack(struct Stack* stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}


int main() {
    struct Stack* stack = createStack(100);
    push(stack, 10);
    push(stack, 10);
    push(stack, 10);
    push(stack, 10);
    printStack(stack);
    return 0;
}