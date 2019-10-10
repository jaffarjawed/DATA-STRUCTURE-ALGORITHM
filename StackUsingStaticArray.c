/* Stack Implementation Using Static Array*/
#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5


int stack[CAPACITY];
int top = -1, ele;

int push(int);
int pop(void);
int peek(void);
int traverse(void);
int isEmpty(void);
int isFull(void);

int main()
{
    int ch,item,i;
    while(1)
    {
    printf("Enter your Choice:\n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Peek\n");
    printf("4.Traverse\n");
    printf("5.Quit\n");
    scanf("%d", &ch);

        switch(ch)
    {
    case 1:
        printf("Enter your elements:\n");
        scanf("%d", &ele);
        push(ele);
        break;
    case 2:
        item = pop();
        if (item == '0')
            printf("Stack is Empty\n");
        else
            printf("%d Element popped successfully\n", item);
        break;
    case 3:
        item = peek();
        if (item == '0')
            printf("Stack is Empty\n");
        else
            printf("%d is Peek Element\n", item);
        break;
    case 4:
        item = traverse();
        if (item == '0')
            printf("Stack is Empty\n");
        else
        {
         for(i = 0; i <= top; i++)
         {
             printf("%d\n",stack[i]);
         }
        }

        break;
    case 5:
        exit(0);
        break;

    default:
        printf("You have entered wrong choice\n");
        break;
    }
    }
}


int push(int ele)
    {
        if(isFull())
        {
            printf("Stack is full\n");
        }
        else
        {
            top++;
            printf("%d Element is inserted successfully\n",ele);
            return stack[top] = ele;
        }
    }


int pop()
    {
        if(isEmpty())
        {
            return '0';
        }
        else
        {
            return stack[top--];
        }

    }

int peek()
    {
        if(isEmpty())
        {
            return '0';
        }
        else
        {
            return stack[top];
        }
    }

int traverse()
    {
        if(isEmpty())
        {
            return '0';
        }
        else
        {
            return 1;
        }
    }

int isFull()
    {
        if(top == CAPACITY - 1)
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

        if(top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
