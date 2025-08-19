#include <stdio.h>

int main(){
    int matrizA[10][10], m, n, i, j;
    scanf("%d %d", &m, &n);
    
    
    while(m < 1 || m > 10){
        scanf("%d", &m);
    }
    
    while(n < 1 || n > 10){
        scanf("%d", &n);
    }
  
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &matrizA[i][j]);
        }
    }

    for(i = 0; i < n; i++){
        printf("linha %d: ", i+1);
        for(j = 0; j < m; j++){
            printf("%d", matrizA[i][j]);
            if(j >= 0 && j < m - 1){
                printf(",");
            }
        }
        printf("\n");
    }

    return 0;
}