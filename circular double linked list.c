#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	struct node* prev;
	int data;
	struct node* next;
}node;
node* head=NULL;
node* tail=NULL;
int count=0;
void insertEnd()
{
	node* newnode=malloc(sizeof(newnode));
	int element;
	printf("Enter the element.");
	scanf("%d",&element);
	newnode->data=element;
	if(head==NULL)
	{
		newnode->prev=NULL;
		newnode->next=NULL;
		head=tail=newnode;
	}
	else
	{
		head->prev=newnode;
		tail->next=newnode;
		newnode->prev=tail;
		newnode->next=head;
		tail=newnode;
    }
	++count;
}
void insertBeginning()
{
	node* newnode=malloc(sizeof(newnode));
	int element;
	printf("Enter the element.");
	scanf("%d",&element);
	newnode->data=element;
	if(head==NULL)
	{
		newnode->next=NULL;
		newnode->prev=NULL;
		head=tail=newnode;
	}
	else
	{
		head->prev=newnode;
		tail->next=newnode;
		newnode->next=head;
		newnode->prev=tail;
		head=newnode;
	}
	++count;
}
void insertAtPos()
{
	int n;
	printf("Enter the position.");
	scanf("%d",&n);
	if(n==count+1)
	{
		insertEnd();
	}
	else if(n==1)
	{
		insertBeginning();
	}
	else if(n>count+1 || n<=0)
	{
		printf("Invalid position.\n");
	}
	else
	{
		node* newnode=malloc(sizeof(newnode));
	    int element;
	    printf("Enter the element.");
	    scanf("%d",&element);
	    newnode->data=element;
	    node* temp=head;
	    int i;
	    for(i=1;i<n-1;i++)
	    {
	    	temp=temp->next;
		}
		newnode->prev=temp;
		newnode->next=temp->next;
		temp->next->prev=newnode;
		temp->next=newnode;
		++count;
	}
}
void deleteEnd()
{
	if(head==NULL)
	{
		printf("Underflow\n");
		return;
	}
	node* temp=tail;
	tail=tail->prev;
	if(count!=1)
	{
	tail->next=head;
	head->prev=tail;
    }
    else
    {
    	tail=head=NULL;
	}
	free(temp);
	--count;
}
void deleteBeginning()
{
	if(head==NULL)
	{
		printf("Underflow\n");
		return;
	}
	node* temp=head;
	head=head->next;
	if(count!=1)
	{
	tail->next=head;
	head->prev=tail;
    }
    else
    {
    	head=tail=NULL;
	}
	free(temp);
	--count;
}
void deleteAtPos()
{
	if(head==NULL)
	{
		printf("Underflow\n");
		return;
	}
	int n;
	printf("Enter the position.");
	scanf("%d",&n);
	if(n==count)
	{
		deleteEnd();
	}
	else if(n==1)
	{
		deleteBeginning();
	}
	else if(n>count || n<=0)
	{
		printf("Invalid position.\n");
    }
    else
    {
    	node* temp=head;
    	int i;
    	for(i=1;i<n;i++)
    	{
    		temp=temp->next;
	    }
	    temp->prev->next=temp->next;
	    temp->next->prev=temp->prev;
	    free(temp);
	    --count;
	}
}
void display()
{
	if(head==NULL)
	{
		printf("Empty linked list.\n");
		return;
	}
	node* temp=head;
	while(temp!=tail)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("%d",temp->data);
	printf("\n");
}
void backDisplay()
{
	if(head==NULL)
	{
		printf("Empty linked list.\n");
		return;
	}
	node* temp=tail;
	while(temp!=head)
	{
		printf("%d ",temp->data);
		temp=temp->prev;
	}
	printf("%d",temp->data);
	printf("\n");
}
int main()
{
	int choice;
	printf("List of operations:\n1.Insert end\n2.Insert Beginning\n3.Insert at a position\n4.Delete end\n5.Delete Beginning\n6.Delete at a position\n7.Display\n8.Back display\n9.Exit\n");
    while(1)
    {
    	printf("Enter your choice.");
    	scanf("%d",&choice);
    	switch(choice)
    	{
    		case 1:insertEnd();break;
    		case 2:insertBeginning();break;
    		case 3:insertAtPos();break;
    		case 4:deleteEnd();break;
    		case 5:deleteBeginning();break;
    		case 6:deleteAtPos();break;
    		case 7:display();break;
    		case 8:backDisplay();break;
    		case 9:exit(0);
    		default:printf("Invalid choice.\n");
		}
	}
}