#include <stdio.h>

int tinhTong(int firstNum, int secondNum){
    if(firstNum > secondNum) return 0;
    return firstNum + tinhTong(firstNum + 1, secondNum);
}
int main(){
    int firstNum, secondNum;
    printf("Nhap so thu 1: ");
    scanf("%d", &firstNum);
    printf("Nhap so thu 2: ");
    scanf("%d", &secondNum);
    
    if(firstNum < 0 || secondNum < 0){
        printf("Khong hop le");
        return 1;
    }
    if(firstNum > secondNum){
        int temp = firstNum;
        firstNum = secondNum;
        secondNum = temp;
    }
    int tong = tinhTong(firstNum, secondNum);
    printf("%d", tong);
    return 0;
}