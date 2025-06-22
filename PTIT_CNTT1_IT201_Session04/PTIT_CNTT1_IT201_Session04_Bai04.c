#include <stdio.h>

int main() {
    int n;
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("So luong phan tu khong hop le.\n");
        return 1;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    int value;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);

    int lastIndex = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            lastIndex = i;
        }
    }

    if (lastIndex != -1) {
        printf("%d", lastIndex);
    } else {
        printf("Khong tim thay phan tu");
    }
    return 0;
}