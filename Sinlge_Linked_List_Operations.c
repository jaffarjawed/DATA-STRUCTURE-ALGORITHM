/*Implementation of Single Linked List Such Append, Delete, Display, Length, Swap, Reverse */

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node* root = NULL;
int len;

void append(void);
void addatbegin(void);
void addafter(void);
int length();
void display();
void delete();
void swap();
void reverse_linked_list();

void main()
{
    int ch;
    while(1)
    {
        printf("1.Append\n");
        printf("2.AddAtBegin\n");
        printf("3.AddAfter\n");
        printf("4.length\n");
        printf("5.Display Items\n");
        printf("6.Delete At Any Location\n");
        printf("7.Swapping of nodes\n");
        printf("8.Reverse of Linked List\n");
        printf("9.Quit\n\n");
        printf("Enter the choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: append();
                    break;
            case 2: addatbegin();
                    break;
            case 3: addafter();
                    break;
            case 4: len = length();
                    printf("%d is length of linked list\n",len);
                    printf("\n");
                    break;
            case 5: display();
                    break;
            case 6: delete();
                    break;
            case 7: swap();
                    break;
            case 8: reverse_linked_list();
                    break;
            case 9: exit(1);
            default: printf("Invalid Choice");
        }


    }
}
// Appending elements in Single Linked List
void append()
{
    struct node* temp;
    struct node* p;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter you data: ");
    scanf("%d", &temp ->data);
    printf("\n");
    temp -> link = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        p = root;
        while(p ->link != NULL)
        {
            p = p ->link;

        }
        p -> link = temp;
    }

}

//Adding elements at beginning of linked list
void addatbegin()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter Your data: ");
    scanf("%d", &temp ->data);
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        temp ->link = root;
        root = temp;
    }

}

//Adding elements after specified position in Single Linked List
void addafter()
{
    struct node* temp;
    struct node* p;
    int loc,i = 1;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter your location:");
    scanf("%d", &loc);
    len = length();
    if(loc > len)
    {
        printf("Invalid Location\n");
    }
    else if(loc == 1)
    {
        printf("Enter your data:");
        scanf("%d",&temp ->data);
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
    else
    {
        p = root;
        while(i <loc )
        {
            p = p ->link;
            i++;
        }
        printf("Enter your data:");
        scanf("%d", &temp ->data);
        temp ->link = NULL;
        temp ->link = p ->link;
        p ->link = temp;
    }

}

//Finding the length of Single Linked List
int length()
{
    struct node* temp;
    temp = root;
    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp -> link;
    }
    return count;
}
//Displaying elements of Single Linked List
void display()
{
    struct node* temp;
    if(root == NULL)
    {
        printf("Linked List is Empty\n");
    }
    else
    {
        temp = root;
        while(temp != NULL)
        {
            printf("%d -->", temp -> data);
            temp = temp -> link;
        }
        printf("\n\n");
    }

}

//Deleting any elements in Single Linked List at Specified Position
void delete()
{
    struct node* temp;
    int loc;
    len = length();
    printf("Enter your location to delete:");
    scanf("%d", &loc);
    if (loc > len)
    {
        printf("Invalid Location\n");
    }
    else if(loc == 1)
    {
        temp = root;
        root = temp ->link;
        free(temp);
    }
    else
    {
        struct node* p;
        struct node* q;
        p = root;
        int i = 1;
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
//Swapping elements of Single Linked List at Specified Position
void swap()
{
    struct node* p, *q, *r;
    int loc, i = 1;
    p = root;
    printf("Enter your location to swap:");
    scanf("%d", &loc);
    while(i < loc -1)
    {
        p = p ->link;
        i++;
    }
    q = p ->link;
    r = q ->link;
    q ->link = r ->link;
    r ->link = q;
    p -> link = r;
    printf("Swapped Successfully\n");
}
//REverse the Elements of Single Linked List
void reverse_linked_list()
{
    struct node* p, *q;
    p = q =root;
    len = length();
    int i, j,k, temp;
    i = k = 0;
    j = len -1;
    while(i < j)
    {
        k= 0;
        while(k < j)
        {
            q = q ->link;
            k++;
        }
    temp = p ->data;
    p ->data = q ->data;
    q -> data = temp;
    p = p -> link;
    q = root;
    i++, j--;
    }
}
