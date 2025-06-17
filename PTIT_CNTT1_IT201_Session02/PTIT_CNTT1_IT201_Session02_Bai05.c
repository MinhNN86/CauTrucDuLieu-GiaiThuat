#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Nhap so phan tu trong mang: ");
    scanf("%d", &n);
    if(n <= 0 || n > 100){
        printf("So phan tu khong hop le");
        return 1;
    }
    int* arr = (int*)malloc(n * sizeof(int));
    if(arr == NULL){
        printf("Cap phat bo nho that bai\n");
        return 1;
    }
    for(int i = 0; i < n; i++){
        printf("Nhap gia tri arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int positionDelete;
    printf("Vi tri muon xoa o mang: ");
    scanf("%d", &positionDelete);
    if(positionDelete < 0 || positionDelete >= n){
        printf("Khong hop le.\n");
        return 1;
    }
    for (int i = positionDelete; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
