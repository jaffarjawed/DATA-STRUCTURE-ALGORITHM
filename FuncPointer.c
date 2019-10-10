#include <stdio.h>

int main()
{
    int r1, r2, r3;
    int (*ptr) (int, int);
    r1 = add(10, 20);
    r2 = mult(10, 20, 30);
    printf("%d, and\t %d\n\n", r1, r2);
    ptr = &add;
    ptr = &mult;
    r3 = ptr(10, 20);
    printf("By using pointer func %d", r3);

}

int add(int x, int y)
{
    int z;
    z = x + y;
    return z;
}
 int mult(int x, int y, int z)
 {

     z = x * y * z;
     return z;
 }
