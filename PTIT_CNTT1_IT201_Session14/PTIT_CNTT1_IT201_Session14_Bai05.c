#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        printf("Loi cap phat bo nho");
        exit(1);
    }
    node -> data = value;
    node -> next = NULL;
    return node;
}

typedef struct Stack {
    Node* top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        printf("Loi cap phat bo nho");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, int value) {
    Node* newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
}

void printStack(Stack* stack) {
    Node* current = stack->top;
    printf("stack={\n   ");
    while (current != NULL) {
        printf("%d->", current -> data);
        current = current -> next;
    }
    printf("NULL\n");
    printf("}\n");
}

int top(Stack* stack) {
    if (stack->top == NULL) {
        printf("Ngăn xếp trống\n");
        return -1;
    }
    return stack->top->data;
}

int main() {
    Stack* stack = createStack();

    push(stack, 5);
    push(stack, 4);
    push(stack, 3);
    push(stack, 2);
    push(stack, 1);

    printStack(stack);
    int topValue = top(stack);
    if (topValue != -1) {
        printf("%d", topValue);
    }

    return 0;
}