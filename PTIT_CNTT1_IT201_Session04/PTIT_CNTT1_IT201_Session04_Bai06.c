#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[100];
    int age;
} Student;

int main() {
    Student students[5];

    for (int i = 0; i < 5; i++) {
        printf("Nhap thong tin sinh vien thu %d: \n", i + 1);
        students[i].id = i + 1;
        printf("Name: ");
        fgets(students[i].name, 100, stdin);
        students[i].name[strlen(students[i].name) - 1] = '\0';
        printf("Age: ");
        scanf("%d", &students[i].age);
        getchar();
    }

    int searchId;
    
    scanf("%d", &searchId);
    int found = 0;
    for (int i = 0; i < 5; i++) {
        if (students[i].id == searchId) {
            printf("{ id: %d, name: \"%s\", age: %d }", students[i].id, students[i].name, students[i].age);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Sinh vien khong ton tai\n");
    }
    return 0;
}