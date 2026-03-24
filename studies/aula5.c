#include <stdio.h>
#include <stdlib.h>

// F A T O R I A L
// long fatorial(int n)
// {
//     if (n == 0 || n == 1)
//     {
//         return 1;
//     }

//     return n * fatorial(n - 1);
// }

// F I B O N A C C I
int fibonacci(int n)
{

    if (n == 0)
    {
        return 0;
    }

    if (n == 1 || n == 2)
    {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{

    int num = 6;

    // printf("Fatorial de %d: %ld", num, fatorial(num));
    printf("Fibonaccit de %d: %d", num, fibonacci(num));

    return 0;
}