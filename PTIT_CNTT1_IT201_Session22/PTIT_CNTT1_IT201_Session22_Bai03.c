#include <stdio.h>
#include <stdlib.h>

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
    Node* newNode = createNode(endNode);
    if (graph[startNode] == NULL) {
        graph[startNode] = newNode;
    } else {
        Node* current = graph[startNode];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void duyetMangThemCanh(int size, int maTran[][size], Node* graph[]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (maTran[i][j] == 1) {
                addEdge(graph, i, j);
            }
        }
    }
}

void printGraph(Node* graph[], int size) {
    for (int i = 0; i < size; i++) {
        Node* current = graph[i];
        printf("%d: ", i);
        while (current != NULL) {
            printf("%d->", current->data);
            current = current->next;
        }
        printf("NULL,\n");
    }
}

int main() {
    int size;
    scanf("%d", &size);
    if (size < 0 || size > 100) {
        printf("So dinh khong hop le");
        return 1;
    }

    int maTran[size][size];
    Node* graph[size];
    for (int i = 0; i < size; i++) {
        graph[i] = NULL;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &maTran[i][j]);
        }
    }
    duyetMangThemCanh(size, maTran, graph);
    printf("\n");
    printGraph(graph, size);
    return 0;
}