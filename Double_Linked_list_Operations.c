/* Program to Implement Operations on Doubly Linked List*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root = NULL;

int len;

void append();
void add_at_begin();
void add_after();
int length();
void traverse();
void delete();
void main()
{
    int ch;
    while(1)
    {
        printf("1.Append\n");
        printf("2.Add Elements at Beginning\n");
        printf("3.Add After Specified Postion\n");
        printf("4.Length\n");
        printf("5.Traverse Elements\n");
        printf("6. Delete");
        printf("7.Quit\n");
        printf("Enter Your Choice\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: append();
                    break;
            case 2: add_at_begin();
                    break;
            case 3: add_after();
                    break;
            case 4: len = length();
                    printf("Length is %d\n", len);
                    break;
            case 5: traverse();
                    break;
            case 6: delete();
                    break;
            case 7 : exit(0);
            default: printf("Invalid Input\n");
        }
    }
}
//Appending Elements in Doubly linked list
void append()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter your data:");
    scanf("%d", &temp ->data);
    temp ->left = NULL;
    temp ->right = NULL;
    if( root == NULL)
    {
        root = temp;
    }
    else
    {
        struct  node* p;
        p = root;
        while(p->right  != NULL)
        {
            p = p ->right;
        }
        p ->right = temp; 
        temp ->left = p;  
    }
}

//Adding Elements at Beginning of Doubly Linked List
void add_at_begin()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter Your Element:");
    scanf("%d", &temp ->data);
    if (root == NULL)
    {
        root = temp;
    }
   else
   {
       temp ->right = root;
       root ->left = temp;
       root = temp;
   }
   
}
//Adding Elements after specified position in DLL
void add_after()
{
    int loc;
    len = length();
    struct node*temp, *p, *q;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter Your Postion to add Elements after:");
    scanf("%d", &loc);
    if(loc > len)
    {
        printf("Invalid Location\n");
        printf("List length is %d", len);
    }
    if (len == 1)
    {
        printf("Enter Your Elements:");
        scanf("%d", &temp ->data);
        root = temp;
    }
    else
    {
        printf("Enter Your Elements:");
        scanf("%d", &temp ->data);
        root = temp;
        while(p ->right != NULL)
        {
            p = p ->right;
        }
        q = p ->right;
        temp ->right = q;
        q -> left = temp;
        p ->right = temp;
        temp ->left = p;
        
    }
    

}

//Finding the Length of DLL
int length()
{
    struct node* temp = root;
    int count = 0;
    while(temp  != NULL)
    {
        count++;
        temp = temp ->right;
    }
    return count;
}

//Displaying the Elements of DLL
void traverse()
{
    struct node* temp;
    temp = root;
    if (root == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
    while(temp != NULL)
        {
        printf("%d -->", temp -> data);
        temp = temp ->right;
        } 
    printf("\n"); 
    }
    
}

//Deleting the Elements of DLL
void delete()
{   int loc;
    len = length();
    struct node* temp , *p, *q, *s;
    temp = p = root;
    printf("Enter your location to delete:");
    scanf("%d", &loc);
    if(loc > len)
    {
        printf("Invalid Location\n");
    }
    else if(loc == 1)
    {
        temp = p ->right;
        root = temp;
        free(p);
    }
    else
    {
        int i = 1;
        while(i < loc-1)
        {
            p = p ->right;
            i++;
        }
         q = p ->right;
         s = q -> right;
         p ->right = s;
         s ->left = q;
         s ->right = NULL;
         free(q);
         free(s);
    }
    
}