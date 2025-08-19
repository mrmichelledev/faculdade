#include <stdio.h>

int main(){
    int m, n, i, j, aux = 1, aux2;
    
    scanf("%d %d", &m, &n);
    
    int xadrez[m][n];
    
    for(i = 0; i < m; i++){
        
        if(i%2 == 1) aux = 0;
        if(i%2 == 0) aux = 1;
        
       for(j = 0; j < n; j++){
           printf("%d", aux);
           if(aux == 1){
              aux = 0; 
           } else{
              aux = 1;
           }
       }
            
       printf("\n");
    }

    return 0;
}