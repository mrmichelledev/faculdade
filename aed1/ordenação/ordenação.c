#include <stdio.h>
#include <stdlib.h>

void ordernar(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main(){
    int vetor[10] = {5, 6, 8, 9, 7, 2, 4, 0, 3, 1};
    int i, j;

    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            if(vetor[j] > vetor[j + 1])
                ordernar(&vetor[j], &vetor[j + 1]);
        }
    }

    for(i = 0; i < 10; i++)
        printf("%d ", vetor[i]);

    return 0;
}