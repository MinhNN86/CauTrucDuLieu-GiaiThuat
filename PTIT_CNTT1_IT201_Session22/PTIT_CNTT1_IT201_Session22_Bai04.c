#include <stdio.h>
#include <stdlib.h>

int tinhCanh(int size, int maTran[][size]) {
    int canh = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (maTran[i][j] == 1) {
                if (maTran[j][i] == 1) {
                    canh++;
                }
            }
        }
    }
    return canh/2;
}

int main() {
    int size;
    scanf("%d", &size);
    if (size < 0 || size > 100) {
        printf("So dinh khong hop le");
        return 1;
    }

    int maTran[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &maTran[i][j]);
        }
    }

    printf("\n%d", tinhCanh(size, maTran));
}