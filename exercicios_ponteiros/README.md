# Exercícios de Ponteiros em C

Pasta com 15 exercícios individuais sobre ponteiros em C, organizados por dificuldade e tópicos.

## 📁 Estrutura da Pasta

```
exercicios_ponteiros/
├── exercicio_1_1.c          (Declaração e Inicialização)
├── exercicio_1_2.c          (Operadores & e *)
├── exercicio_1_3.c          (Ponteiros e Arrays)
├── exercicio_2_1.c          (Passagem por Referência)
├── exercicio_2_2.c          (Retorno de Ponteiro)
├── exercicio_2_3.c          (Ponteiros como Parâmetros)
├── exercicio_3_1.c          (malloc e free)
├── exercicio_3_2.c          (Alocação de Estrutura)
├── exercicio_3_3.c          (Array Dinâmico)
├── exercicio_4_1.c          (Ponteiro para Ponteiro)
├── exercicio_4_2.c          (Matriz Dinâmica)
├── exercicio_4_3.c          (Estrutura com Ponteiros)
├── exercicio_5_1.c          (Modifica Array)
├── exercicio_5_2.c          (Contagem de Elementos)
├── exercicio_5_3.c          (Cópia de Array)
├── exercicio_5_4.c          (Inversão de Array)
├── exercicio_5_5.c          (Busca e Retorno)
├── topicos_pesquisa.txt     (Guia de tópicos para pesquisa)
└── README.md                (Este arquivo)
```

## 🎯 Como Usar

### 1. **Resolva um exercício por vez**
   - Abra `exercicio_X_Y.c`
   - Leia o objetivo no início do arquivo
   - Implemente a solução
   - **NÃO** descomente nada, simplesmente complete o código

### 2. **Compile e teste**
   ```bash
   gcc -Wall -Wextra exercicio_X_Y.c -o exercicio
   ./exercicio
   ```

### 3. **Se travar**
   - Consulte [topicos_pesquisa.txt](topicos_pesquisa.txt)
   - Pesquise os tópicos sugeridos
   - **Não peça respostas, pesquise!**

### 4. **Quando terminar**
   - Commite no GitHub
   - Envie seus exercícios resolvidos para revisão

## 📚 Seções

### Seção 1: Conceitos Básicos (3 exercícios)
- Declaração, inicialização, operadores básicos
- Recomendado: Comece daqui!

### Seção 2: Funções (3 exercícios)
- Passagem por referência, retorno de ponteiros
- Pré-requisito: Seção 1

### Seção 3: Alocação Dinâmica (3 exercícios)
- malloc, free, estruturas
- Pré-requisito: Seção 2

### Seção 4: Conceitos Avançados (3 exercícios)
- Ponteiro para ponteiro, matrizes dinâmicas
- Pré-requisito: Seção 3

### Seção 5: Exercícios Práticos (5 exercícios)
- Desafios práticos integrando tudo
- Pré-requisito: Seções anteriores

## ✅ Checklist para Cada Exercício

Antes de considerar um exercício completo:

- [ ] Código compila sem erros
- [ ] Código compila sem warnings
- [ ] Programa executa corretamente
- [ ] Saída corresponde ao esperado
- [ ] Memória alocada foi liberada (2)
- [ ] Código está bem organizado e comentado

(2) Para verificar memory leaks, compile e execute com ferramentas de análise.

## 🚀 Dicas Importantes

1. **Compile frequentemente** - não deixe para compilar ao final
2. **Leia os erros** - mensagens do compilador são suas amigas
3. **Teste com valores diferentes** - não apenas os exemplos
4. **Imprima valores e endereços** - ajuda a entender ponteiros
5. **Use `sizeof()`** - sempre que não tiver certeza do tamanho
6. **Verifique NULL** - sempre que alocar memória

## 📖 Recursos Recomendados

- Documentação oficial de C
- "The C Programming Language" (Kernighan & Ritchie)
- Tutoriais sobre ponteiros em C
- Material da sua disciplina

## 💡 Recapitulação Rápida

### Referência (endereço)
```c
int x = 10;
int* ptr = &x;  // ptr aponta para x
```

### Desreferência (valor)
```c
printf("%d", *ptr);  // imprime o valor apontado
```

### Alocação Dinâmica
```c
int* arr = (int*) malloc(n * sizeof(int));
free(arr);
```

### Aritmética de Ponteiros
```c
ptr++;     // aponta para próximo elemento
ptr += 3;  // avança 3 elementos
```

## 📝 Notas

- Todos os exercícios devem ser preparados para GitHub
- Crie commits significativos ("Exercício 1.1 completo", etc)
- Mantenha a estrutura de pastas organizada
- Valide que tudo compila antes de fazer push

---

**Bom estudo!** 💪

Se tiver dúvidas conceituais, pesquise. Se o código não compila, leia o erro. Você consegue! 🎯
