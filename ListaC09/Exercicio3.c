// Escreva um programa que contenha duas variaveis inteiras. Leia essas variaveis do
// teclado. Em seguida, compare seus enderecos e exiba o conteudo do maior endereco.

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a = 0, b = 0;
    int *pA = &a;
    int *pB = &b;

    printf("Digite o valor de A: ");
    scanf("%d", pA);
    printf("Digite o valor de B: ");
    scanf("%d", pB);

    printf("\nA: %d", *pA);
    printf("\nEndereco de A: %p", pA);
    printf("\nB: %d", *pB);
    printf("\nEndereco de B: %p", pB);

    printf("\n\n");

    if (pA > pB)
    {
        printf("O maior endereco eh o de A\n");
        printf("Valor: %d", *pA);
    }
    else
    {
        printf("O maior endereco eh o de B\n");
        printf("Valor: %d", *pB);
    }

    return 0;
}