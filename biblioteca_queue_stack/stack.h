#ifndef STACK_H
#define STACK_H

typedef struct StackNode
{
    int data;
    struct StackNode *next;
} StackNode;

typedef struct Stack
{
    StackNode *top;
} Stack;

void initStack(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
int isStackEmpty(const Stack *stack);

#endif