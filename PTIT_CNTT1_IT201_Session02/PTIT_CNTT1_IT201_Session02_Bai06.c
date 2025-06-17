#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Nhap so phan tu trong mang: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("So phan tu khong hop le\n");
        return 1;
    }
    int* arr = (int*)malloc(n+1 * sizeof(int));
    if (arr == NULL) {
        printf("Cap phat bo nho that bai\n");
        return 1;
    }
    for(int i = 0; i < n; i++){
        printf("Nhap gia tri arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int indexAdd;
    printf("Vi tri: ");
    scanf("%d", &indexAdd);
    int addValue;
    printf("gia tri: ");
    scanf("%d", &addValue);
    if (indexAdd < 0 || indexAdd > n) {
        printf("Khong hop le");
        return 1;
    }
    for (int i = n; i > indexAdd; i--) {
        arr[i] = arr[i - 1];
    }
    arr[indexAdd] = addValue;
    n++;
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}