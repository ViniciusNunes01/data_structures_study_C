#include <stdio.h>
#include <stdlib.h>

int main()
{

    // float mat[50][50];
    // int i, j, cont = 0;

    // for (i = 0; i < 50; i++)
    // {
    //     for (j = 0; j < 50; j++)
    //     {
    //         mat[i][j] = cont++;
    //     }
    // }

    // float mat[50][50], *f, cont;
    // f = mat;

    // for (cont = 0; cont < 2500; cont++)
    // {
    //     *f = cont;
    //     f++;
    // }

    int *p;

    p = (int *)malloc(sizeof(int));

    if (p != NULL)
    {
        *p = 42;
        printf("Valor alocado: %d\n", *p);
        free(p);
    }

    return 0;
}