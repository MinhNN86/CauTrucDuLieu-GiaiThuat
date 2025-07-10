#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *data;
    int front;
    int rear;
    int cap;
} Queue;

Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) {
        printf("Loi cap phat bo nho");
        exit(1);
    }
    q->data = (int*)malloc(size*sizeof(int));
    if (!q->data) {
        printf("Loi cap phat bo nho");
        free(q);
        exit(1);
    }
    q->front = 0;
    q->rear = -1;
    q->cap = size;

    return q;
}

int main() {
    int size;
    printf("Nhap kich thuoc hang doi: ");
    scanf("%d", &size);
    Queue *q = createQueue(size);

    return 0;
}