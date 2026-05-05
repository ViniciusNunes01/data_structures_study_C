// Dados duas SCLL, L1 e L2, escreva uma função que as concatene em uma única lista

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

Node *getTail(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *aux = head;
    while (aux->next != head)
    {
        aux = aux->next;
    }

    return aux;
}

void concatenateLists(Node **L1, Node *L2)
{
    if (*L1 == NULL)
    {
        *L1 = L2;
        return;
    }

    if (L2 == NULL)
    {
        return;
    }

    Node *tail1 = getTail(*L1);
    Node *tail2 = getTail(L2);

    tail1->next = L2;
    tail2->next = *L1;
}

int main()
{
    Node *list1 = NULL;
    Node *list2 = NULL;

    printf("Construindo lista 1:\n");
    insertHead(&list1, 10);
    insertHead(&list1, 20);
    insertHead(&list1, 30);
    printList(list1);

    printf("\nConstruindo lista 2:\n");
    insertHead(&list2, 40);
    insertHead(&list2, 50);
    insertHead(&list2, 60);
    printList(list2);

    printf("\nConcatenando listas:\n");
    concatenateLists(&list1, list2);
    printList(list1);

    return 0;
}