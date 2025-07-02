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

Node* insertHead(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;

    return newNode;
}

Node* insertEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) return newNode;
    Node* current = head;
    while (current->next != NULL) {
        current = current -> next;
    }
    current->next = newNode;
    return head;
}

Node* insertAt(Node* head, int data, int index) {
    if (index < 0 || index > lengthNode(head)) {
        printf("Index is not valid");
        return head;
    }
    if (index == 0) {
        return insertHead(head, data);
    }
    if (index == lengthNode(head)) {
        return insertEnd(head, data);
    }
    Node* current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    Node* newNode = createNode(data);
    Node* nextNode = current->next;
    current->next = newNode;
    newNode-> next = nextNode;
    return head;

}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL");
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

    int value, position;
    printf("value: ");
    scanf("%d", &value);
    printf("position: ");
    scanf("%d", &position);
    position--;
    head = insertAt(head, value, position);
    printList(head);
    return 0;
}