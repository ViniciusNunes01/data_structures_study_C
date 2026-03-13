// Faca um programa que leia dois valores inteiros e chame uma funcao que receba estes
// 2 valores de entrada e retorne o maior valor na primeira variavel e o menor valor na
// segunda variavel. Escreva o conteudo das 2 variaveis na tela.

#include <stdio.h>
#include <stdlib.h>

void funcao_troca_valor(int *v1, int *v2)
{
    if (*v2 > *v1)
    {
        int temp = 0;
        temp = *v1;
        *v1 = *v2;
        *v2 = temp;
    }
}

int main()
{

    int *primeiraVariavel = (int *)malloc(sizeof(int));
    int *segundaVariavel = (int *)malloc(sizeof(int));

    printf("Digite o primeiro valor: ");
    scanf("%d", primeiraVariavel);
    printf("Digite o segundo valor: ");
    scanf("%d", segundaVariavel);

    funcao_troca_valor(primeiraVariavel, segundaVariavel);

    printf("\nConteudo da primeira variavel: %d", *primeiraVariavel);
    printf("\nConteudo da segunda variavel: %d", *segundaVariavel);

    free(primeiraVariavel);
    free(segundaVariavel);

    return 0;
}