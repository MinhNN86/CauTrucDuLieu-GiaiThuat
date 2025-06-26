#include <stdio.h>
#include <string.h>
#include <ctype.h>

int laDoiXung(char str[], int left, int right){
    if(left >= right){
        return 1;
    }
    if(str[left] != str[right]){
        return 0;
    }
    return laDoiXung(str, left + 1, right - 1);
}

int main(){
    char str[1000];

    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);

    int len = strlen(str);
    str[len - 1] = '\0';
    len = strlen(str);

    if(laDoiXung(str, 0, len - 1)){
        printf("Palindrome valid");
    } else {
        printf("Palindrome invalid");
    }
    return 0;
}