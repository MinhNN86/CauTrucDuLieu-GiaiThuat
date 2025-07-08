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

void freeStack(Stack* stack) {
    free(stack->data);
    stack->data = NULL;
}

int main() {
    Stack stack = createStack(5);
    freeStack(&stack);
    return 0;
}