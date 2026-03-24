#include <stdio.h>

int mult(int a, int b)
{
    if (b == 0)
    {
        return 0;
    }

    return a + mult(a, b - 1);
}

int main()
{

    int x = 7, y = 3;

    printf("Resultado de %d * %d = %d", x, y, mult(x, y));

    return 0;
}