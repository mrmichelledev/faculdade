#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int tam, i;
    scanf("%d", &tam);

    int *vet = (int*) malloc(tam * sizeof(int));

    for(i = 0; i < tam; i++){
        scanf("%d", &vet[i]);
    }

    for(i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }

    free(vet);

    return 0;
}
