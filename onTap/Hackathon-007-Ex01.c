#include <iso646.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct Order {
    int id;
    char customer[MAX];
    int status;
    long long total;
} Order;

typedef struct ManageOrder {
    Order order;
    struct ManageOrder* prev;
    struct ManageOrder* next;
} ManageOrder;

typedef struct HistoryOrder {
    Order order;
    struct HistoryOrder* next;
} HistoryOrder;

ManageOrder* head = NULL;
HistoryOrder* historyHead = NULL;
int globalId = 1;

int isEmpty() {
    return head == NULL;
}

Order createOrder() {
    Order order;
    order.id = globalId++;
    getchar();
    printf("Nhap ten khac hang: ");
    fgets(order.customer, MAX, stdin);
    order.customer[strcspn(order.customer, "\n")] = '\0';
    printf("Nhap tong tien don hang: ");
    scanf("%lld", &order.total);
    order.status = 0;
    return order;
}

void addOrder() {
    Order order = createOrder();
    ManageOrder* newNode = (ManageOrder*)malloc(sizeof(ManageOrder));
    if (newNode == NULL) {
        printf("loi cap phat");
        exit(0);
    }
    newNode->order = order;
    if (head == NULL) {
        newNode->prev = newNode->next = NULL;
        head = newNode;
    } else {
        ManageOrder* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        newNode->next = NULL;
    }
}

void displayOrder() {
    if (head == NULL && historyHead == NULL) {
        printf("Danh sach rong");
        return;
    }

    printf("\n---Don chua giao---\n");
    if (head == NULL) {
        printf("Khong co don nao");
    } else {
        ManageOrder* current = head;
        while (current != NULL) {
            printf("ID: %d\n", current->order.id);
            printf("Customer: %s\n", current->order.customer);
            printf("Status: Chua giao\n");
            printf("Total: %lld\n", current->order.total);
            printf("----------------------------------------\n");
            current = current->next;
        }
    }

    printf("\n---Don da giao---\n");
    if (historyHead == NULL) {
        printf("Khong co don nao");
    } else {
        HistoryOrder* temp = historyHead;
        while (temp != NULL) {
            printf("ID: %d\n", temp->order.id);
            printf("Customer: %s\n", temp->order.customer);
            printf("Status: Da giao\n");
            printf("Total: %lld\n", temp->order.total);
            printf("----------------------------------------\n");
            temp = temp->next;
        }
    }
}

