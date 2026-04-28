// Listas Circulares em duplamente encadeadas

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

void printListFull(Node *head)
{

    if (head == NULL)
    {
        return;
    }

    Node *aux = head;
    printf("Double Circular List: ");

    do
    {
        printf("%d <-> ", aux->data);
        aux = aux->next;
    } while (aux != head);
    printf("Back to: %d", head->data);

    printf("\nReverse Double Circular List: ");
    aux = head->prev;

    do
    {
        printf("%d <-> ", aux->data);
        aux = aux->prev;
    } while (aux != head->prev);
    printf("Back to: %d", head->data);
}

void insertDoubleCircular(Node **head, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = value;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else
    {
        Node *tail = (*head)->prev;

        newNode->next = *head;
        newNode->prev = tail;

        tail->next = newNode;
        (*head)->prev = newNode;

        *head = newNode;
    }
}

int main()
{
    Node *list = NULL;

    insertDoubleCircular(&list, 10);
    insertDoubleCircular(&list, 20);
    insertDoubleCircular(&list, 30);
    insertDoubleCircular(&list, 40);
    insertDoubleCircular(&list, 50);
    printListFull(list);

    return 0;
}