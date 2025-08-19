#include <stdio.h>
#include <stdlib.h>
#include "lista.h" 

struct elemento{
    struct elemento *ant;
    aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));

    if(li != NULL)
        *li = NULL;

    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int insere_lista_ordenada(Lista* li, aluno al){
    if(li == NULL)
        return 0;

    Elem *no = (Elem*) malloc(sizeof(Elem));

    if(no == NULL)
        return 0;

    no->dados = al;

    if((*li) == NULL){
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;

    } else{
        Elem *ant, *atual = *li;

        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }

        if(atual == *li){
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;

        } else{
            no->prox = ant->prox;
            no->ant = ant;
            ant->prox = no;

            if(atual != NULL)
                atual->ant = no;

        }

        return 1;
    }
}

void retorna_ant_prox(Lista* li, aluno *al){
    if(li == NULL)
        return;

    Elem *no = *li;

    while (no != NULL && no->dados.matricula != al->matricula)
        no = no->prox;

    if(no == NULL)
        return;
    
    if (no->ant != NULL) {
        printf(AZUL"\n(Antecessor)\n"RESET);
        printf("Matricula: %d\n", no->ant->dados.matricula);
        printf("Nome: %s\n", no->ant->dados.nome);
    } else {
        printf(RED"\nNao ha antecessor\n"RESET);
    }

    if (no->prox != NULL) {
        printf(AZUL"\n(Sucessor)\n"RESET);
        printf("Matricula: %d\n", no->prox->dados.matricula);
        printf("Nome: %s\n", no->prox->dados.nome);
    } else {
        printf(RED"\nNao ha sucessor\n"RESET);
    }
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;

    int cont = 0;
    Elem* no = *li;

    while(no != NULL){
        cont++;
        no = no->prox;
    }

    return cont;
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    
    Elem* no = *li;

    printf("\n\nTamanho da lista: %d\n\n", tamanho_lista(li)); 

    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("-------------------------------\n");

        no = no->prox;
    }
}

