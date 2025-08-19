#include <stdio.h>

int main(){
    int n, m, i, j, matriz[1000][1000], encontrado = 0;
    scanf("%d %d", &n, &m);
    
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if (matriz[i][j] == 1111){
                if(matriz[i-1][j] == 4 && matriz[i+1][j] == 8 && (matriz[i][j-1] == 0 || matriz[i][j+1] == 0)){
                   printf("%d %d", i, j);
                   encontrado = 1;
                } else if(i == n-1 && matriz[i-1][j] == 4 && matriz[0][j] == 8 && (matriz[i][j-1] == 0 || matriz[i][j+1] == 0)){
                   printf("%d %d", i, j);
                   encontrado = 1;
                } else if(i == 0 && matriz[n-1][j] == 4 && matriz[i+1][j] == 8 && (matriz[i][j-1] == 0 || matriz[i][j+1] == 0)){
                   printf("%d %d", i, j);
                   encontrado = 1;
                }
            }
        }
            
    }
    
    if(encontrado == 0) printf("WALLY NAO ESTA NA MATRIZ");
    
    return 0;
}