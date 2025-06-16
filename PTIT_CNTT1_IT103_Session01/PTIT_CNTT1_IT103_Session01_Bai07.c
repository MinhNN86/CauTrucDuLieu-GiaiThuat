#include <stdio.h>
int soSanhCapPtu(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] == arr[j]){
                return 1;
            }
        }
    }
    return 0;
    /*
    + Thời gian: O(n^2)
    + Không gian: O(1)
    */
}
int mangDanhDau(int arr[], int n){
    int mark[1001] = {0};
    for(int i = 0; i < n; i++){
        if(mark[arr[i]] == 1){
            return 1;
        }
        mark[arr[i]] = 1;
    }
    return 0;
    /*
    + Thời gian: O(n)
    + Không gian: O(1)
    */
}
int main() {
    int arr[] = {3, 17, 8, 25, 8, 42};
    int n = sizeof(arr) / sizeof(arr[0]);

    if(soSanhCapPtu(arr, n)){
        printf("Cach 1: Co phan tu trung lap\n");
    } else {
        printf("Cach 2: Khong co phan tu trung lap\n");
    }
    return 0;
}