#include <stdio.h>
#include <string.h>

void inverterString(char* str, int inicio, int fim) {
    while (inicio < fim) {
        char temp = str[inicio];
        str[inicio] = str[fim];
        str[fim] = temp;
        inicio++;
        fim--;
    }
}

int main() {
    char biblioteca[100];
    scanf("%s", biblioteca);  // Lendo a biblioteca da entrada

    int tamanho = strlen(biblioteca);
    int inicio = 0;
    int fim = tamanho - 1;

    // Invertendo a ordem dos livros dentro das prateleiras
    while (inicio < fim) {
        if (biblioteca[inicio] == '/') {
            inicio++;
        } else if (biblioteca[fim] == '\\') {
            fim--;
        } else {
            char temp = biblioteca[inicio];
            biblioteca[inicio] = biblioteca[fim];
            biblioteca[fim] = temp;
            inicio++;
            fim--;
        }
    }

    // Removendo as prateleiras e imprimindo a nova ordem dos livros
    int indiceLivro = 0;
    for (int i = 0; i < tamanho; i++) {
        if (biblioteca[i] != '/' && biblioteca[i] != '\\') {
            biblioteca[indiceLivro] = biblioteca[i];
            indiceLivro++;
        }
    }
    biblioteca[indiceLivro] = '\0';

    printf("A biblioteca reorganizada de Alice é: %s\n", biblioteca);

    return 0;
}
