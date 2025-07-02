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
void lengthNode(Node* head) {
    Node* current = head;
    int length = 0;
    while (current != NULL) {
        current = current->next;
        length++;
    }
    printf("Danh sach lien ket co %d phan tu", length);
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

    lengthNode(head);
    return 0;
}