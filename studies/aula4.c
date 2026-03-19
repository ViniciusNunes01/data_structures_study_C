#include <stdio.h>
#include <stdlib.h>

// void mensagem()
// {
//     printf("\nMensagem dentro de uma funcao!\n");
// }

//___________________________________________________________________________

// int soma(int a, int b)
// {
//     return a + b;
// }

// int produto(int a, int b)
// {
//     return a * b;
// }

//___________________________________________________________________________

void processar(int *vetor, int tamanho, int (*regra)(int))
{
    for (int i = 0; i < tamanho; i++)
    {
        *(vetor + i) = regra(*(vetor + i));
    }
}

int dobrar(int x)
{
    return 2 * x;
}

int elevarAoQuadrado(int x)
{
    return x * x;
}

int elevarAoCubo(int x)
{
    return x * x * x;
}

int main()
{

    // void (*PonteiroFuncao)();

    // PonteiroFuncao = mensagem;

    // PonteiroFuncao();

    //___________________________________________________________________________

    // int (*Operacao)(int, int);

    // Operacao = soma;
    // printf("Soma: %d\n", Operacao(5, 3));

    // Operacao = produto;
    // printf("Produto: %d\n", Operacao(5, 3));

    //___________________________________________________________________________

    int num[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", num[i]);
    }

    processar(num, 5, dobrar);

    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", num[i]);
    }

    printf("\n");

    processar(num, 5, elevarAoQuadrado);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", num[i]);
    }

    printf("\n");

    processar(num, 5, elevarAoCubo);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", num[i]);
    }

    return 0;
}