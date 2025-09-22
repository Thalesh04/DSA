#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;
// Function to check if the queue is full
int isFull()
{
    return ((front == 0 && rear == SIZE - 1) || (rear + 1 == front));
}
// Function to check if the queue is empty
int isEmpty()
{
    return (front == -1);
}
// Function to add an element to the queue
void enqueue(int value){
    if (isFull())
    {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear= (rear + 1) % SIZE;
    }
    queue[rear] = value;
    printf("Inserted %d\n", value);
}

void dequeue(int value){
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Removed %d\n", queue[front]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

// Function to display the elements of the queue
void display(){
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    
    dequeue(10);
    display();
    
    enqueue(40);
    display();
    
    dequeue(20);
    display();
    
    enqueue(50);
    display();
    
    return 0;
}

// int queue[SIZE];
// int arr_front = -1, arr_rear = -1;
// struct Node
// {
//     int data;
//     struct Node *prev;
//     struct Node *next;
// };

// struct Node *front = NULL;
// struct Node *rear = NULL;

// // Insert at front
// void enqueueFront(int val)
// {
//     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
//     newNode->data = val;
//     newNode->prev = NULL;
//     newNode->next = front;
//     if (front == NULL)
//     {
//         rear = newNode;
//     }
//     else
//     {
//         front->prev = newNode;
//     }
//     front = newNode;
// }

// // Insert at rear
// void enqueueRear(int val)
// {
//     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
//     newNode->data = val;
//     newNode->next = NULL;
//     newNode->prev = rear;
//     if (rear == NULL)
//     {
//         front = newNode;
//     }
//     else
//     {
//         rear->next = newNode;
//     }
//     rear = newNode;
// }

// // Remove from front
// void dequeueFront()
// {
//     if (front == NULL)
//     {
//         printf("Deque is empty\n");
//         return;
//     }
//     struct Node *temp = front;
//     printf("Removed %d from front\n", temp->data);
//     front = front->next;
//     if (front == NULL)
//     {
//         rear = NULL;
//     }
//     else
//     {
//         front->prev = NULL;
//     }
//     free(temp);
// }

// // Remove from rear
// void dequeueRear()
// {
//     if (rear == NULL)
//     {
//         printf("Deque is empty\n");
//         return;
//     }
//     struct Node *temp = rear;
//     printf("Removed %d from rear\n", temp->data);
//     rear = rear->prev;
//     if (rear == NULL)
//     {
//         front = NULL;
//     }
//     else
//     {
//         rear->next = NULL;
//     }
//     free(temp);
// }

// // Display deque
// void displayDeque()
// {
//     struct Node *temp = front;
//     printf("Deque elements: ");
//     while (temp != NULL)
//     {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("\n");
// }

// int main(){
//     enqueueFront(10);
//     enqueueRear(20);
//     enqueueFront(5);
//     enqueueRear(30);
//     displayDeque();

//     dequeueFront();
//     displayDeque();

//     dequeueRear();
//     displayDeque();

//     return 0;
// }

// int isFull()
// {
//     return (arr_rear == SIZE - 1);
// }

// int isEmpty()
// {
//     return ((arr_front == -1 && arr_rear == -1) || (arr_front > arr_rear));
// }
// // insert
// void enqueue(int val)
// {
//     if (isFull())
//     {
//         printf("queue is full");
//     }
//     else
//     {
//         if (arr_front == -1 && arr_rear == -1)
//         {
//             arr_front = 0;
//         }
//         queue[++arr_rear] = val;
//         printf("inserted");
//     }
// }
// // remove
// void dequeue()
// {
//     if (isEmpty())
//     {
//         printf("Queue empty");
//     }
//     else
//     {
//         printf("Removed %d\n", queue[arr_front]);
//         queue[arr_front] = 0;
//         arr_front++;
//     }
// }
// // peek/front
// void peek()
// {
//     if (isEmpty())
//     {
//         printf("no peek element because queue is empty");
//         return;
//     }
//     else
//     {
//         printf("Front element %d\n", arr_front);
//     }
// }
// // display
// void display()
// {
//     int i;
//     if (isEmpty())
//     {
//         printf("Queue is empty");
//     }
//     else
//     {
//         printf("Queue elements are: ");
//         for (i = arr_front; i <= arr_rear; i++)
//         {
//             printf("%d ", queue[i]);
//         }
//         printf("\n");
//     }
// }
// int main()
// {
//     enqueue(10);
//     enqueue(30);
//     enqueue(34);
//     enqueue(23);
//     enqueue(78);
//     display();
//     dequeue();
//     display();
//     return 0;
// }
