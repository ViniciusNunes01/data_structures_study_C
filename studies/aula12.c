// Listas Circulares em simplesmente encadeadas

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void printList(Node *head)
{

    if (head == NULL)
    {
        return;
    }

    Node *aux = head;
    printf("Circular List: ");

    do
    {
        printf("%d -> ", aux->data);
        aux = aux->next;
    } while (aux != head);
    printf("Back to: %d", head->data);
}

void insertHead(Node **head, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = value;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = newNode;
    }
    else
    {
        Node *aux = *head;
        while (aux->next != *head)
        {
            aux = aux->next;
        }
        newNode->next = *head;
        aux->next = newNode;
        *head = newNode;
    }
}

int main()
{
    Node *list = NULL;

    // Inserção Manual
    // Node *newNode = (Node *)malloc(sizeof(Node));
    // newNode->data = 10;

    // Node *newNode2 = (Node *)malloc(sizeof(Node));
    // newNode2->data = 20;

    // newNode->next = newNode2;
    // newNode2->next = newNode;

    // list = newNode;

    insertHead(&list, 30);
    insertHead(&list, 40);
    insertHead(&list, 50);

    printList(list);

    return 0;
}