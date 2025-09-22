// Hashing is a technique used in data structure that efficiently stores and retrieves data in a way that allows for quick access.
// Hashing involves mapping data to a specific index in a hash table (an array of items) using a hash function.
// It enables fast retrieval of information based on key.
/* 1. Hash Table : an array-like data structure that stores key-value pairs.
   2. Hash Function : a function that takes an input (key) and returns an index in the hash table.
   3. Collision Resolution Techniques : methods to handle cases where two keys hash to the same index. like chaining and open addressing.
    a. Chaining : each index in the hash table contains a linked list of entries that hash to the same index.
    b. Open Addressing : when a collision occurs, the algorithm searches for the next available index in the hash table.
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 7
#define EMPTY -1

// create a hash table
int table[SIZE];

// initialize the hash table
void initTable()
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        table[i] = EMPTY;
    }
}

// hash Function
int hashFunc(int key)
{
    return key % SIZE;
}

// insert using linear probing
void insert(int key)
{
    int index = hashFunc(key);
    int i = 0;
    while (i < SIZE && table[(index + 1) % SIZE != EMPTY])
    {
        i++;
    }
    if (i == SIZE)
    {
        printf("Hash Table is full\n");
        return;
    }
    table[(index + i) % SIZE] = key;
}
// search using linear probing
int search(int key)
{
    int index = hashFunc(key);
    int i = 0;
    while (i < SIZE && table[(index + i) % SIZE] != EMPTY)
    {
        if (table[(index + i) % SIZE] == key)
        {
            return (index + i) % SIZE; // found
        }
        i++;
    }
    return -1; // return index
}

void display()
{
    int i;
    printf("\n index : ");
    for (i = 0; i < SIZE; i++)
    {
        printf("%2d ", i);
    }
    printf("\n table : ");
    for (i = 0; i < SIZE; i++)
    {
        printf("\n %2d", table[i]);
    }
    printf("\n");
}
int main()
{
    initTable();
    int i;
    int key[] = {10, 17, 20, 24};
    int n = sizeof(key) / sizeof(key[0]);
    for (i = 0; i < n; i++)
    {
        insert(key[i]);
        printf("Key is inserted: ", key[i]);
    }
    display();

}
