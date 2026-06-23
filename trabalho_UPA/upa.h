#ifndef UPA_H
#define UPA_H

// Enum para a Classificacao de Risco (Protocolo de Manchester)
// Mapeado de 0 a 4 para facilitar o uso como indice de um vetor.
typedef enum
{
    VERMELHO = 0, /* Emergencia - Indice 0 */
    LARANJA = 1,  /* Muito Urgente - Indice 1 */
    AMARELO = 2,  /* Urgente - Indice 2 */
    VERDE = 3,    /* Pouco Urgente - Indice 3 */
    AZUL = 4      /* Não Urgente - Indice 4 */
} Prioridade;

// Paciente
typedef struct Paciente
{
    int id;
    char nome[100];
    int idade;
    Prioridade classificacao;
    char horaChegada[6]; // hh:mm

    struct Paciente *next;
} Paciente;

// Controlador da fila
typedef struct FilaUPA
{
    Paciente *head;
    Paciente *tail;
} FilaUPA;

// Funções

// Inicializa o vetor com as 5 filas (coloca head e tail como NULL)
void inicializarFilas(FilaUPA filas[]);

// Cria o no do paciente e o insere no final (tail) da fila correspondente
void cadastrarPaciente(FilaUPA filas[], int id, const char *nome, int idade, Prioridade prio, const char *hora);

// Busca na ordem de prioridade e remove o paciente da primeira fila nao vazia
Paciente *chamarPaciente(FilaUPA filas[]);

// Funcionalidade extra: percorre todas as filas para encontrar um paciente pelo ID
Paciente *buscarPaciente(FilaUPA filas[], int id);

#endif