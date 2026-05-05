// Listas Genéricas

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    void *data;
    struct Node *next;
} Node;

void printInt(void *value)
{
    printf("%d -> ", *(int *)value);
}

void printFloat(void *value)
{
    printf("%.2f -> ", *(float *)value);
}

void printList(Node *head, void (*printfFunc)(void *))
{
    Node *aux = head;
    while (aux != NULL)
    {
        printfFunc(head->data);
        aux = aux->next;
    }
    printf("NULL\n");
}

void insertHead(Node **head, void *value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

int main()
{
    Node *intList = NULL;
    Node *floatList = NULL;

    int *i1 = malloc(sizeof(int));
    int *i2 = malloc(sizeof(int));
    float *d1 = malloc(sizeof(float));
    float *d2 = malloc(sizeof(float));

    *i1 = 10;
    *i2 = 20;
    *d1 = 20.5;
    *d2 = 20.7;

    insertHead(&intList, i1);
    insertHead(&intList, i2);
    insertHead(&floatList, d1);
    insertHead(&floatList, d2);

    printf("Lista de Inteiros: ");
    printList(intList, printInt);

    printf("Lista de Floats: ");
    printList(floatList, printFloat);

    return 0;
}