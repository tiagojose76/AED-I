#include <stdio.h>

// Define uma constante MAX com valor 10
#define MAX 8

// Função de ordenação por inserção
void insertion_sort(int *a)
{
    // O primeiro FOR é apenas para percorrer o vetor apartir do 2° elemento [1]
    for (int i = 1; i < MAX; i++)

    // A variavel [tpm] recebe o vetor de indice [i], que é o segundo elemento
    {
        int tmp = a[i];
        // Ja a variável [j] recebi o [i] que logo em seguida é decrementado, ou seja, [j] é o antecessor de i= [0]
        int j = i;

        // Enquanto j for maior que 0(tamanho da lista voltando) e tmp = a[i] maior que o antecessor de i= [0]
        // troca entre eles e decrementa o [j]
        while (j > 0 && tmp < a[j - 1])
        {
            a[j] = a[j - 1];
            j--;
        }
        // a[j] é o mesmo que antecessor e tmp é o elemento da frente.
        a[j] = tmp;
        // feita a troca o [i] é acrescentado virando elemento na 3° posição, e o J que é igual a ele é decrementado a 2° elemento. Assim percorrendo a lista a colocando todos os elementos menores a esquerda da lista
    }
}

int main()
{
    int vet[MAX]; // Declara um array de tamanho MAX

    printf("Digite %d valores:\n", MAX);

    // Loop para ler os valores e preencher o array
    for (int i = 0; i < MAX; i++)
    {
        printf("Valor %d: ", i + 1);
        scanf("%d", &vet[i]);
    }

    insertion_sort(vet); // Chama a função para ordenar o array

    printf("\nElementos do array após a ordenação:\n");

    // Loop para imprimir os elementos ordenados
    for (int i = 0; i < MAX; i++)
    {
        printf("%4d", vet[i]);
    }

    printf("\n");

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
