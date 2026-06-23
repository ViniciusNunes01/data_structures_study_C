#include <stdio.h>
#include <stdlib.h>
#include "upa.h"

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main(void)
{
    FilaUPA filas[5];
    inicializarFilas(filas);

    int opcao;

    do
    {
        printf("\n========================================\n");
        printf("   SISTEMA DE TRIAGEM UPA - MANCHESTER\n");
        printf("========================================\n");
        printf("1. Cadastrar novo paciente na fila\n");
        printf("2. Chamar proximo paciente (Atendimento)\n");
        printf("3. Buscar dados de um paciente por ID\n");
        printf("0. Encerrar Sistema\n");
        printf("========================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            int id, idade, prio_int;
            char nome[100], hora[6];

            printf("\n--- CADASTRO DE PACIENTE ---\n");
            printf("ID do Paciente: ");
            scanf("%d", &id);

            limparBuffer();
            printf("Nome completo: ");
            scanf("%99[^\n]", nome);

            printf("Idade: ");
            scanf("%d", &idade);

            printf("Classificacao (0=Vermelho, 1=Laranja, 2=Amarelo, 3=Verde, 4=Azul): ");
            scanf("%d", &prio_int);

            limparBuffer();
            printf("Hora de Chegada (HH:MM): ");
            scanf("%5s", hora);

            cadastrarPaciente(filas, id, nome, idade, (Prioridade)prio_int, hora);
            printf("-> Paciente %s cadastrado com sucesso na fila %d!\n", nome, prio_int);
        }
        else if (opcao == 2)
        {
            Paciente *p = chamarPaciente(filas);

            if (p != NULL)
            {
                printf("\n>>> CHAMADA PARA ATENDIMENTO <<<\n");
                printf("Paciente: %s\n", p->nome);
                printf("ID: %d | Idade: %d\n", p->id, p->idade);
                printf("Prioridade: %d | Chegada: %s\n", p->classificacao, p->horaChegada);
                printf("--------------------------------\n");

                free(p);
            }
            else
            {
                printf("\n-> Nao ha pacientes na fila de espera no momento.\n");
            }
        }
        else if (opcao == 3)
        {
            int idBusca;
            printf("\nDigite o ID do paciente que deseja buscar: ");
            scanf("%d", &idBusca);

            Paciente *encontrado = buscarPaciente(filas, idBusca);

            if (encontrado != NULL)
            {
                printf("\n--- PACIENTE ENCONTRADO ---\n");
                printf("Nome: %s\n", encontrado->nome);
                printf("Idade: %d\n", encontrado->idade);
                printf("Classificacao atual: %d\n", encontrado->classificacao);
                printf("Hora de Chegada: %s\n", encontrado->horaChegada);
            }
            else
            {
                printf("\n-> Paciente com ID %d nao consta nas filas de espera.\n", idBusca);
            }
        }

    } while (opcao != 0);

    printf("\nEncerrando o sistema e liberando memoria...\n");
    for (int i = 0; i < 5; i++)
    {
        Paciente *atual = filas[i].head;
        while (atual != NULL)
        {
            Paciente *temp = atual->next;
            free(atual);
            atual = temp;
        }
    }
    printf("Memoria liberada com sucesso. Ate logo!\n");

    return 0;
}