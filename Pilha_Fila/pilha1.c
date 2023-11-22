#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int pilha[MAX_SIZE];
    int topo;
} pilha;

void push(pilha *p, int valor) {
    if (p->topo == MAX_SIZE - 1) {
        printf("Erro: a pilha está cheia.\n");
        return;
    }
    p->pilha[++p->topo] = valor;
}

int pop(pilha *p) {
    if (p->topo == -1) {
        printf("Erro: a pilha está vazia.\n");
        return -1; // Valor de retorno de erro
    }
    return p->pilha[p->topo--];
}

int topo(pilha *p) {
    if (p->topo == -1) {
        printf("Erro: a pilha está vazia.\n");
        return -1; // Valor de retorno de erro
    }
    return p->pilha[p->topo];
}

int isEmpty(pilha *p) {
    if (p->topo == -1)
        return 1; // Pilha está vazia
    else
        return 0; // Pilha não está vazia
}

void print(pilha *p) {
    if (isEmpty(p)) {
        printf("A pilha está vazia.\n");
        return;
    }
    printf("Elementos da pilha:\n");
    for (int i = p->topo; i >= 0; i--) {
        printf("%d\n", p->pilha[i]);
    }
}

int main() {
    pilha minhaPilha;
    minhaPilha.topo = -1; // Inicializa o topo da pilha como -1 (pilha vazia)

    push(&minhaPilha, 10);
    push(&minhaPilha, 20);
    push(&minhaPilha, 30);
    push(&minhaPilha, 40);

    printf("Topo da pilha: %d\n", topo(&minhaPilha));

    printf("Removendo elemento do topo: %d\n", pop(&minhaPilha));
    printf("Topo da pilha após remoção: %d\n", topo(&minhaPilha));

    printf("A pilha está vazia? %s\n", isEmpty(&minhaPilha) ? "Sim" : "Não");

    print(&minhaPilha);

    return 0;
}
