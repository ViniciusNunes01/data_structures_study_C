// Escreva uma função que inverta a ordem dos
// elementos da lista. O último nó deve passar a ser o primeiro, e todos
// os ponteiros proximo devem ser ajustados. (Dica: Você precisará de
// três ponteiros auxiliares: anterior, atual e proximo)

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

void insertNode(Node **head, int v)
{
	Node *newNode = (Node *)malloc(sizeof(Node));

	if (newNode == NULL)
	{
		return;
	}

	newNode->data = v;
	newNode->next = *head;

	*head = newNode;
}

void reverseList(Node **head)
{
	Node *anterior = NULL;
	Node *atual = *head;
	Node *proximo = NULL;

	while (atual != NULL)
	{
		proximo = atual->next;
		atual->next = anterior;
		anterior = atual;
		atual = proximo;
	}

	*head = anterior;
}

void printList(Node *head)
{
	while (head != NULL)
	{
		printf("%d", head->data);

		if (head->next != NULL)
		{
			printf(" -> ");
		}

		head = head->next;
	}

	printf(" -> NULL\n");
}

void freeList(Node **head)
{
	Node *curr = *head;

	while (curr != NULL)
	{
		Node *temp = curr;
		curr = curr->next;
		free(temp);
	}

	*head = NULL;
}

int main()
{
	Node *list = NULL;

	insertNode(&list, 10);
	insertNode(&list, 23);
	insertNode(&list, 45);
	insertNode(&list, 13);

	printf("Antes: ");
	printList(list);

	reverseList(&list);

	printf("Depois: ");
	printList(list);

	freeList(&list);

	return 0;
}