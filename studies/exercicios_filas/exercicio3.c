// Dadas duas filas `F1` e `F2`, crie uma função que gere uma terceira fila `F3`
// intercalando os elementos.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

typedef struct Queue {
	Node *head;
	Node *tail;
} Queue;

void initQueue(Queue *q){ q->head = q->tail = NULL; }
void enqueue(Queue *q, int v){
	Node *n = (Node*)malloc(sizeof(Node));
	n->data = v; n->next = NULL;
	if(q->tail==NULL) q->head = q->tail = n; else { q->tail->next = n; q->tail = n; }
}
int dequeue(Queue *q){ if(q->head==NULL) return -1; Node *aux = q->head; int v = aux->data; q->head = q->head->next; if(q->head==NULL) q->tail=NULL; free(aux); return v; }

void printQueue(Queue *q){ Node *aux = q->head; printf("Queue state: "); while(aux){ printf("%d <- ", aux->data); aux = aux->next; } printf("NULL\n"); }

// intercala F1 e F2 em F3
void intercalate(Queue *f1, Queue *f2, Queue *f3){
	while(f1->head != NULL || f2->head != NULL){
		if(f1->head != NULL) enqueue(f3, dequeue(f1));
		if(f2->head != NULL) enqueue(f3, dequeue(f2));
	}
}

int main(void){
	Queue f1, f2, f3; initQueue(&f1); initQueue(&f2); initQueue(&f3);
	int n1, n2;
	if(scanf("%d", &n1) != 1) return 0;
	for(int i=0;i<n1;i++){ int v; if(scanf("%d", &v)!=1) break; enqueue(&f1, v); }
	if(scanf("%d", &n2) != 1) return 0;
	for(int i=0;i<n2;i++){ int v; if(scanf("%d", &v)!=1) break; enqueue(&f2, v); }

	printf("F1: "); printQueue(&f1);
	printf("F2: "); printQueue(&f2);

	intercalate(&f1, &f2, &f3);
	printf("F3 (intercalated): "); printQueue(&f3);
	return 0;
}

