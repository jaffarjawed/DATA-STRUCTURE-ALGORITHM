#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
};
 struct node* top = NULL;


void push();
void pop();
void traverse();
 void main()
 {
     int ch;
     while(1)
     {
         printf("1.Push\n");
         printf("2. Pop\n");
         printf("3.Traverse\n");
         printf("Enter the operation you want to Perform:");
         scanf("%d", &ch);


         switch(ch)
         {
             case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: traverse();
                    break;
            case 4: exit(0);
            default: printf("Invalid Choice:");
         }

     }
 }

 void push()
 {
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter your data:");
    scanf("%d", &temp ->data);
    temp ->link = top;
    top = temp;
 }
 void pop()
 {
    struct node* temp;
    if(top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        temp = top;
        printf("%d is popped successfully\n", temp ->data);
        top = temp ->link;
        free(temp);
    }
 }
 void traverse()
 {
    struct node* temp;
    if (top == NULL)
    {
        printf("Stack is Empty");
    }
    else
    {
        temp = top;
        while(temp != NULL)
        {
            printf("%d ", temp ->data);
            temp = temp ->link;

        }
    }
    printf("\n\n");
 }

