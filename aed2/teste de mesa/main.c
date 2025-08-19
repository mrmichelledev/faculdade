#include <stdio.h>
#include <stdlib.h>
#include "testeDeMesa.h"

int main(){
    Arvore* raiz = cria_arvore();
    int i, num[] = {5, 1, 5, 9, 3, 2, 6, 2, 4, 7, 7};
    
    for(i = 0; i < 11; i++){
        insere_arvore(raiz, num[i]);
    }

    remove_arvore(raiz, num[6]);

    libera_arvore(raiz);
    return 0;
}