#include <stdio.h>
#include <string.h>
#define MAX 1000

typedef struct Operation {
    char action;
    char value;
} Operation;

typedef struct Stack {
    Operation data[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, Operation op) {
    if (!isFull(s)) {
        s->data[++s->top] = op;
    }
}

Operation pop(Stack* s) {
    Operation op = {'\0', '\0'};
    if (!isEmpty(s)) {
        op = s->data[s->top--];
    }
    return op;
}

int main() {
    char text[MAX] = "";
    Stack undoStack, redoStack;
    initStack(&undoStack);
    initStack(&redoStack);

    int choice;
    char ch;

    while (1) {
        printf("\n——————————— TEXT EDITOR ———————————\n");
        printf("1. INSERT\n");
        printf("2. UNDO\n");
        printf("3. REDO\n");
        printf("4. HIEN THI\n");
        printf("5. THOAT\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        getchar();
        if (choice == 1) {
                printf("Nhap ky tu can chen: ");
                scanf("%c", &ch);
                int len = strlen(text);
                text[len] = ch;
                text[len + 1] = '\0';
                Operation op = {'I', ch};
                push(&undoStack, op);
                initStack(&redoStack);
        }
        else if (choice == 2) {
            if (!isEmpty(&undoStack)) {
                Operation op = pop(&undoStack);
                int len = strlen(text);
                if (len > 0) {
                    text[len - 1] = '\0';
                }
                push(&redoStack, op);
            } else {
                printf("Khong co thao tac de UNDO\n");
            }
        }
        else if (choice == 3) {
            if (!isEmpty(&redoStack)) {
                Operation op = pop(&redoStack);
                int len = strlen(text);
                text[len] = op.value;
                text[len + 1] = '\0';
                push(&undoStack, op);
            } else {
                printf("Khong co thao tac de REDO");
            }
        }
        else if (choice == 4) {
            printf("Van ban hien tai: %s\n", text);
        }
        else if (choice == 5) {
            printf("Thoat chuong trinh");
            break;
        }
        else {
            printf("Lua chon khong hop le");
        }
    }

    return 0;
}