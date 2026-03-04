#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    float x;
    float y;
} Ponto2D;

float distancia(Ponto2D *ponto1, Ponto2D *ponto2)
{

    // pitagoras -> raiz quadrada de x2-x1 ao quadrado + y2-y1 ao quadrado

    float distanciaX = ponto2->x - ponto1->x;
    float distanciaY = ponto2->y - ponto1->y;

    return sqrt((distanciaX * distanciaX) + (distanciaY * distanciaY));
}

int main(void)
{

    Ponto2D *ponto1 = malloc(sizeof(Ponto2D));
    Ponto2D *ponto2 = malloc(sizeof(Ponto2D));

    printf("\nVamos calcular a diferenca entre dois pontos no plano cartesiano!");
    printf("\n\nPonto 1: ");
    printf("\nX = ");
    scanf("%f", &(ponto1->x));
    printf("Y = ");
    scanf("%f", &(ponto1->y));
    printf("\nPonto 2: ");
    printf("\nX = ");
    scanf("%f", &(ponto2->x));
    printf("Y = ");
    scanf("%f", &(ponto2->y));

    printf("\n\nA distancia entre os dois pontos eh de: %.3f", distancia(ponto1, ponto2));

    free(ponto1);
    free(ponto2);
}