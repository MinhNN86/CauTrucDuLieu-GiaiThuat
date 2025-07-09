#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Queue {
    int data[MAX];
    int front;
    int real;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->real = -1;
}

int isEmpty(Queue* q) {
    return q->front > q->real;
}

int isFull(Queue* q) {
    return q->real == MAX - 1;
}

void enQueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->real++;
    q->data[q->real] = value;
}

int deQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        int value = q->data[q->front];
        q->front++;
        return value;
    }
}

int frontValue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->data[q->front];
}

void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->real; i++) {
        printf("%d ", q->data[i]);
    }
}

int main() {
    Queue q;
    initQueue(&q);
    enQueue(&q, 10);
    enQueue(&q, 20);
    enQueue(&q, 30);
    enQueue(&q, 40);
    enQueue(&q, 50);
    printQueue(&q);
    return 0;
}