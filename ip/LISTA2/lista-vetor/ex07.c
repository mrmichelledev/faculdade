#include <stdio.h>

int main(){
    int n, vet[10000], i, j, k, maiorE = 0, freqMenores = 0, ii = 0;

    while(1){
        scanf("%d", &n);

        if (n == 0) break;

        for(i = 0; i < n; i++){
            scanf("%d", &vet[i]);
            if(vet[i] > maiorE){
                maiorE = vet[i];
            }
        }

        for(j = 0; j <= maiorE; j++){
            for(k = 0; k < n; k++){
                if(vet[k] <= j){
                    freqMenores++;
                }
            }
            
            printf("(%d) %d\n", j, freqMenores);
            freqMenores = 0;
        }
        
        freqMenores = 0;
        maiorE = 0;
    }

    return 0;
}