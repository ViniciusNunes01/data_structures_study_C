#include <stdio.h>
#include <stdlib.h>

int maior(int *vetor, int *numero)
{
    int maior = *vetor;
    for (int i = 1; i < *numero; i++) // começa em 1 pois a posição 0 ja está com o primeiro elemento do vetor (*vetor)
    {
        if (*(vetor + i) > maior)
        {
            maior = *(vetor + i);
        }
    }
    return maior;
}

int main(void)
{

    // [PONTEIRO COM VETOR]
    // Escreva um programa em C que leia um numero inteiro N e,
    // em seguida, aloque memoria suficiente para armazenar N numeros inteiros.
    // Escreva tambem uma funçao que receba os N numeros inteiros e retorne o maior numero
    // dentre eles.
    // int maior(int *vetor)
    // Obs: NÃO use a notação de vetor (colchetes) da linguagem C para manipulação dos
    // elementos do vetor, utilize somente aritmética de ponteiros.

    int *numero = malloc(sizeof(int));

    printf("\nInforme um numero: ");
    scanf("%d", numero);
    printf("\n");
    
    int *vetor = (int *)malloc(*numero * sizeof(int));
    for (int i = 0; i < *numero; i++)
    {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", vetor + i);
    }

    printf("\nO maior numero eh %d", maior(vetor, numero));

    printf("\n\n");
    free(numero);
    free(vetor);
}
