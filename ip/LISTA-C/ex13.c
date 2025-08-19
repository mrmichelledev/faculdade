#include <stdio.h>

int main(){
    int num, i;
    scanf("%d", &num);
    
    if(num > 0){
        
        if(num%2 == 0){
            printf("NAO PRIMO");
        } else if (num%2 == 1){
            printf("PRIMO");
        }
        
    } else {
        printf("Numero invalido!");
    }

    return 0;
}