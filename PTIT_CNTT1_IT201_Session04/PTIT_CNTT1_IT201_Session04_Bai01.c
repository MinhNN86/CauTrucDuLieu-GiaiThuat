#include <stdio.h>

int main() {
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

    int findValue;
    printf("Nhap so can tim trong mang: ");
    scanf("%d", &findValue);

    for (int i = 0; i < n; i++) {
        if (arr[i] == findValue) {
            printf("%d", i);
            return 0;
        }
    }
    printf("Khong tim thay phan tu");
    return 0;
}