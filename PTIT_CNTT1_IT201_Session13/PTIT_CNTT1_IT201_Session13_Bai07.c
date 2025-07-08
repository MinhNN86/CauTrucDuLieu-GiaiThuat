#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Stack {
    char* data;
    int top;
    int cap;
} Stack;

Stack createStack(int size) {
    Stack s;
    s.data = (char*)malloc(size * sizeof(char));
    s.top = -1;
    s.cap = size;
    return s;
}

void push(Stack* s, char c) {
    if (s->top < s->cap - 1) {
        s->data[++(s->top)] = c;
    }
}

char pop(Stack* s) {
    if (s->top == -1) return '\0';
    return s->data[(s->top)--];
}

char peek(Stack* s) {
    if (s->top == -1) return '\0';
    return s->data[s->top];
}

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isValidExpression(const char* expr) {
    Stack s = createStack(strlen(expr));
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c == '(' || c == '[' || c == '{') {
            push(&s, c);
        } else if (c == ')' || c == ']' || c == '}') {
            char top = peek(&s);
            if (s.top == -1 || !isMatching(top, c)) {
                free(s.data);
                return false;
            }
            pop(&s);
        }
    }
    bool result = (s.top == -1);
    free(s.data);
    return result;
}

int main() {
    char expr[200];
    printf("Nhap bieu thuc: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strlen(expr) - 1] = '\0';

    if (isValidExpression(expr)) {
        printf("Bieu thu hop le\n");
    } else {
        printf("Bieu thuc khong hop le\n");
    }

    return 0;
}