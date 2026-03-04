/*
================================================================================
EXERCÍCIO 1.2 - Operadores & e *
================================================================================

OBJETIVO:
- Crie uma função que receba um inteiro como parâmetro
- Imprima o endereço de memória da variável
- Imprima o valor da variável
- Use apenas ponteiros para acessar essas informações

SAÍDA ESPERADA (exemplo):
Endereço: 0x7ffc1234abcd
Valor: 100

================================================================================
*/

#include <stdio.h>

// Função para completar
void imprimir_info(int valor)
{
    int *pValor = &valor;
    printf("\nEndereco: %p", (void *)pValor);
    printf("\nValor: %d", *pValor);
}

int main()
{
    int numero = 100;
    imprimir_info(numero);

    return 0;
}
