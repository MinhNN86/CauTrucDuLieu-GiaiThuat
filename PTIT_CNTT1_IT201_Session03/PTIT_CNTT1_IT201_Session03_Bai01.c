#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Nhap so phan tu trong mang: ");
    scanf("%d", &n);
    if(n == 0){
        printf("So luong phan tu phai lon hon 0");
        return 1;
    } else if (n < 0){
        printf("So luong phan tu khong duoc am");
        return 1;
    } else if (n >= 1000){
        printf("So luong phan tu vuot qua quy dinh");
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
    for(int i = 0; i < n; i++){
        printf("So thu %d = %d\n", i + 1, arr[i]);
    }
    free(arr);
    return 0;
}