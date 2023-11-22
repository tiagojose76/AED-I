#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* elementos;
    int topo;
    int capacidade;
} Pilha;

void inicializarPilha(Pilha* pilha, int capacidade) {
    pilha->elementos = (char*)malloc(capacidade * sizeof(char));
    pilha->topo = -1;
    pilha->capacidade = capacidade;
}

void destruirPilha(Pilha* pilha) {
    free(pilha->elementos);
}

int isFull(Pilha* pilha) {
    return (pilha->topo == pilha->capacidade - 1);
}

void push(Pilha* pilha, char elemento) {
    if (isFull(pilha)) {
        printf("Erro: a pilha está cheia.\n");
        return;
    }
    pilha->elementos[++pilha->topo] = elemento;
}

char pop(Pilha* pilha) {
    if (pilha->topo == -1) {
        printf("Erro: a pilha está vazia.\n");
        return '\0';
    }
    return pilha->elementos[pilha->topo--];
}

int isEmpty(Pilha* pilha) {
    return (pilha->topo == -1);
}

int verificarBalanceamento(const char* expressao) {
    int tamanho = strlen(expressao);
    Pilha pilha;
    inicializarPilha(&pilha, tamanho);
    for (int i = 0; i < tamanho; i++) {
        char caractere = expressao[i];
        if (caractere == '(' || caractere == '[' || caractere == '{') {
            push(&pilha, caractere);
        } else if (caractere == ')' || caractere == ']' || caractere == '}') {
            if (isEmpty(&pilha)) {
                destruirPilha(&pilha);
                return 0; // Não está bem balanceado
            }
            char topo = pop(&pilha);
            if ((caractere == ')' && topo != '(') ||
                (caractere == ']' && topo != '[') ||
                (caractere == '}' && topo != '{')) {
                destruirPilha(&pilha);
                return 0; // Não está bem balanceado
            }
        }
    }
    int balanceado = isEmpty(&pilha);
    destruirPilha(&pilha);
    return balanceado;
}

int main() {
    char expressao[100];
    printf("Digite a expressao: ");
    fgets(expressao, sizeof(expressao), stdin);
    expressao[strcspn(expressao, "\n")] = '\0';

    int balanceado = verificarBalanceamento(expressao);
    if (balanceado) {
        printf("Os parenteses, colchetes e chaves estao bem balanceados.\n");
    } else {
        printf("Os parenteses, colchetes e chaves nao estao bem balanceados.\n");
    }

    return 0;
}
