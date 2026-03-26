#include <stdio.h>

typedef struct
{
    int id;
    char nome[50];
    float salario;
} RegistroPessoa;

void aplicarBonus(RegistroPessoa *p, float bonus)
{
    p->salario += bonus;
}

int main()
{

    RegistroPessoa pessoa = {1, "Jandrei", 5000.00};
    RegistroPessoa *prof = &pessoa;

    aplicarBonus(prof, 500.0);

    printf("Novo Salario: %.2f", prof->salario);

    return 0;
}