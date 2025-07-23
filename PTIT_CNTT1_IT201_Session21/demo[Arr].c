#include <stdio.h>

void printAdjacencyMatrix(int matrix[4][4], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printConnected(int matrix[4][4], char vertices[4], int size) {
    for (int i = 0; i < size; i++) {
        printf("%c: ", vertices[i]);
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == 1) {
                printf("%c ", vertices[j]);
            }
        }
        printf("\n");
    }
}

int main() {
    char vertexData[4] = {'A', 'B', 'C', 'D'};
    int adjacencyMatrix[4][4]={
        {0,1,1,1},
        {1,0,1,0},
        {1,1,0,0},
        {1,0,0,0}
    };
    printf("VertextData:\n");
    for (int i = 0; i < 4; i++) {
        printf("%c ", vertexData[i]);
    }
    printf("\n");
    printAdjacencyMatrix(adjacencyMatrix, 4);
    printConnected(adjacencyMatrix, vertexData, 4);
}