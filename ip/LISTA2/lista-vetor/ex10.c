#include <stdio.h>

int main(){
    int n, notas[10000], seq = 0, maiorN = 0, aux = 0, i, j;
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
        scanf("%d", &notas[i]);
        if (notas[i] > 10 || notas[i] < 0) i--;
    }
    
    for(j = 0; j < n; j++){
        if(notas[j] == notas[n - 1]){
            seq++;
        }
    }
    
    for(i = 0; i < n; i++){
        if (notas[i] == aux){
            break;
        } else if(notas[i] > aux){
            maiorN = i;
            aux = notas[i];
        }
    }
    
    printf("Nota %d, %d vezes\n", notas[n - 1], seq);
    printf("Nota %d, indice %d\n", notas[maiorN], maiorN);
    
    return 0;
}