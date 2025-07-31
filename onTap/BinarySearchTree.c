#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        printf("gia tri da ton tai");
    }
    return root;
}

Node* findMin(Node* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

Node* delete(Node* root, int data){
    if (root == NULL) {
        printf("Khong tim thay gia tri de xoa\n");
        return NULL;
    }
    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
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
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
}

typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void enQueue(Queue* q, Node* node) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->treeNode = node;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

Node* deQueue(Queue* q) {
    if (isEmpty(q)) return NULL;
    QueueNode* temp = q->front;
    Node* node = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return node;
}

void levelOrder(Node* root) {
    if (root == NULL) return;
    Queue q;
    initQueue(&q);
    enQueue(&q, root);
    while (!isEmpty(&q)) {
        Node* node = deQueue(&q);
        printf("%d ", node->data);
        if (node->left != NULL) {
            enQueue(&q, node->left);
        }
        if (node->right != NULL) {
            enQueue(&q, node->right);
        }
    }
}

int countLeaves(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int treeHeight(Node* root) {
    if (root == NULL) return -1;
    int left = treeHeight(root->left);
    int right = treeHeight(root->right);
    return (left > right ? left : right) + 1;
}



int main() {
    Node* root = NULL;
    int choice, value;
    while (1) {
        printf("\n_____BINARY SEARCH TREE MANAGER_____\n");
        printf("1. Them gia tri x\n");
        printf("2. Xoa gia tri x\n");
        printf("3. Duyet gia tri\n");
        printf("4. Dem la\n");
        printf("5. Chieu cao\n");
        printf("6. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                break;
            case 2:
                printf("Nhap gia tri can xoa: ");
                scanf("%d", &value);
                root = delete(root, value);
                break;
            case 3:
                if (root == NULL) {
                    printf("Cay rong");
                } else {
                    printf("Inorder: ");
                    inorder(root);
                    printf("\nPostorder: ");
                    postorder(root);
                    printf("\nLevelOrder: ");
                    levelOrder(root);
                    printf("\n");
                }
                break;
            case 4:
                printf("So luong la: %d\n", countLeaves(root));
                break;
            case 5:
                printf("Chieu cao cay: %d\n", treeHeight(root));
                break;
            case 6:
                printf("Tam biet");
                return 0;
            default:
                printf("Lua chon khong hop le.\n");
        }
    }
    return 0;
}