#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

#define MAX 1000

struct lista
{
        int elementos[MAX];
        int particao;
};

void inicializar(struct lista *l);

int inserir_fim(struct lista *l, int valor);
int inserir_inicio(struct lista *l, int valor);
void exibir_lista(struct lista *l);
int concatenar(struct lista *l1, struct lista *l2);
int inserir_Posição(struct lista *l, int valor, int posicao);
int inserir_Ordem(struct lista *l, int valor);
int reverso(struct lista *l);
int remover_inicio(struct lista *l);
int remover_fim(struct lista *l);
int remover_Posição(struct lista *l, int posicao);
int remover_Valor(struct lista *l, int valor);
int procurar_Numero(struct lista *l, int numero);
int calcular_Somatorio(struct lista *l);
int calcular_Tamanho(struct lista *l);
void calcular_Quadrado(struct lista *l);
int contarPrimos(struct lista *l);

#endif
