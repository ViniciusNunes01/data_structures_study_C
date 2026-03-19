// Dentro do estudo de tipos heterogêneos, a struct é a ferramenta fundamental para agrupar informações de
// naturezas distintas em uma única unidade lógica . O domínio do operador de seleção de membro (ponto) é o
// primeiro passo para a gestão de dados em memória volátil.

// Implemente uma função chamada calcularSalarioAnual que receba como parâmetro uma estrutura do tipo Pessoa
// e retorne o valor total de sua remuneração ao longo de 12 meses. Utilize a definição de tipo fornecida.

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nome[50];
    float salarioMensal;
} Pessoa;

float calcularSalarioAnual(Pessoa *pessoa)
{
    float salarioDozeMeses = pessoa->salarioMensal * 12;

    return salarioDozeMeses;
}

int main()
{
    Pessoa pessoa = {1, "João", 2500.00};

    printf("O salario anual de Joao eh: R$ %.2f", calcularSalarioAnual(&pessoa));

    return 0;
}