#include <stdio.h>

int main(){
    int n, i, j, binario[32];
    
   while(scanf("%d", &n) != EOF){
       
         if (n == 0){
            printf("0\n");
         } else {
             while(1){
               if (n == 0)break;
               
               if (n % 2 == 0){
                   binario[i] = 0;
               } else if (n % 2 != 0){
                   binario[i] = 1;
               }
               
               n/=2;
               i++;
            }

            for(j = 1; j <= i; j++){
                printf("%d", binario[i - j]);
            }
            
            printf("\n");
            
            i = 0;
         }
         
         
   }
    
    return 0;
}