#include <stdio.h>

int cachLeo(int n) {
    if (n == 0|| n == 1) {
        return 1;
    }
    return cachLeo(n - 1) + cachLeo(n - 2);
}

int main() {
    int n;
    printf("Nhap so bac cau thang: ");
    scanf("%d", &n);
    printf("%d", cachLeo(n));
    return 0;
}