#include <stdio.h>

void count(int n){
    if (n == 0){
        return;
    }
    count(n - 1);
    printf("%d \n", n);
}
int main(){
    int n;
    printf("Nhap so nguyen duong: ");
    scanf("%d", &n);

    if (n <= 0){
        printf("Khong phai so nguyen duong");
    }else{
        count(n);
    }
    return 0;
}