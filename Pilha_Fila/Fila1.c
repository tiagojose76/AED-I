#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* elementos;
    int frente;
    int tras;
    int capacidade;
} Fila;

void inicializarFila(Fila* fila, int capacidade);
void destruirFila(Fila* fila);
int isEmpty(Fila* fila);
void enqueue(Fila* fila, int elemento);
int dequeue(Fila* fila);
int peek(Fila* fila);
void print(Fila* fila);

void inicializarFila(Fila* fila, int capacidade) {
    fila->elementos = (int*)malloc(capacidade * sizeof(int));
    fila->frente = 0;
    fila->tras = -1;
    fila->capacidade = capacidade;
}

void destruirFila(Fila* fila) {
    free(fila->elementos);
}

int isEmpty(Fila* fila) {
    return (fila->tras < fila->frente);
}

void enqueue(Fila* fila, int elemento) {
    if (fila->tras == fila->capacidade - 1) {
        printf("Erro: a fila está cheia.\n");
        return;
    }
    fila->elementos[++fila->tras] = elemento;
}

int dequeue(Fila* fila) {
    if (isEmpty(fila)) {
        printf("Erro: a fila está vazia.\n");
        return -1;
    }
    int elemento = fila->elementos[fila->frente++];
    return elemento;
}

int peek(Fila* fila) {
    if (isEmpty(fila)) {
        printf("Erro: a fila está vazia.\n");
        return -1;
    }
    return fila->elementos[fila->frente];
}

void print(Fila* fila) {
    if (isEmpty(fila)) {
        printf("A fila está vazia.\n");
        return;
    }
    printf("Elementos da fila: ");
    for (int i = fila->frente; i <= fila->tras; i++) {
        printf("%d ", fila->elementos[i]);
    }
    printf("\n");
}

int main() {
    Fila fila;
    inicializarFila(&fila, 5);

    enqueue(&fila, 1);
    enqueue(&fila, 2);
    enqueue(&fila, 3);

    print(&fila);

    printf("Valor do primeiro elemento: %d\n", peek(&fila));

    printf("Elementos removidos da fila: %d %d\n", dequeue(&fila), dequeue(&fila));

    print(&fila);

    destruirFila(&fila);

    return 0;
}
