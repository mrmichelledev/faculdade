#include <stdio.h>
#include <stdlib.h>
#include "listaD.h"

struct elemento{
    aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;


struct descritor{
    struct elemento *inicio;
    struct elemento *final;
    int quant;
};


Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));

    if(li != NULL){
        li->inicio = NULL;
        li->final = NULL;
        li->quant = 0;
    }

    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;

        while((li->inicio) != NULL){
            no = li->inicio;
            li->inicio = li->inicio->prox;
            free(no);
        }

        free(li);
    }
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;

    return li->quant;
}

int insere_lista_inicio(Lista* li, aluno al){
    if(li == NULL)
        return 0;

    Elem* no = (Elem*) malloc(sizeof(Elem));

    if(no == NULL)
        return 0;

    no->dados = al;
    no->prox = li->inicio;

    if(li->inicio == NULL)
        li->final = no;

    li->inicio = no;
    li->quant++;

    return 1;
}

int insere_lista_final(Lista* li, aluno al){
    if(li == NULL)
        return 0;

    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;

    no->dados = al;
    no->prox = NULL;

    if(li->inicio == NULL)
        li->inicio = no;
    else
        li->final->prox = no;

    li->final = no;
    li->quant++;

    return 1;
}


int remove_primeiros(Lista* li, int remove){
    if(li == NULL || li->inicio == NULL || remove <= 0)
        return 0;

    while (li->inicio != NULL && remove > 0) {
        Elem *no = li->inicio;
        li->inicio = no->prox;
        free(no);
        li->quant--;
        remove--;
    }

    if(li->inicio == NULL)
        li->final = NULL;

    return 1;
}

int remove_ultimos(Lista* li, int remove){
    if (li == NULL || li->inicio == NULL || remove <= 0)
        return 0;

    if (remove >= li->quant) {
        return remove_primeiros(li, li->quant);
    }

    li->quant -= remove;
    int i;

    Elem *atual = li->inicio;
    for (i = 1; i < li->quant; i++) {
        atual = atual->prox;
    }

    while (atual->prox != NULL) {
        Elem *no = atual->prox;
        atual->prox = no->prox;
        free(no);
    }

    li->final = atual;
    return 1;
}

void imprime_lista(Lista* li){
    if(li == NULL || li->inicio == NULL)
        return;

    Elem* no = li->inicio;

    printf("\n\nTamanho atual: %d\n\n", tamanho_lista(li)); 

    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %.2f %.2f %.2f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");

        no = no->prox;
    }
}