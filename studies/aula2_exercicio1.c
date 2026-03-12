#include <stdio.h>
#include <stdlib.h>

int main()
{

    // Criar matriz 2x3 e encontrar o menor elemento

    int matriz[2][3];
    int *pMatriz = (int *)matriz;
    int menor;

    for (int i = 0; i < 6; i++, pMatriz++)
    {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", pMatriz);

        if (i == 0)
        {
            menor = *pMatriz;
        }

        if (*pMatriz <= menor)
        {
            menor = *pMatriz;
        }

        printf("\nO menor elemento atual: %d\n\n", menor);
    }

    printf("\n\nO menor elemento eh: %d", menor);

    return 0;
}