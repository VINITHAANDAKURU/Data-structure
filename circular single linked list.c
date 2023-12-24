#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *getnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void insert_at_beginning(int data)
{
    struct node *newnode = getnode(data);
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }
    printf("%d is inserted at the beginning \n",data);
}
void insert_at_end(int data)
{
    struct node *newnode = getnode(data);
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
    printf("%d is inserted at the end \n",data);
}
int insert_at_position(int data, int pos , int size)
{
if(pos > size+1)
    {
    printf("the position entered is unavailable \n");
    return 0;
}
    if (pos < 1)
    {
        printf("Invalid position\n");
        return 0;
    }
    int count;
    struct node * seat = head;
    struct node *newnode = getnode(data);
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
        return 0;
    }
    else if (pos == 1)
    {
        insert_at_beginning(data);
        return 0;
    }
    else
    {
        struct node *temp = head;
        int i;
        for (i = 1; i < pos - 1 && temp->next != head; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    printf("%d is inserted at the %d position \n",data,pos);
    return 0;
}
void delete_at_beginning()
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node *del = head;
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
        free(del);
    }
    printf("the element at the beginning is deleted \n");
}
void delete_at_end()
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node *temp = head;
        struct node *prev = NULL;
        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }
        if (prev != NULL)
        {
            prev->next = head;
        }
        else
        {
            head = NULL;
        }
        free(temp);
    }
    printf("the element at the end is deleted \n");
}
int delete_at_position(int pos,int size)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return 0;
    }
    else
    {
    if(pos > size+1)
    {
    printf("the position entered is unavailable \n");
    return 0;
}
        if (pos == 1)
        {
            delete_at_beginning();
            return 0;
        }
        else
        {
            struct node *temp = head;
            struct node *prev = NULL;
            int i;
            for (i = 1; i < pos && temp->next != head; i++)
            {
                prev = temp;
                temp = temp->next;
            }
            if (temp != head)
            {
                prev->next = temp->next;
                free(temp);
            }
            else
            {
                printf("Invalid position\n");
            }
        }
    }
    printf("the element at the position %d is deleted \n",pos);
    return 0;
}
void display()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("The list elements are:\n");
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}
int main()
{
    int choice, data, position, size;
    while (1)
    {
        printf("MAIN MENU\n");
        printf("1. INSERT AT BEGINNING\n");
        printf("2. INSERT AT END\n");
        printf("3. INSERT AT A POSITION\n");
        printf("4. DELETE AT BEGINNING\n");
        printf("5. DELETE AT END\n");
        printf("6. DELETE AT A POSITION\n");
        printf("7. DISPLAY\n");
        printf("8. EXIT\n");
        printf("Enter the option of your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to insert at the beginning: ");
            scanf("%d", &data);
            insert_at_beginning(data);
            size++;
            break;
        case 2:
            printf("Enter data to insert at the end: ");
            scanf("%d", &data);
            insert_at_end(data);
            size++;
            break;
        case 3:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter the position: ");
            scanf("%d", &position);
            insert_at_position(data, position,size);
            size++;
            break;
        case 4:
            delete_at_beginning();
            break;
        case 5:
            delete_at_end();
            size--;
            break;
        case 6:
            printf("Enter the position to delete: ");
            scanf("%d", &position);
            delete_at_position(position,size);
            size--;
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
        default:
            printf("Enter valid choice\n");
        }
    }
    return 0;
}