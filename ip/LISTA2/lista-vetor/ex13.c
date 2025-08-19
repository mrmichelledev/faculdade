#include <stdio.h>

int main(){
    int num[1000000], n, aux, repet = 0, maiorfreq, freq = 0, i, j;
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
       scanf("%d", &num[i]);
    }
    
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(num[j] == num[i]){
                freq++;
            }
        }
        
        if(repet < freq){
            maiorfreq = num[i];
            repet = freq;
        }
        freq = 0;
    }
    
    printf("%d\n", maiorfreq);
    printf("%d\n", repet+1);
    
    return 0;
}