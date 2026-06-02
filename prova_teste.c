/* ============================================================================
 *  UNIVERSIDADE TECNOLOGICA FEDERAL DO PARANA - UTFPR
 *  AVALIACAO - FUNDAMENTOS DE ESTRUTURAS DE DADOS
 *
 *  Nome: ______________________________________   Data: ____/____/________
 *  Professor: Jandrei Sartori Spancerski
 *
 *  ORIENTACOES
 *  - Resolva os 4 exercicios diretamente neste arquivo.
 *  - Nos exercicios de CORRECAO, identifique o defeito e corrija o minimo
 *    necessario (nao reescreva a funcao inteira sem necessidade).
 *  - Nos exercicios de CRIACAO, implemente a funcao no local indicado.
 *  - As structs Stack e Queue, alem das funcoes initStack() e initQueue(),
 *    ja estao prontas e nao devem ser alteradas.
 *  - O programa deve compilar e executar produzindo as saidas esperadas.
 *
 *  ----------------------------------------------------------------------------
 *  EXERCICIO 1 (CORRECAO) - Lista Simplesmente Encadeada
 *  A funcao printList() deve percorrer a lista e imprimir TODOS os seus
 *  elementos, do primeiro ao ultimo. A implementacao atual contem um defeito.
 *  Identifique-o e corrija.
 *      Saida esperada para a lista 3 -> 7 -> 1 :  "Lista: 3 7 1"
 *
 *  EXERCICIO 2 (CORRECAO) - Pilha (politica LIFO)
 *  A funcao pop() deve remover o elemento do topo, devolver seu valor e
 *  liberar a memoria do no removido, mantendo a pilha consistente para as
 *  proximas operacoes. A implementacao atual contem um defeito relacionado ao
 *  uso de ponteiros / liberacao de memoria. Identifique-o e corrija.
 *
 *  EXERCICIO 3 (CRIACAO) - Lista Duplamente Encadeada
 *  Implemente a funcao insertSorted() que insere um novo valor mantendo a
 *  lista em ordem CRESCENTE. Trate corretamente: lista vazia, insercao no
 *  inicio, no fim e no meio, atualizando os ponteiros 'prev' e 'next'.
 *      Apos inserir 5, 2, 8, 1, 5  =>  "Dupla: 1 2 5 5 8"
 *
 *  EXERCICIO 4 (CRIACAO) - Fila (politica FIFO)
 *  A fila usa a struct Queue, com ponteiros 'head' (primeiro) e 'tail'
 *  (ultimo). Implemente a funcao enqueue() que insere um novo valor ao FINAL
 *  da fila. Trate o caso de fila vazia e mantenha 'head' e 'tail' corretos.
 *      Apos enfileirar 100, 200, 300  =>  "Fila: 100 200 300"
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* ===== Tipos =============================================================== */

typedef struct Node
{ /* lista simples, pilha e fila */
    int data;
    struct Node *next;
} Node;

typedef struct DNode
{ /* lista duplamente encadeada */
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

typedef struct Stack
{
    Node *top;
} Stack;

typedef struct Queue
{
    Node *head;
    Node *tail;
} Queue;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

DNode *createDNode(int value)
{
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void initStack(Stack *s)
{
    s->top = NULL;
}

void initQueue(Queue *q)
{
    q->head = NULL;
    q->tail = NULL;
}

void push(Stack *s, int value)
{
    Node *newNode = createNode(value);
    newNode->next = s->top;
    s->top = newNode;
}

void printDList(DNode *head)
{
    DNode *current = head;
    printf("Dupla: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void printQueue(Queue *q)
{
    Node *current = q->head;
    printf("Fila: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/* ===== EXERCICIO 1 (CORRECAO) ============================================= */

void printList(Node *list)
{
    Node *current = list;
    printf("Lista: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/* ===== EXERCICIO 2 (CORRECAO) ============================================= */

int pop(Stack *s)
{
    if (s->top == NULL)
    {
        printf("Pilha vazia!\n");
        return -1;
    }
    Node *removed = s->top;
    int value = removed->data;
    s->top = removed->next;
    free(removed);
    return value;
}

/* ===== EXERCICIO 3 (CRIACAO) ============================================== */

void insertSorted(DNode **head, int value)
{
    DNode *newNode = createDNode(value);
}

/* ===== EXERCICIO 4 (CRIACAO) ============================================== */

void enqueue(Queue *q, int value)
{
    /* IMPLEMENTE AQUI (Exercicio 4) */
}

int main(void)
{
    /* ---- Exercicio 1: lista simplesmente encadeada ---- */
    Node *list = createNode(3);
    list->next = createNode(7);
    list->next->next = createNode(1);
    printList(list); /* esperado: Lista: 3 7 1 */

    /* ---- Exercicio 2: pilha (LIFO) ---- */
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printf("Desempilhando: ");
    while (stack.top != NULL)
    {
        printf("%d ", pop(&stack)); /* esperado: 30 20 10 */
    }
    printf("\n");

    /* ---- Exercicio 3: lista duplamente encadeada ---- */
    DNode *dlist = NULL;
    insertSorted(&dlist, 5);
    insertSorted(&dlist, 2);
    insertSorted(&dlist, 8);
    insertSorted(&dlist, 1);
    insertSorted(&dlist, 5);
    printDList(dlist); /* esperado: Dupla: 1 2 5 5 8 */

    /* ---- Exercicio 4: fila (FIFO) ---- */
    Queue queue;
    initQueue(&queue);
    enqueue(&queue, 100);
    enqueue(&queue, 200);
    enqueue(&queue, 300);
    printQueue(&queue); /* esperado: Fila: 100 200 300 */

    /* ---- liberacao de memoria ---- */
    while (list != NULL)
    {
        Node *temp = list->next;
        free(list);
        list = temp;
    }
    while (dlist != NULL)
    {
        DNode *temp = dlist->next;
        free(dlist);
        dlist = temp;
    }
    Node *p = queue.head;
    while (p != NULL)
    {
        Node *temp = p->next;
        free(p);
        p = temp;
    }

    return 0;
}