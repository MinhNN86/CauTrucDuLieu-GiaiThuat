#include <stdio.h>

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000) {
        printf("Input khong hop le");
        return 1;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("arr[%d]= ", i);
        scanf("%d", &arr[i]);
    }

    int search;
    int found = 0;
    printf("search = ");
    scanf("%d", &search);

    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            printf("vi tri thu: %d\n", i + 1);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong ton tai phan tu");
    }
    // Độ phức tạp thời gian: O(n)
    return 0;
}