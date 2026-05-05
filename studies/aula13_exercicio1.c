// Implemente uma função que conte quantos nós existem em uma singly circular linked list

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
    printf("Back to: %d\n", head->data);
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

int countNodes(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    int count = 0;
    Node *aux = head;

    do
    {
        count++;
        aux = aux->next;
    } while (aux != head);

    return count;
}

int main()
{
    Node *list = NULL;

    insertHead(&list, 30);
    insertHead(&list, 40);
    insertHead(&list, 50);
    insertHead(&list, 60);

    printList(list);
    printf("Total de nos: %d\n", countNodes(list));

    return 0;
}