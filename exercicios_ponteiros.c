/*
================================================================================
        LISTA DE EXERCÍCIOS - PONTEIROS EM C
        Curso: Estruturas de Dados
        Nível: Introdutório a Intermediário
================================================================================

INSTRUÇÕES:
- Resolva todos os exercícios abaixo
- Não modifique o protótipo das funções
- Teste suas soluções compilando com: gcc -Wall -Wextra seu_arquivo.c -o seu_programa
- Tente resolver sem consultar a solução

================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
================================================================================
SEÇÃO 1: CONCEITOS BÁSICOS DE PONTEIROS
================================================================================
*/

/*
EXERCÍCIO 1.1 - Declaração e Inicialização
Crie uma função que:
- Declare um inteiro com valor 42
- Declare um ponteiro para inteiro
- Inicialize o ponteiro apontando para o inteiro
- Imprima o valor do inteiro usando o ponteiro
*/
void exercicio_1_1() {
    // Seu código aqui
}


/*
EXERCÍCIO 1.2 - Operadores & e *
Complete a função para:
- Receber um inteiro como parâmetro
- Imprimir o endereço de memória da variável
- Imprimir o valor da variável
- Usar apenas ponteiros para acessar essas informações
*/
void exercicio_1_2(int valor) {
    // Seu código aqui
}


/*
EXERCÍCIO 1.3 - Ponteiros e Arrays
Crie uma função que:
- Declare um array de 5 inteiros: {10, 20, 30, 40, 50}
- Use um ponteiro para percorrer o array
- Imprima cada elemento usando aritmética de ponteiros (sem usar índices)
*/
void exercicio_1_3() {
    // Seu código aqui
}


/*
================================================================================
SEÇÃO 2: PONTEIROS E FUNÇÕES
================================================================================
*/

/*
EXERCÍCIO 2.1 - Passagem por Referência
Crie uma função que:
- Receba dois inteiros por referência (ponteiros)
- Troque os valores das duas variáveis
- A troca deve ser refletida na função chamadora
*/
void exercicio_2_1() {
    // Crie a função swap aqui
    // Depois teste com algo como:
    // int a = 5, b = 10;
    // swap(&a, &b);
    // printf("a = %d, b = %d\n", a, b);
}


/*
EXERCÍCIO 2.2 - Retorno de Ponteiro
Crie uma função que:
- Aloque dinamicamente um array de n inteiros
- Preencha este array com os números de 1 até n
- Retorne um ponteiro para este array
- Escreva uma função chamadora que teste isto
*/
void exercicio_2_2() {
    // Crie a função aqui
    // int* criar_array(int tamanho);
}


/*
EXERCÍCIO 2.3 - Ponteiros como Parâmetros
Crie uma função que:
- Receba um array de inteiros e seu tamanho como parâmetros
- Encontre o maior valor do array
- Armazene o maior valor em um inteiro apontado por um ponteiro (passado como parâmetro)
*/
void exercicio_2_3() {
    // Crie a função aqui
    // void encontrar_maximo(int* array, int tamanho, int* maximo);
}


/*
================================================================================
SEÇÃO 3: ALOCAÇÃO DINÂMICA DE MEMÓRIA
================================================================================
*/

/*
EXERCÍCIO 3.1 - malloc e free
Crie uma função que:
- Aloque espaço para 10 inteiros dinamicamente
- Preencha estes inteiros com múltiplos de 5 (5, 10, 15, ..., 50)
- Imprima os valores
- Libere a memória alocada
*/
void exercicio_3_1() {
    // Seu código aqui
}


/*
EXERCÍCIO 3.2 - Alocação de Estrutura
Crie uma estrutura chamada "Pessoa" com os campos:
- char nome[100]
- int idade
- float altura

Depois crie uma função que:
- Aloque espaço para uma Pessoa dinamicamente
- Leia dados do usuário (nome, idade, altura)
- Imprima os dados
- Libere a memória
*/
void exercicio_3_2() {
    // Defina a estrutura Pessoa aqui
    // Crie a função aqui
}


/*
EXERCÍCIO 3.3 - Alocação de Array Dinâmico
Crie uma função que:
- Receba um tamanho n como parâmetro
- Aloque um array dinâmico de n floats
- Preencha com valores lidos do usuário
- Calcule e retorne a média dos valores
- Libere a memória
*/
void exercicio_3_3() {
    // Crie a função aqui
    // float calcular_media_dinamica(int n);
}


/*
================================================================================
SEÇÃO 4: PONTEIROS PARA PONTEIROS E CONCEITOS AVANÇADOS
================================================================================
*/

