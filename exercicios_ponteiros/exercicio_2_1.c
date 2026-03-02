/*
================================================================================
EXERCÍCIO 2.1 - Passagem por Referência
================================================================================

OBJETIVO:
- Crie uma função que receba dois inteiros por referência (ponteiros)
- Troque os valores das duas variáveis
- A troca deve ser refletida na função chamadora

SAÍDA ESPERADA:
Antes: a = 5, b = 10
Depois: a = 10, b = 5

================================================================================
*/

#include <stdio.h>

// Crie aqui a função swap

int main() {
    int a = 5;
    int b = 10;
    
    printf("Antes: a = %d, b = %d\n", a, b);
    
    // Chame a função swap aqui
    
    printf("Depois: a = %d, b = %d\n", a, b);
    
    return 0;
}
