#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int ano;

} Data;

int diferencaDias(Data *data1, Data *data2)
{

    int dias1 = (data1->ano * 365) - (data1->mes * 30) - (data1->dia);
    int dias2 = (data2->ano * 365) - (data2->mes * 30) - (data2->dia);

    return abs(dias1 - dias2);
}

int main(void)
{

    Data *data1 = malloc(sizeof(Data));
    Data *data2 = malloc(sizeof(Data));

    printf("\nVamos calcular a diferenca entre duas datas!");
    printf("\n");
    printf("Informe a primeira data");
    printf("\nDia: ");
    scanf("%d", &data1->dia);
    printf("Mes: ");
    scanf("%d", &data1->mes);
    printf("Ano: ");
    scanf("%d", &data1->ano);
    printf("\nInforme a segunda data");
    printf("\nDia: ");
    scanf("%d", &data2->dia);
    printf("Mes: ");
    scanf("%d", &data2->mes);
    printf("Ano: ");
    scanf("%d", &data2->ano);

    printf("\nA diferenca em dias das datas informadas eh de: %d dias!", diferencaDias(data1, data2));

    free(data1);
    free(data2);
}