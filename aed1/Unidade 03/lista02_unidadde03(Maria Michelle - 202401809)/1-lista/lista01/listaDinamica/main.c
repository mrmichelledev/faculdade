#include <stdio.h>
#include <stdlib.h>
#include "listaD.h"

int main(){
    aluno a1, a[10] =  {{1278, "Maria", 9.5, 7.8, 8.5},
                        {4532, "Michelle", 7.5, 8.7, 6.8},
                        {2941, "Eduarda", 9.7, 6.7, 8.4},
                        {8765, "Felipe", 5.7, 6.1, 7.4},
                        {3402, "Marcos", 8.9, 7.3, 6.5},
                        {6728, "Dinei", 6.5, 8.2, 7.1},
                        {9184, "Vitoria", 7.0, 6.0, 8.0},
                        {4356, "Poliana", 9.1, 8.5, 7.6},
                        {5623, "Leonardo", 5.9, 6.8, 7.7},
                        {7890, "Nathaly", 8.4, 7.9, 9.0}};
    
    int i;

    Lista* li = cria_lista();
        
    printf("\nInserindo no final da lista: ");
    for(i = 0; i < 5; i++) {
        if (!insere_lista_final(li,a[i]))
            printf("Erro ao inserir\n");
    }

    imprime_lista(li);

    /*printf("\n\nInserindo no inicio da lista: ");
    for(i = 5; i < 10; i++) {
        if (!insere_lista_final(li,a[i]))
            printf("Erro ao inserir %d\n");
    }

    imprime_lista(li);*/

    printf("\nremovendo os 2 primeiros elementos da lista:");

    if (!remove_primeiros(li, 2))
        printf("[!]Erro[!]\n");

    imprime_lista(li);

    printf("\nremovendo os 2 ultimos elementos da lista");

    if (!remove_ultimos(li, 2))
        printf("[!]Erro[!]\n");

    imprime_lista(li);

    libera_lista(li);
    return 0;
}

