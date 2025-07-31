#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Area {
    char name[50];
    Node* head;
} Area;

Area areas[MAX];
int areaCount = 0;
int visited[MAX];

Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

int findIndexByName(char* name) {
    for (int i = 0; i < areaCount; i++) {
        if (strcmp(areas[i].name, name) == 0) return i;
    }
    return -1;
}

void resetVisited() {
    for (int i = 0; i < MAX; i++) {
        visited[i] = 0;
    }
}

void addArea(char* name) {
    if (areaCount >= MAX) {
        printf("Danh sach khu vuc da day\n");
        return;
    }
    strcpy(areas[areaCount].name, name);
    areas[areaCount].head = NULL;
    areaCount++;
}

void addEdge(char* name1, char* name2) {
    int i = findIndexByName(name1);
    int j = findIndexByName(name2);
    if (i == -1 || j == -1) {
        printf("Mot hoac ca hai khu vuc khong ton tai\n");
        return;
    }

    Node* node1 = createNode(j);
    node1->next = areas[i].head;
    areas[i].head = node1;

    Node* node2 = createNode(i);
    node2->next = areas[j].head;
    areas[j].head = node2;
}

void hienThiDanhSachKe() {
    for (int i = 0; i < areaCount; i++) {
        printf("%s: ", areas[i].name);
        Node* current = areas[i].head;
        while (current != NULL) {
            printf("%s ", areas[current->vertex].name);
            current = current->next;
        }
        printf("\n");
    }
}

void BFS(char* startName) {
    int start = findIndexByName(startName);
    if (start == -1) {
        printf("Khu vuc khong ton tai.\n");
        return;
    }
    resetVisited();

    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS tu %s: ", startName);
    while (front < rear) {
        int u = queue[front++];
        printf("%s ", areas[u].name);

        for (Node* p = areas[u].head; p != NULL; p = p->next) {
            if (!visited[p->vertex]) {
                visited[p->vertex] = 1;
                queue[rear++] = p->vertex;
            }
        }
    }
    printf("\n");
}

void DFStil(int u) {
    visited[u] = 1;
    printf("%s ", areas[u].name);
    for (Node* p = areas[u].head; p != NULL; p = p->next) {
        if (!visited[p->vertex]) DFStil(p->vertex);
    }
}

void DFS(char* startName) {
    int start = findIndexByName(startName);
    if (start == -1) {
        printf("Khu vuc khong ton tai. \n");
        return;
    }

    resetVisited();
    printf("DFS tu %s: ", startName);
    DFStil(start);
    printf("\n");
}

int hasPath(char* name1, char* name2) {
    int start = findIndexByName(name1);
    int goal = findIndexByName(name2);
    if (start == -1 || goal == -1) return 0;

    resetVisited();
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int u = queue[front++];
        if (u == goal) return 1;
        for (Node* p = areas[u].head; p != NULL; p = p->next) {
            if (!visited[p->vertex]) {
                visited[p->vertex] = 1;
                queue[rear++] = p->vertex;
            }
        }
    }
    return 0;
}

int main() {
    int choice;
    char name1[50], name2[50];

    do {
        printf("\n--- MENU QUAN LY KHU DU LICH ---\n");
        printf("1. Them khu vuc\n");
        printf("2. Them duong di\n");
        printf("3. Hien thi danh sach ke\n");
        printf("4. Duyet BFS\n");
        printf("5. Duyet DFS\n");
        printf("6. Kiem tra duong di giua hai khu vuc\n");
        printf("7. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // Xử lý newline

        switch (choice) {
            case 1:
                printf("Nhap ten khu vuc: ");
                fgets(name1, 50, stdin);
                name1[strcspn(name1, "\n")] = '\0';
                addArea(name1);
                break;
            case 2:
                printf("Ten khu vuc 1: ");
                fgets(name1, 50, stdin);
                name1[strcspn(name1, "\n")] = '\0';
                printf("Ten khu vuc 2: ");
                fgets(name2, 50, stdin);
                name2[strcspn(name2, "\n")] = '\0';
                addEdge(name1, name2);
                break;
            case 3:
                hienThiDanhSachKe();
                break;
            case 4:
                printf("Bat dau tu khu vuc: ");
                fgets(name1, 50, stdin);
                name1[strcspn(name1, "\n")] = '\0';
                BFS(name1);
                break;
            case 5:
                printf("Bat dau tu khu vuc: ");
                fgets(name1, 50, stdin);
                name1[strcspn(name1, "\n")] = '\0';
                DFS(name1);
                break;
            case 6:
                printf("Nhap khu vuc A: ");
                fgets(name1, 50, stdin);
                name1[strcspn(name1, "\n")] = '\0';
                printf("Nhap khu vuc B: ");
                fgets(name2, 50, stdin);
                name2[strcspn(name2, "\n")] = '\0';
                if (hasPath(name1, name2)) {
                    printf("Co duong di\n");
                } else {
                    printf("Khong co duong di\n");
                }
                break;
            case 7:
                printf("Tam biet\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    } while (choice != 7);

    return 0;
}