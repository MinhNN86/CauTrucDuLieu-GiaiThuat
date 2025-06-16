#include <stdio.h>

int main () {
    int arr[] = {37, 92, 14, 58, 6, 71, 23, 85, 49, 10};
    int sizeArr = sizeof(arr) / sizeof(arr[0]);
    int n;
    int found = 0;
    printf("Nhap so n kiem tra phan tu co trong mang: ");
    scanf("%d", &n);
    for (int i = 0; i < sizeArr; i++) {
        if (arr[i] == n) {
            found = 1;
            break;
        }
    }
    if (found) {
        printf("So %d co trong mang.", n);
    } else {
        printf("So %d khong co trong mang.", n);
    }
    return 0;
}
/*
+ Thời gian: O(n);
+ Không gian: O(1);
*/