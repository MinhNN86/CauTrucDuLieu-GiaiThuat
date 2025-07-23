#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Loi cap phat");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* graph[], int startNode, int endNode) {
    Node* newNode1 = createNode(endNode);
    newNode1->next = graph[startNode];
    graph[startNode] = newNode1;

    Node* newNode2 = createNode(startNode);
    newNode2->next = graph[endNode];
    graph[endNode] = newNode2;
}

void printGraph(Node* graph[], int size) {
    printf("[\n");
    for (int i = 0; i < size; i++) {
        Node* current = graph[i];
        while (current != NULL) {
            printf("%d->", current->data);
            current = current->next;
        }
        printf("NULL,\n");
    }
    printf("]\n");
}

int main() {
    int startNode, endNode;
    Node* graph[SIZE] = {NULL};

    printGraph(graph, SIZE);
    printf("startNode = ");
    scanf("%d", &startNode);
    printf("endNode = ");
    scanf("%d", &endNode);
    addEdge(graph, startNode, endNode);
    printf("\n");
    printGraph(graph, SIZE);
    return 0;
}