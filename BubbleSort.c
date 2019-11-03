#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i, j, n, temp;
    printf("Enter size of array:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter your array no:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ->", arr[i]);
    }
}
