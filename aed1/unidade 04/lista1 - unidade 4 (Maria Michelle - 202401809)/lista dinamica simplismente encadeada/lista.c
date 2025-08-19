#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct lista{
    aluno dados;
    struct lista* prox;
};

typedef struct lista Elem;

struct descritor {
    Elem* inicio;  
    Elem* fim;  
};

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));

    if(li != NULL)
        li->inicio = NULL;
        li->fim = NULL;

    return li;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;

    int cont = 0;
    Elem* no = li->inicio;

    while(no != NULL){
        cont++;
        no = no->prox;
    }

    return cont;
}

int insere_inicio(Lista* li, aluno* al, int N){
    if(li == NULL || al == NULL || N <= 0)
        return 0;

    int i;

    for(i = 0; i < N; i++){
        Elem* no = (Elem*) malloc(sizeof(Elem));

        if(no == NULL)
            return 0;

        no->dados = al[i];
        no->prox = li->inicio;
        li->inicio = no;

        if (li->fim == NULL)
            li->fim = no;
    }

    return 1;
}

int insere_final(Lista* li, aluno* al, int N){
    if(li == NULL || al == NULL || N <= 0)
        return 0;

    int i;

    for(i = 0; i < N; i++){
        Elem *no = (Elem*) malloc(sizeof(Elem));

        if(no == NULL)
            return 0;

        no->dados = al[i];
        no->prox = NULL;

        if (li->inicio == NULL)  // Lista vazia
            li->inicio = no;
        else
            li->fim->prox = no;  //último elemento

        li->fim = no;  //ponteiro fim
    }

    return 1;
}

int consulta_posicao(Lista* li, aluno* al,  int pos){
    if(li == NULL || pos <= 0)
        return 0;

    Elem* no = li->inicio;
    int i = 1;

    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }

    if(no == NULL)
        return 0;

    *al = no->dados;
    return 1;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;

        while(li->inicio != NULL){
            no = li->inicio;
            li->inicio = li->inicio->prox;
            free(no);
        }

        free(li);
    }
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;

    Elem* no = li->inicio;
    int i = 0;

    printf(ROXO"\nTamanho atual: %d\n"RESET, tamanho_lista(li));

    while(no != NULL){
        printf("Aluno %d: %s - %d\n", i + 1, no->dados.nome, no->dados.numMatricula);

        no = no->prox;
        i++;
    }

    printf("\n");
}