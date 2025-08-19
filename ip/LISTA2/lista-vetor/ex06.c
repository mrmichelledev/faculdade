#include <stdio.h>

int main(){
    int n, vet[5000], i, j, soma = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &vet[i]);
        soma += vet[i];
    }
    
    printf("%d", soma);

    return 0;
}