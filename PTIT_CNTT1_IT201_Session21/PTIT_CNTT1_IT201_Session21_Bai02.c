#include <stdio.h>
#define SIZE 4
void inMaTran(int maTran[SIZE][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", maTran[i][j]);
        }
        printf("\n");
    }
}

void themCanh(int maTran[SIZE][SIZE], int firstNode, int secondNode) {
    maTran[firstNode][secondNode] = 1;
    maTran[secondNode][firstNode] = 1;
}

int main() {
    int maTran[SIZE][SIZE] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    inMaTran(maTran, SIZE);
    themCanh(maTran, 0, 1);
    themCanh(maTran, 0,2);
    themCanh(maTran, 1, 2);
    themCanh(maTran, 2, 3);
    printf("Sau khi them canh: \n");
    inMaTran(maTran, SIZE);
    return 0;
}
