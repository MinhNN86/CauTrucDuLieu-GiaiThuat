#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int* data;
    int top;
    int maxSize;
} Stack;

Stack createStack(int maxSizeStack) {
    Stack temp;
    temp.data = (int*)malloc(maxSizeStack*sizeof(int));
    temp.top = -1;
    temp.maxSize = maxSizeStack;
    return temp;
}

int isFull(Stack* stack) {
    if (stack->top == stack->maxSize - 1) {
        printf("Stack is full");
        return 1;
    }
    return 0;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        return;
    }
    stack->top++;
    stack->data[stack->top] = value;
}

void viewStackData(Stack stack) {
    if (stack.top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    for (int i = stack.top; i >= 0; i--) {
        printf("%d\n", stack.data[i]);
    }
}

void printStack(Stack stack) {
    printf("stack = {\n  elements: [");
    for (int i = 0; i <= stack.top; i++) {
        printf("%d", stack.data[i]);
        if (i != stack.top) printf(", ");
    }
    printf("],\n  top: %d,\n  cap: %d\n}\n", stack.top, stack.maxSize);
}

void freeStack(Stack* stack) {
    free(stack -> data);
    stack -> data = NULL;
}

int main() {
    Stack stack = createStack(5);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    printStack(stack);
    printf("\n");
    viewStackData(stack);

    freeStack(&stack);

    return 0;
}