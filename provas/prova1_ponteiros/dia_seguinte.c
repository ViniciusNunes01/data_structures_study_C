#include <stdio.h>
#include <stdlib.h>

typedef struct
{

    int dia;
    int mes;
    int ano;

} Data;

Data *diaSeguinte(Data *d)
{
    Data *novaData = (Data *)malloc(sizeof(Data));

    novaData->dia = d->dia;
    novaData->mes = d->mes;
    novaData->ano = d->ano;

    novaData->dia++;

    if (novaData->dia > 28 && novaData->mes == 2)
    {
        novaData->dia = 1;
        novaData->mes++;
    }
    else if (novaData->dia > 31)
    {
        novaData->dia = 1;
        if (novaData->mes == 12)
        {
            novaData->mes = 1;
            novaData->ano++;
        }
        else
        {
            novaData->mes++;
        }
    }

    return novaData;
}

int main(void)
{

    Data *dataDiaHoje = (Data *)malloc(sizeof(Data));

    printf("\nInforme uma data (dia, mes, ano): ");
    printf("\nDia: ");
    scanf("%d", &dataDiaHoje->dia);
    printf("Mes: ");
    scanf("%d", &dataDiaHoje->mes);
    printf("Ano: ");
    scanf("%d", &dataDiaHoje->ano);

    Data *dataDiaMaisUm = diaSeguinte(dataDiaHoje);

    printf("\n");
    printf("Nova data: ");
    printf("\nDia: %d", dataDiaMaisUm->dia);
    printf("\nMes: %d", dataDiaMaisUm->mes);
    printf("\nAno: %d", dataDiaMaisUm->ano);

    free(dataDiaHoje);
    free(dataDiaMaisUm);
}