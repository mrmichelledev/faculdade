#include <stdio.h>

int main(){
    int m, n, i, j, branco = 1, preto = 0, aux = 0;
    scanf("%d %d", &m, &n);
    
    for(i = 0; i < m; i++){
        if(i%2 == 1) aux = branco;
        if(i%2 == 0) aux = preto;
        
        for(j = 0; j < n; j++){
            if(aux == preto){
                printf("%d ", aux);
                aux = branco;
            } else{
                printf("%d ", aux);
                branco++;
                aux = preto;
            }
        }
        
        printf("\n");
    }
    
    return 0;
}