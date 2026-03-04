/*
================================================================================
EXERCÍCIO 2.2 - Retorno de Ponteiro
================================================================================

OBJETIVO:
- Crie uma função que aloque dinamicamente um array de n inteiros
- Preencha este array com os números de 1 até n
- Retorne um ponteiro para este array
- Escreva uma função chamadora que teste isto

SAÍDA ESPERADA (para n = 5):
Array: 1 2 3 4 5

================================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int *criar_array(int tamanho)
{
    int *array = (int *)malloc(sizeof(int) * tamanho);

    for (int i = 0; i < tamanho; i++)
    {
        *(array + i) = i + 1;
    }
    return array;
}

int main()
{

    int n = 0;

    printf("\nInforme o tamanho do vetor: ");
    scanf("%d", &n);

    int *ptr = criar_array(n);

    printf("Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }

    free(ptr);
    return 0;
}
