#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
    char data[100][31];
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q-> size = 0;
}

int isEmpty(Queue *q) {
    return q->size == 0;
}

int isFull(Queue *q) {
    return q->size == 100;
}

void enQueue(Queue *q, const char* name) {
    if (isFull(q)) {
        printf("Hang doi day");
        return;
    }
    q->rear = (q->rear + 1) % 100;
    strcpy(q->data[q->rear], name);
    q->size++;
}

void deQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong\n");
        return;
    }
    printf("Phuc vu khach: %s\n", q->data[q->front]);
    q->front = (q->front + 1) % 100;
    q->size--;
}

void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi trong\n");\
        return;
    }
    printf("Danh sach khach dang cho: \n");
    int index = q->front;
    for (int i = 0; i < q->size; i++) {
        printf("- %s\n", q->data[index]);
        index = (index + 1) % 100;
    }
}

int main() {
    Queue q;
    initQueue(&q);

    int choice;
    char name[31];

    do {
        printf("\n=== MENU ===\n");
        printf("1. Them khach hang\n");
        printf("2. Phuc vu khach hang\n");
        printf("3. Hien thi danh sach khach cho\n");
        printf("4. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nhập tên khách (tối đa 30 ký tự): ");
                fgets(name, 31, stdin);
                name[strcspn(name, "\n")] = 0;
                enQueue(&q, name);
                break;
            case 2:
                deQueue(&q);
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                printf("Thoát chương trình.\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ.\n");
        }
    } while (choice != 4);

    return 0;
}