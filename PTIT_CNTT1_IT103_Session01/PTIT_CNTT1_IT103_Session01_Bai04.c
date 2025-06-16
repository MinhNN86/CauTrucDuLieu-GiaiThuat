#include <stdio.h>
// Cách 1: Dùng for
int sumLoop(int n){
    int sum = 0;
    for(int i = 0; i <= n; i++){
        sum += i;
    }
    return sum;
}
// Cách 2: Công thức toán 
int sumFormula(int n){
    return n * (n + 1) / 2;
}
int main(){
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    int cach1 = sumLoop(n);
    printf("Tong theo cach 1: %d\n", cach1);

    int cach2 = sumFormula(n);
    printf("Tong theo cach 2: %d", cach2);

    return 0;
}
/*
    - Cách 1: Dùng vòng lặp
        + Thời gian: O(n)
        + Không gian: O(1)
    - Cách 2: Dùng công thức 
        + Thời gian: O(1)
        + Không gian: O(1)
*/