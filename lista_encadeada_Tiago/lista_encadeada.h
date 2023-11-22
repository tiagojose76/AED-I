#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

typedef int tipo;

typedef struct no
{
        int valor;
        struct no *proximo;
} no;

typedef no *lista;

lista inserir_fim(lista l, int valor);
lista inserir_inicio(lista l, int valor);
lista inserir_posicao(lista l, int valor, int posicao);
lista inserir_ordem(lista l, int valor);
lista remover_inicio(lista l);
lista remover_fim(lista l);
lista remover_posicao(lista l, int posicao);
lista remover_valor(lista l, int valor);
lista procurar_valor(lista l, int valor);
lista somatorio_lista(lista l);
lista quadrado_lista(lista l);
lista tamanho_lista(lista l);
lista contar_primos(lista l);
void exibir_lista(lista l);
void exibir_lista_r(lista l);
lista concatenar(lista l1, lista l2);

#endif
