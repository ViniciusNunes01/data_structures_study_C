// Escreva um programa que contenha duas variaveis inteiras. Compare seus enderecos e
// exiba o maior endereco.

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a = 0;
    int b = 0;

    printf("\nEndereco de A: %p", &a);
    printf("\nEndereco de B: %p", &b);

    if (&a > &b)
    {
        printf("\nO endereco de A e maior (vem depois)");
    }
    else
    {
        printf("\nO endereco de B e maior (vem depois)");
    }

    return 0;
}