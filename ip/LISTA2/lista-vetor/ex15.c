#include <stdio.h>

int main(){
    int t, n,tamanho[1000], testes[1000];
    scanf("%d %d", &t, &n);

    for(i = 0; i < n; i++){
        scanf("%d", &tamanho[i]);
        for(j = 0; j < tamanho[i]; j++){
            scanf("%d", &tamanho[j]);
        }
    }


    return 0;
}