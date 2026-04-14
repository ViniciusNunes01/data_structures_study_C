// Escreva uma funcao que receba o topo da lista e retorne o maior valor armazenado

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;

} Node;

void insertNode(Node **topo, int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = v;
    newNode->next = *topo;
    *topo = newNode;
}

int maiorValor(Node *topo)
{
    if (topo == NULL)
    {
        return 0;
    }

    Node *aux = topo;
    int maior = aux->data;
    while (aux != NULL)
    {
        if (maior < aux->data)
        {
            maior = aux->data;
        }
        aux = aux->next;
    }
    return maior;
}

int main()
{
    Node *list = NULL;
    insertNode(&list, 10);
    insertNode(&list, 72);
    insertNode(&list, 23);
    insertNode(&list, 50);
    insertNode(&list, 500);

    printf("O maior valor eh: %d\n", maiorValor(list));

    return 0;
}