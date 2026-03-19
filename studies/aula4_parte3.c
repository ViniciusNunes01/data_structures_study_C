#include <stdio.h>
#include <stdlib.h>

// 1. Crie aqui a função 'dobrarInteiro' (recebe void* e dobra o valor)
void dobrarInteiro(void *ptr)
{
    // SEU CÓDIGO AQUI: Faça o cast para int* e multiplique o conteúdo por 2
    int *i = (int *)ptr;
    *i = 2 * (*i);
}

// 2. Função Genérica: não sabe o que está processando
void transformar(void *dado, void (*algoritmo)(void *))
{
    // SEU CÓDIGO AQUI: Chame a função 'algoritmo' passando o 'dado'
    if (dado != NULL && algoritmo != NULL)
    {
        algoritmo(dado);
    }
}

int main()
{
    int valor = 50;

    printf("Valor original: %d\n", valor);

    // 3. Chamada da função genérica
    transformar(&valor, dobrarInteiro);

    printf("Valor transformado: %d\n", valor); // Deve imprimir 100

    return 0;
}