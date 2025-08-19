1#include <stdio.h>
#include <stdlib.h>
#include "pilhaa.h"

int main(){
    int op;
    elemento vetNum, vetNum2; 
    Pilha* pilha1 = NULL;
    Pilha* pilha2 = NULL;

    do{
        clear();
        printf("........................................\n");
        printf(".            MENU PRINCIPAL            .\n");
        printf("........................................\n");
        printf(". 1. Criacao da pilha                  .\n");
        printf(". 2. Liberacao da pilha                .\n");
        printf(". 3. Tamanho da pilha                  .\n");
        printf(". 4. Verificacao de pilha vazia        .\n");
        printf(". 5. Verificacao de pilha cheia        .\n");
        printf(". 6. Insercao na pilha                 .\n");
        printf(". 7. Remocao na pilha                  .\n");
        printf(". 8. Consulta topo                     .\n");
        printf(". 9. Impressao                        .\n");
        printf(". 0. Sair                              .\n");
        printf("........................................\n");
        printf(CINZA "Escolha uma opcao: " RESET);
        scanf("%d", &op);

        switch(op){
            case 1: 
                pilha1 = cria_pilha();
                pilha2 = cria_pilha();
                printf(VERDE "\nPilha criada com sucesso!\n\n" RESET);

                proximo();
                break;
            
            case 2:
                libera_pilha(pilha1);
                printf(VERDE "\nPilha liberada!\n\n" RESET);

                proximo();
                break;

            case 3:
                printf( "\nTamanho da pilha: %d\n\n", tamanho_pilha(pilha1));

                proximo();
                break;

            case 4:
                if(pilha_vazia(pilha1))
                    printf(RED "\nPilha vazia!\n\n" RESET);
                else
                    printf(VERDE "\nExistem elementos armazenados na pilha.\n\n" RESET);

                proximo();
                break;
            
            case 5:
                if(pilha_cheia(pilha1))
                    printf(RED "\nPilha cheia!\n\n" RESET);
                else
                    printf(VERDE "\nPilha ainda nao atingiu a capacidade maxima.\n\n" RESET);

                proximo();
                break;

            case 6:
                printf("\nDigite um numero inteiro para ser inserido: ");
                scanf("%d", &vetNum);
                insere_pilha(pilha1, vetNum);
                printf(VERDE "\nNumero inserido!\n\n" RESET);
                inverte_pilha(pilha1, pilha2);

                proximo();
                break;

            case 7:
                remove_pilha(pilha1);
                printf(VERDE "\nTopo removido!\n\n" RESET);

                proximo();
                break;
            
            case 8:
                if(consulta_topo_pilha(pilha1, &vetNum) && consulta_topo_pilha(pilha2, &vetNum2)){
                    printf("\nTopo pilha1: %d\n", vetNum);
                    printf("\nTopo pilha2: %d\n\n", vetNum2);
                } else {
                    printf(RED "A pilha esta vazia ou nao foi inicializada.\n" RESET);
                }

                proximo();
                break;

            case 9:
                imprime_pilha(pilha1, pilha2);
                proximo();
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;
            
            default:
                printf(RED "Opção inválida. Tente novamente.\n\n" RESET);
        }

    } while(op != 0);

    return 0;
}