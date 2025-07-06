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

Node* deleteNode(Node* head, int valueDelete) {
    Node* current = head;
    while (current != NULL) {
        if (current -> data == valueDelete) {
            Node* temp = current;
            if (current -> prev == NULL) {
                head = current -> next;
                if (head != NULL) {
                    head -> prev = NULL;
                }
            } else if (current -> next == NULL) {
                current -> prev -> next = NULL;
            } else {
                current -> prev -> next = current -> next;
                current -> next -> prev = current -> prev;
            }
            current = current -> next;
            free(temp);
        } else {
            current = current -> next;
        }
    }
    return head;
}

int main() {
    Node* head = createNode(5);
    Node* node2 = createNode(1);
    Node* node3 = createNode(2);
    Node* node4 = createNode(3);
    Node* node5 = createNode(4);
    Node* node6 = createNode(5);

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

    printNode(head);
    int valueDelete;
    printf("Nhap gia tri xoa: ");
    scanf("%d", &valueDelete);

    head = deleteNode(head, valueDelete);
    printNode(head);

    return 0;
}