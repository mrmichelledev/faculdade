#include <stdio.h>

int main(){
    int a[10], b[10], c[10], i, j, k;
    
    printf("Digite 10 numeros para o vetor A: ");
    for(i = 0; i < 10; i++){
        scanf("%d", &a[i]);
    }

    printf("Digite 10 numeros para o vetor B: ");
    for(j = 0; j < 10; j++){
        scanf("%d", &b[j]);
    }

    printf("Os 10 numeros do vetor C: ");
    for(k = 0; k < 10; k++){
        c[k] = a[k] + b[k];
        printf("%d ", c[k]);    
    }

    return 0;
}