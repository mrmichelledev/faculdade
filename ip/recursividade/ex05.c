#include <stdio.h>
#include <stdlib.h>

int soma(int *num){
    int somaa;
    
    if(*num < 1) 
        return 0;

    if(*num > 0)
        return *num + soma(num - 1);
}

int main(){
    int num, i, j, t, *vet, result;
    scanf("%d", &t);

    vet = (int*)malloc(30 * sizeof(int));

    for(i =0; i < t; i++){
        result = 0;
        scanf("%d", &num);
        for(j = 0; j < num; j++){
            scanf("%d", &vet[j]);
            result = soma(&vet[j]);
        }
        printf("%d\n", result);
    }

    return 0;
}