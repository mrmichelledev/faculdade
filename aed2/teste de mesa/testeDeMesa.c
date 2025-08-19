#include <stdio.h>
#include <stdlib.h>
#include "testeDeMesa.h"

struct No{
    int info;
    struct No *esquerda;
    struct No *direita;
};

Arvore* cria_arvore(){
    Arvore* raiz = (Arvore*) malloc(sizeof(Arvore));

    if(raiz != NULL)
        *raiz = NULL;

    return raiz;
}

void libera_No(struct No* no){
    if(no = NULL) return;

    libera_No(no->esquerda);
    libera_No(no->direita);
    free(no);
    no = NULL;
}

void libera_arvore(Arvore* raiz){
    if(raiz == NULL) return;

    libera_No(*raiz);
    free(raiz);
}

int arvore_vazia(Arvore *raiz){
    if(raiz == NULL || *raiz == NULL) return 1;

    return 0;
}

int altura_arvore(Arvore* raiz){
    if(raiz == NULL || *raiz == NULL) return 0;

    int altura_esquerda = altura_arvore(&((*raiz)->esquerda));
    int altura_direita = altura_arvore(&((*raiz)->direita));

    if(altura_esquerda > altura_direita)
        return altura_esquerda++;
    else
        return altura_direita++;
}

int total_No(Arvore* raiz){
    if(raiz == NULL || *raiz == NULL) return 0;

    int altura_esquerda = total_No(&((*raiz)->esquerda));
    int altura_direita = total_No(&((*raiz)->direita));

    return (altura_esquerda + altura_direita + 1);
}

int insere_arvore(Arvore* raiz, int valor){
    if(raiz == NULL || *raiz == NULL) return 0;

    struct No* novo = (struct No*) malloc(sizeof(struct No));

    if(novo == NULL) return 0;

    novo->info = valor;
    novo->direita = NULL;
    novo->esquerda = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else {
        struct No* atual = *raiz;
        struct No* anterior = NULL;

        while(atual != NULL){
            anterior = atual;

            if(valor == atual->info){
                free(novo);
                return 0;
            }

            if(valor > atual->info)
                atual = atual->direita;
            else
                atual = atual->esquerda;
        }

        if(valor > anterior->info)
            anterior->direita = novo;
        else
            anterior->esquerda = novo;

        return 1;
    }
}

int remove_arvore(Arvore* raiz, int  valor){
    if(raiz == NULL) return 0;

    struct No* anterior = NULL;
    struct No* atual = *raiz;

    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(anterior->direita == atual)
                    anterior->direita = remove_atual(atual);
                else
                    anterior->esquerda = remove_atual(atual);
            }

            return 1;
        }

        anterior = atual;

        if(valor > atual->info)
            atual = atual->direita;
        else
            atual = atual->esquerda;
    }
}

struct No* remove_atual(struct No* atual){
    struct No *no1, *no2;

    if(atual->esquerda == NULL){
        no2 = atual->direita;
        free(atual);
        return no2;
    }

    no1 = atual;
    no2 = atual->esquerda;

    while(no2->direita != NULL){
        no1 = no2;
        no2 = no2->direita;
    }

    if(no1 != atual){
        no1->direita = no2->esquerda;
        no2->esquerda = atual->esquerda;
    }

    no2->direita = atual->direita;
    free(atual);
    return no2;
}