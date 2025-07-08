#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    char* data;
    int top;
    int cap;
} Stack;

Stack createSteak(int size) {
    Stack temp;
    temp.data = (char*)malloc(size*sizeof(char));
    temp.top = -1;
    temp.cap = size;
    return temp;
}

void push(Stack* stack, int value) {
    if (stack->top >= stack->cap - 1) {
        printf("Stack is full\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = value;
}

int pop(Stack* stack) {
    if (stack -> top == -1) {
        printf("No element in stack");
        return -1;
    }
    int temp = stack -> data[stack->top];
    stack->top--;
    return temp;
}

void

int main() {

    return 0;
}