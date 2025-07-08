#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    char* data;
    int top;
    int cap;
} Stack;

Stack createStack(int size) {
    Stack temp;
    temp.data = (char*)malloc(size*sizeof(char));
    temp.top = -1;
    temp.cap = size;
    return temp;
}

void push(Stack* stack, int value) {
    if (stack -> top >= stack -> cap - 1) {
        printf("Stack is full\n");
        return;
    }
    stack -> top++;
    stack -> data[stack -> top] = value;
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

int kiemTraDoiXung(char str[]) {
    int len = strlen(str);
    Stack stack = createStack(len);

    for (int i = 0; i < len / 2; i++) {
        push(&stack, str[i]);
    }
    int start;
    if (len % 2 == 0) {
        start = len / 2;
    } else {
        start = (len / 2) + 1;
    }
    for (int i = start; i < len; i++) {
        char topChar = pop(&stack);
        if (str[i] != topChar) {
            free(stack.data);
            return 0;
        }
    }

    free(stack.data);
    return 1;
}

int main() {
    char str[100];
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';

    if (kiemTraDoiXung(str)) {
        printf("true");
    } else {
        printf("false");
    }
    return 0;
}