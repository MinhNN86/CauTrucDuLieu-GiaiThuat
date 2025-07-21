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

void postorderDFS(Node* root) {
    if (root == NULL) return;
    postorderDFS(root->left);
    postorderDFS(root->right);
    printf("%d ", root->data);
}

typedef struct {
    Node* data[100];
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
    return q->rear == 100;
}

void enQueue(Queue *q, Node* node) {
    if (isFull(q)) return;
    q->data[q->rear++] = node;
}

Node* deQueue(Queue *q) {
    if (isEmpty(q)) return NULL;
    return q->data[q->front++];
}

void addNode(Node* root, int addValue) {
    if (root == NULL) return;

    Queue q;
    initQueue(&q);
    enQueue(&q, root);
    while (!isEmpty(&q)) {
        Node* current = deQueue(&q);
        if (current->left == NULL) {
            current->left = createNode(addValue);
            return;
        } else {
            enQueue(&q, current->left);
        }
        if (current->right == NULL) {
            current->right = createNode(addValue);
            return;
        } else {
            enQueue(&q, current->right);
        }
    }
}

int main() {
    Node* root = createNode(2);
    Node* node1 = createNode(3);
    Node* node2 = createNode(4);
    Node* node3 = createNode(5);

    root->left = node1;
    root->right = node2;
    node1->left = node3;

    printf("Cay truoc khi them:\n");
    postorderDFS(root);
    printf("\n");

    int addValue;
    printf("Nhap gia tri phan tu them: ");
    scanf("%d", &addValue);

    addNode(root, addValue);

    printf("Cay sau khi them:\n");
    postorderDFS(root);
    printf("\n");

    return 0;
}