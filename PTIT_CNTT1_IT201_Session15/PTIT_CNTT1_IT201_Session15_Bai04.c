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

int isFull(Queue* q) {
    if (q->rear == q->cap - 1) {
        return 1;
    }
    return 0;
}

int isEmpty(Queue* q) {
    return q->front > q->rear;
}

void enQueue(Queue* q, int value) {
    if(isFull(q)){
        return;
    }
    q->rear++;
    q->data[q->rear] = value;
}

void printDataQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d\n", q->data[i]);
    }
}

int main() {
    Queue *q = createQueue(5);

    // enQueue(q, 1);
    // enQueue(q, 2);
    // enQueue(q, 5);

    printDataQueue(q);

    return 0;
}