/*
EXERCÍCIO 4.1 - Ponteiro para Ponteiro
Crie uma função que:
- Declare um inteiro com valor 100
- Declare um ponteiro para este inteiro
- Declare um ponteiro para o ponteiro anterior
- Imprima o valor usando os três (variável, ponteiro, ponteiro para ponteiro)
*/
void exercicio_4_1() {
    // Seu código aqui
}


/*
EXERCÍCIO 4.2 - Alocação de Matriz Dinâmica
Crie uma função que:
- Aloque dinamicamente uma matriz 3x3 de inteiros
- Preencha com valores de 1 a 9
- Imprima a matriz
- Libere a memória
*/
void exercicio_4_2() {
    // Crie a função aqui
    // int** criar_matriz_dinamica(int linhas, int colunas);
}


/*
EXERCÍCIO 4.3 - Estrutura com Ponteiros
Defina uma estrutura "Lista" que contenha:
- Um ponteiro para inteiros (array)
- Um tamanho
- Uma capacidade

Crie as seguintes funções:
- criar_lista(int capacidade): aloca a lista
- adicionar_elemento(Lista* lista, int valor): adiciona um elemento
- remover_elemento(Lista* lista): remove o último elemento
- destruir_lista(Lista* lista): libera toda memória
*/
void exercicio_4_3() {
    // Defina a estrutura e as funções aqui
}


/*
================================================================================
SEÇÃO 5: EXERCÍCIOS PRÁTICOS E DESAFIOS
================================================================================
*/

/*
EXERCÍCIO 5.1 - Função que Modifica Array
Crie uma função que:
- Receba um array de inteiros e seu tamanho
- Multiplique todos os elementos por 2 usando ponteiros
- A modificação deve afetar o array original
*/
void exercicio_5_1() {
    // Crie a função aqui
    // void dobrar_elementos(int* array, int tamanho);
}


/*
EXERCÍCIO 5.2 - Contagem de Elementos
Crie uma função que:
- Receba um array de inteiros e um valor a procurar
- Conte quantas vezes este valor aparece no array
- Use apenas aritmética de ponteiros (sem índices)
*/
void exercicio_5_2() {
    // Crie a função aqui
    // int contar_ocorrencias(int* array, int tamanho, int valor);
}


/*
EXERCÍCIO 5.3 - Cópia de Array
Crie uma função que:
- Receba um array de inteiros e seu tamanho
- Crie um novo array alocado dinamicamente com os mesmos elementos
- Retorne um ponteiro para o novo array
*/
void exercicio_5_3() {
    // Crie a função aqui
    // int* copiar_array(int* original, int tamanho);
}


/*
EXERCÍCIO 5.4 - Inversão de Array
Crie uma função que:
- Receba um array de inteiros e seu tamanho
- Inverta o ordem dos elementos usando ponteiros
- A inversão deve ser feita in-place (sem array auxiliar)
*/
void exercicio_5_4() {
    // Crie a função aqui
    // void inverter_array(int* array, int tamanho);
}


/*
EXERCÍCIO 5.5 - Busca e Retorno de Endereço
Crie uma função que:
- Receba um array de inteiros, seu tamanho e um valor a procurar
- Retorne um ponteiro para o primeiro elemento igual ao buscado
- Retorne NULL se o elemento não for encontrado
*/
void exercicio_5_5() {
    // Crie a função aqui
    // int* buscar_valor(int* array, int tamanho, int valor);
}


/*
================================================================================
FUNÇÃO MAIN PARA TESTES
================================================================================
Descomente as chamadas das funções conforme você as implementar
*/

int main() {
    printf("=== TESTES DOS EXERCÍCIOS DE PONTEIROS ===\n\n");
    
    // exercicio_1_1();
    // exercicio_1_2(42);
    // exercicio_1_3();
    
    printf("\nBom estudo! Resolva todos os exercícios e teste suas soluções.\n");
    
    return 0;
}

/*
================================================================================
DICAS GERAIS:
================================================================================
1. Sempre libere memória alocada com malloc usando free
2. Inicialize ponteiros antes de usar
3. Ao trabalhar com arrays dinâmicos, sempre guarde o tamanho
4. Use & para obter endereço de uma variável
5. Use * para acessar o valor apontado por um ponteiro
6. Array names são automaticamente convertidos para ponteiros
7. Teste com valores pequenos e acompanhe a memória
8. Use variáveis de depuração para imprimir endereços
9. Sempre combine malloc com free na mesma função ou estruture bem o código
10. Compilar com -Wall e -Wextra ajuda a encontrar problemas

================================================================================
*/
