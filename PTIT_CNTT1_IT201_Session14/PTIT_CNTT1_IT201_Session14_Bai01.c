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
    node->data = value;
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

int main() {
    Stack* stack = createStack();
    return 0;
}