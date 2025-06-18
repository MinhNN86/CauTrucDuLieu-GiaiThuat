#include <stdio.h>
#include <stdlib.h>

int tinhDuongCheoChinh(int** arr, int rows, int cols) {
    int tongDuongCheoChinh = 0;
    for (int i = 0; i < rows && i < cols; i++) {
        tongDuongCheoChinh += arr[i][i];
    }
    return tongDuongCheoChinh;
}
int tinhDuongCheoPhu(int** arr, int rows, int cols) {
    if (rows != cols) {
        printf("Khong ton tai duong cheo phu\n");
        return 0;
    }
    int tongDuongCheoPhu = 0;
    for (int i = 0; i < rows; i++) {
        tongDuongCheoPhu += arr[i][cols - 1 - i];
    }
    return  tongDuongCheoPhu;
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

    int tongChinh = tinhDuongCheoChinh(arr, rows, cols);
    printf("Tong duong cheo chinh = %d\n", tongChinh);
    int tongPhu = tinhDuongCheoPhu(arr, rows, cols);
    if (rows == cols) {
        printf("Tong duong cheo phu = %d\n", tongPhu);
    }

    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}