#include <stdio.h>
#include <stdlib.h>

int timMax(int** arr, int rows, int cols) {
    int max = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}
int timMin(int** arr, int rows, int cols) {
    int min = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }
    return min;
}
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

    int** arr = (int**) malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*) malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    int max = timMax(arr, rows, cols);
    int min = timMin(arr, rows, cols);

    printf("max = %d\n", max);
    printf("min = %d", min);

    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}