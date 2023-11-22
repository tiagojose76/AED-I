#include <stdio.h>

void trocar(int *valor1, int *valor2)
{
    int temporario = *valor1;
    *valor1 = *valor2;
    *valor2 = temporario;
}

void selectionSort(int array[], int n)
{
    // O primeiro FOR é para percorrer o vetor por completo
    for (int i = 0; i < n - 1; i++)
    {
        // O 'menor indice' é apenas o primeiro indice do array
        int indice_menor = i; // Inicializa o índice do menor elemento como 'i'
        // J recebi o sucessor de 'i'
        for (int j = i + 1; j < n; j++)
        {
            // Se o 'j' for maior que 'i'
            if (array[j] < array[indice_menor])
                indice_menor = j; // Atualiza o índice do menor elemento quando um valor menor é encontrado
        }
        // Ali em cima faz apenas a atualização do indice e não faz a troca, ja aqui nessa chamada de função faz a troca com ponteiros
        if (indice_menor != i)
            trocar(&array[indice_menor], &array[i]); // Troca os valores dos elementos no índice 'i' e 'indice_menor'
    }
}

int main()
{
    int array[] = {10, 5, 15, 9, 20, 21, 27, 14};
    int n = sizeof(array) / sizeof(array[0]);
    selectionSort(array, n);
    printf("Array ordenado: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
