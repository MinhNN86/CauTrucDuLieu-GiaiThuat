#include <stdio.h>

#define MAX 100

void addEdge(int graph[MAX][MAX], int startNode, int endNode) {
    graph[startNode][endNode] = 1;
    graph[endNode][startNode] = 1;
}

int main() {
    int size = 5;
    int graph[MAX][MAX] = {0};
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

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}