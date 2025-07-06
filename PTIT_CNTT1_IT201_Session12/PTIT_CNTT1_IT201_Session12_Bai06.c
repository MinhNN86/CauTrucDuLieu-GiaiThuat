#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node-> data = data;
    node -> next = NULL;
    node -> prev = NULL;
    return node;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d<->", current -> data);
        current = current -> next;
    }
    printf("NULL\n");
}

int getLength(Node* head) {
    Node* current = head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current -> next;
    }
    return count;
}

void printDataHalf(Node* head) {
    int indexHalf = getLength(head) / 2;
    Node* current = head;
    for (int i = 0; i < indexHalf; i++) {
        current = current -> next;
    }
    printf("Node %d: %d", indexHalf + 1, current -> data);
}

int main() {
    Node* head = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);
    Node* node6 = createNode(6);

    head -> next = node2;
    node2 -> prev = head;
    node2 -> next = node3;
    node3 -> prev = node2;
    node3 -> next = node4;
    node4 -> prev = node3;
    node4 -> next = node5;
    node5 -> prev = node4;
    node5 -> next = node6;
    node6 -> prev = node5;

    printList(head);
    printDataHalf(head);
    return 0;
}