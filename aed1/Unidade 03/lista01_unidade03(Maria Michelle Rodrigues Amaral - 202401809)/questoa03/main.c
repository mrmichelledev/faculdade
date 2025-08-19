#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    int op, valor, indice;
    inteiros num; 
    Lista* listaInt = NULL;


    do{
        clear();
        printf("........................................\n");
        printf(".            MENU PRINCIPAL            .\n");
        printf("........................................\n");
        printf(". 1. Criacao da lista                  .\n");
        printf(". 2. Liberacao da lista                .\n");
        printf(". 3. Tamanho da lista                  .\n");
        printf(". 4. Verificacao de lista vazia        .\n");
        printf(". 5. Verificacao de lista cheia        .\n");
        printf(". 6. Insercao no inicio da lista       .\n");
        printf(". 7. Insercao no meio da lista         .\n");
        printf(". 8. Insercao no fim da lista          .\n");
        printf(". 9. Remocao no inicio da lista        .\n");
        printf(". 10. Remocao no meio da lista         .\n");
        printf(". 11. Remocao no fim da lista          .\n");
        printf(". 12. Consulta elemento - valor        .\n");
        printf(". 13. Consulta elemento - indice       .\n");
        printf(". 14. Impressao da lista               .\n");
        printf(". 0. Sair                              .\n");
        printf("........................................\n");
        printf(CINZA "Escolha uma opcao: " RESET);
        scanf("%d", &op);

        switch(op){
            case 1: 
                listaInt = cria_lista();
                printf(VERDE "\nlista criada com sucesso!\n\n" RESET);
                proximo();
                break;
            
            case 2:
                libera_lista(listaInt);
                printf(VERDE "\nlista liberada!\n\n" RESET);
                proximo();
                break;

            case 3:
                printf( "\nTamanho da lista: %d\n\n", tamanho_lista(listaInt));
                proximo();
                break;

            case 4:
                if(lista_vazia(listaInt))
                    printf(RED "\nlista vazia!\n\n" RESET);
                else
                    printf(VERDE "\nExistem elementos armazenados na lista.\n\n" RESET);
                
                proximo();
                break;
            
            case 5:
                if(lista_cheia(listaInt))
                    printf(RED "\nlista cheia!\n\n" RESET);
                else
                    printf(VERDE "\nlista ainda nao atingiu a capacidade maxima.\n\n" RESET);

                proximo();
                break;

            case 6:
                printf("\nDigite um numero inteiro para ser inserido no inicio da lista: ");
                scanf("%d", &num);
                insere_inicio_lista(listaInt, num);
                printf(VERDE "\nNumero inserido!\n\n" RESET);
                proximo();
                break;

            case 7:
                printf("\nDigite um numero inteiro para ser inserido no inicio da lista: ");
                scanf("%d", &num);
                insere_meio_lista(listaInt, num);
                printf(VERDE "\nNumero inserido!\n\n" RESET);
                proximo();
                break;

            case 8:
                printf("\nDigite um numero inteiro para ser inserido no meio da lista: ");
                scanf("%d", &num);
                insere_fim_lista(listaInt, num);
                printf(VERDE "\nNumero inserido!\n\n" RESET);
                proximo();
                break;
            
            case 9:
                remove_inicio_lista(listaInt);
                printf(VERDE "\nInicio da lista liberado!\n\n" RESET);
                proximo();
                break;
            
            case 10:
                remove_meio_lista(listaInt);
                printf(VERDE "\nMeio da lista liberado!\n\n" RESET);
                proximo();
                break;
            
            case 11:
                remove_fim_lista(listaInt);
                printf(VERDE "\nFim da lista liberado!\n\n" RESET);
                proximo();
                break;

            case 12:
                printf("Digite o valor que deseja encontrar: ");
                scanf("%d", &valor);

                if(consulta_elemento_valor(listaInt, valor) == -1)
                    printf(RED "A lista esta vazia ou nao foi inicializada.\n" RESET);


                printf("\nValor indicado esta na posicao: %d\n\n", consulta_elemento_valor(listaInt, valor));
                
                proximo();
                break;
            
            case 13:
                printf("Digite o indice do elemento que deseja encontrar: ");
                scanf("%d", &indice);
                if(consulta_elemento_indice(listaInt, &num, indice) == -1)
                    printf(RED "A lista esta vazia ou nao foi inicializada.\n" RESET);
                
                printf("\nValor indicado pelo indice: %d\n\n", num);
                
                proximo();
                break;
            
            case 14:
                imprime_lista(listaInt);
                proximo();
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;
            
            default:
                printf(RED "Opção inválida. Tente novamente.\n\n" RESET);
                SLEEP(1);
        }

    } while(op != 0);

    return 0;
}