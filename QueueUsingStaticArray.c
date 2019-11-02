#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5
int queue[CAPACITY];
int ele;
int front = 0;
int rear = 0;
void enqueue();
void dequeue();
void display();
int isFull();
int isEmpty();
 void main()
{
     int ch;
     while(1)
     {
         printf("1.Enqueue Elements\n");
         printf("2.Dequeue Elements\n");
         printf("3.Display Elements\n");
         printf("5.Quit\n");
         printf("Enter the operation you want to Perform:");
         scanf("%d", &ch);


         switch(ch)
         {
             case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
                    break;
            default: printf("Invalid Choice:");
                    break;
         }
     }
 }

void enqueue()
{
    if(isFull())
    {
        printf("Queue is full\n\n");
    }
    else
    {
        printf("Enter your element to enqueue:");
        scanf("%d",&ele);
        queue[rear] = ele;
        rear++;
    }
}
void dequeue()
{
    if(front == rear)
    {
        printf("Queue is Empty\n\n");
    }
    else
    {
        int i;
        printf("%d is popped successfully\n", queue[front]);
        for (i = 0; i< rear; i++)
        {
        queue[i] = queue[i + 1];
        }
        rear--;
    } 
}
void display()
{
    if(isEmpty())
    {
        printf("Queue is Empty\n\n");
    }
    else
    {
        int i;
        for(i = 0; i < rear; i++)
        {
            printf("%d->",queue[i]);
        }
    }
    printf("\n\n");
}
int isFull()
{
    if(rear == CAPACITY)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty()
{
    if(front == rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
