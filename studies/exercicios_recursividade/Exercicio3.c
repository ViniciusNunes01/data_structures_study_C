#include <stdio.h>

int ocorr(int k, int n)
{

    if (n == 0)
    {
        return 0;
    }

    if (n % 10 == k)
    {
        return (1 + ocorr(k, n / 10));
    }
    else
    {
        return (0 + ocorr(k, n / 10));
    }
}

int main()
{

    int n = 1202, k = 2;
    int res = ocorr(k, n);

    printf("Existem %d ocorrencias do numero %d em %d", res, k, n);

    return 0;
}