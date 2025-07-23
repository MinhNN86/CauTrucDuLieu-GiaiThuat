#include <stdio.h>
#include <stdlib.h>

// 🎋 Node của cây nhị phân
typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 🧺 Node của hàng đợi
typedef struct QueueNode
{
    TreeNode *data;
    struct QueueNode *next;
} QueueNode;

// 📦 Cấu trúc hàng đợi
typedef struct
{
    QueueNode *front, *back;
} Queue;

// 🎁 Hàm tạo node mới cho cây
TreeNode *createNode(int data)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// 📌 Khởi tạo hàng đợi rỗng
Queue *initQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->back = NULL;
    return q;
}

// 📥 Thêm node vào hàng đợi
void push(Queue *q, TreeNode *node)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->data = node;
    newNode->next = NULL;
    if (q->back == NULL)
    {
        q->front = q->back = newNode;
    }
    else
    {
        q->back->next = newNode;
        q->back = newNode;
    }
}

// 📤 Lấy node khỏi hàng đợi
TreeNode *pop(Queue *q)
{
    if (q->front == NULL)
        return NULL;
    QueueNode *temp = q->front;
    TreeNode *data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->back = NULL;
    free(temp);
    return data;
}

// ❓ Kiểm tra hàng đợi rỗng
int empty(Queue *q)
{
    return q->front == NULL;
}

// 🔁 Duyệt cây theo tầng (Level-order / BFS)
void levelOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    Queue *q = initQueue();
    push(q, root);
    while (!empty(q))
    {
        TreeNode *cur = pop(q);
        printf("%d ", cur->data);
        if (cur->left)
            push(q, cur->left);
        if (cur->right)
            push(q, cur->right);
    }
    free(q); // Giải phóng hàng đợi sau khi dùng xong
}

// 🌟 Duyệt cây theo Pre-order (Gốc → Trái → Phải)
void preOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// 🌿 Duyệt cây theo In-order (Trái → Gốc → Phải)
void inOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// 🍁 Duyệt cây theo Post-order (Trái → Phải → Gốc)
void postOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

// 🧹 Giải phóng toàn bộ bộ nhớ của cây
void freeTree(TreeNode *root)
{
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main()
{
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4  5  6  7

    TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("🌟 Pre-order: ");
    preOrder(root);
    printf("\n");

    printf("🌿 In-order: ");
    inOrder(root);
    printf("\n");

    printf("🍁 Post-order: ");
    postOrder(root);
    printf("\n");

    printf("📊 Level-order (BFS): ");
    levelOrder(root);
    printf("\n");

    freeTree(root);
    return 0;
}