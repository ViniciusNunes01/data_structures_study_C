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

void insertAtPosition(Node **head, Node **tail, int value, int position)
{
	Node *newNode = (Node *)malloc(sizeof(Node));

	if (newNode == NULL)
	{
		printf("Erro ao alocar memoria.\n");
		exit(1);
	}

	newNode->data = value;
	newNode->prev = NULL;
	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = newNode;
		*tail = newNode;
		return;
	}

	if (position <= 0)
	{
		newNode->next = *head;
		(*head)->prev = newNode;
		*head = newNode;
		return;
	}

	Node *current = *head;
	int index = 0;

	while (current->next != NULL && index < position)
	{
		current = current->next;
		index++;
	}

	if (index < position)
	{
		newNode->prev = *tail;
		(*tail)->next = newNode;
		*tail = newNode;
		return;
	}

	newNode->next = current;
	newNode->prev = current->prev;

	if (current->prev != NULL)
	{
		current->prev->next = newNode;
	}
	current->prev = newNode;

	if (newNode->prev == NULL)
	{
		*head = newNode;
	}
}

void printList(Node *head)
{
	printf("Lista resultante: ");

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
	int k;

	printf("Digite o valor X: ");
	if (scanf("%d", &x) != 1)
	{
		printf("Entrada invalida.\n");
		return 1;
	}

	printf("Digite a posicao K: ");
	if (scanf("%d", &k) != 1)
	{
		printf("Entrada invalida.\n");
		return 1;
	}

	insertAtPosition(&head, &tail, x, k);
	printList(head);

	return 0;
}
