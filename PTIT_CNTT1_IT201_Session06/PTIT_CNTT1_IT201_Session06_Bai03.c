#include <stdio.h>

int tongChuSo(int n) {
    if (n == 0){
        return 0;
    }
    return ( n % 10 ) + tongChuSo(n / 10);
}
int main() {
    int n;
    printf("Nhap so nguyen duong: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Input khong hop le\n");
        return 1;
    }
    int tong = tongChuSo(n);
    printf("%d", tong);
    return 0;
}