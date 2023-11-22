#include <stdio.h>

int minTempoParaEsvaziarArrays(int n, int* a, int* b) {
    int tempo = 0;
    int i, j;

    // Loop até que ambos os arrays estejam vazios
    while (n > 0) {
        // Verifica se os primeiros elementos de ambos os arrays são iguais
        if (a[0] == b[0]) {
            // Remove os primeiros elementos de ambos os arrays
            for (i = 0; i < n - 1; i++) {
                a[i] = a[i + 1];
                b[i] = b[i + 1];
            }
            n--; // Reduz o tamanho dos arrays
        } else {
            // Rotaciona o primeiro array no sentido horário
            int temp = a[0];
            for (i = 0; i < n - 1; i++) {
                a[i] = a[i + 1];
            }
            a[n - 1] = temp;
        }
        tempo++; // Aumenta o tempo decorrido
    }

    return tempo;
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    int tempoTotal = minTempoParaEsvaziarArrays(n, a, b);
    printf("%d\n", tempoTotal);

    return 0;
}
