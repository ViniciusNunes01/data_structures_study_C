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

int isEmpty(Queue *q){
	return q->head == NULL;
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
}

int dequeue(Queue *q){
	if(isEmpty(q)){
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

Queue filaIntercalar(Queue a, Queue b){
	Queue resultado;
	initQueue(&resultado);

	Node *auxA = a.head;
	Node *auxB = b.head;

	while(auxA != NULL || auxB != NULL){
		if(auxA != NULL){
			enqueue(&resultado, auxA->data);
			auxA = auxA->next;
		}

		if(auxB != NULL){
			enqueue(&resultado, auxB->data);
			auxB = auxB->next;
		}
	}

	return resultado;
}

void printQueue(Queue *q){
	Node *aux = q->head;
	printf("Fila: ");
	while(aux != NULL){
		printf("%d <- ", aux->data);
		aux = aux->next;
	}
	printf("NULL\n");
}

void freeQueue(Queue *q){
	while(!isEmpty(q)){
		dequeue(q);
	}
}

int main(){
	Queue a;
	Queue b;
	Queue intercalada;

	initQueue(&a);
	initQueue(&b);

	enqueue(&a, 1);
	enqueue(&a, 3);
	enqueue(&a, 5);
	enqueue(&a, 7);

	enqueue(&b, 2);
	enqueue(&b, 4);
	enqueue(&b, 6);

	printf("Fila A: ");
	printQueue(&a);
	printf("Fila B: ");
	printQueue(&b);

	intercalada = filaIntercalar(a, b);

	printf("Fila intercalada: ");
	printQueue(&intercalada);

	freeQueue(&a);
	freeQueue(&b);
	freeQueue(&intercalada);

	return 0;
}