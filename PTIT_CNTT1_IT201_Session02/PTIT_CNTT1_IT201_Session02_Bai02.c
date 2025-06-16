#include <stdio.h>

int main() {
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
    int valueCount;
    printf("Nhap gia tri de dem so lan trong mang: ");
    scanf("%d", &valueCount);
    int countValue = 0;
    for (int i = 0; i < n; i++){
        if(arr[i] == valueCount){
            countValue++;
        }
    }
    printf("%d", countValue);
    return 0;
}