#include <stdio.h>
#include <stdlib.h>
#include "pilhaSequencial.h"

struct pilha{
    int quantidade;
    struct aluno dados[MAX];
};

Pilha* cria_pilha(){
    Pilha* pilhinha;
    pilhinha = (Pilha*) malloc(sizeof(Pilha));

    if(pilhinha != NULL)
        pilhinha->quantidade = 0;

    return pilhinha;
}

void libera_pilha(Pilha* pilhinha){
    free(pilhinha);
}

int tamanho_pilha(Pilha* pilhinha){
    if(pilhinha == NULL)
        return -1;
    
    return pilhinha->quantidade;
}

int pilha_cheia(Pilha* pilhinha){
    if(pilhinha == NULL)
        return -1;
    
    return (pilhinha->quantidade == MAX);
}

int pilha_vazia(Pilha* pilhinha){
    if(pilhinha == NULL)
        return -1;
    
    return (pilhinha->quantidade == 0);
}

int consulta_topo_pilha(Pilha* pilhinha, struct aluno* Aluno){
    if(pilhinha == NULL || pilhinha->quantidade == 0)
        return 0;

    return *Aluno = pilhinha->dados[pilhinha->quantidade-1]; 
}

int insere_pilha(Pilha* pilhinha, struct aluno Aluno){
    if(pilhinha == NULL || pilhinha->quantidade == MAX){
        return 0;
    } else{
        pilhinha->dados[pilhinha->quantidade] = Aluno;
        pilhinha->quantidade++;
        return 1;
    }
    
}

int remove_pilha(Pilha* pilhinha){
    if(pilhinha == NULL || pilhinha->quantidade == 0)
        return 0;
    
    pilhinha->quantidade--;
    return 1;
}

void imprime_pilha(Pilha* pilhinha){
    if(pilhinha == NULL)
        return;

    int i;

    printf("\t..............................\n");
    for(i = pilhinha->quantidade-1; i >= 0; i--){
        printf("\tMatricula: %d\n", pilhinha->dados[i].matricula);
        printf("\tNome: %s\n", pilhinha->dados[i].nome);
        printf("\tMedia: %.2f\n", pilhinha->dados[i].media);
        printf("\t..............................\n");
    }
}