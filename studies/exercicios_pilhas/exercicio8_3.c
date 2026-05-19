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
}

int pop(Node **top) {
    if (*top == NULL) {
        return -1;
    }

    Node *aux = *top;
    int v = aux->data;
    *top = (*top)->next;
    free(aux);
    return v;
}

int vazia(Node *top) {
    return top == NULL;
}

int pilhaContem(Node **s, int x) {
    Node *aux = NULL;
    int encontrado = 0;

    while (!vazia(*s)) {
        int v = pop(s);
        if (v == x) {
            encontrado = 1;
        }
        push(&aux, v);
    }

    while (!vazia(aux)) {
        push(s, pop(&aux));
    }

    return encontrado;
}

void pilhaImprimir(Node *top) {
    Node *aux = top;
    printf("Pilha (topo -> base): ");
    while (aux != NULL) {
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

void liberarPilha(Node **top) {
    while (!vazia(*top)) {
        pop(top);
    }
}

int main() {
    Node *stack = NULL;

    push(&stack, 5);
    push(&stack, 12);
    push(&stack, 7);
    push(&stack, 25);
    push(&stack, 9);

    pilhaImprimir(stack);

    int x = 7;
    printf("A pilha contem %d? %d\n", x, pilhaContem(&stack, x));
    pilhaImprimir(stack);

    x = 100;
    printf("A pilha contem %d? %d\n", x, pilhaContem(&stack, x));
    pilhaImprimir(stack);

    liberarPilha(&stack);
    return 0;
}
