// Simule uma fila de impressão de documentos. Leia `N` IDs de documentos e enfileire-os.
// Depois, desenfileire todos imprimindo a frase: "Printing document [ID]".

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

void initQueue(Queue *q){
	q->head = NULL;
	q->tail = NULL;
}

void enqueue(Queue *q, int v){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = v;
	newNode->next = NULL;

	if(q->tail == NULL){
		q->head = newNode;
		q->tail = newNode;
	} else {
		q->tail->next = newNode;
		q->tail = newNode;
	}
	printf("Enqueued: %d\n", q->tail->data);
}

int dequeue(Queue *q){
	if(q->head == NULL){
		printf("Fila vazia\n");
		return -1;
	}
	Node *aux = q->head;
	int v = aux->data;

	q->head = q->head->next;

	if(q->head == NULL){
		q->tail = NULL;
	}

	free(aux);
	return v;
}

// printQueue: imprime o estado atual da fila
void printQueue(Queue *q){
	Node *aux = q->head;
	printf("Queue state: ");
	while(aux != NULL){
		printf("%d <- ", aux->data);
		aux = aux->next;
	}
	printf("NULL\n");
}

int main(void){
	Queue q;
	initQueue(&q);

	int N;
	if(scanf("%d", &N) != 1) return 0;

	for(int i = 0; i < N; i++){
		int id;
		if(scanf("%d", &id) != 1) break;
		enqueue(&q, id);
	}

	while(q.head != NULL){
		int id = dequeue(&q);
		printf("Printing document [%d]\n", id);
	}

	return 0;
}
