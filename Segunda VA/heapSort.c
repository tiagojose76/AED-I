#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void lerVet(int *p, int t)
{
    int i;
    for (i = 0; i < t; i++)
    {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &p[i]);
    }
}

void mostrarVet(int *p, int t)
{
    int i;
    for (i = 0; i < t; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
}

void heapSort(int *a, int n)
{
    int i, pai, filho, t;

    for (i = (n / 2) - 1; i >= 0; i--)
    {
        t = a[i];
        pai = i;
        filho = 2 * i + 1;

        while (filho < n)
        {
            if ((filho + 1 < n) && (a[filho + 1] > a[filho]))
                filho++;

            if (a[filho] > t)
            {
                a[pai] = a[filho];
                pai = filho;
                filho = 2 * pai + 1;
            }
            else
                break;
        }
        a[pai] = t;
    }

    for (i = n - 1; i >= 0; i--)
    {
        t = a[i];
        a[i] = a[0];
        a[0] = t;

        pai = 0;
        filho = 1;

        while (filho < i)
        {
            if ((filho + 1 < i) && (a[filho + 1] > a[filho]))
                filho++;

            if (a[filho] > a[pai])
            {
                t = a[pai];
                a[pai] = a[filho];
                a[filho] = t;

                pai = filho;
                filho = 2 * pai + 1;
            }
            else
                break;
        }
    }
}

int main()
{
    int *p, tam;

    printf("Quantidade de elementos do vetor? ");
    scanf("%d", &tam);

    p = (int *)malloc(tam * sizeof(int));

    if (p == NULL)
    {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    printf("\nDigite o conteudo do vetor:\n");
    lerVet(p, tam);

    printf("\nConteudo digitado para o vetor:\n");
    mostrarVet(p, tam);

    printf("\nOrdenando o vetor...\n");
    heapSort(p, tam);

    printf("\nConteudo do vetor ja ordenado:\n");
    mostrarVet(p, tam);

    free(p);

    return 0;
}