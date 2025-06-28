#include <stdio.h>

int timMin(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }
    int minConLai = timMin(arr, n - 1);
    return (arr[n - 1] < minConLai) ? arr[n - 1] : minConLai;
}

int timMax(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }
    int maxConLai = timMax(arr, n - 1);
    return (arr[n - 1] > maxConLai) ? arr[n - 1] : maxConLai;
}

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Input khong hop le");
        return 1;
    }
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    int min = timMin(arr, n);
    int max = timMax(arr, n);

    printf("min: %d\n", min);
    printf("max: %d\n", max);
    return 0;
}