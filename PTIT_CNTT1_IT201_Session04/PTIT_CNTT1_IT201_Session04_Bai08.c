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

    int findValue;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &findValue);
    int check = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == findValue) {
            printf("%d ", i);
            check++;
        }
    }
    if (check == 0) {
        printf("Phan tu khong co trong mang");
    }
    return 0;
}
