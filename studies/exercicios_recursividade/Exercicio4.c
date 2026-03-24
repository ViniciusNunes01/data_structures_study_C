#include <stdio.h>

int mdc(int x, int y)
{
    if (y == 0)
    {
        return x;
    }

    return mdc(y, x % y);
}

int main()
{

    int a = 48, b = 18;

    printf("Valor final: %d", mdc(a, b));

    return 0;
}