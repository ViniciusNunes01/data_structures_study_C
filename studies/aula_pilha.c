#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void push(Node **top, int v){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL) return;
    
    newNode->data = v;
    newNode->next = *top;
    *top = newNode;
    printf("O valor %d foi inserido\n", (*top)->data);
}

int pop(Node **top){
    if(*top == NULL) {
        printf("A lista esta vazia\n");
        return -1;
    }
    Node *aux = *top;
    int v = aux->data;
    *top = (*top)->next;
    free(aux);
    return v;
}

int peek(Node *top){
    if(top == NULL) return -1;
    return top->data;
}

/* 1. Escreva um programa que leia N números, empilhe todos eles e
      depois desempilhe imprimindo cada valor (em forma de função).
*/

/* 2. Use uma pilha para verificar se uma expressão matemática está
      com os parênteses balanceados.
*/

/* 3. Implemente um conversor de Decimal para Binário usando pilhas.
*/

/* 4. Receba uma frase do usuário e use uma pilha de caracteres
      para imprimir a frease de trás para frente.
*/


int main(){
    Node *stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    printf("Valor removido: %d\n", pop(&stack));
    printf("Topo atual: %d\n", peek(stack));
    printf("Valor removido: %d\n", pop(&stack));
    printf("Topo atual: %d\n", peek(stack));
    printf("Valor removido: %d\n", pop(&stack));
    printf("Topo atual: %d\n", peek(stack));
    printf("Valor removido: %d\n", pop(&stack));
    printf("Topo atual: %d\n", peek(stack));
    printf("Valor removido: %d\n", pop(&stack));
    printf("Topo atual: %d\n", peek(stack));

    return 0;
}