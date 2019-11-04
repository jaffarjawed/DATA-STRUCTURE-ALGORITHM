//Implementing Selection Sort on any n size array
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, i, j, temp, min;
    int arr[5];
    printf("Enter size of array:");
    scanf("%d", &n);
    printf("Enter your data:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n\n");
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ->", arr[i]);
    }
}
