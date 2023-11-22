#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

#define MAX 1000

void inicializar(struct lista *l)
{
    l->particao = 0;
}

int inserir_fim(struct lista *l, int valor)
{
    if (l->particao < MAX)
    {
        l->elementos[l->particao] = valor;
        l->particao++;
        return 1;
    }
    else
    {
        return 0;
    }
}

int inserir_inicio(struct lista *l, int valor)
{
    // movimentação de todos os valores para a direita
    // repetição do fim para o início
    int i;
    if (l->particao < MAX)
    {
        for (i = l->particao; i > 0; i--)
        {
            l->elementos[i] = l->elementos[i - 1];
        }

        l->elementos[0] = valor;
        l->particao++;

        return 1;
    }
    else
    {
        return 0;
    }
}

int reverso(struct lista *l)
{
    int i;

    for (i = l->particao - 1; i >= 0; i--)
    {
        printf("[%d] ", l->elementos[i]);
    }
    printf("\n");
}

void exibir_lista(struct lista *l)
{
    int i;
    for (i = 0; i < l->particao; i++)
    {
        printf("[%d]", l->elementos[i]);
    }
    printf("\n");
}

int concatenar(struct lista *l1, struct lista *l2)
{
    int i;
    if (l1->particao + l2->particao < MAX)
    {
        for (i = 0; i < l2->particao; i++)
        {
            inserir_fim(l1, l2->elementos[i]);
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

int inserir_Posição(struct lista *l, int valor, int posicao)
{

    int i;
    if (l->particao < MAX)
    {
        for (i = l->particao; i > posicao; i--)
        {
            l->elementos[i] = l->elementos[i - 1];
        }

        l->elementos[posicao] = valor;
        l->particao++;
        return 1;
    }
    else
    {
        return 0;
    }
}

int remover_Posição(struct lista *l, int posicao)
{
    if (posicao >= 0 && posicao < l->particao)
    {
        int i;

        for (i = posicao; i < l->particao - 1; i++)
        {
            l->elementos[i] = l->elementos[i + 1];
        }

        l->particao--;

        return 1;
    }
    else
    {
        return 0;
    }
}

int inserir_Ordem(struct lista *l, int valor)
{
    int i;

    if (l->particao < MAX)
    {
        for (i = l->particao; i > 0; i--)
        {
            if (l->elementos[i - 1] > valor)
            {
                l->elementos[i] = l->elementos[i - 1];
            }
            else
            {
                break;
            }
        }

        l->elementos[i] = valor;
        l->particao++;
        return 1;
    }
    else
    {
        return 0;
    }
}

int remover_inicio(struct lista *l)
{
    if (l->particao > 0)
    {
        int i;

        for (i = 0; i < l->particao - 1; i++)
        {
            l->elementos[i] = l->elementos[i + 1];
        }

        l->particao--;

        return 1;
    }
    else
    {
        return 0;
    }
}

int remover_fim(struct lista *l)
{
    if (l->particao > 0)
    {
        l->particao--;

        return 1;
    }
    else
    {
        return 0;
    }
}

int remover_Valor(struct lista *l, int valor)
{
    int i;
    int posicao = -1; // Variável para armazenar a posição do valor a ser removido

    // Encontra a posição do valor na lista
    for (i = 0; i < l->particao; i++)
    {
        if (l->elementos[i] == valor)
        {
            posicao = i;
            break;
        }
    }

    // Se a posição for válida, realiza a remoção
    if (posicao >= 0)
    {
        for (i = posicao; i < l->particao - 1; i++)
        {
            l->elementos[i] = l->elementos[i + 1];
        }

        l->particao--;

        return 1;
    }
    else
    {
        return 0;
    }
}

int procurar_Numero(struct lista *l, int numero)
{
    int i;
    int posicao = -1; // Variável para armazenar a posição do número procurado

    // Encontra a posição do número na lista
    for (i = 0; i < l->particao; i++)
    {
        if (l->elementos[i] == numero)
        {
            posicao = i;
            break;
        }
    }
    printf("a posiçaõ do numero é: %d \n", posicao);
    // Retorna a posição ou -1 se o número não for encontrado
    return posicao;
}

int calcular_Tamanho(struct lista *l)
{

    printf("o tamanho da lista é: %d \n", l->particao);
    return l->particao;
}
void calcular_Quadrado(struct lista *l)
{
    int i;

    // Calcula o quadrado dos números da lista
    for (i = 0; i < l->particao; i++)
    {
        l->elementos[i] = l->elementos[i] * l->elementos[i];
    }
}

int calcular_Somatorio(struct lista *l)
{
    int i;
    int somatorio = 0; // Variável para armazenar o somatório dos números

    // Calcula o somatório dos números da lista
    for (i = 0; i < l->particao; i++)
    {
        somatorio += l->elementos[i];
    }

    printf("o somatorio dos elementos da lista é: %d \n", somatorio);
    return somatorio;
}

int ehPrimo(int numero)
{
    if (numero <= 1)
    {
        return 0;
    }

    int i;
    for (i = 2; i <= numero / 2; i++)
    {
        if (numero % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int contarPrimos(struct lista *l)
{
    int contador = 0; // Variável para armazenar a contagem de números primos

    // Verifica se cada elemento da lista é primo
    int i;
    for (i = 0; i < l->particao; i++)
    {
        if (ehPrimo(l->elementos[i]))
        {
            contador++;
        }
    }

    printf("a quantidade de numeros primos na lsta é: %d \n", contador);
    return contador;
}
