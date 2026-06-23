#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "upa.h"

// Funcao auxiliar para instanciar o nó do paciente.
Paciente *criarPaciente(int id, const char *nome, int idade, Prioridade prio, const char *hora)
{
    Paciente *novo = (Paciente *)malloc(sizeof(Paciente));
    if (novo == NULL)
    {
        printf("Erro crítico: falha na alocacao de memoria!\n");
        exit(1);
    }

    novo->id = id;
    strcpy(novo->nome, nome);
    novo->idade = idade;
    novo->classificacao = prio;
    strcpy(novo->horaChegada, hora);
    novo->next = NULL;

    return novo;
}

// Inicializa o vetor de 5 filas
void inicializarFilas(FilaUPA filas[])
{
    for (int i = 0; i < 5; i++)
    {
        filas[i].head = NULL;
        filas[i].tail = NULL;
    }
}

// Insere um novo paciente sempre no final da sua fila
// Complexidade de Tempo: O(1)
void cadastrarPaciente(FilaUPA filas[], int id, const char *nome, int idade, Prioridade prio, const char *hora)
{
    Paciente *novo = criarPaciente(id, nome, idade, prio, hora);

    FilaUPA *filaAtual = &filas[prio];

    if (filaAtual->head == NULL)
    {
        filaAtual->head = novo;
        filaAtual->tail = novo;
    }
    else
    {
        filaAtual->tail->next = novo;
        filaAtual->tail = novo;
    }
}

// Chama o proximo paciente verificando a ordem de prioridade (0 a 4).
// Complexidade de Tempo: O(1) - limite maximo de 5 iteracoes
Paciente *chamarPaciente(FilaUPA filas[])
{
    for (int i = 0; i < 5; i++)
    {
        if (filas[i].head != NULL)
        {
            Paciente *chamado = filas[i].head;

            filas[i].head = chamado->next;

            if (filas[i].head == NULL)
            {
                filas[i].tail = NULL;
            }

            chamado->next = NULL;
            return chamado;
        }
    }

    return NULL;
}

// Percorre as filas em busca do paciente pelo ID.
// Complexidade de Tempo: O(n) - no pior caso, percorre todos os pacientes.
Paciente *buscarPaciente(FilaUPA filas[], int id)
{
    for (int i = 0; i < 5; i++)
    {
        Paciente *atual = filas[i].head;
        while (atual != NULL)
        {
            if (atual->id == id)
            {
                return atual;
            }
            atual = atual->next;
        }
    }
    return NULL;
}