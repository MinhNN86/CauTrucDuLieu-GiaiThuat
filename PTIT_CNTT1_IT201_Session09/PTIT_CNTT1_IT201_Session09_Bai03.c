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

int lengthNode(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

void findNode(Node* head, int dataFindNode) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == dataFindNode) {
            printf("True");
            return;
        }
        current = current->next;
    }
    printf("False");
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

    int dataFindNode;
    printf("Nhap data Node can tim: ");
    scanf("%d", &dataFindNode);

    findNode(head, dataFindNode);

    return 0;
}