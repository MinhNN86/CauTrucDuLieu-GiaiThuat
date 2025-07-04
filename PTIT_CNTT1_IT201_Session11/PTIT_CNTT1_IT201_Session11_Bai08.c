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

Node* removeAt(Node* head, int index) {
  if (index <= 0 || index > getLength(head)) {
    printf("Index is out of bounds\n");
    return head;
  }
  if (index == 1) {
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
  if (index == getLength(head)) {
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
  Node* current = head;
  for (int i = 0; i < index - 1; i++) {
    current = current -> next;
  }
  Node* prev = current -> prev;
  Node* next = current -> next;
  Node* temp = current;

  prev -> next = next;
  next -> prev = prev;
  free(temp);
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

  int indexRemove;
  printf("Nhap vi tri xoa: ");
  scanf("%d", &indexRemove);

  printNode(head);
  head = removeAt(head, indexRemove);
  printNode(head);

  return 0;
}