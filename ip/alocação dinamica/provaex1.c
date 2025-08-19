#include <stdio.h>
#include <stdlib.h>

//troca os elementos apontados por a e b
void troca(int *a, int *b){
    int swap;
    swap = *a;
    *a = *b;
    *b = swap;
}

//troca os elementos opostos do vetor se maior
void trocaOpostosSeMaior(int *vetor, int tam){
    int i;
    
    for(i = 0; i < (int)tam/2; i++){
        if(vetor[i] > vetor[tam - i -1]){
            troca(&vetor[i], &vetor[tam - i - 1]);
        }
    }
}

int main(){ 
    int vetor[500], num, i, j, tam;
    scanf("%d", &num);
    
    for(i = 0; i < num; i++){
        scanf("%d", &tam);
       for(j = 0; j < tam; j++){
            scanf("%d", &vetor[j]);
        }
        
        trocaOpostosSeMaior(vetor, tam);
        
        for(j = 0; j < tam; j++){
            printf("%d", vetor[j]);
        }
    }
    
    return 0;
}