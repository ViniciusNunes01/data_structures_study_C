// Listas Simplesmente Encadeadas

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int valor;
    struct Node *proximo;
} Node;

// AULA 9 \/
// ____________________________________________________________________

void remover(Node **topo, int v)
{
    Node *aux = *topo;
    Node *anterior = NULL;

    while (aux->proximo != NULL && aux->valor != v)
    {
        anterior = aux;
        aux = aux->proximo;
    }

    if (aux->proximo == NULL)
    {
        printf("O valor %d nao esta na lista!\n", v);
        return;
    }

    if (anterior == NULL)
    {
        *topo = aux->proximo;
    }
    else
    {
        anterior->proximo = aux->proximo;
    }

    free(aux);

    printf("Valor %d removido com sucesso!\n", v);
}

Node *busca(Node *topo, int v)
{

    Node *aux = topo;

    while (aux != NULL)
    {
        if (v == aux->valor)
        {
            return aux;
        }
        aux = aux->proximo;
    }

    free(aux);

    return NULL;
}

// ____________________________________________________________________

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

    int procurar = 120;
    Node *resultado = busca(lista, procurar);
    if (resultado != NULL)
    {
        printf("O valor %d foi esta em %p\n", resultado->valor, (void *)resultado);
    }
    else
    {
        printf("O valor %d nao foi encontrado\n", procurar);
    }

    remover(&lista, procurar);
    imprimir(lista);

    return 0;
}