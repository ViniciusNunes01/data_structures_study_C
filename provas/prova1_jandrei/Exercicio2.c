// Crie um programa que defina uma estrutura ContaBancaria com os campos id (int), titular (string de 50) e saldo (float).
// Implemente uma função chamada depositar que receba o endereço de uma conta e um valor, atualizando o saldo.
// No main, inicialize uma conta com o seu nome, com valor de saldo de 1000, depois realize um depósito de 1500.50 e imprima o saldo final.
// Confira o caso de teste para verificar a saída esperada.

#include <stdio.h>

typedef struct
{
    int id;
    char titular[50];
    float saldo;
} ContaBancaria;

void depositar(ContaBancaria *conta, float deposito)
{
    conta->saldo += deposito;
}

int main()
{

    ContaBancaria pessoa = {
        1,
        "Fulano de Tal",
        1000.00};

    ContaBancaria *fulano = &pessoa;

    depositar(fulano, 1500.50);

    printf("Saldo Final: %.2f", fulano->saldo);

    return 0;
}