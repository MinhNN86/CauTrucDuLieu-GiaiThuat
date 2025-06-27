#include <stdio.h>

void chuyenNhiPhan(int n) {
    if (n == 0) return;
    chuyenNhiPhan(n / 2);
    printf("%d", n % 2);
}

int main() {
    int n;
    printf("Nhap so nguyen: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("0");
    } else {
        chuyenNhiPhan(n);
    }
    return 0;
}