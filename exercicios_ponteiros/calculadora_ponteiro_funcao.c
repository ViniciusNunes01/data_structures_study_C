#include <stdio.h>
#include <stdlib.h>

typedef double (*TipoOperacao)(double, double);

double soma(double a, double b)
{
    return a + b;
}

double subtracao(double a, double b)
{
    return a - b;
}

double multiplicacao(double a, double b)
{
    return a * b;
}

double divisao(double a, double b)
{
    return a / b;
}

double calcular(double a, double b, TipoOperacao op)
{
    return op(a, b);
}

int main(void)
{
    double numero1, numero2;
    int operacao;

    TipoOperacao operacoes[4] = {soma, subtracao, multiplicacao, divisao};

    printf("Digite o primeiro numero: ");
    scanf("%lf", &numero1);

    printf("Digite o segundo numero: ");
    scanf("%lf", &numero2);

    printf("\n1 - Soma");
    printf("\n2 - Subtracao");
    printf("\n3 - Multiplicacao");
    printf("\n4 - Divisao");

    printf("\nOpcao: ");
    scanf("%d", &operacao);

    if (operacao >= 1 && operacao <= 4)
    {
        double resultado = calcular(numero1, numero2, operacoes[operacao - 1]);
        printf("\nResultado: %lf\n", resultado);
    }
    else
    {
        printf("\nOpcao invalida\n");
    }

    return 0;
}