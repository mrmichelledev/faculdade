#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "heap.h"

int main(){
    heap he;
    criaHeap(&he);

    int vet[MAX] = {20, 5, 8, 17, 20, 83, 11, 66, 49, 0, 4, 77, 55, 26, 2, 96, 62};
    int i, num;

    printf("vetor: ");
    for(i = 0; i < MAX; i++){
        insere(&he, vet[i]);
        printf("%d ", vet[i]);
    }

    printf("\nArvore atual:\n");

    imprime(&he);

    printf("\nDigite valor para consultar: ");
    scanf("%d", &num);
    consulta(&he, num);

    printf("\nRemovendo a raiz...\n");
    remover(&he);

    printf("\nArvore apos a remocao:\n");
    imprime(&he);

    return 0;
}