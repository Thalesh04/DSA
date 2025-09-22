#include <stdio.h>
#define MAX 10

int deque[MAX];
int front = -1, rear = -1;

int isFull() { return ((front == 0 && rear == MAX-1) || (front == rear+1)); }
int isEmpty() { return (front == -1); }

void insertFront(int x) {
    if (isFull()) { printf("Deque is full\n"); return; }
    if (front == -1) { front = rear = 0; }
    else if (front == 0) { front = MAX-1; }
    else { front--; }
    deque[front] = x;
}

void insertRear(int x) {
    if (isFull()) { printf("Deque is full\n"); return; }
    if (front == -1) { front = rear = 0; }
    else if (rear == MAX-1) { rear = 0; }
    else { rear++; }
    deque[rear] = x;
}

void deleteFront() {
    if (isEmpty()) { printf("Deque is empty\n"); return; }
    printf("Deleted: %d\n", deque[front]);
    if (front == rear) { front = rear = -1; }
    else if (front == MAX-1) { front = 0; }
    else { front++; }
}

void deleteRear() {
    if (isEmpty()) { printf("Deque is empty\n"); return; }
    printf("Deleted: %d\n", deque[rear]);
    if (front == rear) { front = rear = -1; }
    else if (rear == 0) { rear = MAX-1; }
    else { rear--; }
}

void display() {
    if (isEmpty()) { printf("Deque is empty\n"); return; }
    printf("Deque: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i+1)%MAX;
    }
    printf("\n");
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    display();

    deleteFront();
    display();

    insertFront(15);
    insertRear(25);
    display();

    deleteRear();
    display();

    return 0;
}