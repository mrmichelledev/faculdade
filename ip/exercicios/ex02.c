#include <stdio.h>
#include <stdlib.h>

int main(){
    int a[10], i, j;
    
    printf("Digite 10 numeros para o vetor A: ");
    for(i = 0; i < 10; i++){
        scanf("%d", &a[i]);
    }

    printf("10 numeros invertidos: ");
    for(i = 9; i >= 0; i--){
        printf("%d ", a[i]);
    }

    return 0;
}