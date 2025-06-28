#include <stdio.h>

void thapHaNoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Dia 1 di chuyen tu %c sang %c\n", from, to);
        return;
    }
    thapHaNoi(n - 1, from, aux, to);
    printf("Dia %d di chuyen tu %c sang %c\n", n, from, to);
    thapHaNoi(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Nhap so luong dia: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Input khong hop le\n");
        return 1;
    }

    thapHaNoi(n, 'A', 'C', 'B');
    return 0;
}