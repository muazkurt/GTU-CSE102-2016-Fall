#include <stdio.h>

int f(x, y)
{
    int total = 0;
    if (x <= 0 || y <= 0)
        ;
    else
        total = f(x - 1, y) + f(x, y - 1) + x + y;
    return total;
}

void main()
{
    printf("%d", f(3, 3));
    return;
}