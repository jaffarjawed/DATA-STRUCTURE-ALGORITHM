#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5


int front, rear = 0;
int queue[CAPACITY];
void push();
void pop();
void traverse();
void main()
{
    int ch;
    while(1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Traverse\n");
        printf("4. Quit\n");
        printf("Enter your choice:");
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
        }

    }
}

void push()
{
    int data;
    if(CAPACITY == rear)
    {
        printf("Queue is Full\n");
    }
    else
    {
        printf("Enter Your data:");
        scanf("%d", &data);
        queue[rear] = data;
        rear++;
    }
}
void pop()
{
    int i;
    if(front == rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("%d is popped successfully", queue[front]);
        for(i = front; i< rear-1; i++)
        {
            queue[i] = queue[i+1];
        }
        rear--;
    }

}
void traverse()
{
    int i;
    if(front == rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Elements are: ");
        for(i = front; i< rear; i++)
        printf("%d\n",queue[i]);
    }
    printf("\n");

}
