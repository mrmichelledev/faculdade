#include <stdio.h>

int main(){
    int n, i, j, matriz[1000][1000], matrizT[1000][1000], soma = 0, result;
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &matriz[i][j]);
            matrizT[j][i] = matriz[i][j];
        }
    }
    
    for(i = 0; i < n; i++){
        soma += matrizT[i][i];
    }
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            result = (soma * matriz[i][j]) + matrizT[i][j];
           printf("%d ", result);
        }
        printf("\n");
    }
    
    return 0;
}