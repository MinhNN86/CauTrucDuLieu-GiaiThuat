#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node-> data = data;
    node -> next = NULL;
    return node;
}

int lengthNode(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != NULL) {
        length++;
        current = current -> next;
    }
    return length;
}

int main() {
    Node* head = createNode(5);
    Node* node2 = createNode(4);
    Node* node3 = createNode(3);
    Node* node4 = createNode(2);
    Node* node5 = createNode(1);
    Node* node6 = createNode(6);

    head-> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
    node5 -> next = node6;
    node6 -> next = NULL;

    int length = lengthNode(head);
    int lengthHalf = length / 2;
    lengthHalf++;
    Node* current = head;
    for (int i = 1; i < lengthHalf; i++) {
        current = current -> next;
    }
    printf("Node %d: %d", lengthHalf, current->data);
    return 0;
}