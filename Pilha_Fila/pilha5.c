#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int palindromo(const char* str) {
    int tamanho = strlen(str);
    int i = 0;
    int j = tamanho - 1;

    while (i < j) {
        // Desconsidera acentos e converte os caracteres para minúsculas
        char charI = minusculo(str[i]);
        char charJ = minusculo(str[j]);

        // Ignora espaços em branco
        if (espaco(charI)) {
            i++;
            continue;
        }
        if (espaco(charJ)) {
            j--;
            continue;
        }

        // Compara os caracteres
        if (charI != charJ) {
            return 0; // Não é um palíndromo
        }

        i++;
        j--;
    }

    return 1; // É um palíndromo
}

int main() {
    char str[100];
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    if (palindromo(str)) {
        printf("A string é um palíndromo.\n");
    } else {
        printf("A string não é um palíndromo.\n");
    }

    return 0;
}
