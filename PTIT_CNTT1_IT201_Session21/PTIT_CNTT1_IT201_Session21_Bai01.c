#include <stdio.h>

void inMaTran(int maTran[3][3], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", maTran[i][j]);
        }
        printf("\n");
    }
}

void themCanh(int maTran[3][3], int firstNode, int secondNode) {
    maTran[firstNode][secondNode] = 1;
    maTran[secondNode][firstNode] = 1;
}

int main() {
    int maTran[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    int firstNode, secondNode;
    inMaTran(maTran, 3);
    printf("firstNode: ");
    scanf("%d", &firstNode);
    printf("secondNode: ");
    scanf("%d", &secondNode);
    themCanh(maTran, firstNode, secondNode);
    inMaTran(maTran, 3);
    return 0;
}