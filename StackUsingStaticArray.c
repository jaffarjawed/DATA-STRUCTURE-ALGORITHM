/* Stack Implementation Using Static Array*/
#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5

int stack[CAPACITY];
int top = -1,ele;

void push();
void pop();
void display();
void peek();
int isFull();
int isEmpty();
void main()

{
    int ch;
    while (1)
    {
        printf("1.Push Elements\n");
        printf("2.Pop Elements.\n");
        printf("3.Display Elements of Stack\n");
        printf("4.Peek Elements\n");
        printf("5.Exit.\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: push();
            break;
        
        case 2: pop();
            break;

        case 3: display();
            break;

        case 4: peek();
            break;

        case 5: exit(0);
            break;

        default: printf("Invalid Choice\n");
            break;
        }
    }
    
}

void push()
{
    if(isFull())
    {
        printf("Stack is Full\n\n");
    }
    else
    {
        printf("Enter your elements to push:");
        scanf("%d", &ele);
        top++;
        stack[top] = ele;
    }
}
void pop()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n\n");
    }
    else
    {
        printf("Poped elements is %d\n\n",stack[top]);
        top--;
    }
}
void display()
{
    int i;
    if(isEmpty())
    {
        printf("Stack is Empty\n\n");
    }
    else
    {
        for(i = 0; i <= top; i++)
    {
        printf("->%d", stack[i]);
    }
    printf("\n\n");
    }
}
void peek()
{
if (isEmpty())
    {
        printf("None\n\n");
    }
else
    {
        printf("peek element is %d\n\n", stack[top]);
    }
}
int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull()
{
    if (top == CAPACITY -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }  
}
