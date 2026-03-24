// Exercicio 1: Soma com antecessor e sucessor
// Caso Base: y=0 -> x
// Caso Recursivo: x+1 e y-1

#include <stdio.h>

int sucessor(int n)
{
    return n + 1;
}

int antecessor(int n)
{
    return n - 1;
}

int soma(int x, int y)
{
    if (y == 0)
    {
        return x;
    }

    return soma(sucessor(x), antecessor(y));
}

int main()
{
    int x = 7, y = 3;

    printf("Resultado de %d + %d = %d", x, y, soma(x, y));

    return 0;
}