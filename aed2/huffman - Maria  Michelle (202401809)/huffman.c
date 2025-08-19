#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "huffman.h"


Lista* criaLista() {
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL) {
        li->inicio = NULL;
        li->tam = 0;
    }
    return li;
}

void iniciaTab(unsigned int tab[]){
    for(int i = 0; i < TAM; i++){
        tab[i] = 0;
    }
}

void contaFreq(unsigned char texto[], unsigned int tab[]){
    int i = 0;
    while(texto[i] != '\0'){
        tab[texto[i]]++;
        i++;
    }
}

void inserirOrdenado(Lista* li, No* no){
    if(li->inicio == NULL){
        li->inicio = no;
    } else if(no->frequencia < li->inicio->frequencia){
        no->prox = li->inicio;
        li->inicio = no;
    }else {
        No* aux = li->inicio;
        while(aux->prox && aux->prox->frequencia <= no->frequencia)
            aux = aux->prox;
        no->prox = aux->prox;
        aux->prox = no;
    }
    li->tam++;
}

void preencherLista(unsigned int tab[], Lista* li){
    for(int i = 0; i < TAM; i++){
        if(tab[i] > 0){
            No* novo = (No*) malloc(sizeof(No));
            if(novo){
                novo->caracter = i;
                novo->frequencia = tab[i];
                novo->dir = NULL;
                novo->esq = NULL;
                novo->prox = NULL;
                inserirOrdenado(li, novo);
            } else{
                printf("ERRO ao alocar!");
                break;
            }
        }
    }
}

void imprime(Lista* li){
    No* aux = li->inicio;
    printf("Lista ordenada \tTamanho: %d\n", li->tam);
    while(aux){
        printf("Caracter: %c Frequencia: %d\n", aux->caracter, aux->frequencia);
        aux = aux->prox;
    }
}

No* removeInicio(Lista* li){
    No* aux = NULL;
    if(li->inicio){
        aux = li->inicio;
        li->inicio = aux->prox;
        aux->prox = NULL;
        li->tam--;
    }
    return aux;
}

No* montarArvore(Lista* li){
    No *primeiro, *segundo;
    while(li->tam > 1){
        primeiro = removeInicio(li);
        segundo = removeInicio(li);
        No* novo = (No*) malloc(sizeof(No));
        if(novo){
            novo->caracter = '+';
            novo->frequencia = primeiro->frequencia + segundo->frequencia;
            novo->esq = primeiro;
            novo->dir = segundo;
            novo->prox = NULL;
            inserirOrdenado(li, novo);
        } else{
            printf("ERRO ao alocar memoria em montarArvore!");
            break;
        }
    }
    return li->inicio;
}

void imprimeArvore(No* raiz, int tam){
    if(raiz->esq == NULL && raiz->dir == NULL)
        printf("Folha: %c\tAltura: %d\n", raiz->caracter, tam);
    else{
        imprimeArvore(raiz->esq, tam+1);
        imprimeArvore(raiz->dir, tam+1);
    }
}

void gerarCodigos(No* raiz, char* codigo, int topo, char codigos[][TAM]) {
    if(raiz->esq == NULL && raiz->dir == NULL){
        codigo[topo] = '\0';
        strcpy(codigos[raiz->caracter], codigo);
        return;
    }

    if(raiz->esq){
        codigo[topo] = '0';
        gerarCodigos(raiz->esq, codigo, topo + 1, codigos);
    }
    if(raiz->dir){
        codigo[topo] = '1';
        gerarCodigos(raiz->dir, codigo, topo + 1, codigos);
    }
}

void liberaArvore(No* raiz){
    if(raiz == NULL)
        return;

    liberaArvore(raiz->esq);
    liberaArvore(raiz->dir);
    free(raiz);
}

void codificaTexto(unsigned char texto[], char codigos[][TAM]){
    int i;

    printf("\nTexto codificado:\n");
    for(i = 0; texto[i] != '\0'; i++){
        printf("%s", codigos[texto[i]]);
    }
    printf("\n\n\n");
}
