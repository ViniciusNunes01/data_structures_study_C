#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    // 2 -  Escreva um programa em C que leia 3 numeros inteiros e informa o tipo de triangulo formado pelos 3 numeros.
    // - Equilátero : 3 lados iguais
    // - Isósceles: 2 lados iguais
    // - Escaleno: todos os lados diferentes

    int *numero1 = malloc(sizeof(int));
    int *numero2 = malloc(sizeof(int));
    int *numero3 = malloc(sizeof(int));

    printf("Digite o primeiro numero: ");
    scanf("%d", numero1);
    printf("Digite o segundo numero: ");
    scanf("%d", numero2);
    printf("Digite o terceiro numero: ");
    scanf("%d", numero3);

    if (*numero1 == *numero2 && *numero1 == *numero3)
    {
        printf("\nTRIANGULO EQUILATERO\n");
    }
    else if (*numero1 == *numero2 || *numero1 == *numero3 || *numero2 == *numero3)
    {
        printf("\nTRIANGULO ISOSCELES\n");
    }
    else
    {
        printf("\nTRIANGULO ESCALENO\n");
    }
}