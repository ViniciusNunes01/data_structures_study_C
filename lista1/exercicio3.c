#include <stdio.h>
#include <stdlib.h>

// Escreva um programa em C que leia um nu mero inteiro e
// determina se e  um nu mero perfeito.
// Um nu mero e  perfeito se a soma dos seus divisores e  igual ao pro prio nu mero. Por
// exemplo, o nu mero 6 e  perfeito, pois a soma dos seus divisores - 1 + 2 + 3 – e  igual a 6.
// A lo gica do programa para determinar se um nu mero e  perfeito deve ser implementada
// com uma funça o.
// int perfeito(int *n)

int *perfeito(int *n)
{

    int *soma = malloc(sizeof(int));
    *soma = 0;

    for (int i = 1; i < *n; i++)
    {
        if (*n % i == 0)
        {
            *soma += i;
        }
    }

    return soma;
}

int main(void)
{
    int *numero = malloc(sizeof(int));

    printf("Digite um numero: ");
    scanf("%d", numero);

    int *resultado = perfeito(numero);

    if (*resultado == *numero)
    {
        printf("O numero eh perfeito!");
    }
    else
    {
        printf("O numero nao eh perfeito!");
    }

    free(numero);
    free(resultado);
}
