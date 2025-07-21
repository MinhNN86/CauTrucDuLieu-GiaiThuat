#include <stdio.h>
#include <stdlib.h>

// Cấu trúc node của cây
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Tạo node mới
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Duyệt Preorder (NLR)
void preorderDFS(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderDFS(root->left);
    preorderDFS(root->right);
}

// Duyệt Inorder (LNR)
void inorderDFS(Node* root) {
    if (root == NULL) return;
    inorderDFS(root->left);
    printf("%d ", root->data);
    inorderDFS(root->right);
}

// Duyệt Postorder (LRN)
void postorderDFS(Node* root) {
    if (root == NULL) return;
    postorderDFS(root->left);
    postorderDFS(root->right);
    printf("%d ", root->data);
}

// Cài đặt hàng đợi cho duyệt theo tầng (Level-order)
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

// Duyệt Level-order (theo tầng)
void levelOrder(Node* root) {
    if (root == NULL) return;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(&q, current->left);
        if (current->right != NULL)
            enqueue(&q, current->right);
    }
}

int main() {
    Node *root = createNode(1);
    Node *node1 = createNode(2);
    Node *node2 = createNode(3);
    Node *node3 = createNode(4);
    Node *node4 = createNode(5);

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;

    printf("Preorder: ");
    preorderDFS(root);  // 1 2 4 5 3
    printf("\n");

    printf("Inorder: ");
    inorderDFS(root);   // 4 2 5 1 3
    printf("\n");

    printf("Postorder: ");
    postorderDFS(root); // 4 5 2 3 1
    printf("\n");

    printf("Level-order: ");
    levelOrder(root);   // 1 2 3 4 5
    printf("\n");

    return 0;
}