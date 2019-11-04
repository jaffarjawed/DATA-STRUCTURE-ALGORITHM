#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *root = NULL;
int len;

void insert();
void display();
int length();
void sort();
void main()
{
    int ch;
    while (1)
    {
        printf("1.Append\n");
        printf("2.Display\n");
        printf("3.Length\n");
        printf("4.Sorting\n");
        printf("4.quit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            length();
            break;
        case 4:
            sort();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}

void insert()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->link = NULL;
    printf("Enter your data:");
    scanf("%d", &temp->data);
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        temp->link = root;
        root = temp;
    }
}
void display()
{
    struct node *temp = root;
    if (root == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        while (temp)
        {
            printf("%d ->", temp->data);
            temp = temp->link;
        }
    }
    printf("\n\n");
}
int length()
{
    struct node *temp = root;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->link;
    }
    printf("Length is %d\n\n", count);
    return count;
}
void sort()
{
    int temp;
    struct node *q = root;
    struct node *p, *min;
    while (q)
    {
        min = q;
        p = q->link;
        while (p)
        {
            if (p->data < min->data)
            {
                min = p;
            }
            p = p->link;
        }
        temp = q->data;
        q->data = min->data;
        min->data = temp;
        q = q->link;
    }
}
