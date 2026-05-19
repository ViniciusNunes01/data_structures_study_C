#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CharNode {
    char data;
    struct CharNode *next;
} CharNode;

void push(CharNode **top, char c) {
    CharNode *newNode = (CharNode *)malloc(sizeof(CharNode));
    if (newNode == NULL) return;

    newNode->data = c;
    newNode->next = *top;
    *top = newNode;
}

char pop(CharNode **top) {
    if (*top == NULL) return '\0';

    CharNode *aux = *top;
    char c = aux->data;
    *top = (*top)->next;
    free(aux);
    return c;
}

int ehPalindromo(const char *palavra) {
    int n = (int)strlen(palavra);
    CharNode *stack = NULL;

    for (int i = 0; i < n / 2; i++) {
        push(&stack, palavra[i]);
    }

    int inicioSegundaMetade = n / 2;
    if (n % 2 != 0) {
        inicioSegundaMetade = (n / 2) + 1;
    }

    for (int i = inicioSegundaMetade; i < n; i++) {
        char c = pop(&stack);
        if (c != palavra[i]) {
            while (stack != NULL) pop(&stack);
            return 0;
        }
    }

    return 1;
}

int main() {
    char palavra[201];

    printf("Digite uma palavra: ");
    scanf("%200s", palavra);

    if (ehPalindromo(palavra)) {
        printf("\"%s\" e palindromo\n", palavra);
    } else {
        printf("\"%s\" nao e palindromo\n", palavra);
    }

    return 0;
}
