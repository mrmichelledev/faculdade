#include <stdio.h>

int main(){
    int num[5000], n, aux, repet = 0, i, j;
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
       scanf("%d", &num[i]);
    }
    
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(num[j] == num[i]){
                aux++;
            }
        }
        
        if(aux > 0){
            repet+=2;
        }
        aux = 0;
    }
    
    printf("%d\n", n - repet);
    
    return 0;
}
