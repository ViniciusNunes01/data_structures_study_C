#include <stdio.h>
#include "geometry.h"

int main()
{
    Circle myCircle = createCircle(0, 0, 5); // Circulo no centro (0,0) com raio 5

    Point p1 = createPoint(3, 4); // Distância até (0,0) é 5 (Pertencente)
    Point p2 = createPoint(1, 1); // Distância é ~1.41 (Interno)
    Point p3 = createPoint(6, 0); // Distância é 6 (Externo)

    int status = checkPointCirclePosition(p1, myCircle);

    printf("\nTestando o Ponto P1 (3, 4):\n");
    if (status == -1)
        printf("Ponto interno a circunferencia.\n");
    else if (status == 0)
        printf("Ponto pertencente a circunferencia.\n");
    else if (status == 1)
        printf("Ponto externo a circunferencia.\n");

    return 0;
}