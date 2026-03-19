#include <stdio.h>
#include <stdlib.h>

void verificarMaior(void *a, void *b, int (*comparar)(void *, void *))
{
    int *r = malloc(sizeof(int));
    *r = comparar(a, b);

    if (*r > 0)
    {
        printf("O primeio valor eh maior que o segundo\n");
    }
    else if (*r < 0)
    {
        printf("O segundo valor eh maior que o primeiro\n");
    }
    else
    {
        printf("Os valores sao iguais\n");
    }
}

int compararInteiros(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{

    int x = 20, y = 10;

    verificarMaior(&x, &y, compararInteiros);

    return 0;
}