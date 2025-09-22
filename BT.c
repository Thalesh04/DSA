#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
};
struct Node *createNode(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// create a queue for store nodes inside in it
struct Node *queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(struct Node *x)
{
    if (rear == SIZE - 1)
    {
        return;
    }
    queue[++rear] = x;
    if (front == -1)
        front = 0;
}

struct Node *dequeue()
{
    if (front == -1)
    {
        return NULL;
    }
    struct Node *temp = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
    return temp;
}

struct Node *insertBT(struct Node *root, int val)
{
    // create newnode
    struct Node *newNode = createNode(val);
    if (root == NULL)
    {
        return newNode;
    }
    enqueue(root);
    while (front != -1)
    {
        struct Node *temp = dequeue();
        if (temp->left == NULL)
        {
            temp->left = newNode;
            return root;
        }
        else
        {
            enqueue(temp->left);
        }
        if (temp->right == NULL)
        {
            temp->right = newNode;
            return root;
        }
        else
        {
            enqueue(temp->right);
        }
    }
    return root;
}

void inOrder(struct Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->val);
    inOrder(root->right);
}

int main()
{
    struct Node *root = NULL;
    root = insertBT(root, 10);
    root = insertBT(root, 20);
    root = insertBT(root, 30);
    root = insertBT(root, 40);

    inOrder(root);
}