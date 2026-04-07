// Listas Simplesmente Encadeadas

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int valor;
    struct Node *proximo;
} Node;

void imprimir(Node *topoDaLista)
{
    Node *aux = topoDaLista;

    while (aux != NULL)
    {
        printf("%d -> ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}

void inserirInicio(Node **topoDaLista, int v)
{
    Node *novo = (Node *)malloc(sizeof(Node));

    if (novo == NULL)
    {
        return;
    }

    novo->valor = v;
    novo->proximo = *topoDaLista;
    *topoDaLista = novo;
}

void inserirFim(Node **topoDaLista, int v)
{
    Node *novo = (Node *)malloc(sizeof(Node));

    if (novo == NULL)
    {
        return;
    }

    novo->valor = v;
    novo->proximo = NULL;

    if (*topoDaLista == NULL)
    {
        *topoDaLista = novo;
    }
    else
    {
        Node *aux = *topoDaLista;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
}

int main()
{

    Node *lista = NULL;

    Node *novo = (Node *)malloc(sizeof(Node));
    novo->valor = 3;
    novo->proximo = NULL;

    lista = novo;

    printf("Valor do Node: %d\n", novo->valor);
    printf("Valor do Endereco Prox: %p\n", novo->proximo);

    inserirInicio(&lista, 5);
    inserirInicio(&lista, 2);
    inserirInicio(&lista, 9);

    inserirFim(&lista, 11);

    imprimir(lista);

    return 0;
}