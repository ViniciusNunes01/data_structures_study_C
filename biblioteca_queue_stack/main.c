#include <stdio.h>

#include "queue.h"
#include "stack.h"

static void liberar_queue(Queue *queue)
{
	while (!isQueueEmpty(queue))
	{
		dequeue(queue);
	}
}

static void liberar_stack(Stack *stack)
{
	while (!isStackEmpty(stack))
	{
		pop(stack);
	}
}

int main(void)
{
	Stack stack;
	Queue queue;

	initStack(&stack);
	initQueue(&queue);

	printf("Pilha vazia? %s\n", isStackEmpty(&stack) ? "sim" : "nao");
	printf("Fila vazia? %s\n", isQueueEmpty(&queue) ? "sim" : "nao");

	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);

	enqueue(&queue, 100);
	enqueue(&queue, 200);
	enqueue(&queue, 300);

	printf("\nRemovendo da pilha:\n");
	while (!isStackEmpty(&stack))
	{
		printf("%d\n", pop(&stack));
	}

	printf("\nRemovendo da fila:\n");
	while (!isQueueEmpty(&queue))
	{
		printf("%d\n", dequeue(&queue));
	}

	printf("\nPilha vazia? %s\n", isStackEmpty(&stack) ? "sim" : "nao");
	printf("Fila vazia? %s\n", isQueueEmpty(&queue) ? "sim" : "nao");

	liberar_stack(&stack);
	liberar_queue(&queue);

	return 0;
}
