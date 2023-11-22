#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* elementos;
    int topo;
    int capacidade;
} Pilha;

void inicializarPilha(Pilha* pilha, int capacidade) {
    pilha->elementos = (int*)malloc(capacidade * sizeof(int));
    pilha->topo = -1;
    pilha->capacidade = capacidade;
}

void destruirPilha(Pilha* pilha) {
    free(pilha->elementos);
}

int isFull(Pilha* pilha) {
    return (pilha->topo == pilha->capacidade - 1);
}

void push(Pilha* pilha, int elemento) {
    if (isFull(pilha)) {
        printf("Erro: a pilha está cheia.\n");
        return;
    }
    pilha->elementos[++pilha->topo] = elemento;
}

int pop(Pilha* pilha) {
    if (pilha->topo == -1) {
        printf("Erro: a pilha está vazia.\n");
        return -1;
    }
    return pilha->elementos[pilha->topo--];
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    int a = 0;
    int b = 1;
    int fib;

    for (int i = 2; i <= n; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }

    return fib;
}

void acumularFibonacciNaPilha(Pilha* pilha, int n) {
    for (int i = 0; i < n; i++) {
        int fib = fibonacci(i);
        push(pilha, fib);
    }
}

int main() {
    int n;
    printf("Digite a quantidade de valores da sequência de Fibonacci a acumular: ");
    scanf("%d", &n);

    Pilha pilha;
    inicializarPilha(&pilha, n);

    acumularFibonacciNaPilha(&pilha, n);

    printf("Valores acumulados na pilha:\n");
    while (!isFull(&pilha)) {
        int fib = pop(&pilha);
        printf("%d ", fib);
    }
    printf("\n");

    destruirPilha(&pilha);

    return 0;
}
