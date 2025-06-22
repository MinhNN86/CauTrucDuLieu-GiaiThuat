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

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int findValue;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &findValue);

    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == findValue) {
            printf("Phan tu co trong mang");
            return 0;
        } else if (arr[mid] < findValue) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Phan tu khong co trong mang");
    return 0;
}