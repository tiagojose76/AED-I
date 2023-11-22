#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 10

int main()
{
    setlocale(LC_ALL, "");
    int numeros[TAM];
    int i, aux, contador;

    printf("Entre com os elementos do array em ordem crescente:\n");
    for (i = 0; i < TAM; i++)
    {
        scanf("%d", &numeros[i]);
    }

    printf("Array em ordem crescente:\n");
    for (i = 0; i < TAM; i++)
    {
        printf("%4d", numeros[i]);
    }

    printf("\nAplicando o algoritmo de ordenação Bubblesort:\n");

    // De forma inversa, o FOR começa lendo a lista de trás para frente, onde o contador vai decrementando.
    for (contador = TAM - 1; contador >= 1; contador--)
    {
        // Dentro desse FOR, elemento na posição (i), é o penultimo elemento da lista, onde será feito a comparacação com o sucessor.
        // Se caso for maior, ele troca com seu sucessor e é decrementado para que uma nova verificação seja feita.
        for (i = TAM - 2; i >= 0; i--)
        {

            // penúltimo numero     ultimo numero
            if (numeros[i] > numeros[i + 1])
            {
                // aux recebe o penúltimo numero
                aux = numeros[i];
                // penúltimo numero recebi o ultimo
                numeros[i] = numeros[i + 1];
                // ultimo recebe o penúltimo e é feita a troca entre eles
                numeros[i + 1] = aux;
            }
        }
    }

    printf("\nElementos do array após a ordenação:\n");
    for (i = 0; i < TAM; i++)
    {
        printf("%4d", numeros[i]);
    }

    printf("\n");
    return 0;
}
