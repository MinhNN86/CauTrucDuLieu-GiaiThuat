#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct Operation {
    char url[MAX];
    char timeStamp[MAX];
} Operation;

typedef struct Node {
    Operation data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void initStack(Stack* s) {
    s->top = NULL;
}

int isEmpty(Stack* s) {
    return s->top == NULL;
}

void push(Stack* s, Operation op) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = op;
    newNode->next = s->top;
    s->top = newNode;
}

Operation pop(Stack* s) {
    if (isEmpty(s)) {
        Operation empty = {"", ""};
        return empty;
    }
    Node* temp = s->top;
    Operation op = temp->data;
    s->top = temp->next;
    free(temp);
    return op;
}

void clearStack(Stack* s) {
    while (!isEmpty(s)) {
        pop(s);
    }
}

int main() {
    Stack backStack, forwardStack;
    initStack(&backStack);
    initStack(&forwardStack);

    int choice;
    Operation current = {"", ""};

    do {
        printf("\n______WEB HISTORY_____\n");
        printf("1. VISIT url: Truy cap vao trang web moi\n");
        printf("2. BACKWARD: Quay lai trang truoc\n");
        printf("3. FORWARD: Di den trang sau neu tung bi back\n");
        printf("4. CURRENT: In trang web hien tai\n");
        printf("5. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        getchar(); // Xóa ký tự Enter

        if (choice == 1) {
            Operation newOp;
            printf("Nhap URL: ");
            fgets(newOp.url, MAX, stdin);
            newOp.url[strcspn(newOp.url, "\n")] = '\0';

            printf("Nhap thoi diem truy cap: ");
            fgets(newOp.timeStamp, MAX, stdin);
            newOp.timeStamp[strcspn(newOp.timeStamp, "\n")] = '\0';

            if (strlen(current.url) > 0) {
                push(&backStack, current);
            }

            current = newOp;
            clearStack(&forwardStack);

            printf("Da truy cap: %s luc %s\n", current.url, current.timeStamp);

        } else if (choice == 2) {
            if (isEmpty(&backStack)) {
                printf("Khong the quay lai!\n");
            } else {
                push(&forwardStack, current);
                current = pop(&backStack);
                printf("Da quay lai trang: %s luc %s\n", current.url, current.timeStamp);
            }

        } else if (choice == 3) {
            if (isEmpty(&forwardStack)) {
                printf("Khong the tien toi!\n");
            } else {
                push(&backStack, current);
                current = pop(&forwardStack);
                printf("Da tien toi trang: %s luc %s\n", current.url, current.timeStamp);
            }

        } else if (choice == 4) {
            if (strlen(current.url) == 0) {
                printf("Chua co trang web nao dang mo.\n");
            } else {
                printf("Trang hien tai: %s (Truy cap luc %s)\n", current.url, current.timeStamp);
            }

        } else if (choice == 5) {
            printf("Tam biet!\n");
        } else {
            printf("Lua chon khong hop le!\n");
        }

    } while (choice != 5);

    clearStack(&backStack);
    clearStack(&forwardStack);

    return 0;
}