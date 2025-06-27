#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void inFibonacciNguoc(int index) {
    if ( index == 0 ) return;
    printf("%d", fibonacci(index));
    if (index > 1) {
        printf(", ");
    }
    inFibonacciNguoc(index - 1);
}

int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Input khong hop le");
        return 1;
    }

    inFibonacciNguoc(n);

    return 0;
}