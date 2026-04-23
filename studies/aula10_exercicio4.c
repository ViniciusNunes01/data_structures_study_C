// Desenvolva uma função que
// remova especificamente o último nó da lista. Lembre-se de tratar o
// caso de listas com apenas um elemento.

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

    newNode->data = v;
    newNode->next = *head;

    *head = newNode;
}

void removeLastNode(Node **head)
{
    if (*head == NULL)
    {
        return;
    }

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    Node *prev = NULL;
    Node *curr = *head;

    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    free(curr);
}

int main()
{

    Node *list = NULL;

    insertNode(&list, 10);
    insertNode(&list, 23);
    insertNode(&list, 45);
    insertNode(&list, 13);

    removeLastNode(&list);

    return 0;
}