#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

static QueueNode *createQueueNode(int value)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode == NULL)
    {
        printf("Erro: memoria insuficiente.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void initQueue(Queue *queue)
{
    queue->head = NULL;
    queue->tail = NULL;
}

void enqueue(Queue *queue, int value)
{
    QueueNode *newNode = createQueueNode(value);

    if (isQueueEmpty(queue))
    {
        queue->head = newNode;
        queue->tail = newNode;
        return;
    }

    queue->tail->next = newNode;
    queue->tail = newNode;
}

int dequeue(Queue *queue)
{
    if (isQueueEmpty(queue))
    {
        printf("Fila vazia!\n");
        return -1;
    }

    QueueNode *removed = queue->head;
    int value = removed->data;
    queue->head = removed->next;

    if (queue->head == NULL)
    {
        queue->tail = NULL;
    }

    free(removed);
    return value;
}

int isQueueEmpty(const Queue *queue)
{
    return queue->head == NULL;
}