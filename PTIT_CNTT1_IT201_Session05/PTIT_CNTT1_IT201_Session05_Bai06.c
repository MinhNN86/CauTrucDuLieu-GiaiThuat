#include <stdio.h>

int tinhTong(int arr[], int n){
    if(n == 0){
        return 0;
    }
    return arr[n - 1] + tinhTong(arr, n - 1);
}
int main(){
    int n;
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("So luong phan tu khong hợp lệ");
        return 1;
    }
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    
    int tong = tinhTong(arr, n);
    printf("%d", tong);
    return 0;
}