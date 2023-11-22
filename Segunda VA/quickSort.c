#include <stdio.h>
#include <stdlib.h> // srand, rand
#include <time.h>   // time

// Função que realiza a troca entre dois elementos
void troca(int vet[], int i, int j)
{
    int aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

// Função de particionamento e retorno do índice do pivô
int particiona(int vet[], int inicio, int fim)
{
    int pivo = vet[fim]; // O pivô é sempre o último elemento
    int pivo_indice = inicio;

    for (int i = inicio; i < fim; i++)
    {
        // Verifica se o elemento é <= ao pivô
        if (vet[i] <= pivo)
        {
            // Realiza a troca
            troca(vet, i, pivo_indice);
            // Incrementa o pivo_indice
            pivo_indice++;
        }
    }

    // Troca o pivô
    troca(vet, pivo_indice, fim);

    // Retorna o índice do pivô
    return pivo_indice;
}

// Função que escolhe um pivô aleatório para evitar o pior caso do quicksort
int particiona_random(int vet[], int inicio, int fim)
{
    // Seleciona um número aleatório entre fim e inicio
    int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;

    // Faz a troca para colocar o pivô no fim
    troca(vet, pivo_indice, fim);
    // Chama a função de particionamento
    return particiona(vet, inicio, fim);
}

// Função do quicksort
void quick_sort(int vet[], int inicio, int fim)
{
    if (inicio < fim)
    {
        // Função particionar retorna o índice do pivô
        int pivo_indice = particiona_random(vet, inicio, fim);

        // Chamadas recursivas para o quick_sort
        quick_sort(vet, inicio, pivo_indice - 1);
        quick_sort(vet, pivo_indice + 1, fim);
    }
}

int main()
{
    int vet[] = {10, 5, 15, 9, 20, 21, 27, 14};
    int tam_vet = sizeof(vet) / sizeof(int);

    // Inicializa a seed para os números aleatórios
    srand(time(NULL));

    // Chama o quicksort
    quick_sort(vet, 0, tam_vet - 1);

    // Mostra o vetor ordenado
    for (int i = 0; i < tam_vet; i++)
    {
        printf("%d ", vet[i]);
    }

    return 0;
}
