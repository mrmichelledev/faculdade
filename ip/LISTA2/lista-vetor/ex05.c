#include <stdio.h>

int main(){
    int n1, i, j, maiorN = 0, vet1[10000];
    
    while (1) {
        scanf("%d", &n1);
        
        if (n1 == 0) break;
        
        for(i = 0; i < n1; i++){
            scanf("%d", &vet1[i]);
            if(vet1[i] > maiorN){
                maiorN = vet1[i];
            }
        }
    
        for(j = 0; j < n1; j++){
            if(vet1[j] == maiorN){
                printf("%d %d\n", j, vet1[j]);
                break;
            }
        }
        
        maiorN = 0;
    }
    return 0;
}