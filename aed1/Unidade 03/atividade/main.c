#include <stdio.h>
#include <stdlib.h>
#include "pilhaSequencial.h"

int main(){
    int i;
    struct aluno teste[3] = {{202400001, "Maria", 6.5},
                             {202400010, "Michelle", 8.6},
                             {202400011, "Maria Michelle", 2.3}};
    
    //cria pilha
    Pilha* pilhinha = cria_pilha();
    
    //tamanho da pilha
    printf("Tamanho da pilha: %d", tamanho_pilha(pilhinha));

    //insere pilha
    for(i = 0; i < 3; i++)
        insere_pilha(pilhinha, teste[i]);

    getchar();

    //imprimindo a pilha atual
    imprime_pilha(pilhinha);
    printf("Tamanho: %d\n\n",tamanho_pilha(pilhinha));

    //removendo pilha
    for(i=0; i < 3; i++)
        remove_pilha(pilhinha);

    printf("Tamanho: %d\n\n",tamanho_pilha(pilhinha));
    imprime_pilha(pilhinha);
    getchar();

    libera_pilha(pilhinha);
    getchar();
    return 0;
}

