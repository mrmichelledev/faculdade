#include <stdio.h>

int main(){
    int n, i, j, vet[5000];

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    for(j = 0; j < n; j++){
        printf("%d", vet[n - 1 - j]);
        if( j < n - 1){
            printf(" ");
        }
    }

    return 0;
}