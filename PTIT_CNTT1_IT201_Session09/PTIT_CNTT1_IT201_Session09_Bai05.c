#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Node* addNodeHead(Node* head, int addNodeData) {
    Node* newNode = createNode(addNodeData);
    newNode->next = head;

    return newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL");
}

int main() {
    Node* head = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    int addNodeData;
    printf("Nhap data vao node muon them: ");
    scanf("%d", &addNodeData);

    head = addNodeHead(head, addNodeData);
    printList(head);
    return 0;
}