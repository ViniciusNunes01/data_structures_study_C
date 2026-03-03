#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // 1 - Ler dois n�meros reais e imprimir a m�dia entre eles.

    int *numero1 = malloc(sizeof(int));
    int *numero2 = malloc(sizeof(int));
    float *media = malloc(sizeof(float));

    printf("Digite um numero: ");
    scanf("%d", numero1);
    printf("Digite um numero: ");
    scanf("%d", numero2);

    *media =(float)(*numero1 + *numero2) / 2;

    printf("A media eh: %.2f", *media);

    free(numero1);
    free(numero2);
    free(media);

}