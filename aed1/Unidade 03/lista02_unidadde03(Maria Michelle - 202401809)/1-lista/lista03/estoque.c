#include <stdio.h>
#include <stdlib.h>
#include "estoque.h" 

struct elemento{
    produto estoque;
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

int cadastra_produto(Lista* li, produto p){
    if (li == NULL)
        return 0;

    Elem* no = (Elem*)malloc(sizeof(Elem));

    if (no == NULL)
        return 0;

    no->estoque = p;
    no->prox = *li;
    *li = no;

    return 1;
}

int remove_produto(Lista* li, int codigo){
    if (li == NULL || *li == NULL) return 0;
    Elem *ant = NULL, *no = *li;

    while (no != NULL && no->estoque.codigo != codigo) {
        ant = no;
        no = no->prox;
    }

    if (no == NULL) return 0;

    if (ant == NULL)
        *li = no->prox;
    else 
        ant->prox = no->prox;

    free(no);
    return 1;
}

int busca_produto_menor_preco(Lista* li, produto *p){
    if (li == NULL || *li == NULL) return 0;

    Elem* no = *li;
    Elem* menorP = no;

    while (no != NULL) {
        if (no->estoque.preco < menorP->estoque.preco)
            menorP = no;
        
        no = no->prox;
    }

    *p = menorP->estoque;
    return 1;
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

    printf("\nQuantidade de produtos disponiveis no estoque: %d\n\n", tamanho_lista(li));

    while(no != NULL){
        printf("Codigo: %d\n",no->estoque.codigo);
        printf("Nome: %s\n",no->estoque.nome);
        printf("Preco: %.2f\n", no->estoque.preco);
        printf("Quantidade disponivel em estoque: %.2f\n", no->estoque.quant);
        printf("-------------------------------\n");

        no = no->prox;
    }
}
