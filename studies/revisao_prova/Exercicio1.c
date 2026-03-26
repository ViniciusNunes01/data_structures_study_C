#include <stdio.h>

int main()
{

    int valor = 10;
    int *pValor = &valor;

    printf("O valor apontado eh %d", *pValor);

    return 0;
}