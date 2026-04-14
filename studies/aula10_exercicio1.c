// Implemente uma funcao que calcule a media aritmetica de todos os valores
// inteiros em uma lista. Se a lista estiver vazia, o retorno deve ser 0.

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

    printf("A media eh: %.2f\n", meanList(list));

    return 0;
}