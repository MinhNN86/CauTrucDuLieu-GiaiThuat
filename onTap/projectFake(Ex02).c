#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int price;
    struct Node* left;
    struct Node* right;
} Node;

Node* insert(Node* root, int price) {
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->price = price;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (price < root->price) {
        root->left = insert(root->left, price);
    } else if (price > root->price) {
        root->right = insert(root->right, price);
    } else {
        printf("Gia da ton tai");
    }
    return root;
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* delete(Node* root, int price){
    if (root == NULL) {
        return NULL;
    }
    if (price < root->price) {
        root->left = delete(root->left, price);
    } else if (price > root->price) {
        root->right = delete(root->right, price);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        root->price = temp->price;
        root->right = delete(root->right, temp->price);
    }
    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->price);
        inorder(root->right);
    }
}

int countSingleNodes(Node* root) {
    if (root == NULL) return 0;
    int left = countSingleNodes(root->left);
    int right = countSingleNodes(root->right);
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) {
        return 1 + left + right;
    }
    return left + right;
}

int height(Node* root) {
    if (root == NULL) return 0;
    int left = height(root->left);
    int right = height(root->right);
    return 1 + (left > right ? left : right);
}

int main() {
    Node* root = NULL;
    int choice, price;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Them san pham\n");
        printf("2. Xoa san pham\n");
        printf("3. Danh sach san pham\n");
        printf("4. Dem san phan don le\n");
        printf("5. Tinh so tang cay\n");
        printf("6. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia san pham: ");
                scanf("%d", &price);
                root = insert(root, price);
                break;
            case 2:
                printf("Nhap gia can xoa: ");
                scanf("%d", &price);
                root = delete(root, price);
                break;
            case 3:
                printf("Danh sach san pham: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("So san pham don le: %d\n", countSingleNodes(root));
                break;
            case 5:
                printf("So tang cua cay: %d\n", height(root));
                break;
            case 6:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    } while (choice != 6);

    return 0;
}
