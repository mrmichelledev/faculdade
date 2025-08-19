#include <stdio.h>
#include <math.h>

int main(){
    int  i, j, aux;
    double resultante1 = 0, matriz[2][2];

    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            scanf("%lf", &matriz[i][j]);
        }
    }
    
    //linha 1
    for(i = 0; i < 2; i++){
        resultante1 = 0;
        
        for(j = 0; j < 2; j++){
            resultante1 = (matriz[i][0] * matriz[0][j]) + (matriz[i][1] * matriz[1][j]);
            printf("%.3lf", resultante1);

            if(j < 1){
                printf(" ");
            }
        }
        printf("\n");
    }

    
    return 0;
}