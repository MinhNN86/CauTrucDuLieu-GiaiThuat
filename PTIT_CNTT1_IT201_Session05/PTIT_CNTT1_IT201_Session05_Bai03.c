#include <stdio.h>

int tinhGiaiThua(int n){
    if(n == 0 || n == 1) return 1;
    return n * tinhGiaiThua(n - 1);
}

int main(){
    int n;
    printf("Nhap so nguyen duong: ");
    scanf("%d", &n);

    if(n <= 0){
        printf("Khong phai so nguyen duong");
        return 1;
    } else {
        int giaiThua = tinhGiaiThua(n);
        printf("%d", giaiThua);
    }
    return 0;
}