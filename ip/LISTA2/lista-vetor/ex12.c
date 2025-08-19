#include <stdio.h>

int main(){
    int num[1000],num2[1000], n, aux = 0, m = 0, i, j;
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
       scanf("%d", &num[i]);
    }
    
    for(i = 0; i < n; i++){
        for(j = i; j < n; j++){
            if(num[i] > num[j]){
                aux = num[i];
                num[i] = num[j];
                num[j] = aux;
            }
        }   
    }
    
    for(i = 0; i < n; i++){
        printf("%d\n", num[i]);
    }
    
    return 0;
}