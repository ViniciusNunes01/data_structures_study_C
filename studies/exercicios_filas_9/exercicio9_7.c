#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Cliente {
	int id;
	int tempoChegada;
	struct Cliente *next;
} Cliente;

typedef struct Fila {
	Cliente *head;
	Cliente *tail;
} Fila;

void initFila(Fila *f){
	f->head = NULL;
	f->tail = NULL;
}

int isEmpty(Fila *f){
	return f->head == NULL;
}

void enqueue(Fila *f, int id, int tempoChegada){
	Cliente *novo = (Cliente*)malloc(sizeof(Cliente));
	novo->id = id;
	novo->tempoChegada = tempoChegada;
	novo->next = NULL;

	if(f->tail == NULL){
		f->head = novo;
		f->tail = novo;
	} else {
		f->tail->next = novo;
		f->tail = novo;
	}
}

Cliente* dequeue(Fila *f){
	if(isEmpty(f)){
		return NULL;
	}

	Cliente *aux = f->head;
	f->head = f->head->next;

	if(f->head == NULL){
		f->tail = NULL;
	}

	aux->next = NULL;
	return aux;
}

void freeFila(Fila *f){
	while(!isEmpty(f)){
		Cliente *aux = dequeue(f);
		free(aux);
	}
}

int main(){
	Fila filaBanco;
	int tempoAtual = 0;
	int clientesChegando = 0;
	int clientesAtendidos = 0;
	int totalClientes = 10;
	int totalEspera = 0;
	int tempoRestanteAtendimento = 0;
	int proximoClienteId = 1;

	srand((unsigned)time(NULL));
	initFila(&filaBanco);

	while(clientesAtendidos < totalClientes){
		int chegaCliente = rand() % 3 == 0;

		if(clientesChegando < totalClientes && chegaCliente){
			enqueue(&filaBanco, proximoClienteId, tempoAtual);
			printf("Tempo %d: Cliente %d chegou\n", tempoAtual, proximoClienteId);
			proximoClienteId++;
			clientesChegando++;
		}

		if(tempoRestanteAtendimento > 0){
			tempoRestanteAtendimento--;
		}

		if(tempoRestanteAtendimento == 0 && !isEmpty(&filaBanco)){
			Cliente *cliente = dequeue(&filaBanco);
			int tempoEspera = tempoAtual - cliente->tempoChegada;
			int tempoAtendimento = (rand() % 3) + 1;

			totalEspera += tempoEspera;
			clientesAtendidos++;
			tempoRestanteAtendimento = tempoAtendimento;

			printf("Tempo %d: Cliente %d entrou no atendimento, espera=%d, atendimento=%d\n",
				   tempoAtual, cliente->id, tempoEspera, tempoAtendimento);

			free(cliente);
		}

		tempoAtual++;
	}

	printf("\nTotal de clientes atendidos: %d\n", clientesAtendidos);
	printf("Tempo medio de espera: %.2f\n", (float)totalEspera / clientesAtendidos);

	freeFila(&filaBanco);
	return 0;
}
