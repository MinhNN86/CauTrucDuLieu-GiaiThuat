#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node* )malloc(sizeof(Node));
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
    if (graph[startNode] == NULL) {
        graph[startNode] = newNode1;
    } else {
        Node* temp = graph[startNode];
        while (temp->next != NULL) {
            temp = temp -> next;
        }
        temp->next = newNode1;
    }

    Node* newNode2 = createNode(startNode);
    if (graph[endNode] == NULL) {
        graph[endNode] = newNode2;
    } else {
        Node* temp = graph[endNode];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode2;
    }
}

void printGraph(Node* graph[], int size) {
    for (int i = 0; i < size; i++) {
        Node* current = graph[i];
        printf("%d: ", i);
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    Node* graph[MAX] = {NULL};
    int edges[][2] = {
        {0, 1},
        {0, 2},
        {1, 2},
        {3, 2},
        {1, 3},
        {3, 4}
    };
    int edgeCount = sizeof(edges) / sizeof(edges[0]);
    for (int i = 0; i < edgeCount; i++) {
        int startNode = edges[i][0];
        int endNode = edges[i][1];
        addEdge(graph, startNode, endNode);
    }

    printGraph(graph,MAX);
}