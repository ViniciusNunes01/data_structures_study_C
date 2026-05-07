/* Pilhas
push() -> empilhar
pop() -> desempilhar (remove e retorna o elemento)
peek() -> espiar (retorna quem é o topo)
isEmpty() -> verifica se a pilha está vazia */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void push(Node **top, int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        return;
    }

    newNode->data = v;
    newNode->next = *top;
    *top = newNode;
    printf("\nO valor %d foi inserido", (*top)->data);
}

int pop(Node **top)
{
    if (*top == NULL)
    {
        printf("A lista está vazia\n");
        return -1;
    }

    Node *aux = *top;
    int v = aux->data;

    *top = (*top)->next;
    free(aux);

    return v;
}

int peek(Node *top)
{
    if (top == NULL)
    {
        return -1;
    }
    return top->data;
}

/*
    1. Escreva um programa que leia N números,
    empilhe todos eles e depois desempilhe imprimindo cada valor (em forma de função)
*/

int main()
{
    Node *stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    printf("\nValor removido: %d", pop(&stack));
    printf("\nTopo atual: %d", peek(stack));

    return 0;
}