// Implemente uma função que receba uma Fila e use uma Pilha auxiliar para
// inverter a ordem dos elementos da Fila original.

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
	if(q->tail == NULL){ q->head = q->tail = newNode; }
	else { q->tail->next = newNode; q->tail = newNode; }
}

int dequeue(Queue *q){
	if(q->head == NULL) return -1;
	Node *aux = q->head;
	int v = aux->data;
	q->head = q->head->next;
	if(q->head == NULL) q->tail = NULL;
	free(aux);
	return v;
}

// printQueue
void printQueue(Queue *q){
	Node *aux = q->head;
	printf("Queue state: ");
	while(aux){ printf("%d <- ", aux->data); aux = aux->next; }
	printf("NULL\n");
}

// Stack using Node* for auxiliary storage
typedef struct Stack {
	Node *top;
} Stack;


void initStack(Stack *s){ s->top = NULL; }

void push(Stack *s, int v){
	Node *n = (Node*)malloc(sizeof(Node));
	n->data = v; n->next = s->top; s->top = n;
}

int pop(Stack *s){
	if(s->top == NULL) return -1;
	Node *aux = s->top; int v = aux->data; s->top = aux->next; free(aux); return v;
}

// inverte a fila usando pilha auxiliar
void invertQueue(Queue *q){
	Stack s; initStack(&s);
	while(q->head != NULL){
		push(&s, dequeue(q));
	}
	while(s.top != NULL){
		enqueue(q, pop(&s));
	}
}

int main(void){
	Queue q; initQueue(&q);
	int N;
	if(scanf("%d", &N) != 1) return 0;
	for(int i=0;i<N;i++){ int v; if(scanf("%d", &v)!=1) break; enqueue(&q, v); }

	printf("Original: "); printQueue(&q);
	invertQueue(&q);
	printf("Reversed: "); printQueue(&q);
	return 0;
}

