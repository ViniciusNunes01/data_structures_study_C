#include <stdio.h>
#include <stdlib.h>

int main()
{

    // FILE *arquivo;
    // arquivo = fopen("teste.txt", "a");

    // if (arquivo == NULL)
    // {
    //     printf("Erro ao abrir!\n");
    //     return 1;
    // }

    // char mensagem[100];
    // printf("Digite o seu texto: ");
    // scanf("%[^\n]", mensagem);

    // fprintf(arquivo, "%s\n", mensagem);

    // fclose(arquivo);

    FILE *arquivo;
    arquivo = fopen("teste.txt", "r");

    if (arquivo == NULL)
    {
        return 1;
    }

    char buffer[100];

    while (fscanf(arquivo, "%s", buffer) != EOF)
    {
        printf("Palavra lida: %s\n", buffer);
    }

    fclose(arquivo);
    return 0;
}