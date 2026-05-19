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
        printf("A pilha esta vazia\n");
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

int main() {
    Node *stack = NULL;
    int x;

    printf("Digite 10 numeros inteiros:\n");
    for (int i = 0; i < 10; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &x);
        push(&stack, x);
    }

    printf("\nDesempilhando (ordem inversa da leitura):\n");
    while (!vazia(stack)) {
        printf("%d\n", pop(&stack));
    }

    return 0;
}
