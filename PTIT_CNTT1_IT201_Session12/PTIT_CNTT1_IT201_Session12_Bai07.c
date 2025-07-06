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

void printNode(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d<->", current -> data);
        current = current -> next;
    }
    printf("NULL\n");
}

void sortList(Node* head) {
    if (head == NULL) return;

    int swapped;
    Node* current;
    Node* last = NULL;

    do {
        swapped = 0;
        current = head;

        while (current -> next != last) {
            if (current -> data > current -> next -> data) {
                int temp = current -> data;
                current -> data = current -> next -> data;
                current -> next -> data = temp;
                swapped = 1;
            }
            current = current -> next;
        }
        last = current;
    } while (swapped);
}

int main() {
    Node* head = createNode(5);
    Node* node2 = createNode(4);
    Node* node3 = createNode(3);
    Node* node4 = createNode(2);
    Node* node5 = createNode(1);

    head -> next = node2;
    node2 -> prev = head;
    node2 -> next = node3;
    node3 -> prev = node2;
    node3 -> next = node4;
    node4 -> prev = node3;
    node4 -> next = node5;
    node5 -> prev = node4;

    printNode(head);
    sortList(head);
    printNode(head);

    return 0;
}