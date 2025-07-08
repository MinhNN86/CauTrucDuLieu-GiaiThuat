#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int* data;
    int top;
    int cap;
} Stack;

Stack createStack(int size) {
    Stack temp;
    temp.data = (int*)malloc(size*sizeof(int));
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

void daoNguocMang(int* arr, int n) {
    Stack stack = createStack(n);

    for (int i = 0; i < n; i++) {
        push(&stack, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = pop(&stack);
    }
    free(stack.data);
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    daoNguocMang(arr, n);

    for (int i = 0; i < n; i++) {
        if (i == 0) printf("[");
        printf("%d", arr[i]);
        if (i != n - 1) printf(", ");
    }
    printf("]\n");
    return 0;
}