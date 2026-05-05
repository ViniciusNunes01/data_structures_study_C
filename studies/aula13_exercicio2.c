// Em uma doubly circular linked list, crie uma função que percorra a lista no sentido anti-horário (prev) e retorne a soma de todos os elementos

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
    printf("Back to: %d\n", head->data);

    printf("Reverse Double Circular List: ");
    aux = head->prev;

    do
    {
        printf("%d <-> ", aux->data);
        aux = aux->prev;
    } while (aux != head->prev);
    printf("Back to: %d\n", head->data);
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

int sumReverse(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    int sum = 0;
    Node *aux = head->prev;

    do
    {
        sum += aux->data;
        aux = aux->prev;
    } while (aux != head->prev);

    return sum;
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
    printf("Soma (sentido anti-horario): %d\n", sumReverse(list));

    return 0;
}