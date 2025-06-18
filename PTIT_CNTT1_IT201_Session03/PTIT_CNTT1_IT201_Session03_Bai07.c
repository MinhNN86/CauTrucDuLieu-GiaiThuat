#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    printf("rows = ");
    scanf("%d", &rows);
    printf("cols = ");
    scanf("%d", &cols);

    if (rows <= 0 && cols <= 0) {
        printf("So cot va so hang khong hop le\n");
        return 1;
    } else if (rows <= 0) {
        printf("So hang khong hop le\n");
        return 1;
    } else if (cols <= 0) {
        printf("So cot khong hop le\n");
        return 1;
    }

    int** arr = (int**) malloc (rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*) malloc (cols * sizeof(int));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    int k;
    int tongHangCanTinh = 0;
    printf("k = ");
    scanf("%d", &k);
    if ( k <= 0 || k > rows) {
        printf("Hang can tinh khong ton tai");
        return 1;
    }
    k--;
    for (int j = 0; j < cols; j++) {
        tongHangCanTinh += arr[k][j];
    }

    printf("sum = %d", tongHangCanTinh);

    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}