#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

lista inserir_inicio(lista l, int valor)
{
    // Aloca espaço para o novo nó
    lista novo = (lista)malloc(sizeof(no));
    // inicializan o valor do novo a parir do parâmetro passado para função
    novo->valor = valor;
    // O próximo do novo aponta para o inicio da lista, ou seja, o antigo início passa a ser o segundo elemento (proximo do primeiro)
    novo->proximo = l;
    // Atualização da lista, através do retorno do ponteiro do novo início
    return novo;
}
lista inserir_fim(lista l, int valor)
{
    lista aux = l;
    if (l == NULL)
    {
        return inserir_inicio(l, valor);
    }

    while (aux->proximo != NULL)
    {
        aux = aux->proximo;
    }
    // aqui aux == último
    lista novo = (lista)malloc(sizeof(no));
    novo->valor = valor;
    novo->proximo = NULL;

    // último aponte para o novo
    aux->proximo = novo;
    return l;
}
lista inserir_posicao(lista l, int valor, int posicao)
{
    lista aux = l;
    lista anterior = NULL;
    int cont = 0;

    if (l == NULL || posicao == 0)
    {
        return inserir_inicio(l, valor);
    }

    while (cont < posicao && aux != NULL)
    {
        anterior = aux;
        aux = aux->proximo;
        cont++;
    }

    if (cont < posicao)
    {
        printf("Posicao invalida\n");
        return l;
    }

    lista novo = (lista)malloc(sizeof(no));
    novo->valor = valor;
    novo->proximo = aux;

    if (anterior != NULL)
    {
        anterior->proximo = novo;
    }
    else
    {
        l = novo;
    }

    return l;
}

lista inserir_ordem(lista l, int valor)
{
    lista novo = (lista)malloc(sizeof(no));
    novo->valor = valor;
    novo->proximo = NULL;

    if (l == NULL || valor < l->valor)
    {
        novo->proximo = l;
        return novo;
    }

    lista aux = l;
    while (aux->proximo != NULL && valor > aux->proximo->valor)
    {
        aux = aux->proximo;
    }

    novo->proximo = aux->proximo;
    aux->proximo = novo;

    return l;
}
void exibir_lista(lista l)
{
    lista aux = l;
    for (aux = l; aux != NULL; aux = aux->proximo)
    {
        printf("[%d]", aux->valor);
    }
    printf("\n");
}
void exibir_lista_r(lista l)
{
    // caso base
    if (l == NULL)
    {
        printf("\n");
        return;
    }
    // caso recursivo

    exibir_lista_r(l->proximo);
    printf("[%d]", l->valor);
}

lista remover_inicio(lista l)
{
    if (l == NULL)
        return NULL;

    lista aux = l->proximo;
    free(l);

    return aux;
}

lista remover_fim(lista l) {
    if(l==NULL)
        return NULL;

    if(l->proximo == NULL)
       return remover_inicio(l);

    lista aux = l;
    while(aux->proximo->proximo != NULL) {
        aux = aux->proximo;
    }
    free(aux->proximo);
    aux->proximo = NULL;
    return l;


}
lista remover_posicao(lista l, int posicao)
{
    if (l == NULL)
    {
        printf("Lista vazia\n");
        return l;
    }

    if (posicao == 0)
    {
        lista aux = l;
        l = l->proximo;
        free(aux);
        return l;
    }

    lista aux = l;
    lista anterior = NULL;
    int cont = 0;

    while (aux != NULL && cont < posicao)
    {
        anterior = aux;
        aux = aux->proximo;
        cont++;
    }

    if (aux == NULL)
    {
        printf("Posicao invalida\n");
        return l;
    }

    if (anterior != NULL)
    {
        anterior->proximo = aux->proximo;
    }
    else
    {
        l = aux->proximo;
    }

    free(aux);
    return l;
}

lista remover_valor(lista l, int valor)
{
    if (l == NULL)
    {
        printf("Lista vazia\n");
        return l;
    }

    if (valor == l->valor)
    {
        lista aux = l;
        l = l->proximo;
        free(aux);
        return l;
    }

    lista aux = l;
    lista anterior = NULL;

    while (aux != NULL && valor != aux->valor)
    {
        anterior = aux;
        aux = aux->proximo;
    }

    if (aux == NULL)
    {
        printf("Valor não encontrado\n");
        return l;
    }

    if (anterior != NULL)
    {
        anterior->proximo = aux->proximo;
    }
    else
    {
        l = aux->proximo;
    }

    free(aux);
    return l;
}

lista procurar_valor(lista l, int valor)
{
    lista aux = l;
    int posicao = 0;

    while (aux != NULL)
    {
        if (valor == aux->valor)
        {
            printf("Esse valor está na posição %d\n", posicao + 1);
            return aux;
        }

        aux = aux->proximo;
        posicao++;
    }

    printf("Valor não encontrado\n");
    return NULL;
}

lista somatorio_lista(lista l)
{
    lista aux = l;
    int somatorio = 0;

    while (aux != NULL)
    {
        somatorio += aux->valor;
        aux = aux->proximo;
    }
    printf("o somatorio dos elementos da lista é: %d \n", somatorio);
}

lista quadrado_lista(lista l)
{
    lista aux = l;

    while (aux != NULL)
    {
        aux->valor = aux->valor * aux->valor;
        aux = aux->proximo;
    }
}

lista tamanho_lista(lista l)
{
    lista aux = l;
    int tamanho = 0;

    while (aux != NULL)
    {
        tamanho++;
        aux = aux->proximo;
    }
    printf("Esse é o tamanho da lista %d", tamanho);
}

int eh_primo(int num)
{
    if (num <= 1)
    {
        return 0;
    }

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

lista contar_primos(lista l)
{
    lista aux = l;
    int count = 0;

    while (aux != NULL)
    {
        if (eh_primo(aux->valor))
        {
            count++;
        }
        aux = aux->proximo;
    }
    printf("Essa é a quantidade de números primos: %d", count);
}
