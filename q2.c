#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int deque[SIZE];

int front = -1, rear = -1;

int isFull()
{
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

int isEmpty()
{
    return (front == -1);
}

void insertFront(int val)
{
    if (isFull())
    {
        printf("Queue is overflow");
        return;
    }
    if (isEmpty())
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = SIZE - 1;
    }
    else
    {
        front--;
    }
    deque[front] = val;
    printf("Inserted %d at front\n", val);
}

void insertRear(int val)
{
    if (isFull())
    {
        printf("Queue is overflow");
        return;
    }
    if (isEmpty())
    {
        front = rear = 0;
    }
    else if (rear == SIZE - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    deque[rear] = val;
    printf("Inserted %d at rear\n", val);
}

void deleteFront()
{
    if (isEmpty())
    {
        printf("Queue is underflow\n");
        return;
    }
    printf("Removed %d from front\n", deque[front]);
    if (front == rear)
    {
        front = rear = -1; // Queue is now empty
    }
    else if (front == SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void deleteRear()
{
    if (isEmpty())
    {
        printf("Queue is underflow\n");
        return;
    }
    printf("Removed %d from rear\n", deque[rear]);
    if (front == rear)
    {
        front = rear = -1; // Queue is now empty
    }
    else if (rear == 0)
    {
        rear = SIZE - 1;
    }
    else
    {
        rear--;
    }
}
// display in double ended queue
void display()
{
    if (isEmpty())
    {
        printf("Queue is underflow\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1)
    {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
int main()
{
    insertFront(10);
    insertRear(20);
    insertFront(5);
    display();
    deleteFront();
    display();
    deleteRear();
    display();
}