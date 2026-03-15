#include <stdio.h>
#include <stdlib.h>

int main()
{
    float comprimento = 0, profundidade = 0;

    printf("comprimento: ");
    scanf("%f", &comprimento);
    printf("profundidade: ");
    scanf("%f", &profundidade);

    printf("Valor do terreno: R$%.2f", (comprimento * profundidade) * 500.00);

    return 0;
}