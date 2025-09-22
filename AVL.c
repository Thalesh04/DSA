// AVL Tree implementation in C
// It is a self balancing Binary Search Tree
// cases
// 1. ll rotation - right rotate
// 2. rr rotation - left rotate
// 3. lr rotation - left rotate
// 4. rl rotation - right rotate
// BF = height(left subtree) - height (right subtree)

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
    int height;
};

struct Node *newNode(int v)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->value = v;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
}
// method to get height of the tree
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int x, int y)
{
    return (x > y) ? x : y;
}

// right rotate
struct Node *rightRotate(struct Node *node)
{
    struct Node *x = node->left; // 20
    struct Node *y = x->right;   // 25
    // perform rotation
    x->right = node;
    node->left = y;
    // update height
    node->height = max(height(node->left), height(node->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x; // new root
}
// left rotate
struct Node *leftRotate(struct Node *node)
{
    struct Node *x = node->right;
    struct Node *y = x->left;

    x->left = node;
    node->right = y;

    node->height = max(height(node->left), height(node->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}
// get balance factor
int getBalanceFactor(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
// insert node
struct Node *insertNode(struct Node *node, int key)
{
    if (node == NULL)
    {
        return newNode(key);
    }
    if (key < node->value)
    {
        node->left = insertNode(node->left, key);
    }
    else if (key > node->value)
    {
        node->right = insertNode(node->right, key);
    }
    else
    {
        return node; // duplicate keys not allowed
    }
    // update height
    node->height = 1 + max(height(node->left), height(node->right));
    // get balance factor
    int balance = getBalanceFactor(node);
    // if node is unbalanced, then there are 4 cases
    // left left case
    if (balance > 1 && key < node->left->value)
    {
        return rightRotate(node);
    }
    // right right case
    if (balance < -1 && key > node->right->value)
    {
        return leftRotate(node);
    }
    // left right case
    if (balance > 1 && key > node->left->value)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // right left case
    if (balance < -1 && key < node->right->value)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// main method
int main()
{
    struct Node *root = NULL;
    // Constructing tree given in the above figure
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 60);

    // The constructed AVL Tree would be
    //         20
    //        /  \
    //      15    30
    //           /
    //          25

    printf("Preorder traversal of the constructed AVL tree is \n");
    preOrder(root);

    return 0;
}