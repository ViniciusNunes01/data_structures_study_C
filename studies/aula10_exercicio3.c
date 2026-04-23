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

void insertNode(Node **head, int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        return;
    }

    newNode->data = v;

    if (*head == NULL || v <= (*head)->data)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *current = *head;
    while (current->next != NULL && current->next->data < v)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void printList(Node *head)
{
    Node *current = head;

    while (current != NULL)
    {
        printf("%d", current->data);
        if (current->next != NULL)
        {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

int main()
{

    Node *list = NULL;
    insertNode(&list, 20);
    insertNode(&list, 10);
    insertNode(&list, 30);
    insertNode(&list, 22);
    insertNode(&list, 25);
    insertNode(&list, 2);

    printList(list);

    return 0;
}