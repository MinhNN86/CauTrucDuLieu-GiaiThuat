#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    int id;
    char title[100];
    int priority;
    char deadline[100];
} Task;

typedef struct ManagerTask {
    Task task;
    struct ManagerTask* next;
} ManagerTask;

typedef struct HistoryTask {
    Task task;
    struct HistoryTask* prev;
    struct HistoryTask* next;
} HistoryTask;

ManagerTask* head = NULL;
HistoryTask* headHistory = NULL;

Task createTask() {
    Task task;
    printf("Nhap ID: ");
    scanf("%d", task.id);
    getchar();
    printf("Nhap tieu de nhiem vu: ");
    fgets(task.title, 100, stdin);
    task.title[strlen(task.title) - 1] = '\0';
    printf("Nhap thoi gian hoan thanh nhiem vu: ");
    fgets(task.deadline, 100, stdin);
    task.deadline[strlen(task.deadline) - 1] = '\0';
    printf("Nhap muc do uu tien cua nhiem vu: ");
    scanf("%d", &task.priority);
    return task;
}

void addTask() {
    Task task = createTask();
    ManagerTask* newNode = (ManagerTask*)malloc(sizeof(ManagerTask));
    newNode->task = task;
    newNode->next = head;
    head = newNode;
    printf("Them nhiem vu thanh cong\n");
}

void displayTask() {
    if (!head) {
        printf("Danh sach nhien vu trong");
        return;
    }
    printf("Danh sach nhiem vu: \n");
    ManagerTask* current = head;
    while (current) {
        printf("- ID: %d | Ten: %s | Do uu tien: %d | Thoi gian hoan thanh: %s\n", current->task.id, current->task.title, current->task.priority, current->task.deadline);
        current = current->next;
    }
}

void updateTask() {
    int id;
    printf("Nhap ID nhiem vu can chinh sua: ");
    scanf("%d", &id);
    getchar();
    ManagerTask* current = head;
    while (current) {
        if (current->task.id == id) {
            printf("Nhap tieu de moi: ");
            fgets(current->task.title, sizeof(current->task.title), stdin);
            current->task.title[strlen(current->task.title) - 1] = '\0';
            printf("Nhap deadline moi: ");
            fgets(current->task.deadline, sizeof(current->task.deadline), stdin);
            current->task.deadline[strlen(current->task.deadline) - 1] = '\0';
            printf("Nhap do uu tien moi: ");
            scanf("%d", &current->task.priority);
            printf("Da cap nhat nhiem vu\n");
            return;
        }
        current = current->next;
    }
    printf("Khong tim thay nhiem vu id %d\n", id);
}



int main() {

    return 0;
}