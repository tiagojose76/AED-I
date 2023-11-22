#include <stdio.h>

void imprimirBinarios(int n) {
    for (int i = 1; i <= n; i++) {
        int num = i;
        int binario = 0;
        int casa = 1;

        while (num > 0) {
            int resto = num % 2;
            binario += resto * casa;
            num /= 2;
            casa *= 10;
        }

        printf("%d ", binario);
    }
}

int main() {
    int n;
    printf("Digite um número inteiro: ");
    scanf("%d", &n);

    printf("Números binários entre 1 e %d:\n", n);
    imprimirBinarios(n);

    return 0;
}
