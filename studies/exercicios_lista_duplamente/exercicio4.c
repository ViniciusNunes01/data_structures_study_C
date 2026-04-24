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

void reverseList(Node **head, Node **tail)
{
	Node *current = *head;

	while (current != NULL)
	{
		Node *temp = current->next;
		current->next = current->prev;
		current->prev = temp;
		current = temp;
	}

	Node *temp = *head;
	*head = *tail;
	*tail = temp;
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

	printf("Lista antes da inversao:\n");
	printForward(head);

	reverseList(&head, &tail);

	printf("Lista depois da inversao:\n");
	printForward(head);

	return 0;
}