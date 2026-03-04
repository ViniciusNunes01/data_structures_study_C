#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *numeroA = malloc(sizeof(int));
    int *numeroB = malloc(sizeof(int));
    int *trocador = malloc(sizeof(int));

    printf("\nInforme o numero A: ");
    scanf("%d", numeroA);
    printf("Informe o numero B: ");
    scanf("%d", numeroB);

    *trocador = *numeroA;
    *numeroA = *numeroB;
    *numeroB = *trocador;

    printf("\nAPOS A TROCA: ");
    printf("\nA = %d", *numeroA);
    printf("\nB = %d", *numeroB);

    free(numeroA);
    free(numeroB);
    free(trocador);
}