#include <stdio.h>

int checkDinhKe(int v, int edges[v][2], int valueFind) {
    int count = 0;
    for (int i = 0; i < v; i++) {
        if (edges[i][0] == valueFind || edges[i][1] == valueFind) {
            count++;
        }
    }
    return count;
}

int main() {
    int n, v;
    printf(" NHap so dinh va so canh: ");
    scanf("%d %d", &n, &v);
    if (n < 0 || v > 100) {
        printf("So dinh hoac canh khong hop le");
        return 1;
    }
    int edges[v][2];
    printf("Nhap cac canh: \n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &edges[i][j]);
        }
    }
    int checkDinh;
    printf("Nhap dinh k muon kiem tra: ");
    scanf("%d", &checkDinh);
    printf("So dinh ke voi %d la: %d", checkDinh, checkDinhKe(v, edges,checkDinh));
    return 0;
}