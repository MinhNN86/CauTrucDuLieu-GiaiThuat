#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

#define MAX 100
typedef struct Queue {
    Node* data[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

int isFull(Queue *q) {
    return q->rear == MAX;
}

void enqueue(Queue *q, Node* node) {
    if (isFull(q)) return;
    q->data[q->rear++] = node;
}

Node* dequeue(Queue *q) {
    if (isEmpty(q)) return NULL;
    return q->data[q->front++];
}

int findMaxValue(Node* root) {
    if (root == NULL) return -1;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int maxValue = root->data;
    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);

        if (current->data > maxValue) {
            maxValue = current->data;
        }
        if (current->left != NULL) {
            enqueue(&q, current->left);
        }
        if (current->right != NULL) {
            enqueue(&q, current->right);
        }
    }
    return maxValue;
}

int main() {
    Node* root = createNode(2);
    Node* node1 = createNode(3);
    Node* node2 = createNode(4);
    Node* node3 = createNode(5);

    root->left = node1;
    root->right = node2;
    node1->left = node3;

    printf("max value: %d", findMaxValue(root));

    return 0;
}