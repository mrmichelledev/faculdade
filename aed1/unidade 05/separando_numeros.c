#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void ordena(int *vetor, int tamanho, int tipo){
    int i, j;

    for(i = 0; i < tamanho - 1; i++){
        for(j = 0; j < tamanho - i - 1; j++){
            if(vetor[j] > vetor[j + 1] && tipo == 1){
                swap(&vetor[j], &vetor[j + 1]);
            } else if (vetor[j] < vetor[j + 1] && tipo == -1){
                swap(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}

void ehPar(int *vet, int tam){
    int i, j = 0, aux[tam];

    for(i = 0; i < tam; i++){
        if(vet[i]%2 == 0){
            aux[j] = vet[i];
            j++;
            
        }
    }

    ordena(aux, j, 1);

    for(i = 0; i < j; i++) 
        printf("%d ", aux[i]);
    
    printf("\n");
}

void ehImpar(int *vet, int tam){
    int i, j = 0, aux[tam];

    for(i = 0; i < tam; i++){
        if(vet[i]%2 != 0){
            aux[j] = vet[i];
            j++;
            
        }
    }

    ordena(aux, j, -1);

    for(i = 0; i < j; i++) 
        printf("%d ", aux[i]);
}

int main(){
    int i, n;
    scanf("%d", &n);

    int vet[n];

    for(i = 0; i < n; i++)
        scanf("%d", &vet[i]);

    ehPar(vet, n);

    ehImpar(vet, n);

    return 0;
}