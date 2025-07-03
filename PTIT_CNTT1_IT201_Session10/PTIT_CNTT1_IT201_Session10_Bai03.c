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
Node* insertEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) return newNode;
    Node* current = head;
    while (current->next != NULL) {
        current = current -> next;
    }
    current -> next = newNode;
    return head;
}

int main() {
    Node* head = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);

    head-> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
    node5 -> next = NULL;

    int newValue;
    printf("Nhap gia tri moi: ");
    scanf("%d",&newValue);
    if (newValue < 0) {
        printf("Gia tri moi khong hop le");
        return 1;
    }

    head = insertEnd(head, newValue);
    printNode(head);

    return 0;
}