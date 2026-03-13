// Elaborar um programa que leia dois valores inteiros (A e B). Em seguida faca uma funcao
// que retorne a soma do dobro dos dois numeros lidos. Afuncao devera armazenar o dobro
// de A na propria variavel A e o dobro de B na propria variavel B.

#include <stdio.h>
#include <stdlib.h>

int soma_dos_dobros(int *a, int *b)
{
    int somados = 0;

    *a *= 2;
    *b *= 2;

    somados = *a + *b;

    return somados;
}

int main()
{

    int *pA = (int *)malloc(sizeof(int));
    int *pB = (int *)malloc(sizeof(int));

    printf("Digite o primeiro valor: ");
    scanf("%d", pA);
    printf("Digite o segundo valor: ");
    scanf("%d", pB);

    int soma = soma_dos_dobros(pA, pB);

    printf("\nDobro de A: %d", *pA);
    printf("\nDobro de B: %d", *pB);
    printf("\nSoma: %d", soma);

    free(pA);
    free(pB);

    return 0;
}