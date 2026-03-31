// Crie um programa que aloque dinamicamente um vetor para armazenar 3 números inteiros.
// O programa deve preencher o vetor com os valores {10, 20, 30}, imprimir a soma desses valores e, por fim, liberar a memória.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *vetor = malloc(sizeof(int) * 3);
    int soma = 0;

    if (vetor == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    vetor[0] = 10;
    vetor[1] = 20;
    vetor[2] = 30;

    for (int i = 0; i < 3; i++)
    {
        soma += vetor[i];
    }

    printf("Soma: %d\n", soma);

    free(vetor);

    return 0;
}