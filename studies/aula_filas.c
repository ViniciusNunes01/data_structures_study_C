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

// enqueue
void enqueue(Queue *q, int v){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = NULL;

    if(q->tail == NULL){ // fila vazia
        q->head = newNode;
        q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    printf("Enqueued: %d\n", q->tail->data);
}

// dequeue
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

// front
// isEmpty

// printQueue
void printQueue(Queue *q){
    Node *aux = q->head;
    printf("Queue state: ");
    while(aux != NULL){
        printf("%d <- ", aux->data);
        aux = aux->next;
    }
    printf("NULL\n");
}

int main(){
    Queue myQueue;
    initQueue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);
    printQueue(&myQueue);

    dequeue(&myQueue);
    printQueue(&myQueue);

    enqueue(&myQueue, 90);
    printQueue(&myQueue);

    return 0;
}