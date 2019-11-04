#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
void free_node();
void append();
void inorder();
void preorder();
void postorder();
void main()
{
    int ch;
    while (1)
    {
        printf("1.Append in tree\n");
        printf("2.Inorder traversal of Binary tree\n");
        printf("3.Preorder traversal of Binary tree\n");
        printf("4.Postorder traversal of Binary tree\n");
        printf("5.Delete node in binary tree\n");
        printf("5.Quit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            append();
            break;
        case 2:
            inorder(root);
            printf("\n\n");
            break;
        case 3:
            preorder(root);
            printf("\n\n");
            break;
        case 4:
            postorder(root);
            printf("\n\n");
            break;
        case 5:
            free_node(root);
            break;
        case 6:
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
void append()
{
    struct node *temp, *p = root;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->left = NULL;
    temp->right = NULL;
    printf("Enter your data to append:");
    scanf("%d", &temp->data);
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *curr = root;
        while (curr)
        {
            p = curr;
            if (temp->data > curr->data)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }
        if (temp->data > p->data)
        {
            p->right = temp;
        }
        else
        {
            p->left = temp;
        }
    }
}
void inorder(struct node *temp)
{
    if (temp == NULL)
        return;
    inorder(temp->left);
    printf("%d ->", temp->data);
    inorder(temp->right);
}
void preorder(struct node *temp)
{
    if (temp == NULL)
        return;
    printf("%d ->", temp->data);
    preorder(temp->left);
    preorder(temp->right);
}
void postorder(struct node *temp)
{
    if (temp == NULL)
        return;
    postorder(temp->left);
    postorder(temp->right);
    printf("%d ->", temp->data);
}
void free_node(struct node *p)
{
    if (p == NULL)
        return;
    free_node(p->left);
    free_node(p->right);
    free(p);
}
