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
    // Tạo mảng đảo ngược
    int arrReverse[n];
    for (int i = n - 1; i >= 0; i--) {
        arrReverse[n - 1 - i] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arrReverse[i]);
    }

    return 0;
}