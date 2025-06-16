#include <stdio.h>

int main(){
    int arr[] = {5, 3, 9, 5, 2, 9, 5, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count[1001] = {0};
    for (int i = 0; i < n; i++){
        count[arr[i]]++;
    }
    int maxCount = 0;
    int ptuNhieuNhat = -1;
    for (int i = 0; i <= 1000; i++){
        if(count[i] > maxCount){
            maxCount = count[i];
            ptuNhieuNhat = i;
        }
    }
    printf("Phan tu xuat hien nhieu nhat la: %d", ptuNhieuNhat);
    return 0;
    
    /*
    + Thời gian: O(n)
    + Không gian: O(1)
    */
}