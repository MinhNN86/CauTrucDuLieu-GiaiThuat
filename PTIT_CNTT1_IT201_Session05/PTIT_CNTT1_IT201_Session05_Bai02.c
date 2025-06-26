#include <stdio.h>
int tinhTong(int n){
    if(n == 0) return 0;
    return n + tinhTong(n - 1);
}
int main(){
    int n;
    printf("Nhap so nguyen duong: ");
    scanf("%d", &n);
    if(n <= 0){
        printf("Khong hop le");
        return 1;
    } else {
        int tong = tinhTong(n);
        printf("%d", tong);
    }
    return 0;
}