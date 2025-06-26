#include <stdio.h>
#include <string.h>
#include <ctype.h>

int laChuoiSo(char str[]){
    for(int i = 0; str[i] != '\0'; i++){
        if(!isdigit(str[i])){
            return 0;
        }
    }
    return 1;
}

int pow10(int n){
    if (n == 0) return 1;
    return 10 * pow10(n - 1);
}

int chuyenThanhSo(char str[], int index, int len){
    if(index == len){
        return 0;
    }
    return (str[index] - '0') * pow10(len - index - 1) + chuyenThanhSo(str, index + 1, len);
}

int main(){
    char str[100];

    printf("Nhap chuoi ky tu so: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';

    if(!laChuoiSo(str)){
        printf("Input khong hop le");
        return 1;
    }

    while (str[0] == '0' && strlen(str) > 1){
        memmove(str, str + 1, strlen(str));
    }

    int so = chuyenThanhSo(str, 0, strlen(str));
    printf("%d\n", so);
    return 0;
}