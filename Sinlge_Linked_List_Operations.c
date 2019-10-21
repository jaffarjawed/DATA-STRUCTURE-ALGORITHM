/*Implementation of Single Linked List Such Append, Delete, Display, Length, Swap, Reverse */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
};
int len;
struct node *root = NULL;
void insert();
void addatbegin();
int length();
void print();
void reverseIterative();
void printReverseRecursive();
void reverseRecursive();
void delete();
void insertAnyPos();
void swap();
void main()
{
    int ch;
    len = length();
    while (1)
    {
        printf("1.Insert at Last\n");
        printf("2.Insert at Begining\n");
        printf("3.Length of Linked List\n");
        printf("4.Print Element in Single Linked List\n");
        printf("5.Reverse Element in Linked List using iterative\n");
        printf("6.Print Element in Reverse Order Using Recursive\n");
        printf("7.Reverse element by Using Recursive Process\n");
        printf("8.Delete Elements from the Linked List\n");
        printf("9.Add nodes at any Postion\n");
        printf("10.Swap two adjacent nodes in Single Linked List\n");
        printf("11.Quit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        printf("\n");


        switch (ch)
        {
        case 1: insert();
            break;
        
        case 2: addatbegin();
            break;
        
        case 3: len = length();
                printf("Linked List size is %d\n\n", len);
            break;

        case 4: print();
            break;

        case 5: reverseIterative();
            break;

        case 6: printReverseRecursive(root);
            break;

        case 7: reverseRecursive(root);
            break;

        case 8: delete();
            break;

        case 9: insertAnyPos();
            break;

        case 10: swap();
            break;

        case 11: exit(0);
            break;
        default: printf("Invalid Choice\n");
            break;
        }
    }
    

}

void insert()
{
    struct node* temp;
    struct node* p;
    p = root;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter your data:");
    scanf("%d", &temp ->data);
    temp ->link = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        while(p->link != NULL)
        {
            p = p ->link;
        }
        p ->link = temp;
    }
    

}
void addatbegin()
{
    int i= 1;
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter your data:");
    scanf("%d", &temp ->data);
    temp ->link = NULL;
        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            temp ->link = root;
            root = temp;
        }  
}
int length()
{
    struct node *temp;
    temp = root;
    int count = 0;
    while (temp != NULL)
    {
        count++;
       temp = temp ->link;
    }
    printf("\n");
    return count;
}
void print()
{
    struct node *temp;
    temp = root;
    if (root == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d ->", temp ->data);
            temp = temp ->link;
        }
        printf("\n");
    }
}
void reverseIterative()
{
    struct  node* p, *q;
    p = q = root;
    int k, temp,  i = 0;
    int j = length() -1;
    while(i < j)
    {
        k = 0;
        while(k <j)
        {
            q = q ->link;
            k++;
        }
        temp = p ->data;
        p ->data = q ->data;
        q ->data = temp;
        i++;
        j--;
        p = p ->link;
        q = root;
    }
}
void printReverseRecursive(struct node* temp)
{
    
    if (temp == NULL)
        return;
    printReverseRecursive(temp ->link);
    printf("%d ->", temp ->data);
    printf("\n");
}
void reverseRecursive(struct node* p)
{
    if(p ->link == NULL)
    {
        root = p;
        return;
    }
    reverseRecursive(p->link);
   p->link->link = p;
   p ->link = NULL;

}
void delete()
{
    int loc, i = 1;
    int len = length();
    printf("Enter your location to delete:");
    scanf("%d", &loc);
    if(loc > len)
    {
        printf("Invalid Location\n\n");

    }
    else if(loc == 1)
    {
            struct node* temp = root;
            root = temp ->link;
            temp ->link = NULL;
            free(temp);
    }
    else
    {
        struct node *p = root;
        struct node* q;
        while(i < loc-1)
        {
            p = p ->link;
            i++;
        }
        q = p ->link;
        p ->link = q ->link;
        q ->link = NULL;
        free(q);
    }
    
}

void insertAnyPos()
{
    int loc, i = 1;
    len = length();
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp ->link = NULL;
    printf("Enter your location to append elements:");
    scanf("%d", &loc);
    if( loc > len)
    {
        printf("Invalid location");
        printf("List is having %d elements", len);
    }
    else if (loc ==1 )
    {
        printf("Enter you data:");
        scanf("%d", &temp ->data);
        if (root == NULL)
        {
            temp = root;
        }
        else
        {
            temp ->link = root;
            root = temp;
        }
        
    }
    else
    {
        struct node *p = root;
        printf("Enter your data:");
        scanf("%d", &temp ->data);
        while(i < loc)
        {
            p = p ->link;
            i++; 
        }
        temp ->link = p ->link;
        p ->link = temp;
    }
}
void swap()
{
    int loc, i = 1;
    struct node* r , *p, *q, *temp;
    p = root;
    temp = root;
    printf("Enter loccation to swap:");
    scanf("%d", &loc);
    if (loc > len)
    {
        printf("Invalid Location\n");
        printf("List is having %d elements\n\n", len);
    }
    else if(loc == 1)
    {
        q = p ->link;
        r = q ->link;
        p ->link = r;
        q ->link = temp;
        root = q;


    }
    else
    {
        while (i < loc -1)
        {
            p = p->link;
            i++;
        }
    q = p ->link;
    r = q ->link;
    q ->link = r ->link;
    r ->link = q;
    p ->link = r;
    }
}
    
