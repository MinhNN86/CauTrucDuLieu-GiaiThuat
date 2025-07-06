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

Node* insertEnd(Node* head, int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }
    Node* current = head;
    while (current -> next != NULL) {
        current = current -> next;
    }
    current -> next = newNode;
    newNode -> prev = current;
    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d<->", current -> data);
        current = current -> next;
    }
    printf("NULL\n");
}
int main() {
    Node* head = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);

    head -> next = node2;
    node2 -> prev = head;
    node2 -> next = node3;
    node3 -> prev = node2;
    node3 -> next = node4;
    node4 -> prev = node3;
    node4 -> next = node5;
    node5 -> prev = node4;


    printList(head);

    int valueAdd;
    printf("Nhap gia tri them: ");
    scanf("%d", &valueAdd);

    head = insertEnd(head, valueAdd);
    printList(head);

    return 0;
}