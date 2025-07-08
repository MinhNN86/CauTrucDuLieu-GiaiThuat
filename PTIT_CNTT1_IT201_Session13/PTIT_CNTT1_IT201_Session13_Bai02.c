#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int* data;
    int top;
    int maxSize;
} Stack;

Stack createStack(int maxSizeStack) {
    Stack temp;
    temp.data = (int*)malloc(maxSizeStack * sizeof(int));
    temp.top = -1;
    temp.maxSize = maxSizeStack;
    return temp;
}

int isFull(Stack* stack) {
    if (stack->top == stack->maxSize - 1) {
        return 1;
    }
    return 0;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack da day");
        return;
    }
    stack->top++;
    stack->data[stack->top] = value;
}

void freeStack(Stack* stack) {
    free(stack->data);
    stack->data = NULL;
}

int main() {
    Stack stack = createStack(5);
    int value;

    printf("Nhap cac phan tu: \n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &value);
        push(&stack, value);
    }

    printf("stack={\n   element: [");
    for (int i = 0; i <= stack.top; i++) {
        printf("%d", stack.data[i]);
        if (i != stack.top) {
            printf(", ");
        }
    }
    printf("],\n   top: %d,\n   cap: %d\n}", stack.top, stack.maxSize);

    freeStack(&stack);
    return 0;
}