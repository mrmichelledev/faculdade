#include <stdio.h>

int main(){
    int vet1[100000], vet2[1000], n, i, j, m, k, l, verific = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &vet1[i]);
    }

    scanf("%d", &m);

    for(j = 0; j < m; j++){
        scanf("%d", &vet2[j]);
    }

    for(k = 0; k < m; k++){
        for(l = 0; l < n; l++){
            if(vet2[k] == vet1[l]){
                verific = 1;
                break;
            } 
        }
        
        if(verific == 1){
            printf("ACHEI\n");
        } else if (verific == 0){
             printf("NAO ACHEI\n");
        }
        
        verific = 0;
    }
    

    return 0;
}