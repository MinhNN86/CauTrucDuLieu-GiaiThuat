#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void printList(Node* head) {
    printf("NULL <-> ");
    Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current -> data);
        current = current -> next;
    }
    printf("NULL\n");
}

int getLength(Node* head) {
    Node* current = head;
    int length = 0;
    while (current != NULL) {
        length++;
        current = current -> next;
    }
    return length;
}

Node* getOne(Node* head, int index) {
    if (index < 0 || index > getLength(head)) {
        printf("Index is out of bounds\n");
        return NULL;
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current -> next;
    }
    return current;
}

Node* insertHead(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode -> next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}

Node* insertEnd(Node* head, int data) {
    Node* newNode = createNode(data);
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

Node* insertAt(Node* head, int data, int index) {
    if (index < 0 || index > getLength(head)) {
        printf("Index is out of bounds\n");
        return head;
    }
    if (index == 0) return insertHead(head, data);
    if (index == getLength(head)) {
        return insertEnd(head, data);
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current -> next;
    }
    Node* newNode = createNode(data);
    Node* prev = current->prev;

    newNode -> next = current;
    current -> prev = newNode;
    prev -> next = newNode;
    newNode -> prev = prev;

    return head;
}

Node* removeHead(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* temp = head;
    head = head -> next;
    if (head != NULL) {
        head -> prev = NULL;
    }
    free(temp);
    return head;
}

Node* removeEnd(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head -> next == NULL) {
        free(head);
        return NULL;
    }

    Node* current = head;
    while (current -> next != NULL) {
        current = current -> next;
    }
    current -> prev -> next = NULL;

    free(current);
    return head;
}

Node* removeAt(Node* head, int index) {
    if (index < 0 || index > getLength(head)) {
        printf("Index is out of bounds\n");
        return head;
    }
    if (index == 0) return removeHead(head);
    if (index == getLength(head)) {
        return removeEnd(head);
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current -> next;
    }
    Node* prev = current->prev;
    Node* next = current -> next;
    Node* temp = current;

    prev -> next = next;
    next -> prev = prev;
    free(temp);
    return head;
}

int main() {
    Node* head = createNode(10);
    Node* node2 = createNode(20);
    Node* node3 = createNode(30);

    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;

    Node* findNode = getOne(head, 1);
    printf("Node 1: %d\n", findNode -> data);
    printf("length: %d\n", getLength(head));

    head = insertHead(head, 91);
    head = insertEnd(head, 92);
    head = insertAt(head, 123, 1);

    head = removeHead(head);
    head = removeEnd(head);

    printList(head);
    return 0;
}