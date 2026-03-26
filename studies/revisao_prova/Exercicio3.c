#include <stdio.h>

int somar(int x, int y)
{
    return x + y;
}

int multiplicar(int x, int y)
{
    return x * y;
}

int executar(int x, int y, int (*Operacao)(int, int))
{
    return Operacao(x, y);
}

int main()
{

    printf("Soma: %d", executar(10, 5, somar));
    printf("\n");
    printf("Mult: %d", executar(10, 5, multiplicar));

    return 0;
}