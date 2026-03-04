/*
================================================================================
EXERCÍCIO 1.3 - Ponteiros e Arrays
================================================================================

OBJETIVO:
- Declare um array de 5 inteiros.
- Use um ponteiro para percorrer o array
- Imprima cada elemento usando aritmética de ponteiros (sem usar índices)

SAÍDA ESPERADA:
10 20 30 40 50

================================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamanho = 0;

    printf("\nDeclare o damanho do vetor: ");
    scanf("%d", &tamanho);

    int *array = (int *)malloc(sizeof(int) * tamanho);
    int *ptr = array;

    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", ptr);
        ptr++;
    }

    printf("\n");
    ptr = array;

    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", *ptr);
        ptr++;
    }

    free(array);
    return 0;
}
