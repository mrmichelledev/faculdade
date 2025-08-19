#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista{
    unsigned int tamanho;
    inteiros num[MAX];
};

//limpa tela
void clear(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void proximo(){
    printf(AZUL "Pressione ENTER para sair...\n" RESET);
    getchar();
    getchar();
    SLEEP(0.5);
}

Lista* cria_lista(){
    Lista* listaInt = (Lista*) malloc(sizeof(Lista));

    if(listaInt != NULL)
        listaInt->tamanho = 0;

    return listaInt;
}

void inicia_lista(Lista* listaInt){
    listaInt->tamanho = 0;
}

void libera_lista(Lista* listaInt){
    free(listaInt);
}

int tamanho_lista(Lista* listaInt){
    if(listaInt == NULL)
        return -1;

    return listaInt->tamanho;
}

int lista_vazia(Lista* listaInt){
    if(listaInt == NULL)
        return -1;

    return (listaInt->tamanho == 0);
}

int lista_cheia(Lista* listaInt){
    if(listaInt == NULL)
        return -1;

    return (listaInt->tamanho == MAX);
}

void ordenar(inteiros* a, inteiros* b){
    inteiros aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void ascendente(Lista* listaInt) {
    inteiros aux;
    
    for (i = 0; i < listaInt->tamanho - 1; i++) {
        for (j = 0; j < listaInt->tamanho - i - 1; j++) {

            if (listaInt->num[j].numInt > listaInt->num[j + 1].numInt) {
                ordenar(&listaInt->num[j], &listaInt->num[j + 1]);
            }
        }
    }
}

int insere_inicio_lista(Lista* listaInt, inteiros numInt){
    if(listaInt == NULL || listaInt->tamanho == MAX)
        return -1;
    
    for(i = listaInt->tamanho; i > 0; i--){
        listaInt->num[i] = listaInt->num[i - 1];
    }

    listaInt->num[0] = numInt;
    listaInt->tamanho++;

    return 1;
}

int insere_meio_lista(Lista* listaInt, inteiros numInt){
    ascendente(listaInt);

    if(listaInt == NULL || listaInt->tamanho == MAX)
        return -1;
    
    int meio = listaInt->tamanho / 2;

    for(i = listaInt->tamanho; i > meio; i--){
        listaInt->num[i] = listaInt->num[i - 1];
    }

    listaInt->num[meio] = numInt;
    listaInt->tamanho++;
    
    return 1;
}

int insere_fim_lista(Lista* listaInt, inteiros numInt){
    if(listaInt == NULL || listaInt->tamanho == MAX)
        return -1;

    listaInt->num[listaInt->tamanho] = numInt;
    listaInt->tamanho++;

    return 1;
}

int remove_inicio_lista(Lista* listaInt){
    if(listaInt == NULL || listaInt->tamanho == 0)
        return -1;

    for(i = 0; i < listaInt->tamanho - 1; i++){
        listaInt->num[i] = listaInt->num[i + 1];
    }

    listaInt->tamanho--;

    return 1;
}

int remove_meio_lista(Lista* listaInt){
    ascendente(listaInt);

    if(listaInt == NULL || listaInt->tamanho == 0)
        return -1;

    int meio = listaInt->tamanho / 2;

    for(i = meio; i < (listaInt->tamanho - 1)
    ; i++){
        listaInt->num[i] = listaInt->num[i + 1];
    }

    listaInt->tamanho--;
    
    return 1;
}

int remove_fim_lista(Lista* listaInt){
    if(listaInt == NULL || listaInt->tamanho == 0)
        return -1;

    listaInt->tamanho--;
}

int consulta_elemento_valor(Lista* listaInt, int valor){

    if(listaInt == NULL || listaInt->tamanho == 0)
        return -1;

    for(i = 0; i < listaInt->tamanho; i++){
        if(*(listaInt->num[i].numInt) == valor)
            return i;
    }
}

int consulta_elemento_indice(Lista* listaInt, inteiros* numInt, int indice){

    if(listaInt == NULL || listaInt->tamanho == 0 || indice < 0 || indice >= listaInt->tamanho)
        return -1;

    *numInt = listaInt->num[indice];
    return 0;
}

void imprime_lista(Lista* listaInt){
    int i;

    printf("\n------------------------------\n");
    printf("Tamanho atual da lista: %d\n", listaInt->tamanho);
    printf("lista: ");

    for(i = 0; i < listaInt->tamanho; i++){
        printf("%d", listaInt->num[i]);

        if(i < listaInt->tamanho - 1)
            printf(", ");
    }
    printf("\n");
    printf("------------------------------\n\n");
}