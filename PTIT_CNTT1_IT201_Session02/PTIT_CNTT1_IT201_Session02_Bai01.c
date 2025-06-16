#include <stdio.h>

int main(){
    int n;
    printf("Nhap so phan tu trong mang: ");
    scanf("%d", &n);
    if(n <= 0 || n > 100){
        printf("So phan tu khong hop le");
        return 1;
    }
    int arr[n];
    for(int i = 0; i < n; i++){
        printf("Nhap gia tri arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int maxValue = arr[0];
    for(int i = 0; i < n; i++){
        if(maxValue < arr[i]){
            maxValue = arr[i];
        }
    }
    printf("%d", maxValue);
    return 0;
}