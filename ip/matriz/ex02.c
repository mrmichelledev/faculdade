#include <stdio.h>

int main(){
    int n, matriz[1000][1000], i, j;
    scanf("%d", &n);
  
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i = 0; i < n; i++){
        printf("%d\n", matriz[i][i]);
    }

    return 0;
}