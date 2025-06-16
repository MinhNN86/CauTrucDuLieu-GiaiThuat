#include <stdio.h>

void printDoble(int n) {
    int i = 1;
    while(i < n){
        printf("$d\n", i);
        i *= 2;
    }
}

// Độ phức tạp thời gian O(logn)
int main() {
    return 0;
}