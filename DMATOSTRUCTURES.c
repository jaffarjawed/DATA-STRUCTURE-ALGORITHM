#include <stdio.h>
#include <stdlib.h>

struct emp
{
    int eno;
    char ename[20];
    float esal;
};

int main()
{
    int i;
    struct emp* ptr;
    ptr = (struct emp*)malloc(sizeof(struct emp));
    if (ptr == NULL)
    {
        printf("Out of Memory error");
    }
    else
    {
        for(i=0; i <= 3; i++)
        {
            printf("Enter Employee details: ");
            scanf("%d %s %f", &ptr -> eno, ptr -> ename, &ptr -> esal);
            printf("Emp No: %d\nEmp name: %s\nEmp esal: %f\n", ptr -> eno, ptr -> ename, ptr -> esal);
        }
    }
     return 0;
}
