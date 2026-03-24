// Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas.
// Imprima o endereco de cada posicao dessa matriz.

#include <stdio.h>
#include <stdlib.h>

int main()
{

    float matriz[3][3];
    float (*pMatriz)[3] = matriz;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Endereco na posicao [%d][%d]: %p\n", i + 1, j + 1, &pMatriz[i][j]);
        }
    }

    return 0;
}