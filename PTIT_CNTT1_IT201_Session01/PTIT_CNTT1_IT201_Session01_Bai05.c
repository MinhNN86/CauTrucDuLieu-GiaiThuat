#include <stdio.h>

int main(){
    int arr[10] = {37, 92, 14, 58, 6, 71, 23, 85, 49, 10};
    int n = 10;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Mang da sap xep: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

/* 
+ Thời gian: O(n^2)
+ Không gian: O(1)
*/
