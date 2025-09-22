#include <stdio.h>
#define MAX 10

struct PQNode {
    int data, priority;
};

struct PQNode pq[MAX];
int size = 0;

void insert(int data, int priority) {
    if (size == MAX) { printf("Priority Queue is full\n"); return; }
    pq[size].data = data;
    pq[size].priority = priority;
    size++;
}

void deleteHighest() {
    if (size == 0) { printf("Priority Queue is empty\n"); return; }
    int idx = 0;
    for (int i = 1; i < size; i++)
        if (pq[i].priority > pq[idx].priority)
            idx = i;
    printf("Deleted: %d (Priority: %d)\n", pq[idx].data, pq[idx].priority);
    for (int i = idx; i < size-1; i++)
        pq[i] = pq[i+1];
    size--;
}

void display() {
    if (size == 0) { printf("Priority Queue is empty\n"); return; }
    printf("Priority Queue:\n");
    for (int i = 0; i < size; i++)
        printf("Data: %d, Priority: %d\n", pq[i].data, pq[i].priority);
}

int main() {
    insert(10, 2);
    insert(20, 5);
    insert(30, 1);
    display();

    deleteHighest();
    display();

    insert(40, 4);
    display();

    return 0;
}

/*
Q1
Queue 
Deque
Circular 
Priority

Q2
Stack 
BT
BST

Q3
Array

Q4
Linked List
Graph

*/