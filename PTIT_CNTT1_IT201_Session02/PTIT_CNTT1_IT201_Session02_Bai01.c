#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Nhap so phan tu trong mang: ");
    scanf("%d", &n);
    if(n <= 0 || n > 100){
        printf("So phan tu khong hop le\n");
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
    int maxValue = arr[0];
    for(int i = 1; i < n; i++){
        if(maxValue < arr[i]){
            maxValue = arr[i];
        }
    }
    printf("Gia tri lon nhat: %d\n", maxValue);
    free(arr);
    return 0;
}