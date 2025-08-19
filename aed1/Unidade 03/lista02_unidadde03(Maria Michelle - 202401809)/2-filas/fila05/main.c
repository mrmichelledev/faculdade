#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

int main(){
    Fila* f1 = cria_Fila();
    Fila* f2 = cria_Fila();
    chamada nomeI;
    int i;

    char* nomes[] = {"Maria", "Michelle", "Thiago", "Leonardo", "Rafael",
                     "Poliana", "Vitoria", "Eduarda", "Keven", "Rodrigo"};

    for (i = 0; i < 10; i++) {
        strcpy(nomeI.nome, nomes[i]);
        insere_Fila(f1, nomeI);
    }

    copia_Fila(f1, f2);

    imprime_Fila(f1, f2);
    
    libera_Fila(f1);
    libera_Fila(f2);

    return 0;
}