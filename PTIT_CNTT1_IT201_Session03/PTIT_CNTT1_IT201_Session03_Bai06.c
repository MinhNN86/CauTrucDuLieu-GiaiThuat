#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,m;

    printf("n = ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 1;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Cap phat bo nho that bai");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("m = ");
    scanf("%d", &m);

    if (m < 0 || n + m >= 1000) {
        printf("So luong phan tu khong hop le\n");
        free(arr);
        return 1;
    }
    int* newArr = (int*)realloc(arr, (n + m) * sizeof(int));
    if (newArr == NULL) {
        printf("Cap phat bo nho that bai");
        free(arr);
        return 1;
    }
    arr = newArr;

    for (int i = 0; i < m; i++) {
        printf("arr[%d]= ", n + i);
        scanf("%d", &arr[n + i]);
    }

    for (int i = 0; i < n + m; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}