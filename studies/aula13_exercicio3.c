// Escreva uma função que procure um valor target na lista circular simples. Se encontrar, retorne o índice (0 para head). Se não encontrar, retorne -1

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

int searchValue(Node *head, int target)
{
    if (head == NULL)
    {
        return -1;
    }

    Node *aux = head;
    int index = 0;

    do
    {
        if (aux->data == target)
        {
            return index;
        }
        aux = aux->next;
        index++;
    } while (aux != head);

    return -1;
}

int main()
{
    Node *list = NULL;

    insertHead(&list, 30);
    insertHead(&list, 40);
    insertHead(&list, 50);
    insertHead(&list, 60);

    printList(list);

    int searchTarget = 40;
    int index = searchValue(list, searchTarget);
    
    if (index != -1)
    {
        printf("Valor %d encontrado no indice: %d\n", searchTarget, index);
    }
    else
    {
        printf("Valor %d nao encontrado\n", searchTarget);
    }

    searchTarget = 100;
    index = searchValue(list, searchTarget);
    
    if (index != -1)
    {
        printf("Valor %d encontrado no indice: %d\n", searchTarget, index);
    }
    else
    {
        printf("Valor %d nao encontrado\n", searchTarget);
    }

    return 0;
}