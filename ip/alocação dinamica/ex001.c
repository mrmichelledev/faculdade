#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, m, j, l, k, *num, *den, aux;
    float result[50];
    
    
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
        scanf("%d", &m);
        
        aux = 0;
        
        num = (int*)malloc(m * sizeof(int));
        den = (int*)malloc(m * sizeof(int));
        if (getchar() == '\n') break;
        for(j = 0; j < m; j++){
            scanf("%d/%d", &num[j], &den[j]);
            result[j] = (float) num[j]/den[j];
        }
        
        printf("Caso de teste %d\n", i+1);
        
        for(l = 0; l < m; l++){
            for(k = l + 1; k < m; k++){
                if((result[l] - result[k]) == 0){
                   aux = 1;
                   printf("%d/%d equivalente a %d/%d\n", num[l], den[l], num[k], den[k]);
                }
            }
        }
        
        if(aux == 0) printf("Nao ha fracoes equivalentes na sequencia\n");
    }
    
    return 0;
}