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
  node -> next = NULL;
  node -> prev = NULL;
  return node;
}

int getLength(Node* head) {
  Node* current = head;
  int length = 0;
  while (current != NULL) {
    current = current -> next;
    length++;
  }
  return length;
}

Node* insertNode(Node* head, int data, int index) {
  if (index <= 0 || index > getLength(head)) {
    printf("Index is out of bounds\n");
    return head;
  }
  if (index == 1) {
    Node* newNode = createNode(data);
    newNode -> next = head;
    if (head -> next == NULL) {
      head -> prev = newNode;
    }
    return newNode;
  }
  if (index == getLength(head)) {
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
  Node* current = head;
  for (int i = 0; i < index - 1; i++) {
    current = current -> next;
  }
  Node* newNode = createNode(data);
  Node* prev = current -> prev;

  newNode -> next = current;
  current -> prev = newNode;
  prev -> next = newNode;
  newNode -> prev = prev;
  return head;
}

void printNode(Node* head) {
  Node* current = head;
  while (current != NULL) {
    printf("%d <-> ", current->data);
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
  node5 -> next = NULL;

  printNode(head);

  int indexAdd, valueAdd;
  printf("value: ");
  scanf("%d", &valueAdd);
  printf("position: ");
  scanf("%d", &indexAdd);

  head = insertNode(head, valueAdd, indexAdd);
  printNode(head);

  return 0;
}