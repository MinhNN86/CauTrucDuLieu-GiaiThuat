#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
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

void enQueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Loi cap phat bo nho");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int deQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty");
        return -1;
    }
    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return value;
}

void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    Node* current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

}

int main() {
    Queue* q = createQueue();

    // Thêm phần tử
    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);

    // In queue
    printQueue(q);  // Output: Queue = { 10 20 30 }

    // Lấy phần tử ra
    printf("deQueue: %d\n", deQueue(q));  // 10
    printf("deQueue: %d\n", deQueue(q));  // 20

    // In lại
    printQueue(q);  // Output: Queue = { 30 }

    // Lấy tiếp
    printf("deQueue: %d\n", deQueue(q));  // 30

    // Rỗng rồi
    printQueue(q);  // Queue is empty
    printf("deQueue: %d\n", deQueue(q));  // Queue is empty -1

    return 0;
}