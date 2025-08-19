#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
    int op;
    inteiros num; 
    Fila* filaInt = NULL;


    do{
        clear();
        printf(".................................\n");
        printf(".         MENU PRINCIPAL         .\n");
        printf(".................................\n");
        printf(". 1. Criacao da fila            .\n");
        printf(". 2. Liberacao da fila          .\n");
        printf(". 3. Tamanho da fila            .\n");
        printf(". 4. Verificacao de fila vazia  .\n");
        printf(". 5. Verificacao de fila cheia  .\n");
        printf(". 6. Insercao na fila           .\n");
        printf(". 7. Remocao na fila            .\n");
        printf(". 8. Consulta do inicio da fila .\n");
        printf(". 9. Impressao da fila          .\n");
        printf(". 0. Sair                        .\n");
        printf(".................................\n");
        printf(CINZA "Escolha uma opcao: " RESET);
        scanf("%d", &op);

        switch(op){
            case 1: 
                filaInt = cria_fila();
                printf(VERDE "\nfila criada com sucesso!\n\n" RESET);
                proximo();
                break;
            
            case 2:
                libera_fila(filaInt);
                printf(VERDE "\nfila liberada!\n\n" RESET);
                proximo();
                break;

            case 3:
                printf( "\nTamanho da fila: %d\n\n", tamanho_fila(filaInt));
                proximo();
                break;

            case 4:
                if(fila_vazia(filaInt))
                    printf(RED "\nfila vazia!\n\n" RESET);
                else
                    printf(VERDE "\nExistem elementos armazenados na fila.\n\n" RESET);
                
                proximo();
                break;
            
            case 5:
                if(fila_cheia(filaInt))
                    printf(RED "\nfila cheia!\n\n" RESET);
                else
                    printf(VERDE "\nfila ainda nao atingiu a capacidade maxima.\n\n" RESET);

                proximo();
                break;

            case 6:
                printf("\nDigite um numero inteiro para ser inserido: ");
                scanf("%d", &num);
                insere_fila(filaInt, num);
                printf(VERDE "\nNumero inserido!\n\n" RESET);
                proximo();
                break;

            case 7:
                remove_fila(filaInt);
                printf(VERDE "\nInicio liberado!\n\n" RESET);
                proximo();
                break;
            
            case 8:
                if(consulta_primeiro_fila(filaInt, &num))
                    printf("\nInicio da fila: %d\n\n", num);
                else
                    printf(RED "A fila esta vazia ou nao foi inicializada.\n" RESET);
                
                proximo();
                break;
            
            case 9:
                imprime_fila(filaInt);
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