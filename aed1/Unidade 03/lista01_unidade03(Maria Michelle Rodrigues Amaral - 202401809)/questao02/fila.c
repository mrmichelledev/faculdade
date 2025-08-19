#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila{
    unsigned int tamanho;
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

Fila* cria_fila(){
    Fila* filaInt = (Fila*) malloc(sizeof(Fila));

    if(filaInt != NULL)
        filaInt->tamanho = 0;

    return filaInt;  
}

void inicia_fila(Fila* filaInt){
    filaInt->tamanho = 0;
}

void libera_fila(Fila* filaInt){
    free(filaInt);
}

int tamanho_fila(Fila* filaInt){
    if(filaInt == NULL)
        return -1;

    return filaInt->tamanho;
}

int fila_vazia(Fila* filaInt){
    if(filaInt == NULL)
        return -1;

    return (filaInt->tamanho == 0);
}

int fila_cheia(Fila* filaInt){
    if(filaInt == NULL)
        return -1;

    return (filaInt->tamanho == MAX);
}

int insere_fila(Fila* filaInt, inteiros numInt){//push
    if(filaInt == NULL || filaInt->tamanho == MAX)
        return 0;
    
    filaInt->num[filaInt->tamanho] = numInt;
    filaInt->tamanho++;
    return 1;
}

int remove_fila(Fila* filaInt){
    unsigned int i;

    if(filaInt == NULL || filaInt->tamanho == 0)
        return 0;

    for(i = 0; i < (filaInt->tamanho - 1); i++)
        filaInt->num[i] = filaInt->num[i + 1];

    filaInt->tamanho--;
    return 1;
}

int consulta_primeiro_fila(Fila* filaInt, inteiros* numInt){
    if(filaInt == NULL)
        return 0;

    *numInt = filaInt->num[0];
    return 1;
}

void imprime_fila(Fila* filaInt){
    int i;

    printf("\n------------------------------\n");
    printf("Tamanho atual da fila: %d\n", filaInt->tamanho);
    printf("fila: [");

    for(i = 0; i < filaInt->tamanho; i++){
        printf("%d", filaInt->num[i]);

        if(i < filaInt->tamanho - 1)
            printf(", ");
    }
    printf("]\n");
    printf("------------------------------\n\n");
}