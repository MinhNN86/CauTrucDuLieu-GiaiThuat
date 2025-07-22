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

void enQueue(Queue* q, Node* node) {
    if (isFull(q)) return;
    q->data[q->rear++] = node;
}

Node* deQueue(Queue* q) {
    if (isEmpty(q)) return NULL;
    return q->data[q->front++];
}

int findNodeLevel(Node* root, int value) {
    if (root == NULL) return -1;

    Queue q;
    initQueue(&q);
    enQueue(&q, root);
    int levelNode = 0;
    while (!isEmpty(&q)) {
        int size = q.rear - q.front;
        for (int i = 0; i < size; i++) {
            Node* current = deQueue(&q);
            if (current->data == value) {
                return levelNode;
            }
            if (current->left) {
                enQueue(&q, current->left);
            }
            if (current->right) {
                enQueue(&q, current->right);
            }
        }
        levelNode++;
    }
}

void inorderDFS(Node* root) {
    if (root == NULL) return;
    inorderDFS(root->left);
    printf("%d ", root->data);
    inorderDFS(root->right);
}
int main() {
    Node* root = createNode(2);
    Node* node1 = createNode(3);
    Node* node2 = createNode(4);
    Node* node3 = createNode(5);

    root->left = node1;
    root->right = node2;
    node1->left = node3;

    inorderDFS(root);
    printf("\n");

    int value;
    printf("value: ");
    scanf("%d", &value);
    printf("Node level: %d", findNodeLevel(root, value));

    return 0;
}