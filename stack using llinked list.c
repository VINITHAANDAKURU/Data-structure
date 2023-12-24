#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
} *top = NULL;

int isEmpty() {
    if (top == NULL)
        return 1;
    else
        return 0;
}

void push(int data) {
    struct node* newnode;
    newnode = malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("stack overflow");
        exit(1);
    }
    newnode->data = data;
    newnode->link = top;
    top = newnode;
}

int pop() {
    struct node* temp;
    int val;
    if (isEmpty()) {
        printf("stack underflow");
        return -1;
    }
    temp = top;
    val = temp->data;
    top = top->link;
    free(temp);
    return val;
}

int peek() {
    if (isEmpty()) {
        printf("stack underflow");
        exit(1);
    }
    return top->data;
}

void print() {
    struct node* temp;
    temp = top;
    if (isEmpty()) {
        printf("stack underflow");
        exit(1);
    }
    printf("stack elements are: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("\n");
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.top element\n");
        printf("4.print all elements\n");
        printf("5.Quit\n");
        printf("enter the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("enter the element: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data = pop();
                if (data != -1) {
                    printf("deleted element is %d\n", data);
                }
                break;
            case 3:
                data = peek();
                if (data != -1) {
                    printf("Topmost element is %d\n", data);
                }
                break;
            case 4:
                print();
                break;
            case 5:
                exit(0); // Exit with success code
            default:
                printf("error!!!\n");
        }
    }

    return 0;
}