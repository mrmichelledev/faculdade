#include <stdio.h>
#include <stdlib.h>
#include "conjuntos.h"

//menu
void menu(){

    printf(".....................................\n");
    printf(".               MENU                .\n");
    printf(".....................................\n");
    printf(". 1 - Criar conjunto                .\n");
    printf(". 2 - Verificar se está vazio       .\n");
    printf(". 3 - Inserir elemento              .\n");
    printf(". 4 - Excluir elemento              .\n");
    printf(". 5 - Mostrar conjunto              .\n");
    printf(". 6 - Mostrar tamanho do conjunto   .\n");
    printf(". 0 - Sair                          .\n");
    printf(".....................................\n\n");
}

void clear(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

struct conjunto{
    int *elementos;
    int tam;
};


int criaConjunto(Conjunto** c){
    *c = (Conjunto*)malloc(sizeof(Conjunto));
    (*c)->elementos = NULL;

    if(*c != NULL){
        (*c)->tam = 0;

        return 1;
    }

    return 0;
}

int conjuntoVazio(Conjunto* c){
    return c->tam == 0;
}

int insereElementoConjunto(int e, Conjunto* c){
    int i;

    if(c->tam >= 0){
        //verificando se o elemento já está inserido
        for(i = 0; i < c->tam; i++){
            if(c->elementos[i] == e)
                return 0;
        }
        
        c->elementos = (int*) realloc(c->elementos, ((c->tam)+1)*sizeof(int));
        c->elementos[c->tam] = e;

        c->tam++;
        return 1;
    }
    return 0;
}

int excluirElementoConjunto(int e, Conjunto* c){
    int i, aux = -1;
    for(i = 0; i < c->tam; i++){
        if(c->elementos[i] == e){
            aux = i;
            break;
        }
    }

    if(aux == -1 || c->elementos == NULL) return 0;

    for(i = aux; i < c->tam-1; i++){
        c->elementos[i] = c->elementos[i+1];
    }

    c->elementos = (int*) realloc(c->elementos, (c->tam-1)*sizeof(int));
    c->tam--;

    return 1;
}

int tamanhoConjunto(Conjunto* c){
    if(c->tam > 0) return c->tam;
    return 0;
}

void mostraConjunto(Conjunto* c){
    int i;

    for(i = 0; i < c->tam; i++){
        printf("%d", c->elementos[i]);
        if(i != c->tam-1) printf(" ");
    }

    printf("\n");
}

/*int maior(int e, Conjunto* c){

}

int menor(int e, Conjunto* c){

}

int pertenceConjunto(int e, Conjunto* c){

}

int conjuntosIdenticos(Conjunto* c1, Conjunto* c2){

}

int subconjunto(Conjunto* c1, Conjunto* c2){

}*/