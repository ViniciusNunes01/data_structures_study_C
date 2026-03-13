// Crie um programa que contenha uma funcao que permita passar por parametro dois
// numeros inteiros A e B. A funcao devera calcular a soma entre estes dois numeros e
// armazenar o resultado na variavel A. Esta funcao nao devera possuir retorno, mas devera
// modificar o valor do primeiro parametro. Imprima os valores de A e B na funcao principal.

#include <stdio.h>
#include <stdlib.h>

void soma_dois_numeros_retornando_variavel_A(int *a, int *b)
{
    *a += *b;
}

int main()
{

    int *pA = (int *)malloc(sizeof(int));
    int *pB = (int *)malloc(sizeof(int));

    printf("Digite o primeiro valor: ");
    scanf("%d", pA);
    printf("Digite o segundo valor: ");
    scanf("%d", pB);

    soma_dois_numeros_retornando_variavel_A(pA, pB);

    printf("\nValor de A apos a soma: %d", *pA);
    printf("\nValor de B: %d", *pB);

    free(pA);
    free(pB);

    return 0;
}