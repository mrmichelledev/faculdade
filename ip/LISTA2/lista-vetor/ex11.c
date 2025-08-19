#include <stdio.h>

int main(){
    int v[1000], w[1000], n, maiorE, menorE, aux = 0, aux2 = 0, i, j;
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
        scanf("%d", &v[i]); 
    }
    
    for (i = 0; i < n; i++){
        w[n - i - 1] = v[i];
    }
    
    for(i = 0; i < n; i++){
        if(v[i] > aux){
            maiorE = v[i];
            aux = v[i];
        }
        
        printf("%d", v[i]);
        if (i < n-1){
            printf(" ");
        } else {
           printf("\n");
        }
    }
    
    aux2 = maiorE;
    
    for(i = 0; i < n; i++){
        if(w[i] < aux2){
            menorE = w[i];
            aux2 = w[i];
        }
        
        printf("%d", w[i]);
        if (i < n-1){
            printf(" ");
        } else {
           printf("\n");
        }
    }
    
    printf("%d\n", maiorE);
    printf("%d\n", menorE);
    
    return 0;
}