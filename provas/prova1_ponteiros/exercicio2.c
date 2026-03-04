#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    float x;
    float y;
} Ponto2D;

float distancia(Ponto2D *pontoA, Ponto2D *pontoB)
{

    float diferencaX = pontoB->x - pontoA->x;
    float diferencaY = pontoB->y - pontoA->y;

    return sqrt((diferencaX * diferencaX) + (diferencaY * diferencaY));
}

int main(void)
{

    Ponto2D *ponto1 = (Ponto2D *)malloc(sizeof(Ponto2D));
    Ponto2D *ponto2 = (Ponto2D *)malloc(sizeof(Ponto2D));

    printf("\n");
    printf("Vamos calcular a distancia entre dois pontos!");
    printf("\n");
    printf("Informe as coordenadas do primeiro ponto: ");
    printf("\n");
    printf("X: ");
    scanf("%f", &ponto1->x);
    printf("Y: ");
    scanf("%f", &ponto1->y);
    printf("\n");
    printf("Informe as coordenadas do segundo ponto: ");
    printf("\n");
    printf("X: ");
    scanf("%f", &ponto2->x);
    printf("Y: ");
    scanf("%f", &ponto2->y);
    printf("\n");
    printf("A distancia entre os dois pontos eh de: %.2f", distancia(ponto1, ponto2));

    free(ponto1);
    free(ponto2);
}