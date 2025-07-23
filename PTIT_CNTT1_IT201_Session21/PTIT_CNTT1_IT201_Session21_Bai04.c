#include <stdio.h>
#define SIZE 3
void inMaTran(int maTran[SIZE][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", maTran[i][j]);
        }
        printf("\n");
    }
}

void addEdge(int maTran[SIZE][SIZE], int startNode, int endNode) {
    maTran[startNode][endNode] = 1;
}

int main() {
    int maTran[SIZE][SIZE] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    inMaTran(maTran, SIZE);
    addEdge(maTran, 1, 0);
    addEdge(maTran, 1, 2);
    addEdge(maTran,2, 0);
    printf("Sau khi them canh: \n");
    inMaTran(maTran, SIZE);
    return 0;
}
