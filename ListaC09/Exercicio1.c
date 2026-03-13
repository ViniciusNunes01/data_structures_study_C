// Escreva um programa que declare um inteiro, um real e um char, e ponteiros para in
// teiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de
// cada variavel usando os ponteiros. Imprima os valores das variaveis antes e apos a
// modificacao.

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int inteiro = 0, *pInteiro;
    float real = 0.0, *pReal;
    char letra = 'A', *pLetra;

    pInteiro = &inteiro;
    pReal = &real;
    pLetra = &letra;

    printf("\nAntes da modificacao: ");
    printf("\ninteiro: %d", inteiro);
    printf("\nreal: %.2f", real);
    printf("\nchar: %c", letra);
    printf("\n\n");

    *pInteiro = 10;
    *pReal = 42.24;
    *pLetra = 'V';

    printf("\nDepois da modificacao: ");
    printf("\ninteiro: %d", inteiro);
    printf("\nreal: %.2f", real);
    printf("\nchar: %c", letra);

    return 0;
}