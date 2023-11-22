#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solucao(int N, int* C, int* out_n) {
    int* chocolates_vendidos = (int*)malloc(N * sizeof(int));
    int pilha_chocolates[N];
    int top = -1;

    for (int i = 0; i < N; i++) {
        if (C[i] == 0) {
            chocolates_vendidos[i] = pilha_chocolates[top];
            top--;
        } else {
            top++;
            pilha_chocolates[top] = C[i];
        }
    }

    *out_n = N;

    return chocolates_vendidos;
}

int main() {
    int out_n;
    int N;
    scanf("%d", &N);
    int* C = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", &C[i]);

    int* out_ = solucao(N, C, &out_n);
    for (int i = 0; i < out_n; i++)
        printf("[%d] ", out_[i]);

    free(C);
    free(out_);

    return 0;
}
