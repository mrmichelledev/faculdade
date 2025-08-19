#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

Hash* criaHash() {
    Hash* h = (Hash*) malloc(sizeof(Hash));

    if (h == NULL) {
        printf("Erro na alocacao de memoria\n");
        exit(1);
    }

    for(i = 0; i < TAM_VETOR; i++) {
        h->ocupado[i] = 0;
        h->itens[i] = NULL;
    }
    h->qtd = 0;
    return h;
}

void liberaLista(No* lista) {
    while(lista) {
        No* temp = lista;
        lista = lista->prox;
        free(temp);
    }
}

void liberaHash(Hash* h) {
    for(i = 0; i < TAM_VETOR; i++)
        liberaLista(h->itens[i]);

    free(h);
}

int funcaoHash(int cod) {
    return cod % TAM_VETOR;
}

int inserir(Hash* h, Dados d) {
    int pos = funcaoHash(d.cod);
    if (h->ocupado[pos] == 0) {
        h->vetor[pos] = d;
        h->ocupado[pos] = 1;
        h->qtd++;
        return 1; // insere na principal
    } else {
        No* novo = (No*) malloc(sizeof(No));
        if (!novo) {
            printf("Erro na alocacao de memoria\n");
            exit(1);
        }
        novo->dado = d;
        novo->prox = h->itens[pos];
        h->itens[pos] = novo;
        return 2; // insere lista auxiliar (colisão)
    }
}

int buscar(Hash* h, int cod, Dados* d, int* passos) {
    *passos = 0;
    int pos = funcaoHash(cod);

    (*passos)++;
    if (h->ocupado[pos] && h->vetor[pos].cod == cod) {
        *d = h->vetor[pos];
        return 1;
    }

    No* aux = h->itens[pos];
    while(aux) {
        (*passos)++;
        if (aux->dado.cod == cod) {
            *d = aux->dado;
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

void analiseFinal(Hash* h) {
    printf("\nAvaliacao final\n");
    printf(" > Quantidade de espacos ocupados:" CINZA " %d\n" RESET, h->qtd);
    printf(" > Espacos vazios na estrutura principal (1000 posicoes):" CINZA " %d\n\n\n" RESET, TAM_VETOR - h->qtd);
}