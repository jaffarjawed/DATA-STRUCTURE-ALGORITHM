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
    len = length();
    while (1)
    {
        printf("1.Append\n");
        printf("2.Display\n");
        printf("3.Length\n");
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

// Inserting the node and data into Single Linked List
void insert()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->link = NULL;
    printf("Enter your node data:");
    scanf("%d", &temp->data);
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *p = root;
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}
// Displaying the data of Single Linkled List
void display()
{
    struct node *temp = root;
    if (root == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ->", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}
// Finding length of Single Linked List
int length()
{
    struct node *temp = root;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }
    printf("Length is %d\n\n", count);
    return count;
}
// Bubble Sorting for Single Linked List
void sort()
{
    int temp;
    struct node* p, *q = root;
    while (q)
    {
        p = root;
        while(p ->link != NULL)
        {
            if(p ->data > p ->link ->data)
            {
                temp = p ->data;
                p ->data = p ->link ->data;
                p ->link ->data = temp;
            }
            p = p ->link; 
        }
       q = q ->link;
    }  
}
