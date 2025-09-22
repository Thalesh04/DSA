#include <stdio.h>
#include <stdlib.h>

// Node structure for BST
struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
};

// Insert a node
struct BSTNode* insert(struct BSTNode* root, int data) {
    if (!root) {
        root = (struct BSTNode*)malloc(sizeof(struct BSTNode));
        root->data = data;
        root->left = root->right = NULL;
    } else if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Search for a node
struct BSTNode* search(struct BSTNode* root, int data) {
    if (!root || root->data == data)
        return root;
    if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

// Find minimum value
int findMin(struct BSTNode* root) {
    while (root->left)
        root = root->left;
    return root->data;
}

// Find maximum value
int findMax(struct BSTNode* root) {
    while (root->right)
        root = root->right;
    return root->data;
}

// Inorder traversal
void inorder(struct BSTNode* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function to test BST
int main() {
    struct BSTNode* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder: "); inorder(root); printf("\n");
    printf("Min: %d\n", findMin(root));
    printf("Max: %d\n", findMax(root));
    struct BSTNode* found = search(root, 40);
    printf("Search 40: %s\n", found ? "Found" : "Not Found");
    return 0;
}