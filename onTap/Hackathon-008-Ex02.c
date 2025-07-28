#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Request {
    int id;
    char issue[100];
    int priority;
} Request;

typedef struct Queue {
    Request data[MAX];
    int front;
    int rear;
} Queue;

Queue highQueue = {.front = 0, .rear = -1};
Queue lowQueue = {.front = 0, .rear = -1};
int globalId = 1;

int isEmpty(Queue* q) {
    return q->front > q->rear;
}
int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

void enQueue(Queue* q, Request r) {
    if (isFull(q)) {
        printf("Hang doi day");
        return;
    }
    q->rear++;
    q->data[q->rear] = r;
}

Request deQueue(Queue *q) {
    return q->data[q->front++];
}

Request front(Queue* q) {
    return q->data[q->front];
}

void displayQueue(Queue* q) {
    for (int i = q->front; i <= q->rear; i++) {
        printf("ID: %d\n", q->data[i].id);
        printf("Issue: %s\n", q->data[i].issue);
        printf("Priority: %s\n", q->data[i].priority == 1 ? "Cao" : "Thap");
    }
}

void sendRequest() {
    Request r;
    r.id = globalId++;
    getchar();
    printf("Nhap noi dung yeu cau: ");
    fgets(r.issue, sizeof(r.issue), stdin);
    r.issue[strcspn(r.issue, "\n")] = '\0';

    while (1) {
        printf("Chon muc do uu tien (1: Cao, 2: Thap): ");
        scanf("%d", &r.priority);
        if (r.priority == 1) {
            enQueue(&highQueue, r);
            break;
        } else if (r.priority == 2) {
            enQueue(&lowQueue, r);
            break;
        } else {
            printf("Lua chon khong hop le\n");
        }
    }
    printf("Da gui yeu cau thanh cong!\n");
}

void handleRequest() {
    if (!isEmpty(&highQueue)) {
        Request r = deQueue(&highQueue);
        printf("Dang xu ly yeu cau (ID: %d): %s\n", r.id, r.issue);
    } else if (!isEmpty(&lowQueue)) {
        Request r = deQueue(&lowQueue);
        printf("Dang xu ly yeu cau (ID: %d): %s\n", r.id, r.issue);
    } else {
        printf("Khong co yeu cau nao can xu ly.\n");
    }
}

void topRequest() {
    if (!isEmpty(&highQueue)) {
        Request r = front(&highQueue);
        printf("Yeu cau tiep theo (ID: %d): %s (Uu tien: Cao)\n", r.id, r.issue);
    } else if (!isEmpty(&lowQueue)) {
        Request r = front(&lowQueue);
        printf("Yeu cau tiep theo (ID: %d): %s (Uu tien: Thap)\n", r.id, r.issue);
    } else {
        printf("Khong co yeu cau nao.\n");
    }
}

void displayAll() {
    printf("\n--- Yeu cau uu tien cao ---\n");
    if (isEmpty(&highQueue)) printf("Khong co yeu cau.\n");
    displayQueue(&highQueue);

    printf("\n--- Yeu cau uu tien thap ---\n");
    if (isEmpty(&lowQueue)) printf("Khong co yeu cau.\n");
    displayQueue(&lowQueue);
}

int main() {
    int choice;
    do {
        printf("\n—————————— REQUEST SYSTEM ——————————\n");
        printf("1. Gui yeu cau ho tro\n");
        printf("2. Xu ly yeu cau\n");
        printf("3. Xem yeu cau gan nhat\n");
        printf("4. Hien thi toan bo yeu cau\n");
        printf("5. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: sendRequest(); break;
            case 2: handleRequest(); break;
            case 3: topRequest(); break;
            case 4: displayAll(); break;
            case 5: printf("Tam biet\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (choice != 5);
    return 0;
}