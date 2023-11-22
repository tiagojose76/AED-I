#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* proximo;
} No;

typedef struct {
    No* frente;
    No* tras;
} Fila;

void inicializarFila(Fila* fila);
void destruirFila(Fila* fila);
int isEmpty(Fila* fila);
void enqueue(Fila* fila, int elemento);
int dequeue(Fila* fila);
int peek(Fila* fila);
void print(Fila* fila);

void inicializarFila(Fila* fila) {
    fila->frente = NULL;
    fila->tras = NULL;
}

void destruirFila(Fila* fila) {
    while (!isEmpty(fila)) {
        dequeue(fila);
    }
}

int isEmpty(Fila* fila) {
    return (fila->frente == NULL);
}

void enqueue(Fila* fila, int elemento) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = elemento;
    novoNo->proximo = NULL;

    if (isEmpty(fila)) {
        fila->frente = novoNo;
        fila->tras = novoNo;
    } else {
        fila->tras->proximo = novoNo;
        fila->tras = novoNo;
    }
}

int dequeue(Fila* fila) {
    if (isEmpty(fila)) {
        printf("Erro: a fila está vazia.\n");
        return -1;
    }

    No* noRemovido = fila->frente;
    int elemento = noRemovido->dado;

    fila->frente = fila->frente->proximo;
    free(noRemovido);

    if (fila->frente == NULL) {
        fila->tras = NULL;
    }

    return elemento;
}

int peek(Fila* fila) {
    if (isEmpty(fila)) {
        printf("Erro: a fila está vazia.\n");
        return -1;
    }

    return fila->frente->dado;
}

void print(Fila* fila) {
    if (isEmpty(fila)) {
        printf("A fila está vazia.\n");
        return;
    }

    printf("Elementos da fila: ");

    No* atual = fila->frente;
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }

    printf("\n");
}

int main() {
    Fila fila;
    inicializarFila(&fila);

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
