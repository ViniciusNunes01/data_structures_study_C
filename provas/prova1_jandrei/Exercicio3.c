#include <stdio.h>

int potencia(int b, int e)
{
    if (e == 0)
    {
        return 1;
    }

    return b * potencia(b, e - 1);
}

int main()
{

    int base = 2;
    int exp = 10;

    printf("Resultado: %d", potencia(base, exp));

    return 0;
}