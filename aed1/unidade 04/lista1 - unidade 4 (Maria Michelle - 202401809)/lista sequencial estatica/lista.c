#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct lista{
    int tamanho;
    aluno dados[MAX];
};

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));

    if(li != NULL)
        li->tamanho = 0;

    return li;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return -1;

    return li->tamanho;
}

int insere_inicio(Lista* li, aluno* al, long long int N){
    if(li == NULL || (li->tamanho + N) > MAX)
        return 0;

    int i;
    li->tamanho += N;

    for(i = li->tamanho - 1; i >= N; i--)
        li->dados[i] = li->dados[i - N];

    for (i = 0; i < N; i++)
        li->dados[i] = al[i];
    

    return 1;
}

int insere_final(Lista* li, aluno* al, long long int N){
    if(li == NULL || (li->tamanho + N) > MAX)
        return 0;

    int i;
    for (i = 0; i < N; i++)
        li->dados[li->tamanho + i] = al[i];
    
    li->tamanho += N;
    return 1;
}

int consulta_posicao(Lista* li, aluno* al,  long long int N){
    if(li == NULL || N <= 0 ||  N > li->tamanho)
        return 0;
    
    int i, pos;

    for(i = 0; i < N; i++){
        srand(time(NULL));
        int tamanhoL= tamanho_lista(li);

        pos = rand() % tamanhoL + 1;

        *al = li->dados[pos-1];
    }

    return 1;
}

void libera_lista(Lista* li){
    free(li);
}

void imprime_lista(Lista* li){
    int i;
    printf(ROXO"\nTamanho atual: %d\n"RESET, tamanho_lista(li));

    for (i = 0; i < li->tamanho; i++) {
        printf("Aluno %d: %s - %d\n", i + 1, li->dados[i].nome, li->dados[i].numMatricula);
    }

    printf("\n");
}