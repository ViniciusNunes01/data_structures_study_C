#include <stdio.h>
#include <stdlib.h>

int main()
{

    typedef struct
    {
        float salario;
    } Pessoa;

    Pessoa *pessoa = (Pessoa *)malloc(sizeof(Pessoa));

    pessoa->salario = 5000.00;

    printf("salario: %.2f", pessoa->salario);

    return 0;
}