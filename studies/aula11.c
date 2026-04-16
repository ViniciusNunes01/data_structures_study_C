// LISTAS DUPLAMENTE ENCADEADAS

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;

} Node;

//________________________________________________________________________________________
// INSERÇÃO MANUAL
// int main()
// {
//     Node *list = NULL;

//     Node *newNode = (Node *)malloc(sizeof(Node));
//     newNode->data = 10;
//     newNode->next = NULL;
//     newNode->prev = NULL;

//     Node *newNode2 = (Node *)malloc(sizeof(Node));
//     newNode2->data = 20;
//     newNode2->next = NULL;
//     newNode2->prev = newNode;

//     newNode->next = newNode2;

//     list = newNode;

//     printf("Lista criada! Ida: %d -> %d\n", list->data, list->next->data);
//     printf("Volta: %d -> %d\n", newNode2->data, newNode2->prev->data);

//     return 0;
// }
//________________________________________________________________________________________

void insertHead(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        return;
    }

    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }

    *head = newNode;
}

void removeNode(Node **head, int target)
{
    Node *aux = *head;

    while (aux != NULL && aux->data != target)
    {
        aux = aux->next;
    }

    if (aux == NULL)
    {
        return;
    }

    // PRIMEIRO NÓ
    if (aux->prev == NULL)
    {
        *head = aux->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
    }
    // NÓ DO MEIO DA LISTA
    else
    {
        aux->prev->next = aux->next;
        if (aux->next != NULL)
        {
            aux->next->prev = aux->prev;
        }
    }
    free(aux);
    printf("Valor %d removido!\n", target);
}

void printList(Node *head)
{

    printf("Ida: ");
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{

    Node *list = NULL;
    insertHead(&list, 5);
    insertHead(&list, 15);
    insertHead(&list, 25);

    printList(list);

    removeNode(&list, 5);
    printList(list);

    return 0;
}