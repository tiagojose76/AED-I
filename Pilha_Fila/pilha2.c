#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* proximo;
} no;

typedef struct {
    no* topo;
} pilha;

void push(pilha* p, int valor) {
    no* novoNo = (no*)malloc(sizeof(no));
    if (novoNo == NULL) {
        printf("Erro: falha ao alocar memória.\n");
        return;
    }
    novoNo->valor = valor;
    novoNo->proximo = p->topo;
    p->topo = novoNo;
}

int pop(pilha* p) {
    if (p->topo == NULL) {
        printf("Erro: a pilha está vazia.\n");
        return -1; // Valor de retorno de erro
    }
    no* noRemovido = p->topo;
    int valor = noRemovido->valor;
    p->topo = noRemovido->proximo;
    free(noRemovido);
    return valor;
}

int topo(pilha* p) {
    if (p->topo == NULL) {
        printf("Erro: a pilha está vazia.\n");
        return -1; // Valor de retorno de erro
    }
    return p->topo->valor;
}

int isEmpty(pilha* p) {
    return (p->topo == NULL);
}

void print(pilha* p) {
    if (isEmpty(p)) {
        printf("A pilha está vazia.\n");
        return;
    }
    printf("Elementos da pilha:\n");
    no* atual = p->topo;
    while (atual != NULL) {
        printf("%d\n", atual->valor);
        atual = atual->proximo;
    }
}

void limparPilha(pilha* p) {
    while (!isEmpty(p)) {
        pop(p);
    }
}

int main() {
    pilha minhaPilha;
    minhaPilha.topo = NULL; // Inicializa o topo da pilha como NULL (pilha vazia)

    push(&minhaPilha, 20);
    push(&minhaPilha, 30);
    push(&minhaPilha, 40);
    push(&minhaPilha, 50);

    printf("Topo da pilha: %d\n", topo(&minhaPilha));

    printf("Removendo elemento do topo: %d\n", pop(&minhaPilha));
    printf("Topo da pilha após remoção: %d\n", topo(&minhaPilha));

    printf("A pilha está vazia? %s\n", isEmpty(&minhaPilha) ? "Sim" : "Não");

    print(&minhaPilha);

    limparPilha(&minhaPilha);

    return 0;
}
