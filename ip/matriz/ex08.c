#include <stdio.h>
 
int main(){
    int matriz[100][100], largura, altura, largBorda, valBorda, i, j;
    
    scanf("%d %d %d %d", &largura, &altura, &largBorda, &valBorda);
    
    printf("P2\n%d %d\n255\n", largura, altura);
 
    for(i = 0; i < altura; i++){
        for(j = 0; j < largura; j++){
            if(i < largBorda || j < largBorda || i >= altura - largBorda || j >= largura - largBorda){
                printf("%d ", valBorda);
            } else {
                printf("0 ");
            }
            
        }
        printf("\n");
    }
    
    return 0;
}