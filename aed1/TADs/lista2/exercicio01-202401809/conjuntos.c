#include <stdio.h>
#include <stdlib.h>
#include "conjuntos.h"
#include <unistd.h>
#include <ctype.h>

int main(){
    Conjunto* c;
    int elemento, op;

    do{
        menu();

        printf("Escolha uma opção: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                clear();
                 
                //criando o conjunto
                if(criaConjunto(&c) == 1) printf(VERDE "SUCESSO\n" RESET);
                else printf(RED "FALHA\n" RESET);
            break;

            case 2:
                //verifica se o conjunto esta vazio
                if (conjuntoVazio(c) == 1) printf(VERDE "TRUE\n" RESET);
                else printf(RED "FALSE\n" RESET);
            break;

            case 3:
                //inserindo elemento
                printf("Insira um numero inteiro para ser adicionado ao conjunto: \n");
                scanf("%d", &elemento);

                if (insereElementoConjunto(elemento, c) == 1) printf("SUCESSO\n");
                else printf("FALHA\n");
            break;

            case 4:
                //excluindo elementos
                printf("Insira um numero inteiro para ser excluido do conjunto: \n");
                scanf("%d", &elemento);

                if (excluirElementoConjunto(elemento, c) == 1) printf("SUCESSO\n");
                else printf("FALHA\n");
            break;

            case 5:
                printf("Mostrando o conjunto: ");
                mostraConjunto(c);

            break;

            case 6:
                //tamanho do conjunto
                printf("%d", tamanhoConjunto(c));
            break;

            case 7:
            break;

            case 8:
            break;

            case 9:
            break;

            case 10:
            break;

            case 0:
            break;
        }

    }while (op != 0);

    return 0;
}
