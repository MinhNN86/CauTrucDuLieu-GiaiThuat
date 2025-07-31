#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* insert(Node* root, int value) {
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->value = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    } else {
        printf("Gia tri da ton tai");
    }
    return root;
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root->left = NULL;
    }
    return root;
}

Node* delete(Node* root, int value){
    if (root == NULL) {
        return NULL;
    }

    if (value < root->value) {
        root->left = delete(root->left, value);
    } else if (value > root->value) {
        root->right = delete(root->right, value);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* min = findMin(root->right);
        root->value = min->value;
        root->right = delete(root->right, min->value);
    }
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

int countLeaves(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int left = countLeaves(root->left);
    int right = countLeaves(root->right);
    if (root->left == NULL && root->right == NULL) {
        return 1+left+right;
    }
    return left+right;
}

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return 1 + (left > right ? left : right);
}

int main() {
    int choice, value;
    Node* root = NULL;
    while (1) {
        printf("\n___BINARY SEARCH TREE MANAGER___\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. TRAVERSE\n");
        printf("4. COUNT LEAVES\n");
        printf("5. HEIGHT\n");
        printf("6. EXIT\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Nhap gia tri can chen: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Nhap gia tri can xoa: ");
                scanf("%d", &value);
                root = delete(root, value);
                break;
            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("So la co trong cay: %d", countLeaves(root));
                printf("\n");
                break;
            case 5:
                printf("Chieu cao cay la: %d", height(root));
                printf("\n");
                break;
            case 6:
                printf("Tam biet\n");
                return 0;
            default:
                printf("Lua chon khong hop le");
        }
    }

}