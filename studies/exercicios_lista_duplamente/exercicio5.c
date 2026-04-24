#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *prev;
	struct Node *next;
} Node;

void insertTail(Node **head, Node **tail, int value)
{
	Node *newNode = (Node *)malloc(sizeof(Node));

	if (newNode == NULL)
	{
		printf("Erro ao alocar memoria.\n");
		exit(1);
	}

	newNode->data = value;
	newNode->next = NULL;
	newNode->prev = *tail;

	if (*tail != NULL)
	{
		(*tail)->next = newNode;
	}
	else
	{
		*head = newNode;
	}

	*tail = newNode;
}

void removeAllOccurrences(Node **head, Node **tail, int x)
{
	Node *current = *head;

	while (current != NULL)
	{
		Node *nextNode = current->next;

		if (current->data == x)
		{
			if (current->prev != NULL)
			{
				current->prev->next = current->next;
			}
			else
			{
				*head = current->next;
			}

			if (current->next != NULL)
			{
				current->next->prev = current->prev;
			}
			else
			{
				*tail = current->prev;
			}

			free(current);
		}

		current = nextNode;
	}
}

void printForward(Node *head)
{
	printf("Do inicio ao fim: ");

	if (head == NULL)
	{
		printf("(vazia)\n");
		return;
	}

	while (head != NULL)
	{
		printf("%d", head->data);
		if (head->next != NULL)
		{
			printf(" ");
		}
		head = head->next;
	}

	printf("\n");
}

void printBackward(Node *tail)
{
	printf("Do fim ao inicio: ");

	if (tail == NULL)
	{
		printf("(vazia)\n");
		return;
	}

	while (tail != NULL)
	{
		printf("%d", tail->data);
		if (tail->prev != NULL)
		{
			printf(" ");
		}
		tail = tail->prev;
	}

	printf("\n");
}

int main(void)
{
	Node *head = NULL;
	Node *tail = NULL;
	int n;

	printf("Digite a quantidade de numeros: ");
	if (scanf("%d", &n) != 1 || n < 0)
	{
		printf("Entrada invalida.\n");
		return 1;
	}

	for (int i = 0; i < n; i++)
	{
		int value;

		printf("Numero %d: ", i + 1);
		if (scanf("%d", &value) != 1)
		{
			printf("Entrada invalida.\n");
			return 1;
		}

		insertTail(&head, &tail, value);
	}

	int x;

	printf("Digite o valor X para remover: ");
	if (scanf("%d", &x) != 1)
	{
		printf("Entrada invalida.\n");
		return 1;
	}

	removeAllOccurrences(&head, &tail, x);

	printf("Lista apos remocao:\n");
	printForward(head);
	printBackward(tail);

	return 0;
}