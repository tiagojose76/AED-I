#include <stdio.h>
#include <stdlib.h>

void construirTorre(int N, int* discos) {
    int* torre = (int*)malloc(N * sizeof(int));  // Array para armazenar a torre
    int topo = -1;  // Índice do topo da torre

    for (int dia = 0; dia < N; dia++) {
        int disco = discos[dia];

        // Encontrar a posição correta para inserir o disco na torre
        int posicao = topo + 1;
        while (posicao > 0 && torre[posicao - 1] < disco) {
            posicao--;
        }

        // Empurrar os discos maiores para baixo para abrir espaço para o novo disco
        for (int i = topo; i >= posicao; i--) {
            torre[i + 1] = torre[i];
        }

        // Inserir o novo disco na posição correta
        torre[posicao] = disco;
        topo++;

        // Imprimir a torre atualizada
        for (int i = topo; i >= 0; i--) {
            printf("%d ", torre[i]);
        }
        printf("\n");
    }

    free(torre);
}

int main() {
    int N;
    scanf("%d", &N);

    int* discos = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &discos[i]);
    }

    construirTorre(N, discos);

    free(discos);
    return 0;
}
