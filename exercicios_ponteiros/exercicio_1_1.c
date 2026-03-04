/*
================================================================================
EXERCÍCIO 1.1 - Declaração e Inicialização
================================================================================

OBJETIVO:
- Declare um inteiro com valor 42
- Declare um ponteiro para inteiro
- Inicialize o ponteiro apontando para o inteiro
- Imprima o valor do inteiro usando o ponteiro

SAÍDA ESPERADA:
O valor usando ponteiro: 42

================================================================================
*/

#include <stdio.h>

int main()
{

    int valor = 42;
    int *pValor = &valor;

    printf("\nO valor usando ponteiro: %d\n\n", *pValor);

    return 0;
}
