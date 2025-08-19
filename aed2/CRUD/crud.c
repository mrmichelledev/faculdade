#include <stdio.h>
#include <stdlib.h>
#include "crud.h"

struct elemento{
    aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Lista* cria_lista(){
    Lista* al = (Lista*) malloc(sizeof(Lista));

    if(al != NULL)
        *al = NULL;
    
    return al;
}

void libera_lista(Lista* al){
    if(al != NULL){
        Elem* no;

        while((*al) != NULL){
            no = *al;
            *al = (*al)->prox;
            free(no);
        }

        free(al);
    }
}

int tamanho_lista(Lista* al){
    if (al == NULL) return 0;

    Elem* no = *al;
    int tamanho = 0;
    
    while(no != NULL){
        tamanho++;
        no = no->prox;
    }

    return tamanho;
}

int lista_cheia(Lista* al){
    return 0;
}

int lista_vazia(Lista* al){
    if(al == NULL)
        return 1;
    else if (*al == NULL)
        return 1;

    return 0;
}

int insere_aluno(Lista* al, aluno aluno){
    if(al == NULL) return 0;

    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;

    no->dados = aluno;
    no->prox = NULL;

    if(*al == NULL || aluno.matricula < (*al)->dados.matricula){
        no->prox = *al;
        *al = no;
        return 1;
    }

    Elem* ant = *al;
    Elem* atual = (*al)->prox;

    while (atual != NULL && atual->dados.matricula < aluno.matricula) {
        ant = atual;
        atual = atual->prox;
    }

    no->prox = atual;
    ant->prox = no;

    return 1;
}

int consulta_aluno(Lista* al, int matricula, aluno* aluno){
    if (al == NULL || *al == NULL) return 0;

    Elem* no = *al;

    while (no != NULL) {
        if (no->dados.matricula == matricula) {
            *aluno = no->dados;
            return 1;
        }
        no = no->prox;
    }

    return 0;
}

int atualiza_aluno(Lista* al, int matricula, aluno atualizado){
    if (al == NULL || *al == NULL) return 0;
    
    Elem* no = *al;
    
    while (no != NULL) {
        if (no->dados.matricula == matricula) {
            no->dados = atualizado;
            return 1;
        }

        no = no->prox;
    }
    
    return 0;
}

int exclui_aluno(Lista* al, aluno aluno){
    if (al == NULL || *al == NULL) return 0;

    Elem *ant = NULL;
    Elem *no = *al;

    while (no != NULL && strcmp(no->dados.nome, aluno.nome) != 0) {
        ant = no;
        no = no->prox;
    }

    if (no == NULL) return 0; //não encontrado

    if (ant == NULL) *al = no->prox;
    else ant->prox = no->prox; 

    free(no);
    return 1;
}

void imprime_aluno(Lista* al){
    if(al == NULL)
        return;

    Elem* no = *al;

    printf("\n\nTamanho atual: %d\n\n", tamanho_lista(al)); 

    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("-------------------------------\n");

        no = no->prox;
    }
}