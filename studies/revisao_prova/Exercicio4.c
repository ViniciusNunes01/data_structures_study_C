#include <stdio.h>

int main()
{

    int numero = 10;
    int *pNumero = &numero;

    *pNumero = 42;

    printf("Valor final da variavel: %d", numero);

    return 0;
}