void removeOrder() {
    if (isEmpty()) return;
    int id;
    printf("Nhap ID can xoa: ");
    scanf("%d", &id);
    ManageOrder* current = head;
    while (current != NULL) {
        if (current->order.id == id) {
            if (current == head) {
                head = head->next;
                head->prev = NULL;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
            printf("Xoa don hang thanh cong");
            return;
        }
        current = current->next;
    }
    printf("Khong tim thay don hang");
}

void updateOrder() {
    if (isEmpty() && historyHead == NULL) return;
    int id;
    printf("Nhap ID can xoa: ");
    scanf("%d", &id);
    ManageOrder* current = head;
    HistoryOrder* temp = historyHead;
    while (current != NULL) {
        if (current->order.id == id) {
            getchar();
            printf("Cap nhat ten khach hang moi: ");
            fgets(current->order.customer, sizeof(current->order.customer), stdin);
            current->order.customer[strcspn(current->order.customer, "\n")] = '\0';
            printf("Cap nhat tong tien don hang: ");
            scanf("%lld", &current->order.total);
            printf("Cap nhat thanh cong");
            return;
        }
        current = current->next;
    }
    while (temp != NULL) {
        if (temp->order.id == id) {
            getchar();
            printf("Cap nhat ten khach hang moi: ");
            fgets(temp->order.customer, sizeof(temp->order.customer), stdin);
            temp->order.customer[strcspn(temp->order.customer, "\n")] = '\0';
            printf("Cap nhat tong tien don hang: ");
            scanf("%lld", &temp->order.total);
            printf("Cap nhat thanh cong");
            return;
        }
        temp = temp->next;
    }
    printf("Khong tim thay don hang");
}

void markComplete() {
    if (isEmpty()) return;
    int id;
    printf("Nhap id don hang can chuyen trang thai: ");
    scanf("%d", &id);

    ManageOrder* current = head;
    while (current) {
        if (current->order.id == id) {
            if (current == head) {
                head = head->next;
                head->prev = NULL;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;

            HistoryOrder* newNode = (HistoryOrder*)malloc(sizeof(HistoryOrder));
            newNode->order = current->order;
            newNode->next = NULL;

            if (historyHead == NULL) {
                historyHead = newNode;
            } else {
                HistoryOrder* temp = historyHead;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = newNode;
            }
            free(current);
            printf("Da danh dau don hang hoan thanh");
            return;
        }
        current = current->next;
    }
    printf("Khong tim thay don hang");
}

void sortOrder() {
    if (isEmpty() || head->next == NULL) {
        printf("Danh sach don hang chua giao rong hoac co 1");
    } else {
        int swapped;
        ManageOrder* ptr1;
        ManageOrder* lptr = NULL;

        do {
            swapped = 0;
            ptr1 = head;
            while (ptr1->next != lptr) {
                if (ptr1->order.total > ptr1->next->order.total) {
                    Order temp = ptr1->order;
                    ptr1->order = ptr1->next->order;
                    ptr1->next->order = temp;
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
        printf("Da sap xep don hang chua giao\n");
    }

    if (historyHead == NULL || historyHead->next == NULL) {
        printf("Danh sach don hang da giao rong hoac co 1");
    } else {
        int swapped;
        HistoryOrder* ptr1;
        HistoryOrder* lptr = NULL;

        do {
            swapped = 0;
            ptr1 = historyHead;
            while (ptr1->next != lptr) {
                if (ptr1->order.total > ptr1->next->order.total) {
                    Order temp = ptr1->order;
                    ptr1->order = ptr1->next->order;
                    ptr1->next->order = temp;
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
        printf("Da sap xep don hang da giao\n");
    }
}

void searchOrder() {
    int found = 0;
    char searchName[MAX];
    getchar();
    fgets(searchName, MAX, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';
    if (!isEmpty()) {
        ManageOrder* current = head;
        while (current != NULL) {
            if (strstr(current->order.customer, searchName) != NULL) {
                printf("Tim thay don hang:\n");
                printf("ID: %d\n", current->order.id);
                printf("Customer: %s\n", current->order.customer);
                printf("Status: Chua giao\n");
                printf("Total: %lld\n", current->order.total);
                printf("-------------------\n");
                found = 1;
            }
            current = current->next;
        }
    }
    if (historyHead != NULL) {
        HistoryOrder* current = historyHead;
        while (current != NULL) {
            if (strstr(current->order.customer, searchName) != NULL) {
                printf("Tim thay don hang:\n");
                printf("ID: %d\n", current->order.id);
                printf("Customer: %s\n", current->order.customer);
                printf("Status: Da giao\n");
                printf("Total: %lld\n", current->order.total);
                printf("-------------------\n");
                found = 1;
            }
            current = current->next;
        }
    }
    if (!found) {
        printf("Khong tim thay don hang");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n_______ORDER MANAGER_______\n");
        printf("1. Them don hang moi\n");
        printf("2. Hien thi danh sach don hang\n");
        printf("3. Xoa don hang\n");
        printf("4. Cap nhat thong tin don hang\n");
        printf("5. Danh dau don hang da duoc giao\n");
        printf("6. Sap xep don hang theo tong tien\n");
        printf("7. Tim kiem don hang\n");
        printf("8. Thoat chuong trinh\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addOrder();
                break;
            case 2:
                displayOrder();
                break;
            case 3:
                removeOrder();
                break;
            case 4:
                updateOrder();
                break;
            case 5:
                markComplete();
                break;
            case 6:
                sortOrder();
                break;
            case 7:
                searchOrder();
                break;
            case 8:
                printf("Tam biet");
                return 0;
            default:
                printf("Lua chon khong hop le");
                break;
        }
    }
    return 0;
}