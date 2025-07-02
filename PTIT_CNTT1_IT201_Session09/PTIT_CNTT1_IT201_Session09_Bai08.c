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

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
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

Node* removeHead(Node* head) {
    if (head == NULL) return NULL;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* removeLast(Node* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) { // chỉ có 1 node
        free(head);
        return NULL;
    }

    Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    Node* removeNode = current->next;
    current->next = NULL;
    free(removeNode);
    return head;
}

Node* removeAt(Node* head, int index) {
    int len = lengthNode(head);
    if (index < 0 || index >= len) {
        printf("Index is not valid\n");
        return head;
    }

    if (index == 0) {
        return removeHead(head);
    }

    if (index == len - 1) {
        return removeLast(head);
    }

    Node* current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    Node* removeNode = current->next;
    current->next = removeNode->next;
    free(removeNode);
    return head;
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    int indexRemove;
    printf("Vi tri xoa: ");
    scanf("%d", &indexRemove);
    indexRemove--;
    head = removeAt(head, indexRemove);
    printList(head);


    return 0;
}
