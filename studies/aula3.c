#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// typedef void (*Formatar)(void *);

// void exibirComoInteiro(void *p)
// {
//     printf("Processando Inteiro: %d\n", *(int *)p);
// }

// void exibirComoFloat(void *p)
// {
//     printf("Processando Float: %.2f\n", *(float *)p);
// }

// void processadorDeDados(void *endereco, Formatar acao)
// {
//     if (endereco != NULL && acao != NULL)
//     {
//         acao(endereco);
//     }
// }

//____________________________________________________________________________

typedef struct
{
    int id;
    char nome[50];
    float salario;
} RegistroPessoa;

int main()
{

    // int numeroInteiro = 56;
    // float numeroReal = 3.1415;

    // umNomeLegal(&numeroInteiro, 'i');
    // umNomeLegal(&numeroReal, 'f');

    //________________________________________________________________________

    // int idade = 25;
    // float salario = 3500.50;

    // processadorDeDados(&idade, exibirComoInteiro);
    // processadorDeDados(&salario, exibirComoFloat);

    //________________________________________________________________________

    RegistroPessoa usuario;

    printf("=== CADASTRO DE USUARIO ===\n");

    printf("Informe o ID: ");
    scanf("%d", &usuario.id);

    getchar();
    printf("Informe o nome: ");
    fgets(usuario.nome, 50, stdin);
    usuario.nome[strcspn(usuario.nome, "\n")] = 0;

    printf("Informe o salario: ");
    scanf("%f", &usuario.salario);

    printf("\n--- Dados Cadastrados ---\n");
    printf("ID: %d\nNome: %s\nSalario: R$ %.2f", usuario.id, usuario.nome, usuario.salario);
    return 0;
}