#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("n = ");
    scanf("%d", &n);
    if(n <= 0 || n >= 1000){
        printf("So luong phan tu khong hop le");
        return 1;
    }
    int* arr = (int*) malloc (n * sizeof(int));
    if(arr == NULL){
        printf("Cap phat bo nho that bai\n");
        return 1;
    }
    for(int i = 0; i < n; i++){
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    int maxValue = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > maxValue){
            maxValue = arr[i];
        }
    }
    printf("max = %d", maxValue);
    free(arr);
    return 0;
}