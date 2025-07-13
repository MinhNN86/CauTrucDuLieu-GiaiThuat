#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef  struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) {
        printf("Loi cap phat bo nho");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void enQueue(Queue *q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Loi cap phat bo nho");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q-> rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void printQueue(Queue *q) {
    printf("queue = {\nfront->");
    if (isEmpty(q)) {
        printf("NULL,\nrear->NULL\n},\n");
    } else {
        Node* current = q ->front;
        while (current != NULL) {
            printf("%d->", current->data);
            current = current->next;
        }
        printf("NULL,\n");
        Node* rear = q->rear;
        printf("rear->%d->NULL\n},\n", rear->data);
    }
}

void printDataQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty");
        return;
    }
    Node* current = q->front;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current -> next;
    }
}

int main() {
    Queue* q = createQueue();

    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 5);

    printQueue(q);
    printDataQueue(q);

    return 0;
}