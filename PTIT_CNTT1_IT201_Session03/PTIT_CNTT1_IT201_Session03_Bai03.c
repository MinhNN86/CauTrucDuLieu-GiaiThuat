#include <stdio.h>
#include <stdlib.h>

void trungBinhCongSoChan(int arr[], int n) {
    int tongSoChan = 0;
    int soLuongSoChan = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            tongSoChan += arr[i];
            soLuongSoChan++;
        }
    }
    if (soLuongSoChan > 0) {
        float trungBinhCong = (float)tongSoChan / soLuongSoChan;
        printf("Average = %.2f\n", trungBinhCong);
    } else {
        printf("Khong co so chan trong mang.\n");
    }
}
int main() {
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
    trungBinhCongSoChan(arr, n);
    free(arr);
    return 0;
}