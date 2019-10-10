#include <stdio.h>
void swap(int*, int*);
int main()
{
    int temp;
    int a = 10, b = 20;
    temp = b;
    b = a;
    a = temp;
    printf("%d\n", a);
    printf("%d\n", b);

    printf("-------------------------------------->\n\n\n");


    int c = 10, d = 20;
    printf("Before swapping %d  and\t %d\n\n", c, d);
    swap(&c, &d);
    printf("After swapping %d and %d\n", c, d);
}
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    printf("In called function swapping %d and %d\n\n", *x, *y);

}
