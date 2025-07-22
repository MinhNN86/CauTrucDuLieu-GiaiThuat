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

int main() {
    Node* root = createNode(2);
    Node* node1 = createNode(3);
    Node* node2 = createNode(4);
    Node* node3 = createNode(5);

    root->left = node1;
    root->right = node2;
    node1->left = node3;

    int newValue;
    printf("Nhap gia tri cho node moi: ");
    scanf("%d", &newValue);
    Node* testNode = createNode(newValue);
    printf("node ={\n   data: %d,\n   left->%p,\n   right->%p\n}", testNode->data, testNode->left, testNode->right);


    return 0;
}