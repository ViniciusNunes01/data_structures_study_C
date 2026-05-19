#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int topo;
    int capacidade;
} Pilha;

Pilha *pilhaCriar(int capacidadeInicial) {
    if (capacidadeInicial <= 0) capacidadeInicial = 4;

    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (p == NULL) return NULL;

    p->dados = (int *)malloc(sizeof(int) * capacidadeInicial);
    if (p->dados == NULL) {
        free(p);
        return NULL;
    }

    p->topo = -1;
    p->capacidade = capacidadeInicial;
    return p;
}

void pilhaDestruir(Pilha **p) {
    if (p == NULL || *p == NULL) return;
    free((*p)->dados);
    free(*p);
    *p = NULL;
}

int pilhaVazia(Pilha *p) {
    if (p == NULL) return 1;
    return p->topo == -1;
}

int pilhaTamanho(Pilha *p) {
    if (p == NULL) return 0;
    return p->topo + 1;
}

int pilhaPush(Pilha *p, int valor) {
    if (p == NULL) return 0;

    if (p->topo + 1 == p->capacidade) {
        int novaCapacidade = p->capacidade * 2;
        int *novoVetor = (int *)realloc(p->dados, sizeof(int) * novaCapacidade);
        if (novoVetor == NULL) return 0;
        p->dados = novoVetor;
        p->capacidade = novaCapacidade;
    }

    p->topo++;
    p->dados[p->topo] = valor;
    return 1;
}

int pilhaPop(Pilha *p, int *valorRemovido) {
    if (pilhaVazia(p)) return 0;

    if (valorRemovido != NULL) {
        *valorRemovido = p->dados[p->topo];
    }
    p->topo--;
    return 1;
}

int pilhaTop(Pilha *p, int *valorTopo) {
    if (pilhaVazia(p)) return 0;
    if (valorTopo != NULL) {
        *valorTopo = p->dados[p->topo];
    }
    return 1;
}

int main() {
    Pilha *p = pilhaCriar(2);
    if (p == NULL) {
        printf("Erro ao criar pilha\n");
        return 1;
    }

    pilhaPush(p, 10);
    pilhaPush(p, 20);
    pilhaPush(p, 30);
    pilhaPush(p, 40);

    int topo;
    if (pilhaTop(p, &topo)) {
        printf("Topo atual: %d\n", topo);
    }

    printf("Tamanho da pilha: %d\n", pilhaTamanho(p));

    int removido;
    while (pilhaPop(p, &removido)) {
        printf("Valor removido: %d\n", removido);
    }

    printf("Pilha vazia? %d\n", pilhaVazia(p));

    pilhaDestruir(&p);
    return 0;
}
