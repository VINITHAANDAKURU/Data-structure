#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
 struct node *front=NULL;
 struct node *rear=NULL;
void enqueue(){
    struct node *temp;
    int n;
    temp=malloc(sizeof(struct node));
    temp -> data=n;
    temp -> next=NULL;
    if(rear==NULL)
    {
        front =rear=temp;
    }
    else{
        rear -> next =temp;
        rear=temp;
    }
}
void dequeue()
{
    struct node *temp;
    int data;
    if(front==NULL)
    {
        printf("queue underflow\n");
        exit(1);
    }
    temp=front;
    data =temp -> data;
    front =temp -> next;
    free(temp);
}
void display(){
    struct node *temp;temp=front;
    if(front=NULL)
    {
        printf("queue underflow\n");
        exit(1);
    }
    printf("Queue");
    while(temp -> next !=NULL)
    {
        printf("%d",temp -> data);
        temp =temp -> next;
    }
    printf("%d",temp -> data);
}
void main()
{
    int ch;
    printf("Queue operation using linked list\n");
    printf("enter your choice:1.Enqueue\n2.dequeue\n3.display\n4.exit");
    while(1);
    {
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: enqueue();
                    break;
            case 2: printf("element is popped");
                   dequeue();
                   break;
            case 3: display();
                   break;
            case 4: exit(1);
                   break;
        }
    }
}

