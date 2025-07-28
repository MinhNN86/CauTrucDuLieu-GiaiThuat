#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

typedef struct Student {
    int id;
    char name[MAX];
    bool status;
    int avg;
} Student;

typedef struct Node {
    Student data;
    struct Node* next;
    struct Node* prev;
} Node;

Student studentList[MAX];
int count = 0;

Node* inactiveHead = NULL;
Node* inactiveTail = NULL;

void addInactiveStudent(Student s) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = s;
    newNode->prev = inactiveHead;
    newNode->next = NULL;
    if (inactiveTail != NULL) {
        inactiveTail->next = newNode;
    } else {
        inactiveHead = newNode;
    }
    inactiveTail = newNode;
}

void removeFromInactive(int id) {
    Node* current = inactiveHead;
    while (current != NULL) {
        if (current->data.id == id) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                inactiveHead = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                inactiveTail = current->prev;
            }

            free(current);
            return;
        }
        current = current->next;
    }
}

void addStudent() {
    if (count >= MAX) {
        printf("Danh sach da day");
        return;
    }
    Student s;
    if (count == 0) {
        s.id = 1;
    } else {
        s.id = studentList[count - 1].id + 1;
    }

    getchar();
    printf("Nhap ten: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    printf("Diem trung binh: ");
    scanf("%d", &s.avg);

    while (1) {
        int status;
        printf("Status: \n");
        printf("1. True(Active)\n");
        printf("2. False(Inactive)\n");
        printf("Lua chon: ");
        scanf("%d", &status);
        if (status == 1) {
            s.status = true;
        } else if (status == 2) {
            s.status = false;
            addInactiveStudent(s);
        } else {
            printf("Lua chon khong hop le");
        }
        break;
    }

    studentList[count++] = s;
    printf("Them sinh vien thanh cong");
}

void displayStudent() {
    printf("\n---Danh Sach Sinh Vien---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", studentList[i].id);
        printf("Ten: %s\n", studentList[i].name);
        printf("Trang thai: %s\n", studentList[i].status ? "Hoat dong" : "Khong hoat dong");
        printf("Dien trung binh: %d\n", studentList[i].avg);
    }
}

void deleteStudent() {
    int id;
    printf("Nhap ID sinh vien can xoa: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (studentList[i].id == id) {
            if (studentList[i].status == false) {
                removeFromInactive(id);
            }
            for (int j = i; j < count - 1; j++) {
                studentList[j] = studentList[j + 1];
            }
            count--;
            printf("Da xoa sinh vien\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien.\n");
}

void updateStudent() {
    int id;
    printf("Nhap ID sinh vien can cap nhat: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (studentList[i].id == id) {
            getchar();
            printf("Nhap ten moi: ");
            fgets(studentList[i].name, sizeof(studentList[i].name), stdin);
            studentList[i].name[strcspn(studentList[i].name, "\n")] = '\0';
            printf("Nhap dien TB moi: ");
            scanf("%d", &studentList[i].avg);
            printf("Cap nhat thanh cong");
            return;
        }
    }
    printf("Khong tim thay sinh vien");
}

void toggleStatus() {
    int id;
    printf("Nhap ID sinh vien can doi trang thai: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (studentList[i].id == id) {
            studentList[i].status = !studentList[i].status;
            if (!studentList[i].status) {
                addInactiveStudent(studentList[i]);;
            } else {
                removeFromInactive(id);
            }
            printf("Da thay doi trang thai\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien\n");
}

void merge(Student arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    Student L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].avg <= R[j].avg) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(Student arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void sortStudent() {
    mergeSort(studentList, 0, count - 1);
    printf("Da sap xep sinh vien");
}

//Sử dụng tìm kiếm tuần tự vì sắp sếp sinh viên theo điểm trung bình
void searchStudent() {
    int id;
    printf("Nhap ID can tim: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (studentList[i].id == id) {
            printf("ID: %d\n", studentList[i].id);
            printf("Ten: %s\n", studentList[i].name);
            printf("Trang thai: %s\n", studentList[i].status ? "Hoat dong" : "Khong hoat dong");
            printf("Dien trung binh: %d\n", studentList[i].avg);
            return;
        }
    }
    printf("Khong tim thay sinh vien\n");
}

int main() {
    int luaChon;
    while (1) {
        printf("\n————————— STUDENT MANAGER —————————\n");
        printf("1. Them sinh vien\n");
        printf("2. Hien thi danh sach sinh vien\n");
        printf("3. Xoa sinh vien\n");
        printf("4. Cap nhat thong tin sinh vien\n");
        printf("5. Thay doi trang thai sinh vien\n");
        printf("6. Sap xep sinh vien\n");
        printf("7. Tim kiem sinh vien\n");
        printf("8. Thoat\n");
        printf("Chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudent();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                toggleStatus();
                break;
            case 6:
                sortStudent();
                break;
            case 7:
                searchStudent();
                break;
            case 8:
                printf("Tam biet!");
                return 0;
            default:
                printf("Lua chon khong hop le!\n");
        }
    }
}