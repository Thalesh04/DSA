#include <stdio.h>
#define MAX 10

int cq[MAX];
int front = -1, rear = -1;

int isFull() { return ((front == 0 && rear == MAX-1) || (front == rear+1)); }
int isEmpty() { return (front == -1); }

void enqueue(int x) {
    if (isFull()) { printf("Queue is full\n"); return; }
    if (front == -1) { front = rear = 0; }
    else if (rear == MAX-1) { rear = 0; }
    else { rear++; }
    cq[rear] = x;
}

void dequeue() {
    if (isEmpty()) { printf("Queue is empty\n"); return; }
    printf("Dequeued: %d\n", cq[front]);
    if (front == rear) { front = rear = -1; }
    else if (front == MAX-1) { front = 0; }
    else { front++; }
}

void display() {
    if (isEmpty()) { printf("Queue is empty\n"); return; }
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear) break;
        i = (i+1)%MAX;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    enqueue(40);
    enqueue(50);
    display();

    return 0;
}
