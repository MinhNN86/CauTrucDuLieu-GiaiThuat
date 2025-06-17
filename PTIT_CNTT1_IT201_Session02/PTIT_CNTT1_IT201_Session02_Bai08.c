#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Nhap so phan tu trong mang: ");
    scanf("%d", &n);
    if(n <= 0 || n > 100){
        printf("So phan tu khong hop le\n");
        return 1;
    }
    int* arr = (int*)malloc(n * sizeof(int));
    int* result = (int*)malloc(n * sizeof(int));
    int resultSize = 0;
    if(arr == NULL || result == NULL){
        printf("Cap phat bo nho that bai\n");
        return 1;
    }
    for(int i = 0; i < n; i++){
        printf("Nhap gia tri arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    int maxRight = arr[n-1];
    result[resultSize++] = arr[n - 1];

    for(int i = n - 2; i >= 0; i--) {
        if(arr[i] > maxRight) {
            result[resultSize++] = arr[i];
            maxRight = arr[i];
        }
    }

    for (int i = resultSize - 1; i >= 0; i--) {
        if (i == 0) {
            printf("%d", result[i]);
        } else {
            printf("%d, ", result[i]);
        }
    }

    free(arr);
    free(result);
    return 0;
}