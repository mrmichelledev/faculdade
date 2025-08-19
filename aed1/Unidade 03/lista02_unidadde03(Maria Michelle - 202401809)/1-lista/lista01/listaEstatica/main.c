#include <stdio.h>
#include <stdlib.h>
#include "lista1.h"

int main(){
    numero vet[10] = {{23}, {45}, {12}, {67}, {89}, {34}, {78}, {56}, {10}, {3}};
    Lista* li = NULL;
    
    int i;

    li = cria_lista();
    
    printf("\nVetor atual: ");
    for(i = 0; i < 10; i++)
        printf("%d ", vet[i]);
        
    printf("\n\nInserindo lista ordenada: ");
    for(i = 0; i < 10; i++) {
        if (!insere_lista_ordenada(li, vet[i]))
            printf("Erro ao inserir %d\n", vet[i].num);
    }

    imprime_lista(li);

    printf("removendo os 2 primeiros elementos da lista:");

    if (!remove_primeiros(li, 2))
        printf("[!]Erro[!]\n");

    imprime_lista(li);

    printf("removendo os 2 ultimos elementos da lista");

    if (!remove_ultimos(li, 2))
        printf("[!]Erro[!]\n");

    imprime_lista(li);

    libera_lista(li);
    return 0;
}

