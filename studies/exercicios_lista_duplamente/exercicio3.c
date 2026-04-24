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

Node *findMiddle(Node *head)
{
	Node *slow = head;
	Node *fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

int main(void)
{
	Node *head = NULL;
	Node *tail = NULL;
	int n;

	printf("Digite a quantidade de numeros: ");
	if (scanf("%d", &n) != 1 || n <= 0)
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

	Node *middle = findMiddle(head);

	if (middle != NULL)
	{
		printf("Elemento central: %d\n", middle->data);
	}

	return 0;
}