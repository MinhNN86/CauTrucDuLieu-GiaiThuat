#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

typedef struct Task {
    int id;
    char title[SIZE];
    int priority;
    char deadline[SIZE];
} Task;

typedef struct ManageTask {
    Task task;
    struct ManageTask* next;
} ManageTask;

typedef struct HistoryTask {
    Task task;
    struct HistoryTask* prev;
    struct HistoryTask* next;
} HistoryTask;

ManageTask* head = NULL;
HistoryTask* historyHead = NULL;
int globalId = 1;

Task createTask() {
    Task task;
    task.id = globalId++;
    getchar();
    printf("Nhap tieu de nhiem vu: ");
    fgets(task.title, SIZE, stdin);
    task.title[strcspn(task.title, "\n")] = '\0';
    printf("Nhap thoi gian hoan thanh nhiem vu: ");
    fgets(task.deadline, SIZE, stdin);
    task.deadline[strcspn(task.deadline, "\n")] = '\0';
    printf("Nhap muc do uu tien: ");
    scanf("%d", &task.priority);
    return task;
}

void addTask() {
    Task task = createTask();
    ManageTask* newNode = (ManageTask*)malloc(sizeof(ManageTask));
    if (newNode == NULL) {
        printf("Loi cap phat");
        exit(1);
    }
    newNode->task = task;
    if (head == NULL) {
        head = newNode;
        newNode->next = NULL;
    } else {
        ManageTask* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = NULL;
    }
}

void displayTask() {
    if (head == NULL) {
        printf("Danh sach nhiem vu rong");
        return;
    }
    printf("Danh sach nhiem vu: \n");
    ManageTask* current = head;
    while (current != NULL) {
        printf("ID: %d\n", current->task.id);
        printf("Title: %s\n", current->task.title);
        printf("Priority: %d\n", current->task.priority);
        printf("Deadline: %s\n", current->task.deadline);
        printf("-------------------");
        current = current->next;
    }
}

void deleteTask() {
    if (head == NULL) {
        printf("Danh sach nhiem vu rong");
        return;
    }
    int id;
    printf("Nhap id can xoa: ");
    scanf("%d", &id);
    ManageTask* current = head;
    ManageTask* prev = NULL;

    while (current != NULL) {
        if (current->task.id == id) {
            if (current == head) {
                head = head->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Xoa phan tu thanh cong");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Khong tim thay nhiem vu");
}

void updateTask() {
    if (head == NULL) {
        printf("Danh sach nhiem vu rong");
        return;
    }
    int id;
    printf("Nhap id can xoa: ");
    scanf("%d", &id);
    ManageTask* current = head;

    while (current != NULL) {
        if (current->task.id == id) {
            getchar();
            printf("Nhap tieu de nhiem vu moi: ");
            fgets(current->task.title, sizeof(current->task.title), stdin);
            current->task.title[strcspn(current->task.title, "\n")] = '\0';
            printf("Nhap deadline moi: ");
            fgets(current->task.deadline, sizeof(current->task.deadline), stdin);
            current->task.deadline[strcspn(current->task.deadline, "\n")] = '\0';
            printf("Nhap muc do uu tien: ");
            scanf("%d", &current->task.priority);
        }
        current = current->next;
    }
    printf("Khong tim thay nhiem vu");
}

void checkCompeleteTask() {
    if (head == NULL) {
        printf("Danh sach nhiem vu rong");
        return;
    }
    int id;
    printf("Nhap id can danh dau hoan thanh: ");
    scanf("%d", &id);
    ManageTask* current = head;
    ManageTask* prev = NULL;

    while (current != NULL) {
        if (current->task.id == id) {
            if (current == head) {
                head = head->next;
            } else {
                prev->next = current->next;
            }

            HistoryTask* newNode = (HistoryTask*)malloc(sizeof(HistoryTask));
            if (newNode == NULL) {
                printf("Loi cap phat");
                exit(0);
            }
            newNode->task = current->task;
            if (historyHead == NULL) {
                historyHead = newNode;
                newNode->next = newNode->prev = NULL;
            } else {
                HistoryTask* historyNode = historyHead;
                while (historyNode->next != NULL) {
                    historyNode = historyNode->next;
                }
                historyNode->next = newNode;
                newNode->prev = historyNode;
                newNode->next = NULL;
            }
        }
        prev = current;
        current = current->next;
    }
}

void sortTask() {
    if (head == NULL || head->next == NULL) {
        printf("Danh sach nhiem vu rong hoac co 1");
        return;
    }
    int swapped;
    ManageTask* ptr1;
    ManageTask* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->task.priority > ptr1->next->task.priority) {
                Task temp = ptr1->task;
                ptr1->task = ptr1->next->task;
                ptr1->next->task = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    printf("Da sap xep danh sach");
}

void searchTask() {
    if (head == NULL) {
        printf("Danh sach nhiem vu rong");
        return;
    }
    char nameSearch[SIZE];
    getchar();
    printf("Nhap tieu de can tim: ");
    fgets(nameSearch, SIZE, stdin);
    nameSearch[strcspn(nameSearch, "\n")] = '\0';

    int found = 0;
    ManageTask* current = head;
    while (current != NULL) {
        if (strstr(current->task.title, nameSearch) != NULL) {
            printf("\nTim thay nhiem vu:\n");
            printf("ID: %d\n", current->task.id);
            printf("Title: %s\n", current->task.title);
            printf("Priority: %d\n", current->task.priority);
            printf("Deadline: %s\n", current->task.deadline);
            printf("-------------------\n");
            found = 1;
        }
        current = current->next;
    }
    if (!found) {
        printf("Khong tim thay nhiem vu nao");
    }
}
int main() {
    int choice;
    while (1) {
        printf("\n____TASK MANAGER_____\n");
        printf("1. Them moi nhiem vu\n");
        printf("2. Hien thi nhiem vu\n");
        printf("3. Xoa nhiem vu\n");
        printf("4. Cap nhat nhiem vu\n");
        printf("5. Danh dau nhiem vu hoan thanh\n");
        printf("6. Sap xep nhiem vu\n");
        printf("7. Tim kiem nhiem vu\n");
        printf("8. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTask();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                updateTask();
                break;
            case 5:
                checkCompeleteTask();
                break;
            case 6:
                sortTask();
                break;
            case 7:
                searchTask();
                break;
            case 8:
                printf("Tam biet");
                return 0;
            default:
                printf("Lua chon khong hop le");
                break;
        }
    }
}