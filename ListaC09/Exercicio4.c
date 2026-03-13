#include <stdio.h>
#include <stdlib.h>

void troca_valor(int *pA, int *pB)
{
    int temp = 0;
    temp = *pA;
    *pA = *pB;
    *pB = temp;
}

int main()
{

    int a = 0, b = 0;
    int *pA = &a, *pB = &b;

    printf("Digite o primeiro valor: ");
    scanf("%d", pA);
    printf("Digite o segundo valor: ");
    scanf("%d", pB);

    troca_valor(pA, pB);

    printf("\nValores trocados: ");
    printf("\nA = %d", *pA);
    printf("\nB = %d\n\n", *pB);

    return 0;
}