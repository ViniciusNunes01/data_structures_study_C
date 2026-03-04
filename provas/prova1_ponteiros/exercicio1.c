#include <stdio.h>
#include <stdlib.h>

int contido(int *v1, int *v2, int n1, int n2)
{
    for (int i = 0; i < n1; i++)
    {
        int encontrado = 0;

        for (int j = 0; j < n2; j++)
        {
            if (*(v1 + i) == *(v2 + j))
            {
                encontrado = 1;
                break;
            }
        }

        if (encontrado == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    int n1 = 0;
    int n2 = 0;

    printf("Digite o tamanho do primeiro vetor: ");
    scanf("%d", &n1);
    printf("Digite o tamanho do segundo vetor: ");
    scanf("%d", &n2);

    int *vetor1 = (int *)malloc(sizeof(int) * n1);
    int *vetor2 = (int *)malloc(sizeof(int) * n2);

    printf("\nInsira os dados para o VETOR 1: ");
    printf("\n");
    for (int i = 0; i < n1; i++)
    {
        printf("V1[%d] = ", i + 1);
        scanf("%d", (vetor1 + i));
    }

    printf("\nInsira os dados para o VETOR 2: ");
    printf("\n");
    for (int i = 0; i < n2; i++)
    {
        printf("V2[%d] = ", i + 1);
        scanf("%d", (vetor2 + i));
    }

    if (contido(vetor1, vetor2, n1, n2) == 1)
    {
        printf("\nO VETOR 1 ESTA CONTIDO NO VETOR 2!");
    }
    else
    {
        printf("\nO VETOR 1 NAO ESTA CONTIDO NO VETOR 2!");
    }

    free(vetor1);
    free(vetor2);
}