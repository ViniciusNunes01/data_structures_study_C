#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *arquivo;
    arquivo = fopen("teste.txt", "a");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir!\n");
        return 1;
    }

    char mensagem[100];
    printf("Digite o seu texto: ");
    scanf("%[^\n]", mensagem);

    fprintf(arquivo, "%s\n", mensagem);

    fclose(arquivo);

    return 0;
}