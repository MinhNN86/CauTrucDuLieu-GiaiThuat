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

int getLength(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

Node* getNode(Node* head, int index) {

    Node* current = head;
    current = head;
    for (int i = 0; i < index; i++) {
        current = current -> next;
    }
    return current;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
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
        current = current->next;
    }
    current->next = newNode;
    return head;
}

Node* insertAt(Node* head, int data, int index) {
    if (index < 0 || index > getLength(head)) {
       printf("Index is not valid");
        return head;
    }
    if (index == 0) {
        return insertHead(head, data);
    }
    if (index == getLength(head)) {
        return insertEnd(head, data);
    }
    Node* current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    Node* newNode = createNode(data);
    Node* nextNode = current->next;
    current->next = newNode;
    newNode->next = nextNode;
    return head;
}

int main() {
    Node* head = createNode(10);
    Node* node2 = createNode(20);
    Node* node3 = createNode(30);
    Node* node4 = createNode(40);
    Node* node5 = createNode(50);
    Node* node6 = createNode(60);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    Node* findNode = getNode(head, 4);
    printf("%d \n", findNode->data);
    head = insertAt(head, 199, 3);
    printList(head);


    return 0;
}