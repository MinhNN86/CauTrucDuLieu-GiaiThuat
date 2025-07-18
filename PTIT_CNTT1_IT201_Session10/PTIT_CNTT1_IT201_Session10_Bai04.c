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

void printNode(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current -> next;
    }
    printf("NULL\n");
}

Node* removeEnd(Node* head) {
    Node* current = head;
    while (current->next->next != NULL) {
        current = current -> next;
    }
    Node* temp = current -> next;
    current -> next = NULL;
    free(temp);
    return head;
}

int main() {
    Node* head = createNode(5);
    Node* node2 = createNode(4);
    Node* node3 = createNode(3);
    Node* node4 = createNode(2);
    Node* node5 = createNode(1);

    head-> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
    node5 -> next = NULL;

    head = removeEnd(head);
    printNode(head);

    return 0;
}