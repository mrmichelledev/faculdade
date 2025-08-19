#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    aluno al, a[10] =  {{1278, "Maria"},
                        {4532, "Michelle"},
                        {2941, "Eduarda"},
                        {8765, "Felipe"},
                        {3402, "Marcos"},
                        {6728, "Dinei"},
                        {9184, "Vitoria"},
                        {4356, "Poliana"},
                        {5623, "Leonardo"},
                        {7890, "Nathaly"}};
    
    int i;

    Lista* li = cria_lista();
        
    printf("\nInserindo na lista de forma ordenada: ");
    for(i = 0; i < 10; i++) {
        if (!insere_lista_ordenada(li,a[i]))
            printf(RED"Erro ao inserir\n"RESET);
    }

    imprime_lista(li);

    printf("\nImprimindo alunos matriculados antes e depois de \033[1;33mLeonardo\033[0m");
    al.matricula = 5623;
    retorna_ant_prox(li, &al);

    printf("\nImprimindo alunos matriculados antes e depois de \033[1;33mMaria\033[0m");
    al.matricula = 1278;
    retorna_ant_prox(li, &al);

    libera_lista(li);
    return 0;
}

