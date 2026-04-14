// Crie uma função que insira um
// novo nó na lista mantendo-a sempre em ordem crescente. Você não
// deve usar algoritmos de ordenação (como Bubble Sort), mas sim
// encontrar o local exato para "encaixar" o novo elo.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void insertNode(Node **topo, int v)
{
    Node *beforeNode = (Node *)malloc(sizeof(Node));
    Node *newNode = (Node *)malloc(sizeof(Node));

    

    newNode->data = v;
    newNode->next = *topo;
    *topo = newNode;
}

float meanList(Node *topo)
{
    if (topo == NULL)
    {
        return 0;
    }

    int sum = 0, count = 0;
    Node *aux = topo;

    while (aux != NULL)
    {
        sum += aux->data;
        count++;
        aux = aux->next;
    }
    return (float)(sum / count);
}

int main()
{

    Node *list = NULL;
    insertNode(&list, 10);
    insertNode(&list, 20);
    insertNode(&list, 30);

    return 0;
}