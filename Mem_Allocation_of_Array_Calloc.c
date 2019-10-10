#include <stdio.h>
#include <stdlib.h>

void main()
{
    int capacity, *arr, i;
    printf("Enter the size of array: ");
    scanf("%d", &capacity);
    arr = (int *)calloc(capacity, sizeof(int));
    if (arr == NULL)
        printf("Out of MEM Error");
    else
    {
        for(i = 0; i < capacity; i++)
        {
            printf("Enter the elements of: ");
            scanf("%d", &*(arr + i));
        }
        for(i = 0; i < capacity; i++)
        {
         printf("Elements are: %d\n", *(arr + i));
        }

    }
}
