#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void push(Node **top, int v) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) return;

    newNode->data = v;
    newNode->next = *top;
    *top = newNode;
    printf("O valor %d foi inserido\n", (*top)->data);
}

int pop(Node **top) {
    if (*top == NULL) {
        printf("A pilha esta vazia\n");
        return -1;
    }

    Node *aux = *top;
    int v = aux->data;
    *top = (*top)->next;
    free(aux);
    return v;
}

void pilhaImprimir(Node *top) {
    if (top == NULL) {
        printf("A pilha esta vazia\n");
        return;
    }

    printf("Pilha (topo -> base): ");
    Node *aux = top;
    while (aux != NULL) {
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

void liberarPilha(Node **top) {
    while (*top != NULL) {
        pop(top);
    }
}

int main() {
    Node *stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    pilhaImprimir(stack);

    liberarPilha(&stack);
    return 0;
}
