#include <stdio.h>
#include <stdlib.h>
#include "inteiros.h"

int main(){
    int op;
    inteiros num; 
    Pilha* pilhaInt = NULL;

    do{
        clear();
        printf(".................................\n");
        printf(".         MENU PRINCIPAL         .\n");
        printf(".................................\n");
        printf(". 1. Criacao da pilha            .\n");
        printf(". 2. Liberacao da pilha          .\n");
        printf(". 3. Tamanho da pilha            .\n");
        printf(". 4. Verificacao de pilha vazia  .\n");
        printf(". 5. Verificacao de pilha cheia  .\n");
        printf(". 6. Insercao na pilha           .\n");
        printf(". 7. Remocao na pilha            .\n");
        printf(". 8. Consulta do topo da pilha   .\n");
        printf(". 9. Impressao da pilha          .\n");
        printf(". 0. Sair                        .\n");
        printf(".................................\n");
        printf(CINZA "Escolha uma opcao: " RESET);
        scanf("%d", &op);

        switch(op){
            case 1: 
                pilhaInt = cria_pilha();
                printf(VERDE "\nPilha criada com sucesso!\n\n" RESET);

                proximo();
                break;
            
            case 2:
                libera_pilha(pilhaInt);
                printf(VERDE "\nPilha liberada!\n\n" RESET);

                proximo();
                break;

            case 3:
                printf( "\nTamanho da pilha: %d\n\n", tamanho_pilha(pilhaInt));

                proximo();
                break;

            case 4:
                if(pilha_vazia(pilhaInt))
                    printf(RED "\nPilha vazia!\n\n" RESET);
                else
                    printf(VERDE "\nExistem elementos armazenados na pilha.\n\n" RESET);

                proximo();
                break;
            
            case 5:
                if(pilha_cheia(pilhaInt))
                    printf(RED "\nPilha cheia!\n\n" RESET);
                else
                    printf(VERDE "\nPilha ainda nao atingiu a capacidade maxima.\n\n" RESET);

                proximo();
                break;

            case 6:
                printf("\nDigite um numero inteiro para ser inserido: ");
                scanf("%d", &num);
                insere_pilha(pilhaInt, num);
                printf(VERDE "\nNumero inserido!\n\n" RESET);

                proximo();
                break;

            case 7:
                remove_pilha(pilhaInt);
                printf(VERDE "\nTopo removido!\n\n" RESET);

                proximo();
                break;
            
            case 8:
                if(consulta_topo_pilha(pilhaInt, &num))
                    printf("\nTopo da pilha: %d\n\n", num);
                else
                    printf(RED "A pilha esta vazia ou nao foi inicializada.\n" RESET);

                proximo();
                break;
            
            case 9:
                imprime_pilha(pilhaInt);
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