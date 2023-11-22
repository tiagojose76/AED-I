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
void intercalarFilas(Fila* L1, Fila* L2, Fila* L3);
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

void intercalarFilas(Fila* L1, Fila* L2, Fila* L3) {
    while (!isEmpty(L1) && !isEmpty(L2)) {
        enqueue(L3, dequeue(L1));
        enqueue(L3, dequeue(L2));
    }

    while (!isEmpty(L1)) {
        enqueue(L3, dequeue(L1));
    }

    while (!isEmpty(L2)) {
        enqueue(L3, dequeue(L2));
    }
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
    Fila L1, L2, L3;
    inicializarFila(&L1);
    inicializarFila(&L2);
    inicializarFila(&L3);

    enqueue(&L1, 1);
    enqueue(&L1, 2);
    enqueue(&L1, 3);
    enqueue(&L1, 4);

    enqueue(&L2, 5);
    enqueue(&L2, 6);

    intercalarFilas(&L1, &L2, &L3);

    printf("L1: ");
    print(&L1);

    printf("L2: ");
    print(&L2);

    printf("L3: ");
    print(&L3);

    destruirFila(&L1);
    destruirFila(&L2);
    destruirFila(&L3);

    return 0;
}
