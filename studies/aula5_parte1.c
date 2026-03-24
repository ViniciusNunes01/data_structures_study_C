// Realizar a soma de elementos de um vetor de forma recursiva

#include <stdio.h>
#include <stdlib.h>

int somarVetor(int v[], int n)
{

    if (n == 0)
    {
        return 0;
    }

    return v[n - 1] + somarVetor(v, n - 1);
}

int main()
{

    int vetor[] = {1, 1, 2, 3, 5, 8, 13};
    int tamanho = 7;

    int total = somaVetor(vetor, tamanho);
    printf("Soma total: %d", total);

    return 0;
}