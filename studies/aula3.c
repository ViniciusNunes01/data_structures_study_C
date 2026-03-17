#include <stdio.h>
#include <stdlib.h>

void umNomeLegal(void *p, char tipo)
{
    if (tipo == 'i')
    {
        int valor = *(int *)p;
        printf("O dado informado como inteiro eh: %d\n", valor);
    }

    if (tipo == 'f')
    {
        float valor = *(float *)p;
        printf("O dado informado como real eh: %f\n", valor);
    }
}

int main()
{

    int numeroInteiro = 56;
    float numeroReal = 3.1415;

    umNomeLegal(&numeroInteiro, 'i');
    umNomeLegal(&numeroReal, 'f');

    return 0;
}