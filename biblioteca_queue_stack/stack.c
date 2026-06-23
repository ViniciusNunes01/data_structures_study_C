#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

static StackNode *createStackNode(int value)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode == NULL)
    {
        printf("Erro: memoria insuficiente.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void initStack(Stack *stack)
{
    stack->top = NULL;
}

void push(Stack *stack, int value)
{
    StackNode *newNode = createStackNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack *stack)
{
    if (isStackEmpty(stack))
    {
        printf("Pilha vazia!\n");
        return -1;
    }

    StackNode *removed = stack->top;
    int value = removed->data;
    stack->top = removed->next;
    free(removed);
    return value;
}

int isStackEmpty(const Stack *stack)
{
    return stack->top == NULL;
}