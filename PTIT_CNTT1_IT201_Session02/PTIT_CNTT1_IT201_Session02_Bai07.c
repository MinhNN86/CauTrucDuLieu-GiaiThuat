#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Nhap so phan tu trong mang: ");
    scanf("%d", &n);
    if(n <= 0 || n > 100){
        printf("So phan tu khong hop le\n");
        return 1;
    }
    int* arr = (int*)malloc(n * sizeof(int));
    if(arr == NULL){
        printf("Cap phat bo nho that bai\n");
        return 1;
    }
    for(int i = 0; i < n; i++){
        printf("Nhap gia tri arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int valueSearchTotal;
    printf("Nhap so de tim tong cac gia tri trong mang: ");
    scanf("%d", &valueSearchTotal);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == valueSearchTotal) {
                printf("%d, %d\n", arr[i], arr[j]);
            }
        }
    }

    free(arr);
    return 0;
}
