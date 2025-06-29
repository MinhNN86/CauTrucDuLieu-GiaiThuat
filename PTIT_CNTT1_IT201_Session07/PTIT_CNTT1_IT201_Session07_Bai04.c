#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    printf("Nhap chuoi ky tu: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';

    int len = strlen(str);

    int space = 1;
    for (int i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            space = 0;
            break;
        }
    }

    if (len == 0 || space) {
        printf("Choi khong hop le\n");
        return 1;
    }

    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }

    printf("Sau khi sap xep: %s\n", str);

    return 0;
}