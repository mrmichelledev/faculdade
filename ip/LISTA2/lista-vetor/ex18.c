#include <stdio.h>

#define LIMITE 11

int main(){
    int n, i, j, somad1 = 0, somad2 = 0;
    scanf("%d", &n);

    int cpf[n][LIMITE], d1[n], d2[n];
    
    for(i = 0; i < n; i++){
       for(j = 0; j < LIMITE; j++){
            scanf("%d", &cpf[i][j]);
       }
    }

    for(i = 0; i < n; i++){
       somad1 = 0;
       somad2 = 0;
       
       for(j = 0; j < 9; j++){
            somad1 += (cpf[i][j]) * (j+1);
            somad2 += (cpf[i][j]) * (9-j);
        }
        d1[i] = somad1%11;
        d2[i] = somad2%11;
        
    }
    
    

    for(i = 0; i < n; i++){
        
        
        if(d1[i] == 10){
            d1[i] = 0;
        } else if (d2[i] == 10){
            d2[i] = 0;
        }
        
       if(d1[i] == cpf[i][9] && d2[i] == cpf[i][10]){
           printf("CPF valido\n");     
       } else {
           printf("CPF invalido\n");
       }
    }
    
    return 0;
}