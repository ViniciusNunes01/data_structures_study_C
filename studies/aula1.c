#include <stdio.h>
#include <stdlib.h>

int main()
{
    //  printf("Fundamentos de Estrutura de Dados!");

    int m;
    int *p;

    m = 42;
    p = &m;

    printf("Valor armazenado em m: %d", m);
    printf("\nEndereco de m: %p", &m);
    printf("\nEndereco apontado por p: %p", p);
    printf("\nValor apontado por p: %d", *p);

    *p = 100;
    printf("\n\nValor alterado atraves do ponteiro: %d", m);

    printf("\n\n________________________________________");
    printf("\n\n");

    float *pFloat;
    printf("O endereco de pFloat eh %p", pFloat);
    pFloat++;
    printf("\nO novo endereco de pFloat eh: %p", pFloat);

    printf("\n\n________________________________________");
    printf("\n\n");

    char str[30], *pStr;

    pStr = str;

    printf("Digite um nome: ");
    gets(str);
    printf("O nome digitado foi: ");
    while (*pStr)
    {
        printf("%c", *pStr++);
    }
    printf("\n");

    return 0;
}