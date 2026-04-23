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

long long sumForward(Node *head)
{
	long long sum = 0;

	while (head != NULL)
	{
		sum += head->data;
		head = head->next;
	}

	return sum;
}

long long sumBackward(Node *tail)
{
	long long sum = 0;

	while (tail != NULL)
	{
		sum += tail->data;
		tail = tail->prev;
	}

	return sum;
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

	long long forwardSum = sumForward(head);
	long long backwardSum = sumBackward(tail);

	printf("Soma do inicio ao fim: %lld\n", forwardSum);
	printf("Soma do fim ao inicio: %lld\n", backwardSum);

	if (forwardSum == backwardSum)
	{
		printf("A integridade da lista esta correta.\n");
	}
	else
	{
		printf("A integridade da lista pode estar comprometida.\n");
	}

	return 0;
}
