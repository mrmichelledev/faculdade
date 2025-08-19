#include <stdio.h>
#include <stdlib.h>
#include "pilhaa.h"

struct pilha{
    int topo;
    elemento vet[MAX];
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
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));

    if(p != NULL){
        inicia_pilha(p);
    }

    return p;
}

void inicia_pilha(Pilha* p){
    p->topo = 0;
}

void libera_pilha(Pilha* pilha1){
    free(pilha1);
}

int tamanho_pilha(Pilha* pilha1){
    if(pilha1 == NULL){
        return -1;
    }

    return pilha1->topo;
}

int pilha_vazia(Pilha* pilha1){
    if(pilha1 == NULL){
        return -1;
    }

    return (pilha1->topo == 0);
}

int pilha_cheia(Pilha* pilha1){
    if(pilha1 == NULL){
        return -1;
    }

    return (pilha1->topo == MAX);
}

int insere_pilha(Pilha* pilha1, elemento vetNum){ //push
    if(pilha1 == NULL || pilha1->topo == MAX)
        return 0;

    //o vetor recebe o valor de vetNum como seu elemento
    pilha1->vet[pilha1->topo] = vetNum;
    pilha1->topo++;

    return 1;
}

int remove_pilha(Pilha* pilha1){ //pop
    if(pilha1 == NULL || pilha1->topo == 0)
        return 0;

    pilha1->topo--;
    return 1;
}

void inverte_pilha(Pilha* pilha1, Pilha* pilha2){
    inicia_pilha(pilha2);

    for(i = pilha1->topo - 1; i >= 0; i--)
        insere_pilha(pilha2, pilha1->vet[i]);
}

int consulta_topo_pilha(Pilha* pilha1, elemento* vetNum){
    if(pilha1 == NULL || pilha1->topo == 0)
        return 0;
    
    *vetNum = pilha1->vet[pilha1->topo-1];
    return 1;
}

void imprime_pilha(Pilha* pilha1, Pilha* pilha2){

    printf("\n%-10s %-10s\n", "Pilha 01", "Pilha 02");
    printf("---------------------\n");

    for(i = 0; i < pilha1->topo; i++){
        printf("%-10d", pilha1->vet[i]);
        printf("%-10d", pilha2->vet[i]);
        printf("\n");
    }
}