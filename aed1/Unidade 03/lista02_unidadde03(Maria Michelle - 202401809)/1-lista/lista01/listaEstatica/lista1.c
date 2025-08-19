#include <stdio.h>
#include <stdlib.h>
#include "lista1.h" 

struct lista{
    int quant;
    numero numeros[MAX];
};

Lista* cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));

    if(li != NULL)
        li->quant = 0;

    return li;
}

void libera_lista(Lista* li){
    free(li);
}

int insere_lista_ordenada(Lista* li, numero n){
    if(li == NULL || li->quant == MAX)
        return 0;

    int j, i = 0;

    while(i < li->quant && li->numeros[i].num < n.num)
        i++;

    for(j = li->quant - 1; j >= i; j--)
        li->numeros[j + 1] = li->numeros[j];

    li->numeros[i] = n;
    li->quant++;

    return 1;
}

int remove_primeiros(Lista* li, int remove){
    if(li == NULL || li->quant == 0 || remove > li->quant || remove < 0)
        return 0;
    
    int i;
    for(i = 0; i< li->quant - remove; i++)
        li->numeros[i] = li->numeros[i + remove];

    li->quant -= remove;
    return 1;
}

int remove_ultimos(Lista* li, int remove){
    if(li == NULL || li->quant == 0 || remove > li->quant || remove < 0)
        return 0;

    li->quant -= remove;
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return -1;
    else
        return li->quant;
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    
    printf("\n-------------------------------\n");
    printf("Tamanho atual: %d\n", tamanho_lista(li));

    int i;
    for(i=0; i< li->quant; i++)
        printf("%d ",li->numeros[i].num);
    
    printf("\n-------------------------------\n\n");
}