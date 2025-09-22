#include<stdio.h>
#include<stdlib.h>
struct Node
{
    char data;
    struct Node *NextAddress; 
};
struct Node* CreateNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->NextAddress = NULL;
    return newNode;
}

// INsertion the elements 
void InsertAtEnd(struct Node **Head ,int d){
    struct Node* EndNode = CreateNode(d);
    if(*Head==NULL){
        *Head = EndNode; 
        return ;
    }
    struct Node* temp = *Head;
    while (temp->NextAddress!=NULL)
    {
        temp = temp->NextAddress;
    }
    temp->NextAddress = EndNode;
}

void printList(struct Node* Head){
    while (Head!=NULL)
    {
        printf("%d -",Head->data);
        Head = Head->NextAddress;
    }
    printf("------\n");
}

int main(){
    struct Node* head= NULL;
    InsertAtEnd(&head,10);
    InsertAtEnd(&head,20);
    InsertAtEnd(&head,30);
    InsertAtEnd(&head,40);
    InsertAtEnd(&head,50);
    InsertAtEnd(&head,50);

    printList(head);
    return 0;
}
