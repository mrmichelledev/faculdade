#include <stdio.h>
#include <stdlib.h>
#include "inteiros.h"

struct pilha{
    unsigned int quant;
    inteiros num[MAX];
};

//limpa tela
void clear(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void proximo(){
    printf(AZUL "Pressione ENTER para sair...\n" RESET);
    getchar();
    getchar();
    SLEEP(0.5);
}


Pilha* cria_pilha(){
    Pilha* pilhaInt = (Pilha*) malloc(sizeof(Pilha));

    if(pilhaInt != NULL)
        pilhaInt->quant = 0;

    return pilhaInt;  
}

void inicia_pilha(Pilha* pilhaInt){
    pilhaInt->quant = 0;
}

void libera_pilha(Pilha* pilhaInt){
    free(pilhaInt);
}

int tamanho_pilha(Pilha* pilhaInt){
    if(pilhaInt == NULL)
        return -1;

    return pilhaInt->quant;
}

int pilha_vazia(Pilha* pilhaInt){
    if(pilhaInt == NULL)
        return -1;

    return (pilhaInt->quant == 0);
}

int pilha_cheia(Pilha* pilhaInt){
    if(pilhaInt == NULL)
        return -1;

    return (pilhaInt->quant == MAX);
}

int insere_pilha(Pilha* pilhaInt, inteiros numInt){//push
    if(pilhaInt == NULL || pilhaInt->quant == MAX)
        return 0;
    
    pilhaInt->num[pilhaInt->quant] = numInt;
    pilhaInt->quant++;
    return 1;
}

int remove_pilha(Pilha* pilhaInt){ //pop
    if(pilhaInt == NULL || pilhaInt->quant == 0)
        return 0;

    pilhaInt->quant--;
    return 1;
}

int consulta_topo_pilha(Pilha* pilhaInt, inteiros* numInt){
    if(pilhaInt == NULL || pilhaInt->quant == 0)
        return 0;

    *numInt = pilhaInt->num[pilhaInt->quant-1];
    return 1;
}

void imprime_pilha(Pilha* pilhaInt){
    int i;

    printf("\n------------------------------\n");
    printf("Tamanho atual da pilha: %d\n", pilhaInt->quant);
    printf("Pilha: [");

    for(i = pilhaInt->quant - 1; i >= 0; i--){
        printf("%d", pilhaInt->num[i]);

        if(i > 0)
            printf(", ");
    }
    printf("]\n");
    printf("------------------------------\n\n");
}