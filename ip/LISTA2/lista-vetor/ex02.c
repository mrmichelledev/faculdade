#include <stdio.h>

int main(){
    int num, i, j, k, vet[1000], cont = 0;
    
    scanf("%d", &num);

    for(i = 0; i < num; i++){
        scanf("%d", &vet[i]);
    }

    scanf("%d", &k);

    for(j = 0; j < num; j++){
        if(vet[j] >= k){
            cont++;
        }
    }

    printf("%d\n", cont);

    return 0;
}