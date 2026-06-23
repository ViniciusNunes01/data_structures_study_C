#ifndef QUEUE_H
#define QUEUE_H

typedef struct QueueNode
{
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue
{
    QueueNode *head;
    QueueNode *tail;
} Queue;

void initQueue(Queue *queue);
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue);
int isQueueEmpty(const Queue *queue);

#endif