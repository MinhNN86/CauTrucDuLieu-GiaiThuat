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

int searchDFS(Node* root, int searchValue) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == searchValue) {
        return 1;
    }
    return searchDFS(root->left, searchValue) || searchDFS(root->right, searchValue);
}

int main() {
    Node* root = createNode(2);
    Node* node1 = createNode(3);
    Node* node2 = createNode(4);
    Node* node3 = createNode(5);

    root->left = node1;
    root->right = node2;
    node1->left = node3;

    int searchValue;
    printf("findValue: ");
    scanf("%d", &searchValue);

    int checkSearch = searchDFS(root, searchValue);
    if (checkSearch) {
        printf("True");
    } else {
        printf("False");
    }

    return 0;
}