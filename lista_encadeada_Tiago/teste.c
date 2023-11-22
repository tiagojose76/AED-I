#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

int main(int argc, char *argv)
{

    // declaração da lista
    lista l1 = NULL;

    int opcao, valor, posicao;
    int continuar = 1;


    while (continuar)
    {

        printf("Escolha uma opção:\n");
        printf("1. Inserir no início da lista \n");
        printf("2. Inserir no fim da lista \n");
        printf("3. Inserir na posição lista \n");
        printf("4. Inserir em ordem lista \n");
        printf("5. Exibir lista \n");
        printf("6. reverso lista \n");
        printf("7. Remover do início lista \n");
        printf("8. Remover do fim lista \n");
        printf("9. Remover de uma posição lista \n");
        printf("10. Remover por valor lista \n");
        printf("11. Procurar na lista \n");
        printf("12. somatório dos elementos da lista \n");
        printf("13. tamanho da lista \n");
        printf("14. quadrado dos elementos da lista \n");
        printf("15. números primos na lista \n");
        printf("16. Sair\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o valor a ser inserido no início da lista: ");
            scanf("%d", &valor);
            l1 = inserir_inicio(l1, valor); // atribuir o resultado à lista
            if (l1 != NULL)
            {
                printf("Valor inserido no início da lista\n");
            }
            else
            {
                printf("Não foi possível inserir o valor\n");
            }
            break;

        case 2:
            printf("Digite o valor a ser inserido no fim da lista : ");
            scanf("%d", &valor);
            if (inserir_fim(l1, valor))
            {
                printf("Valor inserido no fim da lista \n");
            }
            else
            {
                printf("Não foi possível inserir o valor\n");
            }
            break;
        case 3:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);
            printf("Digite a posição: ");
            scanf("%d", &posicao);
            l1 = inserir_posicao(l1, valor, posicao);
            if (l1 != NULL)
            {
                printf("Valor inserido na posição %d da lista \n", posicao);
            }
            else
            {
                printf("Não foi possível inserir o valor\n");
            }
            break;
        case 4:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);
            l1 = inserir_ordem(l1, valor);
            if (l1 != NULL)
            {
                printf("Valor inserido em ordem \n");
            }
            else
            {
                printf("Não foi possível inserir o valor\n");
            }
            break;

        case 5:

            exibir_lista(l1);
            break;
        case 6:

            exibir_lista_r(l1);
            break;
        case 7:
            l1 = remover_inicio(l1);
            
            break;
        case 8:
            l1 = remover_fim(l1);
        
            break;
        case 9:
            printf("Digite a posição a ser removida: ");
            scanf("%d", &posicao);
            l1 = remover_posicao(l1, posicao);
            if (remover_posicao(l1, posicao))
            {
                printf("Valor removido da posição %d da lista \n", posicao);
            }
            else
            {
                printf("Não foi possível remover o valor\n");
            }
            break;
        case 10:
            printf("Digite o valor a ser removido: ");
            scanf("%d", &valor);
            l1 = remover_valor(l1, valor);
            if (remover_valor(l1, valor))
            {
                printf("Valor removido \n");
            }
            else
            {
                printf("Não foi possível remover o valor\n");
            }
            break;
        case 11:
            printf("Digite o número a ser procurado: ");
            scanf("%d", &valor);

            if (procurar_valor(l1, valor))
            {
                printf("Valor encontrado na lista \n");
            }
            else
            {
                printf("Não foi possível encontrar o valor\n");
            }
            break;
        case 12:
            somatorio_lista(l1);
            break;
        case 13:
            tamanho_lista(l1);
            break;
        case 14:
            quadrado_lista(l1);
            break;
        case 15:
            contar_primos(l1);
        case 16:
            continuar = 0;
            break;

        default:
            printf("Opção inválida\n");
            break;
        }
        printf("\n");
    }

    exit(0);
}
