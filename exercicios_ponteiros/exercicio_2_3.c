/*
================================================================================
EXERCÍCIO 2.3 - Ponteiros como Parâmetros
================================================================================

OBJETIVO:
- Crie uma função que receba um array de inteiros e seu tamanho
- Encontre o maior valor do array
- Armazene o maior valor em um inteiro apontado por um ponteiro (passado como parâmetro)

SAÍDA ESPERADA:
Array: 15 8 42 3 27 11
Maior valor: 42

================================================================================
*/

#include <stdio.h>

// Assim que é feito: a função pode ser void, porque devolve o resultado por ponteiro.
// E não daquele outro jeito: retornar int quando o exercício pede saída via parâmetro.
void encontrar_maximo(int *array, int tamanho, int *maximo)
{
    // Assim que é feito: começa assumindo o primeiro elemento como máximo.
    // E não daquele outro jeito: comparar sem inicializar *maximo.
    *maximo = *array;

    // Assim que é feito: i é índice inteiro (1 até tamanho-1).
    // E não daquele outro jeito: int i = array (mistura índice com ponteiro).
    // E não daquele outro jeito: i < tamanho - 1 (pula o último elemento).
    for (int i = 1; i < tamanho; i++)
    {
        // Assim que é feito: compara cada elemento array[i] com *maximo.
        // E não daquele outro jeito: comparar sempre *array (olha só o primeiro elemento).
        if (array[i] > *maximo)
        {
            *maximo = array[i];
        }
    }
}

int main()
{
    int array[] = {15, 8, 42, 3, 27, 11};

    // Assim que é feito: nome do vetor "array" vira ponteiro para o primeiro elemento.
    // E não daquele outro jeito: &array (tipo diferente) ou array[0] (isso é int, não int*).
    int *pArray = array;

    int tamanho = 6;

    int maximo;
    int *pMaximo = &maximo;

    printf("Array: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    encontrar_maximo(pArray, tamanho, pMaximo);

    // Assim que é feito: imprime o valor encontrado via ponteiro.
    // Se quiser bater 100% com o enunciado, use "Maior valor" (v minúsculo).
    printf("Maior valor: %d", *pMaximo);

    return 0;
}