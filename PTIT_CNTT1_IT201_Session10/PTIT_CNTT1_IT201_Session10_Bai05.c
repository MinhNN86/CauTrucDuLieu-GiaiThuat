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

int lenghtNode(Node* head) {
    int len = 0;
    Node* current = head;
    while (current != NULL) {
        len++;
        current = current -> next;
    }
    return len;
}

Node* removeHead(Node* head) {
    if (head == NULL) return NULL;
    Node* temp = head;
    head = head -> next;
    free(temp);
    return head;
}

Node* deleteNode(Node* head, int valueDelete) {
    Node* current = head;
    Node* prev = NULL;
    int checkDelete = 0;
    while (current != NULL) {
        if (current->data == valueDelete) {
            checkDelete = 1;
            if (prev == NULL) {
                head = removeHead(head);
                current = head;
            } else {
                Node* temp = current;
                current = current -> next;
                prev->next = current;
                free(temp);
            }
        }  else {
            prev = current;
            current = current -> next;
        }
    }
    if (!checkDelete) {
        printf("Khong tim thay data\n");
    }

    return head;
}

void printNode(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d->", current->data);
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

    head-> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
    node5 -> next = NULL;

    int valueDelete;
    printf("Nhap gia tri can xoa: ");
    scanf("%d", &valueDelete);
    head = deleteNode(head, valueDelete);
    printNode(head);

    return 0;
}