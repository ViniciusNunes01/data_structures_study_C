// Escreva um programa com uma função recursiva estaOrdenado(int v[], int n) que retorne 1 se o vetor estiver em ordem crescente e 0 caso contrário.
// No main, teste com o vetor {1, 3, 5, 8, 10}.
// Proibido o uso de laços.

#include <stdio.h>

int estaOrdenado(int v[], int n)
{
    if (n <= 1)
    {
        return 1;
    }

    if (v[n - 2] > v[n - 1])
    {
        return 0;
    }

    return estaOrdenado(v, n - 1);
}

int main()
{
    int vetor[5] = {1, 3, 5, 8, 10};
    int resultado = estaOrdenado(vetor, 5);

    if (resultado)
    {
        printf("Ordenado");
    }
    else
    {
        printf("Não Ordenado");
    }

    return 0;
}