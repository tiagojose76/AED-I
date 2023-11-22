#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

int main(int argc, char *argv)
{

    // declaração da lista
    struct lista *l1, *l2;
    l1 = (struct lista *)malloc(sizeof(struct lista));
    l2 = (struct lista *)malloc(sizeof(struct lista));
    inicializar(l1);
    inicializar(l2);

    int opcao, valor, posicao;
    int continuar = 1;

    while (continuar)
    {
        printf("Escolha uma opção:\n");
        printf("1. Inserir no início da lista 1\n");
        printf("2. Inserir no início da lista 2\n");
        printf("3. Inserir no fim da lista 1\n");
        printf("4. Inserir no fim da lista 2\n");
        printf("5. Inserir na posição lista 1\n");
        printf("6. Inserir na posição lista 2\n");
        printf("7. Inserir em ordem lista 1\n");
        printf("8. Inserir em ordem lista 2\n");
        printf("9. Exibir lista 1\n");
        printf("10. Exibir lista 2\n");
        printf("11. reverso lista 1\n");
        printf("12. reverso lista 2\n");
        printf("13. Remover do início lista 1\n");
        printf("14. Remover do início lista 2\n");
        printf("15. Remover do fim lista 1\n");
        printf("16. Remover do fim lista 2\n");
        printf("17. Remover de uma posição lista 1\n");
        printf("18. Remover de uma posição lista 2\n");
        printf("19. Remover por valor lista 1\n");
        printf("20. Remover por valor lista 2\n");
        printf("21. Procurar na lista 1\n");
        printf("22. Procurar na lista 2\n");
        printf("23. somatório dos elementos da lista 1\n");
        printf("24. somatório dos elementos da lista 2\n");
        printf("25. tamanho da lista 1\n");
        printf("26. tamanho da lista 2\n");
        printf("27. quadrado dos elementos da lista 1\n");
        printf("28. quadrado dos elementos da lista 2\n");
        printf("29. números primos na lista 1\n");
        printf("30. números primos na lista 2\n");
        printf("31. Sair\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o valor a ser inserido no início da lista 1: ");
            scanf("%d", &valor);
            if (inserir_inicio(l1, valor))
            {
                printf("Valor inserido no início da lista 1\n");
            }
            else
            {
                printf("Não foi possível inserir o valor\n");
            }
            break;
        case 2:
            printf("Digite o valor a ser inserido no início da lista 2: ");
            scanf("%d", &valor);
            if (inserir_inicio(l2, valor))
            {
                printf("Valor inserido no início da lista 2\n");
            }
            else
            {
                printf("Não foi possível inserir o valor\n");
            }
            break;
        case 3:
            printf("Digite o valor a ser inserido no fim da lista 1: ");
            scanf("%d", &valor);
            if (inserir_fim(l1, valor))
            {
                printf("Valor inserido no fim da lista 1\n");
            }
            else
            {
                printf("Não foi possível inserir o valor\n");
            }
            break;
        case 4:
            printf("Digite o valor a ser inserido no fim da lista 2: ");
            scanf("%d", &valor);
            if (inserir_fim(l2, valor))
            {
                printf("Valor inserido no fim da lista 2\n");
            }
            else
            {
                printf("Não foi possível inserir o valor\n");
            }
            break;
        case 5:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);
            printf("Digite a posição: ");
            scanf("%d", &posicao);
            if (inserir_Posição(l1, valor, posicao))
            {
                printf("Valor inserido na posição %d da lista 1\n", posicao);
            }
            else
            {
                printf("Não foi possível inserir o valor\n");
            }
            break;
        case 6:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);
            printf("Digite a posição: ");
            scanf("%d", &posicao);
            if (inserir_Posição(l2, valor, posicao))
            {
                printf("Valor inserido na posição %d da lista 1\n", posicao);
            }
            else
            {
                printf("Não foi possível inserir o valor\n");
            }
            break;
        case 7:
            printf("Digite o valor a ser inserido em ordem na lista 1: ");
            scanf("%d", &valor);
            if (inserir_Ordem(l1, valor))
            {
                printf("Valor inserido em ordem na lista 1\n");
            }
            else
            {
                printf("Não foi possível inserir o valor\n");
            }
            break;
        case 8:
            printf("Digite o valor a ser inserido em ordem na lista 2: ");
            scanf("%d", &valor);
            if (inserir_Ordem(l2, valor))
            {
                printf("Valor inserido em ordem na lista 2\n");
            }
            else
            {
                printf("Não foi possível inserir o valor\n");
            }
            break;
        case 9:

            printf("Lista 1: ");
            exibir_lista(l1);
            break;
        case 10:
            printf("Lista 2: ");
            exibir_lista(l2);
            break;
        case 11:
            printf("Lista 1 reversa: ");
            reverso(l1);
            break;
        case 12:
            printf("Lista 2 reversa: ");
            reverso(l2);
            break;
        case 13:
            if (remover_inicio(l1))
            {
                printf("Valor removido do início da lista 1\n");
            }
            else
            {
                printf("Não foi possível remover o valor\n");
            }
            break;
        case 14:
            if (remover_inicio(l2))
            {
                printf("Valor removido do início da lista 2\n");
            }
            else
            {
                printf("Não foi possível remover o valor\n");
            }
            break;
        case 15:
            if (remover_fim(l1))
            {
                printf("Valor removido do fim da lista 1\n");
            }
            else
            {
                printf("Não foi possível remover o valor\n");
            }
            break;
        case 16:
            if (remover_fim(l2))
            {
                printf("Valor removido do fim da lista 2\n");
            }
            else
            {
                printf("Não foi possível remover o valor\n");
            }
            break;
        case 17:
            printf("Digite a posição a ser removida: ");
            scanf("%d", &posicao);
            if (remover_Posição(l1, posicao))
            {
                printf("Valor removido da posição %d da lista 1\n", posicao);
            }
            else
            {
                printf("Não foi possível remover o valor\n");
            }
            break;
        case 18:
            printf("Digite a posição a ser removida: ");
            scanf("%d", &posicao);
            if (remover_Posição(l2, posicao))
            {
                printf("Valor removido da posição %d da lista 2\n", posicao);
            }
            else
            {
                printf("Não foi possível remover o valor\n");
            }
            break;
        case 19:
            printf("Digite o valor a ser removido: ");
            scanf("%d", &valor);
            if (remover_Valor(l1, valor))
            {
                printf("Valor removido da lista 1\n");
            }
            else
            {
                printf("Não foi possível remover o valor\n");
            }
            break;

        case 20:
            printf("Digite o valor a ser removido: ");
            scanf("%d", &valor);
            if (remover_Valor(l2, valor))
            {
                printf("Valor removido da lista 2\n");
            }
            else
            {
                printf("Não foi possível remover o valor\n");
            }
            break;
        case 21:
            printf("Digite o número a ser procurado: ");
            scanf("%d", &valor);
            posicao = procurar_Numero(l1, valor);
            if (posicao >= 0)
            {
                printf("O número %d está na posição %d da lista 1\n", valor, posicao);
            }
            else
            {
                printf("O número %d não está na lista 1\n", valor);
            }
            break;
        case 22:
            printf("Digite o número a ser procurado: ");
            scanf("%d", &valor);
            posicao = procurar_Numero(l2, valor);
            if (posicao >= 0)
            {
                printf("O número %d está na posição %d da lista 2\n", valor, posicao);
            }
            else
            {
                printf("O número %d não está na lista 1\n", valor);
            }
            break;

        case 23:
            calcular_Somatorio(l1);
            break;

        case 24:
            calcular_Somatorio(l2);
            break;

        case 25:
            calcular_Tamanho(l1);
            break;

        case 26:
            calcular_Tamanho(l2);
            break;

        case 27:
            calcular_Quadrado(l1);
            printf("Os elementos da lista 1 ao quadrado\n");
            break;

        case 28:
            calcular_Quadrado(l2);
            printf("Os elementos da lista 2 ao quadrado\n");
            break;

        case 29:
            contarPrimos(l1);
            break;

        case 30:
            contarPrimos(l2);
            break;
        case 31:
            continuar = 0;
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
        printf("\n");
    }

    return 0;
}
