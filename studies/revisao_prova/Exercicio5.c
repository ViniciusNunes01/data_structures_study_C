#include <stdio.h>

int somaRecursiva(int v[], int tamanho)
{
    if (tamanho == 1)
    {
        return 1;
    }

    return v[tamanho - 1] + somaRecursiva(v, tamanho - 1);
}

int main()
{
    int vetor[5] = {1, 2, 3, 4, 5};
    int tamanho = 5;

    printf("Soma: %d", somaRecursiva(vetor, tamanho));

    return 0;
}