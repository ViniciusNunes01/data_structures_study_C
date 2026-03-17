#include <stdio.h>
#include <stdlib.h>

// void umNomeLegal(void *p, char tipo)
// {
//     if (tipo == 'i')
//     {
//         int valor = *(int *)p;
//         printf("O dado informado como inteiro eh: %d\n", valor);
//     }

//     if (tipo == 'f')
//     {
//         float valor = *(float *)p;
//         printf("O dado informado como real eh: %f\n", valor);
//     }
// }

//___________________________________________________________________________

typedef void (*Formatar)(void *);

void exibirComoInteiro(void *p)
{
    printf("Processando Inteiro: %d\n", *(int *)p);
}

void exibirComoFloat(void *p)
{
    printf("Processando Float: %.2f\n", *(float *)p);
}

void processadorDeDados(void *endereco, Formatar acao)
{
    if (endereco != NULL && acao != NULL)
    {
        acao(endereco);
    }
}

int main()
{

    // int numeroInteiro = 56;
    // float numeroReal = 3.1415;

    // umNomeLegal(&numeroInteiro, 'i');
    // umNomeLegal(&numeroReal, 'f');

    //________________________________________________________________________

    int idade = 25;
    float salario = 3500.50;

    processadorDeDados(&idade, exibirComoInteiro);
    processadorDeDados(&salario, exibirComoFloat);

    return 0;
}