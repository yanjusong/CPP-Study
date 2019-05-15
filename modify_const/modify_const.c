#include <stdio.h>

int main()
{
    const int x = 10;
    int *p = (int *)&x;
    *p = 11;

    printf("after modified by pointer, x=%d\n", x);

    return 0;
}
