#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Course {
    int id;
    char title[100];
    int credit;
} Course;

// lket đơn ( dang hoc )
typedef struct SNode {
    Course course;
    struct SNode* next;
} SNode;

// lket doi ( hoan thanh )
typedef struct DNode {
    Course course;
    struct DNode* prev;
    struct DNode* next;
} DNode;

SNode* head = NULL;
DNode* completedHead = NULL;

Course createCourse() {
    Course c;
    printf("Nhap ID: ");
    scanf("%d", &c.id);
    getchar();
    printf("Nhap ten khoa hoc ");
    fgets(c.title, 100, stdin);
    c.title[strlen(c.title) - 1] = '\0';
    printf("Nhap so tin chi: ");
    scanf("%d", &c.credit);
    return c;
}

void addCourse() {
    Course c = createCourse();
    SNode* newNode = (SNode*)malloc(sizeof(SNode));
    newNode->course = c;
    newNode->next = head;
    head = newNode;
    printf("Them khoa hoc thanh cong.\n");
}

void displayCourses() {
    if (!head) {
        printf("Danh sach rong.\n");
        return;
    }
    printf("Danh scah khoa hoc dang hoc: \n");
    SNode* current = head;
    while (current) {
        printf("- ID: %d | Ten: %s | Tin chi: %d\n", current->course.id, current->course.title, current->course.credit);
        current = current->next;
    }
}

void deleteCourse() {
    int id;
    printf("Nhap ID khoa hoc can xoa: ");
    scanf("%d", &id);
    SNode *current = head;
    SNode *prev = NULL;
    while (current) {
        if (current -> course.id == id) {
            if (prev == NULL) {
                head = current -> next;
            } else {
                prev -> next = current -> next;
            }
            free(current);
            printf("Da xoa khoa hoc ID %d\n", id);
            return;
        }
        prev = current;
        current = current -> next;
    }
    printf("Khong tim thay khoa hoc ID %d\n", id);
}

void updateCourse() {
    int id;
    printf("Nhap ID khoa hoc can cap nhat: ");
    scanf("%d", &id);
    getchar();
    SNode* current = head;
    while (current) {
        if (current->course.id == id) {
            printf("Nhap ten moi: ");
            fgets(current->course.title, sizeof(current->course.title), stdin);
            current->course.title[strlen(current->course.title) -1] = '\0';
            printf("Nhap so tin chi moi: ");
            scanf("%d", &current->course.credit);
            printf("Da cap nhat khoa hoc\n");
            return;
        }
        current = current -> next;
    }
    printf("Khong tim thay khoa hoc ID %d\n", id);
}

void markAsCompleted() {
    int id;
    printf("Nhap ID khoa hoc da hoan thanh: ");
    scanf("%d", &id);

    SNode *current = head;
    SNode *prev = NULL;
    while (current) {
        if (current->course.id == id) {
            if (prev == NULL) {
                head = current -> next;
            } else {
                prev->next = current->next;
            }
            DNode* newNode = (DNode*)malloc(sizeof(DNode));
            newNode->course = current->course;
            newNode->prev = NULL;
            newNode->next = completedHead;
            if (completedHead) {
                completedHead->prev = newNode;
            }
            completedHead = newNode;
            free(current);
            printf("Da danh dau hoan thanh");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Khong tim thay khoa hoc ID %d\n", id);
}

void sortCoursesByCredit() {
    if (!head || head->next == NULL) {
        return;
    }
    SNode *current = head;
    SNode *prev = NULL;
    while (current && current->next) {
        if (current->course.credit > current->next->course.credit) {
            SNode* temp = current->next;
            current->next = temp->next;
            temp->next = current;
            if (prev == NULL) {
                head = temp;
            } else {
                prev->next = temp;
            }
            prev = temp;
        } else {
            prev = current;
            current = current -> next;
        }
    }
    printf("Da sap xem theo tin chi\n");
}

void searchByTitle() {
    char searchCourse[100];
    getchar();
    printf("Nhap tu khoa tim kiem: ");
    fgets(searchCourse, 100, stdin);
    searchCourse[strlen(searchCourse) -1] = '\0';

    SNode* current = head;
    int found = 0;
    while (current) {
        if (strstr(current->course.title, searchCourse)) {
            printf("- ID: %d | Ten: %s | Tin chi: %d\n", current->course.id, current->course.title, current->course.credit);
            found = 1;
        }
        current = current -> next;
    }
    if (!found) {
        printf("Khong tim thay ten khoa hoc: %s\n", searchCourse);
    }
}

void freeMemory() {
    SNode* temp1;
    while (head) {
        temp1 = head;
        head = head->next;
        free(temp1);
    }

    DNode* temp2;
    while (completedHead) {
        temp2 = completedHead;
        completedHead = completedHead->next;
        free(temp2);
    }
}

void menu() {
    int choice;
    do {
        printf("\n===== COURSE MANAGER =====\n");
        printf("1. Them khoa hoc\n");
        printf("2. Hien thi danh sach khoa hoc\n");
        printf("3. Xoa khoa hoc\n");
        printf("4. Cap nhat thong tin khoa hoc\n");
        printf("5. Danh dau khoa hoc da hoan thanh\n");
        printf("6. Sap xep theo tin chi\n");
        printf("7. Tim kiem khoa hoc theo ten\n");
        printf("8. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addCourse(); break;
            case 2: displayCourses(); break;
            case 3: deleteCourse(); break;
            case 4: updateCourse(); break;
            case 5: markAsCompleted(); break;
            case 6: sortCoursesByCredit(); break;
            case 7: searchByTitle(); break;
            case 8: freeMemory(); printf("Da thoat.\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (choice != 8);
}

int main() {
    menu();
    return 0;
}