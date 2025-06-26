#include <stdio.h>

int fibonacci(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main(){
    int n;
    printf("Nhap so nguyen duong: ");
    scanf("%d", &n);

    if (n <= 0){
        printf("So luong phan tu khong hop le");
        return 1;
    }

    int fib[n];
    for (int i = 0; i < n; i++){
        fib[i] = fibonacci(i);
    }
    
    for(int i = 0; i < n; i++){
        printf("%d ", fib[i]);
    }
    return 0;
}