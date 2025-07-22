#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

#define MAX 100

typedef struct Queue {
    Node *data[MAX];
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

void enQueue(Queue *q, Node *node) {
    if (isFull(q)) return;
    q->data[q->rear++] = node;
}

Node *deQueue(Queue *q) {
    if (isEmpty(q)) return NULL;
    return q->data[q->front++];
}

int countLeaves(Node *root) {
    if (root == NULL) return 0;
    int leaves = 0;
    Queue q;
    initQueue(&q);
    enQueue(&q, root);

    while (!isEmpty(&q)) {
        Node *current = deQueue(&q);
        if (current->left == NULL && current->right == NULL) {
            leaves++;
        }
        if (current->left != NULL) {
            enQueue(&q, current->left);
        }
        if (current->right != NULL)
            enQueue(&q, current->right);
    }
    return leaves;
}

int main() {
    Node *root = createNode(2);
    Node *node1 = createNode(3);
    Node *node2 = createNode(4);
    Node *node3 = createNode(5);

    root->left = node1;
    root->right = node2;
    node1->left = node3;

    printf("Number of leaves: %d", countLeaves(root));
    return 0;
}
